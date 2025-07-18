/*
 * Instance header file for PIC32CM5112GC00100
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

/* file generated from device description file (ATDF) version 2024-11-05T16:47:43Z */
#ifndef _PIC32CMGC00_RSTC_INSTANCE_
#define _PIC32CMGC00_RSTC_INSTANCE_


/* ========== Instance Parameter definitions for RSTC peripheral ========== */
#define RSTC_BACKUP_IMPLEMENTED                  (1)        
#define RSTC_BRIDGE_ID                           (2)        /* H2PB Bridge ID */
#define RSTC_CM_DBGRESET_STRETCHED               (3)        /* Reset stretcher size for Cortex CPU related to DBGRESET. */
#define RSTC_CM_HRESET_N_STRETCHED               (3)        /* Reset stretcher size for Cortex CPU related to HRESETn. */
#define RSTC_CM_PORESET_STRETCHED                (3)        /* Reset stretcher size for Cortex CPU related to PORESET. */
#define RSTC_HIB_IMPLEMENTED                     (1)        
#define RSTC_INSTANCE_ID                         (5)        /* Instance index for RSTC */
#define RSTC_MCLK_ID_APB                         (5)        /* Index for RSTC APB clock */
#define RSTC_PAC_ID                              (5)        /* Index for RSTC registers write protection */
#define RSTC_PERIPH_ID                           (2)        /* H2PB Peripheral ID */
#define RSTC_VBAT_IMPLEMENTED                    (0)        /* One if VBAT (Battery backup mode) is supported */

#endif /* _PIC32CMGC00_RSTC_INSTANCE_ */
