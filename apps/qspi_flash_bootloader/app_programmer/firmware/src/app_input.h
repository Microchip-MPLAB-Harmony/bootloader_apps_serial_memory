/*******************************************************************************
  MPLAB Harmony UART input Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_input.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_INPUT_Initialize" and "APP_INPUT_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_INPUT_STATES" definition).  Both
    are defined here for convenience.
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

#ifndef _APP_INPUT_H
#define _APP_INPUT_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************


typedef enum
{
    APP_INPUT_CMD_UNLOCK        = 0xa0,
    APP_INPUT_CMD_DATA          = 0xa1,
    APP_INPUT_CMD_VERIFY        = 0xa2,
    APP_INPUT_CMD_UPDATE_REBOOT = 0xa3,
} T_APP_INPUT_CMD;

typedef enum
{
    APP_INPUT_RESP_OK          = 0x50,
    APP_INPUT_RESP_ERROR       = 0x51,
    APP_INPUT_RESP_INVALID     = 0x52,
    APP_INPUT_RESP_CRC_OK      = 0x53,
    APP_INPUT_RESP_CRC_FAIL    = 0x54,
} T_APP_INPUT_RESP;

typedef enum
{
    APP_INPUT_STATUS_ERROR = 0,
    APP_INPUT_STATUS_UNLOCK,
    APP_INPUT_STATUS_READY_FOR_FLASH,
    APP_INPUT_STATUS_FLASH_SUCCESS,
    APP_INPUT_STATUS_VERIFIED,
    APP_INPUT_STATUS_UPDATE_REBOOT,
} T_APP_INPUT_STATUS;

// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
    /* Application's state machine's initial state. */
    APP_INPUT_STATE_SERIAL_MEM_INIT=0,
    APP_INPUT_STATE_UART_INIT,
    APP_INPUT_STATE_SERVICE_TASKS,
    APP_INPUT_STATE_TRIGGER_SYS_RESET,
    APP_INPUT_STATE_ERROR,
    APP_INPUT_STATE_COMPLETE,
} APP_INPUT_STATES;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* The application's current state */
    APP_INPUT_STATES        state;

    volatile bool           error_status;

    volatile bool           guard_byte_checked;

    volatile uint8_t        input_command;

    volatile bool           packet_received;

    volatile bool           guard_match;

    volatile bool           guard_received;

    uint32_t                app_start_address;

    uint32_t                app_end_address;

    uint32_t                app_size;

    uint32_t                app_crc;

} APP_INPUT_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_INPUT_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_INPUT_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_INPUT_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_INPUT_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_INPUT_Tasks ( void )

  Summary:
    Starts the MPLAB Harmony Live Update execution.

  Description:
    This function can be used to start Live Update execution.

    The function runs only when there is a firmware update request from the HOST-PC via
    selected communication protocol to program into internal flash memory.

    Once the complete application is received, programmed and verified successfully.
    The most recent programmed application runs after the device reset.

    Note: This function never returns.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_INPUT_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_INPUT_Tasks( void );

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_INPUT_H */

/*******************************************************************************
 End of File
 */

