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





// *****************************************************************************
// *****************************************************************************
// Section: Driver Initialization Data
// *****************************************************************************
// *****************************************************************************
// <editor-fold defaultstate="collapsed" desc="DRV_AT25 Initialization Data">

/* SPI PLIB Interface Initialization for AT25 Driver */
const DRV_AT25_PLIB_INTERFACE drvAT25PlibAPI = {

    /* SPI PLIB WriteRead function */
    .writeRead = (DRV_AT25_PLIB_WRITE_READ)SPI3_WriteRead,

    /* SPI PLIB Write function */
    .write = (DRV_AT25_PLIB_WRITE)SPI3_Write,

    /* SPI PLIB Read function */
    .read = (DRV_AT25_PLIB_READ)SPI3_Read,

    /* SPI PLIB Transfer Status function */
    .isBusy = (DRV_AT25_PLIB_IS_BUSY)SPI3_IsBusy,

    /* SPI PLIB Callback Register */
    .callbackRegister = (DRV_AT25_PLIB_CALLBACK_REGISTER)SPI3_CallbackRegister,
};

/* AT25 Driver Initialization Data */
const DRV_AT25_INIT drvAT25InitData =
{
    /* SPI PLIB API  interface*/
    .spiPlib = &drvAT25PlibAPI,

    /* AT25 Number of clients */
    .numClients = DRV_AT25_CLIENTS_NUMBER_IDX,

    /* EEPROM Page Size in bytes */
    .pageSize = DRV_AT25_EEPROM_PAGE_SIZE,

    /* Total size of the EEPROM in bytes */
    .flashSize = DRV_AT25_EEPROM_FLASH_SIZE,

    .blockStartAddress =    0x0,

    .chipSelectPin    = DRV_AT25_CHIP_SELECT_PIN_IDX,

    .holdPin    = DRV_AT25_HOLD_PIN_IDX,

    .writeProtectPin    = DRV_AT25_WP_PIN_IDX,
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


// *****************************************************************************
// *****************************************************************************
// Section: System Initialization
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Local initialization functions
// *****************************************************************************
// *****************************************************************************



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

  
    CLK_Initialize();


	GPIO_Initialize();

	UART3_Initialize();

    CORETIMER_Initialize();
	SPI3_Initialize();

	BSP_Initialize();

    sysObj.drvAT25 = DRV_AT25_Initialize(DRV_AT25_INDEX, (SYS_MODULE_INIT *)&drvAT25InitData);




    APP_Initialize();
    APP_INPUT_Initialize();


    EVIC_Initialize();

	/* Enable global interrupts */
    __builtin_enable_interrupts();


}


/*******************************************************************************
 End of File
*/
