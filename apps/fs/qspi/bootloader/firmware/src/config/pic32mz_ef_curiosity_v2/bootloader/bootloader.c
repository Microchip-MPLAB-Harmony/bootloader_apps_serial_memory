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
#include "peripheral/nvm/plib_nvm.h"
#include "bootloader/bootloader.h"
#include "system/fs/sys_fs.h"
#include "sys/kmem.h"

#define APP_START_ADDRESS       ((uint32_t)(PA_TO_KVA0(0x1d000000UL)))

#define FLASH_START             (0x9d000000UL)
#define FLASH_LENGTH            (0x200000UL)
#define PAGE_SIZE               (2048UL)
#define ERASE_BLOCK_SIZE        (16384UL)
#define PAGES_IN_ERASE_BLOCK    (ERASE_BLOCK_SIZE / PAGE_SIZE)

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

uint8_t CACHE_ALIGN fileBuffer[PAGE_SIZE];

BOOTLOADER_DATA btlData =
{
    .currentState   = BOOTLOADER_REGISTER_FS_EVENT_HANDLER,
    .deviceAttached = false,
    .progAddr       = APP_START_ADDRESS
};

bool __WEAK bootloader_Trigger(void)
{
    /* Function can be overriden with custom implementation */
    return false;
}

static void bootloader_TriggerReset(void)
{
    /* Perform system unlock sequence */
    SYSKEY = 0x00000000;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;

    RSWRSTSET = _RSWRST_SWRST_MASK;
    (void)RSWRST;
}

void run_Application(void)
{
    uint32_t msp            = *(uint32_t *)(APP_START_ADDRESS);

    void (*fptr)(void);

    /* Set default to APP_RESET_ADDRESS */
    fptr = (void (*)(void))APP_START_ADDRESS;

    if (msp == 0xffffffff)
    {
        return;
    }

    fptr();
}


void bootloader_SysFsEventHandler(SYS_FS_EVENT event, void * eventData, uintptr_t context)
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
            break;
        }
    }
}

void bootloader_NvmAppErase( uint32_t appLength )
{
    uint32_t flashAddr = APP_START_ADDRESS;

    /* Align application binary length to erase boundary */
    appLength = appLength + (ERASE_BLOCK_SIZE - (appLength % ERASE_BLOCK_SIZE));

    while ((flashAddr < (FLASH_START + FLASH_LENGTH)) &&
           (appLength != 0))
    {
        NVM_PageErase(flashAddr);

        while(NVM_IsBusy() == true)
        {

        }

        flashAddr += ERASE_BLOCK_SIZE;
        appLength -= ERASE_BLOCK_SIZE;
    }
}

void bootloader_NVMPageWrite(uint8_t* data)
{
    NVM_RowWrite((uint32_t *)data, btlData.progAddr);

    while(NVM_IsBusy() == true)
    {

    }

    btlData.progAddr += PAGE_SIZE;
}

void bootloader_Tasks( void )
{
    size_t fileReadLength;

    switch ( btlData.currentState )
    {
        case BOOTLOADER_REGISTER_FS_EVENT_HANDLER:
        {
            SYS_FS_EventHandlerSet(bootloader_SysFsEventHandler, (uintptr_t)NULL);

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
                if (btlData.fileStat.fsize <= 0)
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

            memset((void *)fileBuffer, 0xFF, PAGE_SIZE);

            break;
        }

        case BOOTLOADER_READ_FILE:
        {
            fileReadLength = SYS_FS_FileRead(btlData.fileHandle, (void *)fileBuffer, PAGE_SIZE);

            /* Reached End of File */
            if (fileReadLength <= 0)
            {
                SYS_FS_FileClose(btlData.fileHandle);

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

            memset((void *)fileBuffer, 0xFF, PAGE_SIZE);

            btlData.currentState = BOOTLOADER_READ_FILE;

            break;
        }

        case BOOTLOADER_DEVICE_DETACHED:
        {
            SYS_FS_FileClose(btlData.fileHandle);

            btlData.currentState = BOOTLOADER_WAIT_FOR_DEVICE_ATTACH;
            break;
        }

        case BOOTLOADER_ERROR:
        default:
            break;
    }
}