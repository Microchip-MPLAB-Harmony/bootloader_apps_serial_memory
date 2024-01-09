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

#ifndef USER_H
#define USER_H

#include "bsp/bsp.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END
#define LED_ON()                RGB_LED_BLUE_On()
#define LED_OFF()               RGB_LED_BLUE_Off()
#define LED_TOGGLE()            RGB_LED_BLUE_Toggle()

#define SWITCH_GET()            SWITCH3_Get()
#define SWITCH_PRESSED          SWITCH3_STATE_PRESSED

#define FLASH_START             (0x01001000)
#define FLASH_LENGTH            (0x80000)
#define PAGE_SIZE               (1024UL)
#define ERASE_BLOCK_SIZE        (4096UL)
#define PAGES_IN_ERASE_BLOCK    (ERASE_BLOCK_SIZE / PAGE_SIZE)

#define APP_JUMP_ADDRESS_OFFSET (0x0)

#define APP_TIMER_START         SYSTICK_TimerStart
#define APP_TIMER_DelayMs       SYSTICK_DelayMs

#define UART_FUNC(OP)           (SERCOM0_USART_ ## OP)

#define INPUT_EVENT             SERCOM_USART_EVENT
#define INPUT_EVENT_READ_ERROR  SERCOM_USART_EVENT_READ_ERROR
#define INPUT_ERROR_NONE        USART_ERROR_NONE

#define USE_HW_CRC_GEN          true

static inline void APP_SystemReset( void )
{
    NVIC_SystemReset();
}
// *****************************************************************************
// *****************************************************************************
// Section: User Configuration macros
// *****************************************************************************
// *****************************************************************************


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // USER_H
/*******************************************************************************
 End of File
*/
