/*******************************************************************************
  FLEXCOM TWI Peripheral Library Source File

  Company
    Microchip Technology Inc.

  File Name
    plib_flexcom7_twi_master.c

  Summary
    FLEXCOM TWI Master peripheral library interface.

  Description
    This file defines the interface to the FLEXCOM TWI peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:

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
// Included Files
// *****************************************************************************
// *****************************************************************************

#include "device.h"
#include "plib_flexcom7_twi_master.h"
#include "interrupts.h"

// *****************************************************************************
// *****************************************************************************
// Local Data Type Definitions
// *****************************************************************************
// *****************************************************************************

#define FLEXCOM_TWI_MASTER_MAX_BAUDRATE        (400000U)
#define FLEXCOM_TWI_LOW_LEVEL_TIME_LIMIT       (384000U)
#define FLEXCOM_TWI_CLK_DIVIDER                     (2U)
#define FLEXCOM_TWI_CLK_CALC_ARGU                   (3U)
#define FLEXCOM_TWI_CLK_DIV_MAX                  (0xFFU)
#define FLEXCOM_TWI_CLK_DIV_MIN                     (7U)

// *****************************************************************************
// *****************************************************************************
// Global Data
// *****************************************************************************
// *****************************************************************************

static volatile FLEXCOM_TWI_OBJ flexcom7TwiObj;

// *****************************************************************************
// *****************************************************************************
// FLEXCOM7 TWI PLib Interface Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void FLEXCOM7_TWI_Initialize(void)

   Summary:
    Initializes given instance of the FLEXCOM TWI peripheral.

   Precondition:
    None.

   Parameters:
    None.

   Returns:
    None
*/

void FLEXCOM7_TWI_Initialize(void)
{
    /* Set FLEXCOM TWI operating mode */
    FLEXCOM7_REGS->FLEX_MR = FLEX_MR_OPMODE_TWI;

    // Reset the i2c Module
    FLEXCOM7_REGS->FLEX_TWI_CR = FLEX_TWI_CR_SWRST_Msk;

    // Disable the I2C Master/Slave Mode
    FLEXCOM7_REGS->FLEX_TWI_CR = FLEX_TWI_CR_MSDIS_Msk |
                                          FLEX_TWI_CR_SVDIS_Msk;

    // Set Baud rate
    FLEXCOM7_REGS->FLEX_TWI_CWGR = (FLEXCOM7_REGS->FLEX_TWI_CWGR & FLEX_TWI_CWGR_HOLD_Msk)  |
                                                    FLEX_TWI_CWGR_BRSRCCLK_PERIPH_CLK |
                                                    (FLEX_TWI_CWGR_CLDIV(122) |
                                                     FLEX_TWI_CWGR_CHDIV(122) |
                                                     FLEX_TWI_CWGR_CKDIV(0));

    // Starts the transfer by clearing the transmit hold register
    FLEXCOM7_REGS->FLEX_TWI_CR = FLEX_TWI_CR_THRCLR_Msk;

    // Disable TXRDY, TXCOMP and RXRDY interrupts
    FLEXCOM7_REGS->FLEX_TWI_IDR = FLEX_TWI_IDR_TXCOMP_Msk | FLEX_TWI_IDR_TXRDY_Msk | FLEX_TWI_IDR_RXRDY_Msk;

    // Enables interrupt on nack and arbitration lost
    FLEXCOM7_REGS->FLEX_TWI_IER = FLEX_TWI_IER_NACK_Msk |
                                           FLEX_TWI_IER_ARBLST_Msk;

    // Enable Master Mode
    FLEXCOM7_REGS->FLEX_TWI_CR = FLEX_TWI_CR_MSEN_Msk;

    // Initialize the flexcom twi PLib Object
    flexcom7TwiObj.error   = FLEXCOM_TWI_ERROR_NONE;
    flexcom7TwiObj.state   = FLEXCOM_TWI_STATE_IDLE;
}


/******************************************************************************
Local Functions
******************************************************************************/

static void FLEXCOM7_TWI_InitiateRead(void)
{

    flexcom7TwiObj.state = FLEXCOM_TWI_STATE_TRANSFER_READ;

    FLEXCOM7_REGS->FLEX_TWI_MMR |= FLEX_TWI_MMR_MREAD_Msk;

    /* When a single data byte read is performed,
    the START and STOP bits must be set at the same time */
    if(flexcom7TwiObj.readSize == 1U)
    {
        FLEXCOM7_REGS->FLEX_TWI_CR = FLEX_TWI_CR_START_Msk | FLEX_TWI_CR_STOP_Msk;
    }
    else
    {
        FLEXCOM7_REGS->FLEX_TWI_CR = FLEX_TWI_CR_START_Msk;
    }

    __enable_irq();
    FLEXCOM7_REGS->FLEX_TWI_IER = FLEX_TWI_IER_RXRDY_Msk | FLEX_TWI_IER_TXCOMP_Msk;
}




static bool FLEXCOM7_TWI_InitiateTransfer(uint16_t address, bool type)
{
    uint32_t timeoutCntr = 40000;

    // 10-bit Slave Address
    if( address > 0x007FU )
    {
        FLEXCOM7_REGS->FLEX_TWI_MMR = FLEX_TWI_MMR_DADR(((uint32_t)address & 0x00007F00U) >> 8U) |
                                               FLEX_TWI_MMR_IADRSZ(1U);

        // Set internal address
        FLEXCOM7_REGS->FLEX_TWI_IADR = FLEX_TWI_IADR_IADR((uint32_t)address & 0x000000FFU );
    }
    // 7-bit Slave Address
    else
    {
        FLEXCOM7_REGS->FLEX_TWI_MMR = FLEX_TWI_MMR_DADR((uint32_t)address) | FLEX_TWI_MMR_IADRSZ(0U);
    }

    flexcom7TwiObj.writeCount= 0;
    flexcom7TwiObj.readCount= 0;

    // Write transfer
    if(type == false)
    {
        // Single Byte Write
        if( flexcom7TwiObj.writeSize == 1U )
        {
            // Single Byte write only
            if(  flexcom7TwiObj.readSize == 0U  )
            {
                // Load last byte in transmit register, issue stop condition
                // Generate TXCOMP interrupt after STOP condition has been sent
                flexcom7TwiObj.state = FLEXCOM_TWI_STATE_WAIT_FOR_TXCOMP;

                FLEXCOM7_REGS->FLEX_TWI_THR = FLEX_TWI_THR_TXDATA((uint32_t)flexcom7TwiObj.writeBuffer[0]);
                flexcom7TwiObj.writeCount++;
                FLEXCOM7_REGS->FLEX_TWI_CR =  FLEX_TWI_CR_STOP_Msk;
                FLEXCOM7_REGS->FLEX_TWI_IER = FLEX_TWI_IER_TXCOMP_Msk;
            }
            // Single Byte write and than read transfer
            else
            {
                // START bit must be set before the byte is shifted out. Hence disabled interrupt
                __disable_irq();
                FLEXCOM7_REGS->FLEX_TWI_THR = FLEX_TWI_THR_TXDATA((uint32_t)flexcom7TwiObj.writeBuffer[0]);
                flexcom7TwiObj.writeCount++;
                // Wait for control byte to be transferred before initiating repeat start for read
                while((FLEXCOM7_REGS->FLEX_TWI_SR & (FLEX_TWI_SR_TXCOMP_Msk | FLEX_TWI_SR_TXRDY_Msk)) != 0U)
                {

                }
                while((FLEXCOM7_REGS->FLEX_TWI_SR & (FLEX_TWI_SR_TXRDY_Msk)) == 0U)
                {
                    if (timeoutCntr == 0U)
                    {
                        flexcom7TwiObj.error = FLEXCOM_TWI_BUS_ERROR;
                        __enable_irq();
                        return false;
                    }
                    timeoutCntr--;
                }
                type=true;
            }
        }
        // Multi-Byte Write
        else
        {
            flexcom7TwiObj.state = FLEXCOM_TWI_STATE_TRANSFER_WRITE;

            FLEXCOM7_REGS->FLEX_TWI_THR = FLEX_TWI_THR_TXDATA((uint32_t)flexcom7TwiObj.writeBuffer[0]);
            flexcom7TwiObj.writeCount++;
            FLEXCOM7_REGS->FLEX_TWI_IER = FLEX_TWI_IDR_TXRDY_Msk | FLEX_TWI_IER_TXCOMP_Msk;
        }
    }
    // Read transfer
    if(type)
    {
        FLEXCOM7_TWI_InitiateRead();
    }

    return true;
}

// *****************************************************************************
/* Function:
    void FLEXCOM7_TWI_CallbackRegister(FLEXCOM_TWI_CALLBACK callback, uintptr_t contextHandle)

   Summary:
    Sets the pointer to the function (and it's context) to be called when the
    given FLEXCOM TWI's transfer events occur.

   Precondition:
    FLEXCOM7_TWI_Initialize must have been called for the associated FLEXCOM TWI instance.

   Parameters:
    callback - A pointer to a function with a calling signature defined
    by the FLEXCOM_TWI_CALLBACK data type.

    context - A value (usually a pointer) passed (unused) into the function
    identified by the callback parameter.

   Returns:
    None.
*/

void FLEXCOM7_TWI_CallbackRegister(FLEXCOM_TWI_CALLBACK callback, uintptr_t contextHandle)
{
    if (callback != NULL)
    {
        flexcom7TwiObj.callback = callback;
        flexcom7TwiObj.context = contextHandle;
    }
}

// *****************************************************************************
/* Function:
    bool FLEXCOM7_TWI_IsBusy(void)

   Summary:
    Returns the Peripheral busy status.

   Precondition:
    FLEXCOM7_TWI_Initialize must have been called for the associated FLEXCOM TWI instance.

   Parameters:
    None.

   Returns:
    true - Busy.
    false - Not busy.
*/

bool FLEXCOM7_TWI_IsBusy(void)
{
    return (flexcom7TwiObj.state != FLEXCOM_TWI_STATE_IDLE );
}



// *****************************************************************************
/* Function:
    bool FLEXCOM7_TWI_Read(uint16_t address, uint8_t *pdata, size_t length)

   Summary:
    Reads data from the slave.

   Precondition:
    FLEXCOM7_TWI_Initialize must have been called for the associated FLEXCOM TWI instance.

   Parameters:
    address - 7-bit / 10-bit slave address.
    pdata   - pointer to destination data buffer
    length  - length of data buffer in number of bytes.

   Returns:
    Request status.
    True - Request was successful.
    False - Request has failed.
*/

bool FLEXCOM7_TWI_Read(uint16_t address, uint8_t *pdata, size_t length)
{
    // Check for ongoing transfer
    if( flexcom7TwiObj.state != FLEXCOM_TWI_STATE_IDLE )
    {
        return false;
    }
    if ((FLEXCOM7_REGS->FLEX_TWI_SR & (FLEX_TWI_SR_SDA_Msk | FLEX_TWI_SR_SCL_Msk)) != (FLEX_TWI_SR_SDA_Msk | FLEX_TWI_SR_SCL_Msk))
    {
        flexcom7TwiObj.error = FLEXCOM_TWI_BUS_ERROR;
        return false;
    }

    flexcom7TwiObj.address=address;
    flexcom7TwiObj.readBuffer=pdata;
    flexcom7TwiObj.readSize=length;
    flexcom7TwiObj.writeBuffer=NULL;
    flexcom7TwiObj.writeSize=0;
    flexcom7TwiObj.error = FLEXCOM_TWI_ERROR_NONE;

    return FLEXCOM7_TWI_InitiateTransfer(address, true);
}

// *****************************************************************************
/* Function:
    bool FLEXCOM7_TWI_Write(uint16_t address, uint8_t *pdata, size_t length)

   Summary:
    Writes data onto the slave.

   Precondition:
    FLEXCOM7_TWI_Initialize must have been called for the associated FLEXCOM TWI instance.

   Parameters:
    address - 7-bit / 10-bit slave address.
    pdata   - pointer to source data buffer
    length  - length of data buffer in number of bytes.

   Returns:
    Request status.
    True - Request was successful.
    False - Request has failed.
*/

bool FLEXCOM7_TWI_Write(uint16_t address, uint8_t *pdata, size_t length)
{
    // Check for ongoing transfer
    if( flexcom7TwiObj.state != FLEXCOM_TWI_STATE_IDLE )
    {
        return false;
    }
    if ((FLEXCOM7_REGS->FLEX_TWI_SR & (FLEX_TWI_SR_SDA_Msk | FLEX_TWI_SR_SCL_Msk)) != (FLEX_TWI_SR_SDA_Msk | FLEX_TWI_SR_SCL_Msk))
    {
        flexcom7TwiObj.error = FLEXCOM_TWI_BUS_ERROR;
        return false;
    }

    flexcom7TwiObj.address=address;
    flexcom7TwiObj.readBuffer=NULL;
    flexcom7TwiObj.readSize=0;
    flexcom7TwiObj.writeBuffer=pdata;
    flexcom7TwiObj.writeSize=length;
    flexcom7TwiObj.error = FLEXCOM_TWI_ERROR_NONE;

    return FLEXCOM7_TWI_InitiateTransfer(address, false);
}

// *****************************************************************************
/* Function:
    bool FLEXCOM7_TWI_WriteRead(uint16_t address, uint8_t *wdata, size_t wlength, uint8_t *rdata, size_t rlength)

   Summary:
    Write and Read data from Slave.

   Precondition:
    FLEXCOM7_TWI_Initialize must have been called for the associated FLEXCOM TWI instance.

   Parameters:
    address - 7-bit / 10-bit slave address.
    wdata   - pointer to write data buffer
    wlength - write data length in bytes.
    rdata   - pointer to read data buffer.
    rlength - read data length in bytes.

   Returns:
    Request status.
    True - Request was successful.
    False - Request has failed.
*/

bool FLEXCOM7_TWI_WriteRead(uint16_t address, uint8_t *wdata, size_t wlength, uint8_t *rdata, size_t rlength)
{

    // Check for ongoing transfer
    if( flexcom7TwiObj.state != FLEXCOM_TWI_STATE_IDLE )
    {
        return false;
    }
    if ((FLEXCOM7_REGS->FLEX_TWI_SR & (FLEX_TWI_SR_SDA_Msk | FLEX_TWI_SR_SCL_Msk)) != (FLEX_TWI_SR_SDA_Msk | FLEX_TWI_SR_SCL_Msk))
    {
        flexcom7TwiObj.error = FLEXCOM_TWI_BUS_ERROR;
        return false;
    }

    flexcom7TwiObj.address=address;
    flexcom7TwiObj.readBuffer=rdata;
    flexcom7TwiObj.readSize=rlength;
    flexcom7TwiObj.writeBuffer=wdata;
    flexcom7TwiObj.writeSize=wlength;
    flexcom7TwiObj.error = FLEXCOM_TWI_ERROR_NONE;

    return FLEXCOM7_TWI_InitiateTransfer(address, false);
}

void FLEXCOM7_TWI_TransferAbort( void )
{
    flexcom7TwiObj.error = FLEXCOM_TWI_ERROR_NONE;

    // Reset the PLib objects and Interrupts
    flexcom7TwiObj.state = FLEXCOM_TWI_STATE_IDLE;
    FLEXCOM7_REGS->FLEX_TWI_IDR = FLEX_TWI_IDR_TXCOMP_Msk | FLEX_TWI_IDR_TXRDY_Msk | FLEX_TWI_IDR_RXRDY_Msk;

    // Disable and Enable I2C Master
    FLEXCOM7_REGS->FLEX_TWI_CR = FLEX_TWI_CR_MSDIS_Msk;
    FLEXCOM7_REGS->FLEX_TWI_CR = FLEX_TWI_CR_MSEN_Msk;
}

// *****************************************************************************
/* Function:
    FLEXCOM_TWI_ERROR FLEXCOM7_TWI_ErrorGet(void)

   Summary:
    Returns the error during transfer.

   Precondition:
    FLEXCOM7_TWI_Initialize must have been called for the associated FLEXCOM TWI instance.

   Parameters:
    None.

   Returns:
    Error during transfer.
*/

FLEXCOM_TWI_ERROR FLEXCOM7_TWI_ErrorGet(void)
{
    FLEXCOM_TWI_ERROR error;

    error = flexcom7TwiObj.error;
    flexcom7TwiObj.error = FLEXCOM_TWI_ERROR_NONE;

    return error;
}

bool FLEXCOM7_TWI_TransferSetup(FLEXCOM_TWI_TRANSFER_SETUP* setup, uint32_t srcClkFreq )
{
    uint32_t i2cClkSpeed;
    uint32_t cldiv;
    uint8_t ckdiv = 0;
    bool setupStatus = false;
    if (setup != NULL)
    {
        i2cClkSpeed = setup->clkSpeed;

        /* Maximum I2C clock speed in Master mode cannot be greater than 400 KHz */
        if (i2cClkSpeed <= 4000000U)
        {
            if( srcClkFreq == 0U)
            {
                srcClkFreq = 100000000;
            }

            /* Formula for calculating baud value involves two unknowns. Fix one unknown and calculate the other.
            Fix the CKDIV value and see if CLDIV (or CHDIV) fits into the 8-bit register. */

            /* Calculate CLDIV with CKDIV set to 0 */
            cldiv = (srcClkFreq /(2U * i2cClkSpeed)) - 3U;

            /* CLDIV must fit within 8-bits and CKDIV must fit within 3-bits */
            while ((cldiv > 255U) && (ckdiv < 7U))
            {
                ckdiv++;
                cldiv /= 2U;
            }

            if (cldiv <= 255U)
            {
                // Set Baud rate
                FLEXCOM7_REGS->FLEX_TWI_CWGR = ( FLEX_TWI_CWGR_HOLD_Msk & FLEXCOM7_REGS->FLEX_TWI_CWGR) |
                                                        FLEX_TWI_CWGR_BRSRCCLK_PERIPH_CLK |
                                                        ( FLEX_TWI_CWGR_CLDIV(cldiv) |
                                                        FLEX_TWI_CWGR_CHDIV(cldiv) |
                                                        FLEX_TWI_CWGR_CKDIV((uint32_t)ckdiv) );
                setupStatus = true;
            }
        }
    }
    return setupStatus;
}

// *****************************************************************************
/* Function:
    void FLEXCOM7_InterruptHandler(void)

   Summary:
    FLEXCOM7_TWI Peripheral Interrupt Handler.

   Description:
    This function is FLEXCOM7_TWI Peripheral Interrupt Handler and will
    called on every FLEXCOM7_TWI interrupt.

   Precondition:
    None.

   Parameters:
    None.

   Returns:
    None.

   Remarks:
    The function is called as peripheral instance's interrupt handler if the
    instance interrupt is enabled. If peripheral instance's interrupt is not
    enabled user need to call it from the main while loop of the application.
*/

void __attribute__((used)) FLEXCOM7_InterruptHandler(void)
{
    uint32_t status;
    uintptr_t context = flexcom7TwiObj.context;

    // Read the peripheral status
    status = FLEXCOM7_REGS->FLEX_TWI_SR;

    /* checks if Slave has Nacked */
    if( (status & FLEX_TWI_SR_NACK_Msk) != 0U )
    {
        flexcom7TwiObj.state = FLEXCOM_TWI_STATE_ERROR;
        flexcom7TwiObj.error = FLEXCOM_TWI_ERROR_NACK;
    }

    if( (status & FLEX_TWI_SR_TXCOMP_Msk) != 0U )
    {
        /* Disable and Enable I2C Master */
        FLEXCOM7_REGS->FLEX_TWI_CR = FLEX_TWI_CR_MSDIS_Msk;
        FLEXCOM7_REGS->FLEX_TWI_CR = FLEX_TWI_CR_MSEN_Msk;

        /* Disable Interrupt */
        FLEXCOM7_REGS->FLEX_TWI_IDR = FLEX_TWI_IDR_TXCOMP_Msk |
                                 FLEX_TWI_IDR_TXRDY_Msk  |
                                 FLEX_TWI_IDR_RXRDY_Msk;
    }

    /* checks if the arbitration is lost in multi-master scenario */
    if( (status & FLEX_TWI_SR_ARBLST_Msk) != 0U )
    {
        /* Re-initiate the transfer if arbitration is lost in
         * between of the transfer
         */
        flexcom7TwiObj.state = FLEXCOM_TWI_STATE_ADDR_SEND;
    }

    if( flexcom7TwiObj.error == FLEXCOM_TWI_ERROR_NONE )
    {
        switch( flexcom7TwiObj.state )
        {
            case FLEXCOM_TWI_STATE_ADDR_SEND:
            {
                if (flexcom7TwiObj.writeSize != 0U )
                {
                    // Initiate Write transfer
                    (void)FLEXCOM7_TWI_InitiateTransfer(flexcom7TwiObj.address, false);
                }
                else
                {
                    // Initiate Read transfer
                    (void)FLEXCOM7_TWI_InitiateTransfer(flexcom7TwiObj.address, true);
                }
            }
            break;

            case FLEXCOM_TWI_STATE_TRANSFER_WRITE:
            {
                size_t  writeCount = flexcom7TwiObj.writeCount;

                /* checks if master is ready to transmit */
                if( (status & FLEX_TWI_SR_TXRDY_Msk) != 0U )
                {
                    // Write Last Byte and then initiate read transfer
                    bool lastByteWrPending = (writeCount == (flexcom7TwiObj.writeSize -1U));

                    if(( flexcom7TwiObj.readSize != 0U ) && (lastByteWrPending))
                    {
                        // START bit must be set before the last byte is shifted out to generate repeat start. Hence disabled interrupt
                        __disable_irq();
                        FLEXCOM7_REGS->FLEX_TWI_IDR = FLEX_TWI_IDR_TXRDY_Msk;
                        FLEXCOM7_REGS->FLEX_TWI_THR = FLEX_TWI_THR_TXDATA((uint32_t)flexcom7TwiObj.writeBuffer[writeCount]);
                        writeCount++;
                        FLEXCOM7_TWI_InitiateRead();
                    }
                    // Write Last byte and then issue STOP condition
                    else if (lastByteWrPending)
                    {
                        // Load last byte in transmit register, issue stop condition
                        // Generate TXCOMP interrupt after STOP condition has been sent
                        FLEXCOM7_REGS->FLEX_TWI_THR = FLEX_TWI_THR_TXDATA((uint32_t)flexcom7TwiObj.writeBuffer[writeCount]);
                        writeCount++;
                        FLEXCOM7_REGS->FLEX_TWI_CR = FLEX_TWI_CR_STOP_Msk;
                        FLEXCOM7_REGS->FLEX_TWI_IDR = FLEX_TWI_IDR_TXRDY_Msk;

                        /* Check TXCOMP to confirm if STOP condition has been sent, otherwise wait for TXCOMP interrupt */
                        status = FLEXCOM7_REGS->FLEX_TWI_SR;
                        if( (status & FLEX_TWI_SR_TXCOMP_Msk) != 0U )
                        {
                            flexcom7TwiObj.state = FLEXCOM_TWI_STATE_TRANSFER_DONE;
                        }
                        else
                        {
                            flexcom7TwiObj.state = FLEXCOM_TWI_STATE_WAIT_FOR_TXCOMP;
                        }
                    }
                    // Write next byte
                    else
                    {
                        FLEXCOM7_REGS->FLEX_TWI_THR = FLEX_TWI_THR_TXDATA((uint32_t)flexcom7TwiObj.writeBuffer[writeCount]);
                        writeCount++;
                    }

                    flexcom7TwiObj.writeCount = writeCount;

                    // Dummy read to ensure that TXRDY bit is cleared
                    (void)FLEXCOM7_REGS->FLEX_TWI_SR;
                }

                break;
            }

            case FLEXCOM_TWI_STATE_TRANSFER_READ:
            {
                /* checks if master has received the data */
                if( (status & FLEX_TWI_SR_RXRDY_Msk) != 0U)
                {
                    size_t readCount = flexcom7TwiObj.readCount;

                    // Set the STOP (or START) bit before reading the FLEX_TWI_RHR on the next-to-last access
                    if(  readCount == (flexcom7TwiObj.readSize - 2U) )
                    {
                        FLEXCOM7_REGS->FLEX_TWI_CR = FLEX_TWI_CR_STOP_Msk;
                    }

                    /* read the received data */
                    flexcom7TwiObj.readBuffer[readCount] = (uint8_t)(FLEXCOM7_REGS->FLEX_TWI_RHR & FLEX_TWI_RHR_RXDATA_Msk);
                    readCount++;

                    /* checks if transmission has reached at the end */
                    if( readCount == flexcom7TwiObj.readSize )
                    {
                        /* Disable the RXRDY interrupt*/
                        FLEXCOM7_REGS->FLEX_TWI_IDR = FLEX_TWI_IDR_RXRDY_Msk;

                        /* Check TXCOMP to confirm if STOP condition has been sent, otherwise wait for TXCOMP interrupt */
                        status = FLEXCOM7_REGS->FLEX_TWI_SR;
                        if( (status & FLEX_TWI_SR_TXCOMP_Msk) != 0U )
                        {
                            flexcom7TwiObj.state = FLEXCOM_TWI_STATE_TRANSFER_DONE;
                        }
                        else
                        {
                            flexcom7TwiObj.state = FLEXCOM_TWI_STATE_WAIT_FOR_TXCOMP;
                        }
                    }

                    flexcom7TwiObj.readCount = readCount;
                }
                break;
            }

            case FLEXCOM_TWI_STATE_WAIT_FOR_TXCOMP:
            {
                if( (status & FLEX_TWI_SR_TXCOMP_Msk) != 0U )
                {
                    flexcom7TwiObj.state = FLEXCOM_TWI_STATE_TRANSFER_DONE;
                }
                break;
            }

            default:
            {
                /*default*/
                break;
            }
        }
    }

    if (flexcom7TwiObj.state == FLEXCOM_TWI_STATE_ERROR)
    {
        // NACK is received,
        flexcom7TwiObj.state = FLEXCOM_TWI_STATE_IDLE;
        FLEXCOM7_REGS->FLEX_TWI_IDR = FLEX_TWI_IDR_TXCOMP_Msk | FLEX_TWI_IDR_TXRDY_Msk | FLEX_TWI_IDR_RXRDY_Msk;

        // Disable and Enable I2C Master
        FLEXCOM7_REGS->FLEX_TWI_CR = FLEX_TWI_CR_MSDIS_Msk;
        FLEXCOM7_REGS->FLEX_TWI_CR = FLEX_TWI_CR_MSEN_Msk;

        if ( flexcom7TwiObj.callback != NULL )
        {
            flexcom7TwiObj.callback( context );
        }
    }

    // check for completion of transfer
    if( flexcom7TwiObj.state == FLEXCOM_TWI_STATE_TRANSFER_DONE )
    {

        flexcom7TwiObj.error = FLEXCOM_TWI_ERROR_NONE;

        // Reset the PLib objects and Interrupts
        flexcom7TwiObj.state = FLEXCOM_TWI_STATE_IDLE;
        FLEXCOM7_REGS->FLEX_TWI_IDR = FLEX_TWI_IDR_TXCOMP_Msk |
                                 FLEX_TWI_IDR_TXRDY_Msk  |
                                 FLEX_TWI_IDR_RXRDY_Msk;

        // Disable and Enable I2C Master
        FLEXCOM7_REGS->FLEX_TWI_CR = FLEX_TWI_CR_MSDIS_Msk;
        FLEXCOM7_REGS->FLEX_TWI_CR = FLEX_TWI_CR_MSEN_Msk;
        if ( flexcom7TwiObj.callback != NULL )
        {
            flexcom7TwiObj.callback( context );
        }
    }

    return;
}

/*******************************************************************************
 End of File
*/
