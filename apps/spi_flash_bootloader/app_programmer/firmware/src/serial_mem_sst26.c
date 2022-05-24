/*******************************************************************************
  Serial Memory Source File for SST26 Flash

  Company:
    Microchip Technology Inc.

  File Name:
    serial_mem_sst26.c

  Summary:
    This file contains the source code for accessing SST26 Flash

  Description:
    This file contains the source code for accessing SST26 Flash.
    It implements the logic of Erasing, reading and writing to SST26 Flash memory

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

#define SERIAL_MEM_PAGE_SIZE                DRV_SST26_PAGE_SIZE
#define SERIAL_MEM_ERASE_SIZE               DRV_SST26_ERASE_BUFFER_SIZE
#define SERIAL_MEM_PAGES_IN_SECTOR          (SERIAL_MEM_ERASE_SIZE / SERIAL_MEM_PAGE_SIZE)

#define SERIAL_MEM_APP_START_ADDRESS        (0x0U)

#define SERIAL_MEM_APP_UPDATE_REQUIRED      (0xFFFFFFFFU)
    
#define SERIAL_MEM_META_DATA_PROLOGUE       (0xDEADBEEFU)
#define SERIAL_MEM_META_DATA_EPILOGUE       (0xBEEFDEADU)
#define SERIAL_MEM_META_DATA_CLR            (0xFFFFFFFFU)

typedef struct
{
    DRV_HANDLE handle;

    DRV_SST26_GEOMETRY geometry;

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

static uint8_t CACHE_ALIGN crcBuffer[SERIAL_MEM_ERASE_SIZE];

void SERIAL_MEM_ReleaseResources(void)
{

}

static bool SERIAL_MEM_WaitForXferComplete( void )
{
    bool status = false;

    DRV_SST26_TRANSFER_STATUS transferStatus = DRV_SST26_TRANSFER_ERROR_UNKNOWN;

    do
    {
        transferStatus = DRV_SST26_TransferStatusGet(serialMemData.handle);

    } while (transferStatus == DRV_SST26_TRANSFER_BUSY);

    if(transferStatus == DRV_SST26_TRANSFER_COMPLETED)
    {
        status = true;
    }

    return status;
}

bool SERIAL_MEM_Ready( void )
{
    if (DRV_SST26_Status(DRV_SST26_INDEX) != SYS_STATUS_READY)
    {
        return false;
    }

    serialMemData.handle = DRV_SST26_Open(DRV_SST26_INDEX, DRV_IO_INTENT_READWRITE);

    if (serialMemData.handle == DRV_HANDLE_INVALID)
    {
        return false;
    }

    if (DRV_SST26_GeometryGet(serialMemData.handle, &serialMemData.geometry) == false)
    {
        DRV_SST26_Close(serialMemData.handle);

        return false;
    }

    serialMemData.serialFlashSize       = (serialMemData.geometry.read_blockSize * serialMemData.geometry.read_numBlocks);

    serialMemData.metaDataStartAddress  = ((DRV_SST26_START_ADDRESS + serialMemData.serialFlashSize) - SERIAL_MEM_ERASE_SIZE);

    return true;
}

bool SERIAL_MEM_FlashTask ( uint32_t *tx_data , uint32_t length)
{
    uint32_t addr       = serialMemData.flash_addr;
    uint32_t sector     = 0;
    uint32_t numSectors = 0;
    uint32_t page       = 0;

    if (length < SERIAL_MEM_ERASE_SIZE)
    {
        return false;
    }

    numSectors = (length / SERIAL_MEM_ERASE_SIZE);

    for (sector = 0; sector < numSectors; sector++)
    {
        if (DRV_SST26_SectorErase(serialMemData.handle, addr) == false)
        {
            return false;
        }

        if ( SERIAL_MEM_WaitForXferComplete() == false)
        {
            return false;
        }

        for (page = 0; page < SERIAL_MEM_PAGES_IN_SECTOR; page++)
        {
            if (DRV_SST26_PageWrite(serialMemData.handle, tx_data, addr) == false)
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
    }

    return true;
}

#if (USE_HW_CRC_GEN == true)

/* Function to Generate CRC using the device service unit peripheral on programmed data */
bool SERIAL_MEM_CRC32Generate(uint32_t length, uint32_t *crc)
{
    uint32_t i = 0;
    uint32_t addr = SERIAL_MEM_APP_START_ADDRESS;
    bool status = false;

    /* Initial Seed */
    *crc = 0xffffffff;

    for (i = 0; i < (length / SERIAL_MEM_ERASE_SIZE); i++)
    {
        memset((void *)crcBuffer, 0xFF, SERIAL_MEM_ERASE_SIZE);

        if (DRV_SST26_Read(serialMemData.handle, (uint32_t *)&crcBuffer, sizeof(crcBuffer), addr) == false)
        {
            return false;
        }

        if ( SERIAL_MEM_WaitForXferComplete() == false)
        {
            return false;
        }

        PAC_PeripheralProtectSetup (PAC_PERIPHERAL_DSU, PAC_PROTECTION_CLEAR);

        status = DSU_CRCCalculate ((uint32_t)crcBuffer, SERIAL_MEM_ERASE_SIZE, *crc, crc);

        PAC_PeripheralProtectSetup (PAC_PERIPHERAL_DSU, PAC_PROTECTION_SET);
        
        addr += SERIAL_MEM_ERASE_SIZE;
    }

    return status;
}

#else

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

    for (i = 0; i < length / SERIAL_MEM_ERASE_SIZE; i++)
    {
        memset((void *)crcBuffer, 0xFF, SERIAL_MEM_ERASE_SIZE);

        if (DRV_SST26_Read(serialMemData.handle, (uint32_t *)&crcBuffer, sizeof(crcBuffer), addr) == false)
        {
            return false;
        }

        if (SERIAL_MEM_WaitForXferComplete() == false)
        {
            return false;
        }

        for (j = 0; j < SERIAL_MEM_ERASE_SIZE; j++)
        {
            *crc = crc_tab[(*crc ^ crcBuffer[j]) & 0xff] ^ (*crc >> 8);
        }

        addr += SERIAL_MEM_ERASE_SIZE;
    }

    return true;
}
#endif

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

    if (DRV_SST26_SectorErase(serialMemData.handle, serialMemData.metaDataStartAddress) == false)
    {
        return false;
    }

    if ( SERIAL_MEM_WaitForXferComplete() == false)
    {
        return false;
    }

    if (DRV_SST26_PageWrite(serialMemData.handle, (uint32_t *)&serialMemMetaData, serialMemData.metaDataStartAddress) == false)
    {
        return false;
    }

    if ( SERIAL_MEM_WaitForXferComplete() == false)
    {
        return false;
    }

    if (DRV_SST26_Read(serialMemData.handle, (uint32_t *)&readMetaData, sizeof(readMetaData), serialMemData.metaDataStartAddress) == false)
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
