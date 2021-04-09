/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    sdcard.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdio.h>
#include <string.h>
#include "sdcard.h"
#include "serial_mem.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
#define SDCARD_MOUNT_NAME       SYS_FS_MEDIA_IDX0_MOUNT_NAME_VOLUME_IDX0
#define SDCARD_DEVICE_NAME      SYS_FS_MEDIA_IDX0_DEVICE_NAME_VOLUME_IDX0

#define SDCARD_IMAGE_FILE_NAME  SDCARD_MOUNT_NAME"/image.bin"

/* Size of One Erase Sector of Serial Memory */
#define READ_BUFFER_SIZE        4096

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the SDCARD_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

SDCARD_DATA sdcardData;

uint8_t CACHE_ALIGN readBuffer[READ_BUFFER_SIZE];

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void SDCARD_SysFSEventHandler(SYS_FS_EVENT event,void* eventData,uintptr_t context)
{
    switch(event)
    {
        /* If the event is mount then check which media has been mounted */
        case SYS_FS_EVENT_MOUNT:
        {
            if(strcmp((const char *)eventData, SDCARD_MOUNT_NAME) == 0)
            {
                sdcardData.sdcardMounted = true;
            }

            break;
        }

        /* If the event is unmount then check which media has been unmount */
        case SYS_FS_EVENT_UNMOUNT:
        {
            if(strcmp((const char *)eventData, SDCARD_MOUNT_NAME) == 0)
            {
                sdcardData.sdcardMounted = false;

                if (sdcardData.state == SDCARD_IDLE)
                {
                    sdcardData.state = SDCARD_MOUNT_WAIT;
                }
                else
                {
                    sdcardData.state = SDCARD_ERROR;
                }
            }

            break;
        }

        case SYS_FS_EVENT_MOUNT_WITH_NO_FILESYSTEM:
        case SYS_FS_EVENT_ERROR:
        default:
        {
            break;
        }
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Functions
// *****************************************************************************
// *****************************************************************************

/* Function to be used to get the current status of SD Card Task */
SDCARD_STATUS SDCARD_getCurrentStatus( void )
{
    return (sdcardData.currentStatus);
}

/* Functions used by Serial Memory Task to get the data read from SD Card */
void SDCARD_getReceivedData(uint8_t *buffer, uint32_t *bytesRead)
{
    memcpy(buffer, readBuffer, sdcardData.bytesRead);

    *bytesRead = sdcardData.bytesRead;

    sdcardData.currentStatus = SDCARD_STATUS_BUSY;
}

/* Function used by Serial Memory Task to notify that Received image Data has been
 * wrtten to Serial Memory.
 */
void SDCARD_setWriteComplete( bool status )
{
    sdcardData.writeComplete = status;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void SDCARD_Initialize ( void )

  Remarks:
    See prototype in sdcard.h.
 */

void SDCARD_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    sdcardData.state = SDCARD_MOUNT_WAIT;

    sdcardData.currentStatus = SDCARD_STATUS_BUSY;

    sdcardData.sdcardMounted = false;

    SDCARD_setWriteComplete(false);

    SYS_FS_EventHandlerSet(SDCARD_SysFSEventHandler,(uintptr_t)NULL);
}


/******************************************************************************
  Function:
    void SDCARD_Tasks ( void )

  Remarks:
    See prototype in sdcard.h.
 */

void SDCARD_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( sdcardData.state )
    {
        case SDCARD_MOUNT_WAIT:
        {
            /* Wait for SDCARD to be Auto Mounted */
            if(sdcardData.sdcardMounted == true)
            {
                sdcardData.state = SDCARD_VALIDATE_FILE_AND_OPEN;
            }

            break;
        }

        case SDCARD_VALIDATE_FILE_AND_OPEN:
        {
            if (SYS_FS_FileStat(SDCARD_IMAGE_FILE_NAME, &sdcardData.fileStat) == SYS_FS_RES_SUCCESS)
            {
                /* Check if the application binary file has any content */
                if (sdcardData.fileStat.fsize <= 0)
                {
                    printf("\r\n!!!!!! ERROR: Size Of Image Binary Is Zero !!!!!!\r\n");
                    sdcardData.state = SDCARD_ERROR;
                    break;
                }

                sdcardData.fileHandle = SYS_FS_FileOpen(SDCARD_IMAGE_FILE_NAME, (SYS_FS_FILE_OPEN_READ));

                if(sdcardData.fileHandle != SYS_FS_HANDLE_INVALID)
                {
                    sdcardData.currentStatus = SDCARD_STATUS_READY;

                    /* File opened successfully. Wait for Serial Memory Task to be Ready*/
                    sdcardData.state = SDCARD_SERIAL_MEM_READY_WAIT;
                }
            }
            else
            {
                printf("\r\n!!!!!! ERROR: Unable To Get Image Binary Statistics Or No Image Binary Present!!!!!!\r\n");

                sdcardData.state = SDCARD_ERROR;
            }

            break;
        }

        case SDCARD_SERIAL_MEM_READY_WAIT:
        {
            /* Wait for Serial Memory task to be ready to receive Image binary */
            if (SERIAL_MEM_isReady() == true)
            {
                printf("\r\n###### Copying Image Binary To Serial Memory ######\r\n\r\n");

                sdcardData.state = SDCARD_READ_DATA;
            }

            break;
        }

        case SDCARD_READ_DATA:
        {
            memset(readBuffer, 0xFF, READ_BUFFER_SIZE);

            sdcardData.bytesRead = SYS_FS_FileRead(sdcardData.fileHandle, (void *)readBuffer, READ_BUFFER_SIZE);

            /* Reached End of File */
            if (sdcardData.bytesRead <= 0)
            {
                SYS_FS_FileClose(sdcardData.fileHandle);

                sdcardData.currentStatus = SDCARD_STATUS_UPDATE_COMPLETE;

                sdcardData.state = SDCARD_IDLE;
            }
            else
            {
                /* This will unblock Serial Memory Task to write received Image data to Serial Memory */
                sdcardData.currentStatus = SDCARD_STATUS_UPDATE_AVAILABLE;

                sdcardData.state = SDCARD_SERIAL_MEM_WRITE_WAIT;
            }

            break;
        }

        case SDCARD_SERIAL_MEM_WRITE_WAIT:
        {
            /* Wait for Serial Memory Write Complete.
             * Print Status Bar on to Console.
             */
            printf ("%c", 178);

            if (sdcardData.writeComplete == true)
            {
                SDCARD_setWriteComplete(false);

                sdcardData.state = SDCARD_READ_DATA;
            }

            break;
        }

        case SDCARD_IDLE:
        {
            break;
        }

        case SDCARD_ERROR:
        default:
        {
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
