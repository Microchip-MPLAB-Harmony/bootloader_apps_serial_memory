/*
 * Component description for SUPC
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

/*  file generated from device description file (ATDF) version 2025-04-15T17:35:01Z  */
#ifndef _PIC32CZCA70_SUPC_COMPONENT_H_
#define _PIC32CZCA70_SUPC_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR SUPC                      */
/* ************************************************************************** */

/* -------- SUPC_CR : (SUPC Offset: 0x00) ( /W 32) Supply Controller Control Register -------- */
#define SUPC_CR_VROFF_Pos                     _UINT32_(2)                                          /* (SUPC_CR) Voltage Regulator Off Position */
#define SUPC_CR_VROFF_Msk                     (_UINT32_(0x1) << SUPC_CR_VROFF_Pos)                 /* (SUPC_CR) Voltage Regulator Off Mask */
#define SUPC_CR_VROFF(value)                  (SUPC_CR_VROFF_Msk & (_UINT32_(value) << SUPC_CR_VROFF_Pos)) /* Assignment of value for VROFF in the SUPC_CR register */
#define   SUPC_CR_VROFF_NO_EFFECT_Val         _UINT32_(0x0)                                        /* (SUPC_CR) No effect.  */
#define   SUPC_CR_VROFF_STOP_VREG_Val         _UINT32_(0x1)                                        /* (SUPC_CR) If KEY is correct, VROFF asserts the vddcore_nreset and stops the voltage regulator.  */
#define SUPC_CR_VROFF_NO_EFFECT               (SUPC_CR_VROFF_NO_EFFECT_Val << SUPC_CR_VROFF_Pos)   /* (SUPC_CR) No effect. Position */
#define SUPC_CR_VROFF_STOP_VREG               (SUPC_CR_VROFF_STOP_VREG_Val << SUPC_CR_VROFF_Pos)   /* (SUPC_CR) If KEY is correct, VROFF asserts the vddcore_nreset and stops the voltage regulator. Position */
#define SUPC_CR_XTALSEL_Pos                   _UINT32_(3)                                          /* (SUPC_CR) Crystal Oscillator Select Position */
#define SUPC_CR_XTALSEL_Msk                   (_UINT32_(0x1) << SUPC_CR_XTALSEL_Pos)               /* (SUPC_CR) Crystal Oscillator Select Mask */
#define SUPC_CR_XTALSEL(value)                (SUPC_CR_XTALSEL_Msk & (_UINT32_(value) << SUPC_CR_XTALSEL_Pos)) /* Assignment of value for XTALSEL in the SUPC_CR register */
#define   SUPC_CR_XTALSEL_NO_EFFECT_Val       _UINT32_(0x0)                                        /* (SUPC_CR) No effect.  */
#define   SUPC_CR_XTALSEL_CRYSTAL_SEL_Val     _UINT32_(0x1)                                        /* (SUPC_CR) If KEY is correct, XTALSEL switches the slow clock on the crystal oscillator output.  */
#define SUPC_CR_XTALSEL_NO_EFFECT             (SUPC_CR_XTALSEL_NO_EFFECT_Val << SUPC_CR_XTALSEL_Pos) /* (SUPC_CR) No effect. Position */
#define SUPC_CR_XTALSEL_CRYSTAL_SEL           (SUPC_CR_XTALSEL_CRYSTAL_SEL_Val << SUPC_CR_XTALSEL_Pos) /* (SUPC_CR) If KEY is correct, XTALSEL switches the slow clock on the crystal oscillator output. Position */
#define SUPC_CR_KEY_Pos                       _UINT32_(24)                                         /* (SUPC_CR) Password Position */
#define SUPC_CR_KEY_Msk                       (_UINT32_(0xFF) << SUPC_CR_KEY_Pos)                  /* (SUPC_CR) Password Mask */
#define SUPC_CR_KEY(value)                    (SUPC_CR_KEY_Msk & (_UINT32_(value) << SUPC_CR_KEY_Pos)) /* Assignment of value for KEY in the SUPC_CR register */
#define   SUPC_CR_KEY_PASSWD_Val              _UINT32_(0xA5)                                       /* (SUPC_CR) Writing any other value in this field aborts the write operation.  */
#define SUPC_CR_KEY_PASSWD                    (SUPC_CR_KEY_PASSWD_Val << SUPC_CR_KEY_Pos)          /* (SUPC_CR) Writing any other value in this field aborts the write operation. Position */
#define SUPC_CR_Msk                           _UINT32_(0xFF00000C)                                 /* (SUPC_CR) Register Mask  */


/* -------- SUPC_SMMR : (SUPC Offset: 0x04) (R/W 32) Supply Controller Supply Monitor Mode Register -------- */
#define SUPC_SMMR_SMTH_Pos                    _UINT32_(0)                                          /* (SUPC_SMMR) Supply Monitor Threshold Position */
#define SUPC_SMMR_SMTH_Msk                    (_UINT32_(0xF) << SUPC_SMMR_SMTH_Pos)                /* (SUPC_SMMR) Supply Monitor Threshold Mask */
#define SUPC_SMMR_SMTH(value)                 (SUPC_SMMR_SMTH_Msk & (_UINT32_(value) << SUPC_SMMR_SMTH_Pos)) /* Assignment of value for SMTH in the SUPC_SMMR register */
#define SUPC_SMMR_SMSMPL_Pos                  _UINT32_(8)                                          /* (SUPC_SMMR) Supply Monitor Sampling Period Position */
#define SUPC_SMMR_SMSMPL_Msk                  (_UINT32_(0x7) << SUPC_SMMR_SMSMPL_Pos)              /* (SUPC_SMMR) Supply Monitor Sampling Period Mask */
#define SUPC_SMMR_SMSMPL(value)               (SUPC_SMMR_SMSMPL_Msk & (_UINT32_(value) << SUPC_SMMR_SMSMPL_Pos)) /* Assignment of value for SMSMPL in the SUPC_SMMR register */
#define   SUPC_SMMR_SMSMPL_SMD_Val            _UINT32_(0x0)                                        /* (SUPC_SMMR) Supply Monitor disabled  */
#define   SUPC_SMMR_SMSMPL_CSM_Val            _UINT32_(0x1)                                        /* (SUPC_SMMR) Continuous Supply Monitor  */
#define   SUPC_SMMR_SMSMPL_32SLCK_Val         _UINT32_(0x2)                                        /* (SUPC_SMMR) Supply Monitor enabled one SLCK period every 32 SLCK periods  */
#define   SUPC_SMMR_SMSMPL_256SLCK_Val        _UINT32_(0x3)                                        /* (SUPC_SMMR) Supply Monitor enabled one SLCK period every 256 SLCK periods  */
#define   SUPC_SMMR_SMSMPL_2048SLCK_Val       _UINT32_(0x4)                                        /* (SUPC_SMMR) Supply Monitor enabled one SLCK period every 2,048 SLCK periods  */
#define SUPC_SMMR_SMSMPL_SMD                  (SUPC_SMMR_SMSMPL_SMD_Val << SUPC_SMMR_SMSMPL_Pos)   /* (SUPC_SMMR) Supply Monitor disabled Position */
#define SUPC_SMMR_SMSMPL_CSM                  (SUPC_SMMR_SMSMPL_CSM_Val << SUPC_SMMR_SMSMPL_Pos)   /* (SUPC_SMMR) Continuous Supply Monitor Position */
#define SUPC_SMMR_SMSMPL_32SLCK               (SUPC_SMMR_SMSMPL_32SLCK_Val << SUPC_SMMR_SMSMPL_Pos) /* (SUPC_SMMR) Supply Monitor enabled one SLCK period every 32 SLCK periods Position */
#define SUPC_SMMR_SMSMPL_256SLCK              (SUPC_SMMR_SMSMPL_256SLCK_Val << SUPC_SMMR_SMSMPL_Pos) /* (SUPC_SMMR) Supply Monitor enabled one SLCK period every 256 SLCK periods Position */
#define SUPC_SMMR_SMSMPL_2048SLCK             (SUPC_SMMR_SMSMPL_2048SLCK_Val << SUPC_SMMR_SMSMPL_Pos) /* (SUPC_SMMR) Supply Monitor enabled one SLCK period every 2,048 SLCK periods Position */
#define SUPC_SMMR_SMRSTEN_Pos                 _UINT32_(12)                                         /* (SUPC_SMMR) Supply Monitor Reset Enable Position */
#define SUPC_SMMR_SMRSTEN_Msk                 (_UINT32_(0x1) << SUPC_SMMR_SMRSTEN_Pos)             /* (SUPC_SMMR) Supply Monitor Reset Enable Mask */
#define SUPC_SMMR_SMRSTEN(value)              (SUPC_SMMR_SMRSTEN_Msk & (_UINT32_(value) << SUPC_SMMR_SMRSTEN_Pos)) /* Assignment of value for SMRSTEN in the SUPC_SMMR register */
#define   SUPC_SMMR_SMRSTEN_NOT_ENABLE_Val    _UINT32_(0x0)                                        /* (SUPC_SMMR) The core reset signal vddcore_nreset is not affected when a supply monitor detection occurs.  */
#define   SUPC_SMMR_SMRSTEN_ENABLE_Val        _UINT32_(0x1)                                        /* (SUPC_SMMR) The core reset signal, vddcore_nreset is asserted when a supply monitor detection occurs.  */
#define SUPC_SMMR_SMRSTEN_NOT_ENABLE          (SUPC_SMMR_SMRSTEN_NOT_ENABLE_Val << SUPC_SMMR_SMRSTEN_Pos) /* (SUPC_SMMR) The core reset signal vddcore_nreset is not affected when a supply monitor detection occurs. Position */
#define SUPC_SMMR_SMRSTEN_ENABLE              (SUPC_SMMR_SMRSTEN_ENABLE_Val << SUPC_SMMR_SMRSTEN_Pos) /* (SUPC_SMMR) The core reset signal, vddcore_nreset is asserted when a supply monitor detection occurs. Position */
#define SUPC_SMMR_SMIEN_Pos                   _UINT32_(13)                                         /* (SUPC_SMMR) Supply Monitor Interrupt Enable Position */
#define SUPC_SMMR_SMIEN_Msk                   (_UINT32_(0x1) << SUPC_SMMR_SMIEN_Pos)               /* (SUPC_SMMR) Supply Monitor Interrupt Enable Mask */
#define SUPC_SMMR_SMIEN(value)                (SUPC_SMMR_SMIEN_Msk & (_UINT32_(value) << SUPC_SMMR_SMIEN_Pos)) /* Assignment of value for SMIEN in the SUPC_SMMR register */
#define   SUPC_SMMR_SMIEN_NOT_ENABLE_Val      _UINT32_(0x0)                                        /* (SUPC_SMMR) The SUPC interrupt signal is not affected when a supply monitor detection occurs.  */
#define   SUPC_SMMR_SMIEN_ENABLE_Val          _UINT32_(0x1)                                        /* (SUPC_SMMR) The SUPC interrupt signal is asserted when a supply monitor detection occurs.  */
#define SUPC_SMMR_SMIEN_NOT_ENABLE            (SUPC_SMMR_SMIEN_NOT_ENABLE_Val << SUPC_SMMR_SMIEN_Pos) /* (SUPC_SMMR) The SUPC interrupt signal is not affected when a supply monitor detection occurs. Position */
#define SUPC_SMMR_SMIEN_ENABLE                (SUPC_SMMR_SMIEN_ENABLE_Val << SUPC_SMMR_SMIEN_Pos)  /* (SUPC_SMMR) The SUPC interrupt signal is asserted when a supply monitor detection occurs. Position */
#define SUPC_SMMR_Msk                         _UINT32_(0x0000370F)                                 /* (SUPC_SMMR) Register Mask  */


/* -------- SUPC_MR : (SUPC Offset: 0x08) (R/W 32) Supply Controller Mode Register -------- */
#define SUPC_MR_BODRSTEN_Pos                  _UINT32_(12)                                         /* (SUPC_MR) Brownout Detector Reset Enable Position */
#define SUPC_MR_BODRSTEN_Msk                  (_UINT32_(0x1) << SUPC_MR_BODRSTEN_Pos)              /* (SUPC_MR) Brownout Detector Reset Enable Mask */
#define SUPC_MR_BODRSTEN(value)               (SUPC_MR_BODRSTEN_Msk & (_UINT32_(value) << SUPC_MR_BODRSTEN_Pos)) /* Assignment of value for BODRSTEN in the SUPC_MR register */
#define   SUPC_MR_BODRSTEN_NOT_ENABLE_Val     _UINT32_(0x0)                                        /* (SUPC_MR) The core reset signal vddcore_nreset is not affected when a brownout detection occurs.  */
#define   SUPC_MR_BODRSTEN_ENABLE_Val         _UINT32_(0x1)                                        /* (SUPC_MR) The core reset signal, vddcore_nreset is asserted when a brownout detection occurs.  */
#define SUPC_MR_BODRSTEN_NOT_ENABLE           (SUPC_MR_BODRSTEN_NOT_ENABLE_Val << SUPC_MR_BODRSTEN_Pos) /* (SUPC_MR) The core reset signal vddcore_nreset is not affected when a brownout detection occurs. Position */
#define SUPC_MR_BODRSTEN_ENABLE               (SUPC_MR_BODRSTEN_ENABLE_Val << SUPC_MR_BODRSTEN_Pos) /* (SUPC_MR) The core reset signal, vddcore_nreset is asserted when a brownout detection occurs. Position */
#define SUPC_MR_BODDIS_Pos                    _UINT32_(13)                                         /* (SUPC_MR) Brownout Detector Disable Position */
#define SUPC_MR_BODDIS_Msk                    (_UINT32_(0x1) << SUPC_MR_BODDIS_Pos)                /* (SUPC_MR) Brownout Detector Disable Mask */
#define SUPC_MR_BODDIS(value)                 (SUPC_MR_BODDIS_Msk & (_UINT32_(value) << SUPC_MR_BODDIS_Pos)) /* Assignment of value for BODDIS in the SUPC_MR register */
#define   SUPC_MR_BODDIS_ENABLE_Val           _UINT32_(0x0)                                        /* (SUPC_MR) The core brownout detector is enabled.  */
#define   SUPC_MR_BODDIS_DISABLE_Val          _UINT32_(0x1)                                        /* (SUPC_MR) The core brownout detector is disabled.  */
#define SUPC_MR_BODDIS_ENABLE                 (SUPC_MR_BODDIS_ENABLE_Val << SUPC_MR_BODDIS_Pos)    /* (SUPC_MR) The core brownout detector is enabled. Position */
#define SUPC_MR_BODDIS_DISABLE                (SUPC_MR_BODDIS_DISABLE_Val << SUPC_MR_BODDIS_Pos)   /* (SUPC_MR) The core brownout detector is disabled. Position */
#define SUPC_MR_ONREG_Pos                     _UINT32_(14)                                         /* (SUPC_MR) Voltage Regulator Enable Position */
#define SUPC_MR_ONREG_Msk                     (_UINT32_(0x1) << SUPC_MR_ONREG_Pos)                 /* (SUPC_MR) Voltage Regulator Enable Mask */
#define SUPC_MR_ONREG(value)                  (SUPC_MR_ONREG_Msk & (_UINT32_(value) << SUPC_MR_ONREG_Pos)) /* Assignment of value for ONREG in the SUPC_MR register */
#define   SUPC_MR_ONREG_ONREG_UNUSED_Val      _UINT32_(0x0)                                        /* (SUPC_MR) Internal voltage regulator is not used (external power supply is used).  */
#define   SUPC_MR_ONREG_ONREG_USED_Val        _UINT32_(0x1)                                        /* (SUPC_MR) Internal voltage regulator is used.  */
#define SUPC_MR_ONREG_ONREG_UNUSED            (SUPC_MR_ONREG_ONREG_UNUSED_Val << SUPC_MR_ONREG_Pos) /* (SUPC_MR) Internal voltage regulator is not used (external power supply is used). Position */
#define SUPC_MR_ONREG_ONREG_USED              (SUPC_MR_ONREG_ONREG_USED_Val << SUPC_MR_ONREG_Pos)  /* (SUPC_MR) Internal voltage regulator is used. Position */
#define SUPC_MR_BKUPRETON_Pos                 _UINT32_(17)                                         /* (SUPC_MR) SRAM On In Backup Mode Position */
#define SUPC_MR_BKUPRETON_Msk                 (_UINT32_(0x1) << SUPC_MR_BKUPRETON_Pos)             /* (SUPC_MR) SRAM On In Backup Mode Mask */
#define SUPC_MR_BKUPRETON(value)              (SUPC_MR_BKUPRETON_Msk & (_UINT32_(value) << SUPC_MR_BKUPRETON_Pos)) /* Assignment of value for BKUPRETON in the SUPC_MR register */
#define SUPC_MR_OSCBYPASS_Pos                 _UINT32_(20)                                         /* (SUPC_MR) Oscillator Bypass Position */
#define SUPC_MR_OSCBYPASS_Msk                 (_UINT32_(0x1) << SUPC_MR_OSCBYPASS_Pos)             /* (SUPC_MR) Oscillator Bypass Mask */
#define SUPC_MR_OSCBYPASS(value)              (SUPC_MR_OSCBYPASS_Msk & (_UINT32_(value) << SUPC_MR_OSCBYPASS_Pos)) /* Assignment of value for OSCBYPASS in the SUPC_MR register */
#define   SUPC_MR_OSCBYPASS_NO_EFFECT_Val     _UINT32_(0x0)                                        /* (SUPC_MR) No effect. Clock selection depends on the value of XTALSEL (SUPC_CR).  */
#define   SUPC_MR_OSCBYPASS_BYPASS_Val        _UINT32_(0x1)                                        /* (SUPC_MR) The 32 kHz crystal oscillator is bypassed if XTALSEL (SUPC_CR) is set. OSCBYPASS must be set prior to setting XTALSEL.  */
#define SUPC_MR_OSCBYPASS_NO_EFFECT           (SUPC_MR_OSCBYPASS_NO_EFFECT_Val << SUPC_MR_OSCBYPASS_Pos) /* (SUPC_MR) No effect. Clock selection depends on the value of XTALSEL (SUPC_CR). Position */
#define SUPC_MR_OSCBYPASS_BYPASS              (SUPC_MR_OSCBYPASS_BYPASS_Val << SUPC_MR_OSCBYPASS_Pos) /* (SUPC_MR) The 32 kHz crystal oscillator is bypassed if XTALSEL (SUPC_CR) is set. OSCBYPASS must be set prior to setting XTALSEL. Position */
#define SUPC_MR_KEY_Pos                       _UINT32_(24)                                         /* (SUPC_MR) Password Key Position */
#define SUPC_MR_KEY_Msk                       (_UINT32_(0xFF) << SUPC_MR_KEY_Pos)                  /* (SUPC_MR) Password Key Mask */
#define SUPC_MR_KEY(value)                    (SUPC_MR_KEY_Msk & (_UINT32_(value) << SUPC_MR_KEY_Pos)) /* Assignment of value for KEY in the SUPC_MR register */
#define   SUPC_MR_KEY_PASSWD_Val              _UINT32_(0xA5)                                       /* (SUPC_MR) Writing any other value in this field aborts the write operation.  */
#define SUPC_MR_KEY_PASSWD                    (SUPC_MR_KEY_PASSWD_Val << SUPC_MR_KEY_Pos)          /* (SUPC_MR) Writing any other value in this field aborts the write operation. Position */
#define SUPC_MR_Msk                           _UINT32_(0xFF127000)                                 /* (SUPC_MR) Register Mask  */


/* -------- SUPC_WUMR : (SUPC Offset: 0x0C) (R/W 32) Supply Controller Wake-up Mode Register -------- */
#define SUPC_WUMR_SMEN_Pos                    _UINT32_(1)                                          /* (SUPC_WUMR) Supply Monitor Wake-up Enable Position */
#define SUPC_WUMR_SMEN_Msk                    (_UINT32_(0x1) << SUPC_WUMR_SMEN_Pos)                /* (SUPC_WUMR) Supply Monitor Wake-up Enable Mask */
#define SUPC_WUMR_SMEN(value)                 (SUPC_WUMR_SMEN_Msk & (_UINT32_(value) << SUPC_WUMR_SMEN_Pos)) /* Assignment of value for SMEN in the SUPC_WUMR register */
#define   SUPC_WUMR_SMEN_NOT_ENABLE_Val       _UINT32_(0x0)                                        /* (SUPC_WUMR) The supply monitor detection has no wake-up effect.  */
#define   SUPC_WUMR_SMEN_ENABLE_Val           _UINT32_(0x1)                                        /* (SUPC_WUMR) The supply monitor detection forces the wake-up of the core power supply.  */
#define SUPC_WUMR_SMEN_NOT_ENABLE             (SUPC_WUMR_SMEN_NOT_ENABLE_Val << SUPC_WUMR_SMEN_Pos) /* (SUPC_WUMR) The supply monitor detection has no wake-up effect. Position */
#define SUPC_WUMR_SMEN_ENABLE                 (SUPC_WUMR_SMEN_ENABLE_Val << SUPC_WUMR_SMEN_Pos)    /* (SUPC_WUMR) The supply monitor detection forces the wake-up of the core power supply. Position */
#define SUPC_WUMR_RTTEN_Pos                   _UINT32_(2)                                          /* (SUPC_WUMR) Real-time Timer Wake-up Enable Position */
#define SUPC_WUMR_RTTEN_Msk                   (_UINT32_(0x1) << SUPC_WUMR_RTTEN_Pos)               /* (SUPC_WUMR) Real-time Timer Wake-up Enable Mask */
#define SUPC_WUMR_RTTEN(value)                (SUPC_WUMR_RTTEN_Msk & (_UINT32_(value) << SUPC_WUMR_RTTEN_Pos)) /* Assignment of value for RTTEN in the SUPC_WUMR register */
#define   SUPC_WUMR_RTTEN_NOT_ENABLE_Val      _UINT32_(0x0)                                        /* (SUPC_WUMR) The RTT alarm signal has no wake-up effect.  */
#define   SUPC_WUMR_RTTEN_ENABLE_Val          _UINT32_(0x1)                                        /* (SUPC_WUMR) The RTT alarm signal forces the wake-up of the core power supply.  */
#define SUPC_WUMR_RTTEN_NOT_ENABLE            (SUPC_WUMR_RTTEN_NOT_ENABLE_Val << SUPC_WUMR_RTTEN_Pos) /* (SUPC_WUMR) The RTT alarm signal has no wake-up effect. Position */
#define SUPC_WUMR_RTTEN_ENABLE                (SUPC_WUMR_RTTEN_ENABLE_Val << SUPC_WUMR_RTTEN_Pos)  /* (SUPC_WUMR) The RTT alarm signal forces the wake-up of the core power supply. Position */
#define SUPC_WUMR_RTCEN_Pos                   _UINT32_(3)                                          /* (SUPC_WUMR) Real-time Clock Wake-up Enable Position */
#define SUPC_WUMR_RTCEN_Msk                   (_UINT32_(0x1) << SUPC_WUMR_RTCEN_Pos)               /* (SUPC_WUMR) Real-time Clock Wake-up Enable Mask */
#define SUPC_WUMR_RTCEN(value)                (SUPC_WUMR_RTCEN_Msk & (_UINT32_(value) << SUPC_WUMR_RTCEN_Pos)) /* Assignment of value for RTCEN in the SUPC_WUMR register */
#define   SUPC_WUMR_RTCEN_NOT_ENABLE_Val      _UINT32_(0x0)                                        /* (SUPC_WUMR) The RTC alarm signal has no wake-up effect.  */
#define   SUPC_WUMR_RTCEN_ENABLE_Val          _UINT32_(0x1)                                        /* (SUPC_WUMR) The RTC alarm signal forces the wake-up of the core power supply.  */
#define SUPC_WUMR_RTCEN_NOT_ENABLE            (SUPC_WUMR_RTCEN_NOT_ENABLE_Val << SUPC_WUMR_RTCEN_Pos) /* (SUPC_WUMR) The RTC alarm signal has no wake-up effect. Position */
#define SUPC_WUMR_RTCEN_ENABLE                (SUPC_WUMR_RTCEN_ENABLE_Val << SUPC_WUMR_RTCEN_Pos)  /* (SUPC_WUMR) The RTC alarm signal forces the wake-up of the core power supply. Position */
#define SUPC_WUMR_LPDBCEN0_Pos                _UINT32_(5)                                          /* (SUPC_WUMR) Low-power Debouncer Enable WKUP0 Position */
#define SUPC_WUMR_LPDBCEN0_Msk                (_UINT32_(0x1) << SUPC_WUMR_LPDBCEN0_Pos)            /* (SUPC_WUMR) Low-power Debouncer Enable WKUP0 Mask */
#define SUPC_WUMR_LPDBCEN0(value)             (SUPC_WUMR_LPDBCEN0_Msk & (_UINT32_(value) << SUPC_WUMR_LPDBCEN0_Pos)) /* Assignment of value for LPDBCEN0 in the SUPC_WUMR register */
#define   SUPC_WUMR_LPDBCEN0_NOT_ENABLE_Val   _UINT32_(0x0)                                        /* (SUPC_WUMR) The WKUP0 input pin is not connected to the low-power debouncer.  */
#define   SUPC_WUMR_LPDBCEN0_ENABLE_Val       _UINT32_(0x1)                                        /* (SUPC_WUMR) The WKUP0 input pin is connected to the low-power debouncer and forces a system wake-up.  */
#define SUPC_WUMR_LPDBCEN0_NOT_ENABLE         (SUPC_WUMR_LPDBCEN0_NOT_ENABLE_Val << SUPC_WUMR_LPDBCEN0_Pos) /* (SUPC_WUMR) The WKUP0 input pin is not connected to the low-power debouncer. Position */
#define SUPC_WUMR_LPDBCEN0_ENABLE             (SUPC_WUMR_LPDBCEN0_ENABLE_Val << SUPC_WUMR_LPDBCEN0_Pos) /* (SUPC_WUMR) The WKUP0 input pin is connected to the low-power debouncer and forces a system wake-up. Position */
#define SUPC_WUMR_LPDBCEN1_Pos                _UINT32_(6)                                          /* (SUPC_WUMR) Low-power Debouncer Enable WKUP1 Position */
#define SUPC_WUMR_LPDBCEN1_Msk                (_UINT32_(0x1) << SUPC_WUMR_LPDBCEN1_Pos)            /* (SUPC_WUMR) Low-power Debouncer Enable WKUP1 Mask */
#define SUPC_WUMR_LPDBCEN1(value)             (SUPC_WUMR_LPDBCEN1_Msk & (_UINT32_(value) << SUPC_WUMR_LPDBCEN1_Pos)) /* Assignment of value for LPDBCEN1 in the SUPC_WUMR register */
#define   SUPC_WUMR_LPDBCEN1_NOT_ENABLE_Val   _UINT32_(0x0)                                        /* (SUPC_WUMR) The WKUP1 input pin is not connected to the low-power debouncer.  */
#define   SUPC_WUMR_LPDBCEN1_ENABLE_Val       _UINT32_(0x1)                                        /* (SUPC_WUMR) The WKUP1 input pin is connected to the low-power debouncer and forces a system wake-up.  */
#define SUPC_WUMR_LPDBCEN1_NOT_ENABLE         (SUPC_WUMR_LPDBCEN1_NOT_ENABLE_Val << SUPC_WUMR_LPDBCEN1_Pos) /* (SUPC_WUMR) The WKUP1 input pin is not connected to the low-power debouncer. Position */
#define SUPC_WUMR_LPDBCEN1_ENABLE             (SUPC_WUMR_LPDBCEN1_ENABLE_Val << SUPC_WUMR_LPDBCEN1_Pos) /* (SUPC_WUMR) The WKUP1 input pin is connected to the low-power debouncer and forces a system wake-up. Position */
#define SUPC_WUMR_LPDBCCLR_Pos                _UINT32_(7)                                          /* (SUPC_WUMR) Low-power Debouncer Clear Position */
#define SUPC_WUMR_LPDBCCLR_Msk                (_UINT32_(0x1) << SUPC_WUMR_LPDBCCLR_Pos)            /* (SUPC_WUMR) Low-power Debouncer Clear Mask */
#define SUPC_WUMR_LPDBCCLR(value)             (SUPC_WUMR_LPDBCCLR_Msk & (_UINT32_(value) << SUPC_WUMR_LPDBCCLR_Pos)) /* Assignment of value for LPDBCCLR in the SUPC_WUMR register */
#define   SUPC_WUMR_LPDBCCLR_NOT_ENABLE_Val   _UINT32_(0x0)                                        /* (SUPC_WUMR) A low-power debounce event does not create an immediate clear on the first half of GPBR registers.  */
#define   SUPC_WUMR_LPDBCCLR_ENABLE_Val       _UINT32_(0x1)                                        /* (SUPC_WUMR) A low-power debounce event on WKUP0 or WKUP1 generates an immediate clear on the first half of GPBR registers.  */
#define SUPC_WUMR_LPDBCCLR_NOT_ENABLE         (SUPC_WUMR_LPDBCCLR_NOT_ENABLE_Val << SUPC_WUMR_LPDBCCLR_Pos) /* (SUPC_WUMR) A low-power debounce event does not create an immediate clear on the first half of GPBR registers. Position */
#define SUPC_WUMR_LPDBCCLR_ENABLE             (SUPC_WUMR_LPDBCCLR_ENABLE_Val << SUPC_WUMR_LPDBCCLR_Pos) /* (SUPC_WUMR) A low-power debounce event on WKUP0 or WKUP1 generates an immediate clear on the first half of GPBR registers. Position */
#define SUPC_WUMR_WKUPDBC_Pos                 _UINT32_(12)                                         /* (SUPC_WUMR) Wake-up Inputs Debouncer Period Position */
#define SUPC_WUMR_WKUPDBC_Msk                 (_UINT32_(0x7) << SUPC_WUMR_WKUPDBC_Pos)             /* (SUPC_WUMR) Wake-up Inputs Debouncer Period Mask */
#define SUPC_WUMR_WKUPDBC(value)              (SUPC_WUMR_WKUPDBC_Msk & (_UINT32_(value) << SUPC_WUMR_WKUPDBC_Pos)) /* Assignment of value for WKUPDBC in the SUPC_WUMR register */
#define   SUPC_WUMR_WKUPDBC_IMMEDIATE_Val     _UINT32_(0x0)                                        /* (SUPC_WUMR) Immediate, no debouncing, detected active at least on one Slow Clock edge.  */
#define   SUPC_WUMR_WKUPDBC_3_SLCK_Val        _UINT32_(0x1)                                        /* (SUPC_WUMR) WKUPx shall be in its active state for at least 3 SLCK periods  */
#define   SUPC_WUMR_WKUPDBC_32_SLCK_Val       _UINT32_(0x2)                                        /* (SUPC_WUMR) WKUPx shall be in its active state for at least 32 SLCK periods  */
#define   SUPC_WUMR_WKUPDBC_512_SLCK_Val      _UINT32_(0x3)                                        /* (SUPC_WUMR) WKUPx shall be in its active state for at least 512 SLCK periods  */
#define   SUPC_WUMR_WKUPDBC_4096_SLCK_Val     _UINT32_(0x4)                                        /* (SUPC_WUMR) WKUPx shall be in its active state for at least 4,096 SLCK periods  */
#define   SUPC_WUMR_WKUPDBC_32768_SLCK_Val    _UINT32_(0x5)                                        /* (SUPC_WUMR) WKUPx shall be in its active state for at least 32,768 SLCK periods  */
#define SUPC_WUMR_WKUPDBC_IMMEDIATE           (SUPC_WUMR_WKUPDBC_IMMEDIATE_Val << SUPC_WUMR_WKUPDBC_Pos) /* (SUPC_WUMR) Immediate, no debouncing, detected active at least on one Slow Clock edge. Position */
#define SUPC_WUMR_WKUPDBC_3_SLCK              (SUPC_WUMR_WKUPDBC_3_SLCK_Val << SUPC_WUMR_WKUPDBC_Pos) /* (SUPC_WUMR) WKUPx shall be in its active state for at least 3 SLCK periods Position */
#define SUPC_WUMR_WKUPDBC_32_SLCK             (SUPC_WUMR_WKUPDBC_32_SLCK_Val << SUPC_WUMR_WKUPDBC_Pos) /* (SUPC_WUMR) WKUPx shall be in its active state for at least 32 SLCK periods Position */
#define SUPC_WUMR_WKUPDBC_512_SLCK            (SUPC_WUMR_WKUPDBC_512_SLCK_Val << SUPC_WUMR_WKUPDBC_Pos) /* (SUPC_WUMR) WKUPx shall be in its active state for at least 512 SLCK periods Position */
#define SUPC_WUMR_WKUPDBC_4096_SLCK           (SUPC_WUMR_WKUPDBC_4096_SLCK_Val << SUPC_WUMR_WKUPDBC_Pos) /* (SUPC_WUMR) WKUPx shall be in its active state for at least 4,096 SLCK periods Position */
#define SUPC_WUMR_WKUPDBC_32768_SLCK          (SUPC_WUMR_WKUPDBC_32768_SLCK_Val << SUPC_WUMR_WKUPDBC_Pos) /* (SUPC_WUMR) WKUPx shall be in its active state for at least 32,768 SLCK periods Position */
#define SUPC_WUMR_LPDBC_Pos                   _UINT32_(16)                                         /* (SUPC_WUMR) Low-power Debouncer Period Position */
#define SUPC_WUMR_LPDBC_Msk                   (_UINT32_(0x7) << SUPC_WUMR_LPDBC_Pos)               /* (SUPC_WUMR) Low-power Debouncer Period Mask */
#define SUPC_WUMR_LPDBC(value)                (SUPC_WUMR_LPDBC_Msk & (_UINT32_(value) << SUPC_WUMR_LPDBC_Pos)) /* Assignment of value for LPDBC in the SUPC_WUMR register */
#define   SUPC_WUMR_LPDBC_DISABLE_Val         _UINT32_(0x0)                                        /* (SUPC_WUMR) Disable the low-power debouncers.  */
#define   SUPC_WUMR_LPDBC_2_RTCOUT_Val        _UINT32_(0x1)                                        /* (SUPC_WUMR) WKUP0/1 in active state for at least 2 RTCOUTx clock periods  */
#define   SUPC_WUMR_LPDBC_3_RTCOUT_Val        _UINT32_(0x2)                                        /* (SUPC_WUMR) WKUP0/1 in active state for at least 3 RTCOUTx clock periods  */
#define   SUPC_WUMR_LPDBC_4_RTCOUT_Val        _UINT32_(0x3)                                        /* (SUPC_WUMR) WKUP0/1 in active state for at least 4 RTCOUTx clock periods  */
#define   SUPC_WUMR_LPDBC_5_RTCOUT_Val        _UINT32_(0x4)                                        /* (SUPC_WUMR) WKUP0/1 in active state for at least 5 RTCOUTx clock periods  */
#define   SUPC_WUMR_LPDBC_6_RTCOUT_Val        _UINT32_(0x5)                                        /* (SUPC_WUMR) WKUP0/1 in active state for at least 6 RTCOUTx clock periods  */
#define   SUPC_WUMR_LPDBC_7_RTCOUT_Val        _UINT32_(0x6)                                        /* (SUPC_WUMR) WKUP0/1 in active state for at least 7 RTCOUTx clock periods  */
#define   SUPC_WUMR_LPDBC_8_RTCOUT_Val        _UINT32_(0x7)                                        /* (SUPC_WUMR) WKUP0/1 in active state for at least 8 RTCOUTx clock periods  */
#define SUPC_WUMR_LPDBC_DISABLE               (SUPC_WUMR_LPDBC_DISABLE_Val << SUPC_WUMR_LPDBC_Pos) /* (SUPC_WUMR) Disable the low-power debouncers. Position */
#define SUPC_WUMR_LPDBC_2_RTCOUT              (SUPC_WUMR_LPDBC_2_RTCOUT_Val << SUPC_WUMR_LPDBC_Pos) /* (SUPC_WUMR) WKUP0/1 in active state for at least 2 RTCOUTx clock periods Position */
#define SUPC_WUMR_LPDBC_3_RTCOUT              (SUPC_WUMR_LPDBC_3_RTCOUT_Val << SUPC_WUMR_LPDBC_Pos) /* (SUPC_WUMR) WKUP0/1 in active state for at least 3 RTCOUTx clock periods Position */
#define SUPC_WUMR_LPDBC_4_RTCOUT              (SUPC_WUMR_LPDBC_4_RTCOUT_Val << SUPC_WUMR_LPDBC_Pos) /* (SUPC_WUMR) WKUP0/1 in active state for at least 4 RTCOUTx clock periods Position */
#define SUPC_WUMR_LPDBC_5_RTCOUT              (SUPC_WUMR_LPDBC_5_RTCOUT_Val << SUPC_WUMR_LPDBC_Pos) /* (SUPC_WUMR) WKUP0/1 in active state for at least 5 RTCOUTx clock periods Position */
#define SUPC_WUMR_LPDBC_6_RTCOUT              (SUPC_WUMR_LPDBC_6_RTCOUT_Val << SUPC_WUMR_LPDBC_Pos) /* (SUPC_WUMR) WKUP0/1 in active state for at least 6 RTCOUTx clock periods Position */
#define SUPC_WUMR_LPDBC_7_RTCOUT              (SUPC_WUMR_LPDBC_7_RTCOUT_Val << SUPC_WUMR_LPDBC_Pos) /* (SUPC_WUMR) WKUP0/1 in active state for at least 7 RTCOUTx clock periods Position */
#define SUPC_WUMR_LPDBC_8_RTCOUT              (SUPC_WUMR_LPDBC_8_RTCOUT_Val << SUPC_WUMR_LPDBC_Pos) /* (SUPC_WUMR) WKUP0/1 in active state for at least 8 RTCOUTx clock periods Position */
#define SUPC_WUMR_Msk                         _UINT32_(0x000770EE)                                 /* (SUPC_WUMR) Register Mask  */

#define SUPC_WUMR_LPDBCEN_Pos                 _UINT32_(5)                                          /* (SUPC_WUMR Position) Low-power Debouncer Enable WKUPx */
#define SUPC_WUMR_LPDBCEN_Msk                 (_UINT32_(0x3) << SUPC_WUMR_LPDBCEN_Pos)             /* (SUPC_WUMR Mask) LPDBCEN */
#define SUPC_WUMR_LPDBCEN(value)              (SUPC_WUMR_LPDBCEN_Msk & (_UINT32_(value) << SUPC_WUMR_LPDBCEN_Pos)) 

/* -------- SUPC_WUIR : (SUPC Offset: 0x10) (R/W 32) Supply Controller Wake-up Inputs Register -------- */
#define SUPC_WUIR_WKUPEN0_Pos                 _UINT32_(0)                                          /* (SUPC_WUIR) Wake-up Input Enable 0 to 0 Position */
#define SUPC_WUIR_WKUPEN0_Msk                 (_UINT32_(0x1) << SUPC_WUIR_WKUPEN0_Pos)             /* (SUPC_WUIR) Wake-up Input Enable 0 to 0 Mask */
#define SUPC_WUIR_WKUPEN0(value)              (SUPC_WUIR_WKUPEN0_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPEN0_Pos)) /* Assignment of value for WKUPEN0 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPEN0_DISABLE_Val       _UINT32_(0x0)                                        /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN0_ENABLE_Val        _UINT32_(0x1)                                        /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN0_DISABLE             (SUPC_WUIR_WKUPEN0_DISABLE_Val << SUPC_WUIR_WKUPEN0_Pos) /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position */
#define SUPC_WUIR_WKUPEN0_ENABLE              (SUPC_WUIR_WKUPEN0_ENABLE_Val << SUPC_WUIR_WKUPEN0_Pos) /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPEN1_Pos                 _UINT32_(1)                                          /* (SUPC_WUIR) Wake-up Input Enable 0 to 1 Position */
#define SUPC_WUIR_WKUPEN1_Msk                 (_UINT32_(0x1) << SUPC_WUIR_WKUPEN1_Pos)             /* (SUPC_WUIR) Wake-up Input Enable 0 to 1 Mask */
#define SUPC_WUIR_WKUPEN1(value)              (SUPC_WUIR_WKUPEN1_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPEN1_Pos)) /* Assignment of value for WKUPEN1 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPEN1_DISABLE_Val       _UINT32_(0x0)                                        /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN1_ENABLE_Val        _UINT32_(0x1)                                        /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN1_DISABLE             (SUPC_WUIR_WKUPEN1_DISABLE_Val << SUPC_WUIR_WKUPEN1_Pos) /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position */
#define SUPC_WUIR_WKUPEN1_ENABLE              (SUPC_WUIR_WKUPEN1_ENABLE_Val << SUPC_WUIR_WKUPEN1_Pos) /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPEN2_Pos                 _UINT32_(2)                                          /* (SUPC_WUIR) Wake-up Input Enable 0 to 2 Position */
#define SUPC_WUIR_WKUPEN2_Msk                 (_UINT32_(0x1) << SUPC_WUIR_WKUPEN2_Pos)             /* (SUPC_WUIR) Wake-up Input Enable 0 to 2 Mask */
#define SUPC_WUIR_WKUPEN2(value)              (SUPC_WUIR_WKUPEN2_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPEN2_Pos)) /* Assignment of value for WKUPEN2 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPEN2_DISABLE_Val       _UINT32_(0x0)                                        /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN2_ENABLE_Val        _UINT32_(0x1)                                        /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN2_DISABLE             (SUPC_WUIR_WKUPEN2_DISABLE_Val << SUPC_WUIR_WKUPEN2_Pos) /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position */
#define SUPC_WUIR_WKUPEN2_ENABLE              (SUPC_WUIR_WKUPEN2_ENABLE_Val << SUPC_WUIR_WKUPEN2_Pos) /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPEN3_Pos                 _UINT32_(3)                                          /* (SUPC_WUIR) Wake-up Input Enable 0 to 3 Position */
#define SUPC_WUIR_WKUPEN3_Msk                 (_UINT32_(0x1) << SUPC_WUIR_WKUPEN3_Pos)             /* (SUPC_WUIR) Wake-up Input Enable 0 to 3 Mask */
#define SUPC_WUIR_WKUPEN3(value)              (SUPC_WUIR_WKUPEN3_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPEN3_Pos)) /* Assignment of value for WKUPEN3 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPEN3_DISABLE_Val       _UINT32_(0x0)                                        /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN3_ENABLE_Val        _UINT32_(0x1)                                        /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN3_DISABLE             (SUPC_WUIR_WKUPEN3_DISABLE_Val << SUPC_WUIR_WKUPEN3_Pos) /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position */
#define SUPC_WUIR_WKUPEN3_ENABLE              (SUPC_WUIR_WKUPEN3_ENABLE_Val << SUPC_WUIR_WKUPEN3_Pos) /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPEN4_Pos                 _UINT32_(4)                                          /* (SUPC_WUIR) Wake-up Input Enable 0 to 4 Position */
#define SUPC_WUIR_WKUPEN4_Msk                 (_UINT32_(0x1) << SUPC_WUIR_WKUPEN4_Pos)             /* (SUPC_WUIR) Wake-up Input Enable 0 to 4 Mask */
#define SUPC_WUIR_WKUPEN4(value)              (SUPC_WUIR_WKUPEN4_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPEN4_Pos)) /* Assignment of value for WKUPEN4 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPEN4_DISABLE_Val       _UINT32_(0x0)                                        /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN4_ENABLE_Val        _UINT32_(0x1)                                        /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN4_DISABLE             (SUPC_WUIR_WKUPEN4_DISABLE_Val << SUPC_WUIR_WKUPEN4_Pos) /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position */
#define SUPC_WUIR_WKUPEN4_ENABLE              (SUPC_WUIR_WKUPEN4_ENABLE_Val << SUPC_WUIR_WKUPEN4_Pos) /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPEN5_Pos                 _UINT32_(5)                                          /* (SUPC_WUIR) Wake-up Input Enable 0 to 5 Position */
#define SUPC_WUIR_WKUPEN5_Msk                 (_UINT32_(0x1) << SUPC_WUIR_WKUPEN5_Pos)             /* (SUPC_WUIR) Wake-up Input Enable 0 to 5 Mask */
#define SUPC_WUIR_WKUPEN5(value)              (SUPC_WUIR_WKUPEN5_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPEN5_Pos)) /* Assignment of value for WKUPEN5 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPEN5_DISABLE_Val       _UINT32_(0x0)                                        /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN5_ENABLE_Val        _UINT32_(0x1)                                        /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN5_DISABLE             (SUPC_WUIR_WKUPEN5_DISABLE_Val << SUPC_WUIR_WKUPEN5_Pos) /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position */
#define SUPC_WUIR_WKUPEN5_ENABLE              (SUPC_WUIR_WKUPEN5_ENABLE_Val << SUPC_WUIR_WKUPEN5_Pos) /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPEN6_Pos                 _UINT32_(6)                                          /* (SUPC_WUIR) Wake-up Input Enable 0 to 6 Position */
#define SUPC_WUIR_WKUPEN6_Msk                 (_UINT32_(0x1) << SUPC_WUIR_WKUPEN6_Pos)             /* (SUPC_WUIR) Wake-up Input Enable 0 to 6 Mask */
#define SUPC_WUIR_WKUPEN6(value)              (SUPC_WUIR_WKUPEN6_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPEN6_Pos)) /* Assignment of value for WKUPEN6 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPEN6_DISABLE_Val       _UINT32_(0x0)                                        /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN6_ENABLE_Val        _UINT32_(0x1)                                        /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN6_DISABLE             (SUPC_WUIR_WKUPEN6_DISABLE_Val << SUPC_WUIR_WKUPEN6_Pos) /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position */
#define SUPC_WUIR_WKUPEN6_ENABLE              (SUPC_WUIR_WKUPEN6_ENABLE_Val << SUPC_WUIR_WKUPEN6_Pos) /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPEN7_Pos                 _UINT32_(7)                                          /* (SUPC_WUIR) Wake-up Input Enable 0 to 7 Position */
#define SUPC_WUIR_WKUPEN7_Msk                 (_UINT32_(0x1) << SUPC_WUIR_WKUPEN7_Pos)             /* (SUPC_WUIR) Wake-up Input Enable 0 to 7 Mask */
#define SUPC_WUIR_WKUPEN7(value)              (SUPC_WUIR_WKUPEN7_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPEN7_Pos)) /* Assignment of value for WKUPEN7 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPEN7_DISABLE_Val       _UINT32_(0x0)                                        /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN7_ENABLE_Val        _UINT32_(0x1)                                        /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN7_DISABLE             (SUPC_WUIR_WKUPEN7_DISABLE_Val << SUPC_WUIR_WKUPEN7_Pos) /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position */
#define SUPC_WUIR_WKUPEN7_ENABLE              (SUPC_WUIR_WKUPEN7_ENABLE_Val << SUPC_WUIR_WKUPEN7_Pos) /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPEN8_Pos                 _UINT32_(8)                                          /* (SUPC_WUIR) Wake-up Input Enable 0 to 8 Position */
#define SUPC_WUIR_WKUPEN8_Msk                 (_UINT32_(0x1) << SUPC_WUIR_WKUPEN8_Pos)             /* (SUPC_WUIR) Wake-up Input Enable 0 to 8 Mask */
#define SUPC_WUIR_WKUPEN8(value)              (SUPC_WUIR_WKUPEN8_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPEN8_Pos)) /* Assignment of value for WKUPEN8 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPEN8_DISABLE_Val       _UINT32_(0x0)                                        /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN8_ENABLE_Val        _UINT32_(0x1)                                        /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN8_DISABLE             (SUPC_WUIR_WKUPEN8_DISABLE_Val << SUPC_WUIR_WKUPEN8_Pos) /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position */
#define SUPC_WUIR_WKUPEN8_ENABLE              (SUPC_WUIR_WKUPEN8_ENABLE_Val << SUPC_WUIR_WKUPEN8_Pos) /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPEN9_Pos                 _UINT32_(9)                                          /* (SUPC_WUIR) Wake-up Input Enable 0 to 9 Position */
#define SUPC_WUIR_WKUPEN9_Msk                 (_UINT32_(0x1) << SUPC_WUIR_WKUPEN9_Pos)             /* (SUPC_WUIR) Wake-up Input Enable 0 to 9 Mask */
#define SUPC_WUIR_WKUPEN9(value)              (SUPC_WUIR_WKUPEN9_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPEN9_Pos)) /* Assignment of value for WKUPEN9 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPEN9_DISABLE_Val       _UINT32_(0x0)                                        /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN9_ENABLE_Val        _UINT32_(0x1)                                        /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN9_DISABLE             (SUPC_WUIR_WKUPEN9_DISABLE_Val << SUPC_WUIR_WKUPEN9_Pos) /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position */
#define SUPC_WUIR_WKUPEN9_ENABLE              (SUPC_WUIR_WKUPEN9_ENABLE_Val << SUPC_WUIR_WKUPEN9_Pos) /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPEN10_Pos                _UINT32_(10)                                         /* (SUPC_WUIR) Wake-up Input Enable 0 to 10 Position */
#define SUPC_WUIR_WKUPEN10_Msk                (_UINT32_(0x1) << SUPC_WUIR_WKUPEN10_Pos)            /* (SUPC_WUIR) Wake-up Input Enable 0 to 10 Mask */
#define SUPC_WUIR_WKUPEN10(value)             (SUPC_WUIR_WKUPEN10_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPEN10_Pos)) /* Assignment of value for WKUPEN10 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPEN10_DISABLE_Val      _UINT32_(0x0)                                        /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN10_ENABLE_Val       _UINT32_(0x1)                                        /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN10_DISABLE            (SUPC_WUIR_WKUPEN10_DISABLE_Val << SUPC_WUIR_WKUPEN10_Pos) /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position */
#define SUPC_WUIR_WKUPEN10_ENABLE             (SUPC_WUIR_WKUPEN10_ENABLE_Val << SUPC_WUIR_WKUPEN10_Pos) /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPEN11_Pos                _UINT32_(11)                                         /* (SUPC_WUIR) Wake-up Input Enable 0 to 11 Position */
#define SUPC_WUIR_WKUPEN11_Msk                (_UINT32_(0x1) << SUPC_WUIR_WKUPEN11_Pos)            /* (SUPC_WUIR) Wake-up Input Enable 0 to 11 Mask */
#define SUPC_WUIR_WKUPEN11(value)             (SUPC_WUIR_WKUPEN11_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPEN11_Pos)) /* Assignment of value for WKUPEN11 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPEN11_DISABLE_Val      _UINT32_(0x0)                                        /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN11_ENABLE_Val       _UINT32_(0x1)                                        /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN11_DISABLE            (SUPC_WUIR_WKUPEN11_DISABLE_Val << SUPC_WUIR_WKUPEN11_Pos) /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position */
#define SUPC_WUIR_WKUPEN11_ENABLE             (SUPC_WUIR_WKUPEN11_ENABLE_Val << SUPC_WUIR_WKUPEN11_Pos) /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPEN12_Pos                _UINT32_(12)                                         /* (SUPC_WUIR) Wake-up Input Enable 0 to 12 Position */
#define SUPC_WUIR_WKUPEN12_Msk                (_UINT32_(0x1) << SUPC_WUIR_WKUPEN12_Pos)            /* (SUPC_WUIR) Wake-up Input Enable 0 to 12 Mask */
#define SUPC_WUIR_WKUPEN12(value)             (SUPC_WUIR_WKUPEN12_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPEN12_Pos)) /* Assignment of value for WKUPEN12 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPEN12_DISABLE_Val      _UINT32_(0x0)                                        /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN12_ENABLE_Val       _UINT32_(0x1)                                        /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN12_DISABLE            (SUPC_WUIR_WKUPEN12_DISABLE_Val << SUPC_WUIR_WKUPEN12_Pos) /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position */
#define SUPC_WUIR_WKUPEN12_ENABLE             (SUPC_WUIR_WKUPEN12_ENABLE_Val << SUPC_WUIR_WKUPEN12_Pos) /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPEN13_Pos                _UINT32_(13)                                         /* (SUPC_WUIR) Wake-up Input Enable 0 to 13 Position */
#define SUPC_WUIR_WKUPEN13_Msk                (_UINT32_(0x1) << SUPC_WUIR_WKUPEN13_Pos)            /* (SUPC_WUIR) Wake-up Input Enable 0 to 13 Mask */
#define SUPC_WUIR_WKUPEN13(value)             (SUPC_WUIR_WKUPEN13_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPEN13_Pos)) /* Assignment of value for WKUPEN13 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPEN13_DISABLE_Val      _UINT32_(0x0)                                        /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN13_ENABLE_Val       _UINT32_(0x1)                                        /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN13_DISABLE            (SUPC_WUIR_WKUPEN13_DISABLE_Val << SUPC_WUIR_WKUPEN13_Pos) /* (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position */
#define SUPC_WUIR_WKUPEN13_ENABLE             (SUPC_WUIR_WKUPEN13_ENABLE_Val << SUPC_WUIR_WKUPEN13_Pos) /* (SUPC_WUIR) The corresponding wake-up input is enabled for a wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT0_Pos                  _UINT32_(16)                                         /* (SUPC_WUIR) Wake-up Input Type 0 to 0 Position */
#define SUPC_WUIR_WKUPT0_Msk                  (_UINT32_(0x1) << SUPC_WUIR_WKUPT0_Pos)              /* (SUPC_WUIR) Wake-up Input Type 0 to 0 Mask */
#define SUPC_WUIR_WKUPT0(value)               (SUPC_WUIR_WKUPT0_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPT0_Pos)) /* Assignment of value for WKUPT0 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPT0_LOW_Val            _UINT32_(0x0)                                        /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT0_HIGH_Val           _UINT32_(0x1)                                        /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT0_LOW                  (SUPC_WUIR_WKUPT0_LOW_Val << SUPC_WUIR_WKUPT0_Pos)   /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT0_HIGH                 (SUPC_WUIR_WKUPT0_HIGH_Val << SUPC_WUIR_WKUPT0_Pos)  /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT1_Pos                  _UINT32_(17)                                         /* (SUPC_WUIR) Wake-up Input Type 0 to 1 Position */
#define SUPC_WUIR_WKUPT1_Msk                  (_UINT32_(0x1) << SUPC_WUIR_WKUPT1_Pos)              /* (SUPC_WUIR) Wake-up Input Type 0 to 1 Mask */
#define SUPC_WUIR_WKUPT1(value)               (SUPC_WUIR_WKUPT1_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPT1_Pos)) /* Assignment of value for WKUPT1 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPT1_LOW_Val            _UINT32_(0x0)                                        /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT1_HIGH_Val           _UINT32_(0x1)                                        /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT1_LOW                  (SUPC_WUIR_WKUPT1_LOW_Val << SUPC_WUIR_WKUPT1_Pos)   /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT1_HIGH                 (SUPC_WUIR_WKUPT1_HIGH_Val << SUPC_WUIR_WKUPT1_Pos)  /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT2_Pos                  _UINT32_(18)                                         /* (SUPC_WUIR) Wake-up Input Type 0 to 2 Position */
#define SUPC_WUIR_WKUPT2_Msk                  (_UINT32_(0x1) << SUPC_WUIR_WKUPT2_Pos)              /* (SUPC_WUIR) Wake-up Input Type 0 to 2 Mask */
#define SUPC_WUIR_WKUPT2(value)               (SUPC_WUIR_WKUPT2_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPT2_Pos)) /* Assignment of value for WKUPT2 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPT2_LOW_Val            _UINT32_(0x0)                                        /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT2_HIGH_Val           _UINT32_(0x1)                                        /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT2_LOW                  (SUPC_WUIR_WKUPT2_LOW_Val << SUPC_WUIR_WKUPT2_Pos)   /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT2_HIGH                 (SUPC_WUIR_WKUPT2_HIGH_Val << SUPC_WUIR_WKUPT2_Pos)  /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT3_Pos                  _UINT32_(19)                                         /* (SUPC_WUIR) Wake-up Input Type 0 to 3 Position */
#define SUPC_WUIR_WKUPT3_Msk                  (_UINT32_(0x1) << SUPC_WUIR_WKUPT3_Pos)              /* (SUPC_WUIR) Wake-up Input Type 0 to 3 Mask */
#define SUPC_WUIR_WKUPT3(value)               (SUPC_WUIR_WKUPT3_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPT3_Pos)) /* Assignment of value for WKUPT3 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPT3_LOW_Val            _UINT32_(0x0)                                        /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT3_HIGH_Val           _UINT32_(0x1)                                        /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT3_LOW                  (SUPC_WUIR_WKUPT3_LOW_Val << SUPC_WUIR_WKUPT3_Pos)   /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT3_HIGH                 (SUPC_WUIR_WKUPT3_HIGH_Val << SUPC_WUIR_WKUPT3_Pos)  /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT4_Pos                  _UINT32_(20)                                         /* (SUPC_WUIR) Wake-up Input Type 0 to 4 Position */
#define SUPC_WUIR_WKUPT4_Msk                  (_UINT32_(0x1) << SUPC_WUIR_WKUPT4_Pos)              /* (SUPC_WUIR) Wake-up Input Type 0 to 4 Mask */
#define SUPC_WUIR_WKUPT4(value)               (SUPC_WUIR_WKUPT4_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPT4_Pos)) /* Assignment of value for WKUPT4 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPT4_LOW_Val            _UINT32_(0x0)                                        /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT4_HIGH_Val           _UINT32_(0x1)                                        /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT4_LOW                  (SUPC_WUIR_WKUPT4_LOW_Val << SUPC_WUIR_WKUPT4_Pos)   /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT4_HIGH                 (SUPC_WUIR_WKUPT4_HIGH_Val << SUPC_WUIR_WKUPT4_Pos)  /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT5_Pos                  _UINT32_(21)                                         /* (SUPC_WUIR) Wake-up Input Type 0 to 5 Position */
#define SUPC_WUIR_WKUPT5_Msk                  (_UINT32_(0x1) << SUPC_WUIR_WKUPT5_Pos)              /* (SUPC_WUIR) Wake-up Input Type 0 to 5 Mask */
#define SUPC_WUIR_WKUPT5(value)               (SUPC_WUIR_WKUPT5_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPT5_Pos)) /* Assignment of value for WKUPT5 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPT5_LOW_Val            _UINT32_(0x0)                                        /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT5_HIGH_Val           _UINT32_(0x1)                                        /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT5_LOW                  (SUPC_WUIR_WKUPT5_LOW_Val << SUPC_WUIR_WKUPT5_Pos)   /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT5_HIGH                 (SUPC_WUIR_WKUPT5_HIGH_Val << SUPC_WUIR_WKUPT5_Pos)  /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT6_Pos                  _UINT32_(22)                                         /* (SUPC_WUIR) Wake-up Input Type 0 to 6 Position */
#define SUPC_WUIR_WKUPT6_Msk                  (_UINT32_(0x1) << SUPC_WUIR_WKUPT6_Pos)              /* (SUPC_WUIR) Wake-up Input Type 0 to 6 Mask */
#define SUPC_WUIR_WKUPT6(value)               (SUPC_WUIR_WKUPT6_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPT6_Pos)) /* Assignment of value for WKUPT6 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPT6_LOW_Val            _UINT32_(0x0)                                        /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT6_HIGH_Val           _UINT32_(0x1)                                        /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT6_LOW                  (SUPC_WUIR_WKUPT6_LOW_Val << SUPC_WUIR_WKUPT6_Pos)   /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT6_HIGH                 (SUPC_WUIR_WKUPT6_HIGH_Val << SUPC_WUIR_WKUPT6_Pos)  /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT7_Pos                  _UINT32_(23)                                         /* (SUPC_WUIR) Wake-up Input Type 0 to 7 Position */
#define SUPC_WUIR_WKUPT7_Msk                  (_UINT32_(0x1) << SUPC_WUIR_WKUPT7_Pos)              /* (SUPC_WUIR) Wake-up Input Type 0 to 7 Mask */
#define SUPC_WUIR_WKUPT7(value)               (SUPC_WUIR_WKUPT7_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPT7_Pos)) /* Assignment of value for WKUPT7 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPT7_LOW_Val            _UINT32_(0x0)                                        /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT7_HIGH_Val           _UINT32_(0x1)                                        /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT7_LOW                  (SUPC_WUIR_WKUPT7_LOW_Val << SUPC_WUIR_WKUPT7_Pos)   /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT7_HIGH                 (SUPC_WUIR_WKUPT7_HIGH_Val << SUPC_WUIR_WKUPT7_Pos)  /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT8_Pos                  _UINT32_(24)                                         /* (SUPC_WUIR) Wake-up Input Type 0 to 8 Position */
#define SUPC_WUIR_WKUPT8_Msk                  (_UINT32_(0x1) << SUPC_WUIR_WKUPT8_Pos)              /* (SUPC_WUIR) Wake-up Input Type 0 to 8 Mask */
#define SUPC_WUIR_WKUPT8(value)               (SUPC_WUIR_WKUPT8_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPT8_Pos)) /* Assignment of value for WKUPT8 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPT8_LOW_Val            _UINT32_(0x0)                                        /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT8_HIGH_Val           _UINT32_(0x1)                                        /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT8_LOW                  (SUPC_WUIR_WKUPT8_LOW_Val << SUPC_WUIR_WKUPT8_Pos)   /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT8_HIGH                 (SUPC_WUIR_WKUPT8_HIGH_Val << SUPC_WUIR_WKUPT8_Pos)  /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT9_Pos                  _UINT32_(25)                                         /* (SUPC_WUIR) Wake-up Input Type 0 to 9 Position */
#define SUPC_WUIR_WKUPT9_Msk                  (_UINT32_(0x1) << SUPC_WUIR_WKUPT9_Pos)              /* (SUPC_WUIR) Wake-up Input Type 0 to 9 Mask */
#define SUPC_WUIR_WKUPT9(value)               (SUPC_WUIR_WKUPT9_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPT9_Pos)) /* Assignment of value for WKUPT9 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPT9_LOW_Val            _UINT32_(0x0)                                        /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT9_HIGH_Val           _UINT32_(0x1)                                        /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT9_LOW                  (SUPC_WUIR_WKUPT9_LOW_Val << SUPC_WUIR_WKUPT9_Pos)   /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT9_HIGH                 (SUPC_WUIR_WKUPT9_HIGH_Val << SUPC_WUIR_WKUPT9_Pos)  /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT10_Pos                 _UINT32_(26)                                         /* (SUPC_WUIR) Wake-up Input Type 0 to 10 Position */
#define SUPC_WUIR_WKUPT10_Msk                 (_UINT32_(0x1) << SUPC_WUIR_WKUPT10_Pos)             /* (SUPC_WUIR) Wake-up Input Type 0 to 10 Mask */
#define SUPC_WUIR_WKUPT10(value)              (SUPC_WUIR_WKUPT10_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPT10_Pos)) /* Assignment of value for WKUPT10 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPT10_LOW_Val           _UINT32_(0x0)                                        /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT10_HIGH_Val          _UINT32_(0x1)                                        /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT10_LOW                 (SUPC_WUIR_WKUPT10_LOW_Val << SUPC_WUIR_WKUPT10_Pos) /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT10_HIGH                (SUPC_WUIR_WKUPT10_HIGH_Val << SUPC_WUIR_WKUPT10_Pos) /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT11_Pos                 _UINT32_(27)                                         /* (SUPC_WUIR) Wake-up Input Type 0 to 11 Position */
#define SUPC_WUIR_WKUPT11_Msk                 (_UINT32_(0x1) << SUPC_WUIR_WKUPT11_Pos)             /* (SUPC_WUIR) Wake-up Input Type 0 to 11 Mask */
#define SUPC_WUIR_WKUPT11(value)              (SUPC_WUIR_WKUPT11_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPT11_Pos)) /* Assignment of value for WKUPT11 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPT11_LOW_Val           _UINT32_(0x0)                                        /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT11_HIGH_Val          _UINT32_(0x1)                                        /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT11_LOW                 (SUPC_WUIR_WKUPT11_LOW_Val << SUPC_WUIR_WKUPT11_Pos) /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT11_HIGH                (SUPC_WUIR_WKUPT11_HIGH_Val << SUPC_WUIR_WKUPT11_Pos) /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT12_Pos                 _UINT32_(28)                                         /* (SUPC_WUIR) Wake-up Input Type 0 to 12 Position */
#define SUPC_WUIR_WKUPT12_Msk                 (_UINT32_(0x1) << SUPC_WUIR_WKUPT12_Pos)             /* (SUPC_WUIR) Wake-up Input Type 0 to 12 Mask */
#define SUPC_WUIR_WKUPT12(value)              (SUPC_WUIR_WKUPT12_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPT12_Pos)) /* Assignment of value for WKUPT12 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPT12_LOW_Val           _UINT32_(0x0)                                        /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT12_HIGH_Val          _UINT32_(0x1)                                        /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT12_LOW                 (SUPC_WUIR_WKUPT12_LOW_Val << SUPC_WUIR_WKUPT12_Pos) /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT12_HIGH                (SUPC_WUIR_WKUPT12_HIGH_Val << SUPC_WUIR_WKUPT12_Pos) /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT13_Pos                 _UINT32_(29)                                         /* (SUPC_WUIR) Wake-up Input Type 0 to 13 Position */
#define SUPC_WUIR_WKUPT13_Msk                 (_UINT32_(0x1) << SUPC_WUIR_WKUPT13_Pos)             /* (SUPC_WUIR) Wake-up Input Type 0 to 13 Mask */
#define SUPC_WUIR_WKUPT13(value)              (SUPC_WUIR_WKUPT13_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPT13_Pos)) /* Assignment of value for WKUPT13 in the SUPC_WUIR register */
#define   SUPC_WUIR_WKUPT13_LOW_Val           _UINT32_(0x0)                                        /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT13_HIGH_Val          _UINT32_(0x1)                                        /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT13_LOW                 (SUPC_WUIR_WKUPT13_LOW_Val << SUPC_WUIR_WKUPT13_Pos) /* (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_WKUPT13_HIGH                (SUPC_WUIR_WKUPT13_HIGH_Val << SUPC_WUIR_WKUPT13_Pos) /* (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wake-up input forces the wake-up of the core power supply. Position */
#define SUPC_WUIR_Msk                         _UINT32_(0x3FFF3FFF)                                 /* (SUPC_WUIR) Register Mask  */

#define SUPC_WUIR_WKUPEN_Pos                  _UINT32_(0)                                          /* (SUPC_WUIR Position) Wake-up Input Enable x to x */
#define SUPC_WUIR_WKUPEN_Msk                  (_UINT32_(0x3FFF) << SUPC_WUIR_WKUPEN_Pos)           /* (SUPC_WUIR Mask) WKUPEN */
#define SUPC_WUIR_WKUPEN(value)               (SUPC_WUIR_WKUPEN_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPEN_Pos)) 
#define SUPC_WUIR_WKUPT_Pos                   _UINT32_(16)                                         /* (SUPC_WUIR Position) Wake-up Input Type x to x3 */
#define SUPC_WUIR_WKUPT_Msk                   (_UINT32_(0x3FFF) << SUPC_WUIR_WKUPT_Pos)            /* (SUPC_WUIR Mask) WKUPT */
#define SUPC_WUIR_WKUPT(value)                (SUPC_WUIR_WKUPT_Msk & (_UINT32_(value) << SUPC_WUIR_WKUPT_Pos)) 

/* -------- SUPC_SR : (SUPC Offset: 0x14) ( R/ 32) Supply Controller Status Register -------- */
#define SUPC_SR_WKUPS_Pos                     _UINT32_(1)                                          /* (SUPC_SR) WKUP Wake-up Status (cleared on read) Position */
#define SUPC_SR_WKUPS_Msk                     (_UINT32_(0x1) << SUPC_SR_WKUPS_Pos)                 /* (SUPC_SR) WKUP Wake-up Status (cleared on read) Mask */
#define SUPC_SR_WKUPS(value)                  (SUPC_SR_WKUPS_Msk & (_UINT32_(value) << SUPC_SR_WKUPS_Pos)) /* Assignment of value for WKUPS in the SUPC_SR register */
#define   SUPC_SR_WKUPS_NO_Val                _UINT32_(0x0)                                        /* (SUPC_SR) No wake-up due to the assertion of the WKUP pins has occurred since the last read of SUPC_SR.  */
#define   SUPC_SR_WKUPS_PRESENT_Val           _UINT32_(0x1)                                        /* (SUPC_SR) At least one wake-up due to the assertion of the WKUP pins has occurred since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPS_NO                      (SUPC_SR_WKUPS_NO_Val << SUPC_SR_WKUPS_Pos)          /* (SUPC_SR) No wake-up due to the assertion of the WKUP pins has occurred since the last read of SUPC_SR. Position */
#define SUPC_SR_WKUPS_PRESENT                 (SUPC_SR_WKUPS_PRESENT_Val << SUPC_SR_WKUPS_Pos)     /* (SUPC_SR) At least one wake-up due to the assertion of the WKUP pins has occurred since the last read of SUPC_SR. Position */
#define SUPC_SR_SMWS_Pos                      _UINT32_(2)                                          /* (SUPC_SR) Supply Monitor Detection Wake-up Status (cleared on read) Position */
#define SUPC_SR_SMWS_Msk                      (_UINT32_(0x1) << SUPC_SR_SMWS_Pos)                  /* (SUPC_SR) Supply Monitor Detection Wake-up Status (cleared on read) Mask */
#define SUPC_SR_SMWS(value)                   (SUPC_SR_SMWS_Msk & (_UINT32_(value) << SUPC_SR_SMWS_Pos)) /* Assignment of value for SMWS in the SUPC_SR register */
#define   SUPC_SR_SMWS_NO_Val                 _UINT32_(0x0)                                        /* (SUPC_SR) No wake-up due to a supply monitor detection has occurred since the last read of SUPC_SR.  */
#define   SUPC_SR_SMWS_PRESENT_Val            _UINT32_(0x1)                                        /* (SUPC_SR) At least one wake-up due to a supply monitor detection has occurred since the last read of SUPC_SR.  */
#define SUPC_SR_SMWS_NO                       (SUPC_SR_SMWS_NO_Val << SUPC_SR_SMWS_Pos)            /* (SUPC_SR) No wake-up due to a supply monitor detection has occurred since the last read of SUPC_SR. Position */
#define SUPC_SR_SMWS_PRESENT                  (SUPC_SR_SMWS_PRESENT_Val << SUPC_SR_SMWS_Pos)       /* (SUPC_SR) At least one wake-up due to a supply monitor detection has occurred since the last read of SUPC_SR. Position */
#define SUPC_SR_BODRSTS_Pos                   _UINT32_(3)                                          /* (SUPC_SR) Brownout Detector Reset Status (cleared on read) Position */
#define SUPC_SR_BODRSTS_Msk                   (_UINT32_(0x1) << SUPC_SR_BODRSTS_Pos)               /* (SUPC_SR) Brownout Detector Reset Status (cleared on read) Mask */
#define SUPC_SR_BODRSTS(value)                (SUPC_SR_BODRSTS_Msk & (_UINT32_(value) << SUPC_SR_BODRSTS_Pos)) /* Assignment of value for BODRSTS in the SUPC_SR register */
#define   SUPC_SR_BODRSTS_NO_Val              _UINT32_(0x0)                                        /* (SUPC_SR) No core brownout rising edge event has been detected since the last read of the SUPC_SR.  */
#define   SUPC_SR_BODRSTS_PRESENT_Val         _UINT32_(0x1)                                        /* (SUPC_SR) At least one brownout output rising edge event has been detected since the last read of the SUPC_SR.  */
#define SUPC_SR_BODRSTS_NO                    (SUPC_SR_BODRSTS_NO_Val << SUPC_SR_BODRSTS_Pos)      /* (SUPC_SR) No core brownout rising edge event has been detected since the last read of the SUPC_SR. Position */
#define SUPC_SR_BODRSTS_PRESENT               (SUPC_SR_BODRSTS_PRESENT_Val << SUPC_SR_BODRSTS_Pos) /* (SUPC_SR) At least one brownout output rising edge event has been detected since the last read of the SUPC_SR. Position */
#define SUPC_SR_SMRSTS_Pos                    _UINT32_(4)                                          /* (SUPC_SR) Supply Monitor Reset Status (cleared on read) Position */
#define SUPC_SR_SMRSTS_Msk                    (_UINT32_(0x1) << SUPC_SR_SMRSTS_Pos)                /* (SUPC_SR) Supply Monitor Reset Status (cleared on read) Mask */
#define SUPC_SR_SMRSTS(value)                 (SUPC_SR_SMRSTS_Msk & (_UINT32_(value) << SUPC_SR_SMRSTS_Pos)) /* Assignment of value for SMRSTS in the SUPC_SR register */
#define   SUPC_SR_SMRSTS_NO_Val               _UINT32_(0x0)                                        /* (SUPC_SR) No supply monitor detection has generated a core reset since the last read of the SUPC_SR.  */
#define   SUPC_SR_SMRSTS_PRESENT_Val          _UINT32_(0x1)                                        /* (SUPC_SR) At least one supply monitor detection has generated a core reset since the last read of the SUPC_SR.  */
#define SUPC_SR_SMRSTS_NO                     (SUPC_SR_SMRSTS_NO_Val << SUPC_SR_SMRSTS_Pos)        /* (SUPC_SR) No supply monitor detection has generated a core reset since the last read of the SUPC_SR. Position */
#define SUPC_SR_SMRSTS_PRESENT                (SUPC_SR_SMRSTS_PRESENT_Val << SUPC_SR_SMRSTS_Pos)   /* (SUPC_SR) At least one supply monitor detection has generated a core reset since the last read of the SUPC_SR. Position */
#define SUPC_SR_SMS_Pos                       _UINT32_(5)                                          /* (SUPC_SR) Supply Monitor Status (cleared on read) Position */
#define SUPC_SR_SMS_Msk                       (_UINT32_(0x1) << SUPC_SR_SMS_Pos)                   /* (SUPC_SR) Supply Monitor Status (cleared on read) Mask */
#define SUPC_SR_SMS(value)                    (SUPC_SR_SMS_Msk & (_UINT32_(value) << SUPC_SR_SMS_Pos)) /* Assignment of value for SMS in the SUPC_SR register */
#define   SUPC_SR_SMS_NO_Val                  _UINT32_(0x0)                                        /* (SUPC_SR) No supply monitor detection since the last read of SUPC_SR.  */
#define   SUPC_SR_SMS_PRESENT_Val             _UINT32_(0x1)                                        /* (SUPC_SR) At least one supply monitor detection since the last read of SUPC_SR.  */
#define SUPC_SR_SMS_NO                        (SUPC_SR_SMS_NO_Val << SUPC_SR_SMS_Pos)              /* (SUPC_SR) No supply monitor detection since the last read of SUPC_SR. Position */
#define SUPC_SR_SMS_PRESENT                   (SUPC_SR_SMS_PRESENT_Val << SUPC_SR_SMS_Pos)         /* (SUPC_SR) At least one supply monitor detection since the last read of SUPC_SR. Position */
#define SUPC_SR_SMOS_Pos                      _UINT32_(6)                                          /* (SUPC_SR) Supply Monitor Output Status Position */
#define SUPC_SR_SMOS_Msk                      (_UINT32_(0x1) << SUPC_SR_SMOS_Pos)                  /* (SUPC_SR) Supply Monitor Output Status Mask */
#define SUPC_SR_SMOS(value)                   (SUPC_SR_SMOS_Msk & (_UINT32_(value) << SUPC_SR_SMOS_Pos)) /* Assignment of value for SMOS in the SUPC_SR register */
#define   SUPC_SR_SMOS_HIGH_Val               _UINT32_(0x0)                                        /* (SUPC_SR) The supply monitor detected VDDIO higher than its threshold at its last measurement.  */
#define   SUPC_SR_SMOS_LOW_Val                _UINT32_(0x1)                                        /* (SUPC_SR) The supply monitor detected VDDIO lower than its threshold at its last measurement.  */
#define SUPC_SR_SMOS_HIGH                     (SUPC_SR_SMOS_HIGH_Val << SUPC_SR_SMOS_Pos)          /* (SUPC_SR) The supply monitor detected VDDIO higher than its threshold at its last measurement. Position */
#define SUPC_SR_SMOS_LOW                      (SUPC_SR_SMOS_LOW_Val << SUPC_SR_SMOS_Pos)           /* (SUPC_SR) The supply monitor detected VDDIO lower than its threshold at its last measurement. Position */
#define SUPC_SR_OSCSEL_Pos                    _UINT32_(7)                                          /* (SUPC_SR) 32-kHz Oscillator Selection Status Position */
#define SUPC_SR_OSCSEL_Msk                    (_UINT32_(0x1) << SUPC_SR_OSCSEL_Pos)                /* (SUPC_SR) 32-kHz Oscillator Selection Status Mask */
#define SUPC_SR_OSCSEL(value)                 (SUPC_SR_OSCSEL_Msk & (_UINT32_(value) << SUPC_SR_OSCSEL_Pos)) /* Assignment of value for OSCSEL in the SUPC_SR register */
#define   SUPC_SR_OSCSEL_RC_Val               _UINT32_(0x0)                                        /* (SUPC_SR) The slow clock, SLCK, is generated by the embedded 32 kHz RC oscillator.  */
#define   SUPC_SR_OSCSEL_CRYST_Val            _UINT32_(0x1)                                        /* (SUPC_SR) The slow clock, SLCK, is generated by the 32 kHz crystal oscillator.  */
#define SUPC_SR_OSCSEL_RC                     (SUPC_SR_OSCSEL_RC_Val << SUPC_SR_OSCSEL_Pos)        /* (SUPC_SR) The slow clock, SLCK, is generated by the embedded 32 kHz RC oscillator. Position */
#define SUPC_SR_OSCSEL_CRYST                  (SUPC_SR_OSCSEL_CRYST_Val << SUPC_SR_OSCSEL_Pos)     /* (SUPC_SR) The slow clock, SLCK, is generated by the 32 kHz crystal oscillator. Position */
#define SUPC_SR_LPDBCS0_Pos                   _UINT32_(13)                                         /* (SUPC_SR) Low-power Debouncer Wake-up Status on WKUP0 (cleared on read) Position */
#define SUPC_SR_LPDBCS0_Msk                   (_UINT32_(0x1) << SUPC_SR_LPDBCS0_Pos)               /* (SUPC_SR) Low-power Debouncer Wake-up Status on WKUP0 (cleared on read) Mask */
#define SUPC_SR_LPDBCS0(value)                (SUPC_SR_LPDBCS0_Msk & (_UINT32_(value) << SUPC_SR_LPDBCS0_Pos)) /* Assignment of value for LPDBCS0 in the SUPC_SR register */
#define   SUPC_SR_LPDBCS0_NO_Val              _UINT32_(0x0)                                        /* (SUPC_SR) No wake-up due to the assertion of the WKUP0 pin has occurred since the last read of SUPC_SR.  */
#define   SUPC_SR_LPDBCS0_PRESENT_Val         _UINT32_(0x1)                                        /* (SUPC_SR) At least one wake-up due to the assertion of the WKUP0 pin has occurred since the last read of SUPC_SR.  */
#define SUPC_SR_LPDBCS0_NO                    (SUPC_SR_LPDBCS0_NO_Val << SUPC_SR_LPDBCS0_Pos)      /* (SUPC_SR) No wake-up due to the assertion of the WKUP0 pin has occurred since the last read of SUPC_SR. Position */
#define SUPC_SR_LPDBCS0_PRESENT               (SUPC_SR_LPDBCS0_PRESENT_Val << SUPC_SR_LPDBCS0_Pos) /* (SUPC_SR) At least one wake-up due to the assertion of the WKUP0 pin has occurred since the last read of SUPC_SR. Position */
#define SUPC_SR_LPDBCS1_Pos                   _UINT32_(14)                                         /* (SUPC_SR) Low-power Debouncer Wake-up Status on WKUP1 (cleared on read) Position */
#define SUPC_SR_LPDBCS1_Msk                   (_UINT32_(0x1) << SUPC_SR_LPDBCS1_Pos)               /* (SUPC_SR) Low-power Debouncer Wake-up Status on WKUP1 (cleared on read) Mask */
#define SUPC_SR_LPDBCS1(value)                (SUPC_SR_LPDBCS1_Msk & (_UINT32_(value) << SUPC_SR_LPDBCS1_Pos)) /* Assignment of value for LPDBCS1 in the SUPC_SR register */
#define   SUPC_SR_LPDBCS1_NO_Val              _UINT32_(0x0)                                        /* (SUPC_SR) No wake-up due to the assertion of the WKUP1 pin has occurred since the last read of SUPC_SR.  */
#define   SUPC_SR_LPDBCS1_PRESENT_Val         _UINT32_(0x1)                                        /* (SUPC_SR) At least one wake-up due to the assertion of the WKUP1 pin has occurred since the last read of SUPC_SR.  */
#define SUPC_SR_LPDBCS1_NO                    (SUPC_SR_LPDBCS1_NO_Val << SUPC_SR_LPDBCS1_Pos)      /* (SUPC_SR) No wake-up due to the assertion of the WKUP1 pin has occurred since the last read of SUPC_SR. Position */
#define SUPC_SR_LPDBCS1_PRESENT               (SUPC_SR_LPDBCS1_PRESENT_Val << SUPC_SR_LPDBCS1_Pos) /* (SUPC_SR) At least one wake-up due to the assertion of the WKUP1 pin has occurred since the last read of SUPC_SR. Position */
#define SUPC_SR_WKUPIS0_Pos                   _UINT32_(16)                                         /* (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS0_Msk                   (_UINT32_(0x1) << SUPC_SR_WKUPIS0_Pos)               /* (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define SUPC_SR_WKUPIS0(value)                (SUPC_SR_WKUPIS0_Msk & (_UINT32_(value) << SUPC_SR_WKUPIS0_Pos)) /* Assignment of value for WKUPIS0 in the SUPC_SR register */
#define   SUPC_SR_WKUPIS0_DIS_Val             _UINT32_(0x0)                                        /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS0_EN_Val              _UINT32_(0x1)                                        /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS0_DIS                   (SUPC_SR_WKUPIS0_DIS_Val << SUPC_SR_WKUPIS0_Pos)     /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position */
#define SUPC_SR_WKUPIS0_EN                    (SUPC_SR_WKUPIS0_EN_Val << SUPC_SR_WKUPIS0_Pos)      /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position */
#define SUPC_SR_WKUPIS1_Pos                   _UINT32_(17)                                         /* (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS1_Msk                   (_UINT32_(0x1) << SUPC_SR_WKUPIS1_Pos)               /* (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define SUPC_SR_WKUPIS1(value)                (SUPC_SR_WKUPIS1_Msk & (_UINT32_(value) << SUPC_SR_WKUPIS1_Pos)) /* Assignment of value for WKUPIS1 in the SUPC_SR register */
#define   SUPC_SR_WKUPIS1_DIS_Val             _UINT32_(0x0)                                        /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS1_EN_Val              _UINT32_(0x1)                                        /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS1_DIS                   (SUPC_SR_WKUPIS1_DIS_Val << SUPC_SR_WKUPIS1_Pos)     /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position */
#define SUPC_SR_WKUPIS1_EN                    (SUPC_SR_WKUPIS1_EN_Val << SUPC_SR_WKUPIS1_Pos)      /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position */
#define SUPC_SR_WKUPIS2_Pos                   _UINT32_(18)                                         /* (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS2_Msk                   (_UINT32_(0x1) << SUPC_SR_WKUPIS2_Pos)               /* (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define SUPC_SR_WKUPIS2(value)                (SUPC_SR_WKUPIS2_Msk & (_UINT32_(value) << SUPC_SR_WKUPIS2_Pos)) /* Assignment of value for WKUPIS2 in the SUPC_SR register */
#define   SUPC_SR_WKUPIS2_DIS_Val             _UINT32_(0x0)                                        /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS2_EN_Val              _UINT32_(0x1)                                        /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS2_DIS                   (SUPC_SR_WKUPIS2_DIS_Val << SUPC_SR_WKUPIS2_Pos)     /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position */
#define SUPC_SR_WKUPIS2_EN                    (SUPC_SR_WKUPIS2_EN_Val << SUPC_SR_WKUPIS2_Pos)      /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position */
#define SUPC_SR_WKUPIS3_Pos                   _UINT32_(19)                                         /* (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS3_Msk                   (_UINT32_(0x1) << SUPC_SR_WKUPIS3_Pos)               /* (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define SUPC_SR_WKUPIS3(value)                (SUPC_SR_WKUPIS3_Msk & (_UINT32_(value) << SUPC_SR_WKUPIS3_Pos)) /* Assignment of value for WKUPIS3 in the SUPC_SR register */
#define   SUPC_SR_WKUPIS3_DIS_Val             _UINT32_(0x0)                                        /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS3_EN_Val              _UINT32_(0x1)                                        /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS3_DIS                   (SUPC_SR_WKUPIS3_DIS_Val << SUPC_SR_WKUPIS3_Pos)     /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position */
#define SUPC_SR_WKUPIS3_EN                    (SUPC_SR_WKUPIS3_EN_Val << SUPC_SR_WKUPIS3_Pos)      /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position */
#define SUPC_SR_WKUPIS4_Pos                   _UINT32_(20)                                         /* (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS4_Msk                   (_UINT32_(0x1) << SUPC_SR_WKUPIS4_Pos)               /* (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define SUPC_SR_WKUPIS4(value)                (SUPC_SR_WKUPIS4_Msk & (_UINT32_(value) << SUPC_SR_WKUPIS4_Pos)) /* Assignment of value for WKUPIS4 in the SUPC_SR register */
#define   SUPC_SR_WKUPIS4_DIS_Val             _UINT32_(0x0)                                        /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS4_EN_Val              _UINT32_(0x1)                                        /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS4_DIS                   (SUPC_SR_WKUPIS4_DIS_Val << SUPC_SR_WKUPIS4_Pos)     /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position */
#define SUPC_SR_WKUPIS4_EN                    (SUPC_SR_WKUPIS4_EN_Val << SUPC_SR_WKUPIS4_Pos)      /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position */
#define SUPC_SR_WKUPIS5_Pos                   _UINT32_(21)                                         /* (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS5_Msk                   (_UINT32_(0x1) << SUPC_SR_WKUPIS5_Pos)               /* (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define SUPC_SR_WKUPIS5(value)                (SUPC_SR_WKUPIS5_Msk & (_UINT32_(value) << SUPC_SR_WKUPIS5_Pos)) /* Assignment of value for WKUPIS5 in the SUPC_SR register */
#define   SUPC_SR_WKUPIS5_DIS_Val             _UINT32_(0x0)                                        /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS5_EN_Val              _UINT32_(0x1)                                        /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS5_DIS                   (SUPC_SR_WKUPIS5_DIS_Val << SUPC_SR_WKUPIS5_Pos)     /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position */
#define SUPC_SR_WKUPIS5_EN                    (SUPC_SR_WKUPIS5_EN_Val << SUPC_SR_WKUPIS5_Pos)      /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position */
#define SUPC_SR_WKUPIS6_Pos                   _UINT32_(22)                                         /* (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS6_Msk                   (_UINT32_(0x1) << SUPC_SR_WKUPIS6_Pos)               /* (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define SUPC_SR_WKUPIS6(value)                (SUPC_SR_WKUPIS6_Msk & (_UINT32_(value) << SUPC_SR_WKUPIS6_Pos)) /* Assignment of value for WKUPIS6 in the SUPC_SR register */
#define   SUPC_SR_WKUPIS6_DIS_Val             _UINT32_(0x0)                                        /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS6_EN_Val              _UINT32_(0x1)                                        /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS6_DIS                   (SUPC_SR_WKUPIS6_DIS_Val << SUPC_SR_WKUPIS6_Pos)     /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position */
#define SUPC_SR_WKUPIS6_EN                    (SUPC_SR_WKUPIS6_EN_Val << SUPC_SR_WKUPIS6_Pos)      /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position */
#define SUPC_SR_WKUPIS7_Pos                   _UINT32_(23)                                         /* (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS7_Msk                   (_UINT32_(0x1) << SUPC_SR_WKUPIS7_Pos)               /* (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define SUPC_SR_WKUPIS7(value)                (SUPC_SR_WKUPIS7_Msk & (_UINT32_(value) << SUPC_SR_WKUPIS7_Pos)) /* Assignment of value for WKUPIS7 in the SUPC_SR register */
#define   SUPC_SR_WKUPIS7_DIS_Val             _UINT32_(0x0)                                        /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS7_EN_Val              _UINT32_(0x1)                                        /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS7_DIS                   (SUPC_SR_WKUPIS7_DIS_Val << SUPC_SR_WKUPIS7_Pos)     /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position */
#define SUPC_SR_WKUPIS7_EN                    (SUPC_SR_WKUPIS7_EN_Val << SUPC_SR_WKUPIS7_Pos)      /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position */
#define SUPC_SR_WKUPIS8_Pos                   _UINT32_(24)                                         /* (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS8_Msk                   (_UINT32_(0x1) << SUPC_SR_WKUPIS8_Pos)               /* (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define SUPC_SR_WKUPIS8(value)                (SUPC_SR_WKUPIS8_Msk & (_UINT32_(value) << SUPC_SR_WKUPIS8_Pos)) /* Assignment of value for WKUPIS8 in the SUPC_SR register */
#define   SUPC_SR_WKUPIS8_DIS_Val             _UINT32_(0x0)                                        /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS8_EN_Val              _UINT32_(0x1)                                        /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS8_DIS                   (SUPC_SR_WKUPIS8_DIS_Val << SUPC_SR_WKUPIS8_Pos)     /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position */
#define SUPC_SR_WKUPIS8_EN                    (SUPC_SR_WKUPIS8_EN_Val << SUPC_SR_WKUPIS8_Pos)      /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position */
#define SUPC_SR_WKUPIS9_Pos                   _UINT32_(25)                                         /* (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS9_Msk                   (_UINT32_(0x1) << SUPC_SR_WKUPIS9_Pos)               /* (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define SUPC_SR_WKUPIS9(value)                (SUPC_SR_WKUPIS9_Msk & (_UINT32_(value) << SUPC_SR_WKUPIS9_Pos)) /* Assignment of value for WKUPIS9 in the SUPC_SR register */
#define   SUPC_SR_WKUPIS9_DIS_Val             _UINT32_(0x0)                                        /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS9_EN_Val              _UINT32_(0x1)                                        /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS9_DIS                   (SUPC_SR_WKUPIS9_DIS_Val << SUPC_SR_WKUPIS9_Pos)     /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position */
#define SUPC_SR_WKUPIS9_EN                    (SUPC_SR_WKUPIS9_EN_Val << SUPC_SR_WKUPIS9_Pos)      /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position */
#define SUPC_SR_WKUPIS10_Pos                  _UINT32_(26)                                         /* (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS10_Msk                  (_UINT32_(0x1) << SUPC_SR_WKUPIS10_Pos)              /* (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define SUPC_SR_WKUPIS10(value)               (SUPC_SR_WKUPIS10_Msk & (_UINT32_(value) << SUPC_SR_WKUPIS10_Pos)) /* Assignment of value for WKUPIS10 in the SUPC_SR register */
#define   SUPC_SR_WKUPIS10_DIS_Val            _UINT32_(0x0)                                        /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS10_EN_Val             _UINT32_(0x1)                                        /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS10_DIS                  (SUPC_SR_WKUPIS10_DIS_Val << SUPC_SR_WKUPIS10_Pos)   /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position */
#define SUPC_SR_WKUPIS10_EN                   (SUPC_SR_WKUPIS10_EN_Val << SUPC_SR_WKUPIS10_Pos)    /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position */
#define SUPC_SR_WKUPIS11_Pos                  _UINT32_(27)                                         /* (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS11_Msk                  (_UINT32_(0x1) << SUPC_SR_WKUPIS11_Pos)              /* (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define SUPC_SR_WKUPIS11(value)               (SUPC_SR_WKUPIS11_Msk & (_UINT32_(value) << SUPC_SR_WKUPIS11_Pos)) /* Assignment of value for WKUPIS11 in the SUPC_SR register */
#define   SUPC_SR_WKUPIS11_DIS_Val            _UINT32_(0x0)                                        /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS11_EN_Val             _UINT32_(0x1)                                        /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS11_DIS                  (SUPC_SR_WKUPIS11_DIS_Val << SUPC_SR_WKUPIS11_Pos)   /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position */
#define SUPC_SR_WKUPIS11_EN                   (SUPC_SR_WKUPIS11_EN_Val << SUPC_SR_WKUPIS11_Pos)    /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position */
#define SUPC_SR_WKUPIS12_Pos                  _UINT32_(28)                                         /* (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS12_Msk                  (_UINT32_(0x1) << SUPC_SR_WKUPIS12_Pos)              /* (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define SUPC_SR_WKUPIS12(value)               (SUPC_SR_WKUPIS12_Msk & (_UINT32_(value) << SUPC_SR_WKUPIS12_Pos)) /* Assignment of value for WKUPIS12 in the SUPC_SR register */
#define   SUPC_SR_WKUPIS12_DIS_Val            _UINT32_(0x0)                                        /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS12_EN_Val             _UINT32_(0x1)                                        /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS12_DIS                  (SUPC_SR_WKUPIS12_DIS_Val << SUPC_SR_WKUPIS12_Pos)   /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position */
#define SUPC_SR_WKUPIS12_EN                   (SUPC_SR_WKUPIS12_EN_Val << SUPC_SR_WKUPIS12_Pos)    /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position */
#define SUPC_SR_WKUPIS13_Pos                  _UINT32_(29)                                         /* (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS13_Msk                  (_UINT32_(0x1) << SUPC_SR_WKUPIS13_Pos)              /* (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define SUPC_SR_WKUPIS13(value)               (SUPC_SR_WKUPIS13_Msk & (_UINT32_(value) << SUPC_SR_WKUPIS13_Pos)) /* Assignment of value for WKUPIS13 in the SUPC_SR register */
#define   SUPC_SR_WKUPIS13_DIS_Val            _UINT32_(0x0)                                        /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS13_EN_Val             _UINT32_(0x1)                                        /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS13_DIS                  (SUPC_SR_WKUPIS13_DIS_Val << SUPC_SR_WKUPIS13_Pos)   /* (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position */
#define SUPC_SR_WKUPIS13_EN                   (SUPC_SR_WKUPIS13_EN_Val << SUPC_SR_WKUPIS13_Pos)    /* (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position */
#define SUPC_SR_Msk                           _UINT32_(0x3FFF60FE)                                 /* (SUPC_SR) Register Mask  */

#define SUPC_SR_LPDBCS_Pos                    _UINT32_(13)                                         /* (SUPC_SR Position) Low-power Debouncer Wake-up Status on WKUPx (cleared on read) */
#define SUPC_SR_LPDBCS_Msk                    (_UINT32_(0x3) << SUPC_SR_LPDBCS_Pos)                /* (SUPC_SR Mask) LPDBCS */
#define SUPC_SR_LPDBCS(value)                 (SUPC_SR_LPDBCS_Msk & (_UINT32_(value) << SUPC_SR_LPDBCS_Pos)) 
#define SUPC_SR_WKUPIS_Pos                    _UINT32_(16)                                         /* (SUPC_SR Position) WKUPx Input Status (cleared on read) */
#define SUPC_SR_WKUPIS_Msk                    (_UINT32_(0x3FFF) << SUPC_SR_WKUPIS_Pos)             /* (SUPC_SR Mask) WKUPIS */
#define SUPC_SR_WKUPIS(value)                 (SUPC_SR_WKUPIS_Msk & (_UINT32_(value) << SUPC_SR_WKUPIS_Pos)) 

/* -------- SYSC_WPMR : (SUPC Offset: 0xD4) (R/W 32) Write Protection Mode Register -------- */
#define SYSC_WPMR_WPEN_Pos                    _UINT32_(0)                                          /* (SYSC_WPMR) Write Protection Enable Position */
#define SYSC_WPMR_WPEN_Msk                    (_UINT32_(0x1) << SYSC_WPMR_WPEN_Pos)                /* (SYSC_WPMR) Write Protection Enable Mask */
#define SYSC_WPMR_WPEN(value)                 (SYSC_WPMR_WPEN_Msk & (_UINT32_(value) << SYSC_WPMR_WPEN_Pos)) /* Assignment of value for WPEN in the SYSC_WPMR register */
#define SYSC_WPMR_WPKEY_Pos                   _UINT32_(8)                                          /* (SYSC_WPMR) Write Protection Key Position */
#define SYSC_WPMR_WPKEY_Msk                   (_UINT32_(0xFFFFFF) << SYSC_WPMR_WPKEY_Pos)          /* (SYSC_WPMR) Write Protection Key Mask */
#define SYSC_WPMR_WPKEY(value)                (SYSC_WPMR_WPKEY_Msk & (_UINT32_(value) << SYSC_WPMR_WPKEY_Pos)) /* Assignment of value for WPKEY in the SYSC_WPMR register */
#define   SYSC_WPMR_WPKEY_PASSWD_Val          _UINT32_(0x525443)                                   /* (SYSC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0.  */
#define SYSC_WPMR_WPKEY_PASSWD                (SYSC_WPMR_WPKEY_PASSWD_Val << SYSC_WPMR_WPKEY_Pos)  /* (SYSC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0. Position */
#define SYSC_WPMR_Msk                         _UINT32_(0xFFFFFF01)                                 /* (SYSC_WPMR) Register Mask  */


/* SUPC register offsets definitions */
#define SUPC_CR_REG_OFST               _UINT32_(0x00)      /* (SUPC_CR) Supply Controller Control Register Offset */
#define SUPC_SMMR_REG_OFST             _UINT32_(0x04)      /* (SUPC_SMMR) Supply Controller Supply Monitor Mode Register Offset */
#define SUPC_MR_REG_OFST               _UINT32_(0x08)      /* (SUPC_MR) Supply Controller Mode Register Offset */
#define SUPC_WUMR_REG_OFST             _UINT32_(0x0C)      /* (SUPC_WUMR) Supply Controller Wake-up Mode Register Offset */
#define SUPC_WUIR_REG_OFST             _UINT32_(0x10)      /* (SUPC_WUIR) Supply Controller Wake-up Inputs Register Offset */
#define SUPC_SR_REG_OFST               _UINT32_(0x14)      /* (SUPC_SR) Supply Controller Status Register Offset */
#define SYSC_WPMR_REG_OFST             _UINT32_(0xD4)      /* (SYSC_WPMR) Write Protection Mode Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* SUPC register API structure */
typedef struct
{
  __O   uint32_t                       SUPC_CR;            /* Offset: 0x00 ( /W  32) Supply Controller Control Register */
  __IO  uint32_t                       SUPC_SMMR;          /* Offset: 0x04 (R/W  32) Supply Controller Supply Monitor Mode Register */
  __IO  uint32_t                       SUPC_MR;            /* Offset: 0x08 (R/W  32) Supply Controller Mode Register */
  __IO  uint32_t                       SUPC_WUMR;          /* Offset: 0x0C (R/W  32) Supply Controller Wake-up Mode Register */
  __IO  uint32_t                       SUPC_WUIR;          /* Offset: 0x10 (R/W  32) Supply Controller Wake-up Inputs Register */
  __I   uint32_t                       SUPC_SR;            /* Offset: 0x14 (R/   32) Supply Controller Status Register */
  __I   uint8_t                        Reserved1[0xBC];
  __IO  uint32_t                       SYSC_WPMR;          /* Offset: 0xD4 (R/W  32) Write Protection Mode Register */
} supc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA70_SUPC_COMPONENT_H_ */
