/*
 * Component description for RSTC
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
#ifndef _PIC32CMGC00_RSTC_COMPONENT_H_
#define _PIC32CMGC00_RSTC_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR RSTC                      */
/* ************************************************************************** */

/* -------- RSTC_RCAUSE : (RSTC Offset: 0x00) ( R/ 16) Reset Cause -------- */
#define RSTC_RCAUSE_POR_Pos                   _UINT16_(0)                                          /* (RSTC_RCAUSE) Power On Reset Position */
#define RSTC_RCAUSE_POR_Msk                   (_UINT16_(0x1) << RSTC_RCAUSE_POR_Pos)               /* (RSTC_RCAUSE) Power On Reset Mask */
#define RSTC_RCAUSE_POR(value)                (RSTC_RCAUSE_POR_Msk & (_UINT16_(value) << RSTC_RCAUSE_POR_Pos)) /* Assignment of value for POR in the RSTC_RCAUSE register */
#define RSTC_RCAUSE_PORCORE_Pos               _UINT16_(1)                                          /* (RSTC_RCAUSE) Brown Out CORE Detector Reset Position */
#define RSTC_RCAUSE_PORCORE_Msk               (_UINT16_(0x1) << RSTC_RCAUSE_PORCORE_Pos)           /* (RSTC_RCAUSE) Brown Out CORE Detector Reset Mask */
#define RSTC_RCAUSE_PORCORE(value)            (RSTC_RCAUSE_PORCORE_Msk & (_UINT16_(value) << RSTC_RCAUSE_PORCORE_Pos)) /* Assignment of value for PORCORE in the RSTC_RCAUSE register */
#define RSTC_RCAUSE_BORVDDREG_Pos             _UINT16_(2)                                          /* (RSTC_RCAUSE) Brown Out VDDREG Detector Reset Position */
#define RSTC_RCAUSE_BORVDDREG_Msk             (_UINT16_(0x1) << RSTC_RCAUSE_BORVDDREG_Pos)         /* (RSTC_RCAUSE) Brown Out VDDREG Detector Reset Mask */
#define RSTC_RCAUSE_BORVDDREG(value)          (RSTC_RCAUSE_BORVDDREG_Msk & (_UINT16_(value) << RSTC_RCAUSE_BORVDDREG_Pos)) /* Assignment of value for BORVDDREG in the RSTC_RCAUSE register */
#define RSTC_RCAUSE_BORVDDA_Pos               _UINT16_(3)                                          /* (RSTC_RCAUSE) Brown Out VDDA Detector Reset Position */
#define RSTC_RCAUSE_BORVDDA_Msk               (_UINT16_(0x1) << RSTC_RCAUSE_BORVDDA_Pos)           /* (RSTC_RCAUSE) Brown Out VDDA Detector Reset Mask */
#define RSTC_RCAUSE_BORVDDA(value)            (RSTC_RCAUSE_BORVDDA_Msk & (_UINT16_(value) << RSTC_RCAUSE_BORVDDA_Pos)) /* Assignment of value for BORVDDA in the RSTC_RCAUSE register */
#define RSTC_RCAUSE_BORVDDIO_Pos              _UINT16_(4)                                          /* (RSTC_RCAUSE) Brown Out VDDIO Detector Reset Position */
#define RSTC_RCAUSE_BORVDDIO_Msk              (_UINT16_(0x1) << RSTC_RCAUSE_BORVDDIO_Pos)          /* (RSTC_RCAUSE) Brown Out VDDIO Detector Reset Mask */
#define RSTC_RCAUSE_BORVDDIO(value)           (RSTC_RCAUSE_BORVDDIO_Msk & (_UINT16_(value) << RSTC_RCAUSE_BORVDDIO_Pos)) /* Assignment of value for BORVDDIO in the RSTC_RCAUSE register */
#define RSTC_RCAUSE_EXT_Pos                   _UINT16_(5)                                          /* (RSTC_RCAUSE) External Reset Position */
#define RSTC_RCAUSE_EXT_Msk                   (_UINT16_(0x1) << RSTC_RCAUSE_EXT_Pos)               /* (RSTC_RCAUSE) External Reset Mask */
#define RSTC_RCAUSE_EXT(value)                (RSTC_RCAUSE_EXT_Msk & (_UINT16_(value) << RSTC_RCAUSE_EXT_Pos)) /* Assignment of value for EXT in the RSTC_RCAUSE register */
#define RSTC_RCAUSE_WDT_Pos                   _UINT16_(6)                                          /* (RSTC_RCAUSE) Watchdog Reset Position */
#define RSTC_RCAUSE_WDT_Msk                   (_UINT16_(0x1) << RSTC_RCAUSE_WDT_Pos)               /* (RSTC_RCAUSE) Watchdog Reset Mask */
#define RSTC_RCAUSE_WDT(value)                (RSTC_RCAUSE_WDT_Msk & (_UINT16_(value) << RSTC_RCAUSE_WDT_Pos)) /* Assignment of value for WDT in the RSTC_RCAUSE register */
#define RSTC_RCAUSE_SYST_Pos                  _UINT16_(7)                                          /* (RSTC_RCAUSE) System Reset Request Position */
#define RSTC_RCAUSE_SYST_Msk                  (_UINT16_(0x1) << RSTC_RCAUSE_SYST_Pos)              /* (RSTC_RCAUSE) System Reset Request Mask */
#define RSTC_RCAUSE_SYST(value)               (RSTC_RCAUSE_SYST_Msk & (_UINT16_(value) << RSTC_RCAUSE_SYST_Pos)) /* Assignment of value for SYST in the RSTC_RCAUSE register */
#define RSTC_RCAUSE_BACKUP_Pos                _UINT16_(8)                                          /* (RSTC_RCAUSE) Backup Reset Position */
#define RSTC_RCAUSE_BACKUP_Msk                (_UINT16_(0x1) << RSTC_RCAUSE_BACKUP_Pos)            /* (RSTC_RCAUSE) Backup Reset Mask */
#define RSTC_RCAUSE_BACKUP(value)             (RSTC_RCAUSE_BACKUP_Msk & (_UINT16_(value) << RSTC_RCAUSE_BACKUP_Pos)) /* Assignment of value for BACKUP in the RSTC_RCAUSE register */
#define RSTC_RCAUSE_LOCKUP_Pos                _UINT16_(9)                                          /* (RSTC_RCAUSE) Lockup Reset Position */
#define RSTC_RCAUSE_LOCKUP_Msk                (_UINT16_(0x1) << RSTC_RCAUSE_LOCKUP_Pos)            /* (RSTC_RCAUSE) Lockup Reset Mask */
#define RSTC_RCAUSE_LOCKUP(value)             (RSTC_RCAUSE_LOCKUP_Msk & (_UINT16_(value) << RSTC_RCAUSE_LOCKUP_Pos)) /* Assignment of value for LOCKUP in the RSTC_RCAUSE register */
#define RSTC_RCAUSE_Msk                       _UINT16_(0x03FF)                                     /* (RSTC_RCAUSE) Register Mask  */


/* -------- RSTC_BKUPEXIT : (RSTC Offset: 0x02) ( R/ 8) Backup Exit Source. Implemented only if RSTC_BACKUP_IMPLEMENTED=1 -------- */
#define RSTC_BKUPEXIT_RESETVALUE              _UINT8_(0x00)                                        /*  (RSTC_BKUPEXIT) Backup Exit Source. Implemented only if RSTC_BACKUP_IMPLEMENTED=1  Reset Value */

#define RSTC_BKUPEXIT_RTC_Pos                 _UINT8_(1)                                           /* (RSTC_BKUPEXIT) Real Timer Counter Interrupt Position */
#define RSTC_BKUPEXIT_RTC_Msk                 (_UINT8_(0x1) << RSTC_BKUPEXIT_RTC_Pos)              /* (RSTC_BKUPEXIT) Real Timer Counter Interrupt Mask */
#define RSTC_BKUPEXIT_RTC(value)              (RSTC_BKUPEXIT_RTC_Msk & (_UINT8_(value) << RSTC_BKUPEXIT_RTC_Pos)) /* Assignment of value for RTC in the RSTC_BKUPEXIT register */
#define RSTC_BKUPEXIT_HIB0_Pos                _UINT8_(7)                                           /* (RSTC_BKUPEXIT) Hibernate Position */
#define RSTC_BKUPEXIT_HIB0_Msk                (_UINT8_(0x1) << RSTC_BKUPEXIT_HIB0_Pos)             /* (RSTC_BKUPEXIT) Hibernate Mask */
#define RSTC_BKUPEXIT_HIB0(value)             (RSTC_BKUPEXIT_HIB0_Msk & (_UINT8_(value) << RSTC_BKUPEXIT_HIB0_Pos)) /* Assignment of value for HIB0 in the RSTC_BKUPEXIT register */
#define RSTC_BKUPEXIT_Msk                     _UINT8_(0x82)                                        /* (RSTC_BKUPEXIT) Register Mask  */

#define RSTC_BKUPEXIT_HIB_Pos                 _UINT8_(7)                                           /* (RSTC_BKUPEXIT Position) Hibernate */
#define RSTC_BKUPEXIT_HIB_Msk                 (_UINT8_(0x1) << RSTC_BKUPEXIT_HIB_Pos)              /* (RSTC_BKUPEXIT Mask) HIB */
#define RSTC_BKUPEXIT_HIB(value)              (RSTC_BKUPEXIT_HIB_Msk & (_UINT8_(value) << RSTC_BKUPEXIT_HIB_Pos)) 

/* -------- RSTC_DBGCTRL : (RSTC Offset: 0x04) (R/W 32) Debug Control -------- */
#define RSTC_DBGCTRL_RESETVALUE               _UINT32_(0x00)                                       /*  (RSTC_DBGCTRL) Debug Control  Reset Value */

#define RSTC_DBGCTRL_LCKUPDIS_Pos             _UINT32_(0)                                          /* (RSTC_DBGCTRL) Lockup Disable Position */
#define RSTC_DBGCTRL_LCKUPDIS_Msk             (_UINT32_(0x1) << RSTC_DBGCTRL_LCKUPDIS_Pos)         /* (RSTC_DBGCTRL) Lockup Disable Mask */
#define RSTC_DBGCTRL_LCKUPDIS(value)          (RSTC_DBGCTRL_LCKUPDIS_Msk & (_UINT32_(value) << RSTC_DBGCTRL_LCKUPDIS_Pos)) /* Assignment of value for LCKUPDIS in the RSTC_DBGCTRL register */
#define RSTC_DBGCTRL_Msk                      _UINT32_(0x00000001)                                 /* (RSTC_DBGCTRL) Register Mask  */


/* RSTC register offsets definitions */
#define RSTC_RCAUSE_REG_OFST           _UINT32_(0x00)      /* (RSTC_RCAUSE) Reset Cause Offset */
#define RSTC_BKUPEXIT_REG_OFST         _UINT32_(0x02)      /* (RSTC_BKUPEXIT) Backup Exit Source. Implemented only if RSTC_BACKUP_IMPLEMENTED=1 Offset */
#define RSTC_DBGCTRL_REG_OFST          _UINT32_(0x04)      /* (RSTC_DBGCTRL) Debug Control Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* RSTC register API structure */
typedef struct
{  /* Reset Controller */
  __I   uint16_t                       RSTC_RCAUSE;        /* Offset: 0x00 (R/   16) Reset Cause */
  __I   uint8_t                        RSTC_BKUPEXIT;      /* Offset: 0x02 (R/   8) Backup Exit Source. Implemented only if RSTC_BACKUP_IMPLEMENTED=1 */
  __I   uint8_t                        Reserved1[0x01];
  __IO  uint32_t                       RSTC_DBGCTRL;       /* Offset: 0x04 (R/W  32) Debug Control */
} rstc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMGC00_RSTC_COMPONENT_H_ */
