/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_pic32cz_ca.c

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app_pic32cz_ca.h"
#include "definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_PIC32CZ_CA_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_PIC32CZ_CA_DATA app_pic32cz_caData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

#define BTL_TRIGGER_PATTERN (0x5048434DUL)

static uint32_t *ramStart = (uint32_t *)BTL_TRIGGER_RAM_START;

bool bootloader_Trigger(void)
{
    uint32_t i;

    // Cheap delay. This should give at leat 1 ms delay.
    for (i = 0; i < 2000; i++)
    {
        asm("nop");
    }

    if (RSTC_REGS->RSTC_RCAUSE & (RSTC_RCAUSE_WDT_Msk | RSTC_RCAUSE_SYST_Msk))
    {
        /* Check for Bootloader Trigger Pattern in first 16 Bytes of RAM to enter
         * Bootloader.
         */
        if (BTL_TRIGGER_PATTERN == ramStart[0] && BTL_TRIGGER_PATTERN == ramStart[1] &&
            BTL_TRIGGER_PATTERN == ramStart[2] && BTL_TRIGGER_PATTERN == ramStart[3])
        {
            ramStart[0] = 0;

            DCACHE_CLEAN_BY_ADDR(ramStart, 4);

            return true;
        }
    }

    /* Check for Switch press to enter Bootloader */
    if (SWITCH_GET() == SWITCH_PRESSED)
    {
        return true;
    }

    return false;
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_PIC32CZ_CA_Initialize ( void )

  Remarks:
    See prototype in app_pic32cz_ca.h.
 */

void APP_PIC32CZ_CA_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_pic32cz_caData.state = APP_PIC32CZ_CA_STATE_INIT;



    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_PIC32CZ_CA_Tasks ( void )

  Remarks:
    See prototype in app_pic32cz_ca.h.
 */

void APP_PIC32CZ_CA_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( app_pic32cz_caData.state )
    {
        /* Application's initial state. */
        case APP_PIC32CZ_CA_STATE_INIT:
        {
            LED_ON();
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


/*******************************************************************************
 End of File
 */
