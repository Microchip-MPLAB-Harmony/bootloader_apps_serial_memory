/*******************************************************************************
  Company:
    Microchip Technology Inc.

  File Name:
    bootloader.c

  Summary:
    Interface for the Bootloader library.

  Description:
    This file contains the interface definition for the Bootloader library.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Include Files
// *****************************************************************************
// *****************************************************************************

#include <string.h>
#include "configuration.h"
#include "peripheral/fcw/plib_fcw.h"
#include "bootloader/bootloader_sdcard.h"
#include "system/fs/sys_fs.h"

#define BOOTLOADER_MOUNT_NAME   SYS_FS_MEDIA_IDX0_MOUNT_NAME_VOLUME_IDX0
#define BOOTLOADER_DEV_NAME     SYS_FS_MEDIA_IDX0_DEVICE_NAME_VOLUME_IDX0
#define APP_IMAGE_FILE_NAME     "image.bin"
#define APP_IMAGE_FILE_PATH     BOOTLOADER_MOUNT_NAME"/"APP_IMAGE_FILE_NAME

typedef enum
{
    BOOTLOADER_REGISTER_FS_EVENT_HANDLER = 0,

    BOOTLOADER_WAIT_FOR_DEVICE_ATTACH,

    BOOTLOADER_VALIDATE_FILE_AND_OPEN,

    BOOTLOADER_ERASE_APPLICATION_SPACE,

    BOOTLOADER_READ_FILE,

    BOOTLOADER_PROCESS_FILE_BUFFER,

    BOOTLOADER_DEVICE_DETACHED,

    BOOTLOADER_ERROR,

} BOOTLOADER_STATES;


typedef struct
{
    /* Bootloader current state */
    BOOTLOADER_STATES currentState;

    /* Programming address */
    uint32_t progAddr;

    /* Stream handle */
    SYS_FS_HANDLE fileHandle;

    /* Stores Application binary file information */
    SYS_FS_FSTAT fileStat;

    /* Flag to indicate device attached */
    bool deviceAttached;

} BOOTLOADER_DATA;

static uint8_t CACHE_ALIGN fileBuffer[PAGE_SIZE];

/* MISRA C-2012 Rule 7.2 deviated:1 Deviation record ID -  H3_MISRAC_2012_R_5_2_DR_1 */

static BOOTLOADER_DATA btlData =
{
    .currentState   = BOOTLOADER_REGISTER_FS_EVENT_HANDLER,
    .deviceAttached = false,
    .progAddr       = APP_START_ADDRESS
};


/* MISRAC 2012 deviation block end */


static void bootloader_SysFsEventHandler(SYS_FS_EVENT event, void * eventData, uintptr_t context)
{
    switch(event)
    {
        case SYS_FS_EVENT_MOUNT:
        {
            btlData.deviceAttached = true;
            break;
        }

        case SYS_FS_EVENT_UNMOUNT:
        {
            btlData.deviceAttached = false;

            btlData.currentState = BOOTLOADER_DEVICE_DETACHED;
            break;
        }

        default:
        {
            /* Do Nothing */
            break;
        }
    }
}

/* MISRA C-2012 Rule 11.3, 11.6 deviated below. Deviation record ID -  
   H3_MISRAC_2012_R_11_3_DR_1 & H3_MISRAC_2012_R_11_6_DR_1*/

static void bootloader_NvmAppErase( uint32_t appLength )
{
    uint32_t flashAddr = APP_START_ADDRESS;

    /* Align application binary length to erase boundary */
    appLength = appLength + (ERASE_BLOCK_SIZE - (appLength % ERASE_BLOCK_SIZE));

    while ((flashAddr < (FLASH_START + FLASH_LENGTH)) &&
           (appLength != 0U))
    {
        (void) FCW_PageErase(flashAddr);

        while(FCW_IsBusy() == true)
        {
              /* Do Nothing */
        }

        flashAddr += ERASE_BLOCK_SIZE;
        appLength -= ERASE_BLOCK_SIZE;
    }
}

static void bootloader_NVMPageWrite(uint8_t* data)
{
    (void) FCW_RowWrite((uint32_t *)data, btlData.progAddr);

    while(FCW_IsBusy() == true)
    {
       /* Do Nothing */
    }

    btlData.progAddr += PAGE_SIZE;
}


/* MISRAC 2012 deviation block end */

void bootloader_SDCARD_Tasks( void )
{
    size_t fileReadLength;

    switch ( btlData.currentState )
    {
        case BOOTLOADER_REGISTER_FS_EVENT_HANDLER:
        {
            SYS_FS_EventHandlerSet(bootloader_SysFsEventHandler, 0U);

            btlData.currentState = BOOTLOADER_WAIT_FOR_DEVICE_ATTACH;

            break;
        }

        case BOOTLOADER_WAIT_FOR_DEVICE_ATTACH:
        {
            if (btlData.deviceAttached == true)
            {
                btlData.currentState = BOOTLOADER_VALIDATE_FILE_AND_OPEN;
            }
            break;
        }

        case BOOTLOADER_VALIDATE_FILE_AND_OPEN:
        {
            if (SYS_FS_FileStat(APP_IMAGE_FILE_PATH, &btlData.fileStat) == SYS_FS_RES_SUCCESS)
            {
                /* Check if the application binary file has any content */
                if (btlData.fileStat.fsize <= 0U)
                {
                    break;
                }

                btlData.fileHandle = SYS_FS_FileOpen(APP_IMAGE_FILE_PATH, (SYS_FS_FILE_OPEN_READ));

                if(btlData.fileHandle != SYS_FS_HANDLE_INVALID)
                {
                    /* File opened successfully. Erase Application space */
                    btlData.currentState = BOOTLOADER_ERASE_APPLICATION_SPACE;
                }
            }

            break;
        }

        case BOOTLOADER_ERASE_APPLICATION_SPACE:
        {
            bootloader_NvmAppErase(btlData.fileStat.fsize);

            btlData.currentState = BOOTLOADER_READ_FILE;

            (void) memset((void *)fileBuffer, 0xFF, PAGE_SIZE);

            break;
        }

        case BOOTLOADER_READ_FILE:
        {
            fileReadLength = SYS_FS_FileRead(btlData.fileHandle, (void *)fileBuffer, PAGE_SIZE);

            /* Reached End of File */
            if (fileReadLength <= 0U)
            {
                (void) SYS_FS_FileClose(btlData.fileHandle);

                bootloader_TriggerReset();
            }
            else
            {
                btlData.currentState = BOOTLOADER_PROCESS_FILE_BUFFER;
            }

            break;
        }

        case BOOTLOADER_PROCESS_FILE_BUFFER:
        {
            bootloader_NVMPageWrite(fileBuffer);

            (void) memset((void *)fileBuffer, 0xFF, PAGE_SIZE);

            btlData.currentState = BOOTLOADER_READ_FILE;

            break;
        }

        case BOOTLOADER_DEVICE_DETACHED:
        {
            (void) SYS_FS_FileClose(btlData.fileHandle);

            btlData.currentState = BOOTLOADER_WAIT_FOR_DEVICE_ATTACH;
            break;
        }

        case BOOTLOADER_ERROR:
        default:
            /* Do Nothing */
            break;
    }
}