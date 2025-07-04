/*******************************************************************************
  Non-Volatile Memory Controller(FCW) PLIB.

  Company:
    Microchip Technology Inc.

  File Name:
    plib_fcw.h

  Summary:
    Interface definition of FCW Plib.

  Description:
    This file defines the interface for the FCW Plib.
    It allows user to Program, Erase and lock the on-chip Non Volatile Flash
    Memory.

*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

#ifndef PLIB_FCW_H
#define PLIB_FCW_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "device.h"     // For device registers and uint32_t
#include <stdbool.h>    // For bool

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C++ Compatibility

    extern "C" {

#endif

// DOM-IGNORE-END

#define FCW_FLASH_START_ADDRESS    (0xC000000U)
#define FCW_FLASH_ROWSIZE          (1024U)
#define FCW_FLASH_PAGESIZE         (4096U)



 /* Bank/Panel 1 */
#define    PROGRAM_FLASH_BANK_1    (0U)

/* Bank/Panel 2 */
#define    PROGRAM_FLASH_BANK_2    (1U)

typedef uint32_t PROGRAM_FLASH_BANK;

    /* Boot Flash Page 0 Write Protect */
#define    FCW_BOOT_WRITE_PROTECT_PAGE_0     (1U << 0U)

    /* Boot Flash Page 1 Write Protect */
#define    FCW_BOOT_WRITE_PROTECT_PAGE_1     (1U << 1U)

    /* Boot Flash Page 2 Write Protect */
#define    FCW_BOOT_WRITE_PROTECT_PAGE_2     (1U << 2U)

    /* Boot Flash Page 3 Write Protect */
#define    FCW_BOOT_WRITE_PROTECT_PAGE_3     (1U << 3U)

    /* Boot Flash Page 4 Write Protect */
#define    FCW_BOOT_WRITE_PROTECT_PAGE_4     (1U << 4U)

    /* Boot Flash Page 5 Write Protect */
#define    FCW_BOOT_WRITE_PROTECT_PAGE_5     (1U << 5U)

    /* Boot Flash Page 6 Write Protect */
#define    FCW_BOOT_WRITE_PROTECT_PAGE_6     (1U << 6U)

    /* Boot Flash Page 7 Write Protect */
#define    FCW_BOOT_WRITE_PROTECT_PAGE_7     (1U << 7U)

    /* Boot Flash Page 8 Write Protect */
#define    FCW_BOOT_WRITE_PROTECT_PAGE_8     (1U << 8U)

    /* Boot Flash Page 9 Write Protect */
#define   FCW_BOOT_WRITE_PROTECT_PAGE_9      (1U << 9U)

    /* Boot Flash Page 10 Write Protect */
#define    FCW_BOOT_WRITE_PROTECT_PAGE_10    (1U << 10U)

    /* Boot Flash Page 11 Write Protect */
#define    FCW_BOOT_WRITE_PROTECT_PAGE_11    (1U << 11U)

    /* Boot Flash Page 12 Write Protect */
#define    FCW_BOOT_WRITE_PROTECT_PAGE_12    (1U << 12U)

    /* Boot Flash Page 13 Write Protect */
#define    FCW_BOOT_WRITE_PROTECT_PAGE_13    (1U << 13U)

    /* Boot Flash Page 14 Write Protect */
#define    FCW_BOOT_WRITE_PROTECT_PAGE_14    (1U << 14U)

    /* Boot Flash Page15 Write Protect */
#define    FCW_BOOT_WRITE_PROTECT_PAGE_15    (1U << 15U)

typedef uint32_t FCW_BOOT_FLASH_WRITE_PROTECT;


/* No error */
#define    FCW_ERROR_NONE                  (0x0U)

/* FCW key error */
#define     FCW_ERROR_KEY                  (FCW_INTFLAG_KEYERR_Msk)

/* FCW configuration error */
#define     FCW_ERROR_CONFIGURATION        (FCW_INTFLAG_CFGERR_Msk)

/* FCW FIFO underrun error */    
#define     FCW_ERROR_FIFO_UNDERRUN        (FCW_INTFLAG_FIFOERR_Msk)

/* FCW AHB bus error */    
#define     FCW_ERROR_BUS_AHB              (FCW_INTFLAG_BUSERR_Msk)

/* FCW write protection error */    
#define     FCW_ERROR_WRITE_PROTECTION     (FCW_INTFLAG_WPERR_Msk)

/* FCW operation error */    
#define     FCW_ERROR_OPERATION            (FCW_INTFLAG_OPERR_Msk)

/* FCW security violation error */    
#define     FCW_ERROR_SECURITY_VIOLATION   (FCW_INTFLAG_SECERR_Msk)

/* FCW High Temperature detect error */    
#define     FCW_ERROR_HIGH_TEMP_DETECT     (FCW_INTFLAG_HTDPGM_Msk)

/* FCW Reset or Brown out detect error */    
#define     FCW_ERROR_RESET                (FCW_INTFLAG_BORERR_Msk)

/* FCW write error */
#define     FCW_ERROR_WRITE                (FCW_INTFLAG_WRERR_Msk)

typedef uint32_t FCW_ERROR;



typedef enum
{
    /* Bank/Panel 1 */
    BOOT_FLASH_BANK_1,

    /* Bank/Panel 2 */
    BOOT_FLASH_BANK_2

}BOOT_FLASH_BANK;
typedef enum{
    PFM_WP_REGION_0,
    PFM_WP_REGION_1,
    PFM_WP_REGION_2,
    PFM_WP_REGION_3,
    PFM_WP_REGION_4,
    PFM_WP_REGION_5,
    PFM_WP_REGION_6,
    PFM_WP_REGION_7,
}PFM_WP_REGION;

typedef struct
{
    uint32_t    regionBaseAddress;
    bool        mirrorEnable;
    uint32_t    regionSize;
}PFM_WP_REGION_SETUP; 



void FCW_Initialize( void );

bool FCW_Read( uint32_t *data, uint32_t length, const uint32_t address );

bool FCW_SingleDoubleWordWrite( uint32_t *data, uint32_t address );

bool FCW_QuadDoubleWordWrite( uint32_t *data, uint32_t address );

bool FCW_RowWrite( uint32_t *data, uint32_t address );

bool FCW_PageErase( uint32_t address );

FCW_ERROR FCW_ErrorGet( void );

bool FCW_IsBusy( void );

void FCW_ProgramFlashBankSelect( PROGRAM_FLASH_BANK pfmBank );

PROGRAM_FLASH_BANK FCW_ProgramFlashBankGet(void);

void FCW_PFM_WriteProtectRegionSetup( PFM_WP_REGION region, PFM_WP_REGION_SETUP setupStruct );

void FCW_PFM_WriteProtectEnable(PFM_WP_REGION region);

void FCW_PFM_WriteProtectDisable(PFM_WP_REGION region);

void FCW_PFM_WriteProtectLock(PFM_WP_REGION region);

void FCW_BootFlashWriteProtectEnable( BOOT_FLASH_BANK bootBank, FCW_BOOT_FLASH_WRITE_PROTECT writeProtectPage );

void FCW_BootFlashWriteProtectDisable(BOOT_FLASH_BANK bootBank, FCW_BOOT_FLASH_WRITE_PROTECT writeProtectPage );

void FCW_BootFlashWriteProtectLock( BOOT_FLASH_BANK bootBank );


// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C++ Compatibility

    }

#endif

// DOM-IGNORE-END
#endif // PLIB_FCW_H
