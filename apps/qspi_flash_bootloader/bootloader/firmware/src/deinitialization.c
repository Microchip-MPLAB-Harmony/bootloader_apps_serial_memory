/*******************************************************************************
  De-Initialization Source File

  Company:
    Microchip Technology Inc.

  File Name:
    deinitialization.c

  Summary:
    This file contains the "SYS_DeInitialize" function for a project.

  Description:
    This file contains the "SYS_DeInitialize" function for a project.  The
    SYS_DeInitialize() function has to be defined based on the device it is running
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

void CLOCK_DeInitialize(void)
{
    // Enable DFLL
    OSCCTRL_REGS->OSCCTRL_DFLLCTRLA = OSCCTRL_DFLLCTRLA_ENABLE_Msk ;
    // Configure CPU to run from DFLL Clock
    MCLK_REGS->MCLK_CPUDIV = MCLK_CPUDIV_DIV(0x01);
    while((MCLK_REGS->MCLK_INTFLAG & MCLK_INTFLAG_CKRDY_Msk) != MCLK_INTFLAG_CKRDY_Msk)
    {
        /* Wait for the Main Clock to be Ready */
    }
    GCLK_REGS->GCLK_GENCTRL[0] = GCLK_GENCTRL_DIV(1) | GCLK_GENCTRL_SRC(6) | GCLK_GENCTRL_GENEN_Msk;
    while((GCLK_REGS->GCLK_SYNCBUSY & GCLK_SYNCBUSY_GENCTRL_GCLK0) == GCLK_SYNCBUSY_GENCTRL_GCLK0)
    {
        /* wait for the Generator 0 synchronization */
    }
    /* Disable FDPLL0 */
    OSCCTRL_REGS->DPLL[0].OSCCTRL_DPLLCTRLA &= (~OSCCTRL_DPLLCTRLA_ENABLE_Msk)   ;
    while((OSCCTRL_REGS->DPLL[0].OSCCTRL_DPLLSYNCBUSY & OSCCTRL_DPLLSYNCBUSY_ENABLE_Msk) == OSCCTRL_DPLLSYNCBUSY_ENABLE_Msk )
    {
        /* Waiting for the DPLL enable synchronization */
    }
    /* Disable FDPLL1 */
    OSCCTRL_REGS->DPLL[1].OSCCTRL_DPLLCTRLA &= (~OSCCTRL_DPLLCTRLA_ENABLE_Msk)   ;
    while((OSCCTRL_REGS->DPLL[1].OSCCTRL_DPLLSYNCBUSY & OSCCTRL_DPLLSYNCBUSY_ENABLE_Msk) == OSCCTRL_DPLLSYNCBUSY_ENABLE_Msk )
    {
        /* Waiting for the DPLL enable synchronization */
    }
}

/* Fill this function to release or De-Initialize all the resources used 
 * It will be called by bootloader before jumping into application
 */
void SYS_DeInitialize( void)
{
    /* Reset CLOCK as it will Re-Initialized in application space */
    CLOCK_DeInitialize();
}
