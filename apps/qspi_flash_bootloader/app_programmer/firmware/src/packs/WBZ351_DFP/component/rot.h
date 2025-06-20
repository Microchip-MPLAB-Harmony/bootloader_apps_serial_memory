/*
 * Component description for ROT
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
#ifndef _WBZ35_ROT_COMPONENT_H_
#define _WBZ35_ROT_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR ROT                       */
/* ************************************************************************** */

/* -------- ROT_SECCFG : (ROT Offset: 0x00) (R/W 32) Secure Configuration HOLDING REGISTER1,2 -------- */
#define ROT_SECCFG_RESETVALUE                 _UINT32_(0x00)                                       /*  (ROT_SECCFG) Secure Configuration HOLDING REGISTER1,2  Reset Value */

#define ROT_SECCFG_UUID_LOCK_Pos              _UINT32_(4)                                          /* (ROT_SECCFG) Programming lock bits for Unique ID fuses Position */
#define ROT_SECCFG_UUID_LOCK_Msk              (_UINT32_(0x3) << ROT_SECCFG_UUID_LOCK_Pos)          /* (ROT_SECCFG) Programming lock bits for Unique ID fuses Mask */
#define ROT_SECCFG_UUID_LOCK(value)           (ROT_SECCFG_UUID_LOCK_Msk & (_UINT32_(value) << ROT_SECCFG_UUID_LOCK_Pos)) /* Assignment of value for UUID_LOCK in the ROT_SECCFG register */
#define   ROT_SECCFG_UUID_LOCK_UUID_NOT_LCK_0_Val _UINT32_(0x0)                                        /* (ROT_SECCFG) Unique ID is not locked  */
#define   ROT_SECCFG_UUID_LOCK_UUID_LCK_1_Val _UINT32_(0x1)                                        /* (ROT_SECCFG) Unique ID is locked and cannot be programmed  */
#define   ROT_SECCFG_UUID_LOCK_UUID_LCK_2_Val _UINT32_(0x2)                                        /* (ROT_SECCFG) Unique ID is locked and cannot be programmed  */
#define   ROT_SECCFG_UUID_LOCK_UUID_LCK_3_Val _UINT32_(0x3)                                        /* (ROT_SECCFG) Unique ID is locked and cannot be programmed  */
#define ROT_SECCFG_UUID_LOCK_UUID_NOT_LCK_0   (ROT_SECCFG_UUID_LOCK_UUID_NOT_LCK_0_Val << ROT_SECCFG_UUID_LOCK_Pos) /* (ROT_SECCFG) Unique ID is not locked Position */
#define ROT_SECCFG_UUID_LOCK_UUID_LCK_1       (ROT_SECCFG_UUID_LOCK_UUID_LCK_1_Val << ROT_SECCFG_UUID_LOCK_Pos) /* (ROT_SECCFG) Unique ID is locked and cannot be programmed Position */
#define ROT_SECCFG_UUID_LOCK_UUID_LCK_2       (ROT_SECCFG_UUID_LOCK_UUID_LCK_2_Val << ROT_SECCFG_UUID_LOCK_Pos) /* (ROT_SECCFG) Unique ID is locked and cannot be programmed Position */
#define ROT_SECCFG_UUID_LOCK_UUID_LCK_3       (ROT_SECCFG_UUID_LOCK_UUID_LCK_3_Val << ROT_SECCFG_UUID_LOCK_Pos) /* (ROT_SECCFG) Unique ID is locked and cannot be programmed Position */
#define ROT_SECCFG_DEBUG_LOCK_Pos             _UINT32_(6)                                          /* (ROT_SECCFG) Lock bits for debug/programming Position */
#define ROT_SECCFG_DEBUG_LOCK_Msk             (_UINT32_(0x3) << ROT_SECCFG_DEBUG_LOCK_Pos)         /* (ROT_SECCFG) Lock bits for debug/programming Mask */
#define ROT_SECCFG_DEBUG_LOCK(value)          (ROT_SECCFG_DEBUG_LOCK_Msk & (_UINT32_(value) << ROT_SECCFG_DEBUG_LOCK_Pos)) /* Assignment of value for DEBUG_LOCK in the ROT_SECCFG register */
#define   ROT_SECCFG_DEBUG_LOCK_DEBUG_NOT_LCK_0_Val _UINT32_(0x0)                                        /* (ROT_SECCFG) Debug is not locked  */
#define   ROT_SECCFG_DEBUG_LOCK_DEBUG_LCK_1_Val _UINT32_(0x1)                                        /* (ROT_SECCFG) Debug is locked  */
#define   ROT_SECCFG_DEBUG_LOCK_DEBUG_LCK_2_Val _UINT32_(0x2)                                        /* (ROT_SECCFG) Debug is locked  */
#define   ROT_SECCFG_DEBUG_LOCK_DEBUG_LCK_3_Val _UINT32_(0x3)                                        /* (ROT_SECCFG) Debug is locked  */
#define ROT_SECCFG_DEBUG_LOCK_DEBUG_NOT_LCK_0 (ROT_SECCFG_DEBUG_LOCK_DEBUG_NOT_LCK_0_Val << ROT_SECCFG_DEBUG_LOCK_Pos) /* (ROT_SECCFG) Debug is not locked Position */
#define ROT_SECCFG_DEBUG_LOCK_DEBUG_LCK_1     (ROT_SECCFG_DEBUG_LOCK_DEBUG_LCK_1_Val << ROT_SECCFG_DEBUG_LOCK_Pos) /* (ROT_SECCFG) Debug is locked Position */
#define ROT_SECCFG_DEBUG_LOCK_DEBUG_LCK_2     (ROT_SECCFG_DEBUG_LOCK_DEBUG_LCK_2_Val << ROT_SECCFG_DEBUG_LOCK_Pos) /* (ROT_SECCFG) Debug is locked Position */
#define ROT_SECCFG_DEBUG_LOCK_DEBUG_LCK_3     (ROT_SECCFG_DEBUG_LOCK_DEBUG_LCK_3_Val << ROT_SECCFG_DEBUG_LOCK_Pos) /* (ROT_SECCFG) Debug is locked Position */
#define ROT_SECCFG_ROOT_KEY_LOCK_Pos          _UINT32_(8)                                          /* (ROT_SECCFG) Lock bits for storage root Key Position */
#define ROT_SECCFG_ROOT_KEY_LOCK_Msk          (_UINT32_(0x3) << ROT_SECCFG_ROOT_KEY_LOCK_Pos)      /* (ROT_SECCFG) Lock bits for storage root Key Mask */
#define ROT_SECCFG_ROOT_KEY_LOCK(value)       (ROT_SECCFG_ROOT_KEY_LOCK_Msk & (_UINT32_(value) << ROT_SECCFG_ROOT_KEY_LOCK_Pos)) /* Assignment of value for ROOT_KEY_LOCK in the ROT_SECCFG register */
#define   ROT_SECCFG_ROOT_KEY_LOCK_ROOT_KEY_NOT_LCK_0_Val _UINT32_(0x0)                                        /* (ROT_SECCFG) Storage root key is not locked  */
#define   ROT_SECCFG_ROOT_KEY_LOCK_ROOT_KEY_LCK_1_Val _UINT32_(0x1)                                        /* (ROT_SECCFG) Storage root key is locked and cannot be programmed  */
#define   ROT_SECCFG_ROOT_KEY_LOCK_ROOT_KEY_LCK_2_Val _UINT32_(0x2)                                        /* (ROT_SECCFG) Storage root key is locked and cannot be programmed  */
#define   ROT_SECCFG_ROOT_KEY_LOCK_ROOT_KEY_LCK_3_Val _UINT32_(0x3)                                        /* (ROT_SECCFG) Storage root key is locked and cannot be programmed  */
#define ROT_SECCFG_ROOT_KEY_LOCK_ROOT_KEY_NOT_LCK_0 (ROT_SECCFG_ROOT_KEY_LOCK_ROOT_KEY_NOT_LCK_0_Val << ROT_SECCFG_ROOT_KEY_LOCK_Pos) /* (ROT_SECCFG) Storage root key is not locked Position */
#define ROT_SECCFG_ROOT_KEY_LOCK_ROOT_KEY_LCK_1 (ROT_SECCFG_ROOT_KEY_LOCK_ROOT_KEY_LCK_1_Val << ROT_SECCFG_ROOT_KEY_LOCK_Pos) /* (ROT_SECCFG) Storage root key is locked and cannot be programmed Position */
#define ROT_SECCFG_ROOT_KEY_LOCK_ROOT_KEY_LCK_2 (ROT_SECCFG_ROOT_KEY_LOCK_ROOT_KEY_LCK_2_Val << ROT_SECCFG_ROOT_KEY_LOCK_Pos) /* (ROT_SECCFG) Storage root key is locked and cannot be programmed Position */
#define ROT_SECCFG_ROOT_KEY_LOCK_ROOT_KEY_LCK_3 (ROT_SECCFG_ROOT_KEY_LOCK_ROOT_KEY_LCK_3_Val << ROT_SECCFG_ROOT_KEY_LOCK_Pos) /* (ROT_SECCFG) Storage root key is locked and cannot be programmed Position */
#define ROT_SECCFG_BOOT_KEY_LOCK_Pos          _UINT32_(10)                                         /* (ROT_SECCFG) Lock bits for Secure Boot/OTA Key Position */
#define ROT_SECCFG_BOOT_KEY_LOCK_Msk          (_UINT32_(0x3) << ROT_SECCFG_BOOT_KEY_LOCK_Pos)      /* (ROT_SECCFG) Lock bits for Secure Boot/OTA Key Mask */
#define ROT_SECCFG_BOOT_KEY_LOCK(value)       (ROT_SECCFG_BOOT_KEY_LOCK_Msk & (_UINT32_(value) << ROT_SECCFG_BOOT_KEY_LOCK_Pos)) /* Assignment of value for BOOT_KEY_LOCK in the ROT_SECCFG register */
#define   ROT_SECCFG_BOOT_KEY_LOCK_BOOT_KEY_NOT_LCK_0_Val _UINT32_(0x0)                                        /* (ROT_SECCFG) Secure boot key is not locked  */
#define   ROT_SECCFG_BOOT_KEY_LOCK_BOOT_KEY_LCK_1_Val _UINT32_(0x1)                                        /* (ROT_SECCFG) Secure boot key is locked and cannot be programmed  */
#define   ROT_SECCFG_BOOT_KEY_LOCK_BOOT_KEY_LCK_2_Val _UINT32_(0x2)                                        /* (ROT_SECCFG) Secure boot key is locked and cannot be programmed  */
#define   ROT_SECCFG_BOOT_KEY_LOCK_BOOT_KEY_LCK_3_Val _UINT32_(0x3)                                        /* (ROT_SECCFG) Secure boot key is locked and cannot be programmed  */
#define ROT_SECCFG_BOOT_KEY_LOCK_BOOT_KEY_NOT_LCK_0 (ROT_SECCFG_BOOT_KEY_LOCK_BOOT_KEY_NOT_LCK_0_Val << ROT_SECCFG_BOOT_KEY_LOCK_Pos) /* (ROT_SECCFG) Secure boot key is not locked Position */
#define ROT_SECCFG_BOOT_KEY_LOCK_BOOT_KEY_LCK_1 (ROT_SECCFG_BOOT_KEY_LOCK_BOOT_KEY_LCK_1_Val << ROT_SECCFG_BOOT_KEY_LOCK_Pos) /* (ROT_SECCFG) Secure boot key is locked and cannot be programmed Position */
#define ROT_SECCFG_BOOT_KEY_LOCK_BOOT_KEY_LCK_2 (ROT_SECCFG_BOOT_KEY_LOCK_BOOT_KEY_LCK_2_Val << ROT_SECCFG_BOOT_KEY_LOCK_Pos) /* (ROT_SECCFG) Secure boot key is locked and cannot be programmed Position */
#define ROT_SECCFG_BOOT_KEY_LOCK_BOOT_KEY_LCK_3 (ROT_SECCFG_BOOT_KEY_LOCK_BOOT_KEY_LCK_3_Val << ROT_SECCFG_BOOT_KEY_LOCK_Pos) /* (ROT_SECCFG) Secure boot key is locked and cannot be programmed Position */
#define ROT_SECCFG_ADD_BOOT_KEY_Pos           _UINT32_(16)                                         /* (ROT_SECCFG) Additional boot Key bit Position */
#define ROT_SECCFG_ADD_BOOT_KEY_Msk           (_UINT32_(0x1) << ROT_SECCFG_ADD_BOOT_KEY_Pos)       /* (ROT_SECCFG) Additional boot Key bit Mask */
#define ROT_SECCFG_ADD_BOOT_KEY(value)        (ROT_SECCFG_ADD_BOOT_KEY_Msk & (_UINT32_(value) << ROT_SECCFG_ADD_BOOT_KEY_Pos)) /* Assignment of value for ADD_BOOT_KEY in the ROT_SECCFG register */
#define ROT_SECCFG_Msk                        _UINT32_(0x00010FF0)                                 /* (ROT_SECCFG) Register Mask  */


/* -------- ROT_ANTIROLLBACKCOUNTER : (ROT Offset: 0x04) (R/W 32) Anti Roll back counter -------- */
#define ROT_ANTIROLLBACKCOUNTER_RESETVALUE    _UINT32_(0x00)                                       /*  (ROT_ANTIROLLBACKCOUNTER) Anti Roll back counter  Reset Value */

#define ROT_ANTIROLLBACKCOUNTER_ANTIROLLBACKCOUNTER_Pos _UINT32_(0)                                          /* (ROT_ANTIROLLBACKCOUNTER) Anti rollback counter bits Position */
#define ROT_ANTIROLLBACKCOUNTER_ANTIROLLBACKCOUNTER_Msk (_UINT32_(0xFFFFFFFF) << ROT_ANTIROLLBACKCOUNTER_ANTIROLLBACKCOUNTER_Pos) /* (ROT_ANTIROLLBACKCOUNTER) Anti rollback counter bits Mask */
#define ROT_ANTIROLLBACKCOUNTER_ANTIROLLBACKCOUNTER(value) (ROT_ANTIROLLBACKCOUNTER_ANTIROLLBACKCOUNTER_Msk & (_UINT32_(value) << ROT_ANTIROLLBACKCOUNTER_ANTIROLLBACKCOUNTER_Pos)) /* Assignment of value for ANTIROLLBACKCOUNTER in the ROT_ANTIROLLBACKCOUNTER register */
#define ROT_ANTIROLLBACKCOUNTER_Msk           _UINT32_(0xFFFFFFFF)                                 /* (ROT_ANTIROLLBACKCOUNTER) Register Mask  */


/* -------- ROT_LIFECYCLECTR_BOOTKEY : (ROT Offset: 0x24) (R/W 32) Life cycle counter and Secure boot key LSB bytes -------- */
#define ROT_LIFECYCLECTR_BOOTKEY_RESETVALUE   _UINT32_(0x00)                                       /*  (ROT_LIFECYCLECTR_BOOTKEY) Life cycle counter and Secure boot key LSB bytes  Reset Value */

#define ROT_LIFECYCLECTR_BOOTKEY_LIFECYCLECOUNTER_Pos _UINT32_(0)                                          /* (ROT_LIFECYCLECTR_BOOTKEY) Life cycle counter bits Position */
#define ROT_LIFECYCLECTR_BOOTKEY_LIFECYCLECOUNTER_Msk (_UINT32_(0xFFFF) << ROT_LIFECYCLECTR_BOOTKEY_LIFECYCLECOUNTER_Pos) /* (ROT_LIFECYCLECTR_BOOTKEY) Life cycle counter bits Mask */
#define ROT_LIFECYCLECTR_BOOTKEY_LIFECYCLECOUNTER(value) (ROT_LIFECYCLECTR_BOOTKEY_LIFECYCLECOUNTER_Msk & (_UINT32_(value) << ROT_LIFECYCLECTR_BOOTKEY_LIFECYCLECOUNTER_Pos)) /* Assignment of value for LIFECYCLECOUNTER in the ROT_LIFECYCLECTR_BOOTKEY register */
#define ROT_LIFECYCLECTR_BOOTKEY_SECUREBOOTKEY_1_2_Pos _UINT32_(16)                                         /* (ROT_LIFECYCLECTR_BOOTKEY) Secure boot key bits Position */
#define ROT_LIFECYCLECTR_BOOTKEY_SECUREBOOTKEY_1_2_Msk (_UINT32_(0xFFFF) << ROT_LIFECYCLECTR_BOOTKEY_SECUREBOOTKEY_1_2_Pos) /* (ROT_LIFECYCLECTR_BOOTKEY) Secure boot key bits Mask */
#define ROT_LIFECYCLECTR_BOOTKEY_SECUREBOOTKEY_1_2(value) (ROT_LIFECYCLECTR_BOOTKEY_SECUREBOOTKEY_1_2_Msk & (_UINT32_(value) << ROT_LIFECYCLECTR_BOOTKEY_SECUREBOOTKEY_1_2_Pos)) /* Assignment of value for SECUREBOOTKEY_1_2 in the ROT_LIFECYCLECTR_BOOTKEY register */
#define ROT_LIFECYCLECTR_BOOTKEY_Msk          _UINT32_(0xFFFFFFFF)                                 /* (ROT_LIFECYCLECTR_BOOTKEY) Register Mask  */


/* -------- ROT_SECUREBOOTKEY_3_46 : (ROT Offset: 0x28) (R/W 32) Secure boot key -------- */
#define ROT_SECUREBOOTKEY_3_46_RESETVALUE     _UINT32_(0x00)                                       /*  (ROT_SECUREBOOTKEY_3_46) Secure boot key  Reset Value */

#define ROT_SECUREBOOTKEY_3_46_SECUREBOOTKEY_3_46_Pos _UINT32_(0)                                          /* (ROT_SECUREBOOTKEY_3_46) Secure boot key bits Position */
#define ROT_SECUREBOOTKEY_3_46_SECUREBOOTKEY_3_46_Msk (_UINT32_(0xFFFFFFFF) << ROT_SECUREBOOTKEY_3_46_SECUREBOOTKEY_3_46_Pos) /* (ROT_SECUREBOOTKEY_3_46) Secure boot key bits Mask */
#define ROT_SECUREBOOTKEY_3_46_SECUREBOOTKEY_3_46(value) (ROT_SECUREBOOTKEY_3_46_SECUREBOOTKEY_3_46_Msk & (_UINT32_(value) << ROT_SECUREBOOTKEY_3_46_SECUREBOOTKEY_3_46_Pos)) /* Assignment of value for SECUREBOOTKEY_3_46 in the ROT_SECUREBOOTKEY_3_46 register */
#define ROT_SECUREBOOTKEY_3_46_Msk            _UINT32_(0xFFFFFFFF)                                 /* (ROT_SECUREBOOTKEY_3_46) Register Mask  */


/* -------- ROT_SECUREBOOTKEY_47_48_STORAGE_KEY : (ROT Offset: 0x54) (R/W 32) Secure boot key, Storage Key -------- */
#define ROT_SECUREBOOTKEY_47_48_STORAGE_KEY_RESETVALUE _UINT32_(0x00)                                       /*  (ROT_SECUREBOOTKEY_47_48_STORAGE_KEY) Secure boot key, Storage Key  Reset Value */

#define ROT_SECUREBOOTKEY_47_48_STORAGE_KEY_SECUREBOOTKEY_47_48_Pos _UINT32_(0)                                          /* (ROT_SECUREBOOTKEY_47_48_STORAGE_KEY) Secure boot key bits Position */
#define ROT_SECUREBOOTKEY_47_48_STORAGE_KEY_SECUREBOOTKEY_47_48_Msk (_UINT32_(0xFFFF) << ROT_SECUREBOOTKEY_47_48_STORAGE_KEY_SECUREBOOTKEY_47_48_Pos) /* (ROT_SECUREBOOTKEY_47_48_STORAGE_KEY) Secure boot key bits Mask */
#define ROT_SECUREBOOTKEY_47_48_STORAGE_KEY_SECUREBOOTKEY_47_48(value) (ROT_SECUREBOOTKEY_47_48_STORAGE_KEY_SECUREBOOTKEY_47_48_Msk & (_UINT32_(value) << ROT_SECUREBOOTKEY_47_48_STORAGE_KEY_SECUREBOOTKEY_47_48_Pos)) /* Assignment of value for SECUREBOOTKEY_47_48 in the ROT_SECUREBOOTKEY_47_48_STORAGE_KEY register */
#define ROT_SECUREBOOTKEY_47_48_STORAGE_KEY_STORAGE_KEY_1_2_Pos _UINT32_(16)                                         /* (ROT_SECUREBOOTKEY_47_48_STORAGE_KEY) Storage root key bits Position */
#define ROT_SECUREBOOTKEY_47_48_STORAGE_KEY_STORAGE_KEY_1_2_Msk (_UINT32_(0xFFFF) << ROT_SECUREBOOTKEY_47_48_STORAGE_KEY_STORAGE_KEY_1_2_Pos) /* (ROT_SECUREBOOTKEY_47_48_STORAGE_KEY) Storage root key bits Mask */
#define ROT_SECUREBOOTKEY_47_48_STORAGE_KEY_STORAGE_KEY_1_2(value) (ROT_SECUREBOOTKEY_47_48_STORAGE_KEY_STORAGE_KEY_1_2_Msk & (_UINT32_(value) << ROT_SECUREBOOTKEY_47_48_STORAGE_KEY_STORAGE_KEY_1_2_Pos)) /* Assignment of value for STORAGE_KEY_1_2 in the ROT_SECUREBOOTKEY_47_48_STORAGE_KEY register */
#define ROT_SECUREBOOTKEY_47_48_STORAGE_KEY_Msk _UINT32_(0xFFFFFFFF)                                 /* (ROT_SECUREBOOTKEY_47_48_STORAGE_KEY) Register Mask  */


/* -------- ROT_STORAGE_KEY_3_30 : (ROT Offset: 0x58) (R/W 32) Storage Key -------- */
#define ROT_STORAGE_KEY_3_30_RESETVALUE       _UINT32_(0x00)                                       /*  (ROT_STORAGE_KEY_3_30) Storage Key  Reset Value */

#define ROT_STORAGE_KEY_3_30_STORAGE_KEY_3_30_Pos _UINT32_(0)                                          /* (ROT_STORAGE_KEY_3_30) Storage Key bits Position */
#define ROT_STORAGE_KEY_3_30_STORAGE_KEY_3_30_Msk (_UINT32_(0xFFFFFFFF) << ROT_STORAGE_KEY_3_30_STORAGE_KEY_3_30_Pos) /* (ROT_STORAGE_KEY_3_30) Storage Key bits Mask */
#define ROT_STORAGE_KEY_3_30_STORAGE_KEY_3_30(value) (ROT_STORAGE_KEY_3_30_STORAGE_KEY_3_30_Msk & (_UINT32_(value) << ROT_STORAGE_KEY_3_30_STORAGE_KEY_3_30_Pos)) /* Assignment of value for STORAGE_KEY_3_30 in the ROT_STORAGE_KEY_3_30 register */
#define ROT_STORAGE_KEY_3_30_Msk              _UINT32_(0xFFFFFFFF)                                 /* (ROT_STORAGE_KEY_3_30) Register Mask  */


/* -------- ROT_STORAGE_KEY_FFCFG : (ROT Offset: 0x74) (R/W 32) Storage Key, FFCFG -------- */
#define ROT_STORAGE_KEY_FFCFG_RESETVALUE      _UINT32_(0x00)                                       /*  (ROT_STORAGE_KEY_FFCFG) Storage Key, FFCFG  Reset Value */

#define ROT_STORAGE_KEY_FFCFG_STORAGE_KEY_31_32_Pos _UINT32_(0)                                          /* (ROT_STORAGE_KEY_FFCFG) Storage Key bits Position */
#define ROT_STORAGE_KEY_FFCFG_STORAGE_KEY_31_32_Msk (_UINT32_(0xFFFF) << ROT_STORAGE_KEY_FFCFG_STORAGE_KEY_31_32_Pos) /* (ROT_STORAGE_KEY_FFCFG) Storage Key bits Mask */
#define ROT_STORAGE_KEY_FFCFG_STORAGE_KEY_31_32(value) (ROT_STORAGE_KEY_FFCFG_STORAGE_KEY_31_32_Msk & (_UINT32_(value) << ROT_STORAGE_KEY_FFCFG_STORAGE_KEY_31_32_Pos)) /* Assignment of value for STORAGE_KEY_31_32 in the ROT_STORAGE_KEY_FFCFG register */
#define ROT_STORAGE_KEY_FFCFG_FFCFG_Pos       _UINT32_(16)                                         /* (ROT_STORAGE_KEY_FFCFG) FFCFG bits Position */
#define ROT_STORAGE_KEY_FFCFG_FFCFG_Msk       (_UINT32_(0xFFFF) << ROT_STORAGE_KEY_FFCFG_FFCFG_Pos) /* (ROT_STORAGE_KEY_FFCFG) FFCFG bits Mask */
#define ROT_STORAGE_KEY_FFCFG_FFCFG(value)    (ROT_STORAGE_KEY_FFCFG_FFCFG_Msk & (_UINT32_(value) << ROT_STORAGE_KEY_FFCFG_FFCFG_Pos)) /* Assignment of value for FFCFG in the ROT_STORAGE_KEY_FFCFG register */
#define ROT_STORAGE_KEY_FFCFG_Msk             _UINT32_(0xFFFFFFFF)                                 /* (ROT_STORAGE_KEY_FFCFG) Register Mask  */


/* -------- ROT_DEVICE_ID_PATCH_CFG : (ROT Offset: 0x78) (R/W 32) Device ID and Patch CFG -------- */
#define ROT_DEVICE_ID_PATCH_CFG_RESETVALUE    _UINT32_(0x00)                                       /*  (ROT_DEVICE_ID_PATCH_CFG) Device ID and Patch CFG  Reset Value */

#define ROT_DEVICE_ID_PATCH_CFG_DEVICE_ID_Pos _UINT32_(0)                                          /* (ROT_DEVICE_ID_PATCH_CFG) Device ID bits Position */
#define ROT_DEVICE_ID_PATCH_CFG_DEVICE_ID_Msk (_UINT32_(0xFFFF) << ROT_DEVICE_ID_PATCH_CFG_DEVICE_ID_Pos) /* (ROT_DEVICE_ID_PATCH_CFG) Device ID bits Mask */
#define ROT_DEVICE_ID_PATCH_CFG_DEVICE_ID(value) (ROT_DEVICE_ID_PATCH_CFG_DEVICE_ID_Msk & (_UINT32_(value) << ROT_DEVICE_ID_PATCH_CFG_DEVICE_ID_Pos)) /* Assignment of value for DEVICE_ID in the ROT_DEVICE_ID_PATCH_CFG register */
#define ROT_DEVICE_ID_PATCH_CFG_PATCH_CFG_Pos _UINT32_(16)                                         /* (ROT_DEVICE_ID_PATCH_CFG) Patch CFG bits Position */
#define ROT_DEVICE_ID_PATCH_CFG_PATCH_CFG_Msk (_UINT32_(0xFFFF) << ROT_DEVICE_ID_PATCH_CFG_PATCH_CFG_Pos) /* (ROT_DEVICE_ID_PATCH_CFG) Patch CFG bits Mask */
#define ROT_DEVICE_ID_PATCH_CFG_PATCH_CFG(value) (ROT_DEVICE_ID_PATCH_CFG_PATCH_CFG_Msk & (_UINT32_(value) << ROT_DEVICE_ID_PATCH_CFG_PATCH_CFG_Pos)) /* Assignment of value for PATCH_CFG in the ROT_DEVICE_ID_PATCH_CFG register */
#define ROT_DEVICE_ID_PATCH_CFG_Msk           _UINT32_(0xFFFFFFFF)                                 /* (ROT_DEVICE_ID_PATCH_CFG) Register Mask  */


/* -------- ROT_PATCH_CFG : (ROT Offset: 0x7C) (R/W 32) Patch CFG -------- */
#define ROT_PATCH_CFG_RESETVALUE              _UINT32_(0x00)                                       /*  (ROT_PATCH_CFG) Patch CFG  Reset Value */

#define ROT_PATCH_CFG_PATCH_CFG_Pos           _UINT32_(0)                                          /* (ROT_PATCH_CFG) Patch CFG bits Position */
#define ROT_PATCH_CFG_PATCH_CFG_Msk           (_UINT32_(0xFFFFFFFF) << ROT_PATCH_CFG_PATCH_CFG_Pos) /* (ROT_PATCH_CFG) Patch CFG bits Mask */
#define ROT_PATCH_CFG_PATCH_CFG(value)        (ROT_PATCH_CFG_PATCH_CFG_Msk & (_UINT32_(value) << ROT_PATCH_CFG_PATCH_CFG_Pos)) /* Assignment of value for PATCH_CFG in the ROT_PATCH_CFG register */
#define ROT_PATCH_CFG_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (ROT_PATCH_CFG) Register Mask  */


/* -------- ROT_PATCH_CODE : (ROT Offset: 0x80) (R/W 32) Patch Code -------- */
#define ROT_PATCH_CODE_RESETVALUE             _UINT32_(0x00)                                       /*  (ROT_PATCH_CODE) Patch Code  Reset Value */

#define ROT_PATCH_CODE_PATCH_CODE_Pos         _UINT32_(0)                                          /* (ROT_PATCH_CODE) Patch Code bits Position */
#define ROT_PATCH_CODE_PATCH_CODE_Msk         (_UINT32_(0xFFFFFFFF) << ROT_PATCH_CODE_PATCH_CODE_Pos) /* (ROT_PATCH_CODE) Patch Code bits Mask */
#define ROT_PATCH_CODE_PATCH_CODE(value)      (ROT_PATCH_CODE_PATCH_CODE_Msk & (_UINT32_(value) << ROT_PATCH_CODE_PATCH_CODE_Pos)) /* Assignment of value for PATCH_CODE in the ROT_PATCH_CODE register */
#define ROT_PATCH_CODE_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (ROT_PATCH_CODE) Register Mask  */


/* -------- ROT_UUID : (ROT Offset: 0x1D8) (R/W 32) Unique ID -------- */
#define ROT_UUID_RESETVALUE                   _UINT32_(0x00)                                       /*  (ROT_UUID) Unique ID  Reset Value */

#define ROT_UUID_UUID_Pos                     _UINT32_(0)                                          /* (ROT_UUID) Unique ID bits Position */
#define ROT_UUID_UUID_Msk                     (_UINT32_(0xFFFFFFFF) << ROT_UUID_UUID_Pos)          /* (ROT_UUID) Unique ID bits Mask */
#define ROT_UUID_UUID(value)                  (ROT_UUID_UUID_Msk & (_UINT32_(value) << ROT_UUID_UUID_Pos)) /* Assignment of value for UUID in the ROT_UUID register */
#define ROT_UUID_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (ROT_UUID) Register Mask  */


/* -------- ROT_SEC_BOOT : (ROT Offset: 0xC00) (R/W 32) Secure Boot Register -------- */
#define ROT_SEC_BOOT_RESETVALUE               _UINT32_(0x10002)                                    /*  (ROT_SEC_BOOT) Secure Boot Register  Reset Value */

#define ROT_SEC_BOOT_SECURE_BOOT_REQD_Pos     _UINT32_(0)                                          /* (ROT_SEC_BOOT) Bits to indicate that secure boot is required on the next device reset. Position */
#define ROT_SEC_BOOT_SECURE_BOOT_REQD_Msk     (_UINT32_(0x3) << ROT_SEC_BOOT_SECURE_BOOT_REQD_Pos) /* (ROT_SEC_BOOT) Bits to indicate that secure boot is required on the next device reset. Mask */
#define ROT_SEC_BOOT_SECURE_BOOT_REQD(value)  (ROT_SEC_BOOT_SECURE_BOOT_REQD_Msk & (_UINT32_(value) << ROT_SEC_BOOT_SECURE_BOOT_REQD_Pos)) /* Assignment of value for SECURE_BOOT_REQD in the ROT_SEC_BOOT register */
#define   ROT_SEC_BOOT_SECURE_BOOT_REQD_SEC_BOOT_REQD_0_Val _UINT32_(0x0)                                        /* (ROT_SEC_BOOT) Secure boot code authentication is required  */
#define   ROT_SEC_BOOT_SECURE_BOOT_REQD_SEC_BOOT_NOT_REQD_1_Val _UINT32_(0x1)                                        /* (ROT_SEC_BOOT) Secure boot code authentication is NOT required  */
#define   ROT_SEC_BOOT_SECURE_BOOT_REQD_SEC_BOOT_NOT_REQD_2_Val _UINT32_(0x2)                                        /* (ROT_SEC_BOOT) Secure boot code authentication is NOT required  */
#define   ROT_SEC_BOOT_SECURE_BOOT_REQD_SEC_BOOT_REQD_3_Val _UINT32_(0x3)                                        /* (ROT_SEC_BOOT) Secure boot code authentication is required  */
#define ROT_SEC_BOOT_SECURE_BOOT_REQD_SEC_BOOT_REQD_0 (ROT_SEC_BOOT_SECURE_BOOT_REQD_SEC_BOOT_REQD_0_Val << ROT_SEC_BOOT_SECURE_BOOT_REQD_Pos) /* (ROT_SEC_BOOT) Secure boot code authentication is required Position */
#define ROT_SEC_BOOT_SECURE_BOOT_REQD_SEC_BOOT_NOT_REQD_1 (ROT_SEC_BOOT_SECURE_BOOT_REQD_SEC_BOOT_NOT_REQD_1_Val << ROT_SEC_BOOT_SECURE_BOOT_REQD_Pos) /* (ROT_SEC_BOOT) Secure boot code authentication is NOT required Position */
#define ROT_SEC_BOOT_SECURE_BOOT_REQD_SEC_BOOT_NOT_REQD_2 (ROT_SEC_BOOT_SECURE_BOOT_REQD_SEC_BOOT_NOT_REQD_2_Val << ROT_SEC_BOOT_SECURE_BOOT_REQD_Pos) /* (ROT_SEC_BOOT) Secure boot code authentication is NOT required Position */
#define ROT_SEC_BOOT_SECURE_BOOT_REQD_SEC_BOOT_REQD_3 (ROT_SEC_BOOT_SECURE_BOOT_REQD_SEC_BOOT_REQD_3_Val << ROT_SEC_BOOT_SECURE_BOOT_REQD_Pos) /* (ROT_SEC_BOOT) Secure boot code authentication is required Position */
#define ROT_SEC_BOOT_SEC_BOOT_STATUS_Pos      _UINT32_(8)                                          /* (ROT_SEC_BOOT) Bits to indicate that secure boot status Position */
#define ROT_SEC_BOOT_SEC_BOOT_STATUS_Msk      (_UINT32_(0xFF) << ROT_SEC_BOOT_SEC_BOOT_STATUS_Pos) /* (ROT_SEC_BOOT) Bits to indicate that secure boot status Mask */
#define ROT_SEC_BOOT_SEC_BOOT_STATUS(value)   (ROT_SEC_BOOT_SEC_BOOT_STATUS_Msk & (_UINT32_(value) << ROT_SEC_BOOT_SEC_BOOT_STATUS_Pos)) /* Assignment of value for SEC_BOOT_STATUS in the ROT_SEC_BOOT register */
#define ROT_SEC_BOOT_SECURE_BOOT_DONE_Pos     _UINT32_(16)                                         /* (ROT_SEC_BOOT) Bits to indicate that secure boot is done Position */
#define ROT_SEC_BOOT_SECURE_BOOT_DONE_Msk     (_UINT32_(0x3) << ROT_SEC_BOOT_SECURE_BOOT_DONE_Pos) /* (ROT_SEC_BOOT) Bits to indicate that secure boot is done Mask */
#define ROT_SEC_BOOT_SECURE_BOOT_DONE(value)  (ROT_SEC_BOOT_SECURE_BOOT_DONE_Msk & (_UINT32_(value) << ROT_SEC_BOOT_SECURE_BOOT_DONE_Pos)) /* Assignment of value for SECURE_BOOT_DONE in the ROT_SEC_BOOT register */
#define   ROT_SEC_BOOT_SECURE_BOOT_DONE_SEC_BOOT_DONE_0_Val _UINT32_(0x0)                                        /* (ROT_SEC_BOOT) S ecure boot is done  */
#define   ROT_SEC_BOOT_SECURE_BOOT_DONE_SEC_BOOT_NOT_DONE_1_Val _UINT32_(0x1)                                        /* (ROT_SEC_BOOT) S ecure boot is not done  */
#define   ROT_SEC_BOOT_SECURE_BOOT_DONE_SEC_BOOT_NOT_DONE_2_Val _UINT32_(0x2)                                        /* (ROT_SEC_BOOT) S ecure boot is not done  */
#define   ROT_SEC_BOOT_SECURE_BOOT_DONE_SEC_BOOT_DONE_3_Val _UINT32_(0x3)                                        /* (ROT_SEC_BOOT) S ecure boot is done  */
#define ROT_SEC_BOOT_SECURE_BOOT_DONE_SEC_BOOT_DONE_0 (ROT_SEC_BOOT_SECURE_BOOT_DONE_SEC_BOOT_DONE_0_Val << ROT_SEC_BOOT_SECURE_BOOT_DONE_Pos) /* (ROT_SEC_BOOT) S ecure boot is done Position */
#define ROT_SEC_BOOT_SECURE_BOOT_DONE_SEC_BOOT_NOT_DONE_1 (ROT_SEC_BOOT_SECURE_BOOT_DONE_SEC_BOOT_NOT_DONE_1_Val << ROT_SEC_BOOT_SECURE_BOOT_DONE_Pos) /* (ROT_SEC_BOOT) S ecure boot is not done Position */
#define ROT_SEC_BOOT_SECURE_BOOT_DONE_SEC_BOOT_NOT_DONE_2 (ROT_SEC_BOOT_SECURE_BOOT_DONE_SEC_BOOT_NOT_DONE_2_Val << ROT_SEC_BOOT_SECURE_BOOT_DONE_Pos) /* (ROT_SEC_BOOT) S ecure boot is not done Position */
#define ROT_SEC_BOOT_SECURE_BOOT_DONE_SEC_BOOT_DONE_3 (ROT_SEC_BOOT_SECURE_BOOT_DONE_SEC_BOOT_DONE_3_Val << ROT_SEC_BOOT_SECURE_BOOT_DONE_Pos) /* (ROT_SEC_BOOT) S ecure boot is done Position */
#define ROT_SEC_BOOT_Msk                      _UINT32_(0x0003FF03)                                 /* (ROT_SEC_BOOT) Register Mask  */


/* -------- ROT_EFUSE_RWDATA : (ROT Offset: 0xC04) (R/W 32) EFuse RW Data Register -------- */
#define ROT_EFUSE_RWDATA_RESETVALUE           _UINT32_(0x00)                                       /*  (ROT_EFUSE_RWDATA) EFuse RW Data Register  Reset Value */

#define ROT_EFUSE_RWDATA_DATA_Pos             _UINT32_(0)                                          /* (ROT_EFUSE_RWDATA) eFuse Program (Write) Data Position */
#define ROT_EFUSE_RWDATA_DATA_Msk             (_UINT32_(0xFF) << ROT_EFUSE_RWDATA_DATA_Pos)        /* (ROT_EFUSE_RWDATA) eFuse Program (Write) Data Mask */
#define ROT_EFUSE_RWDATA_DATA(value)          (ROT_EFUSE_RWDATA_DATA_Msk & (_UINT32_(value) << ROT_EFUSE_RWDATA_DATA_Pos)) /* Assignment of value for DATA in the ROT_EFUSE_RWDATA register */
#define ROT_EFUSE_RWDATA_ADDR_Pos             _UINT32_(16)                                         /* (ROT_EFUSE_RWDATA) eFuse Program/Read Address Position */
#define ROT_EFUSE_RWDATA_ADDR_Msk             (_UINT32_(0xFFF) << ROT_EFUSE_RWDATA_ADDR_Pos)       /* (ROT_EFUSE_RWDATA) eFuse Program/Read Address Mask */
#define ROT_EFUSE_RWDATA_ADDR(value)          (ROT_EFUSE_RWDATA_ADDR_Msk & (_UINT32_(value) << ROT_EFUSE_RWDATA_ADDR_Pos)) /* Assignment of value for ADDR in the ROT_EFUSE_RWDATA register */
#define ROT_EFUSE_RWDATA_Msk                  _UINT32_(0x0FFF00FF)                                 /* (ROT_EFUSE_RWDATA) Register Mask  */


/* -------- ROT_EFUSE_CON : (ROT Offset: 0xC08) (R/W 32) Efuse Configuration Register2 -------- */
#define ROT_EFUSE_CON_RESETVALUE              _UINT32_(0x00)                                       /*  (ROT_EFUSE_CON) Efuse Configuration Register2  Reset Value */

#define ROT_EFUSE_CON_PGM_1BIT_Pos            _UINT32_(0)                                          /* (ROT_EFUSE_CON) eFuse CTRL to program 1 bit at a time. Valid only when EN_PGM is set Position */
#define ROT_EFUSE_CON_PGM_1BIT_Msk            (_UINT32_(0x1) << ROT_EFUSE_CON_PGM_1BIT_Pos)        /* (ROT_EFUSE_CON) eFuse CTRL to program 1 bit at a time. Valid only when EN_PGM is set Mask */
#define ROT_EFUSE_CON_PGM_1BIT(value)         (ROT_EFUSE_CON_PGM_1BIT_Msk & (_UINT32_(value) << ROT_EFUSE_CON_PGM_1BIT_Pos)) /* Assignment of value for PGM_1BIT in the ROT_EFUSE_CON register */
#define   ROT_EFUSE_CON_PGM_1BIT_EFUSE_RW_15_0_Val _UINT32_(0x0)                                        /* (ROT_EFUSE_CON) EFuse controller will program EFUSE_RWDATA.DATA[15:0] to the address in EFUSE_RWDATA.ADDR[11:3]  */
#define   ROT_EFUSE_CON_PGM_1BIT_EFUSE_RW_0_Val _UINT32_(0x1)                                        /* (ROT_EFUSE_CON) EFuse controller will program EFUSE_RWDATA.DATA[0] to the address in EFUSE_RWDATA.ADDR[11:0]  */
#define ROT_EFUSE_CON_PGM_1BIT_EFUSE_RW_15_0  (ROT_EFUSE_CON_PGM_1BIT_EFUSE_RW_15_0_Val << ROT_EFUSE_CON_PGM_1BIT_Pos) /* (ROT_EFUSE_CON) EFuse controller will program EFUSE_RWDATA.DATA[15:0] to the address in EFUSE_RWDATA.ADDR[11:3] Position */
#define ROT_EFUSE_CON_PGM_1BIT_EFUSE_RW_0     (ROT_EFUSE_CON_PGM_1BIT_EFUSE_RW_0_Val << ROT_EFUSE_CON_PGM_1BIT_Pos) /* (ROT_EFUSE_CON) EFuse controller will program EFUSE_RWDATA.DATA[0] to the address in EFUSE_RWDATA.ADDR[11:0] Position */
#define ROT_EFUSE_CON_PGM_MODE_Pos            _UINT32_(1)                                          /* (ROT_EFUSE_CON) eFuse Programming Mode Enable bit Position */
#define ROT_EFUSE_CON_PGM_MODE_Msk            (_UINT32_(0x1) << ROT_EFUSE_CON_PGM_MODE_Pos)        /* (ROT_EFUSE_CON) eFuse Programming Mode Enable bit Mask */
#define ROT_EFUSE_CON_PGM_MODE(value)         (ROT_EFUSE_CON_PGM_MODE_Msk & (_UINT32_(value) << ROT_EFUSE_CON_PGM_MODE_Pos)) /* Assignment of value for PGM_MODE in the ROT_EFUSE_CON register */
#define   ROT_EFUSE_CON_PGM_MODE_PGM_MODE_DISABLED_Val _UINT32_(0x0)                                        /* (ROT_EFUSE_CON) EFuse Programming disabled  */
#define   ROT_EFUSE_CON_PGM_MODE_PGM_MODE_ENABLED_Val _UINT32_(0x1)                                        /* (ROT_EFUSE_CON) EFuse Programming enabled  */
#define ROT_EFUSE_CON_PGM_MODE_PGM_MODE_DISABLED (ROT_EFUSE_CON_PGM_MODE_PGM_MODE_DISABLED_Val << ROT_EFUSE_CON_PGM_MODE_Pos) /* (ROT_EFUSE_CON) EFuse Programming disabled Position */
#define ROT_EFUSE_CON_PGM_MODE_PGM_MODE_ENABLED (ROT_EFUSE_CON_PGM_MODE_PGM_MODE_ENABLED_Val << ROT_EFUSE_CON_PGM_MODE_Pos) /* (ROT_EFUSE_CON) EFuse Programming enabled Position */
#define ROT_EFUSE_CON_EN_LD_Pos               _UINT32_(5)                                          /* (ROT_EFUSE_CON) eFuse Word Read Start bit for loading the fuse byte pointed by ADDR field into the holding register Position */
#define ROT_EFUSE_CON_EN_LD_Msk               (_UINT32_(0x1) << ROT_EFUSE_CON_EN_LD_Pos)           /* (ROT_EFUSE_CON) eFuse Word Read Start bit for loading the fuse byte pointed by ADDR field into the holding register Mask */
#define ROT_EFUSE_CON_EN_LD(value)            (ROT_EFUSE_CON_EN_LD_Msk & (_UINT32_(value) << ROT_EFUSE_CON_EN_LD_Pos)) /* Assignment of value for EN_LD in the ROT_EFUSE_CON register */
#define   ROT_EFUSE_CON_EN_LD_ENLD_READ_COMPLETED_Val _UINT32_(0x0)                                        /* (ROT_EFUSE_CON) EFuse Read operation has completed  */
#define   ROT_EFUSE_CON_EN_LD_ENLD_READ_START_Val _UINT32_(0x1)                                        /* (ROT_EFUSE_CON) Start eFuse Read operation for specified eFuse word as addressed in EFUSE_RWDATA register  */
#define ROT_EFUSE_CON_EN_LD_ENLD_READ_COMPLETED (ROT_EFUSE_CON_EN_LD_ENLD_READ_COMPLETED_Val << ROT_EFUSE_CON_EN_LD_Pos) /* (ROT_EFUSE_CON) EFuse Read operation has completed Position */
#define ROT_EFUSE_CON_EN_LD_ENLD_READ_START   (ROT_EFUSE_CON_EN_LD_ENLD_READ_START_Val << ROT_EFUSE_CON_EN_LD_Pos) /* (ROT_EFUSE_CON) Start eFuse Read operation for specified eFuse word as addressed in EFUSE_RWDATA register Position */
#define ROT_EFUSE_CON_EN_LD_ALL1_Pos          _UINT32_(6)                                          /* (ROT_EFUSE_CON) eFuse Panel Read Start bit for loading into the holding registers Position */
#define ROT_EFUSE_CON_EN_LD_ALL1_Msk          (_UINT32_(0x1) << ROT_EFUSE_CON_EN_LD_ALL1_Pos)      /* (ROT_EFUSE_CON) eFuse Panel Read Start bit for loading into the holding registers Mask */
#define ROT_EFUSE_CON_EN_LD_ALL1(value)       (ROT_EFUSE_CON_EN_LD_ALL1_Msk & (_UINT32_(value) << ROT_EFUSE_CON_EN_LD_ALL1_Pos)) /* Assignment of value for EN_LD_ALL1 in the ROT_EFUSE_CON register */
#define   ROT_EFUSE_CON_EN_LD_ALL1_ENLD_ALL1_READ_COMPLETED_Val _UINT32_(0x0)                                        /* (ROT_EFUSE_CON) EFuse Read operation has completed  */
#define   ROT_EFUSE_CON_EN_LD_ALL1_ENLD_ALL1_READ_START_Val _UINT32_(0x1)                                        /* (ROT_EFUSE_CON) Start eFuse Read operation for entire eFuse panel  */
#define ROT_EFUSE_CON_EN_LD_ALL1_ENLD_ALL1_READ_COMPLETED (ROT_EFUSE_CON_EN_LD_ALL1_ENLD_ALL1_READ_COMPLETED_Val << ROT_EFUSE_CON_EN_LD_ALL1_Pos) /* (ROT_EFUSE_CON) EFuse Read operation has completed Position */
#define ROT_EFUSE_CON_EN_LD_ALL1_ENLD_ALL1_READ_START (ROT_EFUSE_CON_EN_LD_ALL1_ENLD_ALL1_READ_START_Val << ROT_EFUSE_CON_EN_LD_ALL1_Pos) /* (ROT_EFUSE_CON) Start eFuse Read operation for entire eFuse panel Position */
#define ROT_EFUSE_CON_EN_PGM_Pos              _UINT32_(7)                                          /* (ROT_EFUSE_CON) eFuse Programming Start bit Position */
#define ROT_EFUSE_CON_EN_PGM_Msk              (_UINT32_(0x1) << ROT_EFUSE_CON_EN_PGM_Pos)          /* (ROT_EFUSE_CON) eFuse Programming Start bit Mask */
#define ROT_EFUSE_CON_EN_PGM(value)           (ROT_EFUSE_CON_EN_PGM_Msk & (_UINT32_(value) << ROT_EFUSE_CON_EN_PGM_Pos)) /* Assignment of value for EN_PGM in the ROT_EFUSE_CON register */
#define   ROT_EFUSE_CON_EN_PGM_EN_PGM_COMPLETED_Val _UINT32_(0x0)                                        /* (ROT_EFUSE_CON) EFuse Programming operation has completed  */
#define   ROT_EFUSE_CON_EN_PGM_EN_PGM_START_Val _UINT32_(0x1)                                        /* (ROT_EFUSE_CON) Start eFuse Programming operation  */
#define ROT_EFUSE_CON_EN_PGM_EN_PGM_COMPLETED (ROT_EFUSE_CON_EN_PGM_EN_PGM_COMPLETED_Val << ROT_EFUSE_CON_EN_PGM_Pos) /* (ROT_EFUSE_CON) EFuse Programming operation has completed Position */
#define ROT_EFUSE_CON_EN_PGM_EN_PGM_START     (ROT_EFUSE_CON_EN_PGM_EN_PGM_START_Val << ROT_EFUSE_CON_EN_PGM_Pos) /* (ROT_EFUSE_CON) Start eFuse Programming operation Position */
#define ROT_EFUSE_CON_Msk                     _UINT32_(0x000000E3)                                 /* (ROT_EFUSE_CON) Register Mask  */

#define ROT_EFUSE_CON_EN_LD_ALL_Pos           _UINT32_(6)                                          /* (ROT_EFUSE_CON Position) eFuse Panel Read Start bit for loading into the holding registers */
#define ROT_EFUSE_CON_EN_LD_ALL_Msk           (_UINT32_(0x1) << ROT_EFUSE_CON_EN_LD_ALL_Pos)       /* (ROT_EFUSE_CON Mask) EN_LD_ALL */
#define ROT_EFUSE_CON_EN_LD_ALL(value)        (ROT_EFUSE_CON_EN_LD_ALL_Msk & (_UINT32_(value) << ROT_EFUSE_CON_EN_LD_ALL_Pos)) 

/* ROT register offsets definitions */
#define ROT_SECCFG_REG_OFST            _UINT32_(0x00)      /* (ROT_SECCFG) Secure Configuration HOLDING REGISTER1,2 Offset */
#define ROT_ANTIROLLBACKCOUNTER_REG_OFST _UINT32_(0x04)      /* (ROT_ANTIROLLBACKCOUNTER) Anti Roll back counter Offset */
#define ROT_ANTIROLLBACKCOUNTER0_REG_OFST _UINT32_(0x04)      /* (ROT_ANTIROLLBACKCOUNTER0) Anti Roll back counter Offset */
#define ROT_ANTIROLLBACKCOUNTER1_REG_OFST _UINT32_(0x08)      /* (ROT_ANTIROLLBACKCOUNTER1) Anti Roll back counter Offset */
#define ROT_ANTIROLLBACKCOUNTER2_REG_OFST _UINT32_(0x0C)      /* (ROT_ANTIROLLBACKCOUNTER2) Anti Roll back counter Offset */
#define ROT_ANTIROLLBACKCOUNTER3_REG_OFST _UINT32_(0x10)      /* (ROT_ANTIROLLBACKCOUNTER3) Anti Roll back counter Offset */
#define ROT_ANTIROLLBACKCOUNTER4_REG_OFST _UINT32_(0x14)      /* (ROT_ANTIROLLBACKCOUNTER4) Anti Roll back counter Offset */
#define ROT_ANTIROLLBACKCOUNTER5_REG_OFST _UINT32_(0x18)      /* (ROT_ANTIROLLBACKCOUNTER5) Anti Roll back counter Offset */
#define ROT_ANTIROLLBACKCOUNTER6_REG_OFST _UINT32_(0x1C)      /* (ROT_ANTIROLLBACKCOUNTER6) Anti Roll back counter Offset */
#define ROT_ANTIROLLBACKCOUNTER7_REG_OFST _UINT32_(0x20)      /* (ROT_ANTIROLLBACKCOUNTER7) Anti Roll back counter Offset */
#define ROT_LIFECYCLECTR_BOOTKEY_REG_OFST _UINT32_(0x24)      /* (ROT_LIFECYCLECTR_BOOTKEY) Life cycle counter and Secure boot key LSB bytes Offset */
#define ROT_SECUREBOOTKEY_3_46_REG_OFST _UINT32_(0x28)      /* (ROT_SECUREBOOTKEY_3_46) Secure boot key Offset */
#define ROT_SECUREBOOTKEY_3_46_0_REG_OFST _UINT32_(0x28)      /* (ROT_SECUREBOOTKEY_3_46_0) Secure boot key Offset */
#define ROT_SECUREBOOTKEY_3_46_1_REG_OFST _UINT32_(0x2C)      /* (ROT_SECUREBOOTKEY_3_46_1) Secure boot key Offset */
#define ROT_SECUREBOOTKEY_3_46_2_REG_OFST _UINT32_(0x30)      /* (ROT_SECUREBOOTKEY_3_46_2) Secure boot key Offset */
#define ROT_SECUREBOOTKEY_3_46_3_REG_OFST _UINT32_(0x34)      /* (ROT_SECUREBOOTKEY_3_46_3) Secure boot key Offset */
#define ROT_SECUREBOOTKEY_3_46_4_REG_OFST _UINT32_(0x38)      /* (ROT_SECUREBOOTKEY_3_46_4) Secure boot key Offset */
#define ROT_SECUREBOOTKEY_3_46_5_REG_OFST _UINT32_(0x3C)      /* (ROT_SECUREBOOTKEY_3_46_5) Secure boot key Offset */
#define ROT_SECUREBOOTKEY_3_46_6_REG_OFST _UINT32_(0x40)      /* (ROT_SECUREBOOTKEY_3_46_6) Secure boot key Offset */
#define ROT_SECUREBOOTKEY_3_46_7_REG_OFST _UINT32_(0x44)      /* (ROT_SECUREBOOTKEY_3_46_7) Secure boot key Offset */
#define ROT_SECUREBOOTKEY_3_46_8_REG_OFST _UINT32_(0x48)      /* (ROT_SECUREBOOTKEY_3_46_8) Secure boot key Offset */
#define ROT_SECUREBOOTKEY_3_46_9_REG_OFST _UINT32_(0x4C)      /* (ROT_SECUREBOOTKEY_3_46_9) Secure boot key Offset */
#define ROT_SECUREBOOTKEY_3_46_10_REG_OFST _UINT32_(0x50)      /* (ROT_SECUREBOOTKEY_3_46_10) Secure boot key Offset */
#define ROT_SECUREBOOTKEY_47_48_STORAGE_KEY_REG_OFST _UINT32_(0x54)      /* (ROT_SECUREBOOTKEY_47_48_STORAGE_KEY) Secure boot key, Storage Key Offset */
#define ROT_STORAGE_KEY_3_30_REG_OFST  _UINT32_(0x58)      /* (ROT_STORAGE_KEY_3_30) Storage Key Offset */
#define ROT_STORAGE_KEY_3_30_0_REG_OFST _UINT32_(0x58)      /* (ROT_STORAGE_KEY_3_30_0) Storage Key Offset */
#define ROT_STORAGE_KEY_3_30_1_REG_OFST _UINT32_(0x5C)      /* (ROT_STORAGE_KEY_3_30_1) Storage Key Offset */
#define ROT_STORAGE_KEY_3_30_2_REG_OFST _UINT32_(0x60)      /* (ROT_STORAGE_KEY_3_30_2) Storage Key Offset */
#define ROT_STORAGE_KEY_3_30_3_REG_OFST _UINT32_(0x64)      /* (ROT_STORAGE_KEY_3_30_3) Storage Key Offset */
#define ROT_STORAGE_KEY_3_30_4_REG_OFST _UINT32_(0x68)      /* (ROT_STORAGE_KEY_3_30_4) Storage Key Offset */
#define ROT_STORAGE_KEY_3_30_5_REG_OFST _UINT32_(0x6C)      /* (ROT_STORAGE_KEY_3_30_5) Storage Key Offset */
#define ROT_STORAGE_KEY_3_30_6_REG_OFST _UINT32_(0x70)      /* (ROT_STORAGE_KEY_3_30_6) Storage Key Offset */
#define ROT_STORAGE_KEY_FFCFG_REG_OFST _UINT32_(0x74)      /* (ROT_STORAGE_KEY_FFCFG) Storage Key, FFCFG Offset */
#define ROT_DEVICE_ID_PATCH_CFG_REG_OFST _UINT32_(0x78)      /* (ROT_DEVICE_ID_PATCH_CFG) Device ID and Patch CFG Offset */
#define ROT_PATCH_CFG_REG_OFST         _UINT32_(0x7C)      /* (ROT_PATCH_CFG) Patch CFG Offset */
#define ROT_PATCH_CODE_REG_OFST        _UINT32_(0x80)      /* (ROT_PATCH_CODE) Patch Code Offset */
#define ROT_PATCH_CODE0_REG_OFST       _UINT32_(0x80)      /* (ROT_PATCH_CODE0) Patch Code Offset */
#define ROT_PATCH_CODE1_REG_OFST       _UINT32_(0x84)      /* (ROT_PATCH_CODE1) Patch Code Offset */
#define ROT_PATCH_CODE2_REG_OFST       _UINT32_(0x88)      /* (ROT_PATCH_CODE2) Patch Code Offset */
#define ROT_PATCH_CODE3_REG_OFST       _UINT32_(0x8C)      /* (ROT_PATCH_CODE3) Patch Code Offset */
#define ROT_PATCH_CODE4_REG_OFST       _UINT32_(0x90)      /* (ROT_PATCH_CODE4) Patch Code Offset */
#define ROT_PATCH_CODE5_REG_OFST       _UINT32_(0x94)      /* (ROT_PATCH_CODE5) Patch Code Offset */
#define ROT_PATCH_CODE6_REG_OFST       _UINT32_(0x98)      /* (ROT_PATCH_CODE6) Patch Code Offset */
#define ROT_PATCH_CODE7_REG_OFST       _UINT32_(0x9C)      /* (ROT_PATCH_CODE7) Patch Code Offset */
#define ROT_PATCH_CODE8_REG_OFST       _UINT32_(0xA0)      /* (ROT_PATCH_CODE8) Patch Code Offset */
#define ROT_PATCH_CODE9_REG_OFST       _UINT32_(0xA4)      /* (ROT_PATCH_CODE9) Patch Code Offset */
#define ROT_PATCH_CODE10_REG_OFST      _UINT32_(0xA8)      /* (ROT_PATCH_CODE10) Patch Code Offset */
#define ROT_PATCH_CODE11_REG_OFST      _UINT32_(0xAC)      /* (ROT_PATCH_CODE11) Patch Code Offset */
#define ROT_PATCH_CODE12_REG_OFST      _UINT32_(0xB0)      /* (ROT_PATCH_CODE12) Patch Code Offset */
#define ROT_PATCH_CODE13_REG_OFST      _UINT32_(0xB4)      /* (ROT_PATCH_CODE13) Patch Code Offset */
#define ROT_PATCH_CODE14_REG_OFST      _UINT32_(0xB8)      /* (ROT_PATCH_CODE14) Patch Code Offset */
#define ROT_PATCH_CODE15_REG_OFST      _UINT32_(0xBC)      /* (ROT_PATCH_CODE15) Patch Code Offset */
#define ROT_PATCH_CODE16_REG_OFST      _UINT32_(0xC0)      /* (ROT_PATCH_CODE16) Patch Code Offset */
#define ROT_PATCH_CODE17_REG_OFST      _UINT32_(0xC4)      /* (ROT_PATCH_CODE17) Patch Code Offset */
#define ROT_PATCH_CODE18_REG_OFST      _UINT32_(0xC8)      /* (ROT_PATCH_CODE18) Patch Code Offset */
#define ROT_PATCH_CODE19_REG_OFST      _UINT32_(0xCC)      /* (ROT_PATCH_CODE19) Patch Code Offset */
#define ROT_PATCH_CODE20_REG_OFST      _UINT32_(0xD0)      /* (ROT_PATCH_CODE20) Patch Code Offset */
#define ROT_PATCH_CODE21_REG_OFST      _UINT32_(0xD4)      /* (ROT_PATCH_CODE21) Patch Code Offset */
#define ROT_PATCH_CODE22_REG_OFST      _UINT32_(0xD8)      /* (ROT_PATCH_CODE22) Patch Code Offset */
#define ROT_PATCH_CODE23_REG_OFST      _UINT32_(0xDC)      /* (ROT_PATCH_CODE23) Patch Code Offset */
#define ROT_PATCH_CODE24_REG_OFST      _UINT32_(0xE0)      /* (ROT_PATCH_CODE24) Patch Code Offset */
#define ROT_PATCH_CODE25_REG_OFST      _UINT32_(0xE4)      /* (ROT_PATCH_CODE25) Patch Code Offset */
#define ROT_PATCH_CODE26_REG_OFST      _UINT32_(0xE8)      /* (ROT_PATCH_CODE26) Patch Code Offset */
#define ROT_PATCH_CODE27_REG_OFST      _UINT32_(0xEC)      /* (ROT_PATCH_CODE27) Patch Code Offset */
#define ROT_PATCH_CODE28_REG_OFST      _UINT32_(0xF0)      /* (ROT_PATCH_CODE28) Patch Code Offset */
#define ROT_PATCH_CODE29_REG_OFST      _UINT32_(0xF4)      /* (ROT_PATCH_CODE29) Patch Code Offset */
#define ROT_PATCH_CODE30_REG_OFST      _UINT32_(0xF8)      /* (ROT_PATCH_CODE30) Patch Code Offset */
#define ROT_PATCH_CODE31_REG_OFST      _UINT32_(0xFC)      /* (ROT_PATCH_CODE31) Patch Code Offset */
#define ROT_PATCH_CODE32_REG_OFST      _UINT32_(0x100)     /* (ROT_PATCH_CODE32) Patch Code Offset */
#define ROT_PATCH_CODE33_REG_OFST      _UINT32_(0x104)     /* (ROT_PATCH_CODE33) Patch Code Offset */
#define ROT_PATCH_CODE34_REG_OFST      _UINT32_(0x108)     /* (ROT_PATCH_CODE34) Patch Code Offset */
#define ROT_PATCH_CODE35_REG_OFST      _UINT32_(0x10C)     /* (ROT_PATCH_CODE35) Patch Code Offset */
#define ROT_PATCH_CODE36_REG_OFST      _UINT32_(0x110)     /* (ROT_PATCH_CODE36) Patch Code Offset */
#define ROT_PATCH_CODE37_REG_OFST      _UINT32_(0x114)     /* (ROT_PATCH_CODE37) Patch Code Offset */
#define ROT_PATCH_CODE38_REG_OFST      _UINT32_(0x118)     /* (ROT_PATCH_CODE38) Patch Code Offset */
#define ROT_PATCH_CODE39_REG_OFST      _UINT32_(0x11C)     /* (ROT_PATCH_CODE39) Patch Code Offset */
#define ROT_PATCH_CODE40_REG_OFST      _UINT32_(0x120)     /* (ROT_PATCH_CODE40) Patch Code Offset */
#define ROT_PATCH_CODE41_REG_OFST      _UINT32_(0x124)     /* (ROT_PATCH_CODE41) Patch Code Offset */
#define ROT_PATCH_CODE42_REG_OFST      _UINT32_(0x128)     /* (ROT_PATCH_CODE42) Patch Code Offset */
#define ROT_PATCH_CODE43_REG_OFST      _UINT32_(0x12C)     /* (ROT_PATCH_CODE43) Patch Code Offset */
#define ROT_PATCH_CODE44_REG_OFST      _UINT32_(0x130)     /* (ROT_PATCH_CODE44) Patch Code Offset */
#define ROT_PATCH_CODE45_REG_OFST      _UINT32_(0x134)     /* (ROT_PATCH_CODE45) Patch Code Offset */
#define ROT_PATCH_CODE46_REG_OFST      _UINT32_(0x138)     /* (ROT_PATCH_CODE46) Patch Code Offset */
#define ROT_PATCH_CODE47_REG_OFST      _UINT32_(0x13C)     /* (ROT_PATCH_CODE47) Patch Code Offset */
#define ROT_PATCH_CODE48_REG_OFST      _UINT32_(0x140)     /* (ROT_PATCH_CODE48) Patch Code Offset */
#define ROT_PATCH_CODE49_REG_OFST      _UINT32_(0x144)     /* (ROT_PATCH_CODE49) Patch Code Offset */
#define ROT_PATCH_CODE50_REG_OFST      _UINT32_(0x148)     /* (ROT_PATCH_CODE50) Patch Code Offset */
#define ROT_PATCH_CODE51_REG_OFST      _UINT32_(0x14C)     /* (ROT_PATCH_CODE51) Patch Code Offset */
#define ROT_PATCH_CODE52_REG_OFST      _UINT32_(0x150)     /* (ROT_PATCH_CODE52) Patch Code Offset */
#define ROT_UUID_REG_OFST              _UINT32_(0x1D8)     /* (ROT_UUID) Unique ID Offset */
#define ROT_UUID0_REG_OFST             _UINT32_(0x1D8)     /* (ROT_UUID0) Unique ID Offset */
#define ROT_UUID1_REG_OFST             _UINT32_(0x1DC)     /* (ROT_UUID1) Unique ID Offset */
#define ROT_UUID2_REG_OFST             _UINT32_(0x1E0)     /* (ROT_UUID2) Unique ID Offset */
#define ROT_UUID3_REG_OFST             _UINT32_(0x1E4)     /* (ROT_UUID3) Unique ID Offset */
#define ROT_SEC_BOOT_REG_OFST          _UINT32_(0xC00)     /* (ROT_SEC_BOOT) Secure Boot Register Offset */
#define ROT_EFUSE_RWDATA_REG_OFST      _UINT32_(0xC04)     /* (ROT_EFUSE_RWDATA) EFuse RW Data Register Offset */
#define ROT_EFUSE_CON_REG_OFST         _UINT32_(0xC08)     /* (ROT_EFUSE_CON) Efuse Configuration Register2 Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* ROT register API structure */
typedef struct
{  /* Secure Root of Trust Macro */
  __IO  uint32_t                       ROT_SECCFG;         /* Offset: 0x00 (R/W  32) Secure Configuration HOLDING REGISTER1,2 */
  __IO  uint32_t                       ROT_ANTIROLLBACKCOUNTER[8]; /* Offset: 0x04 (R/W  32) Anti Roll back counter */
  __IO  uint32_t                       ROT_LIFECYCLECTR_BOOTKEY; /* Offset: 0x24 (R/W  32) Life cycle counter and Secure boot key LSB bytes */
  __IO  uint32_t                       ROT_SECUREBOOTKEY_3_46[11]; /* Offset: 0x28 (R/W  32) Secure boot key */
  __IO  uint32_t                       ROT_SECUREBOOTKEY_47_48_STORAGE_KEY; /* Offset: 0x54 (R/W  32) Secure boot key, Storage Key */
  __IO  uint32_t                       ROT_STORAGE_KEY_3_30[7]; /* Offset: 0x58 (R/W  32) Storage Key */
  __IO  uint32_t                       ROT_STORAGE_KEY_FFCFG; /* Offset: 0x74 (R/W  32) Storage Key, FFCFG */
  __IO  uint32_t                       ROT_DEVICE_ID_PATCH_CFG; /* Offset: 0x78 (R/W  32) Device ID and Patch CFG */
  __IO  uint32_t                       ROT_PATCH_CFG;      /* Offset: 0x7C (R/W  32) Patch CFG */
  __IO  uint32_t                       ROT_PATCH_CODE[53]; /* Offset: 0x80 (R/W  32) Patch Code */
  __I   uint8_t                        Reserved1[0x84];
  __IO  uint32_t                       ROT_UUID[4];        /* Offset: 0x1D8 (R/W  32) Unique ID */
  __I   uint8_t                        Reserved2[0xA18];
  __IO  uint32_t                       ROT_SEC_BOOT;       /* Offset: 0xC00 (R/W  32) Secure Boot Register */
  __IO  uint32_t                       ROT_EFUSE_RWDATA;   /* Offset: 0xC04 (R/W  32) EFuse RW Data Register */
  __IO  uint32_t                       ROT_EFUSE_CON;      /* Offset: 0xC08 (R/W  32) Efuse Configuration Register2 */
} rot_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _WBZ35_ROT_COMPONENT_H_ */
