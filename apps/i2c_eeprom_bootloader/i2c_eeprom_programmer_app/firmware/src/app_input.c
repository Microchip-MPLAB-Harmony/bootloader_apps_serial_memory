/*******************************************************************************
  MPLAB Harmony UART App Update Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_input.c

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

#include <string.h>
#include "definitions.h"
#include "app_input.h"
#include "serial_mem.h"

#define GUARD_OFFSET            0
#define CMD_OFFSET              2
#define ADDR_OFFSET             0
#define SIZE_OFFSET             1
#define DATA_OFFSET             1
#define CRC_OFFSET              0

#define CMD_SIZE                1
#define GUARD_SIZE              4
#define SIZE_SIZE               4
#define OFFSET_SIZE             4
#define CRC_SIZE                4
#define HEADER_SIZE             (GUARD_SIZE + SIZE_SIZE + CMD_SIZE)
#define DATA_SIZE               ERASE_BLOCK_SIZE

#define WORDS(x)                ((int)((x) / sizeof(uint32_t)))

#define OFFSET_ALIGN_MASK       (~ERASE_BLOCK_SIZE + 1)
#define SIZE_ALIGN_MASK         (~PAGE_SIZE + 1)

#define APP_INPUT_GUARD         (0x5048434DUL)

// *****************************************************************************
// *****************************************************************************
// Section: Global objects
// *****************************************************************************
// *****************************************************************************

APP_INPUT_DATA app_input;

static SERIAL_MEM_META_DATA CACHE_ALIGN serialMemMetaData;

static uint32_t CACHE_ALIGN app_input_buffer[WORDS(OFFSET_SIZE + DATA_SIZE)];

static uint32_t *flashDataPtr;

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Input Task Local Functions
// *****************************************************************************
// *****************************************************************************

/* Function to Send the response command to the Host */
static void send_Response( T_APP_INPUT_RESP sendResp )
{
    UART_FUNC(Write)((uint8_t*)&sendResp, 1);

    /* Wait for all bytes to be transmitted out */
    while (UART_FUNC(WriteCountGet)() != 0);
}

static bool updateAppMetaData( void )
{
    bool status = false;

    serialMemMetaData.appStartAddress       = app_input.app_start_address;
    serialMemMetaData.appSize               = app_input.app_size;
    serialMemMetaData.appCRC32              = app_input.app_crc;

    status = SERIAL_MEM_UpdateMetaData(&serialMemMetaData);

    return status;
}

/* Function to process the received command */
static T_APP_INPUT_STATUS command_Task( uint8_t command )
{
    T_APP_INPUT_STATUS command_status = APP_INPUT_STATUS_ERROR;

    if (APP_INPUT_CMD_UNLOCK == command)
    {
        uint32_t begin  = (app_input_buffer[ADDR_OFFSET] & OFFSET_ALIGN_MASK);

        uint32_t end    = begin + (app_input_buffer[SIZE_OFFSET] & SIZE_ALIGN_MASK);

        if (end > begin && end <= (FLASH_START + FLASH_LENGTH))
        {
            app_input.app_start_address = begin;
            app_input.app_end_address = end;
            app_input.app_size = (end - begin);            

            send_Response(APP_INPUT_RESP_OK);
            command_status = APP_INPUT_STATUS_UNLOCK;
        }
        else
        {
            app_input.app_start_address = 0;
            app_input.app_end_address = 0;
            app_input.app_size = 0;

            send_Response(APP_INPUT_RESP_ERROR);
        }
    }
    else if (APP_INPUT_CMD_DATA == command)
    {
        uint32_t app_flash_addr = (app_input_buffer[ADDR_OFFSET] & OFFSET_ALIGN_MASK);

        if (app_input.app_start_address <= app_flash_addr && app_flash_addr < app_input.app_end_address)
        {
            flashDataPtr = (uint32_t *)&app_input_buffer[DATA_OFFSET];

            command_status = APP_INPUT_STATUS_READY_FOR_FLASH;
        }
        else
        {
            send_Response(APP_INPUT_RESP_ERROR);
        }
    }
    else if (APP_INPUT_CMD_VERIFY == command)
    {
        uint32_t crc        = app_input_buffer[CRC_OFFSET];
        uint32_t crc_gen    = 0;

        if (SERIAL_MEM_CRC32Generate(app_input.app_size, &crc_gen) == true)
        {
            if (crc == crc_gen)
            {
                app_input.app_crc = crc;

                send_Response(APP_INPUT_RESP_CRC_OK);

                command_status = APP_INPUT_STATUS_VERIFIED;
            }
            else
            {
                send_Response(APP_INPUT_RESP_CRC_FAIL);
            }
        }
        else
        {
            send_Response(APP_INPUT_RESP_CRC_FAIL);
        }
    }
    else if(APP_INPUT_CMD_UPDATE_REBOOT == command)
    {
        if (updateAppMetaData() == true)
        {
            send_Response(APP_INPUT_RESP_OK);

            command_status = APP_INPUT_STATUS_UPDATE_REBOOT;
        }
        else
        {
            send_Response(APP_INPUT_RESP_ERROR);
        }
    }
    else
    {
        send_Response(APP_INPUT_RESP_INVALID);
    }

    app_input.packet_received = false;

    return command_status;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void usart_ReadEventHandler( UART_EVENT event, uintptr_t context )
{
    uint32_t idx                    = 0;
    static uint32_t bytes_read      = 0;
    static uint32_t ptr             = 0;
    static uint32_t size            = 0;
    static bool header_received     = false;

    uint8_t input_data[12]          = {0};
    uint8_t *byte_buf               = (uint8_t *)&app_input_buffer[0];

    if(event == UART_EVENT_READ_ERROR)
    {
        if(UART_FUNC(ErrorGet)() != UART_ERROR_NONE)
        {
            /* ErrorGet clears errors, set error flag to notify to the application */
            app_input.error_status = true;
        }
    }
    else
    {
        /* Receive data from HOST-PC. */
        bytes_read = UART_FUNC(Read)((uint8_t*)&input_data, sizeof(input_data));

        /* Check whether the header is received. If yes check for valid guard
         * before processing the data.
         */
        if (header_received == false)
        {
            idx = 0;

            if (app_input.guard_byte_checked == false)
            {
                for (; idx < bytes_read; idx++)
                {
                    /* Ignore any invalid bytes received before the guard */
                    if (input_data[idx] == (uint8_t)APP_INPUT_GUARD)
                    {
                        ptr = 0;

                        bytes_read -= idx;

                        app_input.guard_byte_checked = true;

                        break;
                    }
                }
            }

            /* Copy the Received Bytes to input buffer */
            memcpy((void *)&byte_buf[ptr], (void *)&input_data[idx], bytes_read);
                
            ptr += bytes_read;

            if (ptr == GUARD_SIZE)
            {
                if (app_input_buffer[GUARD_OFFSET] != APP_INPUT_GUARD)
                {
                    app_input.guard_match = false;
                    ptr                   = 0;
                }
                else
                {
                    app_input.guard_match = true;
                }

                app_input.guard_received  = true;
            }
            else if (ptr == HEADER_SIZE)
            {
                size                        = app_input_buffer[SIZE_OFFSET];
                app_input.guard_match       = true;
                app_input.input_command     = (uint8_t)app_input_buffer[CMD_OFFSET];

                ptr                         = 0;

                if (size == 0)
                {
                    header_received             = false;
                    app_input.packet_received   = true;
                }
                else
                {
                    header_received             = true;
                }
            }
        }
        else if (header_received == true)
        {
            if (ptr < size)
            {
                memcpy((void *)&byte_buf[ptr], (void *)&input_data[0], bytes_read);
                
                ptr += bytes_read;
            }

            if (ptr >= size)
            {
                ptr                             = 0;
                header_received                 = false;
                size                            = 0;
                app_input.packet_received       = true;
            }
        }
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************
/*******************************************************************************
  Function:
    void APP_INPUT_Initialize ( void )

  Remarks:
    See prototype in app_input.h.
 */

void APP_INPUT_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_input.state               = APP_INPUT_STATE_SERIAL_MEM_INIT;
    app_input.error_status        = false;
    app_input.guard_byte_checked  = false;
    app_input.guard_match         = false;
    app_input.packet_received     = false;
    app_input.guard_received      = false;
}

/* Function to process the commands and program received application firmware into QSPI flash */
T_APP_INPUT_STATUS APP_INPUT_ServiceTasks( void )
{
    T_APP_INPUT_STATUS status = APP_INPUT_STATUS_ERROR;

    status = command_Task(app_input.input_command);

    if (status == APP_INPUT_STATUS_READY_FOR_FLASH)
    {
        if (SERIAL_MEM_FlashTask(flashDataPtr, DATA_SIZE) == true)
        {
            send_Response(APP_INPUT_RESP_OK);

            status = APP_INPUT_STATUS_FLASH_SUCCESS;
        }
        else
        {
            status = APP_INPUT_STATUS_ERROR;

            send_Response(APP_INPUT_RESP_ERROR);
        }
    }

    return status;
}

/******************************************************************************
  Function:
    void APP_INPUT_Tasks ( void )

  Remarks:
    See prototype in app_input.h.
 */

void APP_INPUT_Tasks ( void )
{
    static T_APP_INPUT_STATUS resp = APP_INPUT_STATUS_ERROR;

    /* Check the application's current state. */
    switch ( app_input.state )
    {
        /* Application's initial state. */
        case APP_INPUT_STATE_SERIAL_MEM_INIT:
        {
            if (SERIAL_MEM_Ready() == true)
            {
                app_input.state = APP_INPUT_STATE_UART_INIT;
            }
            break;
        }

        case APP_INPUT_STATE_UART_INIT:
        {
            /* Register a callback for read events */
            UART_FUNC(ReadCallbackRegister)(usart_ReadEventHandler, (uintptr_t) NULL);

            /* Receive a callback for each character */
            UART_FUNC(ReadThresholdSet)(1);

            /* Enable RX event notifications */
            UART_FUNC(ReadNotificationEnable)(true, true);

            app_input.state = APP_INPUT_STATE_SERVICE_TASKS;

            break;
        }

        /* App Update Service Routine. */
        case APP_INPUT_STATE_SERVICE_TASKS:
        {
            if (app_input.error_status == true)
            {
                app_input.error_status = false;
                app_input.state        = APP_INPUT_STATE_ERROR;
                break;
            }

            if (app_input.guard_byte_checked == true &&
                app_input.guard_received   == true)
            {
                if (app_input.guard_match == false)
                {
                    /* Send error response to HOST-PC. */
                    send_Response(APP_INPUT_RESP_ERROR);

                    /* Wrong guard received, send response and wait for a valid guard data. */
                    app_input.state = APP_INPUT_STATE_ERROR;

                    app_input.guard_byte_checked  = false;
                    app_input.guard_received      = false;

                    break;
                }

                if (app_input.packet_received == true)
                {
                    app_input.guard_byte_checked = false;

                    resp = APP_INPUT_ServiceTasks();

                    if (resp == APP_INPUT_STATUS_ERROR)
                    {
                        app_input.state = APP_INPUT_STATE_ERROR;
                    }
                    else if (resp == APP_INPUT_STATUS_VERIFIED)
                    {
                        app_input.state = APP_INPUT_STATE_COMPLETE;
                    }
                    else if (resp == APP_INPUT_STATUS_UPDATE_REBOOT)
                    {
                        app_input.state = APP_INPUT_STATE_TRIGGER_SYS_RESET;
                    }
                    /* Update still in progress */
                }
                /* Wait for receiving the complete packet. */
            }
            else if (resp == APP_INPUT_STATUS_VERIFIED)
            {
                app_input.state = APP_INPUT_STATE_COMPLETE;
            }

            break;
        }

        /* Get ready for next App Update request. */
        case APP_INPUT_STATE_COMPLETE:
        {
            /* Update the Meta data for bootloader and trigger reset to
             * program new firmware in Internal flash
             */
            if (SWITCH_GET() == SWITCH_PRESSED)
            {
                while(SWITCH_GET() == SWITCH_PRESSED)
                {
                    
                }

                if (updateAppMetaData() == true)
                {
                    app_input.state = APP_INPUT_STATE_TRIGGER_SYS_RESET;
                }
            }
            /* Get ready for next firmware upgrade. */
            else if (app_input.guard_byte_checked == true)
            {
                /* Reset SST26 states */
                SERIAL_MEM_Reset();

                app_input.state   = APP_INPUT_STATE_SERVICE_TASKS;
            }

            break;
        }

        /* App Update Failed. */
        case APP_INPUT_STATE_ERROR:
        {
            app_input.guard_byte_checked  = false;
            app_input.guard_received      = false;
            app_input.guard_match         = false;
            app_input.packet_received     = false;


            SERIAL_MEM_Reset();

            resp = APP_INPUT_STATUS_ERROR;

            app_input.state   = APP_INPUT_STATE_SERVICE_TASKS;

            break;
        }

        /* Trigger System Reset. */
        case APP_INPUT_STATE_TRIGGER_SYS_RESET:
        {
            APP_SystemReset();
            break;
        }

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}
