/*
 * Component description for CHIPID
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
#ifndef _PIC32CZCA70_CHIPID_COMPONENT_H_
#define _PIC32CZCA70_CHIPID_COMPONENT_H_

/* ************************************************************************** */
/*                     SOFTWARE API DEFINITION FOR CHIPID                     */
/* ************************************************************************** */

/* -------- CHIPID_CIDR : (CHIPID Offset: 0x00) ( R/ 32) Chip ID Register -------- */
#define CHIPID_CIDR_VERSION_Pos               _UINT32_(0)                                          /* (CHIPID_CIDR) Version of the Device Position */
#define CHIPID_CIDR_VERSION_Msk               (_UINT32_(0x1F) << CHIPID_CIDR_VERSION_Pos)          /* (CHIPID_CIDR) Version of the Device Mask */
#define CHIPID_CIDR_VERSION(value)            (CHIPID_CIDR_VERSION_Msk & (_UINT32_(value) << CHIPID_CIDR_VERSION_Pos)) /* Assignment of value for VERSION in the CHIPID_CIDR register */
#define CHIPID_CIDR_EPROC_Pos                 _UINT32_(5)                                          /* (CHIPID_CIDR) Embedded Processor Position */
#define CHIPID_CIDR_EPROC_Msk                 (_UINT32_(0x7) << CHIPID_CIDR_EPROC_Pos)             /* (CHIPID_CIDR) Embedded Processor Mask */
#define CHIPID_CIDR_EPROC(value)              (CHIPID_CIDR_EPROC_Msk & (_UINT32_(value) << CHIPID_CIDR_EPROC_Pos)) /* Assignment of value for EPROC in the CHIPID_CIDR register */
#define   CHIPID_CIDR_EPROC_SAMx7_Val         _UINT32_(0x0)                                        /* (CHIPID_CIDR) Cortex-M7  */
#define   CHIPID_CIDR_EPROC_ARM946ES_Val      _UINT32_(0x1)                                        /* (CHIPID_CIDR) ARM946ES  */
#define   CHIPID_CIDR_EPROC_ARM7TDMI_Val      _UINT32_(0x2)                                        /* (CHIPID_CIDR) ARM7TDMI  */
#define   CHIPID_CIDR_EPROC_CM3_Val           _UINT32_(0x3)                                        /* (CHIPID_CIDR) Cortex-M3  */
#define   CHIPID_CIDR_EPROC_ARM920T_Val       _UINT32_(0x4)                                        /* (CHIPID_CIDR) ARM920T  */
#define   CHIPID_CIDR_EPROC_ARM926EJS_Val     _UINT32_(0x5)                                        /* (CHIPID_CIDR) ARM926EJS  */
#define   CHIPID_CIDR_EPROC_CA5_Val           _UINT32_(0x6)                                        /* (CHIPID_CIDR) Cortex-A5  */
#define   CHIPID_CIDR_EPROC_CM4_Val           _UINT32_(0x7)                                        /* (CHIPID_CIDR) Cortex-M4  */
#define CHIPID_CIDR_EPROC_SAMx7               (CHIPID_CIDR_EPROC_SAMx7_Val << CHIPID_CIDR_EPROC_Pos) /* (CHIPID_CIDR) Cortex-M7 Position */
#define CHIPID_CIDR_EPROC_ARM946ES            (CHIPID_CIDR_EPROC_ARM946ES_Val << CHIPID_CIDR_EPROC_Pos) /* (CHIPID_CIDR) ARM946ES Position */
#define CHIPID_CIDR_EPROC_ARM7TDMI            (CHIPID_CIDR_EPROC_ARM7TDMI_Val << CHIPID_CIDR_EPROC_Pos) /* (CHIPID_CIDR) ARM7TDMI Position */
#define CHIPID_CIDR_EPROC_CM3                 (CHIPID_CIDR_EPROC_CM3_Val << CHIPID_CIDR_EPROC_Pos) /* (CHIPID_CIDR) Cortex-M3 Position */
#define CHIPID_CIDR_EPROC_ARM920T             (CHIPID_CIDR_EPROC_ARM920T_Val << CHIPID_CIDR_EPROC_Pos) /* (CHIPID_CIDR) ARM920T Position */
#define CHIPID_CIDR_EPROC_ARM926EJS           (CHIPID_CIDR_EPROC_ARM926EJS_Val << CHIPID_CIDR_EPROC_Pos) /* (CHIPID_CIDR) ARM926EJS Position */
#define CHIPID_CIDR_EPROC_CA5                 (CHIPID_CIDR_EPROC_CA5_Val << CHIPID_CIDR_EPROC_Pos) /* (CHIPID_CIDR) Cortex-A5 Position */
#define CHIPID_CIDR_EPROC_CM4                 (CHIPID_CIDR_EPROC_CM4_Val << CHIPID_CIDR_EPROC_Pos) /* (CHIPID_CIDR) Cortex-M4 Position */
#define CHIPID_CIDR_NVPSIZ_Pos                _UINT32_(8)                                          /* (CHIPID_CIDR) Nonvolatile Program Memory Size Position */
#define CHIPID_CIDR_NVPSIZ_Msk                (_UINT32_(0xF) << CHIPID_CIDR_NVPSIZ_Pos)            /* (CHIPID_CIDR) Nonvolatile Program Memory Size Mask */
#define CHIPID_CIDR_NVPSIZ(value)             (CHIPID_CIDR_NVPSIZ_Msk & (_UINT32_(value) << CHIPID_CIDR_NVPSIZ_Pos)) /* Assignment of value for NVPSIZ in the CHIPID_CIDR register */
#define   CHIPID_CIDR_NVPSIZ_NONE_Val         _UINT32_(0x0)                                        /* (CHIPID_CIDR) None  */
#define   CHIPID_CIDR_NVPSIZ_8K_Val           _UINT32_(0x1)                                        /* (CHIPID_CIDR) 8 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ_16K_Val          _UINT32_(0x2)                                        /* (CHIPID_CIDR) 16 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ_32K_Val          _UINT32_(0x3)                                        /* (CHIPID_CIDR) 32 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ_64K_Val          _UINT32_(0x5)                                        /* (CHIPID_CIDR) 64 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ_128K_Val         _UINT32_(0x7)                                        /* (CHIPID_CIDR) 128 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ_160K_Val         _UINT32_(0x8)                                        /* (CHIPID_CIDR) 160 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ_256K_Val         _UINT32_(0x9)                                        /* (CHIPID_CIDR) 256 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ_512K_Val         _UINT32_(0xA)                                        /* (CHIPID_CIDR) 512 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ_1024K_Val        _UINT32_(0xC)                                        /* (CHIPID_CIDR) 1024 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ_2048K_Val        _UINT32_(0xE)                                        /* (CHIPID_CIDR) 2048 Kbytes  */
#define CHIPID_CIDR_NVPSIZ_NONE               (CHIPID_CIDR_NVPSIZ_NONE_Val << CHIPID_CIDR_NVPSIZ_Pos) /* (CHIPID_CIDR) None Position */
#define CHIPID_CIDR_NVPSIZ_8K                 (CHIPID_CIDR_NVPSIZ_8K_Val << CHIPID_CIDR_NVPSIZ_Pos) /* (CHIPID_CIDR) 8 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ_16K                (CHIPID_CIDR_NVPSIZ_16K_Val << CHIPID_CIDR_NVPSIZ_Pos) /* (CHIPID_CIDR) 16 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ_32K                (CHIPID_CIDR_NVPSIZ_32K_Val << CHIPID_CIDR_NVPSIZ_Pos) /* (CHIPID_CIDR) 32 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ_64K                (CHIPID_CIDR_NVPSIZ_64K_Val << CHIPID_CIDR_NVPSIZ_Pos) /* (CHIPID_CIDR) 64 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ_128K               (CHIPID_CIDR_NVPSIZ_128K_Val << CHIPID_CIDR_NVPSIZ_Pos) /* (CHIPID_CIDR) 128 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ_160K               (CHIPID_CIDR_NVPSIZ_160K_Val << CHIPID_CIDR_NVPSIZ_Pos) /* (CHIPID_CIDR) 160 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ_256K               (CHIPID_CIDR_NVPSIZ_256K_Val << CHIPID_CIDR_NVPSIZ_Pos) /* (CHIPID_CIDR) 256 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ_512K               (CHIPID_CIDR_NVPSIZ_512K_Val << CHIPID_CIDR_NVPSIZ_Pos) /* (CHIPID_CIDR) 512 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ_1024K              (CHIPID_CIDR_NVPSIZ_1024K_Val << CHIPID_CIDR_NVPSIZ_Pos) /* (CHIPID_CIDR) 1024 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ_2048K              (CHIPID_CIDR_NVPSIZ_2048K_Val << CHIPID_CIDR_NVPSIZ_Pos) /* (CHIPID_CIDR) 2048 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ2_Pos               _UINT32_(12)                                         /* (CHIPID_CIDR) Second Nonvolatile Program Memory Size Position */
#define CHIPID_CIDR_NVPSIZ2_Msk               (_UINT32_(0xF) << CHIPID_CIDR_NVPSIZ2_Pos)           /* (CHIPID_CIDR) Second Nonvolatile Program Memory Size Mask */
#define CHIPID_CIDR_NVPSIZ2(value)            (CHIPID_CIDR_NVPSIZ2_Msk & (_UINT32_(value) << CHIPID_CIDR_NVPSIZ2_Pos)) /* Assignment of value for NVPSIZ2 in the CHIPID_CIDR register */
#define   CHIPID_CIDR_NVPSIZ2_NONE_Val        _UINT32_(0x0)                                        /* (CHIPID_CIDR) None  */
#define   CHIPID_CIDR_NVPSIZ2_8K_Val          _UINT32_(0x1)                                        /* (CHIPID_CIDR) 8 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ2_16K_Val         _UINT32_(0x2)                                        /* (CHIPID_CIDR) 16 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ2_32K_Val         _UINT32_(0x3)                                        /* (CHIPID_CIDR) 32 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ2_64K_Val         _UINT32_(0x5)                                        /* (CHIPID_CIDR) 64 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ2_128K_Val        _UINT32_(0x7)                                        /* (CHIPID_CIDR) 128 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ2_256K_Val        _UINT32_(0x9)                                        /* (CHIPID_CIDR) 256 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ2_512K_Val        _UINT32_(0xA)                                        /* (CHIPID_CIDR) 512 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ2_1024K_Val       _UINT32_(0xC)                                        /* (CHIPID_CIDR) 1024 Kbytes  */
#define   CHIPID_CIDR_NVPSIZ2_2048K_Val       _UINT32_(0xE)                                        /* (CHIPID_CIDR) 2048 Kbytes  */
#define CHIPID_CIDR_NVPSIZ2_NONE              (CHIPID_CIDR_NVPSIZ2_NONE_Val << CHIPID_CIDR_NVPSIZ2_Pos) /* (CHIPID_CIDR) None Position */
#define CHIPID_CIDR_NVPSIZ2_8K                (CHIPID_CIDR_NVPSIZ2_8K_Val << CHIPID_CIDR_NVPSIZ2_Pos) /* (CHIPID_CIDR) 8 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ2_16K               (CHIPID_CIDR_NVPSIZ2_16K_Val << CHIPID_CIDR_NVPSIZ2_Pos) /* (CHIPID_CIDR) 16 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ2_32K               (CHIPID_CIDR_NVPSIZ2_32K_Val << CHIPID_CIDR_NVPSIZ2_Pos) /* (CHIPID_CIDR) 32 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ2_64K               (CHIPID_CIDR_NVPSIZ2_64K_Val << CHIPID_CIDR_NVPSIZ2_Pos) /* (CHIPID_CIDR) 64 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ2_128K              (CHIPID_CIDR_NVPSIZ2_128K_Val << CHIPID_CIDR_NVPSIZ2_Pos) /* (CHIPID_CIDR) 128 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ2_256K              (CHIPID_CIDR_NVPSIZ2_256K_Val << CHIPID_CIDR_NVPSIZ2_Pos) /* (CHIPID_CIDR) 256 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ2_512K              (CHIPID_CIDR_NVPSIZ2_512K_Val << CHIPID_CIDR_NVPSIZ2_Pos) /* (CHIPID_CIDR) 512 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ2_1024K             (CHIPID_CIDR_NVPSIZ2_1024K_Val << CHIPID_CIDR_NVPSIZ2_Pos) /* (CHIPID_CIDR) 1024 Kbytes Position */
#define CHIPID_CIDR_NVPSIZ2_2048K             (CHIPID_CIDR_NVPSIZ2_2048K_Val << CHIPID_CIDR_NVPSIZ2_Pos) /* (CHIPID_CIDR) 2048 Kbytes Position */
#define CHIPID_CIDR_SRAMSIZ_Pos               _UINT32_(16)                                         /* (CHIPID_CIDR) Internal SRAM Size Position */
#define CHIPID_CIDR_SRAMSIZ_Msk               (_UINT32_(0xF) << CHIPID_CIDR_SRAMSIZ_Pos)           /* (CHIPID_CIDR) Internal SRAM Size Mask */
#define CHIPID_CIDR_SRAMSIZ(value)            (CHIPID_CIDR_SRAMSIZ_Msk & (_UINT32_(value) << CHIPID_CIDR_SRAMSIZ_Pos)) /* Assignment of value for SRAMSIZ in the CHIPID_CIDR register */
#define   CHIPID_CIDR_SRAMSIZ_48K_Val         _UINT32_(0x0)                                        /* (CHIPID_CIDR) 48 Kbytes  */
#define   CHIPID_CIDR_SRAMSIZ_192K_Val        _UINT32_(0x1)                                        /* (CHIPID_CIDR) 192 Kbytes  */
#define   CHIPID_CIDR_SRAMSIZ_384K_Val        _UINT32_(0x2)                                        /* (CHIPID_CIDR) 384 Kbytes  */
#define   CHIPID_CIDR_SRAMSIZ_6K_Val          _UINT32_(0x3)                                        /* (CHIPID_CIDR) 6 Kbytes  */
#define   CHIPID_CIDR_SRAMSIZ_24K_Val         _UINT32_(0x4)                                        /* (CHIPID_CIDR) 24 Kbytes  */
#define   CHIPID_CIDR_SRAMSIZ_4K_Val          _UINT32_(0x5)                                        /* (CHIPID_CIDR) 4 Kbytes  */
#define   CHIPID_CIDR_SRAMSIZ_80K_Val         _UINT32_(0x6)                                        /* (CHIPID_CIDR) 80 Kbytes  */
#define   CHIPID_CIDR_SRAMSIZ_160K_Val        _UINT32_(0x7)                                        /* (CHIPID_CIDR) 160 Kbytes  */
#define   CHIPID_CIDR_SRAMSIZ_8K_Val          _UINT32_(0x8)                                        /* (CHIPID_CIDR) 8 Kbytes  */
#define   CHIPID_CIDR_SRAMSIZ_16K_Val         _UINT32_(0x9)                                        /* (CHIPID_CIDR) 16 Kbytes  */
#define   CHIPID_CIDR_SRAMSIZ_32K_Val         _UINT32_(0xA)                                        /* (CHIPID_CIDR) 32 Kbytes  */
#define   CHIPID_CIDR_SRAMSIZ_64K_Val         _UINT32_(0xB)                                        /* (CHIPID_CIDR) 64 Kbytes  */
#define   CHIPID_CIDR_SRAMSIZ_128K_Val        _UINT32_(0xC)                                        /* (CHIPID_CIDR) 128 Kbytes  */
#define   CHIPID_CIDR_SRAMSIZ_256K_Val        _UINT32_(0xD)                                        /* (CHIPID_CIDR) 256 Kbytes  */
#define   CHIPID_CIDR_SRAMSIZ_96K_Val         _UINT32_(0xE)                                        /* (CHIPID_CIDR) 96 Kbytes  */
#define   CHIPID_CIDR_SRAMSIZ_512K_Val        _UINT32_(0xF)                                        /* (CHIPID_CIDR) 512 Kbytes  */
#define CHIPID_CIDR_SRAMSIZ_48K               (CHIPID_CIDR_SRAMSIZ_48K_Val << CHIPID_CIDR_SRAMSIZ_Pos) /* (CHIPID_CIDR) 48 Kbytes Position */
#define CHIPID_CIDR_SRAMSIZ_192K              (CHIPID_CIDR_SRAMSIZ_192K_Val << CHIPID_CIDR_SRAMSIZ_Pos) /* (CHIPID_CIDR) 192 Kbytes Position */
#define CHIPID_CIDR_SRAMSIZ_384K              (CHIPID_CIDR_SRAMSIZ_384K_Val << CHIPID_CIDR_SRAMSIZ_Pos) /* (CHIPID_CIDR) 384 Kbytes Position */
#define CHIPID_CIDR_SRAMSIZ_6K                (CHIPID_CIDR_SRAMSIZ_6K_Val << CHIPID_CIDR_SRAMSIZ_Pos) /* (CHIPID_CIDR) 6 Kbytes Position */
#define CHIPID_CIDR_SRAMSIZ_24K               (CHIPID_CIDR_SRAMSIZ_24K_Val << CHIPID_CIDR_SRAMSIZ_Pos) /* (CHIPID_CIDR) 24 Kbytes Position */
#define CHIPID_CIDR_SRAMSIZ_4K                (CHIPID_CIDR_SRAMSIZ_4K_Val << CHIPID_CIDR_SRAMSIZ_Pos) /* (CHIPID_CIDR) 4 Kbytes Position */
#define CHIPID_CIDR_SRAMSIZ_80K               (CHIPID_CIDR_SRAMSIZ_80K_Val << CHIPID_CIDR_SRAMSIZ_Pos) /* (CHIPID_CIDR) 80 Kbytes Position */
#define CHIPID_CIDR_SRAMSIZ_160K              (CHIPID_CIDR_SRAMSIZ_160K_Val << CHIPID_CIDR_SRAMSIZ_Pos) /* (CHIPID_CIDR) 160 Kbytes Position */
#define CHIPID_CIDR_SRAMSIZ_8K                (CHIPID_CIDR_SRAMSIZ_8K_Val << CHIPID_CIDR_SRAMSIZ_Pos) /* (CHIPID_CIDR) 8 Kbytes Position */
#define CHIPID_CIDR_SRAMSIZ_16K               (CHIPID_CIDR_SRAMSIZ_16K_Val << CHIPID_CIDR_SRAMSIZ_Pos) /* (CHIPID_CIDR) 16 Kbytes Position */
#define CHIPID_CIDR_SRAMSIZ_32K               (CHIPID_CIDR_SRAMSIZ_32K_Val << CHIPID_CIDR_SRAMSIZ_Pos) /* (CHIPID_CIDR) 32 Kbytes Position */
#define CHIPID_CIDR_SRAMSIZ_64K               (CHIPID_CIDR_SRAMSIZ_64K_Val << CHIPID_CIDR_SRAMSIZ_Pos) /* (CHIPID_CIDR) 64 Kbytes Position */
#define CHIPID_CIDR_SRAMSIZ_128K              (CHIPID_CIDR_SRAMSIZ_128K_Val << CHIPID_CIDR_SRAMSIZ_Pos) /* (CHIPID_CIDR) 128 Kbytes Position */
#define CHIPID_CIDR_SRAMSIZ_256K              (CHIPID_CIDR_SRAMSIZ_256K_Val << CHIPID_CIDR_SRAMSIZ_Pos) /* (CHIPID_CIDR) 256 Kbytes Position */
#define CHIPID_CIDR_SRAMSIZ_96K               (CHIPID_CIDR_SRAMSIZ_96K_Val << CHIPID_CIDR_SRAMSIZ_Pos) /* (CHIPID_CIDR) 96 Kbytes Position */
#define CHIPID_CIDR_SRAMSIZ_512K              (CHIPID_CIDR_SRAMSIZ_512K_Val << CHIPID_CIDR_SRAMSIZ_Pos) /* (CHIPID_CIDR) 512 Kbytes Position */
#define CHIPID_CIDR_ARCH_Pos                  _UINT32_(20)                                         /* (CHIPID_CIDR) Architecture Identifier Position */
#define CHIPID_CIDR_ARCH_Msk                  (_UINT32_(0xFF) << CHIPID_CIDR_ARCH_Pos)             /* (CHIPID_CIDR) Architecture Identifier Mask */
#define CHIPID_CIDR_ARCH(value)               (CHIPID_CIDR_ARCH_Msk & (_UINT32_(value) << CHIPID_CIDR_ARCH_Pos)) /* Assignment of value for ARCH in the CHIPID_CIDR register */
#define   CHIPID_CIDR_ARCH_SAME70_Val         _UINT32_(0x10)                                       /* (CHIPID_CIDR) SAM E70  */
#define   CHIPID_CIDR_ARCH_SAMS70_Val         _UINT32_(0x11)                                       /* (CHIPID_CIDR) SAM S70  */
#define   CHIPID_CIDR_ARCH_SAMV71_Val         _UINT32_(0x12)                                       /* (CHIPID_CIDR) SAM V71  */
#define   CHIPID_CIDR_ARCH_SAMV70_Val         _UINT32_(0x13)                                       /* (CHIPID_CIDR) SAM V70  */
#define CHIPID_CIDR_ARCH_SAME70               (CHIPID_CIDR_ARCH_SAME70_Val << CHIPID_CIDR_ARCH_Pos) /* (CHIPID_CIDR) SAM E70 Position */
#define CHIPID_CIDR_ARCH_SAMS70               (CHIPID_CIDR_ARCH_SAMS70_Val << CHIPID_CIDR_ARCH_Pos) /* (CHIPID_CIDR) SAM S70 Position */
#define CHIPID_CIDR_ARCH_SAMV71               (CHIPID_CIDR_ARCH_SAMV71_Val << CHIPID_CIDR_ARCH_Pos) /* (CHIPID_CIDR) SAM V71 Position */
#define CHIPID_CIDR_ARCH_SAMV70               (CHIPID_CIDR_ARCH_SAMV70_Val << CHIPID_CIDR_ARCH_Pos) /* (CHIPID_CIDR) SAM V70 Position */
#define CHIPID_CIDR_NVPTYP_Pos                _UINT32_(28)                                         /* (CHIPID_CIDR) Nonvolatile Program Memory Type Position */
#define CHIPID_CIDR_NVPTYP_Msk                (_UINT32_(0x7) << CHIPID_CIDR_NVPTYP_Pos)            /* (CHIPID_CIDR) Nonvolatile Program Memory Type Mask */
#define CHIPID_CIDR_NVPTYP(value)             (CHIPID_CIDR_NVPTYP_Msk & (_UINT32_(value) << CHIPID_CIDR_NVPTYP_Pos)) /* Assignment of value for NVPTYP in the CHIPID_CIDR register */
#define   CHIPID_CIDR_NVPTYP_ROM_Val          _UINT32_(0x0)                                        /* (CHIPID_CIDR) ROM  */
#define   CHIPID_CIDR_NVPTYP_ROMLESS_Val      _UINT32_(0x1)                                        /* (CHIPID_CIDR) ROMless or on-chip Flash  */
#define   CHIPID_CIDR_NVPTYP_FLASH_Val        _UINT32_(0x2)                                        /* (CHIPID_CIDR) Embedded Flash Memory  */
#define   CHIPID_CIDR_NVPTYP_ROM_FLASH_Val    _UINT32_(0x3)                                        /* (CHIPID_CIDR) ROM and Embedded Flash Memory- NVPSIZ is ROM size- NVPSIZ2 is Flash size  */
#define   CHIPID_CIDR_NVPTYP_SRAM_Val         _UINT32_(0x4)                                        /* (CHIPID_CIDR) SRAM emulating ROM  */
#define CHIPID_CIDR_NVPTYP_ROM                (CHIPID_CIDR_NVPTYP_ROM_Val << CHIPID_CIDR_NVPTYP_Pos) /* (CHIPID_CIDR) ROM Position */
#define CHIPID_CIDR_NVPTYP_ROMLESS            (CHIPID_CIDR_NVPTYP_ROMLESS_Val << CHIPID_CIDR_NVPTYP_Pos) /* (CHIPID_CIDR) ROMless or on-chip Flash Position */
#define CHIPID_CIDR_NVPTYP_FLASH              (CHIPID_CIDR_NVPTYP_FLASH_Val << CHIPID_CIDR_NVPTYP_Pos) /* (CHIPID_CIDR) Embedded Flash Memory Position */
#define CHIPID_CIDR_NVPTYP_ROM_FLASH          (CHIPID_CIDR_NVPTYP_ROM_FLASH_Val << CHIPID_CIDR_NVPTYP_Pos) /* (CHIPID_CIDR) ROM and Embedded Flash Memory- NVPSIZ is ROM size- NVPSIZ2 is Flash size Position */
#define CHIPID_CIDR_NVPTYP_SRAM               (CHIPID_CIDR_NVPTYP_SRAM_Val << CHIPID_CIDR_NVPTYP_Pos) /* (CHIPID_CIDR) SRAM emulating ROM Position */
#define CHIPID_CIDR_EXT_Pos                   _UINT32_(31)                                         /* (CHIPID_CIDR) Extension Flag Position */
#define CHIPID_CIDR_EXT_Msk                   (_UINT32_(0x1) << CHIPID_CIDR_EXT_Pos)               /* (CHIPID_CIDR) Extension Flag Mask */
#define CHIPID_CIDR_EXT(value)                (CHIPID_CIDR_EXT_Msk & (_UINT32_(value) << CHIPID_CIDR_EXT_Pos)) /* Assignment of value for EXT in the CHIPID_CIDR register */
#define CHIPID_CIDR_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (CHIPID_CIDR) Register Mask  */


/* -------- CHIPID_EXID : (CHIPID Offset: 0x04) ( R/ 32) Chip ID Extension Register -------- */
#define CHIPID_EXID_EXID_Pos                  _UINT32_(0)                                          /* (CHIPID_EXID) Chip ID Extension Position */
#define CHIPID_EXID_EXID_Msk                  (_UINT32_(0xFFFFFFFF) << CHIPID_EXID_EXID_Pos)       /* (CHIPID_EXID) Chip ID Extension Mask */
#define CHIPID_EXID_EXID(value)               (CHIPID_EXID_EXID_Msk & (_UINT32_(value) << CHIPID_EXID_EXID_Pos)) /* Assignment of value for EXID in the CHIPID_EXID register */
#define CHIPID_EXID_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (CHIPID_EXID) Register Mask  */


/* CHIPID register offsets definitions */
#define CHIPID_CIDR_REG_OFST           _UINT32_(0x00)      /* (CHIPID_CIDR) Chip ID Register Offset */
#define CHIPID_EXID_REG_OFST           _UINT32_(0x04)      /* (CHIPID_EXID) Chip ID Extension Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* CHIPID register API structure */
typedef struct
{
  __I   uint32_t                       CHIPID_CIDR;        /* Offset: 0x00 (R/   32) Chip ID Register */
  __I   uint32_t                       CHIPID_EXID;        /* Offset: 0x04 (R/   32) Chip ID Extension Register */
} chipid_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA70_CHIPID_COMPONENT_H_ */
