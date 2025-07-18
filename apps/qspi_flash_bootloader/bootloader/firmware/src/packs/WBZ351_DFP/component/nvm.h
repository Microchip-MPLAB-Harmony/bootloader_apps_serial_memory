/*
 * Component description for NVM
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

/*  file generated from device description file (ATDF) version 2025-02-18T06:25:25Z  */
#ifndef _WBZ35_NVM_COMPONENT_H_
#define _WBZ35_NVM_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR NVM                       */
/* ************************************************************************** */

/* -------- NVM_NVMCON : (NVM Offset: 0x00) (R/W 32)  -------- */
#define NVM_NVMCON_RESETVALUE                 _UINT32_(0x00)                                       /*  (NVM_NVMCON)   Reset Value */

#define NVM_NVMCON_NVMOP_Pos                  _UINT32_(0)                                          /* (NVM_NVMCON)  Position */
#define NVM_NVMCON_NVMOP_Msk                  (_UINT32_(0xF) << NVM_NVMCON_NVMOP_Pos)              /* (NVM_NVMCON)  Mask */
#define NVM_NVMCON_NVMOP(value)               (NVM_NVMCON_NVMOP_Msk & (_UINT32_(value) << NVM_NVMCON_NVMOP_Pos)) /* Assignment of value for NVMOP in the NVM_NVMCON register */
#define NVM_NVMCON_LVDERR_Pos                 _UINT32_(12)                                         /* (NVM_NVMCON)  Position */
#define NVM_NVMCON_LVDERR_Msk                 (_UINT32_(0x1) << NVM_NVMCON_LVDERR_Pos)             /* (NVM_NVMCON)  Mask */
#define NVM_NVMCON_LVDERR(value)              (NVM_NVMCON_LVDERR_Msk & (_UINT32_(value) << NVM_NVMCON_LVDERR_Pos)) /* Assignment of value for LVDERR in the NVM_NVMCON register */
#define NVM_NVMCON_WRERR_Pos                  _UINT32_(13)                                         /* (NVM_NVMCON)  Position */
#define NVM_NVMCON_WRERR_Msk                  (_UINT32_(0x1) << NVM_NVMCON_WRERR_Pos)              /* (NVM_NVMCON)  Mask */
#define NVM_NVMCON_WRERR(value)               (NVM_NVMCON_WRERR_Msk & (_UINT32_(value) << NVM_NVMCON_WRERR_Pos)) /* Assignment of value for WRERR in the NVM_NVMCON register */
#define NVM_NVMCON_WREN_Pos                   _UINT32_(14)                                         /* (NVM_NVMCON)  Position */
#define NVM_NVMCON_WREN_Msk                   (_UINT32_(0x1) << NVM_NVMCON_WREN_Pos)               /* (NVM_NVMCON)  Mask */
#define NVM_NVMCON_WREN(value)                (NVM_NVMCON_WREN_Msk & (_UINT32_(value) << NVM_NVMCON_WREN_Pos)) /* Assignment of value for WREN in the NVM_NVMCON register */
#define NVM_NVMCON_WR_Pos                     _UINT32_(15)                                         /* (NVM_NVMCON)  Position */
#define NVM_NVMCON_WR_Msk                     (_UINT32_(0x1) << NVM_NVMCON_WR_Pos)                 /* (NVM_NVMCON)  Mask */
#define NVM_NVMCON_WR(value)                  (NVM_NVMCON_WR_Msk & (_UINT32_(value) << NVM_NVMCON_WR_Pos)) /* Assignment of value for WR in the NVM_NVMCON register */
#define NVM_NVMCON_Msk                        _UINT32_(0x0000F00F)                                 /* (NVM_NVMCON) Register Mask  */


/* -------- NVM_NVMCONCLR : (NVM Offset: 0x04) (R/W 32)  -------- */
#define NVM_NVMCONCLR_RESETVALUE              _UINT32_(0x00)                                       /*  (NVM_NVMCONCLR)   Reset Value */

#define NVM_NVMCONCLR_Msk                     _UINT32_(0x00000000)                                 /* (NVM_NVMCONCLR) Register Mask  */


/* -------- NVM_NVMCONSET : (NVM Offset: 0x08) (R/W 32)  -------- */
#define NVM_NVMCONSET_RESETVALUE              _UINT32_(0x00)                                       /*  (NVM_NVMCONSET)   Reset Value */

#define NVM_NVMCONSET_Msk                     _UINT32_(0x00000000)                                 /* (NVM_NVMCONSET) Register Mask  */


/* -------- NVM_NVMCONINV : (NVM Offset: 0x0C) (R/W 32)  -------- */
#define NVM_NVMCONINV_RESETVALUE              _UINT32_(0x00)                                       /*  (NVM_NVMCONINV)   Reset Value */

#define NVM_NVMCONINV_Msk                     _UINT32_(0x00000000)                                 /* (NVM_NVMCONINV) Register Mask  */


/* -------- NVM_NVMCON2 : (NVM Offset: 0x10) (R/W 32)  -------- */
#define NVM_NVMCON2_RESETVALUE                _UINT32_(0x11F4000)                                  /*  (NVM_NVMCON2)   Reset Value */

#define NVM_NVMCON2_NVMPREPG_Pos              _UINT32_(0)                                          /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_NVMPREPG_Msk              (_UINT32_(0x1) << NVM_NVMCON2_NVMPREPG_Pos)          /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_NVMPREPG(value)           (NVM_NVMCON2_NVMPREPG_Msk & (_UINT32_(value) << NVM_NVMCON2_NVMPREPG_Pos)) /* Assignment of value for NVMPREPG in the NVM_NVMCON2 register */
#define NVM_NVMCON2_RETRY_Pos                 _UINT32_(8)                                          /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_RETRY_Msk                 (_UINT32_(0x3) << NVM_NVMCON2_RETRY_Pos)             /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_RETRY(value)              (NVM_NVMCON2_RETRY_Msk & (_UINT32_(value) << NVM_NVMCON2_RETRY_Pos)) /* Assignment of value for RETRY in the NVM_NVMCON2 register */
#define NVM_NVMCON2_VREAD1_Pos                _UINT32_(12)                                         /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_VREAD1_Msk                (_UINT32_(0x1) << NVM_NVMCON2_VREAD1_Pos)            /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_VREAD1(value)             (NVM_NVMCON2_VREAD1_Msk & (_UINT32_(value) << NVM_NVMCON2_VREAD1_Pos)) /* Assignment of value for VREAD1 in the NVM_NVMCON2 register */
#define NVM_NVMCON2_CREAD1_Pos                _UINT32_(13)                                         /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_CREAD1_Msk                (_UINT32_(0x1) << NVM_NVMCON2_CREAD1_Pos)            /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_CREAD1(value)             (NVM_NVMCON2_CREAD1_Msk & (_UINT32_(value) << NVM_NVMCON2_CREAD1_Pos)) /* Assignment of value for CREAD1 in the NVM_NVMCON2 register */
#define NVM_NVMCON2_TEMP_Pos                  _UINT32_(14)                                         /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_TEMP_Msk                  (_UINT32_(0x1) << NVM_NVMCON2_TEMP_Pos)              /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_TEMP(value)               (NVM_NVMCON2_TEMP_Msk & (_UINT32_(value) << NVM_NVMCON2_TEMP_Pos)) /* Assignment of value for TEMP in the NVM_NVMCON2 register */
#define NVM_NVMCON2_WS_Pos                    _UINT32_(16)                                         /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_WS_Msk                    (_UINT32_(0x1F) << NVM_NVMCON2_WS_Pos)               /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_WS(value)                 (NVM_NVMCON2_WS_Msk & (_UINT32_(value) << NVM_NVMCON2_WS_Pos)) /* Assignment of value for WS in the NVM_NVMCON2 register */
#define NVM_NVMCON2_SLEEP_Pos                 _UINT32_(24)                                         /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_SLEEP_Msk                 (_UINT32_(0x1) << NVM_NVMCON2_SLEEP_Pos)             /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_SLEEP(value)              (NVM_NVMCON2_SLEEP_Msk & (_UINT32_(value) << NVM_NVMCON2_SLEEP_Pos)) /* Assignment of value for SLEEP in the NVM_NVMCON2 register */
#define NVM_NVMCON2_ERS_Pos                   _UINT32_(28)                                         /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_ERS_Msk                   (_UINT32_(0xF) << NVM_NVMCON2_ERS_Pos)               /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_ERS(value)                (NVM_NVMCON2_ERS_Msk & (_UINT32_(value) << NVM_NVMCON2_ERS_Pos)) /* Assignment of value for ERS in the NVM_NVMCON2 register */
#define NVM_NVMCON2_Msk                       _UINT32_(0xF11F7301)                                 /* (NVM_NVMCON2) Register Mask  */

#define NVM_NVMCON2_VREAD_Pos                 _UINT32_(12)                                         /* (NVM_NVMCON2 Position)  */
#define NVM_NVMCON2_VREAD_Msk                 (_UINT32_(0x1) << NVM_NVMCON2_VREAD_Pos)             /* (NVM_NVMCON2 Mask) VREAD */
#define NVM_NVMCON2_VREAD(value)              (NVM_NVMCON2_VREAD_Msk & (_UINT32_(value) << NVM_NVMCON2_VREAD_Pos)) 
#define NVM_NVMCON2_CREAD_Pos                 _UINT32_(13)                                         /* (NVM_NVMCON2 Position)  */
#define NVM_NVMCON2_CREAD_Msk                 (_UINT32_(0x1) << NVM_NVMCON2_CREAD_Pos)             /* (NVM_NVMCON2 Mask) CREAD */
#define NVM_NVMCON2_CREAD(value)              (NVM_NVMCON2_CREAD_Msk & (_UINT32_(value) << NVM_NVMCON2_CREAD_Pos)) 

/* -------- NVM_NVMCON2CLR : (NVM Offset: 0x14) (R/W 32)  -------- */
#define NVM_NVMCON2CLR_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMCON2CLR)   Reset Value */

#define NVM_NVMCON2CLR_Msk                    _UINT32_(0x00000000)                                 /* (NVM_NVMCON2CLR) Register Mask  */


/* -------- NVM_NVMCON2SET : (NVM Offset: 0x18) (R/W 32)  -------- */
#define NVM_NVMCON2SET_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMCON2SET)   Reset Value */

#define NVM_NVMCON2SET_Msk                    _UINT32_(0x00000000)                                 /* (NVM_NVMCON2SET) Register Mask  */


/* -------- NVM_NVMCON2INV : (NVM Offset: 0x1C) (R/W 32)  -------- */
#define NVM_NVMCON2INV_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMCON2INV)   Reset Value */

#define NVM_NVMCON2INV_Msk                    _UINT32_(0x00000000)                                 /* (NVM_NVMCON2INV) Register Mask  */


/* -------- NVM_NVMKEY : (NVM Offset: 0x20) (R/W 32)  -------- */
#define NVM_NVMKEY_RESETVALUE                 _UINT32_(0x00)                                       /*  (NVM_NVMKEY)   Reset Value */

#define NVM_NVMKEY_NVMKEY_Pos                 _UINT32_(0)                                          /* (NVM_NVMKEY)  Position */
#define NVM_NVMKEY_NVMKEY_Msk                 (_UINT32_(0xFFFFFFFF) << NVM_NVMKEY_NVMKEY_Pos)      /* (NVM_NVMKEY)  Mask */
#define NVM_NVMKEY_NVMKEY(value)              (NVM_NVMKEY_NVMKEY_Msk & (_UINT32_(value) << NVM_NVMKEY_NVMKEY_Pos)) /* Assignment of value for NVMKEY in the NVM_NVMKEY register */
#define NVM_NVMKEY_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMKEY) Register Mask  */


/* -------- NVM_NVMADDR : (NVM Offset: 0x30) (R/W 32)  -------- */
#define NVM_NVMADDR_RESETVALUE                _UINT32_(0x00)                                       /*  (NVM_NVMADDR)   Reset Value */

#define NVM_NVMADDR_NVMADDR_Pos               _UINT32_(0)                                          /* (NVM_NVMADDR)  Position */
#define NVM_NVMADDR_NVMADDR_Msk               (_UINT32_(0xFFFFFFFF) << NVM_NVMADDR_NVMADDR_Pos)    /* (NVM_NVMADDR)  Mask */
#define NVM_NVMADDR_NVMADDR(value)            (NVM_NVMADDR_NVMADDR_Msk & (_UINT32_(value) << NVM_NVMADDR_NVMADDR_Pos)) /* Assignment of value for NVMADDR in the NVM_NVMADDR register */
#define NVM_NVMADDR_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMADDR) Register Mask  */


/* -------- NVM_NVMDATA0 : (NVM Offset: 0x40) (R/W 32)  -------- */
#define NVM_NVMDATA0_RESETVALUE               _UINT32_(0x00)                                       /*  (NVM_NVMDATA0)   Reset Value */

#define NVM_NVMDATA0_NVMDATA0_Pos             _UINT32_(0)                                          /* (NVM_NVMDATA0)  Position */
#define NVM_NVMDATA0_NVMDATA0_Msk             (_UINT32_(0xFFFFFFFF) << NVM_NVMDATA0_NVMDATA0_Pos)  /* (NVM_NVMDATA0)  Mask */
#define NVM_NVMDATA0_NVMDATA0(value)          (NVM_NVMDATA0_NVMDATA0_Msk & (_UINT32_(value) << NVM_NVMDATA0_NVMDATA0_Pos)) /* Assignment of value for NVMDATA0 in the NVM_NVMDATA0 register */
#define NVM_NVMDATA0_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMDATA0) Register Mask  */


/* -------- NVM_NVMDATA1 : (NVM Offset: 0x50) (R/W 32)  -------- */
#define NVM_NVMDATA1_RESETVALUE               _UINT32_(0x00)                                       /*  (NVM_NVMDATA1)   Reset Value */

#define NVM_NVMDATA1_NVMDATA1_Pos             _UINT32_(0)                                          /* (NVM_NVMDATA1)  Position */
#define NVM_NVMDATA1_NVMDATA1_Msk             (_UINT32_(0xFFFFFFFF) << NVM_NVMDATA1_NVMDATA1_Pos)  /* (NVM_NVMDATA1)  Mask */
#define NVM_NVMDATA1_NVMDATA1(value)          (NVM_NVMDATA1_NVMDATA1_Msk & (_UINT32_(value) << NVM_NVMDATA1_NVMDATA1_Pos)) /* Assignment of value for NVMDATA1 in the NVM_NVMDATA1 register */
#define NVM_NVMDATA1_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMDATA1) Register Mask  */


/* -------- NVM_NVMDATA2 : (NVM Offset: 0x60) (R/W 32)  -------- */
#define NVM_NVMDATA2_RESETVALUE               _UINT32_(0x00)                                       /*  (NVM_NVMDATA2)   Reset Value */

#define NVM_NVMDATA2_NVMDATA2_Pos             _UINT32_(0)                                          /* (NVM_NVMDATA2)  Position */
#define NVM_NVMDATA2_NVMDATA2_Msk             (_UINT32_(0xFFFFFFFF) << NVM_NVMDATA2_NVMDATA2_Pos)  /* (NVM_NVMDATA2)  Mask */
#define NVM_NVMDATA2_NVMDATA2(value)          (NVM_NVMDATA2_NVMDATA2_Msk & (_UINT32_(value) << NVM_NVMDATA2_NVMDATA2_Pos)) /* Assignment of value for NVMDATA2 in the NVM_NVMDATA2 register */
#define NVM_NVMDATA2_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMDATA2) Register Mask  */


/* -------- NVM_NVMDATA3 : (NVM Offset: 0x70) (R/W 32)  -------- */
#define NVM_NVMDATA3_RESETVALUE               _UINT32_(0x00)                                       /*  (NVM_NVMDATA3)   Reset Value */

#define NVM_NVMDATA3_NVMDATA3_Pos             _UINT32_(0)                                          /* (NVM_NVMDATA3)  Position */
#define NVM_NVMDATA3_NVMDATA3_Msk             (_UINT32_(0xFFFFFFFF) << NVM_NVMDATA3_NVMDATA3_Pos)  /* (NVM_NVMDATA3)  Mask */
#define NVM_NVMDATA3_NVMDATA3(value)          (NVM_NVMDATA3_NVMDATA3_Msk & (_UINT32_(value) << NVM_NVMDATA3_NVMDATA3_Pos)) /* Assignment of value for NVMDATA3 in the NVM_NVMDATA3 register */
#define NVM_NVMDATA3_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMDATA3) Register Mask  */


/* -------- NVM_NVMSRCADDR : (NVM Offset: 0xC0) (R/W 32)  -------- */
#define NVM_NVMSRCADDR_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMSRCADDR)   Reset Value */

#define NVM_NVMSRCADDR_NVMSRCADDR_Pos         _UINT32_(0)                                          /* (NVM_NVMSRCADDR)  Position */
#define NVM_NVMSRCADDR_NVMSRCADDR_Msk         (_UINT32_(0xFFFFFFFF) << NVM_NVMSRCADDR_NVMSRCADDR_Pos) /* (NVM_NVMSRCADDR)  Mask */
#define NVM_NVMSRCADDR_NVMSRCADDR(value)      (NVM_NVMSRCADDR_NVMSRCADDR_Msk & (_UINT32_(value) << NVM_NVMSRCADDR_NVMSRCADDR_Pos)) /* Assignment of value for NVMSRCADDR in the NVM_NVMSRCADDR register */
#define NVM_NVMSRCADDR_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMSRCADDR) Register Mask  */


/* -------- NVM_NVMPWPLT : (NVM Offset: 0xD0) (R/W 32)  -------- */
#define NVM_NVMPWPLT_RESETVALUE               _UINT32_(0x00)                                       /*  (NVM_NVMPWPLT)   Reset Value */

#define NVM_NVMPWPLT_PWPLT_Pos                _UINT32_(0)                                          /* (NVM_NVMPWPLT)  Position */
#define NVM_NVMPWPLT_PWPLT_Msk                (_UINT32_(0xFFFFFF) << NVM_NVMPWPLT_PWPLT_Pos)       /* (NVM_NVMPWPLT)  Mask */
#define NVM_NVMPWPLT_PWPLT(value)             (NVM_NVMPWPLT_PWPLT_Msk & (_UINT32_(value) << NVM_NVMPWPLT_PWPLT_Pos)) /* Assignment of value for PWPLT in the NVM_NVMPWPLT register */
#define NVM_NVMPWPLT_ULOCK_Pos                _UINT32_(31)                                         /* (NVM_NVMPWPLT)  Position */
#define NVM_NVMPWPLT_ULOCK_Msk                (_UINT32_(0x1) << NVM_NVMPWPLT_ULOCK_Pos)            /* (NVM_NVMPWPLT)  Mask */
#define NVM_NVMPWPLT_ULOCK(value)             (NVM_NVMPWPLT_ULOCK_Msk & (_UINT32_(value) << NVM_NVMPWPLT_ULOCK_Pos)) /* Assignment of value for ULOCK in the NVM_NVMPWPLT register */
#define NVM_NVMPWPLT_Msk                      _UINT32_(0x80FFFFFF)                                 /* (NVM_NVMPWPLT) Register Mask  */


/* -------- NVM_NVMPWPLTCLR : (NVM Offset: 0xD4) (R/W 32)  -------- */
#define NVM_NVMPWPLTCLR_RESETVALUE            _UINT32_(0x00)                                       /*  (NVM_NVMPWPLTCLR)   Reset Value */

#define NVM_NVMPWPLTCLR_Msk                   _UINT32_(0x00000000)                                 /* (NVM_NVMPWPLTCLR) Register Mask  */


/* -------- NVM_NVMPWPLTSET : (NVM Offset: 0xD8) (R/W 32)  -------- */
#define NVM_NVMPWPLTSET_RESETVALUE            _UINT32_(0x00)                                       /*  (NVM_NVMPWPLTSET)   Reset Value */

#define NVM_NVMPWPLTSET_Msk                   _UINT32_(0x00000000)                                 /* (NVM_NVMPWPLTSET) Register Mask  */


/* -------- NVM_NVMPWPLTINV : (NVM Offset: 0xDC) (R/W 32)  -------- */
#define NVM_NVMPWPLTINV_RESETVALUE            _UINT32_(0x00)                                       /*  (NVM_NVMPWPLTINV)   Reset Value */

#define NVM_NVMPWPLTINV_Msk                   _UINT32_(0x00000000)                                 /* (NVM_NVMPWPLTINV) Register Mask  */


/* -------- NVM_NVMPWPGTE : (NVM Offset: 0xE0) (R/W 32)  -------- */
#define NVM_NVMPWPGTE_RESETVALUE              _UINT32_(0x80FFFFFF)                                 /*  (NVM_NVMPWPGTE)   Reset Value */

#define NVM_NVMPWPGTE_PWPGTE_Pos              _UINT32_(0)                                          /* (NVM_NVMPWPGTE)  Position */
#define NVM_NVMPWPGTE_PWPGTE_Msk              (_UINT32_(0xFFFFFF) << NVM_NVMPWPGTE_PWPGTE_Pos)     /* (NVM_NVMPWPGTE)  Mask */
#define NVM_NVMPWPGTE_PWPGTE(value)           (NVM_NVMPWPGTE_PWPGTE_Msk & (_UINT32_(value) << NVM_NVMPWPGTE_PWPGTE_Pos)) /* Assignment of value for PWPGTE in the NVM_NVMPWPGTE register */
#define NVM_NVMPWPGTE_ULOCK_Pos               _UINT32_(31)                                         /* (NVM_NVMPWPGTE)  Position */
#define NVM_NVMPWPGTE_ULOCK_Msk               (_UINT32_(0x1) << NVM_NVMPWPGTE_ULOCK_Pos)           /* (NVM_NVMPWPGTE)  Mask */
#define NVM_NVMPWPGTE_ULOCK(value)            (NVM_NVMPWPGTE_ULOCK_Msk & (_UINT32_(value) << NVM_NVMPWPGTE_ULOCK_Pos)) /* Assignment of value for ULOCK in the NVM_NVMPWPGTE register */
#define NVM_NVMPWPGTE_Msk                     _UINT32_(0x80FFFFFF)                                 /* (NVM_NVMPWPGTE) Register Mask  */


/* -------- NVM_NVMPWPGTECLR : (NVM Offset: 0xE4) (R/W 32)  -------- */
#define NVM_NVMPWPGTECLR_RESETVALUE           _UINT32_(0x00)                                       /*  (NVM_NVMPWPGTECLR)   Reset Value */

#define NVM_NVMPWPGTECLR_Msk                  _UINT32_(0x00000000)                                 /* (NVM_NVMPWPGTECLR) Register Mask  */


/* -------- NVM_NVMPWPGTESET : (NVM Offset: 0xE8) (R/W 32)  -------- */
#define NVM_NVMPWPGTESET_RESETVALUE           _UINT32_(0x00)                                       /*  (NVM_NVMPWPGTESET)   Reset Value */

#define NVM_NVMPWPGTESET_Msk                  _UINT32_(0x00000000)                                 /* (NVM_NVMPWPGTESET) Register Mask  */


/* -------- NVM_NVMPWPGTEINV : (NVM Offset: 0xEC) (R/W 32)  -------- */
#define NVM_NVMPWPGTEINV_RESETVALUE           _UINT32_(0x00)                                       /*  (NVM_NVMPWPGTEINV)   Reset Value */

#define NVM_NVMPWPGTEINV_Msk                  _UINT32_(0x00000000)                                 /* (NVM_NVMPWPGTEINV) Register Mask  */


/* -------- NVM_NVMLBWP : (NVM Offset: 0xF0) (R/W 32)  -------- */
#define NVM_NVMLBWP_RESETVALUE                _UINT32_(0x80FFFFFF)                                 /*  (NVM_NVMLBWP)   Reset Value */

#define NVM_NVMLBWP_LBWP0_Pos                 _UINT32_(0)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP0_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP0_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP0(value)              (NVM_NVMLBWP_LBWP0_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP0_Pos)) /* Assignment of value for LBWP0 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP1_Pos                 _UINT32_(1)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP1_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP1_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP1(value)              (NVM_NVMLBWP_LBWP1_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP1_Pos)) /* Assignment of value for LBWP1 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP2_Pos                 _UINT32_(2)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP2_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP2_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP2(value)              (NVM_NVMLBWP_LBWP2_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP2_Pos)) /* Assignment of value for LBWP2 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP3_Pos                 _UINT32_(3)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP3_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP3_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP3(value)              (NVM_NVMLBWP_LBWP3_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP3_Pos)) /* Assignment of value for LBWP3 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP4_Pos                 _UINT32_(4)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP4_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP4_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP4(value)              (NVM_NVMLBWP_LBWP4_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP4_Pos)) /* Assignment of value for LBWP4 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP5_Pos                 _UINT32_(5)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP5_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP5_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP5(value)              (NVM_NVMLBWP_LBWP5_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP5_Pos)) /* Assignment of value for LBWP5 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP6_Pos                 _UINT32_(6)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP6_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP6_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP6(value)              (NVM_NVMLBWP_LBWP6_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP6_Pos)) /* Assignment of value for LBWP6 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP7_Pos                 _UINT32_(7)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP7_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP7_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP7(value)              (NVM_NVMLBWP_LBWP7_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP7_Pos)) /* Assignment of value for LBWP7 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP8_Pos                 _UINT32_(8)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP8_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP8_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP8(value)              (NVM_NVMLBWP_LBWP8_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP8_Pos)) /* Assignment of value for LBWP8 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP9_Pos                 _UINT32_(9)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP9_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP9_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP9(value)              (NVM_NVMLBWP_LBWP9_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP9_Pos)) /* Assignment of value for LBWP9 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP10_Pos                _UINT32_(10)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP10_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP10_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP10(value)             (NVM_NVMLBWP_LBWP10_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP10_Pos)) /* Assignment of value for LBWP10 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP11_Pos                _UINT32_(11)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP11_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP11_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP11(value)             (NVM_NVMLBWP_LBWP11_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP11_Pos)) /* Assignment of value for LBWP11 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP12_Pos                _UINT32_(12)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP12_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP12_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP12(value)             (NVM_NVMLBWP_LBWP12_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP12_Pos)) /* Assignment of value for LBWP12 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP13_Pos                _UINT32_(13)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP13_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP13_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP13(value)             (NVM_NVMLBWP_LBWP13_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP13_Pos)) /* Assignment of value for LBWP13 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP14_Pos                _UINT32_(14)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP14_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP14_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP14(value)             (NVM_NVMLBWP_LBWP14_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP14_Pos)) /* Assignment of value for LBWP14 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP15_Pos                _UINT32_(15)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP15_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP15_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP15(value)             (NVM_NVMLBWP_LBWP15_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP15_Pos)) /* Assignment of value for LBWP15 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP16_Pos                _UINT32_(16)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP16_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP16_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP16(value)             (NVM_NVMLBWP_LBWP16_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP16_Pos)) /* Assignment of value for LBWP16 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP17_Pos                _UINT32_(17)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP17_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP17_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP17(value)             (NVM_NVMLBWP_LBWP17_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP17_Pos)) /* Assignment of value for LBWP17 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP18_Pos                _UINT32_(18)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP18_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP18_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP18(value)             (NVM_NVMLBWP_LBWP18_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP18_Pos)) /* Assignment of value for LBWP18 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP19_Pos                _UINT32_(19)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP19_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP19_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP19(value)             (NVM_NVMLBWP_LBWP19_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP19_Pos)) /* Assignment of value for LBWP19 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP20_Pos                _UINT32_(20)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP20_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP20_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP20(value)             (NVM_NVMLBWP_LBWP20_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP20_Pos)) /* Assignment of value for LBWP20 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP21_Pos                _UINT32_(21)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP21_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP21_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP21(value)             (NVM_NVMLBWP_LBWP21_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP21_Pos)) /* Assignment of value for LBWP21 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP22_Pos                _UINT32_(22)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP22_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP22_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP22(value)             (NVM_NVMLBWP_LBWP22_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP22_Pos)) /* Assignment of value for LBWP22 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP23_Pos                _UINT32_(23)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP23_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP23_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP23(value)             (NVM_NVMLBWP_LBWP23_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP23_Pos)) /* Assignment of value for LBWP23 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_ULOCK_Pos                 _UINT32_(31)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_ULOCK_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_ULOCK_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_ULOCK(value)              (NVM_NVMLBWP_ULOCK_Msk & (_UINT32_(value) << NVM_NVMLBWP_ULOCK_Pos)) /* Assignment of value for ULOCK in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_Msk                       _UINT32_(0x80FFFFFF)                                 /* (NVM_NVMLBWP) Register Mask  */

#define NVM_NVMLBWP_LBWP_Pos                  _UINT32_(0)                                          /* (NVM_NVMLBWP Position)  */
#define NVM_NVMLBWP_LBWP_Msk                  (_UINT32_(0xFFFFFF) << NVM_NVMLBWP_LBWP_Pos)         /* (NVM_NVMLBWP Mask) LBWP */
#define NVM_NVMLBWP_LBWP(value)               (NVM_NVMLBWP_LBWP_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP_Pos)) 

/* -------- NVM_NVMLBWPCLR : (NVM Offset: 0xF4) (R/W 32)  -------- */
#define NVM_NVMLBWPCLR_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMLBWPCLR)   Reset Value */

#define NVM_NVMLBWPCLR_Msk                    _UINT32_(0x00000000)                                 /* (NVM_NVMLBWPCLR) Register Mask  */


/* -------- NVM_NVMLBWPSET : (NVM Offset: 0xF8) (R/W 32)  -------- */
#define NVM_NVMLBWPSET_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMLBWPSET)   Reset Value */

#define NVM_NVMLBWPSET_Msk                    _UINT32_(0x00000000)                                 /* (NVM_NVMLBWPSET) Register Mask  */


/* -------- NVM_NVMLBWPINV : (NVM Offset: 0xFC) (R/W 32)  -------- */
#define NVM_NVMLBWPINV_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMLBWPINV)   Reset Value */

#define NVM_NVMLBWPINV_Msk                    _UINT32_(0x00000000)                                 /* (NVM_NVMLBWPINV) Register Mask  */


/* NVM register offsets definitions */
#define NVM_NVMCON_REG_OFST            _UINT32_(0x00)      /* (NVM_NVMCON)  Offset */
#define NVM_NVMCONCLR_REG_OFST         _UINT32_(0x04)      /* (NVM_NVMCONCLR)  Offset */
#define NVM_NVMCONSET_REG_OFST         _UINT32_(0x08)      /* (NVM_NVMCONSET)  Offset */
#define NVM_NVMCONINV_REG_OFST         _UINT32_(0x0C)      /* (NVM_NVMCONINV)  Offset */
#define NVM_NVMCON2_REG_OFST           _UINT32_(0x10)      /* (NVM_NVMCON2)  Offset */
#define NVM_NVMCON2CLR_REG_OFST        _UINT32_(0x14)      /* (NVM_NVMCON2CLR)  Offset */
#define NVM_NVMCON2SET_REG_OFST        _UINT32_(0x18)      /* (NVM_NVMCON2SET)  Offset */
#define NVM_NVMCON2INV_REG_OFST        _UINT32_(0x1C)      /* (NVM_NVMCON2INV)  Offset */
#define NVM_NVMKEY_REG_OFST            _UINT32_(0x20)      /* (NVM_NVMKEY)  Offset */
#define NVM_NVMADDR_REG_OFST           _UINT32_(0x30)      /* (NVM_NVMADDR)  Offset */
#define NVM_NVMDATA0_REG_OFST          _UINT32_(0x40)      /* (NVM_NVMDATA0)  Offset */
#define NVM_NVMDATA1_REG_OFST          _UINT32_(0x50)      /* (NVM_NVMDATA1)  Offset */
#define NVM_NVMDATA2_REG_OFST          _UINT32_(0x60)      /* (NVM_NVMDATA2)  Offset */
#define NVM_NVMDATA3_REG_OFST          _UINT32_(0x70)      /* (NVM_NVMDATA3)  Offset */
#define NVM_NVMSRCADDR_REG_OFST        _UINT32_(0xC0)      /* (NVM_NVMSRCADDR)  Offset */
#define NVM_NVMPWPLT_REG_OFST          _UINT32_(0xD0)      /* (NVM_NVMPWPLT)  Offset */
#define NVM_NVMPWPLTCLR_REG_OFST       _UINT32_(0xD4)      /* (NVM_NVMPWPLTCLR)  Offset */
#define NVM_NVMPWPLTSET_REG_OFST       _UINT32_(0xD8)      /* (NVM_NVMPWPLTSET)  Offset */
#define NVM_NVMPWPLTINV_REG_OFST       _UINT32_(0xDC)      /* (NVM_NVMPWPLTINV)  Offset */
#define NVM_NVMPWPGTE_REG_OFST         _UINT32_(0xE0)      /* (NVM_NVMPWPGTE)  Offset */
#define NVM_NVMPWPGTECLR_REG_OFST      _UINT32_(0xE4)      /* (NVM_NVMPWPGTECLR)  Offset */
#define NVM_NVMPWPGTESET_REG_OFST      _UINT32_(0xE8)      /* (NVM_NVMPWPGTESET)  Offset */
#define NVM_NVMPWPGTEINV_REG_OFST      _UINT32_(0xEC)      /* (NVM_NVMPWPGTEINV)  Offset */
#define NVM_NVMLBWP_REG_OFST           _UINT32_(0xF0)      /* (NVM_NVMLBWP)  Offset */
#define NVM_NVMLBWPCLR_REG_OFST        _UINT32_(0xF4)      /* (NVM_NVMLBWPCLR)  Offset */
#define NVM_NVMLBWPSET_REG_OFST        _UINT32_(0xF8)      /* (NVM_NVMLBWPSET)  Offset */
#define NVM_NVMLBWPINV_REG_OFST        _UINT32_(0xFC)      /* (NVM_NVMLBWPINV)  Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* NVM register API structure */
typedef struct
{  /* flash controller */
  __IO  uint32_t                       NVM_NVMCON;         /* Offset: 0x00 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMCONCLR;      /* Offset: 0x04 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMCONSET;      /* Offset: 0x08 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMCONINV;      /* Offset: 0x0C (R/W  32)  */
  __IO  uint32_t                       NVM_NVMCON2;        /* Offset: 0x10 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMCON2CLR;     /* Offset: 0x14 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMCON2SET;     /* Offset: 0x18 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMCON2INV;     /* Offset: 0x1C (R/W  32)  */
  __IO  uint32_t                       NVM_NVMKEY;         /* Offset: 0x20 (R/W  32)  */
  __I   uint8_t                        Reserved1[0x0C];
  __IO  uint32_t                       NVM_NVMADDR;        /* Offset: 0x30 (R/W  32)  */
  __I   uint8_t                        Reserved2[0x0C];
  __IO  uint32_t                       NVM_NVMDATA0;       /* Offset: 0x40 (R/W  32)  */
  __I   uint8_t                        Reserved3[0x0C];
  __IO  uint32_t                       NVM_NVMDATA1;       /* Offset: 0x50 (R/W  32)  */
  __I   uint8_t                        Reserved4[0x0C];
  __IO  uint32_t                       NVM_NVMDATA2;       /* Offset: 0x60 (R/W  32)  */
  __I   uint8_t                        Reserved5[0x0C];
  __IO  uint32_t                       NVM_NVMDATA3;       /* Offset: 0x70 (R/W  32)  */
  __I   uint8_t                        Reserved6[0x4C];
  __IO  uint32_t                       NVM_NVMSRCADDR;     /* Offset: 0xC0 (R/W  32)  */
  __I   uint8_t                        Reserved7[0x0C];
  __IO  uint32_t                       NVM_NVMPWPLT;       /* Offset: 0xD0 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMPWPLTCLR;    /* Offset: 0xD4 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMPWPLTSET;    /* Offset: 0xD8 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMPWPLTINV;    /* Offset: 0xDC (R/W  32)  */
  __IO  uint32_t                       NVM_NVMPWPGTE;      /* Offset: 0xE0 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMPWPGTECLR;   /* Offset: 0xE4 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMPWPGTESET;   /* Offset: 0xE8 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMPWPGTEINV;   /* Offset: 0xEC (R/W  32)  */
  __IO  uint32_t                       NVM_NVMLBWP;        /* Offset: 0xF0 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMLBWPCLR;     /* Offset: 0xF4 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMLBWPSET;     /* Offset: 0xF8 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMLBWPINV;     /* Offset: 0xFC (R/W  32)  */
} nvm_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _WBZ35_NVM_COMPONENT_H_ */
