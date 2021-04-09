/*******************************************************************************
  System Initialization File

  File Name:
    initialization.c

  Summary:
    This file contains source code necessary to initialize the system.

  Description:
    This file contains source code necessary to initialize the system.  It
    implements the "SYS_Initialize" function, defines the configuration bits,
    and allocates any necessary global system resources,
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "configuration.h"
#include "definitions.h"
#include "device.h"



// ****************************************************************************
// ****************************************************************************
// Section: Configuration Bits
// ****************************************************************************
// ****************************************************************************




/*** FBCFG0 ***/
#pragma config BUHSWEN =    OFF
#pragma config PCSCMODE =    DUAL
#pragma config BOOTISA =    MIPS32



/*** DEVCFG0 ***/
#pragma config TDOEN =      ON
#pragma config TROEN =     OFF
#pragma config JTAGEN =     OFF
#pragma config FCPRI =      LRSA
#pragma config DMAPRI =    LRSA
#pragma config EXLPRI =    LRSA
#pragma config USBSSEN =     OFF
#pragma config PMULOCK =     OFF
#pragma config PGLOCK =      OFF
#pragma config PMDLOCK =   OFF
#pragma config IOLOCK =  OFF
#pragma config CFGLOCK =   OFF
#pragma config OC_ACLK =  OCMP_TMR2_TMR3
#pragma config IC_ACLK =  ICAP_TMR2_TMR3
#pragma config CANFDDIV =  0
#pragma config PCM =  SFR
#pragma config UPLLHWMD =  OFF
#pragma config SPLLHWMD =   OFF
#pragma config BTPLLHWMD =        OFF
#pragma config ETHPLLHWMD =        OFF
#pragma config FECCCON =         OFF
#pragma config ETHTPSF =         RPSF
#pragma config EPGMCLK =         FRC


/*** DEVCFG1 ***/
#pragma config DEBUG =         EMUC
#pragma config ICESEL =         ICS_PGx2
#pragma config TRCEN =         ON
#pragma config FMIIEN =         OFF
#pragma config ETHEXEREF =         OFF
#pragma config CLASSBDIS =         DISABLE
#pragma config USBIDIO =         ON
#pragma config VBUSIO =         ON
#pragma config HSSPIEN =         ON
#pragma config SMCLR =      MCLR_NORM
#pragma config USBDMTRIM =      0
#pragma config USBDPTRIM =      0
#pragma config HSUARTEN =    ON
#pragma config WDTPSS =    PSS1



/*** DEVCFG2 ***/
#pragma config DMTINTV =    WIN_63_64
#pragma config POSCMOD =    HS
#pragma config WDTRMCS =    LPRC
#pragma config SOSCSEL =    CRYSTAL
#pragma config WAKE2SPD =    ON
#pragma config CKSWEN =    ON
#pragma config FSCMEN =    ON
#pragma config WDTPS =    PS1
#pragma config WDTSPGM =    STOP
#pragma config WINDIS =    NORMAL
#pragma config WDTEN =    OFF
#pragma config WDTWINSZ =    WINSZ_25
#pragma config DMTCNT =    DMT31
#pragma config DMTEN =    OFF



/*** DEVCFG4 ***/
#pragma config SOSCCFG =    0
#pragma config VBZPBOREN =    ON
#pragma config DSZPBOREN =    ON
#pragma config DSWDTPS =    DSPS1
#pragma config DSWDTOSC =    LPRC
#pragma config DSWDTEN =    OFF
#pragma config DSEN =    OFF
#pragma config SOSCEN =    OFF




// *****************************************************************************
// *****************************************************************************
// Section: Driver Initialization Data
// *****************************************************************************
// *****************************************************************************
// <editor-fold defaultstate="collapsed" desc="DRV_SDSPI Instance 0 Initialization Data">

/* SDSPI Client Objects Pool */
static DRV_SDSPI_CLIENT_OBJ drvSDSPI0ClientObjPool[DRV_SDSPI_CLIENTS_NUMBER_IDX0];

/* SDSPI Transfer Objects Pool */
static DRV_SDSPI_BUFFER_OBJ drvSDSPI0TransferObjPool[DRV_SDSPI_QUEUE_SIZE_IDX0];

/* SPI PLIB Interface Initialization for SDSPI Driver */
const DRV_SDSPI_PLIB_INTERFACE drvSDSPI0PlibAPI = {

    /* SPI PLIB WriteRead function */
    .writeRead = (DRV_SDSPI_PLIB_WRITEREAD)SPI2_WriteRead,

    /* SPI PLIB Write function */
    .write = (DRV_SDSPI_PLIB_WRITE)SPI2_Write,

    /* SPI PLIB Read function */
    .read = (DRV_SDSPI_PLIB_READ)SPI2_Read,

    /* SPI PLIB Transfer Status function */
    .isBusy = (DRV_SDSPI_PLIB_IS_BUSY)SPI2_IsBusy,

    .transferSetup = (DRV_SDSPI_PLIB_SETUP)SPI2_TransferSetup,

    /* SPI PLIB Callback Register */
    .callbackRegister = (DRV_SDSPI_PLIB_CALLBACK_REGISTER)SPI2_CallbackRegister,
};

const uint32_t drvSDSPI0remapDataBits[]= { 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000400 };
const uint32_t drvSDSPI0remapClockPolarity[] = { 0x00000000, 0x00000040 };
const uint32_t drvSDSPI0remapClockPhase[] = { 0x00000000, 0x00000100 };

/* SDSPI Driver Initialization Data */
const DRV_SDSPI_INIT drvSDSPI0InitData =
{
    /* SD Card SPI PLIB API interface*/
    .spiPlib                = &drvSDSPI0PlibAPI,

    .remapDataBits          = drvSDSPI0remapDataBits,

    .remapClockPolarity     = drvSDSPI0remapClockPolarity,

    .remapClockPhase        = drvSDSPI0remapClockPhase,


    /* SDSPI Number of clients */
    .numClients             = DRV_SDSPI_CLIENTS_NUMBER_IDX0,

    /* SDSPI Client Objects Pool */
    .clientObjPool          = (uintptr_t)&drvSDSPI0ClientObjPool[0],

    /* SDSPI Transfer Objects Pool */
    .bufferObjPool          = (uintptr_t)&drvSDSPI0TransferObjPool[0],

    /* SDSPI Transfer Objects Queue Size */
    .bufferObjPoolSize      = DRV_SDSPI_QUEUE_SIZE_IDX0,

    .chipSelectPin          = DRV_SDSPI_CHIP_SELECT_PIN_IDX0,

    .sdcardSpeedHz          = DRV_SDSPI_SPEED_HZ_IDX0,

    .pollingIntervalMs      = DRV_SDSPI_POLLING_INTERVAL_MS_IDX0,

    .writeProtectPin        = SYS_PORT_PIN_NONE,

    .isFsEnabled            = true,

    /* DMA Channel for Transmit */
    .txDMAChannel           = SYS_DMA_CHANNEL_NONE,

    /* DMA Channel for Receive */
    .rxDMAChannel           = SYS_DMA_CHANNEL_NONE,
};

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="DRV_SST26 Initialization Data">

const DRV_SST26_PLIB_INTERFACE drvSST26PlibAPI = {
    .writeRead          = (DRV_SST26_PLIB_WRITE_READ)SPI1_WriteRead,
    .write              = (DRV_SST26_PLIB_WRITE)SPI1_Write,
    .read               = (DRV_SST26_PLIB_READ)SPI1_Read,
    .isBusy             = (DRV_SST26_PLIB_IS_BUSY)SPI1_IsBusy,
    .callbackRegister   = (DRV_SST26_PLIB_CALLBACK_REGISTER)SPI1_CallbackRegister,
};

const DRV_SST26_INIT drvSST26InitData =
{
    .sst26Plib      = &drvSST26PlibAPI,
    .chipSelectPin  = DRV_SST26_CHIP_SELECT_PIN
};
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="DRV_MEMORY Instance 0 Initialization Data">

static uint8_t gDrvMemory0EraseBuffer[DRV_SST26_ERASE_BUFFER_SIZE] CACHE_ALIGN;

static DRV_MEMORY_CLIENT_OBJECT gDrvMemory0ClientObject[DRV_MEMORY_CLIENTS_NUMBER_IDX0];

static DRV_MEMORY_BUFFER_OBJECT gDrvMemory0BufferObject[DRV_MEMORY_BUFFER_QUEUE_SIZE_IDX0];

const DRV_MEMORY_DEVICE_INTERFACE drvMemory0DeviceAPI = {
    .Open               = DRV_SST26_Open,
    .Close              = DRV_SST26_Close,
    .Status             = DRV_SST26_Status,
    .SectorErase        = DRV_SST26_SectorErase,
    .Read               = DRV_SST26_Read,
    .PageWrite          = DRV_SST26_PageWrite,
    .EventHandlerSet    = (DRV_MEMORY_DEVICE_EVENT_HANDLER_SET)DRV_SST26_EventHandlerSet,
    .GeometryGet        = (DRV_MEMORY_DEVICE_GEOMETRY_GET)DRV_SST26_GeometryGet,
    .TransferStatusGet  = (DRV_MEMORY_DEVICE_TRANSFER_STATUS_GET)DRV_SST26_TransferStatusGet
};

const DRV_MEMORY_INIT drvMemory0InitData =
{
    .memDevIndex                = DRV_SST26_INDEX,
    .memoryDevice               = &drvMemory0DeviceAPI,
    .isMemDevInterruptEnabled   = true,
    .isFsEnabled                = true,
    .deviceMediaType            = (uint8_t)SYS_FS_MEDIA_TYPE_SPIFLASH,
    .ewBuffer                   = &gDrvMemory0EraseBuffer[0],
    .clientObjPool              = (uintptr_t)&gDrvMemory0ClientObject[0],
    .bufferObj                  = (uintptr_t)&gDrvMemory0BufferObject[0],
    .queueSize                  = DRV_MEMORY_BUFFER_QUEUE_SIZE_IDX0,
    .nClientsMax                = DRV_MEMORY_CLIENTS_NUMBER_IDX0
};

// </editor-fold>


// *****************************************************************************
// *****************************************************************************
// Section: System Data
// *****************************************************************************
// *****************************************************************************
/* Structure to hold the object handles for the modules in the system. */
SYSTEM_OBJECTS sysObj;

// *****************************************************************************
// *****************************************************************************
// Section: Library/Stack Initialization Data
// *****************************************************************************
// *****************************************************************************
// <editor-fold defaultstate="collapsed" desc="File System Initialization Data">

const SYS_FS_MEDIA_MOUNT_DATA sysfsMountTable[SYS_FS_VOLUME_NUMBER] =
{
    {
        .mountName = SYS_FS_MEDIA_IDX0_MOUNT_NAME_VOLUME_IDX0,
        .devName   = SYS_FS_MEDIA_IDX0_DEVICE_NAME_VOLUME_IDX0,
        .mediaType = SYS_FS_MEDIA_TYPE_IDX0,
        .fsType   = SYS_FS_TYPE_IDX0
    },
    {
        .mountName = SYS_FS_MEDIA_IDX1_MOUNT_NAME_VOLUME_IDX0,
        .devName   = SYS_FS_MEDIA_IDX1_DEVICE_NAME_VOLUME_IDX0,
        .mediaType = SYS_FS_MEDIA_TYPE_IDX1,
        .fsType   = SYS_FS_TYPE_IDX1
    },
};


const SYS_FS_FUNCTIONS FatFsFunctions =
{
    .mount             = FATFS_mount,
    .unmount           = FATFS_unmount,
    .open              = FATFS_open,
    .read              = FATFS_read,
    .close             = FATFS_close,
    .seek              = FATFS_lseek,
    .fstat             = FATFS_stat,
    .getlabel          = FATFS_getlabel,
    .currWD            = FATFS_getcwd,
    .getstrn           = FATFS_gets,
    .openDir           = FATFS_opendir,
    .readDir           = FATFS_readdir,
    .closeDir          = FATFS_closedir,
    .chdir             = FATFS_chdir,
    .chdrive           = FATFS_chdrive,
    .write             = FATFS_write,
    .tell              = FATFS_tell,
    .eof               = FATFS_eof,
    .size              = FATFS_size,
    .mkdir             = FATFS_mkdir,
    .remove            = FATFS_unlink,
    .setlabel          = FATFS_setlabel,
    .truncate          = FATFS_truncate,
    .chmode            = FATFS_chmod,
    .chtime            = FATFS_utime,
    .rename            = FATFS_rename,
    .sync              = FATFS_sync,
    .putchr            = FATFS_putc,
    .putstrn           = FATFS_puts,
    .formattedprint    = FATFS_printf,
    .testerror         = FATFS_error,
    .formatDisk        = (FORMAT_DISK)FATFS_mkfs,
    .partitionDisk     = FATFS_fdisk,
    .getCluster        = FATFS_getclusters
};


const SYS_FS_REGISTRATION_TABLE sysFSInit [ SYS_FS_MAX_FILE_SYSTEM_TYPE ] =
{
    {
        .nativeFileSystemType = FAT,
        .nativeFileSystemFunctions = &FatFsFunctions
    }
};

// </editor-fold>



// *****************************************************************************
// *****************************************************************************
// Section: System Initialization
// *****************************************************************************
// *****************************************************************************
// <editor-fold defaultstate="collapsed" desc="SYS_TIME Initialization Data">

const SYS_TIME_PLIB_INTERFACE sysTimePlibAPI = {
    .timerCallbackSet = (SYS_TIME_PLIB_CALLBACK_REGISTER)CORETIMER_CallbackSet,
    .timerStart = (SYS_TIME_PLIB_START)CORETIMER_Start,
    .timerStop = (SYS_TIME_PLIB_STOP)CORETIMER_Stop ,
    .timerFrequencyGet = (SYS_TIME_PLIB_FREQUENCY_GET)CORETIMER_FrequencyGet,
    .timerPeriodSet = (SYS_TIME_PLIB_PERIOD_SET)NULL,
    .timerCompareSet = (SYS_TIME_PLIB_COMPARE_SET)CORETIMER_CompareSet,
    .timerCounterGet = (SYS_TIME_PLIB_COUNTER_GET)CORETIMER_CounterGet,
};

const SYS_TIME_INIT sysTimeInitData =
{
    .timePlib = &sysTimePlibAPI,
    .hwTimerIntNum = 0,
};

// </editor-fold>



// *****************************************************************************
// *****************************************************************************
// Section: Local initialization functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void STDIO_BufferModeSet ( void )

  Summary:
    Sets the buffering mode for stdin and stdout

  Remarks:
 ********************************************************************************/
static void STDIO_BufferModeSet(void)
{

    /* Make stdin unbuffered */
    setbuf(stdin, NULL);

    /* Make stdout unbuffered */
    setbuf(stdout, NULL);
}




/*******************************************************************************
  Function:
    void SYS_Initialize ( void *data )

  Summary:
    Initializes the board, services, drivers, application and other modules.

  Remarks:
 */

void SYS_Initialize ( void* data )
{

    /* Start out with interrupts disabled before configuring any modules */
    __builtin_disable_interrupts();

    STDIO_BufferModeSet();


  
    CLK_Initialize();
	SYS_PMU_MLDO_TRIM();

    /* Configure Wait States */
    PRECONbits.PFMWS = 5;



	GPIO_Initialize();

	BSP_Initialize();
    CORETIMER_Initialize();
	UART1_Initialize();

	SPI2_Initialize();

	SPI1_Initialize();


    /* Initialize SDSPI0 Driver Instance */
    sysObj.drvSDSPI0 = DRV_SDSPI_Initialize(DRV_SDSPI_INDEX_0, (SYS_MODULE_INIT *)&drvSDSPI0InitData);

    sysObj.drvSST26 = DRV_SST26_Initialize((SYS_MODULE_INDEX)DRV_SST26_INDEX, (SYS_MODULE_INIT *)&drvSST26InitData);

    sysObj.drvMemory0 = DRV_MEMORY_Initialize((SYS_MODULE_INDEX)DRV_MEMORY_INDEX_0, (SYS_MODULE_INIT *)&drvMemory0InitData);


    sysObj.sysTime = SYS_TIME_Initialize(SYS_TIME_INDEX_0, (SYS_MODULE_INIT *)&sysTimeInitData);

    /*** File System Service Initialization Code ***/
    SYS_FS_Initialize( (const void *) sysFSInit );


    SDCARD_Initialize();
    SERIAL_MEM_Initialize();
    APP_MONITOR_Initialize();


    EVIC_Initialize();

	/* Enable global interrupts */
    __builtin_enable_interrupts();


}


/*******************************************************************************
 End of File
*/
