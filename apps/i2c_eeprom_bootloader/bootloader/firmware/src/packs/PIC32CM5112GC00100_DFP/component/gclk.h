/*
 * Component description for GCLK
 *
 * Copyright (c) 2025 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/*  file generated from device description file (ATDF) version 2024-11-05T16:47:43Z  */
#ifndef _PIC32CMGC00_GCLK_COMPONENT_H_
#define _PIC32CMGC00_GCLK_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR GCLK                      */
/* ************************************************************************** */

/* -------- GCLK_CTRLA : (GCLK Offset: 0x00) (R/W 8) Control -------- */
#define GCLK_CTRLA_RESETVALUE                 _UINT8_(0x00)                                        /*  (GCLK_CTRLA) Control  Reset Value */

#define GCLK_CTRLA_SWRST_Pos                  _UINT8_(0)                                           /* (GCLK_CTRLA) Software Reset Position */
#define GCLK_CTRLA_SWRST_Msk                  (_UINT8_(0x1) << GCLK_CTRLA_SWRST_Pos)               /* (GCLK_CTRLA) Software Reset Mask */
#define GCLK_CTRLA_SWRST(value)               (GCLK_CTRLA_SWRST_Msk & (_UINT8_(value) << GCLK_CTRLA_SWRST_Pos)) /* Assignment of value for SWRST in the GCLK_CTRLA register */
#define GCLK_CTRLA_Msk                        _UINT8_(0x01)                                        /* (GCLK_CTRLA) Register Mask  */


/* -------- GCLK_SYNCBUSY : (GCLK Offset: 0x04) ( R/ 32) Synchronization Busy -------- */
#define GCLK_SYNCBUSY_RESETVALUE              _UINT32_(0x00)                                       /*  (GCLK_SYNCBUSY) Synchronization Busy  Reset Value */

#define GCLK_SYNCBUSY_SWRST_Pos               _UINT32_(0)                                          /* (GCLK_SYNCBUSY) Software Reset Synchronization Busy bit Position */
#define GCLK_SYNCBUSY_SWRST_Msk               (_UINT32_(0x1) << GCLK_SYNCBUSY_SWRST_Pos)           /* (GCLK_SYNCBUSY) Software Reset Synchronization Busy bit Mask */
#define GCLK_SYNCBUSY_SWRST(value)            (GCLK_SYNCBUSY_SWRST_Msk & (_UINT32_(value) << GCLK_SYNCBUSY_SWRST_Pos)) /* Assignment of value for SWRST in the GCLK_SYNCBUSY register */
#define GCLK_SYNCBUSY_GENCTRL0_Pos            _UINT32_(2)                                          /* (GCLK_SYNCBUSY) Generic Clock Generator Control 0 Synchronization Busy bit Position */
#define GCLK_SYNCBUSY_GENCTRL0_Msk            (_UINT32_(0x1) << GCLK_SYNCBUSY_GENCTRL0_Pos)        /* (GCLK_SYNCBUSY) Generic Clock Generator Control 0 Synchronization Busy bit Mask */
#define GCLK_SYNCBUSY_GENCTRL0(value)         (GCLK_SYNCBUSY_GENCTRL0_Msk & (_UINT32_(value) << GCLK_SYNCBUSY_GENCTRL0_Pos)) /* Assignment of value for GENCTRL0 in the GCLK_SYNCBUSY register */
#define GCLK_SYNCBUSY_GENCTRL1_Pos            _UINT32_(3)                                          /* (GCLK_SYNCBUSY) Generic Clock Generator Control 1 Synchronization Busy bit Position */
#define GCLK_SYNCBUSY_GENCTRL1_Msk            (_UINT32_(0x1) << GCLK_SYNCBUSY_GENCTRL1_Pos)        /* (GCLK_SYNCBUSY) Generic Clock Generator Control 1 Synchronization Busy bit Mask */
#define GCLK_SYNCBUSY_GENCTRL1(value)         (GCLK_SYNCBUSY_GENCTRL1_Msk & (_UINT32_(value) << GCLK_SYNCBUSY_GENCTRL1_Pos)) /* Assignment of value for GENCTRL1 in the GCLK_SYNCBUSY register */
#define GCLK_SYNCBUSY_GENCTRL2_Pos            _UINT32_(4)                                          /* (GCLK_SYNCBUSY) Generic Clock Generator Control 2 Synchronization Busy bit Position */
#define GCLK_SYNCBUSY_GENCTRL2_Msk            (_UINT32_(0x1) << GCLK_SYNCBUSY_GENCTRL2_Pos)        /* (GCLK_SYNCBUSY) Generic Clock Generator Control 2 Synchronization Busy bit Mask */
#define GCLK_SYNCBUSY_GENCTRL2(value)         (GCLK_SYNCBUSY_GENCTRL2_Msk & (_UINT32_(value) << GCLK_SYNCBUSY_GENCTRL2_Pos)) /* Assignment of value for GENCTRL2 in the GCLK_SYNCBUSY register */
#define GCLK_SYNCBUSY_GENCTRL3_Pos            _UINT32_(5)                                          /* (GCLK_SYNCBUSY) Generic Clock Generator Control 3 Synchronization Busy bit Position */
#define GCLK_SYNCBUSY_GENCTRL3_Msk            (_UINT32_(0x1) << GCLK_SYNCBUSY_GENCTRL3_Pos)        /* (GCLK_SYNCBUSY) Generic Clock Generator Control 3 Synchronization Busy bit Mask */
#define GCLK_SYNCBUSY_GENCTRL3(value)         (GCLK_SYNCBUSY_GENCTRL3_Msk & (_UINT32_(value) << GCLK_SYNCBUSY_GENCTRL3_Pos)) /* Assignment of value for GENCTRL3 in the GCLK_SYNCBUSY register */
#define GCLK_SYNCBUSY_GENCTRL4_Pos            _UINT32_(6)                                          /* (GCLK_SYNCBUSY) Generic Clock Generator Control 4 Synchronization Busy bit Position */
#define GCLK_SYNCBUSY_GENCTRL4_Msk            (_UINT32_(0x1) << GCLK_SYNCBUSY_GENCTRL4_Pos)        /* (GCLK_SYNCBUSY) Generic Clock Generator Control 4 Synchronization Busy bit Mask */
#define GCLK_SYNCBUSY_GENCTRL4(value)         (GCLK_SYNCBUSY_GENCTRL4_Msk & (_UINT32_(value) << GCLK_SYNCBUSY_GENCTRL4_Pos)) /* Assignment of value for GENCTRL4 in the GCLK_SYNCBUSY register */
#define GCLK_SYNCBUSY_GENCTRL5_Pos            _UINT32_(7)                                          /* (GCLK_SYNCBUSY) Generic Clock Generator Control 5 Synchronization Busy bit Position */
#define GCLK_SYNCBUSY_GENCTRL5_Msk            (_UINT32_(0x1) << GCLK_SYNCBUSY_GENCTRL5_Pos)        /* (GCLK_SYNCBUSY) Generic Clock Generator Control 5 Synchronization Busy bit Mask */
#define GCLK_SYNCBUSY_GENCTRL5(value)         (GCLK_SYNCBUSY_GENCTRL5_Msk & (_UINT32_(value) << GCLK_SYNCBUSY_GENCTRL5_Pos)) /* Assignment of value for GENCTRL5 in the GCLK_SYNCBUSY register */
#define GCLK_SYNCBUSY_GENCTRL6_Pos            _UINT32_(8)                                          /* (GCLK_SYNCBUSY) Generic Clock Generator Control 6 Synchronization Busy bit Position */
#define GCLK_SYNCBUSY_GENCTRL6_Msk            (_UINT32_(0x1) << GCLK_SYNCBUSY_GENCTRL6_Pos)        /* (GCLK_SYNCBUSY) Generic Clock Generator Control 6 Synchronization Busy bit Mask */
#define GCLK_SYNCBUSY_GENCTRL6(value)         (GCLK_SYNCBUSY_GENCTRL6_Msk & (_UINT32_(value) << GCLK_SYNCBUSY_GENCTRL6_Pos)) /* Assignment of value for GENCTRL6 in the GCLK_SYNCBUSY register */
#define GCLK_SYNCBUSY_GENCTRL7_Pos            _UINT32_(9)                                          /* (GCLK_SYNCBUSY) Generic Clock Generator Control 7 Synchronization Busy bit Position */
#define GCLK_SYNCBUSY_GENCTRL7_Msk            (_UINT32_(0x1) << GCLK_SYNCBUSY_GENCTRL7_Pos)        /* (GCLK_SYNCBUSY) Generic Clock Generator Control 7 Synchronization Busy bit Mask */
#define GCLK_SYNCBUSY_GENCTRL7(value)         (GCLK_SYNCBUSY_GENCTRL7_Msk & (_UINT32_(value) << GCLK_SYNCBUSY_GENCTRL7_Pos)) /* Assignment of value for GENCTRL7 in the GCLK_SYNCBUSY register */
#define GCLK_SYNCBUSY_GENCTRL8_Pos            _UINT32_(10)                                         /* (GCLK_SYNCBUSY) Generic Clock Generator Control 8 Synchronization Busy bit Position */
#define GCLK_SYNCBUSY_GENCTRL8_Msk            (_UINT32_(0x1) << GCLK_SYNCBUSY_GENCTRL8_Pos)        /* (GCLK_SYNCBUSY) Generic Clock Generator Control 8 Synchronization Busy bit Mask */
#define GCLK_SYNCBUSY_GENCTRL8(value)         (GCLK_SYNCBUSY_GENCTRL8_Msk & (_UINT32_(value) << GCLK_SYNCBUSY_GENCTRL8_Pos)) /* Assignment of value for GENCTRL8 in the GCLK_SYNCBUSY register */
#define GCLK_SYNCBUSY_GENCTRL9_Pos            _UINT32_(11)                                         /* (GCLK_SYNCBUSY) Generic Clock Generator Control 9 Synchronization Busy bit Position */
#define GCLK_SYNCBUSY_GENCTRL9_Msk            (_UINT32_(0x1) << GCLK_SYNCBUSY_GENCTRL9_Pos)        /* (GCLK_SYNCBUSY) Generic Clock Generator Control 9 Synchronization Busy bit Mask */
#define GCLK_SYNCBUSY_GENCTRL9(value)         (GCLK_SYNCBUSY_GENCTRL9_Msk & (_UINT32_(value) << GCLK_SYNCBUSY_GENCTRL9_Pos)) /* Assignment of value for GENCTRL9 in the GCLK_SYNCBUSY register */
#define GCLK_SYNCBUSY_GENCTRL10_Pos           _UINT32_(12)                                         /* (GCLK_SYNCBUSY) Generic Clock Generator Control 10 Synchronization Busy bit Position */
#define GCLK_SYNCBUSY_GENCTRL10_Msk           (_UINT32_(0x1) << GCLK_SYNCBUSY_GENCTRL10_Pos)       /* (GCLK_SYNCBUSY) Generic Clock Generator Control 10 Synchronization Busy bit Mask */
#define GCLK_SYNCBUSY_GENCTRL10(value)        (GCLK_SYNCBUSY_GENCTRL10_Msk & (_UINT32_(value) << GCLK_SYNCBUSY_GENCTRL10_Pos)) /* Assignment of value for GENCTRL10 in the GCLK_SYNCBUSY register */
#define GCLK_SYNCBUSY_GENCTRL11_Pos           _UINT32_(13)                                         /* (GCLK_SYNCBUSY) Generic Clock Generator Control 11 Synchronization Busy bit Position */
#define GCLK_SYNCBUSY_GENCTRL11_Msk           (_UINT32_(0x1) << GCLK_SYNCBUSY_GENCTRL11_Pos)       /* (GCLK_SYNCBUSY) Generic Clock Generator Control 11 Synchronization Busy bit Mask */
#define GCLK_SYNCBUSY_GENCTRL11(value)        (GCLK_SYNCBUSY_GENCTRL11_Msk & (_UINT32_(value) << GCLK_SYNCBUSY_GENCTRL11_Pos)) /* Assignment of value for GENCTRL11 in the GCLK_SYNCBUSY register */
#define GCLK_SYNCBUSY_Msk                     _UINT32_(0x00003FFD)                                 /* (GCLK_SYNCBUSY) Register Mask  */

#define GCLK_SYNCBUSY_GENCTRL_Pos             _UINT32_(2)                                          /* (GCLK_SYNCBUSY Position) Generic Clock Generator Control xx Synchronization Busy bit */
#define GCLK_SYNCBUSY_GENCTRL_Msk             (_UINT32_(0xFFF) << GCLK_SYNCBUSY_GENCTRL_Pos)       /* (GCLK_SYNCBUSY Mask) GENCTRL */
#define GCLK_SYNCBUSY_GENCTRL(value)          (GCLK_SYNCBUSY_GENCTRL_Msk & (_UINT32_(value) << GCLK_SYNCBUSY_GENCTRL_Pos)) 

/* -------- GCLK_GENCTRL : (GCLK Offset: 0x20) (R/W 32) Generic Clock Generator Control -------- */
#define GCLK_GENCTRL_RESETVALUE               _UINT32_(0x00)                                       /*  (GCLK_GENCTRL) Generic Clock Generator Control  Reset Value */

#define GCLK_GENCTRL_SRC_Pos                  _UINT32_(0)                                          /* (GCLK_GENCTRL) Source Select Position */
#define GCLK_GENCTRL_SRC_Msk                  (_UINT32_(0xF) << GCLK_GENCTRL_SRC_Pos)              /* (GCLK_GENCTRL) Source Select Mask */
#define GCLK_GENCTRL_SRC(value)               (GCLK_GENCTRL_SRC_Msk & (_UINT32_(value) << GCLK_GENCTRL_SRC_Pos)) /* Assignment of value for SRC in the GCLK_GENCTRL register */
#define   GCLK_GENCTRL_SRC_XOSC_Val           _UINT32_(0x0)                                        /* (GCLK_GENCTRL) XOSC oscillator output  */
#define   GCLK_GENCTRL_SRC_GCLK_IN_Val        _UINT32_(0x1)                                        /* (GCLK_GENCTRL) Generator input pad (GCLK_IO)  */
#define   GCLK_GENCTRL_SRC_GCLK_GEN1_Val      _UINT32_(0x2)                                        /* (GCLK_GENCTRL) Generic clock generator 1 output  */
#define   GCLK_GENCTRL_SRC_OSCULP32K_Val      _UINT32_(0x3)                                        /* (GCLK_GENCTRL) OSCULP32K oscillator output  */
#define   GCLK_GENCTRL_SRC_XOSC32K_Val        _UINT32_(0x4)                                        /* (GCLK_GENCTRL) XOSC32K oscillator output  */
#define   GCLK_GENCTRL_SRC_DFLL48M_Val        _UINT32_(0x5)                                        /* (GCLK_GENCTRL) DFLL oscillator output  */
#define   GCLK_GENCTRL_SRC_PLL0_CLKOUT1_Val   _UINT32_(0x6)                                        /* (GCLK_GENCTRL) PLL 0 port CLKOUT1  */
#define   GCLK_GENCTRL_SRC_PLL0_CLKOUT2_Val   _UINT32_(0x7)                                        /* (GCLK_GENCTRL) PLL 0 port CLKOUT2  */
#define   GCLK_GENCTRL_SRC_PLL0_CLKOUT3_Val   _UINT32_(0x8)                                        /* (GCLK_GENCTRL) PLL 0 port CLKOUT3  */
#define   GCLK_GENCTRL_SRC_PLL0_CLKOUT4_Val   _UINT32_(0x9)                                        /* (GCLK_GENCTRL) PLL 0 port CLKOUT4  */
#define   GCLK_GENCTRL_SRC_PLL0_CLKOUT5_Val   _UINT32_(0xA)                                        /* (GCLK_GENCTRL) PLL 0 port CLKOUT5  */
#define GCLK_GENCTRL_SRC_XOSC                 (GCLK_GENCTRL_SRC_XOSC_Val << GCLK_GENCTRL_SRC_Pos)  /* (GCLK_GENCTRL) XOSC oscillator output Position */
#define GCLK_GENCTRL_SRC_GCLK_IN              (GCLK_GENCTRL_SRC_GCLK_IN_Val << GCLK_GENCTRL_SRC_Pos) /* (GCLK_GENCTRL) Generator input pad (GCLK_IO) Position */
#define GCLK_GENCTRL_SRC_GCLK_GEN1            (GCLK_GENCTRL_SRC_GCLK_GEN1_Val << GCLK_GENCTRL_SRC_Pos) /* (GCLK_GENCTRL) Generic clock generator 1 output Position */
#define GCLK_GENCTRL_SRC_OSCULP32K            (GCLK_GENCTRL_SRC_OSCULP32K_Val << GCLK_GENCTRL_SRC_Pos) /* (GCLK_GENCTRL) OSCULP32K oscillator output Position */
#define GCLK_GENCTRL_SRC_XOSC32K              (GCLK_GENCTRL_SRC_XOSC32K_Val << GCLK_GENCTRL_SRC_Pos) /* (GCLK_GENCTRL) XOSC32K oscillator output Position */
#define GCLK_GENCTRL_SRC_DFLL48M              (GCLK_GENCTRL_SRC_DFLL48M_Val << GCLK_GENCTRL_SRC_Pos) /* (GCLK_GENCTRL) DFLL oscillator output Position */
#define GCLK_GENCTRL_SRC_PLL0_CLKOUT1         (GCLK_GENCTRL_SRC_PLL0_CLKOUT1_Val << GCLK_GENCTRL_SRC_Pos) /* (GCLK_GENCTRL) PLL 0 port CLKOUT1 Position */
#define GCLK_GENCTRL_SRC_PLL0_CLKOUT2         (GCLK_GENCTRL_SRC_PLL0_CLKOUT2_Val << GCLK_GENCTRL_SRC_Pos) /* (GCLK_GENCTRL) PLL 0 port CLKOUT2 Position */
#define GCLK_GENCTRL_SRC_PLL0_CLKOUT3         (GCLK_GENCTRL_SRC_PLL0_CLKOUT3_Val << GCLK_GENCTRL_SRC_Pos) /* (GCLK_GENCTRL) PLL 0 port CLKOUT3 Position */
#define GCLK_GENCTRL_SRC_PLL0_CLKOUT4         (GCLK_GENCTRL_SRC_PLL0_CLKOUT4_Val << GCLK_GENCTRL_SRC_Pos) /* (GCLK_GENCTRL) PLL 0 port CLKOUT4 Position */
#define GCLK_GENCTRL_SRC_PLL0_CLKOUT5         (GCLK_GENCTRL_SRC_PLL0_CLKOUT5_Val << GCLK_GENCTRL_SRC_Pos) /* (GCLK_GENCTRL) PLL 0 port CLKOUT5 Position */
#define GCLK_GENCTRL_GENEN_Pos                _UINT32_(8)                                          /* (GCLK_GENCTRL) Generic Clock Generator Enable Position */
#define GCLK_GENCTRL_GENEN_Msk                (_UINT32_(0x1) << GCLK_GENCTRL_GENEN_Pos)            /* (GCLK_GENCTRL) Generic Clock Generator Enable Mask */
#define GCLK_GENCTRL_GENEN(value)             (GCLK_GENCTRL_GENEN_Msk & (_UINT32_(value) << GCLK_GENCTRL_GENEN_Pos)) /* Assignment of value for GENEN in the GCLK_GENCTRL register */
#define GCLK_GENCTRL_IDC_Pos                  _UINT32_(9)                                          /* (GCLK_GENCTRL) Improve Duty Cycle Position */
#define GCLK_GENCTRL_IDC_Msk                  (_UINT32_(0x1) << GCLK_GENCTRL_IDC_Pos)              /* (GCLK_GENCTRL) Improve Duty Cycle Mask */
#define GCLK_GENCTRL_IDC(value)               (GCLK_GENCTRL_IDC_Msk & (_UINT32_(value) << GCLK_GENCTRL_IDC_Pos)) /* Assignment of value for IDC in the GCLK_GENCTRL register */
#define GCLK_GENCTRL_OOV_Pos                  _UINT32_(10)                                         /* (GCLK_GENCTRL) Output Off Value Position */
#define GCLK_GENCTRL_OOV_Msk                  (_UINT32_(0x1) << GCLK_GENCTRL_OOV_Pos)              /* (GCLK_GENCTRL) Output Off Value Mask */
#define GCLK_GENCTRL_OOV(value)               (GCLK_GENCTRL_OOV_Msk & (_UINT32_(value) << GCLK_GENCTRL_OOV_Pos)) /* Assignment of value for OOV in the GCLK_GENCTRL register */
#define GCLK_GENCTRL_OE_Pos                   _UINT32_(11)                                         /* (GCLK_GENCTRL) Output Enable Position */
#define GCLK_GENCTRL_OE_Msk                   (_UINT32_(0x1) << GCLK_GENCTRL_OE_Pos)               /* (GCLK_GENCTRL) Output Enable Mask */
#define GCLK_GENCTRL_OE(value)                (GCLK_GENCTRL_OE_Msk & (_UINT32_(value) << GCLK_GENCTRL_OE_Pos)) /* Assignment of value for OE in the GCLK_GENCTRL register */
#define GCLK_GENCTRL_DIVSEL_Pos               _UINT32_(12)                                         /* (GCLK_GENCTRL) Divide Selection Position */
#define GCLK_GENCTRL_DIVSEL_Msk               (_UINT32_(0x1) << GCLK_GENCTRL_DIVSEL_Pos)           /* (GCLK_GENCTRL) Divide Selection Mask */
#define GCLK_GENCTRL_DIVSEL(value)            (GCLK_GENCTRL_DIVSEL_Msk & (_UINT32_(value) << GCLK_GENCTRL_DIVSEL_Pos)) /* Assignment of value for DIVSEL in the GCLK_GENCTRL register */
#define   GCLK_GENCTRL_DIVSEL_DIV1_Val        _UINT32_(0x0)                                        /* (GCLK_GENCTRL) Divide input directly by divider factor  */
#define   GCLK_GENCTRL_DIVSEL_DIV2_Val        _UINT32_(0x1)                                        /* (GCLK_GENCTRL) Divide input by 2^(divider factor+ 1)  */
#define GCLK_GENCTRL_DIVSEL_DIV1              (GCLK_GENCTRL_DIVSEL_DIV1_Val << GCLK_GENCTRL_DIVSEL_Pos) /* (GCLK_GENCTRL) Divide input directly by divider factor Position */
#define GCLK_GENCTRL_DIVSEL_DIV2              (GCLK_GENCTRL_DIVSEL_DIV2_Val << GCLK_GENCTRL_DIVSEL_Pos) /* (GCLK_GENCTRL) Divide input by 2^(divider factor+ 1) Position */
#define GCLK_GENCTRL_RUNSTDBY_Pos             _UINT32_(13)                                         /* (GCLK_GENCTRL) Run in Standby Position */
#define GCLK_GENCTRL_RUNSTDBY_Msk             (_UINT32_(0x1) << GCLK_GENCTRL_RUNSTDBY_Pos)         /* (GCLK_GENCTRL) Run in Standby Mask */
#define GCLK_GENCTRL_RUNSTDBY(value)          (GCLK_GENCTRL_RUNSTDBY_Msk & (_UINT32_(value) << GCLK_GENCTRL_RUNSTDBY_Pos)) /* Assignment of value for RUNSTDBY in the GCLK_GENCTRL register */
#define GCLK_GENCTRL_DIV_Pos                  _UINT32_(16)                                         /* (GCLK_GENCTRL) Division Factor Position */
#define GCLK_GENCTRL_DIV_Msk                  (_UINT32_(0xFFFF) << GCLK_GENCTRL_DIV_Pos)           /* (GCLK_GENCTRL) Division Factor Mask */
#define GCLK_GENCTRL_DIV(value)               (GCLK_GENCTRL_DIV_Msk & (_UINT32_(value) << GCLK_GENCTRL_DIV_Pos)) /* Assignment of value for DIV in the GCLK_GENCTRL register */
#define GCLK_GENCTRL_Msk                      _UINT32_(0xFFFF3F0F)                                 /* (GCLK_GENCTRL) Register Mask  */


/* -------- GCLK_PCHCTRL : (GCLK Offset: 0x80) (R/W 32) Peripheral Clock Control -------- */
#define GCLK_PCHCTRL_RESETVALUE               _UINT32_(0x00)                                       /*  (GCLK_PCHCTRL) Peripheral Clock Control  Reset Value */

#define GCLK_PCHCTRL_GEN_Pos                  _UINT32_(0)                                          /* (GCLK_PCHCTRL) Generic Clock Generator Position */
#define GCLK_PCHCTRL_GEN_Msk                  (_UINT32_(0xF) << GCLK_PCHCTRL_GEN_Pos)              /* (GCLK_PCHCTRL) Generic Clock Generator Mask */
#define GCLK_PCHCTRL_GEN(value)               (GCLK_PCHCTRL_GEN_Msk & (_UINT32_(value) << GCLK_PCHCTRL_GEN_Pos)) /* Assignment of value for GEN in the GCLK_PCHCTRL register */
#define   GCLK_PCHCTRL_GEN_GCLK0_Val          _UINT32_(0x0)                                        /* (GCLK_PCHCTRL) Generic clock generator 0  */
#define   GCLK_PCHCTRL_GEN_GCLK1_Val          _UINT32_(0x1)                                        /* (GCLK_PCHCTRL) Generic clock generator 1  */
#define   GCLK_PCHCTRL_GEN_GCLK2_Val          _UINT32_(0x2)                                        /* (GCLK_PCHCTRL) Generic clock generator 2  */
#define   GCLK_PCHCTRL_GEN_GCLK3_Val          _UINT32_(0x3)                                        /* (GCLK_PCHCTRL) Generic clock generator 3  */
#define   GCLK_PCHCTRL_GEN_GCLK4_Val          _UINT32_(0x4)                                        /* (GCLK_PCHCTRL) Generic clock generator 4  */
#define   GCLK_PCHCTRL_GEN_GCLK5_Val          _UINT32_(0x5)                                        /* (GCLK_PCHCTRL) Generic clock generator 5  */
#define   GCLK_PCHCTRL_GEN_GCLK6_Val          _UINT32_(0x6)                                        /* (GCLK_PCHCTRL) Generic clock generator 6  */
#define   GCLK_PCHCTRL_GEN_GCLK7_Val          _UINT32_(0x7)                                        /* (GCLK_PCHCTRL) Generic clock generator 7  */
#define   GCLK_PCHCTRL_GEN_GCLK8_Val          _UINT32_(0x8)                                        /* (GCLK_PCHCTRL) Generic clock generator 8  */
#define   GCLK_PCHCTRL_GEN_GCLK9_Val          _UINT32_(0x9)                                        /* (GCLK_PCHCTRL) Generic clock generator 9  */
#define   GCLK_PCHCTRL_GEN_GCLK10_Val         _UINT32_(0xA)                                        /* (GCLK_PCHCTRL) Generic clock generator 10  */
#define   GCLK_PCHCTRL_GEN_GCLK11_Val         _UINT32_(0xB)                                        /* (GCLK_PCHCTRL) Generic clock generator 11  */
#define GCLK_PCHCTRL_GEN_GCLK0                (GCLK_PCHCTRL_GEN_GCLK0_Val << GCLK_PCHCTRL_GEN_Pos) /* (GCLK_PCHCTRL) Generic clock generator 0 Position */
#define GCLK_PCHCTRL_GEN_GCLK1                (GCLK_PCHCTRL_GEN_GCLK1_Val << GCLK_PCHCTRL_GEN_Pos) /* (GCLK_PCHCTRL) Generic clock generator 1 Position */
#define GCLK_PCHCTRL_GEN_GCLK2                (GCLK_PCHCTRL_GEN_GCLK2_Val << GCLK_PCHCTRL_GEN_Pos) /* (GCLK_PCHCTRL) Generic clock generator 2 Position */
#define GCLK_PCHCTRL_GEN_GCLK3                (GCLK_PCHCTRL_GEN_GCLK3_Val << GCLK_PCHCTRL_GEN_Pos) /* (GCLK_PCHCTRL) Generic clock generator 3 Position */
#define GCLK_PCHCTRL_GEN_GCLK4                (GCLK_PCHCTRL_GEN_GCLK4_Val << GCLK_PCHCTRL_GEN_Pos) /* (GCLK_PCHCTRL) Generic clock generator 4 Position */
#define GCLK_PCHCTRL_GEN_GCLK5                (GCLK_PCHCTRL_GEN_GCLK5_Val << GCLK_PCHCTRL_GEN_Pos) /* (GCLK_PCHCTRL) Generic clock generator 5 Position */
#define GCLK_PCHCTRL_GEN_GCLK6                (GCLK_PCHCTRL_GEN_GCLK6_Val << GCLK_PCHCTRL_GEN_Pos) /* (GCLK_PCHCTRL) Generic clock generator 6 Position */
#define GCLK_PCHCTRL_GEN_GCLK7                (GCLK_PCHCTRL_GEN_GCLK7_Val << GCLK_PCHCTRL_GEN_Pos) /* (GCLK_PCHCTRL) Generic clock generator 7 Position */
#define GCLK_PCHCTRL_GEN_GCLK8                (GCLK_PCHCTRL_GEN_GCLK8_Val << GCLK_PCHCTRL_GEN_Pos) /* (GCLK_PCHCTRL) Generic clock generator 8 Position */
#define GCLK_PCHCTRL_GEN_GCLK9                (GCLK_PCHCTRL_GEN_GCLK9_Val << GCLK_PCHCTRL_GEN_Pos) /* (GCLK_PCHCTRL) Generic clock generator 9 Position */
#define GCLK_PCHCTRL_GEN_GCLK10               (GCLK_PCHCTRL_GEN_GCLK10_Val << GCLK_PCHCTRL_GEN_Pos) /* (GCLK_PCHCTRL) Generic clock generator 10 Position */
#define GCLK_PCHCTRL_GEN_GCLK11               (GCLK_PCHCTRL_GEN_GCLK11_Val << GCLK_PCHCTRL_GEN_Pos) /* (GCLK_PCHCTRL) Generic clock generator 11 Position */
#define GCLK_PCHCTRL_CHEN_Pos                 _UINT32_(6)                                          /* (GCLK_PCHCTRL) Channel Enable Position */
#define GCLK_PCHCTRL_CHEN_Msk                 (_UINT32_(0x1) << GCLK_PCHCTRL_CHEN_Pos)             /* (GCLK_PCHCTRL) Channel Enable Mask */
#define GCLK_PCHCTRL_CHEN(value)              (GCLK_PCHCTRL_CHEN_Msk & (_UINT32_(value) << GCLK_PCHCTRL_CHEN_Pos)) /* Assignment of value for CHEN in the GCLK_PCHCTRL register */
#define GCLK_PCHCTRL_WRTLOCK_Pos              _UINT32_(7)                                          /* (GCLK_PCHCTRL) Write Lock Position */
#define GCLK_PCHCTRL_WRTLOCK_Msk              (_UINT32_(0x1) << GCLK_PCHCTRL_WRTLOCK_Pos)          /* (GCLK_PCHCTRL) Write Lock Mask */
#define GCLK_PCHCTRL_WRTLOCK(value)           (GCLK_PCHCTRL_WRTLOCK_Msk & (_UINT32_(value) << GCLK_PCHCTRL_WRTLOCK_Pos)) /* Assignment of value for WRTLOCK in the GCLK_PCHCTRL register */
#define GCLK_PCHCTRL_Msk                      _UINT32_(0x000000CF)                                 /* (GCLK_PCHCTRL) Register Mask  */


/* GCLK register offsets definitions */
#define GCLK_CTRLA_REG_OFST            _UINT32_(0x00)      /* (GCLK_CTRLA) Control Offset */
#define GCLK_SYNCBUSY_REG_OFST         _UINT32_(0x04)      /* (GCLK_SYNCBUSY) Synchronization Busy Offset */
#define GCLK_GENCTRL_REG_OFST          _UINT32_(0x20)      /* (GCLK_GENCTRL) Generic Clock Generator Control Offset */
#define GCLK_GENCTRL0_REG_OFST         _UINT32_(0x20)      /* (GCLK_GENCTRL0) Generic Clock Generator Control Offset */
#define GCLK_GENCTRL1_REG_OFST         _UINT32_(0x24)      /* (GCLK_GENCTRL1) Generic Clock Generator Control Offset */
#define GCLK_GENCTRL2_REG_OFST         _UINT32_(0x28)      /* (GCLK_GENCTRL2) Generic Clock Generator Control Offset */
#define GCLK_GENCTRL3_REG_OFST         _UINT32_(0x2C)      /* (GCLK_GENCTRL3) Generic Clock Generator Control Offset */
#define GCLK_GENCTRL4_REG_OFST         _UINT32_(0x30)      /* (GCLK_GENCTRL4) Generic Clock Generator Control Offset */
#define GCLK_GENCTRL5_REG_OFST         _UINT32_(0x34)      /* (GCLK_GENCTRL5) Generic Clock Generator Control Offset */
#define GCLK_GENCTRL6_REG_OFST         _UINT32_(0x38)      /* (GCLK_GENCTRL6) Generic Clock Generator Control Offset */
#define GCLK_GENCTRL7_REG_OFST         _UINT32_(0x3C)      /* (GCLK_GENCTRL7) Generic Clock Generator Control Offset */
#define GCLK_GENCTRL8_REG_OFST         _UINT32_(0x40)      /* (GCLK_GENCTRL8) Generic Clock Generator Control Offset */
#define GCLK_GENCTRL9_REG_OFST         _UINT32_(0x44)      /* (GCLK_GENCTRL9) Generic Clock Generator Control Offset */
#define GCLK_GENCTRL10_REG_OFST        _UINT32_(0x48)      /* (GCLK_GENCTRL10) Generic Clock Generator Control Offset */
#define GCLK_GENCTRL11_REG_OFST        _UINT32_(0x4C)      /* (GCLK_GENCTRL11) Generic Clock Generator Control Offset */
#define GCLK_PCHCTRL_REG_OFST          _UINT32_(0x80)      /* (GCLK_PCHCTRL) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL0_REG_OFST         _UINT32_(0x80)      /* (GCLK_PCHCTRL0) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL1_REG_OFST         _UINT32_(0x84)      /* (GCLK_PCHCTRL1) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL2_REG_OFST         _UINT32_(0x88)      /* (GCLK_PCHCTRL2) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL3_REG_OFST         _UINT32_(0x8C)      /* (GCLK_PCHCTRL3) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL4_REG_OFST         _UINT32_(0x90)      /* (GCLK_PCHCTRL4) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL5_REG_OFST         _UINT32_(0x94)      /* (GCLK_PCHCTRL5) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL6_REG_OFST         _UINT32_(0x98)      /* (GCLK_PCHCTRL6) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL7_REG_OFST         _UINT32_(0x9C)      /* (GCLK_PCHCTRL7) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL8_REG_OFST         _UINT32_(0xA0)      /* (GCLK_PCHCTRL8) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL9_REG_OFST         _UINT32_(0xA4)      /* (GCLK_PCHCTRL9) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL10_REG_OFST        _UINT32_(0xA8)      /* (GCLK_PCHCTRL10) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL11_REG_OFST        _UINT32_(0xAC)      /* (GCLK_PCHCTRL11) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL12_REG_OFST        _UINT32_(0xB0)      /* (GCLK_PCHCTRL12) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL13_REG_OFST        _UINT32_(0xB4)      /* (GCLK_PCHCTRL13) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL14_REG_OFST        _UINT32_(0xB8)      /* (GCLK_PCHCTRL14) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL15_REG_OFST        _UINT32_(0xBC)      /* (GCLK_PCHCTRL15) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL16_REG_OFST        _UINT32_(0xC0)      /* (GCLK_PCHCTRL16) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL17_REG_OFST        _UINT32_(0xC4)      /* (GCLK_PCHCTRL17) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL18_REG_OFST        _UINT32_(0xC8)      /* (GCLK_PCHCTRL18) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL19_REG_OFST        _UINT32_(0xCC)      /* (GCLK_PCHCTRL19) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL20_REG_OFST        _UINT32_(0xD0)      /* (GCLK_PCHCTRL20) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL21_REG_OFST        _UINT32_(0xD4)      /* (GCLK_PCHCTRL21) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL22_REG_OFST        _UINT32_(0xD8)      /* (GCLK_PCHCTRL22) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL23_REG_OFST        _UINT32_(0xDC)      /* (GCLK_PCHCTRL23) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL24_REG_OFST        _UINT32_(0xE0)      /* (GCLK_PCHCTRL24) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL25_REG_OFST        _UINT32_(0xE4)      /* (GCLK_PCHCTRL25) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL26_REG_OFST        _UINT32_(0xE8)      /* (GCLK_PCHCTRL26) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL27_REG_OFST        _UINT32_(0xEC)      /* (GCLK_PCHCTRL27) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL28_REG_OFST        _UINT32_(0xF0)      /* (GCLK_PCHCTRL28) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL29_REG_OFST        _UINT32_(0xF4)      /* (GCLK_PCHCTRL29) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL30_REG_OFST        _UINT32_(0xF8)      /* (GCLK_PCHCTRL30) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL31_REG_OFST        _UINT32_(0xFC)      /* (GCLK_PCHCTRL31) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL32_REG_OFST        _UINT32_(0x100)     /* (GCLK_PCHCTRL32) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL33_REG_OFST        _UINT32_(0x104)     /* (GCLK_PCHCTRL33) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL34_REG_OFST        _UINT32_(0x108)     /* (GCLK_PCHCTRL34) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL35_REG_OFST        _UINT32_(0x10C)     /* (GCLK_PCHCTRL35) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL36_REG_OFST        _UINT32_(0x110)     /* (GCLK_PCHCTRL36) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL37_REG_OFST        _UINT32_(0x114)     /* (GCLK_PCHCTRL37) Peripheral Clock Control Offset */
#define GCLK_PCHCTRL38_REG_OFST        _UINT32_(0x118)     /* (GCLK_PCHCTRL38) Peripheral Clock Control Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* GCLK register API structure */
typedef struct
{  /* Generic Clock Generator */
  __IO  uint8_t                        GCLK_CTRLA;         /* Offset: 0x00 (R/W  8) Control */
  __I   uint8_t                        Reserved1[0x03];
  __I   uint32_t                       GCLK_SYNCBUSY;      /* Offset: 0x04 (R/   32) Synchronization Busy */
  __I   uint8_t                        Reserved2[0x18];
  __IO  uint32_t                       GCLK_GENCTRL[12];   /* Offset: 0x20 (R/W  32) Generic Clock Generator Control */
  __I   uint8_t                        Reserved3[0x30];
  __IO  uint32_t                       GCLK_PCHCTRL[39];   /* Offset: 0x80 (R/W  32) Peripheral Clock Control */
} gclk_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMGC00_GCLK_COMPONENT_H_ */
