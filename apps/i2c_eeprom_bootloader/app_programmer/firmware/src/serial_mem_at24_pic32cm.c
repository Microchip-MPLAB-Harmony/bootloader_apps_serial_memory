/*******************************************************************************
  Serial Memory Source File for AT24 EEPROM

  Company:
    Microchip Technology Inc.

  File Name:
    serial_mem_at25.c

  Summary:
    This file contains the source code for accessing AT24 EEPROM

  Description:
    This file contains the source code for accessing AT24 EEPROM.
    It implements the logic of Erasing, reading and writing to AT24 EEPROM memory

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <string.h>
#include "definitions.h"
#include "serial_mem.h"


#ifndef DRV_AT24_EEPROM_START_ADDRESS
    #define DRV_AT24_EEPROM_START_ADDRESS    0x0
#endif

#define SERIAL_MEM_PAGE_SIZE                DRV_AT24_EEPROM_PAGE_SIZE
#define SERIAL_MEM_APP_START_ADDRESS        (0x0U)


#define SERIAL_MEM_APP_UPDATE_REQUIRED   (0xFFFFFFFFU)

#define SERIAL_MEM_META_DATA_PROLOGUE    (0xDEADBEEFU)
#define SERIAL_MEM_META_DATA_EPILOGUE    (0xBEEFDEADU)
#define SERIAL_MEM_META_DATA_CLR         (0xFFFFFFFFU)

typedef struct
{
    DRV_HANDLE handle;

    DRV_AT24_GEOMETRY geometry;

    uint32_t serialFlashSize;

    uint32_t metaDataStartAddress;

    uint32_t flash_addr;

} SERIAL_MEM_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

SERIAL_MEM_META_DATA CACHE_ALIGN readMetaData;

SERIAL_MEM_DATA CACHE_ALIGN serialMemData = {

    .flash_addr = SERIAL_MEM_APP_START_ADDRESS,

};

static uint8_t CACHE_ALIGN serialMemMetaData[SERIAL_MEM_PAGE_SIZE];

static uint8_t CACHE_ALIGN crcBuffer[SERIAL_MEM_PAGE_SIZE];

void SERIAL_MEM_ReleaseResources(void)
{

}

static bool SERIAL_MEM_WaitForXferComplete( void )
{
    bool status = false;

    DRV_AT24_TRANSFER_STATUS transferStatus = DRV_AT24_TRANSFER_STATUS_ERROR;

    do
    {
        transferStatus = DRV_AT24_TransferStatusGet(serialMemData.handle);

    } while (transferStatus == DRV_AT24_TRANSFER_STATUS_BUSY);

    if(transferStatus == DRV_AT24_TRANSFER_STATUS_COMPLETED)
    {
        status = true;
    }

    return status;
}

bool SERIAL_MEM_Ready( void )
{
    if (DRV_AT24_Status(DRV_AT24_INDEX) != SYS_STATUS_READY)
    {
        return false;
    }

    serialMemData.handle = DRV_AT24_Open(DRV_AT24_INDEX, DRV_IO_INTENT_READWRITE);

    if (serialMemData.handle == DRV_HANDLE_INVALID)
    {
        return false;
    }

    if (DRV_AT24_GeometryGet(serialMemData.handle, &serialMemData.geometry) == false)
    {
        DRV_AT24_Close(serialMemData.handle);

        return false;
    }

    serialMemData.serialFlashSize       = (serialMemData.geometry.readBlockSize * serialMemData.geometry.readNumBlocks);

    serialMemData.metaDataStartAddress  = ((DRV_AT24_EEPROM_START_ADDRESS + serialMemData.serialFlashSize) - SERIAL_MEM_PAGE_SIZE);

    return true;
}

bool SERIAL_MEM_FlashTask ( uint32_t *tx_data , uint32_t length)
{
    uint32_t addr       = serialMemData.flash_addr;
    uint32_t sector     = 0;
    uint32_t numSectors = 0;

    if (length < SERIAL_MEM_PAGE_SIZE)
    {
        return false;
    }

    numSectors = (length / SERIAL_MEM_PAGE_SIZE);

    for (sector = 0; sector < numSectors; sector++)
    {
        if (DRV_AT24_PageWrite(serialMemData.handle, tx_data, addr) == false)
        {
            return false;
        }

        if ( SERIAL_MEM_WaitForXferComplete() == false)
        {
            return false;
        }

        addr    += SERIAL_MEM_PAGE_SIZE;
        tx_data += (SERIAL_MEM_PAGE_SIZE / sizeof(uint32_t));
    }

    serialMemData.flash_addr = addr;

    return true;
}

bool SERIAL_MEM_CRC32Generate(uint32_t length, uint32_t *crc)
{
    uint32_t    addr = SERIAL_MEM_APP_START_ADDRESS;
    uint32_t    i, j, value;
    uint32_t    crc_tab[256];

    for (i = 0; i < 256; i++)
    {
        value = i;

        for (j = 0; j < 8; j++)
        {
            if (value & 1)
            {
                value = (value >> 1) ^ 0xEDB88320;
            }
            else
            {
                value >>= 1;
            }
        }
        crc_tab[i] = value;
    }

    /* Initial Seed */
    *crc = 0xFFFFFFFF;

    for (i = 0; i < (length / SERIAL_MEM_PAGE_SIZE); i++)
    {
        memset((void *)crcBuffer, 0xFF, SERIAL_MEM_PAGE_SIZE);

        if (DRV_AT24_Read(serialMemData.handle, (uint32_t *)&crcBuffer, sizeof(crcBuffer), addr) == false)
        {
            return false;
        }

        if (SERIAL_MEM_WaitForXferComplete() == false)
        {
            return false;
        }

        for (j = 0; j < SERIAL_MEM_PAGE_SIZE; j++)
        {
            *crc = crc_tab[(*crc ^ crcBuffer[j]) & 0xff] ^ (*crc >> 8);
        }

        addr += SERIAL_MEM_PAGE_SIZE;
    }

    return true;
}

void SERIAL_MEM_Reset( void )
{
    serialMemData.flash_addr = SERIAL_MEM_APP_START_ADDRESS;
}

bool SERIAL_MEM_UpdateMetaData(SERIAL_MEM_META_DATA *metaData)
{
    SERIAL_MEM_META_DATA *metaDataPtr = (SERIAL_MEM_META_DATA *)serialMemMetaData;

    memset(serialMemMetaData, 0xFF, sizeof(serialMemMetaData));

    metaDataPtr->appStartAddress        = metaData->appStartAddress;
    metaDataPtr->appJumpAddress         = metaData->appJumpAddress;
    metaDataPtr->appSize                = metaData->appSize;
    metaDataPtr->appCRC32               = metaData->appCRC32;
    metaDataPtr->isAppUpdateRequired    = SERIAL_MEM_APP_UPDATE_REQUIRED;
    metaDataPtr->prologue               = SERIAL_MEM_META_DATA_PROLOGUE;
    metaDataPtr->epilogue               = SERIAL_MEM_META_DATA_EPILOGUE;

    if (DRV_AT24_PageWrite(serialMemData.handle, (uint32_t *)&serialMemMetaData, serialMemData.metaDataStartAddress) == false)
    {
        return false;
    }

    if ( SERIAL_MEM_WaitForXferComplete() == false)
    {
        return false;
    }

    if (DRV_AT24_Read(serialMemData.handle, (uint32_t *)&readMetaData, sizeof(readMetaData), serialMemData.metaDataStartAddress) == false)
    {
        return false;
    }

    if ( SERIAL_MEM_WaitForXferComplete() == false)
    {
        return false;
    }

    if (memcmp((void *)&readMetaData, (void *)&serialMemMetaData, sizeof(readMetaData)) != 0)
    {
        return false;
    }

    return true;
}

/*******************************************************************************
 End of File
 */
