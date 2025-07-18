/*
 * Component description for EFC
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
#ifndef _PIC32CZCA70_EFC_COMPONENT_H_
#define _PIC32CZCA70_EFC_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR EFC                       */
/* ************************************************************************** */

/* -------- EEFC_FMR : (EFC Offset: 0x00) (R/W 32) EEFC Flash Mode Register -------- */
#define EEFC_FMR_FRDY_Pos                     _UINT32_(0)                                          /* (EEFC_FMR) Flash Ready Interrupt Enable Position */
#define EEFC_FMR_FRDY_Msk                     (_UINT32_(0x1) << EEFC_FMR_FRDY_Pos)                 /* (EEFC_FMR) Flash Ready Interrupt Enable Mask */
#define EEFC_FMR_FRDY(value)                  (EEFC_FMR_FRDY_Msk & (_UINT32_(value) << EEFC_FMR_FRDY_Pos)) /* Assignment of value for FRDY in the EEFC_FMR register */
#define EEFC_FMR_FWS_Pos                      _UINT32_(8)                                          /* (EEFC_FMR) Flash Wait State Position */
#define EEFC_FMR_FWS_Msk                      (_UINT32_(0xF) << EEFC_FMR_FWS_Pos)                  /* (EEFC_FMR) Flash Wait State Mask */
#define EEFC_FMR_FWS(value)                   (EEFC_FMR_FWS_Msk & (_UINT32_(value) << EEFC_FMR_FWS_Pos)) /* Assignment of value for FWS in the EEFC_FMR register */
#define EEFC_FMR_SCOD_Pos                     _UINT32_(16)                                         /* (EEFC_FMR) Sequential Code Optimization Disable Position */
#define EEFC_FMR_SCOD_Msk                     (_UINT32_(0x1) << EEFC_FMR_SCOD_Pos)                 /* (EEFC_FMR) Sequential Code Optimization Disable Mask */
#define EEFC_FMR_SCOD(value)                  (EEFC_FMR_SCOD_Msk & (_UINT32_(value) << EEFC_FMR_SCOD_Pos)) /* Assignment of value for SCOD in the EEFC_FMR register */
#define EEFC_FMR_CLOE_Pos                     _UINT32_(26)                                         /* (EEFC_FMR) Code Loop Optimization Enable Position */
#define EEFC_FMR_CLOE_Msk                     (_UINT32_(0x1) << EEFC_FMR_CLOE_Pos)                 /* (EEFC_FMR) Code Loop Optimization Enable Mask */
#define EEFC_FMR_CLOE(value)                  (EEFC_FMR_CLOE_Msk & (_UINT32_(value) << EEFC_FMR_CLOE_Pos)) /* Assignment of value for CLOE in the EEFC_FMR register */
#define EEFC_FMR_Msk                          _UINT32_(0x04010F01)                                 /* (EEFC_FMR) Register Mask  */


/* -------- EEFC_FCR : (EFC Offset: 0x04) ( /W 32) EEFC Flash Command Register -------- */
#define EEFC_FCR_FCMD_Pos                     _UINT32_(0)                                          /* (EEFC_FCR) Flash Command Position */
#define EEFC_FCR_FCMD_Msk                     (_UINT32_(0xFF) << EEFC_FCR_FCMD_Pos)                /* (EEFC_FCR) Flash Command Mask */
#define EEFC_FCR_FCMD(value)                  (EEFC_FCR_FCMD_Msk & (_UINT32_(value) << EEFC_FCR_FCMD_Pos)) /* Assignment of value for FCMD in the EEFC_FCR register */
#define   EEFC_FCR_FCMD_GETD_Val              _UINT32_(0x0)                                        /* (EEFC_FCR) Get Flash descriptor  */
#define   EEFC_FCR_FCMD_WP_Val                _UINT32_(0x1)                                        /* (EEFC_FCR) Write page  */
#define   EEFC_FCR_FCMD_WPL_Val               _UINT32_(0x2)                                        /* (EEFC_FCR) Write page and lock  */
#define   EEFC_FCR_FCMD_EWP_Val               _UINT32_(0x3)                                        /* (EEFC_FCR) Erase page and write page  */
#define   EEFC_FCR_FCMD_EWPL_Val              _UINT32_(0x4)                                        /* (EEFC_FCR) Erase page and write page then lock  */
#define   EEFC_FCR_FCMD_EA_Val                _UINT32_(0x5)                                        /* (EEFC_FCR) Erase all  */
#define   EEFC_FCR_FCMD_EPA_Val               _UINT32_(0x7)                                        /* (EEFC_FCR) Erase pages  */
#define   EEFC_FCR_FCMD_SLB_Val               _UINT32_(0x8)                                        /* (EEFC_FCR) Set lock bit  */
#define   EEFC_FCR_FCMD_CLB_Val               _UINT32_(0x9)                                        /* (EEFC_FCR) Clear lock bit  */
#define   EEFC_FCR_FCMD_GLB_Val               _UINT32_(0xA)                                        /* (EEFC_FCR) Get lock bit  */
#define   EEFC_FCR_FCMD_SGPB_Val              _UINT32_(0xB)                                        /* (EEFC_FCR) Set GPNVM bit  */
#define   EEFC_FCR_FCMD_CGPB_Val              _UINT32_(0xC)                                        /* (EEFC_FCR) Clear GPNVM bit  */
#define   EEFC_FCR_FCMD_GGPB_Val              _UINT32_(0xD)                                        /* (EEFC_FCR) Get GPNVM bit  */
#define   EEFC_FCR_FCMD_STUI_Val              _UINT32_(0xE)                                        /* (EEFC_FCR) Start read unique identifier  */
#define   EEFC_FCR_FCMD_SPUI_Val              _UINT32_(0xF)                                        /* (EEFC_FCR) Stop read unique identifier  */
#define   EEFC_FCR_FCMD_GCALB_Val             _UINT32_(0x10)                                       /* (EEFC_FCR) Get CALIB bit  */
#define   EEFC_FCR_FCMD_ES_Val                _UINT32_(0x11)                                       /* (EEFC_FCR) Erase sector  */
#define   EEFC_FCR_FCMD_WUS_Val               _UINT32_(0x12)                                       /* (EEFC_FCR) Write user signature  */
#define   EEFC_FCR_FCMD_EUS_Val               _UINT32_(0x13)                                       /* (EEFC_FCR) Erase user signature  */
#define   EEFC_FCR_FCMD_STUS_Val              _UINT32_(0x14)                                       /* (EEFC_FCR) Start read user signature  */
#define   EEFC_FCR_FCMD_SPUS_Val              _UINT32_(0x15)                                       /* (EEFC_FCR) Stop read user signature  */
#define EEFC_FCR_FCMD_GETD                    (EEFC_FCR_FCMD_GETD_Val << EEFC_FCR_FCMD_Pos)        /* (EEFC_FCR) Get Flash descriptor Position */
#define EEFC_FCR_FCMD_WP                      (EEFC_FCR_FCMD_WP_Val << EEFC_FCR_FCMD_Pos)          /* (EEFC_FCR) Write page Position */
#define EEFC_FCR_FCMD_WPL                     (EEFC_FCR_FCMD_WPL_Val << EEFC_FCR_FCMD_Pos)         /* (EEFC_FCR) Write page and lock Position */
#define EEFC_FCR_FCMD_EWP                     (EEFC_FCR_FCMD_EWP_Val << EEFC_FCR_FCMD_Pos)         /* (EEFC_FCR) Erase page and write page Position */
#define EEFC_FCR_FCMD_EWPL                    (EEFC_FCR_FCMD_EWPL_Val << EEFC_FCR_FCMD_Pos)        /* (EEFC_FCR) Erase page and write page then lock Position */
#define EEFC_FCR_FCMD_EA                      (EEFC_FCR_FCMD_EA_Val << EEFC_FCR_FCMD_Pos)          /* (EEFC_FCR) Erase all Position */
#define EEFC_FCR_FCMD_EPA                     (EEFC_FCR_FCMD_EPA_Val << EEFC_FCR_FCMD_Pos)         /* (EEFC_FCR) Erase pages Position */
#define EEFC_FCR_FCMD_SLB                     (EEFC_FCR_FCMD_SLB_Val << EEFC_FCR_FCMD_Pos)         /* (EEFC_FCR) Set lock bit Position */
#define EEFC_FCR_FCMD_CLB                     (EEFC_FCR_FCMD_CLB_Val << EEFC_FCR_FCMD_Pos)         /* (EEFC_FCR) Clear lock bit Position */
#define EEFC_FCR_FCMD_GLB                     (EEFC_FCR_FCMD_GLB_Val << EEFC_FCR_FCMD_Pos)         /* (EEFC_FCR) Get lock bit Position */
#define EEFC_FCR_FCMD_SGPB                    (EEFC_FCR_FCMD_SGPB_Val << EEFC_FCR_FCMD_Pos)        /* (EEFC_FCR) Set GPNVM bit Position */
#define EEFC_FCR_FCMD_CGPB                    (EEFC_FCR_FCMD_CGPB_Val << EEFC_FCR_FCMD_Pos)        /* (EEFC_FCR) Clear GPNVM bit Position */
#define EEFC_FCR_FCMD_GGPB                    (EEFC_FCR_FCMD_GGPB_Val << EEFC_FCR_FCMD_Pos)        /* (EEFC_FCR) Get GPNVM bit Position */
#define EEFC_FCR_FCMD_STUI                    (EEFC_FCR_FCMD_STUI_Val << EEFC_FCR_FCMD_Pos)        /* (EEFC_FCR) Start read unique identifier Position */
#define EEFC_FCR_FCMD_SPUI                    (EEFC_FCR_FCMD_SPUI_Val << EEFC_FCR_FCMD_Pos)        /* (EEFC_FCR) Stop read unique identifier Position */
#define EEFC_FCR_FCMD_GCALB                   (EEFC_FCR_FCMD_GCALB_Val << EEFC_FCR_FCMD_Pos)       /* (EEFC_FCR) Get CALIB bit Position */
#define EEFC_FCR_FCMD_ES                      (EEFC_FCR_FCMD_ES_Val << EEFC_FCR_FCMD_Pos)          /* (EEFC_FCR) Erase sector Position */
#define EEFC_FCR_FCMD_WUS                     (EEFC_FCR_FCMD_WUS_Val << EEFC_FCR_FCMD_Pos)         /* (EEFC_FCR) Write user signature Position */
#define EEFC_FCR_FCMD_EUS                     (EEFC_FCR_FCMD_EUS_Val << EEFC_FCR_FCMD_Pos)         /* (EEFC_FCR) Erase user signature Position */
#define EEFC_FCR_FCMD_STUS                    (EEFC_FCR_FCMD_STUS_Val << EEFC_FCR_FCMD_Pos)        /* (EEFC_FCR) Start read user signature Position */
#define EEFC_FCR_FCMD_SPUS                    (EEFC_FCR_FCMD_SPUS_Val << EEFC_FCR_FCMD_Pos)        /* (EEFC_FCR) Stop read user signature Position */
#define EEFC_FCR_FARG_Pos                     _UINT32_(8)                                          /* (EEFC_FCR) Flash Command Argument Position */
#define EEFC_FCR_FARG_Msk                     (_UINT32_(0xFFFF) << EEFC_FCR_FARG_Pos)              /* (EEFC_FCR) Flash Command Argument Mask */
#define EEFC_FCR_FARG(value)                  (EEFC_FCR_FARG_Msk & (_UINT32_(value) << EEFC_FCR_FARG_Pos)) /* Assignment of value for FARG in the EEFC_FCR register */
#define EEFC_FCR_FKEY_Pos                     _UINT32_(24)                                         /* (EEFC_FCR) Flash Writing Protection Key Position */
#define EEFC_FCR_FKEY_Msk                     (_UINT32_(0xFF) << EEFC_FCR_FKEY_Pos)                /* (EEFC_FCR) Flash Writing Protection Key Mask */
#define EEFC_FCR_FKEY(value)                  (EEFC_FCR_FKEY_Msk & (_UINT32_(value) << EEFC_FCR_FKEY_Pos)) /* Assignment of value for FKEY in the EEFC_FCR register */
#define   EEFC_FCR_FKEY_PASSWD_Val            _UINT32_(0x5A)                                       /* (EEFC_FCR) The 0x5A value enables the command defined by the bits of the register. If the field is written with a different value, the write is not performed and no action is started.  */
#define EEFC_FCR_FKEY_PASSWD                  (EEFC_FCR_FKEY_PASSWD_Val << EEFC_FCR_FKEY_Pos)      /* (EEFC_FCR) The 0x5A value enables the command defined by the bits of the register. If the field is written with a different value, the write is not performed and no action is started. Position */
#define EEFC_FCR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (EEFC_FCR) Register Mask  */


/* -------- EEFC_FSR : (EFC Offset: 0x08) ( R/ 32) EEFC Flash Status Register -------- */
#define EEFC_FSR_FRDY_Pos                     _UINT32_(0)                                          /* (EEFC_FSR) Flash Ready Status (cleared when Flash is busy) Position */
#define EEFC_FSR_FRDY_Msk                     (_UINT32_(0x1) << EEFC_FSR_FRDY_Pos)                 /* (EEFC_FSR) Flash Ready Status (cleared when Flash is busy) Mask */
#define EEFC_FSR_FRDY(value)                  (EEFC_FSR_FRDY_Msk & (_UINT32_(value) << EEFC_FSR_FRDY_Pos)) /* Assignment of value for FRDY in the EEFC_FSR register */
#define EEFC_FSR_FCMDE_Pos                    _UINT32_(1)                                          /* (EEFC_FSR) Flash Command Error Status (cleared on read or by writing EEFC_FCR) Position */
#define EEFC_FSR_FCMDE_Msk                    (_UINT32_(0x1) << EEFC_FSR_FCMDE_Pos)                /* (EEFC_FSR) Flash Command Error Status (cleared on read or by writing EEFC_FCR) Mask */
#define EEFC_FSR_FCMDE(value)                 (EEFC_FSR_FCMDE_Msk & (_UINT32_(value) << EEFC_FSR_FCMDE_Pos)) /* Assignment of value for FCMDE in the EEFC_FSR register */
#define EEFC_FSR_FLOCKE_Pos                   _UINT32_(2)                                          /* (EEFC_FSR) Flash Lock Error Status (cleared on read) Position */
#define EEFC_FSR_FLOCKE_Msk                   (_UINT32_(0x1) << EEFC_FSR_FLOCKE_Pos)               /* (EEFC_FSR) Flash Lock Error Status (cleared on read) Mask */
#define EEFC_FSR_FLOCKE(value)                (EEFC_FSR_FLOCKE_Msk & (_UINT32_(value) << EEFC_FSR_FLOCKE_Pos)) /* Assignment of value for FLOCKE in the EEFC_FSR register */
#define EEFC_FSR_FLERR_Pos                    _UINT32_(3)                                          /* (EEFC_FSR) Flash Error Status (cleared when a programming operation starts) Position */
#define EEFC_FSR_FLERR_Msk                    (_UINT32_(0x1) << EEFC_FSR_FLERR_Pos)                /* (EEFC_FSR) Flash Error Status (cleared when a programming operation starts) Mask */
#define EEFC_FSR_FLERR(value)                 (EEFC_FSR_FLERR_Msk & (_UINT32_(value) << EEFC_FSR_FLERR_Pos)) /* Assignment of value for FLERR in the EEFC_FSR register */
#define EEFC_FSR_UECCELSB_Pos                 _UINT32_(16)                                         /* (EEFC_FSR) Unique ECC Error on LSB Part of the Memory Flash Data Bus (cleared on read) Position */
#define EEFC_FSR_UECCELSB_Msk                 (_UINT32_(0x1) << EEFC_FSR_UECCELSB_Pos)             /* (EEFC_FSR) Unique ECC Error on LSB Part of the Memory Flash Data Bus (cleared on read) Mask */
#define EEFC_FSR_UECCELSB(value)              (EEFC_FSR_UECCELSB_Msk & (_UINT32_(value) << EEFC_FSR_UECCELSB_Pos)) /* Assignment of value for UECCELSB in the EEFC_FSR register */
#define EEFC_FSR_MECCELSB_Pos                 _UINT32_(17)                                         /* (EEFC_FSR) Multiple ECC Error on LSB Part of the Memory Flash Data Bus (cleared on read) Position */
#define EEFC_FSR_MECCELSB_Msk                 (_UINT32_(0x1) << EEFC_FSR_MECCELSB_Pos)             /* (EEFC_FSR) Multiple ECC Error on LSB Part of the Memory Flash Data Bus (cleared on read) Mask */
#define EEFC_FSR_MECCELSB(value)              (EEFC_FSR_MECCELSB_Msk & (_UINT32_(value) << EEFC_FSR_MECCELSB_Pos)) /* Assignment of value for MECCELSB in the EEFC_FSR register */
#define EEFC_FSR_UECCEMSB_Pos                 _UINT32_(18)                                         /* (EEFC_FSR) Unique ECC Error on MSB Part of the Memory Flash Data Bus (cleared on read) Position */
#define EEFC_FSR_UECCEMSB_Msk                 (_UINT32_(0x1) << EEFC_FSR_UECCEMSB_Pos)             /* (EEFC_FSR) Unique ECC Error on MSB Part of the Memory Flash Data Bus (cleared on read) Mask */
#define EEFC_FSR_UECCEMSB(value)              (EEFC_FSR_UECCEMSB_Msk & (_UINT32_(value) << EEFC_FSR_UECCEMSB_Pos)) /* Assignment of value for UECCEMSB in the EEFC_FSR register */
#define EEFC_FSR_MECCEMSB_Pos                 _UINT32_(19)                                         /* (EEFC_FSR) Multiple ECC Error on MSB Part of the Memory Flash Data Bus (cleared on read) Position */
#define EEFC_FSR_MECCEMSB_Msk                 (_UINT32_(0x1) << EEFC_FSR_MECCEMSB_Pos)             /* (EEFC_FSR) Multiple ECC Error on MSB Part of the Memory Flash Data Bus (cleared on read) Mask */
#define EEFC_FSR_MECCEMSB(value)              (EEFC_FSR_MECCEMSB_Msk & (_UINT32_(value) << EEFC_FSR_MECCEMSB_Pos)) /* Assignment of value for MECCEMSB in the EEFC_FSR register */
#define EEFC_FSR_Msk                          _UINT32_(0x000F000F)                                 /* (EEFC_FSR) Register Mask  */


/* -------- EEFC_FRR : (EFC Offset: 0x0C) ( R/ 32) EEFC Flash Result Register -------- */
#define EEFC_FRR_FVALUE_Pos                   _UINT32_(0)                                          /* (EEFC_FRR) Flash Result Value Position */
#define EEFC_FRR_FVALUE_Msk                   (_UINT32_(0xFFFFFFFF) << EEFC_FRR_FVALUE_Pos)        /* (EEFC_FRR) Flash Result Value Mask */
#define EEFC_FRR_FVALUE(value)                (EEFC_FRR_FVALUE_Msk & (_UINT32_(value) << EEFC_FRR_FVALUE_Pos)) /* Assignment of value for FVALUE in the EEFC_FRR register */
#define EEFC_FRR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (EEFC_FRR) Register Mask  */


/* -------- EEFC_WPMR : (EFC Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define EEFC_WPMR_WPEN_Pos                    _UINT32_(0)                                          /* (EEFC_WPMR) Write Protection Enable Position */
#define EEFC_WPMR_WPEN_Msk                    (_UINT32_(0x1) << EEFC_WPMR_WPEN_Pos)                /* (EEFC_WPMR) Write Protection Enable Mask */
#define EEFC_WPMR_WPEN(value)                 (EEFC_WPMR_WPEN_Msk & (_UINT32_(value) << EEFC_WPMR_WPEN_Pos)) /* Assignment of value for WPEN in the EEFC_WPMR register */
#define EEFC_WPMR_WPKEY_Pos                   _UINT32_(8)                                          /* (EEFC_WPMR) Write Protection Key Position */
#define EEFC_WPMR_WPKEY_Msk                   (_UINT32_(0xFFFFFF) << EEFC_WPMR_WPKEY_Pos)          /* (EEFC_WPMR) Write Protection Key Mask */
#define EEFC_WPMR_WPKEY(value)                (EEFC_WPMR_WPKEY_Msk & (_UINT32_(value) << EEFC_WPMR_WPKEY_Pos)) /* Assignment of value for WPKEY in the EEFC_WPMR register */
#define   EEFC_WPMR_WPKEY_PASSWD_Val          _UINT32_(0x454643)                                   /* (EEFC_WPMR) Writing any other value in this field aborts the write operation.Always reads as 0.  */
#define EEFC_WPMR_WPKEY_PASSWD                (EEFC_WPMR_WPKEY_PASSWD_Val << EEFC_WPMR_WPKEY_Pos)  /* (EEFC_WPMR) Writing any other value in this field aborts the write operation.Always reads as 0. Position */
#define EEFC_WPMR_Msk                         _UINT32_(0xFFFFFF01)                                 /* (EEFC_WPMR) Register Mask  */


/* EFC register offsets definitions */
#define EEFC_FMR_REG_OFST              _UINT32_(0x00)      /* (EEFC_FMR) EEFC Flash Mode Register Offset */
#define EEFC_FCR_REG_OFST              _UINT32_(0x04)      /* (EEFC_FCR) EEFC Flash Command Register Offset */
#define EEFC_FSR_REG_OFST              _UINT32_(0x08)      /* (EEFC_FSR) EEFC Flash Status Register Offset */
#define EEFC_FRR_REG_OFST              _UINT32_(0x0C)      /* (EEFC_FRR) EEFC Flash Result Register Offset */
#define EEFC_WPMR_REG_OFST             _UINT32_(0xE4)      /* (EEFC_WPMR) Write Protection Mode Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* EFC register API structure */
typedef struct
{
  __IO  uint32_t                       EEFC_FMR;           /* Offset: 0x00 (R/W  32) EEFC Flash Mode Register */
  __O   uint32_t                       EEFC_FCR;           /* Offset: 0x04 ( /W  32) EEFC Flash Command Register */
  __I   uint32_t                       EEFC_FSR;           /* Offset: 0x08 (R/   32) EEFC Flash Status Register */
  __I   uint32_t                       EEFC_FRR;           /* Offset: 0x0C (R/   32) EEFC Flash Result Register */
  __I   uint8_t                        Reserved1[0xD4];
  __IO  uint32_t                       EEFC_WPMR;          /* Offset: 0xE4 (R/W  32) Write Protection Mode Register */
} efc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA70_EFC_COMPONENT_H_ */
