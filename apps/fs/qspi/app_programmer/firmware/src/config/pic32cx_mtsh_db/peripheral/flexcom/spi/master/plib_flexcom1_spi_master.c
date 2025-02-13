/*******************************************************************************
  FLEXCOM1 SPI PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_flexcom1_spi_master.c

  Summary:
    FLEXCOM1 SPI Master PLIB Implementation File.

  Description:
    This file defines the interface to the FLEXCOM SPI peripheral library.
    This library provides access to and control of the associated
    peripheral instance.

  Remarks:
    None.

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

#include "plib_flexcom1_spi_master.h"
#include "interrupts.h"

#define FLEXCOM_SPI_TDR_8BIT_REG      (*(volatile uint8_t* const)((FLEXCOM1_BASE_ADDRESS + FLEX_SPI_TDR_REG_OFST)))

#define FLEXCOM_SPI_TDR_9BIT_REG      (*(volatile uint16_t* const)((FLEXCOM1_BASE_ADDRESS + FLEX_SPI_TDR_REG_OFST)))



#define FLEXCOM_SPI_RDR_8BIT_REG      (*(volatile uint8_t* const)((FLEXCOM1_BASE_ADDRESS + FLEX_SPI_RDR_REG_OFST)))

#define FLEXCOM_SPI_RDR_9BIT_REG      (*(volatile uint16_t* const)((FLEXCOM1_BASE_ADDRESS + FLEX_SPI_RDR_REG_OFST)))
// *****************************************************************************
// *****************************************************************************
// Section: FLEXCOM1 SPI Implementation
// *****************************************************************************
// *****************************************************************************
/* Global object to save FLEXCOM SPI Exchange related data */
volatile static FLEXCOM_SPI_OBJECT flexcom1SpiObj;


void FLEXCOM1_SPI_Initialize ( void )
{
    /* Set FLEXCOM SPI operating mode */
    FLEXCOM1_REGS->FLEX_MR = FLEX_MR_OPMODE_SPI;

    /* Disable and Reset the FLEXCOM SPI */
    FLEXCOM1_REGS->FLEX_SPI_CR = FLEX_SPI_CR_SPIDIS_Msk | FLEX_SPI_CR_SWRST_Msk;


    /* Enable Master mode, select clock source, select particular NPCS line for chip select and disable mode fault detection */
    FLEXCOM1_REGS->FLEX_SPI_MR = FLEX_SPI_MR_MSTR_Msk | FLEX_SPI_MR_BRSRCCLK_PERIPH_CLK | FLEX_SPI_MR_DLYBCS(0U) | FLEX_SPI_MR_PCS((uint32_t)FLEXCOM_SPI_CHIP_SELECT_NPCS0) | FLEX_SPI_MR_MODFDIS_Msk;

    /* Set up clock Polarity, data phase, Communication Width, Baud Rate */
    FLEXCOM1_REGS->FLEX_SPI_CSR[0]= FLEX_SPI_CSR_CPOL(0U) | FLEX_SPI_CSR_NCPHA(1U) | FLEX_SPI_CSR_BITS_8_BIT | FLEX_SPI_CSR_SCBR(100U) | FLEX_SPI_CSR_DLYBS(0U) | FLEX_SPI_CSR_DLYBCT(0U)  | FLEX_SPI_CSR_CSAAT_Msk ;




    /* Initialize global variables */
    flexcom1SpiObj.transferIsBusy = false;
    flexcom1SpiObj.callback = NULL;

    /* Enable FLEXCOM1 SPI */
    FLEXCOM1_REGS->FLEX_SPI_CR = FLEX_SPI_CR_SPIEN_Msk;
    return;
}



bool FLEXCOM1_SPI_WriteRead (void* pTransmitData, size_t txSize, void* pReceiveData, size_t rxSize)
{
    bool isRequestAccepted = false;
    uint32_t dummyData;
    size_t txSz;

    if (flexcom1SpiObj.transferIsBusy == false)
    {
        /* Verify the request */
        if(((txSize > 0U) && (pTransmitData != NULL)) || ((rxSize > 0U) && (pReceiveData != NULL)))
        {
            isRequestAccepted = true;
            flexcom1SpiObj.txBuffer = pTransmitData;
            flexcom1SpiObj.rxBuffer = pReceiveData;
            flexcom1SpiObj.rxCount = 0;
            flexcom1SpiObj.txCount = 0;
            flexcom1SpiObj.dummySize = 0;
            if (pTransmitData != NULL)
            {
                flexcom1SpiObj.txSize = txSize;
            }
            else
            {
                flexcom1SpiObj.txSize = 0;
            }

            if (pReceiveData != NULL)
            {
                flexcom1SpiObj.rxSize = rxSize;
            }
            else
            {
                flexcom1SpiObj.rxSize = 0;
            }

            flexcom1SpiObj.transferIsBusy = true;

            /* Flush out any unread data in SPI read buffer */
            dummyData = (FLEXCOM1_REGS->FLEX_SPI_RDR & FLEX_SPI_RDR_RD_Msk) >> FLEX_SPI_RDR_RD_Pos;
            (void)dummyData;

            txSz = flexcom1SpiObj.txSize;

            if (flexcom1SpiObj.rxSize > txSz)
            {
                flexcom1SpiObj.dummySize = flexcom1SpiObj.rxSize - txSz;
            }

            /* Start the first write here itself, rest will happen in ISR context */
            if((FLEXCOM1_REGS->FLEX_SPI_CSR[0] & FLEX_SPI_CSR_BITS_Msk) == FLEX_SPI_CSR_BITS_8_BIT)
            {
                if (flexcom1SpiObj.txCount < txSz)
                {
                    FLEXCOM1_REGS->FLEX_SPI_TDR = *((uint8_t*)flexcom1SpiObj.txBuffer);
                    flexcom1SpiObj.txCount++;
                }
                else if (flexcom1SpiObj.dummySize > 0U)
                {
                    FLEXCOM1_REGS->FLEX_SPI_TDR = (uint8_t)(0xff);
                    flexcom1SpiObj.dummySize--;
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                flexcom1SpiObj.txSize >>= 1;
                flexcom1SpiObj.dummySize >>= 1;
                flexcom1SpiObj.rxSize >>= 1;

                txSz = flexcom1SpiObj.txSize;

                if (flexcom1SpiObj.txCount < txSz)
                {
                    FLEXCOM1_REGS->FLEX_SPI_TDR = *((uint16_t*)flexcom1SpiObj.txBuffer);
                    flexcom1SpiObj.txCount++;
                }
                else if (flexcom1SpiObj.dummySize > 0U)
                {
                    FLEXCOM1_REGS->FLEX_SPI_TDR = (uint16_t)(0xffff);
                    flexcom1SpiObj.dummySize--;
                }
                else
                {
                    /* Do nothing */
                }
            }

            if (rxSize > 0U)
            {
                /* Enable receive interrupt to complete the transfer in ISR context */
                FLEXCOM1_REGS->FLEX_SPI_IER = FLEX_SPI_IER_RDRF_Msk;
            }
            else
            {
                /* Enable transmit interrupt to complete the transfer in ISR context */
                FLEXCOM1_REGS->FLEX_SPI_IER = FLEX_SPI_IER_TDRE_Msk;
            }
        }
    }

    return isRequestAccepted;
}

bool FLEXCOM1_SPI_TransferSetup (FLEXCOM_SPI_TRANSFER_SETUP * setup, uint32_t spiSourceClock )
{
    uint32_t scbr;
    bool setupStatus = false;
    if ((setup != NULL) && (setup->clockFrequency != 0U))
    {
        if(spiSourceClock == 0U)
        {
            // Fetch Master Clock Frequency directly
            spiSourceClock = 100000000;
        }

        scbr = spiSourceClock/setup->clockFrequency;

        if(scbr == 0U)
        {
            scbr = 1;
        }
        else if(scbr > 255U)
        {
            scbr = 255;
        }
        else
        {
            /* Do nothing */
        }

        FLEXCOM1_REGS->FLEX_SPI_CSR[0]= (FLEXCOM1_REGS->FLEX_SPI_CSR[0] & ~(FLEX_SPI_CSR_CPOL_Msk | FLEX_SPI_CSR_NCPHA_Msk | FLEX_SPI_CSR_BITS_Msk | FLEX_SPI_CSR_SCBR_Msk)) | ((uint32_t)setup->clockPolarity | (uint32_t)setup->clockPhase | (uint32_t)setup->dataBits | FLEX_SPI_CSR_SCBR(scbr));

        setupStatus = true;
    }
    return setupStatus;
}

bool FLEXCOM1_SPI_Write(void* pTransmitData, size_t txSize)
{
    return(FLEXCOM1_SPI_WriteRead(pTransmitData, txSize, NULL, 0));
}

bool FLEXCOM1_SPI_Read(void* pReceiveData, size_t rxSize)
{
    return(FLEXCOM1_SPI_WriteRead(NULL, 0, pReceiveData, rxSize));
}

bool FLEXCOM1_SPI_IsTransmitterBusy(void)
{
    return ((FLEXCOM1_REGS->FLEX_SPI_SR & FLEX_SPI_SR_TXEMPTY_Msk) == 0U);
}

void FLEXCOM1_SPI_CallbackRegister (FLEXCOM_SPI_CALLBACK callback, uintptr_t context)
{
    flexcom1SpiObj.callback = callback;
    flexcom1SpiObj.context = context;
}

bool FLEXCOM1_SPI_IsBusy(void)
{
    bool transferIsBusy = flexcom1SpiObj.transferIsBusy;

    return (((FLEXCOM1_REGS->FLEX_SPI_SR & FLEX_SPI_SR_TXEMPTY_Msk) == 0U) || (transferIsBusy));
}

void __attribute__((used)) FLEXCOM1_InterruptHandler(void)
{
    uint32_t dataBits ;
    uint32_t receivedData;
    dataBits = FLEXCOM1_REGS->FLEX_SPI_CSR[0] & FLEX_SPI_CSR_BITS_Msk;

    static bool isLastByteTransferInProgress = false;
    uintptr_t context = flexcom1SpiObj.context;

    /* save the status in global object before it gets cleared */
    flexcom1SpiObj.status = FLEXCOM1_REGS->FLEX_SPI_SR;


    size_t rxCount = flexcom1SpiObj.rxCount;
    size_t txCount = flexcom1SpiObj.txCount;

    if ((FLEXCOM1_REGS->FLEX_SPI_SR & FLEX_SPI_SR_RDRF_Msk ) == FLEX_SPI_SR_RDRF_Msk)
    {
        receivedData = (FLEXCOM1_REGS->FLEX_SPI_RDR & FLEX_SPI_RDR_RD_Msk) >> FLEX_SPI_RDR_RD_Pos;

        if (rxCount < flexcom1SpiObj.rxSize)
        {
            if(dataBits == FLEX_SPI_CSR_BITS_8_BIT)
            {
                ((uint8_t*)flexcom1SpiObj.rxBuffer)[rxCount] = (uint8_t)receivedData;
            }
            else
            {
                ((uint16_t*)flexcom1SpiObj.rxBuffer)[rxCount] = (uint16_t)receivedData;
            }
            rxCount++;
        }
    }

    /* If there are more words to be transmitted, then transmit them here and keep track of the count */
    if((FLEXCOM1_REGS->FLEX_SPI_SR & FLEX_SPI_SR_TDRE_Msk) == FLEX_SPI_SR_TDRE_Msk)
    {
        /* Disable the TDRE interrupt. This will be enabled back if more than
         * one byte is pending to be transmitted */
        FLEXCOM1_REGS->FLEX_SPI_IDR = FLEX_SPI_IDR_TDRE_Msk;

        if(dataBits == FLEX_SPI_CSR_BITS_8_BIT)
        {
            if (txCount < flexcom1SpiObj.txSize)
            {
                FLEXCOM1_REGS->FLEX_SPI_TDR = ((uint8_t*)flexcom1SpiObj.txBuffer)[txCount];
                txCount++;
            }
            else if (flexcom1SpiObj.dummySize > 0U)
            {
                FLEXCOM1_REGS->FLEX_SPI_TDR = (uint8_t)(0xff);
                flexcom1SpiObj.dummySize--;
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            if (txCount < flexcom1SpiObj.txSize)
            {
                FLEXCOM1_REGS->FLEX_SPI_TDR = ((uint16_t*)flexcom1SpiObj.txBuffer)[txCount];
                txCount++;
            }
            else if (flexcom1SpiObj.dummySize > 0U)
            {
                FLEXCOM1_REGS->FLEX_SPI_TDR = (uint16_t)(0xffff);
                flexcom1SpiObj.dummySize--;
            }
            else
            {
                /* Do nothing */
            }
        }
        size_t dummySize = flexcom1SpiObj.dummySize;

        if ((txCount == flexcom1SpiObj.txSize) && (dummySize == 0U))
        {
            /* At higher baud rates, the data in the shift register can be
             * shifted out and TXEMPTY flag can get set resulting in a
             * callback been given to the application with the SPI interrupt
             * pending with the application. This will then result in the
             * interrupt handler being called again with nothing to transmit.
             * To avoid the above mentioned issue, a software flag is set, but
             * the TXEMPTY interrupt is not enabled until the very end.
             * At higher baud rates, if the software flag is set and the
             * TXEMPTY status bit is set, then it means that the transfer is
             * complete and a callback can be given to the application. Since
             * the TXEMPTY interrupt is not enabled there is no need to
             * explicitly clear the pending interrupt from the Interrupt controller.
             */

            isLastByteTransferInProgress = true;
        }
        else if (rxCount == flexcom1SpiObj.rxSize)
        {
            /* Enable TDRE interrupt as all the requested bytes are received
             * and can now make use of the internal transmit shift register.
             */
            FLEXCOM1_REGS->FLEX_SPI_IDR = FLEX_SPI_IDR_RDRF_Msk;
            FLEXCOM1_REGS->FLEX_SPI_IER = FLEX_SPI_IDR_TDRE_Msk;
        }
        else
        {
            /* Do nothing */
        }
    }

    flexcom1SpiObj.rxCount = rxCount;
    flexcom1SpiObj.txCount = txCount;

    /* See if Exchange is complete */
    if ((isLastByteTransferInProgress == true) && ((FLEXCOM1_REGS->FLEX_SPI_SR & FLEX_SPI_SR_TXEMPTY_Msk) == FLEX_SPI_SR_TXEMPTY_Msk))
    {
        if (rxCount == flexcom1SpiObj.rxSize)
        {
            /* Set Last transfer to deassert NPCS after the last byte written in TDR has been transferred. */
            FLEXCOM1_REGS->FLEX_SPI_CR = FLEX_SPI_CR_LASTXFER_Msk;

            flexcom1SpiObj.transferIsBusy = false;

            /* Disable TDRE, RDRF and TXEMPTY interrupts */
            FLEXCOM1_REGS->FLEX_SPI_IDR = FLEX_SPI_IDR_TDRE_Msk | FLEX_SPI_IDR_RDRF_Msk | FLEX_SPI_IDR_TXEMPTY_Msk;

            isLastByteTransferInProgress = false;

            if(flexcom1SpiObj.callback != NULL)
            {
                flexcom1SpiObj.callback(context);
            }
        }
    }
    if (isLastByteTransferInProgress == true)
    {
        /* For the last byte transfer, the TDRE interrupt is already disabled.
         * Enable TXEMPTY interrupt to ensure no data is present in the shift
         * register before application callback is called.
         */
        FLEXCOM1_REGS->FLEX_SPI_IER = FLEX_SPI_IER_TXEMPTY_Msk;
    }

}


/*******************************************************************************
 End of File
*/

