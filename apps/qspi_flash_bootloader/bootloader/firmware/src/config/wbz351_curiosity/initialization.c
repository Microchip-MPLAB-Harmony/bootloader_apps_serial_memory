/*******************************************************************************
  System Initialization File

  File Name:
    initialization.c

  Summary:
    This file contains source code necessary to initialize the system.

  Description:
    This file contains source code necessary to initialize the system.  It
    implements the "SYS_Initialize" function, defines the configuration bits,
    and allocates any necessary global system resources,
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2025 Microchip Technology Inc. and its subsidiaries.
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
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "configuration.h"
#include "definitions.h"
#include "device.h"


// ****************************************************************************
// ****************************************************************************
// Section: Configuration Bits
// ****************************************************************************
// ****************************************************************************

/*** FUSERID ***/
#pragma config USER_ID =      0xffffU

/*** DEVCFG0 ***/
#pragma config SWOEN =      ON
#pragma config TROEN =      OFF
#pragma config ADCPOVR =      HW
#pragma config ACCMP1_ALTEN =      PA13
#pragma config CPENFILT =      OFF
#pragma config RTCIN0_ALTEN =      PA3
#pragma config RTCOUT_ALTEN =      PA4
#pragma config SMBUSEN0 =      OFF
#pragma config SMBUSEN1 =      OFF
#pragma config HPLUGDIS =      OFF
#pragma config SLRTEN0 =      OFF
#pragma config SLRTEN1 =      OFF
#pragma config SLRTEN2 =      OFF
#pragma config PCM =      SFR
#pragma config INT0E =      OFF
#pragma config INT0P =      NEG
#pragma config FECCCON =         OFF
#pragma config FRECCDIS =      OFF



/*** DEVCFG1 ***/
#pragma config TRCEN =      ON
#pragma config ECC_SEL_MEM =      ROWA
#pragma config ZBTWKSYS =      OFF
#pragma config CMP0_OE =      OFF
#pragma config CMP1_OE =      OFF
#pragma config SLRCTRL0 =      GPIO
#pragma config SLRCTRL1 =      GPIO
#pragma config SLRCTRL2 =      GPIO
#pragma config SMCLR =      NO_POR
#pragma config QSCHE_EN =      OFF
#pragma config QSPI_HSEN =      DIRECT
#pragma config SCOM0_HSEN =      PPS
#pragma config SCOM1_HSEN =      PPS
#pragma config CCL_OE =      ON
#pragma config I2CDSEL0 =      OFF
#pragma config I2CDSEL1 =      OFF
#pragma config I2CDSEL2 =      OFF
#pragma config WDTPSS =      PSS1048576
#pragma config QSPIDDRM =      OFF
#pragma config CLKZBREF =      OFF

/*** DEVCFG2 ***/
#pragma config ACMP_CYCLE =      _32US
#pragma config DMTINTV =      WIN_127_128
#pragma config PMUTEST_VDD_EN =      VDD_DIV_2
#pragma config POSCMOD =      HS
#pragma config WDTRMCS =      LPRC
#pragma config SOSCSEL =      XTAL
#pragma config WAKE2SPD =      ON
#pragma config CKSWEN =      ON
#pragma config FSCMEN =      ON
#pragma config WDTPSR =      PS1048576
#pragma config WDTSPGM =      STOPS
#pragma config WINDIS =      NORMAL
#pragma config WDTEN =      OFF
#pragma config WDTWINSZ =    WINSZ_25
#pragma config DMTCNT =      DMT31
#pragma config DMTEN =      OFF


/*** DEVCFG4 ***/
#pragma config SOSCCFG =    0x0U
#pragma config RTCEVENT_SEL =      ONE_SEC
#pragma config RTCEVENT_EN =      OFF
#pragma config VBKP_1KCSEL =      _32K
#pragma config VBKP_32KCSEL =      FRC
#pragma config VBKP_DIVSEL =      DIV_31_25
#pragma config LPCLK_MOD =      DIV_1
#pragma config RTCEVTYPE =      OUT
#pragma config CPEN_DLY =      _8_LPRC
#pragma config DSZPBOREN =      OFF
#pragma config DSWDTPS =      DSPS5
#pragma config DSWDTOSC =    LPRC
#pragma config DSWDTEN =      OFF
#pragma config DSEN =    OFF
#pragma config UVREGROVR =      CONTROLLED
#pragma config LPOSCEN =      OFF
#pragma config RTCNTM_CSEL =      RAW

/*** FBCFG0 ***/
#pragma config BINFOVALID =      VALID
#pragma config PCSCMODE =      DUAL

/*** FCPN0 ***/
#pragma config CP =      DISABLED





// *****************************************************************************
// *****************************************************************************
// Section: Driver Initialization Data
// *****************************************************************************
// *****************************************************************************
/* Following MISRA-C rules are deviated in the below code block */
/* MISRA C-2012 Rule 7.2 - Deviation record ID - H3_MISRAC_2012_R_7_2_DR_1 */
/* MISRA C-2012 Rule 11.1 - Deviation record ID - H3_MISRAC_2012_R_11_1_DR_1 */
/* MISRA C-2012 Rule 11.3 - Deviation record ID - H3_MISRAC_2012_R_11_3_DR_1 */
/* MISRA C-2012 Rule 11.8 - Deviation record ID - H3_MISRAC_2012_R_11_8_DR_1 */
// <editor-fold defaultstate="collapsed" desc="DRV_SST26 Initialization Data">

static const DRV_SST26_PLIB_INTERFACE drvSST26PlibAPI = {
    .CommandWrite   = QSPI_CommandWrite,
    .RegisterRead   = QSPI_RegisterRead,
    .RegisterWrite  = QSPI_RegisterWrite,
    .MemoryRead     = QSPI_MemoryRead,
    .MemoryWrite    = QSPI_MemoryWrite
};

static const DRV_SST26_INIT drvSST26InitData =
{
    .sst26Plib      = &drvSST26PlibAPI,
};
// </editor-fold>




// *****************************************************************************
// *****************************************************************************
// Section: System Data
// *****************************************************************************
// *****************************************************************************
/* Structure to hold the object handles for the modules in the system. */
SYSTEM_OBJECTS sysObj;

// *****************************************************************************
// *****************************************************************************
// Section: Library/Stack Initialization Data
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: System Initialization
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Local initialization functions
// *****************************************************************************
// *****************************************************************************

/* MISRAC 2012 deviation block end */

/*******************************************************************************
  Function:
    void SYS_Initialize ( void *data )

  Summary:
    Initializes the board, services, drivers, application and other modules.

  Remarks:
 */

void SYS_Initialize ( void* data )
{

    /* MISRAC 2012 deviation block start */
    /* MISRA C-2012 Rule 2.2 deviated in this file.  Deviation record ID -  H3_MISRAC_2012_R_2_2_DR_1 */

  
    CLOCK_Initialize();
    /* MISRAC 2012 deviation block start */
    /* MISRA C-2012 Rule 11.1 deviated 1 time. Deviation record ID -  H3_MISRAC_2012_R_11_1_DR_1 */

    /* Configure Prefetch, Wait States by calling the ROM function whose address is available at address 0xF2D0 */
    typedef void (*FUNC_PCHE_SETUP)(uint32_t setup);
    (void)((FUNC_PCHE_SETUP)(*(uint32_t*)0xF2D0))((PCHE_REGS->PCHE_CHECON & (~(PCHE_CHECON_PFMWS_Msk | PCHE_CHECON_ADRWS_Msk | PCHE_CHECON_PREFEN_Msk)))
                                    | (PCHE_CHECON_PFMWS(2) | PCHE_CHECON_PREFEN(1)  | PCHE_CHECON_ADRWS(0)));

    /* MISRAC 2012 deviation block end */



	GPIO_Initialize();

    QSPI_Initialize();

    EVSYS_Initialize();

    PAC_Initialize();

	BSP_Initialize();
    NVM_Initialize();


    /* MISRAC 2012 deviation block start */
    /* Following MISRA-C rules deviated in this block  */
    /* MISRA C-2012 Rule 11.3 - Deviation record ID - H3_MISRAC_2012_R_11_3_DR_1 */
    /* MISRA C-2012 Rule 11.8 - Deviation record ID - H3_MISRAC_2012_R_11_8_DR_1 */

    sysObj.drvSST26 = DRV_SST26_Initialize((SYS_MODULE_INDEX)DRV_SST26_INDEX, (SYS_MODULE_INIT *)&drvSST26InitData);




    /* MISRAC 2012 deviation block end */
    APP_Initialize();


    NVIC_Initialize();


    /* MISRAC 2012 deviation block end */
}

/*******************************************************************************
 End of File
*/
