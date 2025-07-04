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
#pragma config FUSES_BOOTCFG1_DEVSIGN_SEQ = 0x1U
#pragma config FUSES_BOOTCFG1_DEVSIGN_SEQBAR = 0xfffeU
#pragma config FUSES_BOOTCFG1_BOOT_FLAG_PUFRETRY = CLEAR
#pragma config FUSES_BOOTCFG1_BOOT_FLAG_PUFSTARTUP = CLEAR
#pragma config FUSES_BOOTCFG1_BOOT_FLAG_DICEDIS = SET
#pragma config FUSES_BOOTCFG1_BOOT_FLAG_BOOTMODE = SET
#pragma config FUSES_BOOTCFG1_BOOT_FLAG_RAM_INIT_ENB = SET
#pragma config FUSES_BOOTCFG1_BOOT_FLAG_PUFSCORE = 0x0U
#pragma config FUSES_BOOTCFG1_DICE_CDI_INDEX_DICE_CDI_INDEX = 0x7fU
#pragma config FUSES_BOOTCFG1_DICE_FW_HASH_INDEX_DICE_FW_HASH_INDEX = 0x7fU
#pragma config FUSES_BOOTCFG1_BOOT_GPIOSEL_GPIOPINSEL = 0x1fU
#pragma config FUSES_BOOTCFG1_BOOT_GPIOSEL_GPIOPORTSEL = 0xfU
#pragma config FUSES_BOOTCFG1_BOOT_GPIOSEL_FLTPOL = SET
#pragma config FUSES_BOOTCFG1_BOOT_GPIOSEL_FLTODRAIN = SET
#pragma config FUSES_BOOTCFG1_BOOT_GPIOSEL_FLTSLEWLIM = 0x3U
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC0 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC1 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC2 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC3 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC4 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC5 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC6 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC7 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC8 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC9 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC10 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC11 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC12 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC13 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC14 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC15 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC16 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC17 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC18 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC19 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC20 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC21 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC22 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC23 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC24 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC25 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC26 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC27 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC28 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC29 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC30 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECCLRA_NONSEC31 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC0 = SET
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC1 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC2 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC3 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC4 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC5 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC6 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC7 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC8 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC9 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC10 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC11 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC12 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC13 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC14 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC15 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC16 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC17 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC18 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC19 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC20 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC21 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC22 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC23 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC24 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC25 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC26 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC27 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC28 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC29 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC30 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB0_NONSECSETA_NONSEC31 = CLEAR
#pragma config FUSES_BOOTCFG1_PAC_WRCTRL_H2PB0_PERID = 0x13U
#pragma config FUSES_BOOTCFG1_PAC_WRCTRL_H2PB0_KEY = OFF
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC0 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC1 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC2 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC3 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC4 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC5 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC6 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC7 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC8 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC9 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC10 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC11 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC12 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC13 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC14 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC15 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC16 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC17 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC18 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC19 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC20 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC21 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC22 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC23 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC24 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC25 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC26 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC27 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC28 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC29 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC30 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECCLRA_NONSEC31 = SET
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC0 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC1 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC2 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC3 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC4 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC5 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC6 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC7 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC8 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC9 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC10 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC11 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC12 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC13 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC14 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC15 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC16 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC17 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC18 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC19 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC20 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC21 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC22 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC23 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC24 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC25 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC26 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC27 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC28 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC29 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC30 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB1_NONSECSETA_NONSEC31 = CLEAR
#pragma config FUSES_BOOTCFG1_PAC_WRCTRL_H2PB1_PERID = 0x2eU
#pragma config FUSES_BOOTCFG1_PAC_WRCTRL_H2PB1_KEY = OFF
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC0 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC1 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC2 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC3 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC4 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC5 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC6 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC7 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC8 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC9 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC10 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC11 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC12 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC13 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC14 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC15 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC16 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC17 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC18 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC19 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC20 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC21 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC22 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC23 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC24 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC25 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC26 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC27 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC28 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC29 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC30 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECCLRA_NONSEC31 = SET
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC0 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC1 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC2 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC3 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC4 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC5 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC6 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC7 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC8 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC9 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC10 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC11 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC12 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC13 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC14 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC15 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC16 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC17 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC18 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC19 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC20 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC21 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC22 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC23 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC24 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC25 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC26 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC27 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC28 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC29 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC30 = CLEAR
#pragma config FUSES_BOOTCFG1_H2PB2_NONSECSETA_NONSEC31 = CLEAR
#pragma config FUSES_BOOTCFG1_PAC_WRCTRL_H2PB2_PERID = 0x2fU
#pragma config FUSES_BOOTCFG1_PAC_WRCTRL_H2PB2_KEY = OFF
#pragma config FUSES_BOOTCFG1_IDAU_RCTRL_BFM_ARG = 0x0U
#pragma config FUSES_BOOTCFG1_IDAU_RCTRL_BFM_CMD = WRSZ
#pragma config FUSES_BOOTCFG1_IDAU_RCTRL_PFMANS_ARG = 0x0U
#pragma config FUSES_BOOTCFG1_IDAU_RCTRL_PFMANS_CMD = WRSZ
#pragma config FUSES_BOOTCFG1_IDAU_RCTRL_PFMANSC_ARG = 0x0U
#pragma config FUSES_BOOTCFG1_IDAU_RCTRL_PFMANSC_CMD = WRSZ
#pragma config FUSES_BOOTCFG1_IDAU_RCTRL_DRM_ARG = 0x0U
#pragma config FUSES_BOOTCFG1_IDAU_RCTRL_DRM_CMD = WRSZ
#pragma config FUSES_BOOTCFG1_IDAU_CTRL_EN_CMD = ENABLE
#pragma config FUSES_BOOTCFG1_IDAU_CTRL_WLCK_CMD = WLCK
#pragma config FUSES_BOOTCFG1_FCW_CWP_BC1AWP = DISABLE
#pragma config FUSES_BOOTCFG1_FCW_CWP_BC1WP = DISABLE
#pragma config FUSES_BOOTCFG1_FCW_CWP_RCWP = DISABLE
#pragma config FUSES_BOOTCFG1_FCW_CWP_VSSWP0 = DISABLE
#pragma config FUSES_BOOTCFG1_FCW_CWP_VSSWP1 = DISABLE
#pragma config FUSES_BOOTCFG1_FCW_CWP_BC1AWPLOCK = UNLOCKED
#pragma config FUSES_BOOTCFG1_FCW_CWP_BC1WPLOCK = UNLOCKED
#pragma config FUSES_BOOTCFG1_FCW_CWP_RCWPLOCK = UNLOCKED
#pragma config FUSES_BOOTCFG1_FCW_CWP_VSSWPLOCK0 = UNLOCKED
#pragma config FUSES_BOOTCFG1_FCW_CWP_VSSWPLOCK1 = UNLOCKED
#pragma config FUSES_BOOTCFG1_FCR_CRP_BC1ARP = DISABLE
#pragma config FUSES_BOOTCFG1_FCR_CRP_BC1RP = DISABLE
#pragma config FUSES_BOOTCFG1_FCR_CRP_RCRP = DISABLE
#pragma config FUSES_BOOTCFG1_FCR_CRP_VSSRP0 = DISABLE
#pragma config FUSES_BOOTCFG1_FCR_CRP_VSSRP1 = DISABLE
#pragma config FUSES_BOOTCFG1_FCR_CRP_BC1ARPLOCK = UNLOCKED
#pragma config FUSES_BOOTCFG1_FCR_CRP_BC1RPLOCK = UNLOCKED
#pragma config FUSES_BOOTCFG1_FCR_CRP_RCRPLOCK = UNLOCKED
#pragma config FUSES_BOOTCFG1_FCR_CRP_VSSRPLOCK0 = UNLOCKED
#pragma config FUSES_BOOTCFG1_FCR_CRP_VSSRPLOCK1 = UNLOCKED
#pragma config FUSES_BOOTCFG1_FCR_ECCCTRL_ECCCTL = STRICT
#pragma config FUSES_BOOTCFG1_FCR_ECCCTRL_ECCUNLCK = LOCKED
#pragma config FUSES_BOOTCFG1_FCR_ECCCTRL_SECCNT = 0x0U
#pragma config FUSES_BOOTCFG1_SUPC_BRCFGUSMOR_BOR_HYST_BOR_VDDIO = LOW
#pragma config FUSES_BOOTCFG1_SUPC_BRCFGUSMOR_BOR_BOR_TRIP_VDDIO = 0x0U
#pragma config FUSES_BOOTCFG1_SUPC_BRCFGUSMOR_BOR_HYST_BOR_VDDREG = LOW
#pragma config FUSES_BOOTCFG1_SUPC_BRCFGUDSSMOR_BOR_HYST = LOW
#pragma config FUSES_BOOTCFG1_SUPC_BRCFGUDSSMOR_BOR_TRIP = 0x0U
#pragma config FUSES_BOOTCFG1_SUPC_BRCFGUCP0_CP = 0x0U
#pragma config FUSES_BOOTCFG1_WDT_SETUP_ENABLE = CLEAR
#pragma config FUSES_BOOTCFG1_WDT_SETUP_WEN = CLEAR
#pragma config FUSES_BOOTCFG1_WDT_SETUP_RUNSTDBY = CLEAR
#pragma config FUSES_BOOTCFG1_WDT_SETUP_ALWAYSON = CLEAR
#pragma config FUSES_BOOTCFG1_WDT_SETUP_PER = CYC8
#pragma config FUSES_BOOTCFG1_WDT_SETUP_WINDOW = CYC8
#pragma config FUSES_BOOTCFG1_WDT_SETUP_EWOFFSET = CYC8
#pragma config FUSES_BOOTCFG1A_DEVSIGN_SEQ = 0x2U
#pragma config FUSES_BOOTCFG1A_DEVSIGN_SEQBAR = 0xfffdU
#pragma config FUSES_BOOTCFG1A_BOOT_FLAG_PUFRETRY = CLEAR
#pragma config FUSES_BOOTCFG1A_BOOT_FLAG_PUFSTARTUP = CLEAR
#pragma config FUSES_BOOTCFG1A_BOOT_FLAG_DICEDIS = SET
#pragma config FUSES_BOOTCFG1A_BOOT_FLAG_BOOTMODE = SET
#pragma config FUSES_BOOTCFG1A_BOOT_FLAG_RAM_INIT_ENB = SET
#pragma config FUSES_BOOTCFG1A_BOOT_FLAG_PUFSCORE = 0x0U
#pragma config FUSES_BOOTCFG1A_DICE_CDI_INDEX_DICE_CDI_INDEX = 0x7fU
#pragma config FUSES_BOOTCFG1A_DICE_FW_HASH_INDEX_DICE_FW_HASH_INDEX = 0x7fU
#pragma config FUSES_BOOTCFG1A_BOOT_GPIOSEL_GPIOPINSEL = 0x1fU
#pragma config FUSES_BOOTCFG1A_BOOT_GPIOSEL_GPIOPORTSEL = 0xfU
#pragma config FUSES_BOOTCFG1A_BOOT_GPIOSEL_FLTPOL = SET
#pragma config FUSES_BOOTCFG1A_BOOT_GPIOSEL_FLTODRAIN = SET
#pragma config FUSES_BOOTCFG1A_BOOT_GPIOSEL_FLTSLEWLIM = 0x3U
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC0 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC1 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC2 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC3 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC4 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC5 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC6 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC7 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC8 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC9 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC10 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC11 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC12 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC13 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC14 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC15 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC16 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC17 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC18 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC19 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC20 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC21 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC22 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC23 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC24 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC25 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC26 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC27 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC28 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC29 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC30 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECCLRA_NONSEC31 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC0 = SET
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC1 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC2 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC3 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC4 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC5 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC6 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC7 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC8 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC9 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC10 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC11 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC12 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC13 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC14 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC15 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC16 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC17 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC18 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC19 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC20 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC21 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC22 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC23 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC24 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC25 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC26 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC27 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC28 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC29 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC30 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB0_NONSECSETA_NONSEC31 = CLEAR
#pragma config FUSES_BOOTCFG1A_PAC_WRCTRL_H2PB0_PERID = 0x13U
#pragma config FUSES_BOOTCFG1A_PAC_WRCTRL_H2PB0_KEY = OFF
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC0 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC1 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC2 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC3 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC4 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC5 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC6 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC7 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC8 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC9 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC10 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC11 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC12 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC13 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC14 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC15 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC16 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC17 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC18 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC19 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC20 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC21 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC22 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC23 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC24 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC25 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC26 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC27 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC28 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC29 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC30 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECCLRA_NONSEC31 = SET
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC0 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC1 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC2 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC3 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC4 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC5 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC6 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC7 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC8 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC9 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC10 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC11 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC12 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC13 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC14 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC15 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC16 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC17 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC18 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC19 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC20 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC21 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC22 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC23 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC24 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC25 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC26 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC27 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC28 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC29 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC30 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB1_NONSECSETA_NONSEC31 = CLEAR
#pragma config FUSES_BOOTCFG1A_PAC_WRCTRL_H2PB1_PERID = 0x2eU
#pragma config FUSES_BOOTCFG1A_PAC_WRCTRL_H2PB1_KEY = OFF
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC0 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC1 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC2 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC3 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC4 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC5 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC6 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC7 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC8 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC9 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC10 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC11 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC12 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC13 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC14 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC15 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC16 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC17 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC18 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC19 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC20 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC21 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC22 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC23 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC24 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC25 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC26 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC27 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC28 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC29 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC30 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECCLRA_NONSEC31 = SET
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC0 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC1 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC2 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC3 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC4 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC5 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC6 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC7 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC8 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC9 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC10 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC11 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC12 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC13 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC14 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC15 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC16 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC17 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC18 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC19 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC20 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC21 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC22 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC23 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC24 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC25 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC26 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC27 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC28 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC29 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC30 = CLEAR
#pragma config FUSES_BOOTCFG1A_H2PB2_NONSECSETA_NONSEC31 = CLEAR
#pragma config FUSES_BOOTCFG1A_PAC_WRCTRL_H2PB2_PERID = 0x2fU
#pragma config FUSES_BOOTCFG1A_PAC_WRCTRL_H2PB2_KEY = OFF
#pragma config FUSES_BOOTCFG1A_IDAU_RCTRL_BFM_ARG = 0x0U
#pragma config FUSES_BOOTCFG1A_IDAU_RCTRL_BFM_CMD = WRSZ
#pragma config FUSES_BOOTCFG1A_IDAU_RCTRL_PFMANS_ARG = 0x0U
#pragma config FUSES_BOOTCFG1A_IDAU_RCTRL_PFMANS_CMD = WRSZ
#pragma config FUSES_BOOTCFG1A_IDAU_RCTRL_PFMANSC_ARG = 0x0U
#pragma config FUSES_BOOTCFG1A_IDAU_RCTRL_PFMANSC_CMD = WRSZ
#pragma config FUSES_BOOTCFG1A_IDAU_RCTRL_DRM_ARG = 0x0U
#pragma config FUSES_BOOTCFG1A_IDAU_RCTRL_DRM_CMD = WRSZ
#pragma config FUSES_BOOTCFG1A_IDAU_CTRL_EN_CMD = ENABLE
#pragma config FUSES_BOOTCFG1A_IDAU_CTRL_WLCK_CMD = WLCK
#pragma config FUSES_BOOTCFG1A_FCW_CWP_BC1AWP = DISABLE
#pragma config FUSES_BOOTCFG1A_FCW_CWP_BC1WP = DISABLE
#pragma config FUSES_BOOTCFG1A_FCW_CWP_RCWP = DISABLE
#pragma config FUSES_BOOTCFG1A_FCW_CWP_VSSWP0 = DISABLE
#pragma config FUSES_BOOTCFG1A_FCW_CWP_VSSWP1 = DISABLE
#pragma config FUSES_BOOTCFG1A_FCW_CWP_BC1AWPLOCK = UNLOCKED
#pragma config FUSES_BOOTCFG1A_FCW_CWP_BC1WPLOCK = UNLOCKED
#pragma config FUSES_BOOTCFG1A_FCW_CWP_RCWPLOCK = UNLOCKED
#pragma config FUSES_BOOTCFG1A_FCW_CWP_VSSWPLOCK0 = UNLOCKED
#pragma config FUSES_BOOTCFG1A_FCW_CWP_VSSWPLOCK1 = UNLOCKED
#pragma config FUSES_BOOTCFG1A_FCR_CRP_BC1ARP = DISABLE
#pragma config FUSES_BOOTCFG1A_FCR_CRP_BC1RP = DISABLE
#pragma config FUSES_BOOTCFG1A_FCR_CRP_RCRP = DISABLE
#pragma config FUSES_BOOTCFG1A_FCR_CRP_VSSRP0 = DISABLE
#pragma config FUSES_BOOTCFG1A_FCR_CRP_VSSRP1 = DISABLE
#pragma config FUSES_BOOTCFG1A_FCR_CRP_BC1ARPLOCK = UNLOCKED
#pragma config FUSES_BOOTCFG1A_FCR_CRP_BC1RPLOCK = UNLOCKED
#pragma config FUSES_BOOTCFG1A_FCR_CRP_RCRPLOCK = UNLOCKED
#pragma config FUSES_BOOTCFG1A_FCR_CRP_VSSRPLOCK0 = UNLOCKED
#pragma config FUSES_BOOTCFG1A_FCR_CRP_VSSRPLOCK1 = UNLOCKED
#pragma config FUSES_BOOTCFG1A_FCR_ECCCTRL_ECCCTL = STRICT
#pragma config FUSES_BOOTCFG1A_FCR_ECCCTRL_ECCUNLCK = LOCKED
#pragma config FUSES_BOOTCFG1A_FCR_ECCCTRL_SECCNT = 0x0U
#pragma config FUSES_BOOTCFG1A_SUPC_BRCFGUSMOR_BOR_HYST_BOR_VDDIO = LOW
#pragma config FUSES_BOOTCFG1A_SUPC_BRCFGUSMOR_BOR_BOR_TRIP_VDDIO = 0x0U
#pragma config FUSES_BOOTCFG1A_SUPC_BRCFGUSMOR_BOR_HYST_BOR_VDDREG = LOW
#pragma config FUSES_BOOTCFG1A_SUPC_BRCFGUDSSMOR_BOR_HYST = LOW
#pragma config FUSES_BOOTCFG1A_SUPC_BRCFGUDSSMOR_BOR_TRIP = 0x0U
#pragma config FUSES_BOOTCFG1A_SUPC_BRCFGUCP0_CP = 0x0U
#pragma config FUSES_BOOTCFG1A_WDT_SETUP_ENABLE = CLEAR
#pragma config FUSES_BOOTCFG1A_WDT_SETUP_WEN = CLEAR
#pragma config FUSES_BOOTCFG1A_WDT_SETUP_RUNSTDBY = CLEAR
#pragma config FUSES_BOOTCFG1A_WDT_SETUP_ALWAYSON = CLEAR
#pragma config FUSES_BOOTCFG1A_WDT_SETUP_PER = CYC8
#pragma config FUSES_BOOTCFG1A_WDT_SETUP_WINDOW = CYC8
#pragma config FUSES_BOOTCFG1A_WDT_SETUP_EWOFFSET = CYC8




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
// <editor-fold defaultstate="collapsed" desc="DRV_AT24 Initialization Data">

/* I2C PLIB Interface Initialization for AT24 Driver */
static const DRV_AT24_PLIB_INTERFACE drvAT24PlibAPI = {

    /* I2C PLIB WriteRead function */
    .writeRead = (DRV_AT24_PLIB_WRITE_READ)SERCOM1_I2C_WriteRead,

    /* I2C PLIB Write function */
    .write_t = (DRV_AT24_PLIB_WRITE)SERCOM1_I2C_Write,

    /* I2C PLIB Read function */
    .read_t = (DRV_AT24_PLIB_READ)SERCOM1_I2C_Read,

    /* I2C PLIB Transfer Status function */
    .isBusy = (DRV_AT24_PLIB_IS_BUSY)SERCOM1_I2C_IsBusy,

    /* I2C PLIB Error Status function */
    .errorGet = (DRV_AT24_PLIB_ERROR_GET)SERCOM1_I2C_ErrorGet,

    /* I2C PLIB Callback Register */
    .callbackRegister = (DRV_AT24_PLIB_CALLBACK_REGISTER)SERCOM1_I2C_CallbackRegister,
};

/* AT24 Driver Initialization Data */
static const DRV_AT24_INIT drvAT24InitData =
{
    /* I2C PLIB API  interface*/
    .i2cPlib = &drvAT24PlibAPI,

    /* 7-bit I2C Slave address */
    .slaveAddress = 0x57,

    /* EEPROM Page Size in bytes */
    .pageSize = DRV_AT24_EEPROM_PAGE_SIZE,

    /* Total size of the EEPROM in bytes */
    .flashSize = DRV_AT24_EEPROM_FLASH_SIZE,

    /* AT24 Number of clients */
    .numClients = DRV_AT24_CLIENTS_NUMBER_IDX,

    .blockStartAddress =    0x0,
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

    FCR_Initialize();

FCR_REGS->FCR_CTRLA = ((FCR_REGS->FCR_CTRLA) & (FCR_CTRLA_RDBUFWS_Msk | FCR_CTRLA_FWS_Msk)) | FCR_CTRLA_ADRWS(0U) | FCR_CTRLA_AUTOWS(1U);
  
    PORT_Initialize();

    CLOCK_Initialize();




    FCW_Initialize();

    SERCOM1_I2C_Initialize();

    EVSYS_Initialize();

    PM_Initialize();

	BSP_Initialize();

    /* MISRAC 2012 deviation block start */
    /* Following MISRA-C rules deviated in this block  */
    /* MISRA C-2012 Rule 11.3 - Deviation record ID - H3_MISRAC_2012_R_11_3_DR_1 */
    /* MISRA C-2012 Rule 11.8 - Deviation record ID - H3_MISRAC_2012_R_11_8_DR_1 */

    sysObj.drvAT24 = DRV_AT24_Initialize(DRV_AT24_INDEX, (SYS_MODULE_INIT *)&drvAT24InitData);




    /* MISRAC 2012 deviation block end */
    APP_Initialize();


    NVIC_Initialize();


    /* MISRAC 2012 deviation block end */
}

/*******************************************************************************
 End of File
*/
