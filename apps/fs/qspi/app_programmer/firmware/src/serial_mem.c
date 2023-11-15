/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    serial_mem.c

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
#include "serial_mem.h"
#include "sdcard.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
#define SERIAL_MEM_MOUNT_NAME       SYS_FS_MEDIA_IDX1_MOUNT_NAME_VOLUME_IDX0
#define SERIAL_MEM_DEVICE_NAME      SYS_FS_MEDIA_IDX1_DEVICE_NAME_VOLUME_IDX0

#define SERIAL_MEM_IMAGE_FILE_NAME  SERIAL_MEM_MOUNT_NAME"/image.bin"

/* Size of One Erase Sector of Serial Memory */
#define WRITE_BUFFER_SIZE           4096

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the SERIAL_MEM_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

SERIAL_MEM_DATA serialMemData;

uint8_t CACHE_ALIGN writeBuffer[WRITE_BUFFER_SIZE];

/* work1 buffer used by FAT FS during Format */
uint8_t CACHE_ALIGN work1[SYS_FS_FAT_MAX_SS];

SYS_FS_FORMAT_PARAM formatOpt;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void SERIAL_MEM_SysFSEventHandler(SYS_FS_EVENT event,void* eventData,uintptr_t context)
{
    switch(event)
    {
        /* If the event is mount then check which media has been mounted */
        case SYS_FS_EVENT_MOUNT:
        {
            if(strcmp((const char *)eventData, SERIAL_MEM_MOUNT_NAME) == 0)
            {
                serialMemData.serialMemMounted = true;
            }

            break;
        }

        /* If the serial memory is mounted with No Valid File System */
        case SYS_FS_EVENT_MOUNT_WITH_NO_FILESYSTEM:
        {
            if(strcmp((const char *)eventData, SERIAL_MEM_MOUNT_NAME) == 0)
            {
                serialMemData.serialMemFormatRequired = true;
            }
            break;
        }

        /* If the event is unmount then check which media has been unmount */
        case SYS_FS_EVENT_UNMOUNT:
        {
            if(strcmp((const char *)eventData, SERIAL_MEM_MOUNT_NAME) == 0)
            {
                serialMemData.serialMemMounted = false;
                serialMemData.serialMemFormatRequired = false;

                if (serialMemData.state == SERIAL_MEM_IDLE)
                {
                    serialMemData.state = SERIAL_MEM_MOUNT_WAIT;
                }
                else
                {
                    serialMemData.state = SERIAL_MEM_ERROR;
                }
            }

            break;
        }

        case SYS_FS_EVENT_ERROR:
        default:
        {
            break;
        }
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Global Functions
// *****************************************************************************
// *****************************************************************************

/* Used by SDCard task to to check if Seriam Memory task is ready to receive
 * Image Data
 */
bool SERIAL_MEM_isReady( void )
{
    return (serialMemData.isReady);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void SERIAL_MEM_Initialize ( void )

  Remarks:
    See prototype in serialMem.h.
 */

void SERIAL_MEM_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    serialMemData.state = SERIAL_MEM_MOUNT_WAIT;

    serialMemData.isReady = false;
    serialMemData.serialMemMounted = false;
    serialMemData.serialMemFormatRequired = false;

    SYS_FS_EventHandlerSet(SERIAL_MEM_SysFSEventHandler,(uintptr_t)NULL);
}


/******************************************************************************
  Function:
    void SERIAL_MEM_Tasks ( void )

  Remarks:
    See prototype in serialMem.h.
 */

void SERIAL_MEM_Tasks ( void )
{
    SDCARD_STATUS sdcardStatus = SDCARD_STATUS_BUSY;

    /* Check the application's current state. */
    switch ( serialMemData.state )
    {
        /* Application's initial state. */
        case SERIAL_MEM_MOUNT_WAIT:
        {
            /* Wait for SERIAL_MEM to be Auto Mounted */
            if (serialMemData.serialMemFormatRequired == true)
            {
                /* Mount was successful. Format the disk. */
                serialMemData.state = SERIAL_MEM_FORMAT_DISK;
            }
            else if(serialMemData.serialMemMounted == true)
            {
                printf("\r\n###### Insert SD Card To Copy Image Binary To Serial Memory ######\r\n");

                serialMemData.state = SERIAL_MEM_SDCARD_READY_WAIT;
            }
            break;
        }

        case SERIAL_MEM_FORMAT_DISK:
        {
            printf("\r\n###### Formatting Serial Memory To FAT File System ######\r\n");

            formatOpt.fmt = SYS_FS_FORMAT_FAT;
            formatOpt.au_size = 0;

            if (SYS_FS_DriveFormat (SERIAL_MEM_MOUNT_NAME, &formatOpt, (void *)work1, SYS_FS_FAT_MAX_SS) != SYS_FS_RES_SUCCESS)
            {
                /* Format of the disk failed. */
                printf("\r\n!!!!!! ERROR: Format Of Serial Memory Failed !!!!!!\r\n");

                serialMemData.state = SERIAL_MEM_ERROR;
            }
            else
            {
                /* Format succeeded. Open a file. */
                printf("\r\n###### Insert SD Card To Copy Image Binary To Serial Memory ######\r\n");

                serialMemData.state = SERIAL_MEM_SDCARD_READY_WAIT;
            }
            break;
        }

        case SERIAL_MEM_SDCARD_READY_WAIT:
        {
            /* Wait until SDCARD Task is ready to send Image Data before Opening the File in Serial Memory */
            sdcardStatus = SDCARD_getCurrentStatus();

            if (sdcardStatus == SDCARD_STATUS_READY)
            {
                serialMemData.state = SERIAL_MEM_FILE_OPEN_TO_WRITE;
            }

            break;
        }

        case SERIAL_MEM_FILE_OPEN_TO_WRITE:
        {
            /* Open Image binary file on Serial Memory which will be used by Bootloader during Update.
             * As we are opening in Write Mode the Existing Image binary will be overwritten.
             */
            serialMemData.fileHandle = SYS_FS_FileOpen(SERIAL_MEM_IMAGE_FILE_NAME, (SYS_FS_FILE_OPEN_WRITE));

            if(serialMemData.fileHandle != SYS_FS_HANDLE_INVALID)
            {
                serialMemData.isReady = true;

                /* File opened successfully. Erase Application space */
                serialMemData.state = SERIAL_MEM_WAIT_FOR_DATA;
            }

            break;
        }

        case SERIAL_MEM_WAIT_FOR_DATA:
        {
            /* Wait for Image Data or UpdateComplete Status */
            sdcardStatus = SDCARD_getCurrentStatus();

            if (sdcardStatus == SDCARD_STATUS_UPDATE_AVAILABLE)
            {
                memset(writeBuffer, 0xFF, WRITE_BUFFER_SIZE);

                SDCARD_getReceivedData(writeBuffer, &serialMemData.bytesReceived);

                serialMemData.state = SERIAL_MEM_WRITE_DATA;
            }
            else if(sdcardStatus == SDCARD_STATUS_UPDATE_COMPLETE)
            {
                SYS_FS_FileClose(serialMemData.fileHandle);

                serialMemData.state = SERIAL_MEM_IDLE;
            }

            break;
        }

        case SERIAL_MEM_WRITE_DATA:
        {
            serialMemData.bytesWritten = SYS_FS_FileWrite(serialMemData.fileHandle, (void *)writeBuffer, serialMemData.bytesReceived);

            if (serialMemData.bytesWritten != serialMemData.bytesReceived)
            {
                SYS_FS_FileClose(serialMemData.fileHandle);

                printf("\r\n!!!!!! ERROR: Serial Memory Write Error !!!!!!\r\n");

                serialMemData.state = SERIAL_MEM_ERROR;
            }
            else
            {
                /* Notify SDCARD Task that write is complete */
                SDCARD_setWriteComplete(true);

                serialMemData.state = SERIAL_MEM_WAIT_FOR_DATA;
            }

            break;
        }

        case SERIAL_MEM_IDLE:
        {
            break;
        }

        case SERIAL_MEM_ERROR:
        default:
        {
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
