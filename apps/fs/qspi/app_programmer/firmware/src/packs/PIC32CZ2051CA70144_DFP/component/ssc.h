/*
 * Component description for SSC
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
#ifndef _PIC32CZCA70_SSC_COMPONENT_H_
#define _PIC32CZCA70_SSC_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR SSC                       */
/* ************************************************************************** */

/* -------- SSC_CR : (SSC Offset: 0x00) ( /W 32) Control Register -------- */
#define SSC_CR_RXEN_Pos                       _UINT32_(0)                                          /* (SSC_CR) Receive Enable Position */
#define SSC_CR_RXEN_Msk                       (_UINT32_(0x1) << SSC_CR_RXEN_Pos)                   /* (SSC_CR) Receive Enable Mask */
#define SSC_CR_RXEN(value)                    (SSC_CR_RXEN_Msk & (_UINT32_(value) << SSC_CR_RXEN_Pos)) /* Assignment of value for RXEN in the SSC_CR register */
#define SSC_CR_RXDIS_Pos                      _UINT32_(1)                                          /* (SSC_CR) Receive Disable Position */
#define SSC_CR_RXDIS_Msk                      (_UINT32_(0x1) << SSC_CR_RXDIS_Pos)                  /* (SSC_CR) Receive Disable Mask */
#define SSC_CR_RXDIS(value)                   (SSC_CR_RXDIS_Msk & (_UINT32_(value) << SSC_CR_RXDIS_Pos)) /* Assignment of value for RXDIS in the SSC_CR register */
#define SSC_CR_TXEN_Pos                       _UINT32_(8)                                          /* (SSC_CR) Transmit Enable Position */
#define SSC_CR_TXEN_Msk                       (_UINT32_(0x1) << SSC_CR_TXEN_Pos)                   /* (SSC_CR) Transmit Enable Mask */
#define SSC_CR_TXEN(value)                    (SSC_CR_TXEN_Msk & (_UINT32_(value) << SSC_CR_TXEN_Pos)) /* Assignment of value for TXEN in the SSC_CR register */
#define SSC_CR_TXDIS_Pos                      _UINT32_(9)                                          /* (SSC_CR) Transmit Disable Position */
#define SSC_CR_TXDIS_Msk                      (_UINT32_(0x1) << SSC_CR_TXDIS_Pos)                  /* (SSC_CR) Transmit Disable Mask */
#define SSC_CR_TXDIS(value)                   (SSC_CR_TXDIS_Msk & (_UINT32_(value) << SSC_CR_TXDIS_Pos)) /* Assignment of value for TXDIS in the SSC_CR register */
#define SSC_CR_SWRST_Pos                      _UINT32_(15)                                         /* (SSC_CR) Software Reset Position */
#define SSC_CR_SWRST_Msk                      (_UINT32_(0x1) << SSC_CR_SWRST_Pos)                  /* (SSC_CR) Software Reset Mask */
#define SSC_CR_SWRST(value)                   (SSC_CR_SWRST_Msk & (_UINT32_(value) << SSC_CR_SWRST_Pos)) /* Assignment of value for SWRST in the SSC_CR register */
#define SSC_CR_Msk                            _UINT32_(0x00008303)                                 /* (SSC_CR) Register Mask  */


/* -------- SSC_CMR : (SSC Offset: 0x04) (R/W 32) Clock Mode Register -------- */
#define SSC_CMR_DIV_Pos                       _UINT32_(0)                                          /* (SSC_CMR) Clock Divider Position */
#define SSC_CMR_DIV_Msk                       (_UINT32_(0xFFF) << SSC_CMR_DIV_Pos)                 /* (SSC_CMR) Clock Divider Mask */
#define SSC_CMR_DIV(value)                    (SSC_CMR_DIV_Msk & (_UINT32_(value) << SSC_CMR_DIV_Pos)) /* Assignment of value for DIV in the SSC_CMR register */
#define SSC_CMR_Msk                           _UINT32_(0x00000FFF)                                 /* (SSC_CMR) Register Mask  */


/* -------- SSC_RCMR : (SSC Offset: 0x10) (R/W 32) Receive Clock Mode Register -------- */
#define SSC_RCMR_CKS_Pos                      _UINT32_(0)                                          /* (SSC_RCMR) Receive Clock Selection Position */
#define SSC_RCMR_CKS_Msk                      (_UINT32_(0x3) << SSC_RCMR_CKS_Pos)                  /* (SSC_RCMR) Receive Clock Selection Mask */
#define SSC_RCMR_CKS(value)                   (SSC_RCMR_CKS_Msk & (_UINT32_(value) << SSC_RCMR_CKS_Pos)) /* Assignment of value for CKS in the SSC_RCMR register */
#define   SSC_RCMR_CKS_MCK_Val                _UINT32_(0x0)                                        /* (SSC_RCMR) Divided Clock  */
#define   SSC_RCMR_CKS_TK_Val                 _UINT32_(0x1)                                        /* (SSC_RCMR) TK Clock signal  */
#define   SSC_RCMR_CKS_RK_Val                 _UINT32_(0x2)                                        /* (SSC_RCMR) RK pin  */
#define SSC_RCMR_CKS_MCK                      (SSC_RCMR_CKS_MCK_Val << SSC_RCMR_CKS_Pos)           /* (SSC_RCMR) Divided Clock Position */
#define SSC_RCMR_CKS_TK                       (SSC_RCMR_CKS_TK_Val << SSC_RCMR_CKS_Pos)            /* (SSC_RCMR) TK Clock signal Position */
#define SSC_RCMR_CKS_RK                       (SSC_RCMR_CKS_RK_Val << SSC_RCMR_CKS_Pos)            /* (SSC_RCMR) RK pin Position */
#define SSC_RCMR_CKO_Pos                      _UINT32_(2)                                          /* (SSC_RCMR) Receive Clock Output Mode Selection Position */
#define SSC_RCMR_CKO_Msk                      (_UINT32_(0x7) << SSC_RCMR_CKO_Pos)                  /* (SSC_RCMR) Receive Clock Output Mode Selection Mask */
#define SSC_RCMR_CKO(value)                   (SSC_RCMR_CKO_Msk & (_UINT32_(value) << SSC_RCMR_CKO_Pos)) /* Assignment of value for CKO in the SSC_RCMR register */
#define   SSC_RCMR_CKO_NONE_Val               _UINT32_(0x0)                                        /* (SSC_RCMR) None, RK pin is an input  */
#define   SSC_RCMR_CKO_CONTINUOUS_Val         _UINT32_(0x1)                                        /* (SSC_RCMR) Continuous Receive Clock, RK pin is an output  */
#define   SSC_RCMR_CKO_TRANSFER_Val           _UINT32_(0x2)                                        /* (SSC_RCMR) Receive Clock only during data transfers, RK pin is an output  */
#define SSC_RCMR_CKO_NONE                     (SSC_RCMR_CKO_NONE_Val << SSC_RCMR_CKO_Pos)          /* (SSC_RCMR) None, RK pin is an input Position */
#define SSC_RCMR_CKO_CONTINUOUS               (SSC_RCMR_CKO_CONTINUOUS_Val << SSC_RCMR_CKO_Pos)    /* (SSC_RCMR) Continuous Receive Clock, RK pin is an output Position */
#define SSC_RCMR_CKO_TRANSFER                 (SSC_RCMR_CKO_TRANSFER_Val << SSC_RCMR_CKO_Pos)      /* (SSC_RCMR) Receive Clock only during data transfers, RK pin is an output Position */
#define SSC_RCMR_CKI_Pos                      _UINT32_(5)                                          /* (SSC_RCMR) Receive Clock Inversion Position */
#define SSC_RCMR_CKI_Msk                      (_UINT32_(0x1) << SSC_RCMR_CKI_Pos)                  /* (SSC_RCMR) Receive Clock Inversion Mask */
#define SSC_RCMR_CKI(value)                   (SSC_RCMR_CKI_Msk & (_UINT32_(value) << SSC_RCMR_CKI_Pos)) /* Assignment of value for CKI in the SSC_RCMR register */
#define SSC_RCMR_CKG_Pos                      _UINT32_(6)                                          /* (SSC_RCMR) Receive Clock Gating Selection Position */
#define SSC_RCMR_CKG_Msk                      (_UINT32_(0x3) << SSC_RCMR_CKG_Pos)                  /* (SSC_RCMR) Receive Clock Gating Selection Mask */
#define SSC_RCMR_CKG(value)                   (SSC_RCMR_CKG_Msk & (_UINT32_(value) << SSC_RCMR_CKG_Pos)) /* Assignment of value for CKG in the SSC_RCMR register */
#define   SSC_RCMR_CKG_CONTINUOUS_Val         _UINT32_(0x0)                                        /* (SSC_RCMR) None  */
#define   SSC_RCMR_CKG_EN_RF_LOW_Val          _UINT32_(0x1)                                        /* (SSC_RCMR) Receive Clock enabled only if RF Low  */
#define   SSC_RCMR_CKG_EN_RF_HIGH_Val         _UINT32_(0x2)                                        /* (SSC_RCMR) Receive Clock enabled only if RF High  */
#define SSC_RCMR_CKG_CONTINUOUS               (SSC_RCMR_CKG_CONTINUOUS_Val << SSC_RCMR_CKG_Pos)    /* (SSC_RCMR) None Position */
#define SSC_RCMR_CKG_EN_RF_LOW                (SSC_RCMR_CKG_EN_RF_LOW_Val << SSC_RCMR_CKG_Pos)     /* (SSC_RCMR) Receive Clock enabled only if RF Low Position */
#define SSC_RCMR_CKG_EN_RF_HIGH               (SSC_RCMR_CKG_EN_RF_HIGH_Val << SSC_RCMR_CKG_Pos)    /* (SSC_RCMR) Receive Clock enabled only if RF High Position */
#define SSC_RCMR_START_Pos                    _UINT32_(8)                                          /* (SSC_RCMR) Receive Start Selection Position */
#define SSC_RCMR_START_Msk                    (_UINT32_(0xF) << SSC_RCMR_START_Pos)                /* (SSC_RCMR) Receive Start Selection Mask */
#define SSC_RCMR_START(value)                 (SSC_RCMR_START_Msk & (_UINT32_(value) << SSC_RCMR_START_Pos)) /* Assignment of value for START in the SSC_RCMR register */
#define   SSC_RCMR_START_CONTINUOUS_Val       _UINT32_(0x0)                                        /* (SSC_RCMR) Continuous, as soon as the receiver is enabled, and immediately after the end of transfer of the previous data.  */
#define   SSC_RCMR_START_TRANSMIT_Val         _UINT32_(0x1)                                        /* (SSC_RCMR) Transmit start  */
#define   SSC_RCMR_START_RF_LOW_Val           _UINT32_(0x2)                                        /* (SSC_RCMR) Detection of a low level on RF signal  */
#define   SSC_RCMR_START_RF_HIGH_Val          _UINT32_(0x3)                                        /* (SSC_RCMR) Detection of a high level on RF signal  */
#define   SSC_RCMR_START_RF_FALLING_Val       _UINT32_(0x4)                                        /* (SSC_RCMR) Detection of a falling edge on RF signal  */
#define   SSC_RCMR_START_RF_RISING_Val        _UINT32_(0x5)                                        /* (SSC_RCMR) Detection of a rising edge on RF signal  */
#define   SSC_RCMR_START_RF_LEVEL_Val         _UINT32_(0x6)                                        /* (SSC_RCMR) Detection of any level change on RF signal  */
#define   SSC_RCMR_START_RF_EDGE_Val          _UINT32_(0x7)                                        /* (SSC_RCMR) Detection of any edge on RF signal  */
#define   SSC_RCMR_START_CMP_0_Val            _UINT32_(0x8)                                        /* (SSC_RCMR) Compare 0  */
#define SSC_RCMR_START_CONTINUOUS             (SSC_RCMR_START_CONTINUOUS_Val << SSC_RCMR_START_Pos) /* (SSC_RCMR) Continuous, as soon as the receiver is enabled, and immediately after the end of transfer of the previous data. Position */
#define SSC_RCMR_START_TRANSMIT               (SSC_RCMR_START_TRANSMIT_Val << SSC_RCMR_START_Pos)  /* (SSC_RCMR) Transmit start Position */
#define SSC_RCMR_START_RF_LOW                 (SSC_RCMR_START_RF_LOW_Val << SSC_RCMR_START_Pos)    /* (SSC_RCMR) Detection of a low level on RF signal Position */
#define SSC_RCMR_START_RF_HIGH                (SSC_RCMR_START_RF_HIGH_Val << SSC_RCMR_START_Pos)   /* (SSC_RCMR) Detection of a high level on RF signal Position */
#define SSC_RCMR_START_RF_FALLING             (SSC_RCMR_START_RF_FALLING_Val << SSC_RCMR_START_Pos) /* (SSC_RCMR) Detection of a falling edge on RF signal Position */
#define SSC_RCMR_START_RF_RISING              (SSC_RCMR_START_RF_RISING_Val << SSC_RCMR_START_Pos) /* (SSC_RCMR) Detection of a rising edge on RF signal Position */
#define SSC_RCMR_START_RF_LEVEL               (SSC_RCMR_START_RF_LEVEL_Val << SSC_RCMR_START_Pos)  /* (SSC_RCMR) Detection of any level change on RF signal Position */
#define SSC_RCMR_START_RF_EDGE                (SSC_RCMR_START_RF_EDGE_Val << SSC_RCMR_START_Pos)   /* (SSC_RCMR) Detection of any edge on RF signal Position */
#define SSC_RCMR_START_CMP_0                  (SSC_RCMR_START_CMP_0_Val << SSC_RCMR_START_Pos)     /* (SSC_RCMR) Compare 0 Position */
#define SSC_RCMR_STOP_Pos                     _UINT32_(12)                                         /* (SSC_RCMR) Receive Stop Selection Position */
#define SSC_RCMR_STOP_Msk                     (_UINT32_(0x1) << SSC_RCMR_STOP_Pos)                 /* (SSC_RCMR) Receive Stop Selection Mask */
#define SSC_RCMR_STOP(value)                  (SSC_RCMR_STOP_Msk & (_UINT32_(value) << SSC_RCMR_STOP_Pos)) /* Assignment of value for STOP in the SSC_RCMR register */
#define SSC_RCMR_STTDLY_Pos                   _UINT32_(16)                                         /* (SSC_RCMR) Receive Start Delay Position */
#define SSC_RCMR_STTDLY_Msk                   (_UINT32_(0xFF) << SSC_RCMR_STTDLY_Pos)              /* (SSC_RCMR) Receive Start Delay Mask */
#define SSC_RCMR_STTDLY(value)                (SSC_RCMR_STTDLY_Msk & (_UINT32_(value) << SSC_RCMR_STTDLY_Pos)) /* Assignment of value for STTDLY in the SSC_RCMR register */
#define SSC_RCMR_PERIOD_Pos                   _UINT32_(24)                                         /* (SSC_RCMR) Receive Period Divider Selection Position */
#define SSC_RCMR_PERIOD_Msk                   (_UINT32_(0xFF) << SSC_RCMR_PERIOD_Pos)              /* (SSC_RCMR) Receive Period Divider Selection Mask */
#define SSC_RCMR_PERIOD(value)                (SSC_RCMR_PERIOD_Msk & (_UINT32_(value) << SSC_RCMR_PERIOD_Pos)) /* Assignment of value for PERIOD in the SSC_RCMR register */
#define SSC_RCMR_Msk                          _UINT32_(0xFFFF1FFF)                                 /* (SSC_RCMR) Register Mask  */


/* -------- SSC_RFMR : (SSC Offset: 0x14) (R/W 32) Receive Frame Mode Register -------- */
#define SSC_RFMR_DATLEN_Pos                   _UINT32_(0)                                          /* (SSC_RFMR) Data Length Position */
#define SSC_RFMR_DATLEN_Msk                   (_UINT32_(0x1F) << SSC_RFMR_DATLEN_Pos)              /* (SSC_RFMR) Data Length Mask */
#define SSC_RFMR_DATLEN(value)                (SSC_RFMR_DATLEN_Msk & (_UINT32_(value) << SSC_RFMR_DATLEN_Pos)) /* Assignment of value for DATLEN in the SSC_RFMR register */
#define SSC_RFMR_LOOP_Pos                     _UINT32_(5)                                          /* (SSC_RFMR) Loop Mode Position */
#define SSC_RFMR_LOOP_Msk                     (_UINT32_(0x1) << SSC_RFMR_LOOP_Pos)                 /* (SSC_RFMR) Loop Mode Mask */
#define SSC_RFMR_LOOP(value)                  (SSC_RFMR_LOOP_Msk & (_UINT32_(value) << SSC_RFMR_LOOP_Pos)) /* Assignment of value for LOOP in the SSC_RFMR register */
#define SSC_RFMR_MSBF_Pos                     _UINT32_(7)                                          /* (SSC_RFMR) Most Significant Bit First Position */
#define SSC_RFMR_MSBF_Msk                     (_UINT32_(0x1) << SSC_RFMR_MSBF_Pos)                 /* (SSC_RFMR) Most Significant Bit First Mask */
#define SSC_RFMR_MSBF(value)                  (SSC_RFMR_MSBF_Msk & (_UINT32_(value) << SSC_RFMR_MSBF_Pos)) /* Assignment of value for MSBF in the SSC_RFMR register */
#define SSC_RFMR_DATNB_Pos                    _UINT32_(8)                                          /* (SSC_RFMR) Data Number per Frame Position */
#define SSC_RFMR_DATNB_Msk                    (_UINT32_(0xF) << SSC_RFMR_DATNB_Pos)                /* (SSC_RFMR) Data Number per Frame Mask */
#define SSC_RFMR_DATNB(value)                 (SSC_RFMR_DATNB_Msk & (_UINT32_(value) << SSC_RFMR_DATNB_Pos)) /* Assignment of value for DATNB in the SSC_RFMR register */
#define SSC_RFMR_FSLEN_Pos                    _UINT32_(16)                                         /* (SSC_RFMR) Receive Frame Sync Length Position */
#define SSC_RFMR_FSLEN_Msk                    (_UINT32_(0xF) << SSC_RFMR_FSLEN_Pos)                /* (SSC_RFMR) Receive Frame Sync Length Mask */
#define SSC_RFMR_FSLEN(value)                 (SSC_RFMR_FSLEN_Msk & (_UINT32_(value) << SSC_RFMR_FSLEN_Pos)) /* Assignment of value for FSLEN in the SSC_RFMR register */
#define SSC_RFMR_FSOS_Pos                     _UINT32_(20)                                         /* (SSC_RFMR) Receive Frame Sync Output Selection Position */
#define SSC_RFMR_FSOS_Msk                     (_UINT32_(0x7) << SSC_RFMR_FSOS_Pos)                 /* (SSC_RFMR) Receive Frame Sync Output Selection Mask */
#define SSC_RFMR_FSOS(value)                  (SSC_RFMR_FSOS_Msk & (_UINT32_(value) << SSC_RFMR_FSOS_Pos)) /* Assignment of value for FSOS in the SSC_RFMR register */
#define   SSC_RFMR_FSOS_NONE_Val              _UINT32_(0x0)                                        /* (SSC_RFMR) None, RF pin is an input  */
#define   SSC_RFMR_FSOS_NEGATIVE_Val          _UINT32_(0x1)                                        /* (SSC_RFMR) Negative Pulse, RF pin is an output  */
#define   SSC_RFMR_FSOS_POSITIVE_Val          _UINT32_(0x2)                                        /* (SSC_RFMR) Positive Pulse, RF pin is an output  */
#define   SSC_RFMR_FSOS_LOW_Val               _UINT32_(0x3)                                        /* (SSC_RFMR) Driven Low during data transfer, RF pin is an output  */
#define   SSC_RFMR_FSOS_HIGH_Val              _UINT32_(0x4)                                        /* (SSC_RFMR) Driven High during data transfer, RF pin is an output  */
#define   SSC_RFMR_FSOS_TOGGLING_Val          _UINT32_(0x5)                                        /* (SSC_RFMR) Toggling at each start of data transfer, RF pin is an output  */
#define SSC_RFMR_FSOS_NONE                    (SSC_RFMR_FSOS_NONE_Val << SSC_RFMR_FSOS_Pos)        /* (SSC_RFMR) None, RF pin is an input Position */
#define SSC_RFMR_FSOS_NEGATIVE                (SSC_RFMR_FSOS_NEGATIVE_Val << SSC_RFMR_FSOS_Pos)    /* (SSC_RFMR) Negative Pulse, RF pin is an output Position */
#define SSC_RFMR_FSOS_POSITIVE                (SSC_RFMR_FSOS_POSITIVE_Val << SSC_RFMR_FSOS_Pos)    /* (SSC_RFMR) Positive Pulse, RF pin is an output Position */
#define SSC_RFMR_FSOS_LOW                     (SSC_RFMR_FSOS_LOW_Val << SSC_RFMR_FSOS_Pos)         /* (SSC_RFMR) Driven Low during data transfer, RF pin is an output Position */
#define SSC_RFMR_FSOS_HIGH                    (SSC_RFMR_FSOS_HIGH_Val << SSC_RFMR_FSOS_Pos)        /* (SSC_RFMR) Driven High during data transfer, RF pin is an output Position */
#define SSC_RFMR_FSOS_TOGGLING                (SSC_RFMR_FSOS_TOGGLING_Val << SSC_RFMR_FSOS_Pos)    /* (SSC_RFMR) Toggling at each start of data transfer, RF pin is an output Position */
#define SSC_RFMR_FSEDGE_Pos                   _UINT32_(24)                                         /* (SSC_RFMR) Frame Sync Edge Detection Position */
#define SSC_RFMR_FSEDGE_Msk                   (_UINT32_(0x1) << SSC_RFMR_FSEDGE_Pos)               /* (SSC_RFMR) Frame Sync Edge Detection Mask */
#define SSC_RFMR_FSEDGE(value)                (SSC_RFMR_FSEDGE_Msk & (_UINT32_(value) << SSC_RFMR_FSEDGE_Pos)) /* Assignment of value for FSEDGE in the SSC_RFMR register */
#define   SSC_RFMR_FSEDGE_POSITIVE_Val        _UINT32_(0x0)                                        /* (SSC_RFMR) Positive Edge Detection  */
#define   SSC_RFMR_FSEDGE_NEGATIVE_Val        _UINT32_(0x1)                                        /* (SSC_RFMR) Negative Edge Detection  */
#define SSC_RFMR_FSEDGE_POSITIVE              (SSC_RFMR_FSEDGE_POSITIVE_Val << SSC_RFMR_FSEDGE_Pos) /* (SSC_RFMR) Positive Edge Detection Position */
#define SSC_RFMR_FSEDGE_NEGATIVE              (SSC_RFMR_FSEDGE_NEGATIVE_Val << SSC_RFMR_FSEDGE_Pos) /* (SSC_RFMR) Negative Edge Detection Position */
#define SSC_RFMR_FSLEN_EXT_Pos                _UINT32_(28)                                         /* (SSC_RFMR) FSLEN Field Extension Position */
#define SSC_RFMR_FSLEN_EXT_Msk                (_UINT32_(0xF) << SSC_RFMR_FSLEN_EXT_Pos)            /* (SSC_RFMR) FSLEN Field Extension Mask */
#define SSC_RFMR_FSLEN_EXT(value)             (SSC_RFMR_FSLEN_EXT_Msk & (_UINT32_(value) << SSC_RFMR_FSLEN_EXT_Pos)) /* Assignment of value for FSLEN_EXT in the SSC_RFMR register */
#define SSC_RFMR_Msk                          _UINT32_(0xF17F0FBF)                                 /* (SSC_RFMR) Register Mask  */


/* -------- SSC_TCMR : (SSC Offset: 0x18) (R/W 32) Transmit Clock Mode Register -------- */
#define SSC_TCMR_CKS_Pos                      _UINT32_(0)                                          /* (SSC_TCMR) Transmit Clock Selection Position */
#define SSC_TCMR_CKS_Msk                      (_UINT32_(0x3) << SSC_TCMR_CKS_Pos)                  /* (SSC_TCMR) Transmit Clock Selection Mask */
#define SSC_TCMR_CKS(value)                   (SSC_TCMR_CKS_Msk & (_UINT32_(value) << SSC_TCMR_CKS_Pos)) /* Assignment of value for CKS in the SSC_TCMR register */
#define   SSC_TCMR_CKS_MCK_Val                _UINT32_(0x0)                                        /* (SSC_TCMR) Divided Clock  */
#define   SSC_TCMR_CKS_RK_Val                 _UINT32_(0x1)                                        /* (SSC_TCMR) RK Clock signal  */
#define   SSC_TCMR_CKS_TK_Val                 _UINT32_(0x2)                                        /* (SSC_TCMR) TK pin  */
#define SSC_TCMR_CKS_MCK                      (SSC_TCMR_CKS_MCK_Val << SSC_TCMR_CKS_Pos)           /* (SSC_TCMR) Divided Clock Position */
#define SSC_TCMR_CKS_RK                       (SSC_TCMR_CKS_RK_Val << SSC_TCMR_CKS_Pos)            /* (SSC_TCMR) RK Clock signal Position */
#define SSC_TCMR_CKS_TK                       (SSC_TCMR_CKS_TK_Val << SSC_TCMR_CKS_Pos)            /* (SSC_TCMR) TK pin Position */
#define SSC_TCMR_CKO_Pos                      _UINT32_(2)                                          /* (SSC_TCMR) Transmit Clock Output Mode Selection Position */
#define SSC_TCMR_CKO_Msk                      (_UINT32_(0x7) << SSC_TCMR_CKO_Pos)                  /* (SSC_TCMR) Transmit Clock Output Mode Selection Mask */
#define SSC_TCMR_CKO(value)                   (SSC_TCMR_CKO_Msk & (_UINT32_(value) << SSC_TCMR_CKO_Pos)) /* Assignment of value for CKO in the SSC_TCMR register */
#define   SSC_TCMR_CKO_NONE_Val               _UINT32_(0x0)                                        /* (SSC_TCMR) None, TK pin is an input  */
#define   SSC_TCMR_CKO_CONTINUOUS_Val         _UINT32_(0x1)                                        /* (SSC_TCMR) Continuous Transmit Clock, TK pin is an output  */
#define   SSC_TCMR_CKO_TRANSFER_Val           _UINT32_(0x2)                                        /* (SSC_TCMR) Transmit Clock only during data transfers, TK pin is an output  */
#define SSC_TCMR_CKO_NONE                     (SSC_TCMR_CKO_NONE_Val << SSC_TCMR_CKO_Pos)          /* (SSC_TCMR) None, TK pin is an input Position */
#define SSC_TCMR_CKO_CONTINUOUS               (SSC_TCMR_CKO_CONTINUOUS_Val << SSC_TCMR_CKO_Pos)    /* (SSC_TCMR) Continuous Transmit Clock, TK pin is an output Position */
#define SSC_TCMR_CKO_TRANSFER                 (SSC_TCMR_CKO_TRANSFER_Val << SSC_TCMR_CKO_Pos)      /* (SSC_TCMR) Transmit Clock only during data transfers, TK pin is an output Position */
#define SSC_TCMR_CKI_Pos                      _UINT32_(5)                                          /* (SSC_TCMR) Transmit Clock Inversion Position */
#define SSC_TCMR_CKI_Msk                      (_UINT32_(0x1) << SSC_TCMR_CKI_Pos)                  /* (SSC_TCMR) Transmit Clock Inversion Mask */
#define SSC_TCMR_CKI(value)                   (SSC_TCMR_CKI_Msk & (_UINT32_(value) << SSC_TCMR_CKI_Pos)) /* Assignment of value for CKI in the SSC_TCMR register */
#define SSC_TCMR_CKG_Pos                      _UINT32_(6)                                          /* (SSC_TCMR) Transmit Clock Gating Selection Position */
#define SSC_TCMR_CKG_Msk                      (_UINT32_(0x3) << SSC_TCMR_CKG_Pos)                  /* (SSC_TCMR) Transmit Clock Gating Selection Mask */
#define SSC_TCMR_CKG(value)                   (SSC_TCMR_CKG_Msk & (_UINT32_(value) << SSC_TCMR_CKG_Pos)) /* Assignment of value for CKG in the SSC_TCMR register */
#define   SSC_TCMR_CKG_CONTINUOUS_Val         _UINT32_(0x0)                                        /* (SSC_TCMR) None  */
#define   SSC_TCMR_CKG_EN_TF_LOW_Val          _UINT32_(0x1)                                        /* (SSC_TCMR) Transmit Clock enabled only if TF Low  */
#define   SSC_TCMR_CKG_EN_TF_HIGH_Val         _UINT32_(0x2)                                        /* (SSC_TCMR) Transmit Clock enabled only if TF High  */
#define SSC_TCMR_CKG_CONTINUOUS               (SSC_TCMR_CKG_CONTINUOUS_Val << SSC_TCMR_CKG_Pos)    /* (SSC_TCMR) None Position */
#define SSC_TCMR_CKG_EN_TF_LOW                (SSC_TCMR_CKG_EN_TF_LOW_Val << SSC_TCMR_CKG_Pos)     /* (SSC_TCMR) Transmit Clock enabled only if TF Low Position */
#define SSC_TCMR_CKG_EN_TF_HIGH               (SSC_TCMR_CKG_EN_TF_HIGH_Val << SSC_TCMR_CKG_Pos)    /* (SSC_TCMR) Transmit Clock enabled only if TF High Position */
#define SSC_TCMR_START_Pos                    _UINT32_(8)                                          /* (SSC_TCMR) Transmit Start Selection Position */
#define SSC_TCMR_START_Msk                    (_UINT32_(0xF) << SSC_TCMR_START_Pos)                /* (SSC_TCMR) Transmit Start Selection Mask */
#define SSC_TCMR_START(value)                 (SSC_TCMR_START_Msk & (_UINT32_(value) << SSC_TCMR_START_Pos)) /* Assignment of value for START in the SSC_TCMR register */
#define   SSC_TCMR_START_CONTINUOUS_Val       _UINT32_(0x0)                                        /* (SSC_TCMR) Continuous, as soon as a word is written in the SSC_THR (if Transmit is enabled), and immediately after the end of transfer of the previous data  */
#define   SSC_TCMR_START_RECEIVE_Val          _UINT32_(0x1)                                        /* (SSC_TCMR) Receive start  */
#define   SSC_TCMR_START_TF_LOW_Val           _UINT32_(0x2)                                        /* (SSC_TCMR) Detection of a low level on TF signal  */
#define   SSC_TCMR_START_TF_HIGH_Val          _UINT32_(0x3)                                        /* (SSC_TCMR) Detection of a high level on TF signal  */
#define   SSC_TCMR_START_TF_FALLING_Val       _UINT32_(0x4)                                        /* (SSC_TCMR) Detection of a falling edge on TF signal  */
#define   SSC_TCMR_START_TF_RISING_Val        _UINT32_(0x5)                                        /* (SSC_TCMR) Detection of a rising edge on TF signal  */
#define   SSC_TCMR_START_TF_LEVEL_Val         _UINT32_(0x6)                                        /* (SSC_TCMR) Detection of any level change on TF signal  */
#define   SSC_TCMR_START_TF_EDGE_Val          _UINT32_(0x7)                                        /* (SSC_TCMR) Detection of any edge on TF signal  */
#define SSC_TCMR_START_CONTINUOUS             (SSC_TCMR_START_CONTINUOUS_Val << SSC_TCMR_START_Pos) /* (SSC_TCMR) Continuous, as soon as a word is written in the SSC_THR (if Transmit is enabled), and immediately after the end of transfer of the previous data Position */
#define SSC_TCMR_START_RECEIVE                (SSC_TCMR_START_RECEIVE_Val << SSC_TCMR_START_Pos)   /* (SSC_TCMR) Receive start Position */
#define SSC_TCMR_START_TF_LOW                 (SSC_TCMR_START_TF_LOW_Val << SSC_TCMR_START_Pos)    /* (SSC_TCMR) Detection of a low level on TF signal Position */
#define SSC_TCMR_START_TF_HIGH                (SSC_TCMR_START_TF_HIGH_Val << SSC_TCMR_START_Pos)   /* (SSC_TCMR) Detection of a high level on TF signal Position */
#define SSC_TCMR_START_TF_FALLING             (SSC_TCMR_START_TF_FALLING_Val << SSC_TCMR_START_Pos) /* (SSC_TCMR) Detection of a falling edge on TF signal Position */
#define SSC_TCMR_START_TF_RISING              (SSC_TCMR_START_TF_RISING_Val << SSC_TCMR_START_Pos) /* (SSC_TCMR) Detection of a rising edge on TF signal Position */
#define SSC_TCMR_START_TF_LEVEL               (SSC_TCMR_START_TF_LEVEL_Val << SSC_TCMR_START_Pos)  /* (SSC_TCMR) Detection of any level change on TF signal Position */
#define SSC_TCMR_START_TF_EDGE                (SSC_TCMR_START_TF_EDGE_Val << SSC_TCMR_START_Pos)   /* (SSC_TCMR) Detection of any edge on TF signal Position */
#define SSC_TCMR_STTDLY_Pos                   _UINT32_(16)                                         /* (SSC_TCMR) Transmit Start Delay Position */
#define SSC_TCMR_STTDLY_Msk                   (_UINT32_(0xFF) << SSC_TCMR_STTDLY_Pos)              /* (SSC_TCMR) Transmit Start Delay Mask */
#define SSC_TCMR_STTDLY(value)                (SSC_TCMR_STTDLY_Msk & (_UINT32_(value) << SSC_TCMR_STTDLY_Pos)) /* Assignment of value for STTDLY in the SSC_TCMR register */
#define SSC_TCMR_PERIOD_Pos                   _UINT32_(24)                                         /* (SSC_TCMR) Transmit Period Divider Selection Position */
#define SSC_TCMR_PERIOD_Msk                   (_UINT32_(0xFF) << SSC_TCMR_PERIOD_Pos)              /* (SSC_TCMR) Transmit Period Divider Selection Mask */
#define SSC_TCMR_PERIOD(value)                (SSC_TCMR_PERIOD_Msk & (_UINT32_(value) << SSC_TCMR_PERIOD_Pos)) /* Assignment of value for PERIOD in the SSC_TCMR register */
#define SSC_TCMR_Msk                          _UINT32_(0xFFFF0FFF)                                 /* (SSC_TCMR) Register Mask  */


/* -------- SSC_TFMR : (SSC Offset: 0x1C) (R/W 32) Transmit Frame Mode Register -------- */
#define SSC_TFMR_DATLEN_Pos                   _UINT32_(0)                                          /* (SSC_TFMR) Data Length Position */
#define SSC_TFMR_DATLEN_Msk                   (_UINT32_(0x1F) << SSC_TFMR_DATLEN_Pos)              /* (SSC_TFMR) Data Length Mask */
#define SSC_TFMR_DATLEN(value)                (SSC_TFMR_DATLEN_Msk & (_UINT32_(value) << SSC_TFMR_DATLEN_Pos)) /* Assignment of value for DATLEN in the SSC_TFMR register */
#define SSC_TFMR_DATDEF_Pos                   _UINT32_(5)                                          /* (SSC_TFMR) Data Default Value Position */
#define SSC_TFMR_DATDEF_Msk                   (_UINT32_(0x1) << SSC_TFMR_DATDEF_Pos)               /* (SSC_TFMR) Data Default Value Mask */
#define SSC_TFMR_DATDEF(value)                (SSC_TFMR_DATDEF_Msk & (_UINT32_(value) << SSC_TFMR_DATDEF_Pos)) /* Assignment of value for DATDEF in the SSC_TFMR register */
#define SSC_TFMR_MSBF_Pos                     _UINT32_(7)                                          /* (SSC_TFMR) Most Significant Bit First Position */
#define SSC_TFMR_MSBF_Msk                     (_UINT32_(0x1) << SSC_TFMR_MSBF_Pos)                 /* (SSC_TFMR) Most Significant Bit First Mask */
#define SSC_TFMR_MSBF(value)                  (SSC_TFMR_MSBF_Msk & (_UINT32_(value) << SSC_TFMR_MSBF_Pos)) /* Assignment of value for MSBF in the SSC_TFMR register */
#define SSC_TFMR_DATNB_Pos                    _UINT32_(8)                                          /* (SSC_TFMR) Data Number per Frame Position */
#define SSC_TFMR_DATNB_Msk                    (_UINT32_(0xF) << SSC_TFMR_DATNB_Pos)                /* (SSC_TFMR) Data Number per Frame Mask */
#define SSC_TFMR_DATNB(value)                 (SSC_TFMR_DATNB_Msk & (_UINT32_(value) << SSC_TFMR_DATNB_Pos)) /* Assignment of value for DATNB in the SSC_TFMR register */
#define SSC_TFMR_FSLEN_Pos                    _UINT32_(16)                                         /* (SSC_TFMR) Transmit Frame Sync Length Position */
#define SSC_TFMR_FSLEN_Msk                    (_UINT32_(0xF) << SSC_TFMR_FSLEN_Pos)                /* (SSC_TFMR) Transmit Frame Sync Length Mask */
#define SSC_TFMR_FSLEN(value)                 (SSC_TFMR_FSLEN_Msk & (_UINT32_(value) << SSC_TFMR_FSLEN_Pos)) /* Assignment of value for FSLEN in the SSC_TFMR register */
#define SSC_TFMR_FSOS_Pos                     _UINT32_(20)                                         /* (SSC_TFMR) Transmit Frame Sync Output Selection Position */
#define SSC_TFMR_FSOS_Msk                     (_UINT32_(0x7) << SSC_TFMR_FSOS_Pos)                 /* (SSC_TFMR) Transmit Frame Sync Output Selection Mask */
#define SSC_TFMR_FSOS(value)                  (SSC_TFMR_FSOS_Msk & (_UINT32_(value) << SSC_TFMR_FSOS_Pos)) /* Assignment of value for FSOS in the SSC_TFMR register */
#define   SSC_TFMR_FSOS_NONE_Val              _UINT32_(0x0)                                        /* (SSC_TFMR) None, TF pin is an input  */
#define   SSC_TFMR_FSOS_NEGATIVE_Val          _UINT32_(0x1)                                        /* (SSC_TFMR) Negative Pulse, TF pin is an output  */
#define   SSC_TFMR_FSOS_POSITIVE_Val          _UINT32_(0x2)                                        /* (SSC_TFMR) Positive Pulse, TF pin is an output  */
#define   SSC_TFMR_FSOS_LOW_Val               _UINT32_(0x3)                                        /* (SSC_TFMR) Driven Low during data transfer  */
#define   SSC_TFMR_FSOS_HIGH_Val              _UINT32_(0x4)                                        /* (SSC_TFMR) Driven High during data transfer  */
#define   SSC_TFMR_FSOS_TOGGLING_Val          _UINT32_(0x5)                                        /* (SSC_TFMR) Toggling at each start of data transfer  */
#define SSC_TFMR_FSOS_NONE                    (SSC_TFMR_FSOS_NONE_Val << SSC_TFMR_FSOS_Pos)        /* (SSC_TFMR) None, TF pin is an input Position */
#define SSC_TFMR_FSOS_NEGATIVE                (SSC_TFMR_FSOS_NEGATIVE_Val << SSC_TFMR_FSOS_Pos)    /* (SSC_TFMR) Negative Pulse, TF pin is an output Position */
#define SSC_TFMR_FSOS_POSITIVE                (SSC_TFMR_FSOS_POSITIVE_Val << SSC_TFMR_FSOS_Pos)    /* (SSC_TFMR) Positive Pulse, TF pin is an output Position */
#define SSC_TFMR_FSOS_LOW                     (SSC_TFMR_FSOS_LOW_Val << SSC_TFMR_FSOS_Pos)         /* (SSC_TFMR) Driven Low during data transfer Position */
#define SSC_TFMR_FSOS_HIGH                    (SSC_TFMR_FSOS_HIGH_Val << SSC_TFMR_FSOS_Pos)        /* (SSC_TFMR) Driven High during data transfer Position */
#define SSC_TFMR_FSOS_TOGGLING                (SSC_TFMR_FSOS_TOGGLING_Val << SSC_TFMR_FSOS_Pos)    /* (SSC_TFMR) Toggling at each start of data transfer Position */
#define SSC_TFMR_FSDEN_Pos                    _UINT32_(23)                                         /* (SSC_TFMR) Frame Sync Data Enable Position */
#define SSC_TFMR_FSDEN_Msk                    (_UINT32_(0x1) << SSC_TFMR_FSDEN_Pos)                /* (SSC_TFMR) Frame Sync Data Enable Mask */
#define SSC_TFMR_FSDEN(value)                 (SSC_TFMR_FSDEN_Msk & (_UINT32_(value) << SSC_TFMR_FSDEN_Pos)) /* Assignment of value for FSDEN in the SSC_TFMR register */
#define SSC_TFMR_FSEDGE_Pos                   _UINT32_(24)                                         /* (SSC_TFMR) Frame Sync Edge Detection Position */
#define SSC_TFMR_FSEDGE_Msk                   (_UINT32_(0x1) << SSC_TFMR_FSEDGE_Pos)               /* (SSC_TFMR) Frame Sync Edge Detection Mask */
#define SSC_TFMR_FSEDGE(value)                (SSC_TFMR_FSEDGE_Msk & (_UINT32_(value) << SSC_TFMR_FSEDGE_Pos)) /* Assignment of value for FSEDGE in the SSC_TFMR register */
#define   SSC_TFMR_FSEDGE_POSITIVE_Val        _UINT32_(0x0)                                        /* (SSC_TFMR) Positive Edge Detection  */
#define   SSC_TFMR_FSEDGE_NEGATIVE_Val        _UINT32_(0x1)                                        /* (SSC_TFMR) Negative Edge Detection  */
#define SSC_TFMR_FSEDGE_POSITIVE              (SSC_TFMR_FSEDGE_POSITIVE_Val << SSC_TFMR_FSEDGE_Pos) /* (SSC_TFMR) Positive Edge Detection Position */
#define SSC_TFMR_FSEDGE_NEGATIVE              (SSC_TFMR_FSEDGE_NEGATIVE_Val << SSC_TFMR_FSEDGE_Pos) /* (SSC_TFMR) Negative Edge Detection Position */
#define SSC_TFMR_FSLEN_EXT_Pos                _UINT32_(28)                                         /* (SSC_TFMR) FSLEN Field Extension Position */
#define SSC_TFMR_FSLEN_EXT_Msk                (_UINT32_(0xF) << SSC_TFMR_FSLEN_EXT_Pos)            /* (SSC_TFMR) FSLEN Field Extension Mask */
#define SSC_TFMR_FSLEN_EXT(value)             (SSC_TFMR_FSLEN_EXT_Msk & (_UINT32_(value) << SSC_TFMR_FSLEN_EXT_Pos)) /* Assignment of value for FSLEN_EXT in the SSC_TFMR register */
#define SSC_TFMR_Msk                          _UINT32_(0xF1FF0FBF)                                 /* (SSC_TFMR) Register Mask  */


/* -------- SSC_RHR : (SSC Offset: 0x20) ( R/ 32) Receive Holding Register -------- */
#define SSC_RHR_RDAT_Pos                      _UINT32_(0)                                          /* (SSC_RHR) Receive Data Position */
#define SSC_RHR_RDAT_Msk                      (_UINT32_(0xFFFFFFFF) << SSC_RHR_RDAT_Pos)           /* (SSC_RHR) Receive Data Mask */
#define SSC_RHR_RDAT(value)                   (SSC_RHR_RDAT_Msk & (_UINT32_(value) << SSC_RHR_RDAT_Pos)) /* Assignment of value for RDAT in the SSC_RHR register */
#define SSC_RHR_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (SSC_RHR) Register Mask  */


/* -------- SSC_THR : (SSC Offset: 0x24) ( /W 32) Transmit Holding Register -------- */
#define SSC_THR_TDAT_Pos                      _UINT32_(0)                                          /* (SSC_THR) Transmit Data Position */
#define SSC_THR_TDAT_Msk                      (_UINT32_(0xFFFFFFFF) << SSC_THR_TDAT_Pos)           /* (SSC_THR) Transmit Data Mask */
#define SSC_THR_TDAT(value)                   (SSC_THR_TDAT_Msk & (_UINT32_(value) << SSC_THR_TDAT_Pos)) /* Assignment of value for TDAT in the SSC_THR register */
#define SSC_THR_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (SSC_THR) Register Mask  */


/* -------- SSC_RSHR : (SSC Offset: 0x30) ( R/ 32) Receive Sync. Holding Register -------- */
#define SSC_RSHR_RSDAT_Pos                    _UINT32_(0)                                          /* (SSC_RSHR) Receive Synchronization Data Position */
#define SSC_RSHR_RSDAT_Msk                    (_UINT32_(0xFFFF) << SSC_RSHR_RSDAT_Pos)             /* (SSC_RSHR) Receive Synchronization Data Mask */
#define SSC_RSHR_RSDAT(value)                 (SSC_RSHR_RSDAT_Msk & (_UINT32_(value) << SSC_RSHR_RSDAT_Pos)) /* Assignment of value for RSDAT in the SSC_RSHR register */
#define SSC_RSHR_Msk                          _UINT32_(0x0000FFFF)                                 /* (SSC_RSHR) Register Mask  */


/* -------- SSC_TSHR : (SSC Offset: 0x34) (R/W 32) Transmit Sync. Holding Register -------- */
#define SSC_TSHR_TSDAT_Pos                    _UINT32_(0)                                          /* (SSC_TSHR) Transmit Synchronization Data Position */
#define SSC_TSHR_TSDAT_Msk                    (_UINT32_(0xFFFF) << SSC_TSHR_TSDAT_Pos)             /* (SSC_TSHR) Transmit Synchronization Data Mask */
#define SSC_TSHR_TSDAT(value)                 (SSC_TSHR_TSDAT_Msk & (_UINT32_(value) << SSC_TSHR_TSDAT_Pos)) /* Assignment of value for TSDAT in the SSC_TSHR register */
#define SSC_TSHR_Msk                          _UINT32_(0x0000FFFF)                                 /* (SSC_TSHR) Register Mask  */


/* -------- SSC_RC0R : (SSC Offset: 0x38) (R/W 32) Receive Compare 0 Register -------- */
#define SSC_RC0R_CP0_Pos                      _UINT32_(0)                                          /* (SSC_RC0R) Receive Compare Data 0 Position */
#define SSC_RC0R_CP0_Msk                      (_UINT32_(0xFFFF) << SSC_RC0R_CP0_Pos)               /* (SSC_RC0R) Receive Compare Data 0 Mask */
#define SSC_RC0R_CP0(value)                   (SSC_RC0R_CP0_Msk & (_UINT32_(value) << SSC_RC0R_CP0_Pos)) /* Assignment of value for CP0 in the SSC_RC0R register */
#define SSC_RC0R_Msk                          _UINT32_(0x0000FFFF)                                 /* (SSC_RC0R) Register Mask  */


/* -------- SSC_RC1R : (SSC Offset: 0x3C) (R/W 32) Receive Compare 1 Register -------- */
#define SSC_RC1R_CP1_Pos                      _UINT32_(0)                                          /* (SSC_RC1R) Receive Compare Data 1 Position */
#define SSC_RC1R_CP1_Msk                      (_UINT32_(0xFFFF) << SSC_RC1R_CP1_Pos)               /* (SSC_RC1R) Receive Compare Data 1 Mask */
#define SSC_RC1R_CP1(value)                   (SSC_RC1R_CP1_Msk & (_UINT32_(value) << SSC_RC1R_CP1_Pos)) /* Assignment of value for CP1 in the SSC_RC1R register */
#define SSC_RC1R_Msk                          _UINT32_(0x0000FFFF)                                 /* (SSC_RC1R) Register Mask  */


/* -------- SSC_SR : (SSC Offset: 0x40) ( R/ 32) Status Register -------- */
#define SSC_SR_TXRDY_Pos                      _UINT32_(0)                                          /* (SSC_SR) Transmit Ready Position */
#define SSC_SR_TXRDY_Msk                      (_UINT32_(0x1) << SSC_SR_TXRDY_Pos)                  /* (SSC_SR) Transmit Ready Mask */
#define SSC_SR_TXRDY(value)                   (SSC_SR_TXRDY_Msk & (_UINT32_(value) << SSC_SR_TXRDY_Pos)) /* Assignment of value for TXRDY in the SSC_SR register */
#define SSC_SR_TXEMPTY_Pos                    _UINT32_(1)                                          /* (SSC_SR) Transmit Empty Position */
#define SSC_SR_TXEMPTY_Msk                    (_UINT32_(0x1) << SSC_SR_TXEMPTY_Pos)                /* (SSC_SR) Transmit Empty Mask */
#define SSC_SR_TXEMPTY(value)                 (SSC_SR_TXEMPTY_Msk & (_UINT32_(value) << SSC_SR_TXEMPTY_Pos)) /* Assignment of value for TXEMPTY in the SSC_SR register */
#define SSC_SR_RXRDY_Pos                      _UINT32_(4)                                          /* (SSC_SR) Receive Ready Position */
#define SSC_SR_RXRDY_Msk                      (_UINT32_(0x1) << SSC_SR_RXRDY_Pos)                  /* (SSC_SR) Receive Ready Mask */
#define SSC_SR_RXRDY(value)                   (SSC_SR_RXRDY_Msk & (_UINT32_(value) << SSC_SR_RXRDY_Pos)) /* Assignment of value for RXRDY in the SSC_SR register */
#define SSC_SR_OVRUN_Pos                      _UINT32_(5)                                          /* (SSC_SR) Receive Overrun Position */
#define SSC_SR_OVRUN_Msk                      (_UINT32_(0x1) << SSC_SR_OVRUN_Pos)                  /* (SSC_SR) Receive Overrun Mask */
#define SSC_SR_OVRUN(value)                   (SSC_SR_OVRUN_Msk & (_UINT32_(value) << SSC_SR_OVRUN_Pos)) /* Assignment of value for OVRUN in the SSC_SR register */
#define SSC_SR_CP0_Pos                        _UINT32_(8)                                          /* (SSC_SR) Compare 0 Position */
#define SSC_SR_CP0_Msk                        (_UINT32_(0x1) << SSC_SR_CP0_Pos)                    /* (SSC_SR) Compare 0 Mask */
#define SSC_SR_CP0(value)                     (SSC_SR_CP0_Msk & (_UINT32_(value) << SSC_SR_CP0_Pos)) /* Assignment of value for CP0 in the SSC_SR register */
#define SSC_SR_CP1_Pos                        _UINT32_(9)                                          /* (SSC_SR) Compare 1 Position */
#define SSC_SR_CP1_Msk                        (_UINT32_(0x1) << SSC_SR_CP1_Pos)                    /* (SSC_SR) Compare 1 Mask */
#define SSC_SR_CP1(value)                     (SSC_SR_CP1_Msk & (_UINT32_(value) << SSC_SR_CP1_Pos)) /* Assignment of value for CP1 in the SSC_SR register */
#define SSC_SR_TXSYN_Pos                      _UINT32_(10)                                         /* (SSC_SR) Transmit Sync Position */
#define SSC_SR_TXSYN_Msk                      (_UINT32_(0x1) << SSC_SR_TXSYN_Pos)                  /* (SSC_SR) Transmit Sync Mask */
#define SSC_SR_TXSYN(value)                   (SSC_SR_TXSYN_Msk & (_UINT32_(value) << SSC_SR_TXSYN_Pos)) /* Assignment of value for TXSYN in the SSC_SR register */
#define SSC_SR_RXSYN_Pos                      _UINT32_(11)                                         /* (SSC_SR) Receive Sync Position */
#define SSC_SR_RXSYN_Msk                      (_UINT32_(0x1) << SSC_SR_RXSYN_Pos)                  /* (SSC_SR) Receive Sync Mask */
#define SSC_SR_RXSYN(value)                   (SSC_SR_RXSYN_Msk & (_UINT32_(value) << SSC_SR_RXSYN_Pos)) /* Assignment of value for RXSYN in the SSC_SR register */
#define SSC_SR_TXEN_Pos                       _UINT32_(16)                                         /* (SSC_SR) Transmit Enable Position */
#define SSC_SR_TXEN_Msk                       (_UINT32_(0x1) << SSC_SR_TXEN_Pos)                   /* (SSC_SR) Transmit Enable Mask */
#define SSC_SR_TXEN(value)                    (SSC_SR_TXEN_Msk & (_UINT32_(value) << SSC_SR_TXEN_Pos)) /* Assignment of value for TXEN in the SSC_SR register */
#define SSC_SR_RXEN_Pos                       _UINT32_(17)                                         /* (SSC_SR) Receive Enable Position */
#define SSC_SR_RXEN_Msk                       (_UINT32_(0x1) << SSC_SR_RXEN_Pos)                   /* (SSC_SR) Receive Enable Mask */
#define SSC_SR_RXEN(value)                    (SSC_SR_RXEN_Msk & (_UINT32_(value) << SSC_SR_RXEN_Pos)) /* Assignment of value for RXEN in the SSC_SR register */
#define SSC_SR_Msk                            _UINT32_(0x00030F33)                                 /* (SSC_SR) Register Mask  */

#define SSC_SR_CP_Pos                         _UINT32_(8)                                          /* (SSC_SR Position) Compare x */
#define SSC_SR_CP_Msk                         (_UINT32_(0x3) << SSC_SR_CP_Pos)                     /* (SSC_SR Mask) CP */
#define SSC_SR_CP(value)                      (SSC_SR_CP_Msk & (_UINT32_(value) << SSC_SR_CP_Pos)) 

/* -------- SSC_IER : (SSC Offset: 0x44) ( /W 32) Interrupt Enable Register -------- */
#define SSC_IER_TXRDY_Pos                     _UINT32_(0)                                          /* (SSC_IER) Transmit Ready Interrupt Enable Position */
#define SSC_IER_TXRDY_Msk                     (_UINT32_(0x1) << SSC_IER_TXRDY_Pos)                 /* (SSC_IER) Transmit Ready Interrupt Enable Mask */
#define SSC_IER_TXRDY(value)                  (SSC_IER_TXRDY_Msk & (_UINT32_(value) << SSC_IER_TXRDY_Pos)) /* Assignment of value for TXRDY in the SSC_IER register */
#define SSC_IER_TXEMPTY_Pos                   _UINT32_(1)                                          /* (SSC_IER) Transmit Empty Interrupt Enable Position */
#define SSC_IER_TXEMPTY_Msk                   (_UINT32_(0x1) << SSC_IER_TXEMPTY_Pos)               /* (SSC_IER) Transmit Empty Interrupt Enable Mask */
#define SSC_IER_TXEMPTY(value)                (SSC_IER_TXEMPTY_Msk & (_UINT32_(value) << SSC_IER_TXEMPTY_Pos)) /* Assignment of value for TXEMPTY in the SSC_IER register */
#define SSC_IER_RXRDY_Pos                     _UINT32_(4)                                          /* (SSC_IER) Receive Ready Interrupt Enable Position */
#define SSC_IER_RXRDY_Msk                     (_UINT32_(0x1) << SSC_IER_RXRDY_Pos)                 /* (SSC_IER) Receive Ready Interrupt Enable Mask */
#define SSC_IER_RXRDY(value)                  (SSC_IER_RXRDY_Msk & (_UINT32_(value) << SSC_IER_RXRDY_Pos)) /* Assignment of value for RXRDY in the SSC_IER register */
#define SSC_IER_OVRUN_Pos                     _UINT32_(5)                                          /* (SSC_IER) Receive Overrun Interrupt Enable Position */
#define SSC_IER_OVRUN_Msk                     (_UINT32_(0x1) << SSC_IER_OVRUN_Pos)                 /* (SSC_IER) Receive Overrun Interrupt Enable Mask */
#define SSC_IER_OVRUN(value)                  (SSC_IER_OVRUN_Msk & (_UINT32_(value) << SSC_IER_OVRUN_Pos)) /* Assignment of value for OVRUN in the SSC_IER register */
#define SSC_IER_CP0_Pos                       _UINT32_(8)                                          /* (SSC_IER) Compare 0 Interrupt Enable Position */
#define SSC_IER_CP0_Msk                       (_UINT32_(0x1) << SSC_IER_CP0_Pos)                   /* (SSC_IER) Compare 0 Interrupt Enable Mask */
#define SSC_IER_CP0(value)                    (SSC_IER_CP0_Msk & (_UINT32_(value) << SSC_IER_CP0_Pos)) /* Assignment of value for CP0 in the SSC_IER register */
#define SSC_IER_CP1_Pos                       _UINT32_(9)                                          /* (SSC_IER) Compare 1 Interrupt Enable Position */
#define SSC_IER_CP1_Msk                       (_UINT32_(0x1) << SSC_IER_CP1_Pos)                   /* (SSC_IER) Compare 1 Interrupt Enable Mask */
#define SSC_IER_CP1(value)                    (SSC_IER_CP1_Msk & (_UINT32_(value) << SSC_IER_CP1_Pos)) /* Assignment of value for CP1 in the SSC_IER register */
#define SSC_IER_TXSYN_Pos                     _UINT32_(10)                                         /* (SSC_IER) Tx Sync Interrupt Enable Position */
#define SSC_IER_TXSYN_Msk                     (_UINT32_(0x1) << SSC_IER_TXSYN_Pos)                 /* (SSC_IER) Tx Sync Interrupt Enable Mask */
#define SSC_IER_TXSYN(value)                  (SSC_IER_TXSYN_Msk & (_UINT32_(value) << SSC_IER_TXSYN_Pos)) /* Assignment of value for TXSYN in the SSC_IER register */
#define SSC_IER_RXSYN_Pos                     _UINT32_(11)                                         /* (SSC_IER) Rx Sync Interrupt Enable Position */
#define SSC_IER_RXSYN_Msk                     (_UINT32_(0x1) << SSC_IER_RXSYN_Pos)                 /* (SSC_IER) Rx Sync Interrupt Enable Mask */
#define SSC_IER_RXSYN(value)                  (SSC_IER_RXSYN_Msk & (_UINT32_(value) << SSC_IER_RXSYN_Pos)) /* Assignment of value for RXSYN in the SSC_IER register */
#define SSC_IER_Msk                           _UINT32_(0x00000F33)                                 /* (SSC_IER) Register Mask  */

#define SSC_IER_CP_Pos                        _UINT32_(8)                                          /* (SSC_IER Position) Compare x Interrupt Enable */
#define SSC_IER_CP_Msk                        (_UINT32_(0x3) << SSC_IER_CP_Pos)                    /* (SSC_IER Mask) CP */
#define SSC_IER_CP(value)                     (SSC_IER_CP_Msk & (_UINT32_(value) << SSC_IER_CP_Pos)) 

/* -------- SSC_IDR : (SSC Offset: 0x48) ( /W 32) Interrupt Disable Register -------- */
#define SSC_IDR_TXRDY_Pos                     _UINT32_(0)                                          /* (SSC_IDR) Transmit Ready Interrupt Disable Position */
#define SSC_IDR_TXRDY_Msk                     (_UINT32_(0x1) << SSC_IDR_TXRDY_Pos)                 /* (SSC_IDR) Transmit Ready Interrupt Disable Mask */
#define SSC_IDR_TXRDY(value)                  (SSC_IDR_TXRDY_Msk & (_UINT32_(value) << SSC_IDR_TXRDY_Pos)) /* Assignment of value for TXRDY in the SSC_IDR register */
#define SSC_IDR_TXEMPTY_Pos                   _UINT32_(1)                                          /* (SSC_IDR) Transmit Empty Interrupt Disable Position */
#define SSC_IDR_TXEMPTY_Msk                   (_UINT32_(0x1) << SSC_IDR_TXEMPTY_Pos)               /* (SSC_IDR) Transmit Empty Interrupt Disable Mask */
#define SSC_IDR_TXEMPTY(value)                (SSC_IDR_TXEMPTY_Msk & (_UINT32_(value) << SSC_IDR_TXEMPTY_Pos)) /* Assignment of value for TXEMPTY in the SSC_IDR register */
#define SSC_IDR_RXRDY_Pos                     _UINT32_(4)                                          /* (SSC_IDR) Receive Ready Interrupt Disable Position */
#define SSC_IDR_RXRDY_Msk                     (_UINT32_(0x1) << SSC_IDR_RXRDY_Pos)                 /* (SSC_IDR) Receive Ready Interrupt Disable Mask */
#define SSC_IDR_RXRDY(value)                  (SSC_IDR_RXRDY_Msk & (_UINT32_(value) << SSC_IDR_RXRDY_Pos)) /* Assignment of value for RXRDY in the SSC_IDR register */
#define SSC_IDR_OVRUN_Pos                     _UINT32_(5)                                          /* (SSC_IDR) Receive Overrun Interrupt Disable Position */
#define SSC_IDR_OVRUN_Msk                     (_UINT32_(0x1) << SSC_IDR_OVRUN_Pos)                 /* (SSC_IDR) Receive Overrun Interrupt Disable Mask */
#define SSC_IDR_OVRUN(value)                  (SSC_IDR_OVRUN_Msk & (_UINT32_(value) << SSC_IDR_OVRUN_Pos)) /* Assignment of value for OVRUN in the SSC_IDR register */
#define SSC_IDR_CP0_Pos                       _UINT32_(8)                                          /* (SSC_IDR) Compare 0 Interrupt Disable Position */
#define SSC_IDR_CP0_Msk                       (_UINT32_(0x1) << SSC_IDR_CP0_Pos)                   /* (SSC_IDR) Compare 0 Interrupt Disable Mask */
#define SSC_IDR_CP0(value)                    (SSC_IDR_CP0_Msk & (_UINT32_(value) << SSC_IDR_CP0_Pos)) /* Assignment of value for CP0 in the SSC_IDR register */
#define SSC_IDR_CP1_Pos                       _UINT32_(9)                                          /* (SSC_IDR) Compare 1 Interrupt Disable Position */
#define SSC_IDR_CP1_Msk                       (_UINT32_(0x1) << SSC_IDR_CP1_Pos)                   /* (SSC_IDR) Compare 1 Interrupt Disable Mask */
#define SSC_IDR_CP1(value)                    (SSC_IDR_CP1_Msk & (_UINT32_(value) << SSC_IDR_CP1_Pos)) /* Assignment of value for CP1 in the SSC_IDR register */
#define SSC_IDR_TXSYN_Pos                     _UINT32_(10)                                         /* (SSC_IDR) Tx Sync Interrupt Enable Position */
#define SSC_IDR_TXSYN_Msk                     (_UINT32_(0x1) << SSC_IDR_TXSYN_Pos)                 /* (SSC_IDR) Tx Sync Interrupt Enable Mask */
#define SSC_IDR_TXSYN(value)                  (SSC_IDR_TXSYN_Msk & (_UINT32_(value) << SSC_IDR_TXSYN_Pos)) /* Assignment of value for TXSYN in the SSC_IDR register */
#define SSC_IDR_RXSYN_Pos                     _UINT32_(11)                                         /* (SSC_IDR) Rx Sync Interrupt Enable Position */
#define SSC_IDR_RXSYN_Msk                     (_UINT32_(0x1) << SSC_IDR_RXSYN_Pos)                 /* (SSC_IDR) Rx Sync Interrupt Enable Mask */
#define SSC_IDR_RXSYN(value)                  (SSC_IDR_RXSYN_Msk & (_UINT32_(value) << SSC_IDR_RXSYN_Pos)) /* Assignment of value for RXSYN in the SSC_IDR register */
#define SSC_IDR_Msk                           _UINT32_(0x00000F33)                                 /* (SSC_IDR) Register Mask  */

#define SSC_IDR_CP_Pos                        _UINT32_(8)                                          /* (SSC_IDR Position) Compare x Interrupt Disable */
#define SSC_IDR_CP_Msk                        (_UINT32_(0x3) << SSC_IDR_CP_Pos)                    /* (SSC_IDR Mask) CP */
#define SSC_IDR_CP(value)                     (SSC_IDR_CP_Msk & (_UINT32_(value) << SSC_IDR_CP_Pos)) 

/* -------- SSC_IMR : (SSC Offset: 0x4C) ( R/ 32) Interrupt Mask Register -------- */
#define SSC_IMR_TXRDY_Pos                     _UINT32_(0)                                          /* (SSC_IMR) Transmit Ready Interrupt Mask Position */
#define SSC_IMR_TXRDY_Msk                     (_UINT32_(0x1) << SSC_IMR_TXRDY_Pos)                 /* (SSC_IMR) Transmit Ready Interrupt Mask Mask */
#define SSC_IMR_TXRDY(value)                  (SSC_IMR_TXRDY_Msk & (_UINT32_(value) << SSC_IMR_TXRDY_Pos)) /* Assignment of value for TXRDY in the SSC_IMR register */
#define SSC_IMR_TXEMPTY_Pos                   _UINT32_(1)                                          /* (SSC_IMR) Transmit Empty Interrupt Mask Position */
#define SSC_IMR_TXEMPTY_Msk                   (_UINT32_(0x1) << SSC_IMR_TXEMPTY_Pos)               /* (SSC_IMR) Transmit Empty Interrupt Mask Mask */
#define SSC_IMR_TXEMPTY(value)                (SSC_IMR_TXEMPTY_Msk & (_UINT32_(value) << SSC_IMR_TXEMPTY_Pos)) /* Assignment of value for TXEMPTY in the SSC_IMR register */
#define SSC_IMR_RXRDY_Pos                     _UINT32_(4)                                          /* (SSC_IMR) Receive Ready Interrupt Mask Position */
#define SSC_IMR_RXRDY_Msk                     (_UINT32_(0x1) << SSC_IMR_RXRDY_Pos)                 /* (SSC_IMR) Receive Ready Interrupt Mask Mask */
#define SSC_IMR_RXRDY(value)                  (SSC_IMR_RXRDY_Msk & (_UINT32_(value) << SSC_IMR_RXRDY_Pos)) /* Assignment of value for RXRDY in the SSC_IMR register */
#define SSC_IMR_OVRUN_Pos                     _UINT32_(5)                                          /* (SSC_IMR) Receive Overrun Interrupt Mask Position */
#define SSC_IMR_OVRUN_Msk                     (_UINT32_(0x1) << SSC_IMR_OVRUN_Pos)                 /* (SSC_IMR) Receive Overrun Interrupt Mask Mask */
#define SSC_IMR_OVRUN(value)                  (SSC_IMR_OVRUN_Msk & (_UINT32_(value) << SSC_IMR_OVRUN_Pos)) /* Assignment of value for OVRUN in the SSC_IMR register */
#define SSC_IMR_CP0_Pos                       _UINT32_(8)                                          /* (SSC_IMR) Compare 0 Interrupt Mask Position */
#define SSC_IMR_CP0_Msk                       (_UINT32_(0x1) << SSC_IMR_CP0_Pos)                   /* (SSC_IMR) Compare 0 Interrupt Mask Mask */
#define SSC_IMR_CP0(value)                    (SSC_IMR_CP0_Msk & (_UINT32_(value) << SSC_IMR_CP0_Pos)) /* Assignment of value for CP0 in the SSC_IMR register */
#define SSC_IMR_CP1_Pos                       _UINT32_(9)                                          /* (SSC_IMR) Compare 1 Interrupt Mask Position */
#define SSC_IMR_CP1_Msk                       (_UINT32_(0x1) << SSC_IMR_CP1_Pos)                   /* (SSC_IMR) Compare 1 Interrupt Mask Mask */
#define SSC_IMR_CP1(value)                    (SSC_IMR_CP1_Msk & (_UINT32_(value) << SSC_IMR_CP1_Pos)) /* Assignment of value for CP1 in the SSC_IMR register */
#define SSC_IMR_TXSYN_Pos                     _UINT32_(10)                                         /* (SSC_IMR) Tx Sync Interrupt Mask Position */
#define SSC_IMR_TXSYN_Msk                     (_UINT32_(0x1) << SSC_IMR_TXSYN_Pos)                 /* (SSC_IMR) Tx Sync Interrupt Mask Mask */
#define SSC_IMR_TXSYN(value)                  (SSC_IMR_TXSYN_Msk & (_UINT32_(value) << SSC_IMR_TXSYN_Pos)) /* Assignment of value for TXSYN in the SSC_IMR register */
#define SSC_IMR_RXSYN_Pos                     _UINT32_(11)                                         /* (SSC_IMR) Rx Sync Interrupt Mask Position */
#define SSC_IMR_RXSYN_Msk                     (_UINT32_(0x1) << SSC_IMR_RXSYN_Pos)                 /* (SSC_IMR) Rx Sync Interrupt Mask Mask */
#define SSC_IMR_RXSYN(value)                  (SSC_IMR_RXSYN_Msk & (_UINT32_(value) << SSC_IMR_RXSYN_Pos)) /* Assignment of value for RXSYN in the SSC_IMR register */
#define SSC_IMR_Msk                           _UINT32_(0x00000F33)                                 /* (SSC_IMR) Register Mask  */

#define SSC_IMR_CP_Pos                        _UINT32_(8)                                          /* (SSC_IMR Position) Compare x Interrupt Mask */
#define SSC_IMR_CP_Msk                        (_UINT32_(0x3) << SSC_IMR_CP_Pos)                    /* (SSC_IMR Mask) CP */
#define SSC_IMR_CP(value)                     (SSC_IMR_CP_Msk & (_UINT32_(value) << SSC_IMR_CP_Pos)) 

/* -------- SSC_WPMR : (SSC Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define SSC_WPMR_WPEN_Pos                     _UINT32_(0)                                          /* (SSC_WPMR) Write Protection Enable Position */
#define SSC_WPMR_WPEN_Msk                     (_UINT32_(0x1) << SSC_WPMR_WPEN_Pos)                 /* (SSC_WPMR) Write Protection Enable Mask */
#define SSC_WPMR_WPEN(value)                  (SSC_WPMR_WPEN_Msk & (_UINT32_(value) << SSC_WPMR_WPEN_Pos)) /* Assignment of value for WPEN in the SSC_WPMR register */
#define SSC_WPMR_WPKEY_Pos                    _UINT32_(8)                                          /* (SSC_WPMR) Write Protection Key Position */
#define SSC_WPMR_WPKEY_Msk                    (_UINT32_(0xFFFFFF) << SSC_WPMR_WPKEY_Pos)           /* (SSC_WPMR) Write Protection Key Mask */
#define SSC_WPMR_WPKEY(value)                 (SSC_WPMR_WPKEY_Msk & (_UINT32_(value) << SSC_WPMR_WPKEY_Pos)) /* Assignment of value for WPKEY in the SSC_WPMR register */
#define   SSC_WPMR_WPKEY_PASSWD_Val           _UINT32_(0x535343)                                   /* (SSC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0.  */
#define SSC_WPMR_WPKEY_PASSWD                 (SSC_WPMR_WPKEY_PASSWD_Val << SSC_WPMR_WPKEY_Pos)    /* (SSC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0. Position */
#define SSC_WPMR_Msk                          _UINT32_(0xFFFFFF01)                                 /* (SSC_WPMR) Register Mask  */


/* -------- SSC_WPSR : (SSC Offset: 0xE8) ( R/ 32) Write Protection Status Register -------- */
#define SSC_WPSR_WPVS_Pos                     _UINT32_(0)                                          /* (SSC_WPSR) Write Protection Violation Status Position */
#define SSC_WPSR_WPVS_Msk                     (_UINT32_(0x1) << SSC_WPSR_WPVS_Pos)                 /* (SSC_WPSR) Write Protection Violation Status Mask */
#define SSC_WPSR_WPVS(value)                  (SSC_WPSR_WPVS_Msk & (_UINT32_(value) << SSC_WPSR_WPVS_Pos)) /* Assignment of value for WPVS in the SSC_WPSR register */
#define SSC_WPSR_WPVSRC_Pos                   _UINT32_(8)                                          /* (SSC_WPSR) Write Protect Violation Source Position */
#define SSC_WPSR_WPVSRC_Msk                   (_UINT32_(0xFFFF) << SSC_WPSR_WPVSRC_Pos)            /* (SSC_WPSR) Write Protect Violation Source Mask */
#define SSC_WPSR_WPVSRC(value)                (SSC_WPSR_WPVSRC_Msk & (_UINT32_(value) << SSC_WPSR_WPVSRC_Pos)) /* Assignment of value for WPVSRC in the SSC_WPSR register */
#define SSC_WPSR_Msk                          _UINT32_(0x00FFFF01)                                 /* (SSC_WPSR) Register Mask  */


/* SSC register offsets definitions */
#define SSC_CR_REG_OFST                _UINT32_(0x00)      /* (SSC_CR) Control Register Offset */
#define SSC_CMR_REG_OFST               _UINT32_(0x04)      /* (SSC_CMR) Clock Mode Register Offset */
#define SSC_RCMR_REG_OFST              _UINT32_(0x10)      /* (SSC_RCMR) Receive Clock Mode Register Offset */
#define SSC_RFMR_REG_OFST              _UINT32_(0x14)      /* (SSC_RFMR) Receive Frame Mode Register Offset */
#define SSC_TCMR_REG_OFST              _UINT32_(0x18)      /* (SSC_TCMR) Transmit Clock Mode Register Offset */
#define SSC_TFMR_REG_OFST              _UINT32_(0x1C)      /* (SSC_TFMR) Transmit Frame Mode Register Offset */
#define SSC_RHR_REG_OFST               _UINT32_(0x20)      /* (SSC_RHR) Receive Holding Register Offset */
#define SSC_THR_REG_OFST               _UINT32_(0x24)      /* (SSC_THR) Transmit Holding Register Offset */
#define SSC_RSHR_REG_OFST              _UINT32_(0x30)      /* (SSC_RSHR) Receive Sync. Holding Register Offset */
#define SSC_TSHR_REG_OFST              _UINT32_(0x34)      /* (SSC_TSHR) Transmit Sync. Holding Register Offset */
#define SSC_RC0R_REG_OFST              _UINT32_(0x38)      /* (SSC_RC0R) Receive Compare 0 Register Offset */
#define SSC_RC1R_REG_OFST              _UINT32_(0x3C)      /* (SSC_RC1R) Receive Compare 1 Register Offset */
#define SSC_SR_REG_OFST                _UINT32_(0x40)      /* (SSC_SR) Status Register Offset */
#define SSC_IER_REG_OFST               _UINT32_(0x44)      /* (SSC_IER) Interrupt Enable Register Offset */
#define SSC_IDR_REG_OFST               _UINT32_(0x48)      /* (SSC_IDR) Interrupt Disable Register Offset */
#define SSC_IMR_REG_OFST               _UINT32_(0x4C)      /* (SSC_IMR) Interrupt Mask Register Offset */
#define SSC_WPMR_REG_OFST              _UINT32_(0xE4)      /* (SSC_WPMR) Write Protection Mode Register Offset */
#define SSC_WPSR_REG_OFST              _UINT32_(0xE8)      /* (SSC_WPSR) Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* SSC register API structure */
typedef struct
{
  __O   uint32_t                       SSC_CR;             /* Offset: 0x00 ( /W  32) Control Register */
  __IO  uint32_t                       SSC_CMR;            /* Offset: 0x04 (R/W  32) Clock Mode Register */
  __I   uint8_t                        Reserved1[0x08];
  __IO  uint32_t                       SSC_RCMR;           /* Offset: 0x10 (R/W  32) Receive Clock Mode Register */
  __IO  uint32_t                       SSC_RFMR;           /* Offset: 0x14 (R/W  32) Receive Frame Mode Register */
  __IO  uint32_t                       SSC_TCMR;           /* Offset: 0x18 (R/W  32) Transmit Clock Mode Register */
  __IO  uint32_t                       SSC_TFMR;           /* Offset: 0x1C (R/W  32) Transmit Frame Mode Register */
  __I   uint32_t                       SSC_RHR;            /* Offset: 0x20 (R/   32) Receive Holding Register */
  __O   uint32_t                       SSC_THR;            /* Offset: 0x24 ( /W  32) Transmit Holding Register */
  __I   uint8_t                        Reserved2[0x08];
  __I   uint32_t                       SSC_RSHR;           /* Offset: 0x30 (R/   32) Receive Sync. Holding Register */
  __IO  uint32_t                       SSC_TSHR;           /* Offset: 0x34 (R/W  32) Transmit Sync. Holding Register */
  __IO  uint32_t                       SSC_RC0R;           /* Offset: 0x38 (R/W  32) Receive Compare 0 Register */
  __IO  uint32_t                       SSC_RC1R;           /* Offset: 0x3C (R/W  32) Receive Compare 1 Register */
  __I   uint32_t                       SSC_SR;             /* Offset: 0x40 (R/   32) Status Register */
  __O   uint32_t                       SSC_IER;            /* Offset: 0x44 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       SSC_IDR;            /* Offset: 0x48 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       SSC_IMR;            /* Offset: 0x4C (R/   32) Interrupt Mask Register */
  __I   uint8_t                        Reserved3[0x94];
  __IO  uint32_t                       SSC_WPMR;           /* Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       SSC_WPSR;           /* Offset: 0xE8 (R/   32) Write Protection Status Register */
} ssc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA70_SSC_COMPONENT_H_ */
