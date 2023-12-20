/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_monitor.c

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
#include "app_monitor.h"
#include "sdcard.h"
#include "serial_mem.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

#define BTL_TRIGGER_PATTERN     (0x5048434DUL)

#define TIMER_DELAY_BOOT_MS     3000
#define TIMER_DELAY_MS          1000

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_MONITOR_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_MONITOR_DATA app_monitorData;

static uint32_t *ramStart = (uint32_t *)BTL_TRIGGER_RAM_START;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void timerCallback(uintptr_t context)
{
    LED_TOGGLE();
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_MONITOR_Initialize ( void )

  Remarks:
    See prototype in app_monitor.h.
 */

void APP_MONITOR_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_monitorData.state = APP_MONITOR_INIT;

}


/******************************************************************************
  Function:
    void APP_MONITOR_Tasks ( void )

  Remarks:
    See prototype in app_monitor.h.
 */

void APP_MONITOR_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( app_monitorData.state )
    {
        /* Application's initial state. */
        case APP_MONITOR_INIT:
        {
            /* Add Delay for the UART Console to get enumerated after reset */
            app_monitorData.timerHandle = SYS_TIME_HANDLE_INVALID;

            if (SYS_TIME_DelayMS(TIMER_DELAY_BOOT_MS, &app_monitorData.timerHandle) != SYS_TIME_SUCCESS)
            {
                app_monitorData.state = APP_MONITOR_ERROR;

                break;
            }

            if(SYS_TIME_DelayIsComplete(app_monitorData.timerHandle) != true)
            {
                // Wait till the delay has not expired
                while (SYS_TIME_DelayIsComplete(app_monitorData.timerHandle) == false)
                {

                }
            }

            printf("\r\n--------------------------------------------------------------------------------\r\n");

            printf("\r\n###### File System (Serial Memory) Programmer Application Running ######\r\n");

            /* Register a 1 Second periodic callback with time system service to Blink LED */
            app_monitorData.timerHandle = SYS_TIME_HANDLE_INVALID;

            app_monitorData.timerHandle = SYS_TIME_CallbackRegisterMS(timerCallback, (uintptr_t)&app_monitorData, TIMER_DELAY_MS, SYS_TIME_PERIODIC);

            if (app_monitorData.timerHandle == SYS_TIME_HANDLE_INVALID)
            {
                printf("\r\n!!!!!! ERROR: Unable To Start Periodic Timer !!!!!!\r\n");

                app_monitorData.state = APP_MONITOR_ERROR;
            }
            else
            {
                app_monitorData.state = APP_MONITOR_WAIT_FOR_COMPLETE;
            }

            break;
        }

        case APP_MONITOR_WAIT_FOR_COMPLETE:
        {
            /* Wait for Image binary to be copied in Serial memory */
            if (SDCARD_getCurrentStatus() == SDCARD_STATUS_UPDATE_COMPLETE)
            {
                printf("\r\n\r\n###### Copied Image Binary To Serial Memory ######\r\n");

                printf("\r\n###### Eject SD Card And " BTL_TRIGGER_METHOD " To Trigger FS Bootloader ######\r\n");

                 app_monitorData.state = APP_MONITOR_WAIT_FOR_SWITCH_PRESS;
            }

            break;
        }


        case APP_MONITOR_WAIT_FOR_SWITCH_PRESS:
        {
            /* Wait for switch press to trigger Bootloader */
            if (SWITCH_GET() == SWITCH_PRESSED)
            {
                while(SWITCH_GET() == SWITCH_PRESSED)
                {

                }

                printf("\r\n###### FS Bootloader Triggered To Program Image Binary In Internal Flash ######\r\n\r\n");

                app_monitorData.state = APP_MONITOR_TRIGGER_SYS_RESET;
            }

            break;
        }

        case APP_MONITOR_TRIGGER_SYS_RESET:
        {
            /* Load Bootloader trigger pattern and initiate reset */
            ramStart[0] = BTL_TRIGGER_PATTERN;
            ramStart[1] = BTL_TRIGGER_PATTERN;
            ramStart[2] = BTL_TRIGGER_PATTERN;
            ramStart[3] = BTL_TRIGGER_PATTERN;

            DCACHE_CLEAN_BY_ADDR(ramStart, 16);

            APP_SystemReset();

            break;
        }

        case APP_MONITOR_IDLE:
        {
            break;
        }

        case APP_MONITOR_ERROR:
        {
            LED_ON();
            break;
        }

        default:
        {
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
