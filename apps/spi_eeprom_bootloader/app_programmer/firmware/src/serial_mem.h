/*******************************************************************************
  Serial Memory Header File

  Company:
    Microchip Technology Inc.

  File Name:
    serial_mem.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the Serial memory interface.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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
//DOM-IGNORE-END

#ifndef SERIAL_MEM_H
#define SERIAL_MEM_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

/* Structure to store the Meta Data of the application binary for bootloader
 * Note: The order of the members should not be changed
 */
typedef struct
{
    /* Used to Validate the Meta Data itself*/
    uint32_t prologue;

    /* Flag to indicate if a firmware update is required
     * 0xFFFFFFFF --> Update Required. Set by Serial Memory programmer after programming
     *                the image in Serial memory
     * 0x00000000 --> Update Completed. Changed by bootloader after programming
     *                the image from Serial memory to internal flash
     */
    uint32_t isAppUpdateRequired;

    /* Application Start address */
    uint32_t appStartAddress;

    /* Application Jump address */
    uint32_t appJumpAddress;
    
    /* Size of the application binary */
    uint32_t appSize;

    /* CRC32 value for the application binary */
    uint32_t appCRC32;

    /* Used to Validate the Meta Data itself*/
    uint32_t epilogue;

} SERIAL_MEM_META_DATA;

bool SERIAL_MEM_Ready ( void );

bool SERIAL_MEM_FlashTask ( uint32_t *tx_data , uint32_t length);

void SERIAL_MEM_Reset( void );

bool SERIAL_MEM_CRC32Generate(uint32_t length, uint32_t *crc);

bool SERIAL_MEM_UpdateMetaData(SERIAL_MEM_META_DATA *metaData);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* SERIAL_MEM_H */

/*******************************************************************************
 End of File
 */

