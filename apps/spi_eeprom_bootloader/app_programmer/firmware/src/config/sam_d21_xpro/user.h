/*******************************************************************************
  User Configuration Header

  File Name:
    user.h

  Summary:
    Build-time configuration header for the user defined by this project.

  Description:
    An MPLAB Project may have multiple configurations.  This file defines the
    build-time options for a single configuration.

  Remarks:
    It only provides macro definitions for build-time configuration options

*******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#ifndef USER_H
#define USER_H

#include "bsp/bsp.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: User Configuration macros
// *****************************************************************************
// *****************************************************************************
#define LED_ON()                LED_On()
#define LED_OFF()               LED_Off()
#define LED_TOGGLE()            LED_Toggle()

#define SWITCH_GET()            SWITCH_Get()
#define SWITCH_PRESSED          SWITCH_STATE_PRESSED

#define FLASH_START             (0x00000000UL)
#define FLASH_LENGTH            (0x40000UL)
#define PAGE_SIZE               (64UL)
#define ERASE_BLOCK_SIZE        (256UL)
#define PAGES_IN_ERASE_BLOCK    (ERASE_BLOCK_SIZE / PAGE_SIZE)

#define APP_JUMP_ADDRESS_OFFSET (0x0)

#define APP_TIMER_START         SYSTICK_TimerStart
#define APP_TIMER_DelayMs       SYSTICK_DelayMs

#define UART_FUNC(OP)           (SERCOM3_USART_ ## OP)

#define INPUT_EVENT             SERCOM_USART_EVENT
#define INPUT_EVENT_READ_ERROR  SERCOM_USART_EVENT_READ_ERROR
#define INPUT_ERROR_NONE        USART_ERROR_NONE

#define USE_HW_CRC_GEN          true

/* On SAMD21 CRC32 Computation fails on RAM buffer.
 * Below Magic code have to be used before and after computing CRC32
 * for proper value CRC32 Value
 * ERRATA: "1.8.3 CRC32 Computation Failure"
 */
#define DSU_ERRATA_FIX_BEFORE_CRC   (*((volatile unsigned int*) 0x41007058) &= ~0x30000UL)
#define DSU_ERRATA_FIX_AFTER_CRC    (*((volatile unsigned int*) 0x41007058) |= 0x20000UL)

static inline void APP_SystemReset( void )
{
    NVIC_SystemReset();
}


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // USER_H
/*******************************************************************************
 End of File
*/
