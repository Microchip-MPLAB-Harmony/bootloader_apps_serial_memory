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
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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
#pragma config FUSES_USERCFG1_FSEQ0_SEQNUM = 0x1U
#pragma config FUSES_USERCFG1_FSEQ0_SEQBAR = 0xfffeU
#pragma config FUSES_USERCFG1_FSEQ1_SEQNUM = 0x1U
#pragma config FUSES_USERCFG1_FSEQ1_SEQBAR = 0xfffeU
#pragma config FUSES_USERCFG1_FSEQ2_SEQNUM = 0x1U
#pragma config FUSES_USERCFG1_FSEQ2_SEQBAR = 0xfffeU
#pragma config FUSES_USERCFG1_FSEQ3_SEQNUM = 0x1U
#pragma config FUSES_USERCFG1_FSEQ3_SEQBAR = 0xfffeU
#pragma config FUSES_USERCFG1_FSEQ4_SEQNUM = 0x1U
#pragma config FUSES_USERCFG1_FSEQ4_SEQBAR = 0xfffeU
#pragma config FUSES_USERCFG1_FSEQ5_SEQNUM = 0x1U
#pragma config FUSES_USERCFG1_FSEQ5_SEQBAR = 0xfffeU
#pragma config FUSES_USERCFG1_FSEQ6_SEQNUM = 0x1U
#pragma config FUSES_USERCFG1_FSEQ6_SEQBAR = 0xfffeU
#pragma config FUSES_USERCFG1_FSEQ7_SEQNUM = 0x1U
#pragma config FUSES_USERCFG1_FSEQ7_SEQBAR = 0xfffeU
#pragma config FUSES_USERCFG1_AFSEQ0_ASEQNUM = 0xffffU
#pragma config FUSES_USERCFG1_AFSEQ0_ASEQBAR = 0xffffU
#pragma config FUSES_USERCFG1_AFSEQ1_ASEQNUM = 0xffffU
#pragma config FUSES_USERCFG1_AFSEQ1_ASEQBAR = 0xffffU
#pragma config FUSES_USERCFG1_AFSEQ2_ASEQNUM = 0xffffU
#pragma config FUSES_USERCFG1_AFSEQ2_ASEQBAR = 0xffffU
#pragma config FUSES_USERCFG1_AFSEQ3_ASEQNUM = 0xffffU
#pragma config FUSES_USERCFG1_AFSEQ3_ASEQBAR = 0xffffU
#pragma config FUSES_USERCFG1_AFSEQ4_ASEQNUM = 0xffffU
#pragma config FUSES_USERCFG1_AFSEQ4_ASEQBAR = 0xffffU
#pragma config FUSES_USERCFG1_AFSEQ5_ASEQNUM = 0xffffU
#pragma config FUSES_USERCFG1_AFSEQ5_ASEQBAR = 0xffffU
#pragma config FUSES_USERCFG1_AFSEQ6_ASEQNUM = 0xffffU
#pragma config FUSES_USERCFG1_AFSEQ6_ASEQBAR = 0xffffU
#pragma config FUSES_USERCFG1_AFSEQ7_ASEQNUM = 0xffffU
#pragma config FUSES_USERCFG1_AFSEQ7_ASEQBAR = 0xffffU
#pragma config FUSES_USERCFG1_FUCFG0_WDT_ENABLE = CLEAR
#pragma config FUSES_USERCFG1_FUCFG0_WDT_WEN = CLEAR
#pragma config FUSES_USERCFG1_FUCFG0_WDT_RUNSTDBY = CLEAR
#pragma config FUSES_USERCFG1_FUCFG0_WDT_ALWAYSON = CLEAR
#pragma config FUSES_USERCFG1_FUCFG0_WDT_PER = 0x0U
#pragma config FUSES_USERCFG1_FUCFG0_WDT_WINDOW = 0x0U
#pragma config FUSES_USERCFG1_FUCFG0_WDT_EWOFFSET = 0x0U
#pragma config FUSES_USERCFG1_FUCFG1_FUCFG1 = 0xffffffffU
#pragma config FUSES_USERCFG1_FUCFG2_BRCFGUDSSMOR_BOR_HYST = SET
#pragma config FUSES_USERCFG1_FUCFG2_BRCFGUDSSMOR_BOR_TRIP = 0x3U
#pragma config FUSES_USERCFG1_FUCFG3_HYST_BOR_VDDIO = SET
#pragma config FUSES_USERCFG1_FUCFG3_BOR_TRIP_VDDIO = 0x3U
#pragma config FUSES_USERCFG1_FUCFG3_HYST_BOR_VDDIOB = SET
#pragma config FUSES_USERCFG1_FUCFG3_BOR_TRIP_VDDIOB = 0x3U
#pragma config FUSES_USERCFG1_FUCFG3_HYST_BOR_VDDA = SET
#pragma config FUSES_USERCFG1_FUCFG3_BOR_TRIP_VDDA = 0x3U
#pragma config FUSES_USERCFG1_FUCFG3_HYST_BOR_VDDREG = SET
#pragma config FUSES_USERCFG1_FUCFG5_UCP0 = 0xfU
#pragma config FUSES_USERCFG1_FUCFG5_UCP1 = 0xfU
#pragma config FUSES_USERCFG1_FUCFG6_PFM_ECCCTL = 0x3U
#pragma config FUSES_USERCFG1_FUCFG6_PFM_ECCUNLCK = SET
#pragma config FUSES_USERCFG1_FUCFG6_PFM_SECCNT = 0x0U
#pragma config FUSES_USERCFG1_FUCFG7_PFM_TEMP = SET
#pragma config FUSES_USERCFG1_FUCFG8_PFM_UC1WP = CLEAR
#pragma config FUSES_USERCFG1_FUCFG8_PFM_UC2WP = CLEAR
#pragma config FUSES_USERCFG1_FUCFG8_PFM_UC1WPLOCK = CLEAR
#pragma config FUSES_USERCFG1_FUCFG8_PFM_UC2WPLOCK = CLEAR
#pragma config FUSES_USERCFG1_FUCFG9_FUCFG9 = 0x202U
#pragma config FUSES_BOOTCFG1_BLDRCFG_PFM_BCRP = CLEAR
#pragma config FUSES_BOOTCFG1_BLDRCFG_PFM_BCWP = CLEAR
#pragma config FUSES_BOOTCFG1_BLDRCFG_BROM_EN_BFMCHK = NONE
#pragma config FUSES_BOOTCFG1_BLDRCFG_BROM_EN_PLL = CLEAR
#pragma config FUSES_BOOTCFG1_BLDRCFG_BROM_EN_DALUN = SET
#pragma config FUSES_BOOTCFG1_BLDRCFG_BROM_EN_RWLOCKS = SET
#pragma config FUSES_BOOTCFG1_BROM_BSEQ_SEQNUM = 0x1U
#pragma config FUSES_BOOTCFG1_BROM_BSEQ_SEQBAR = 0xfffeU
#pragma config FUSES_BOOTCFG1_BFM_CHK_TABLEPTR_BFM_CHK_TABLEPTR = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_TZ1_CE_NS0_KEYVAL_TZ1_CE_NS = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_TZ1_CE_NS1_KEYVAL_TZ1_CE_NS = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_TZ1_CE_NS2_KEYVAL_TZ1_CE_NS = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_TZ1_CE_NS3_KEYVAL_TZ1_CE_NS = 0xffffffffU
#pragma config FUSES_BOOTCFG1_CELOCK_TZ1_CE_NS0_CELOCK_TZ1_CE_NS = 0xffffffffU
#pragma config FUSES_BOOTCFG1_CELOCK_TZ1_CE_NS1_CELOCK_TZ1_CE_NS = 0xffffffffU
#pragma config FUSES_BOOTCFG1_CELOCK_TZ1_CE_NS2_CELOCK_TZ1_CE_NS = 0xffffffffU
#pragma config FUSES_BOOTCFG1_CELOCK_TZ1_CE_NS3_CELOCK_TZ1_CE_NS = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_TZ1_CE_S0_KEYVAL_TZ1_CE_S = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_TZ1_CE_S1_KEYVAL_TZ1_CE_S = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_TZ1_CE_S2_KEYVAL_TZ1_CE_S = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_TZ1_CE_S3_KEYVAL_TZ1_CE_S = 0xffffffffU
#pragma config FUSES_BOOTCFG1_CELOCK_TZ1_CE_S0_CELOCK_TZ1_CE_S = 0xffffffffU
#pragma config FUSES_BOOTCFG1_CELOCK_TZ1_CE_S1_CELOCK_TZ1_CE_S = 0xffffffffU
#pragma config FUSES_BOOTCFG1_CELOCK_TZ1_CE_S2_CELOCK_TZ1_CE_S = 0xffffffffU
#pragma config FUSES_BOOTCFG1_CELOCK_TZ1_CE_S3_CELOCK_TZ1_CE_S = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_TZ1_CE_ALL0_KEYVAL_TZ1_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_TZ1_CE_ALL1_KEYVAL_TZ1_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_TZ1_CE_ALL2_KEYVAL_TZ1_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_TZ1_CE_ALL3_KEYVAL_TZ1_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG1_CELOCK_TZ1_CE_ALL0_CELOCK_TZ1_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG1_CELOCK_TZ1_CE_ALL1_CELOCK_TZ1_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG1_CELOCK_TZ1_CE_ALL2_CELOCK_TZ1_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG1_CELOCK_TZ1_CE_ALL3_CELOCK_TZ1_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_TZ0_CE_ALL0_KEYVAL_TZ0_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_TZ0_CE_ALL1_KEYVAL_TZ0_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_TZ0_CE_ALL2_KEYVAL_TZ0_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_TZ0_CE_ALL3_KEYVAL_TZ0_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG1_CELOCK_TZ0_CE_ALL0_CELOCK_TZ0_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG1_CELOCK_TZ0_CE_ALL1_CELOCK_TZ0_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG1_CELOCK_TZ0_CE_ALL2_CELOCK_TZ0_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG1_CELOCK_TZ0_CE_ALL3_CELOCK_TZ0_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_CRCCMD0_KEYVAL_CRCCMD = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_CRCCMD1_KEYVAL_CRCCMD = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_CRCCMD2_KEYVAL_CRCCMD = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_CRCCMD3_KEYVAL_CRCCMD = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYCONFIG_CRCCMD0_KEYCONFIG_CRCCMD = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYCONFIG_CRCCMD1_KEYCONFIG_CRCCMD = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYCONFIG_CRCCMD2_KEYCONFIG_CRCCMD = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYCONFIG_CRCCMD3_KEYCONFIG_CRCCMD = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_HOSTDALELEV0_KEYVAL_HOSTDALELEV = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_HOSTDALELEV1_KEYVAL_HOSTDALELEV = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_HOSTDALELEV2_KEYVAL_HOSTDALELEV = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYVAL_HOSTDALELEV3_KEYVAL_HOSTDALELEV = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYCONFIG_HOSTDALELEV0_KEYCONFIG_HOSTDALELEV = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYCONFIG_HOSTDALELEV1_KEYCONFIG_HOSTDALELEV = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYCONFIG_HOSTDALELEV2_KEYCONFIG_HOSTDALELEV = 0xffffffffU
#pragma config FUSES_BOOTCFG1_KEYCONFIG_HOSTDALELEV3_KEYCONFIG_HOSTDALELEV = 0xffffffffU
#pragma config FUSES_BOOTCFG1_ROM_CTRLA_ROM_CTRLA = 0x706U
#pragma config FUSES_BOOTCFG1_FCR_CTRLA_FCR_CTRLA = 0xfcf04U
#pragma config FUSES_BOOTCFG1_RPMU_VREGCTRL_RPMU_VREGCTRL = 0x707f736U
#pragma config FUSES_BOOTCFG1_PLL0_CTRL_PLL0_CTRL = 0x3a86U
#pragma config FUSES_BOOTCFG1_PLL0_FBDIV_PLL0_FBDIV = 0x3ffU
#pragma config FUSES_BOOTCFG1_PLL0_REFDIV_PLL0_REFDIV = 0x3fU
#pragma config FUSES_BOOTCFG1_PLL0_POSTDIVA_PLL0_POSTDIVA = 0xbfU
#pragma config FUSES_BOOTCFG1_MCLK_CLKDIV1_MCLK_CLKDIV1 = 0xffffffffU
#pragma config FUSES_BOOTCFG1_GCLK_GENCTRL0_GCLK_GENCTRL0 = 0xffffffffU
#pragma config FUSES_BOOTCFG1_BROM_BOOTCFGCRC0_BROM_BOOTCFGCRC = 0xffffffffU
#pragma config FUSES_BOOTCFG1_BROM_BOOTCFGCRC1_BROM_BOOTCFGCRC = 0xffffffffU
#pragma config FUSES_BOOTCFG1_BROM_BOOTCFGCRC2_BROM_BOOTCFGCRC = 0xffffffffU
#pragma config FUSES_BOOTCFG1_BROM_BOOTCFGCRC3_BROM_BOOTCFGCRC = 0xffffffffU
#pragma config FUSES_BOOTCFG1_BROM_PAGEEND_BROM_PAGEEND = 0xffffffffU
#pragma config FUSES_USERCFG2_FSEQ0_SEQNUM = 0x0U
#pragma config FUSES_USERCFG2_FSEQ0_SEQBAR = 0xffffU
#pragma config FUSES_USERCFG2_FSEQ1_SEQNUM = 0x0U
#pragma config FUSES_USERCFG2_FSEQ1_SEQBAR = 0xffffU
#pragma config FUSES_USERCFG2_FSEQ2_SEQNUM = 0x0U
#pragma config FUSES_USERCFG2_FSEQ2_SEQBAR = 0xffffU
#pragma config FUSES_USERCFG2_FSEQ3_SEQNUM = 0x0U
#pragma config FUSES_USERCFG2_FSEQ3_SEQBAR = 0xffffU
#pragma config FUSES_USERCFG2_FSEQ4_SEQNUM = 0x0U
#pragma config FUSES_USERCFG2_FSEQ4_SEQBAR = 0xffffU
#pragma config FUSES_USERCFG2_FSEQ5_SEQNUM = 0x0U
#pragma config FUSES_USERCFG2_FSEQ5_SEQBAR = 0xffffU
#pragma config FUSES_USERCFG2_FSEQ6_SEQNUM = 0x0U
#pragma config FUSES_USERCFG2_FSEQ6_SEQBAR = 0xffffU
#pragma config FUSES_USERCFG2_FSEQ7_SEQNUM = 0x0U
#pragma config FUSES_USERCFG2_FSEQ7_SEQBAR = 0xffffU
#pragma config FUSES_USERCFG2_AFSEQ0_ASEQNUM = 0xffffU
#pragma config FUSES_USERCFG2_AFSEQ0_ASEQBAR = 0xffffU
#pragma config FUSES_USERCFG2_AFSEQ1_ASEQNUM = 0xffffU
#pragma config FUSES_USERCFG2_AFSEQ1_ASEQBAR = 0xffffU
#pragma config FUSES_USERCFG2_AFSEQ2_ASEQNUM = 0xffffU
#pragma config FUSES_USERCFG2_AFSEQ2_ASEQBAR = 0xffffU
#pragma config FUSES_USERCFG2_AFSEQ3_ASEQNUM = 0xffffU
#pragma config FUSES_USERCFG2_AFSEQ3_ASEQBAR = 0xffffU
#pragma config FUSES_USERCFG2_AFSEQ4_ASEQNUM = 0xffffU
#pragma config FUSES_USERCFG2_AFSEQ4_ASEQBAR = 0xffffU
#pragma config FUSES_USERCFG2_AFSEQ5_ASEQNUM = 0xffffU
#pragma config FUSES_USERCFG2_AFSEQ5_ASEQBAR = 0xffffU
#pragma config FUSES_USERCFG2_AFSEQ6_ASEQNUM = 0xffffU
#pragma config FUSES_USERCFG2_AFSEQ6_ASEQBAR = 0xffffU
#pragma config FUSES_USERCFG2_AFSEQ7_ASEQNUM = 0xffffU
#pragma config FUSES_USERCFG2_AFSEQ7_ASEQBAR = 0xffffU
#pragma config FUSES_USERCFG2_FUCFG0_WDT_ENABLE = CLEAR
#pragma config FUSES_USERCFG2_FUCFG0_WDT_WEN = SET
#pragma config FUSES_USERCFG2_FUCFG0_WDT_RUNSTDBY = SET
#pragma config FUSES_USERCFG2_FUCFG0_WDT_ALWAYSON = CLEAR
#pragma config FUSES_USERCFG2_FUCFG0_WDT_PER = 0x0U
#pragma config FUSES_USERCFG2_FUCFG0_WDT_WINDOW = 0x0U
#pragma config FUSES_USERCFG2_FUCFG0_WDT_EWOFFSET = 0x0U
#pragma config FUSES_USERCFG2_FUCFG1_FUCFG1 = 0xffffffffU
#pragma config FUSES_USERCFG2_FUCFG2_BRCFGUDSSMOR_BOR_HYST = SET
#pragma config FUSES_USERCFG2_FUCFG2_BRCFGUDSSMOR_BOR_TRIP = 0x3U
#pragma config FUSES_USERCFG2_FUCFG3_HYST_BOR_VDDIO = SET
#pragma config FUSES_USERCFG2_FUCFG3_BOR_TRIP_VDDIO = 0x3U
#pragma config FUSES_USERCFG2_FUCFG3_HYST_BOR_VDDIOB = SET
#pragma config FUSES_USERCFG2_FUCFG3_BOR_TRIP_VDDIOB = 0x3U
#pragma config FUSES_USERCFG2_FUCFG3_HYST_BOR_VDDA = SET
#pragma config FUSES_USERCFG2_FUCFG3_BOR_TRIP_VDDA = 0x3U
#pragma config FUSES_USERCFG2_FUCFG3_HYST_BOR_VDDREG = SET
#pragma config FUSES_USERCFG2_FUCFG5_UCP0 = 0xfU
#pragma config FUSES_USERCFG2_FUCFG5_UCP1 = 0xfU
#pragma config FUSES_USERCFG2_FUCFG6_PFM_ECCCTL = 0x3U
#pragma config FUSES_USERCFG2_FUCFG6_PFM_ECCUNLCK = SET
#pragma config FUSES_USERCFG2_FUCFG6_PFM_SECCNT = 0x0U
#pragma config FUSES_USERCFG2_FUCFG7_PFM_TEMP = SET
#pragma config FUSES_USERCFG2_FUCFG8_PFM_UC1WP = CLEAR
#pragma config FUSES_USERCFG2_FUCFG8_PFM_UC2WP = CLEAR
#pragma config FUSES_USERCFG2_FUCFG8_PFM_UC1WPLOCK = CLEAR
#pragma config FUSES_USERCFG2_FUCFG8_PFM_UC2WPLOCK = CLEAR
#pragma config FUSES_USERCFG2_FUCFG9_FUCFG9 = 0x202U
#pragma config FUSES_BOOTCFG2_BLDRCFG_PFM_BCRP = CLEAR
#pragma config FUSES_BOOTCFG2_BLDRCFG_PFM_BCWP = CLEAR
#pragma config FUSES_BOOTCFG2_BLDRCFG_BROM_EN_BFMCHK = NONE
#pragma config FUSES_BOOTCFG2_BLDRCFG_BROM_EN_PLL = CLEAR
#pragma config FUSES_BOOTCFG2_BLDRCFG_BROM_EN_DALUN = SET
#pragma config FUSES_BOOTCFG2_BLDRCFG_BROM_EN_RWLOCKS = SET
#pragma config FUSES_BOOTCFG2_BROM_BSEQ_SEQNUM = 0x0U
#pragma config FUSES_BOOTCFG2_BROM_BSEQ_SEQBAR = 0xffffU
#pragma config FUSES_BOOTCFG2_BFM_CHK_TABLEPTR_BFM_CHK_TABLEPTR = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_TZ1_CE_NS0_KEYVAL_TZ1_CE_NS = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_TZ1_CE_NS1_KEYVAL_TZ1_CE_NS = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_TZ1_CE_NS2_KEYVAL_TZ1_CE_NS = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_TZ1_CE_NS3_KEYVAL_TZ1_CE_NS = 0xffffffffU
#pragma config FUSES_BOOTCFG2_CELOCK_TZ1_CE_NS0_CELOCK_TZ1_CE_NS = 0xffffffffU
#pragma config FUSES_BOOTCFG2_CELOCK_TZ1_CE_NS1_CELOCK_TZ1_CE_NS = 0xffffffffU
#pragma config FUSES_BOOTCFG2_CELOCK_TZ1_CE_NS2_CELOCK_TZ1_CE_NS = 0xffffffffU
#pragma config FUSES_BOOTCFG2_CELOCK_TZ1_CE_NS3_CELOCK_TZ1_CE_NS = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_TZ1_CE_S0_KEYVAL_TZ1_CE_S = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_TZ1_CE_S1_KEYVAL_TZ1_CE_S = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_TZ1_CE_S2_KEYVAL_TZ1_CE_S = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_TZ1_CE_S3_KEYVAL_TZ1_CE_S = 0xffffffffU
#pragma config FUSES_BOOTCFG2_CELOCK_TZ1_CE_S0_CELOCK_TZ1_CE_S = 0xffffffffU
#pragma config FUSES_BOOTCFG2_CELOCK_TZ1_CE_S1_CELOCK_TZ1_CE_S = 0xffffffffU
#pragma config FUSES_BOOTCFG2_CELOCK_TZ1_CE_S2_CELOCK_TZ1_CE_S = 0xffffffffU
#pragma config FUSES_BOOTCFG2_CELOCK_TZ1_CE_S3_CELOCK_TZ1_CE_S = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_TZ1_CE_ALL0_KEYVAL_TZ1_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_TZ1_CE_ALL1_KEYVAL_TZ1_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_TZ1_CE_ALL2_KEYVAL_TZ1_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_TZ1_CE_ALL3_KEYVAL_TZ1_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG2_CELOCK_TZ1_CE_ALL0_CELOCK_TZ1_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG2_CELOCK_TZ1_CE_ALL1_CELOCK_TZ1_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG2_CELOCK_TZ1_CE_ALL2_CELOCK_TZ1_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG2_CELOCK_TZ1_CE_ALL3_CELOCK_TZ1_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_TZ0_CE_ALL0_KEYVAL_TZ0_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_TZ0_CE_ALL1_KEYVAL_TZ0_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_TZ0_CE_ALL2_KEYVAL_TZ0_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_TZ0_CE_ALL3_KEYVAL_TZ0_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG2_CELOCK_TZ0_CE_ALL0_CELOCK_TZ0_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG2_CELOCK_TZ0_CE_ALL1_CELOCK_TZ0_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG2_CELOCK_TZ0_CE_ALL2_CELOCK_TZ0_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG2_CELOCK_TZ0_CE_ALL3_CELOCK_TZ0_CE_ALL = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_CRCCMD0_KEYVAL_CRCCMD = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_CRCCMD1_KEYVAL_CRCCMD = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_CRCCMD2_KEYVAL_CRCCMD = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_CRCCMD3_KEYVAL_CRCCMD = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYCONFIG_CRCCMD0_KEYCONFIG_CRCCMD = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYCONFIG_CRCCMD1_KEYCONFIG_CRCCMD = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYCONFIG_CRCCMD2_KEYCONFIG_CRCCMD = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYCONFIG_CRCCMD3_KEYCONFIG_CRCCMD = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_HOSTDALELEV0_KEYVAL_HOSTDALELEV = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_HOSTDALELEV1_KEYVAL_HOSTDALELEV = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_HOSTDALELEV2_KEYVAL_HOSTDALELEV = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYVAL_HOSTDALELEV3_KEYVAL_HOSTDALELEV = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYCONFIG_HOSTDALELEV0_KEYCONFIG_HOSTDALELEV = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYCONFIG_HOSTDALELEV1_KEYCONFIG_HOSTDALELEV = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYCONFIG_HOSTDALELEV2_KEYCONFIG_HOSTDALELEV = 0xffffffffU
#pragma config FUSES_BOOTCFG2_KEYCONFIG_HOSTDALELEV3_KEYCONFIG_HOSTDALELEV = 0xffffffffU
#pragma config FUSES_BOOTCFG2_ROM_CTRLA_ROM_CTRLA = 0x706U
#pragma config FUSES_BOOTCFG2_FCR_CTRLA_FCR_CTRLA = 0xfcf04U
#pragma config FUSES_BOOTCFG2_RPMU_VREGCTRL_RPMU_VREGCTRL = 0x707f736U
#pragma config FUSES_BOOTCFG2_PLL0_CTRL_PLL0_CTRL = 0x3a86U
#pragma config FUSES_BOOTCFG2_PLL0_FBDIV_PLL0_FBDIV = 0x3ffU
#pragma config FUSES_BOOTCFG2_PLL0_REFDIV_PLL0_REFDIV = 0x3fU
#pragma config FUSES_BOOTCFG2_PLL0_POSTDIVA_PLL0_POSTDIVA = 0xbfU
#pragma config FUSES_BOOTCFG2_MCLK_CLKDIV1_MCLK_CLKDIV1 = 0xffffffffU
#pragma config FUSES_BOOTCFG2_GCLK_GENCTRL0_GCLK_GENCTRL0 = 0xffffffffU
#pragma config FUSES_BOOTCFG2_BROM_BOOTCFGCRC0_BROM_BOOTCFGCRC = 0xffffffffU
#pragma config FUSES_BOOTCFG2_BROM_BOOTCFGCRC1_BROM_BOOTCFGCRC = 0xffffffffU
#pragma config FUSES_BOOTCFG2_BROM_BOOTCFGCRC2_BROM_BOOTCFGCRC = 0xffffffffU
#pragma config FUSES_BOOTCFG2_BROM_BOOTCFGCRC3_BROM_BOOTCFGCRC = 0xffffffffU
#pragma config FUSES_BOOTCFG2_BROM_PAGEEND_BROM_PAGEEND = 0xffffffffU




// *****************************************************************************
// *****************************************************************************
// Section: Driver Initialization Data
// *****************************************************************************
// *****************************************************************************
/* Following MISRA-C rules are deviated in the below code block */
/* MISRA C-2012 Rule 7.2 */
/* MISRA C-2012 Rule 11.1 */
/* MISRA C-2012 Rule 11.3 */
/* MISRA C-2012 Rule 11.8 */
// <editor-fold defaultstate="collapsed" desc="DRV_SST26 Initialization Data">

static const DRV_SST26_PLIB_INTERFACE drvSST26PlibAPI = {
    .DMATransfer       = SQI_DMATransfer,
    .RegisterCallback  = SQI_RegisterCallback,
};

static const DRV_SST26_INIT drvSST26InitData =
{
    .sst26Plib      = &drvSST26PlibAPI,
};
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="DRV_MEMORY Instance 0 Initialization Data">

static uint8_t gDrvMemory0EraseBuffer[DRV_SST26_ERASE_BUFFER_SIZE] CACHE_ALIGN;

static DRV_MEMORY_CLIENT_OBJECT gDrvMemory0ClientObject[DRV_MEMORY_CLIENTS_NUMBER_IDX0];

static DRV_MEMORY_BUFFER_OBJECT gDrvMemory0BufferObject[DRV_MEMORY_BUF_Q_SIZE_IDX0];

static const DRV_MEMORY_DEVICE_INTERFACE drvMemory0DeviceAPI = {
    .Open               = DRV_SST26_Open,
    .Close              = DRV_SST26_Close,
    .Status             = DRV_SST26_Status,
    .SectorErase        = DRV_SST26_SectorErase,
    .Read               = DRV_SST26_Read,
    .PageWrite          = DRV_SST26_PageWrite,
    .EventHandlerSet    = NULL,
    .GeometryGet        = (DRV_MEMORY_DEVICE_GEOMETRY_GET)DRV_SST26_GeometryGet,
    .TransferStatusGet  = (DRV_MEMORY_DEVICE_TRANSFER_STATUS_GET)DRV_SST26_TransferStatusGet
};
static const DRV_MEMORY_INIT drvMemory0InitData =
{
    .memDevIndex                = DRV_SST26_INDEX,
    .memoryDevice               = &drvMemory0DeviceAPI,
    .isMemDevInterruptEnabled   = false,
    .isFsEnabled                = true,
    .deviceMediaType            = (uint8_t)SYS_FS_MEDIA_TYPE_SPIFLASH,
    .ewBuffer                   = &gDrvMemory0EraseBuffer[0],
    .clientObjPool              = (uintptr_t)&gDrvMemory0ClientObject[0],
    .bufferObj                  = (uintptr_t)&gDrvMemory0BufferObject[0],
    .queueSize                  = DRV_MEMORY_BUF_Q_SIZE_IDX0,
    .nClientsMax                = DRV_MEMORY_CLIENTS_NUMBER_IDX0
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
// <editor-fold defaultstate="collapsed" desc="File System Initialization Data">

 const SYS_FS_MEDIA_MOUNT_DATA sysfsMountTable[SYS_FS_VOLUME_NUMBER] =
{
    {
        .mountName = SYS_FS_MEDIA_IDX0_MOUNT_NAME_VOLUME_IDX0,
        .devName   = SYS_FS_MEDIA_IDX0_DEVICE_NAME_VOLUME_IDX0,
        .mediaType = SYS_FS_MEDIA_TYPE_IDX0,
        .fsType   = SYS_FS_TYPE_IDX0
    },
};


static const SYS_FS_FUNCTIONS FatFsFunctions =
{
    .mount             = FATFS_mount,
    .unmount           = FATFS_unmount,
    .open              = FATFS_open,
    .read_t              = FATFS_read,
    .close             = FATFS_close,
    .seek              = FATFS_lseek,
    .fstat             = FATFS_stat,
    .getlabel          = FATFS_getlabel,
    .currWD            = FATFS_getcwd,
    .getstrn           = FATFS_gets,
    .openDir           = FATFS_opendir,
    .readDir           = FATFS_readdir,
    .closeDir          = FATFS_closedir,
    .chdir             = FATFS_chdir,
    .chdrive           = FATFS_chdrive,
    .write_t             = NULL,
    .tell              = NULL,
    .eof               = NULL,
    .size              = NULL,
    .mkdir             = NULL,
    .remove_t            = NULL,
    .setlabel          = NULL,
    .truncate          = NULL,
    .chmode            = NULL,
    .chtime            = NULL,
    .rename_t            = NULL,
    .sync              = NULL,
    .putchr            = NULL,
    .putstrn           = NULL,
    .formattedprint    = NULL,
    .testerror         = NULL,
    .formatDisk        = NULL,
    .partitionDisk     = NULL,
    .getCluster        = NULL
};




static const SYS_FS_REGISTRATION_TABLE sysFSInit [ SYS_FS_MAX_FILE_SYSTEM_TYPE ] =
{
    {
        .nativeFileSystemType = FAT,
        .nativeFileSystemFunctions = &FatFsFunctions
    }
};
// </editor-fold>



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
        FCW_Initialize();


    PORT_Initialize();

    if (bootloader_Trigger() == false)
    {
        run_Application(APP_START_ADDRESS);
    }


    CLOCK_Initialize();

    FCW_Initialize();

    EVSYS_Initialize();

    PM_Initialize();

	BSP_Initialize();
    SQI_Initialize();


    /* MISRAC 2012 deviation block start */
    /* Following MISRA-C rules deviated in this block  */
    /* MISRA C-2012 Rule 11.3 - Deviation record ID - H3_MISRAC_2012_R_11_3_DR_1 */
    /* MISRA C-2012 Rule 11.8 - Deviation record ID - H3_MISRAC_2012_R_11_8_DR_1 */
    sysObj.drvSST26 = DRV_SST26_Initialize((SYS_MODULE_INDEX)DRV_SST26_INDEX, (SYS_MODULE_INIT *)&drvSST26InitData);


    sysObj.drvMemory0 = DRV_MEMORY_Initialize((SYS_MODULE_INDEX)DRV_MEMORY_INDEX_0, (SYS_MODULE_INIT *)&drvMemory0InitData);



    /*** File System Service Initialization Code ***/
    (void) SYS_FS_Initialize( (const void *) sysFSInit );


    /* MISRAC 2012 deviation block end */
    APP_Initialize();


    NVIC_Initialize();

    /* MISRAC 2012 deviation block end */
}
