/*******************************************************************************
  SERCOM Universal Synchronous/Asynchrnous Receiver/Transmitter PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_sercom4_usart.c

  Summary
    USART peripheral library interface.

  Description
    This file defines the interface to the USART peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.
*******************************************************************************/

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "interrupts.h"
#include "plib_sercom4_usart.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************


/* SERCOM4 USART baud value for 115200 Hz baud rate */
#define SERCOM4_USART_INT_BAUD_VALUE            (62180UL)

static volatile SERCOM_USART_RING_BUFFER_OBJECT sercom4USARTObj;

// *****************************************************************************
// *****************************************************************************
// Section: SERCOM4 USART Interface Routines
// *****************************************************************************
// *****************************************************************************

#define SERCOM4_USART_READ_BUFFER_SIZE      128U
#define SERCOM4_USART_READ_BUFFER_9BIT_SIZE     (128U >> 1U)
#define SERCOM4_USART_RX_INT_DISABLE()      SERCOM4_REGS->USART.SERCOM_INTENCLR = SERCOM_USART_INTENCLR_RXC_Msk
#define SERCOM4_USART_RX_INT_ENABLE()       SERCOM4_REGS->USART.SERCOM_INTENSET = SERCOM_USART_INTENSET_RXC_Msk

static volatile uint8_t SERCOM4_USART_ReadBuffer[SERCOM4_USART_READ_BUFFER_SIZE];

#define SERCOM4_USART_WRITE_BUFFER_SIZE     128U
#define SERCOM4_USART_WRITE_BUFFER_9BIT_SIZE  (128U >> 1U)
#define SERCOM4_USART_TX_INT_DISABLE()      SERCOM4_REGS->USART.SERCOM_INTENCLR = SERCOM_USART_INTENCLR_DRE_Msk
#define SERCOM4_USART_TX_INT_ENABLE()       SERCOM4_REGS->USART.SERCOM_INTENSET = SERCOM_USART_INTENSET_DRE_Msk

static volatile uint8_t SERCOM4_USART_WriteBuffer[SERCOM4_USART_WRITE_BUFFER_SIZE];

void SERCOM4_USART_Initialize( void )
{
    /*
     * Configures USART Clock Mode
     * Configures TXPO and RXPO
     * Configures Data Order
     * Configures Standby Mode
     * Configures Sampling rate
     * Configures IBON
     */
    SERCOM4_REGS->USART.SERCOM_CTRLA = SERCOM_USART_CTRLA_MODE_INTCLK | SERCOM_USART_CTRLA_RXPO(0x1UL) | SERCOM_USART_CTRLA_TXPO(0x0UL) | SERCOM_USART_CTRLA_DORD_Msk | SERCOM_USART_CTRLA_IBON_Msk | SERCOM_USART_CTRLA_FORM(0x0UL) | SERCOM_USART_CTRLA_SAMPR(0UL) ;

    /* Configure Baud Rate */
    SERCOM4_REGS->USART.SERCOM_BAUD = (uint16_t)SERCOM_USART_BAUD_BAUD(SERCOM4_USART_INT_BAUD_VALUE);

    /*
     * Configures RXEN
     * Configures TXEN
     * Configures CHSIZE
     * Configures Parity
     * Configures Stop bits
     */
    SERCOM4_REGS->USART.SERCOM_CTRLB = SERCOM_USART_CTRLB_CHSIZE_8BITS | SERCOM_USART_CTRLB_SBMODE_ONE | SERCOM_USART_CTRLB_RXEN_Msk | SERCOM_USART_CTRLB_TXEN_Msk;

    /* Wait for sync */
    while((SERCOM4_REGS->USART.SERCOM_SYNCBUSY) != 0U)
    {
        /* Do nothing */
    }


    /* Enable the UART after the configurations */
    SERCOM4_REGS->USART.SERCOM_CTRLA |= SERCOM_USART_CTRLA_ENABLE_Msk;

    /* Wait for sync */
    while((SERCOM4_REGS->USART.SERCOM_SYNCBUSY) != 0U)
    {
        /* Do nothing */
    }

    /* Initialize instance object */
    sercom4USARTObj.rdCallback = NULL;
    sercom4USARTObj.rdInIndex = 0U;
    sercom4USARTObj.rdOutIndex = 0U;
    sercom4USARTObj.isRdNotificationEnabled = false;
    sercom4USARTObj.isRdNotifyPersistently = false;
    sercom4USARTObj.rdThreshold = 0U;
    sercom4USARTObj.errorStatus = USART_ERROR_NONE;
    sercom4USARTObj.wrCallback = NULL;
    sercom4USARTObj.wrInIndex = 0U;
    sercom4USARTObj.wrOutIndex = 0U;
    sercom4USARTObj.isWrNotificationEnabled = false;
    sercom4USARTObj.isWrNotifyPersistently = false;
    sercom4USARTObj.wrThreshold = 0U;
    if (((SERCOM4_REGS->USART.SERCOM_CTRLB & SERCOM_USART_CTRLB_CHSIZE_Msk) >> SERCOM_USART_CTRLB_CHSIZE_Pos) != 0x01U)
    {
        sercom4USARTObj.rdBufferSize = SERCOM4_USART_READ_BUFFER_SIZE;
        sercom4USARTObj.wrBufferSize = SERCOM4_USART_WRITE_BUFFER_SIZE;
    }
    else
    {
        sercom4USARTObj.rdBufferSize = SERCOM4_USART_READ_BUFFER_9BIT_SIZE;
        sercom4USARTObj.wrBufferSize = SERCOM4_USART_WRITE_BUFFER_9BIT_SIZE;
    }
    /* Enable error interrupt */
    SERCOM4_REGS->USART.SERCOM_INTENSET = (uint8_t)SERCOM_USART_INTENSET_ERROR_Msk;

    /* Enable Receive Complete interrupt */
    SERCOM4_REGS->USART.SERCOM_INTENSET = (uint8_t)SERCOM_USART_INTENSET_RXC_Msk;
}

uint32_t SERCOM4_USART_FrequencyGet( void )
{
    return 36000000UL;
}

bool SERCOM4_USART_SerialSetup( USART_SERIAL_SETUP * serialSetup, uint32_t clkFrequency )
{
    bool setupStatus       = false;
    uint32_t baudValue     = 0U;
    uint32_t sampleRate    = 0U;
    uint32_t sampleCount   = 0U;

    if((serialSetup != NULL) && (serialSetup->baudRate != 0U))
    {
        if(clkFrequency == 0U)
        {
            clkFrequency = SERCOM4_USART_FrequencyGet();
        }

        if(clkFrequency >= (16U * serialSetup->baudRate))
        {
            sampleRate = 0U;
            sampleCount = 16U;
        }
        else if(clkFrequency >= (8U * serialSetup->baudRate))
        {
            sampleRate = 2U;
            sampleCount = 8U;
        }
        else if(clkFrequency >= (3U * serialSetup->baudRate))
        {
            sampleRate = 4U;
            sampleCount = 3U;
        }
        else
        {
            /* Do nothing */
        }
        baudValue = 65536U - (uint32_t)(((uint64_t)65536U * sampleCount * serialSetup->baudRate) / clkFrequency);

        /* Disable the USART before configurations */
        SERCOM4_REGS->USART.SERCOM_CTRLA &= ~SERCOM_USART_CTRLA_ENABLE_Msk;

        /* Wait for sync */
        while((SERCOM4_REGS->USART.SERCOM_SYNCBUSY) != 0U)
        {
            /* Do nothing */
        }

        /* Configure Baud Rate */
        SERCOM4_REGS->USART.SERCOM_BAUD = (uint16_t)SERCOM_USART_BAUD_BAUD(baudValue);

        /* Configure Parity Options */
        if(serialSetup->parity == USART_PARITY_NONE)
        {
            SERCOM4_REGS->USART.SERCOM_CTRLA =  (SERCOM4_REGS->USART.SERCOM_CTRLA & ~(SERCOM_USART_CTRLA_SAMPR_Msk | SERCOM_USART_CTRLA_FORM_Msk)) | SERCOM_USART_CTRLA_FORM(0x0UL) | SERCOM_USART_CTRLA_SAMPR((uint32_t)sampleRate); 
            SERCOM4_REGS->USART.SERCOM_CTRLB = (SERCOM4_REGS->USART.SERCOM_CTRLB & ~(SERCOM_USART_CTRLB_CHSIZE_Msk | SERCOM_USART_CTRLB_SBMODE_Msk)) | ((uint32_t) serialSetup->dataWidth | (uint32_t) serialSetup->stopBits);
        }
        else
        {
            SERCOM4_REGS->USART.SERCOM_CTRLA =  (SERCOM4_REGS->USART.SERCOM_CTRLA & ~(SERCOM_USART_CTRLA_SAMPR_Msk | SERCOM_USART_CTRLA_FORM_Msk)) | SERCOM_USART_CTRLA_FORM(0x1UL) | SERCOM_USART_CTRLA_SAMPR((uint32_t)sampleRate); 
            SERCOM4_REGS->USART.SERCOM_CTRLB = (SERCOM4_REGS->USART.SERCOM_CTRLB & ~(SERCOM_USART_CTRLB_CHSIZE_Msk | SERCOM_USART_CTRLB_SBMODE_Msk | SERCOM_USART_CTRLB_PMODE_Msk)) | (uint32_t) serialSetup->dataWidth | (uint32_t) serialSetup->stopBits | (uint32_t) serialSetup->parity ;
        }

        /* Wait for sync */
        while((SERCOM4_REGS->USART.SERCOM_SYNCBUSY) != 0U)
        {
            /* Do nothing */
        }

        /* Enable the USART after the configurations */
        SERCOM4_REGS->USART.SERCOM_CTRLA |= SERCOM_USART_CTRLA_ENABLE_Msk;

        /* Wait for sync */
        while((SERCOM4_REGS->USART.SERCOM_SYNCBUSY) != 0U)
        {
            /* Do nothing */
        }


        if (((SERCOM4_REGS->USART.SERCOM_CTRLB & SERCOM_USART_CTRLB_CHSIZE_Msk) >> SERCOM_USART_CTRLB_CHSIZE_Pos) != 0x01U)
        {
            sercom4USARTObj.rdBufferSize = SERCOM4_USART_READ_BUFFER_SIZE;
            sercom4USARTObj.wrBufferSize = SERCOM4_USART_WRITE_BUFFER_SIZE;
        }
        else
        {
            sercom4USARTObj.rdBufferSize = SERCOM4_USART_READ_BUFFER_9BIT_SIZE;
            sercom4USARTObj.wrBufferSize = SERCOM4_USART_WRITE_BUFFER_9BIT_SIZE;
        }

        setupStatus = true;
    }

    return setupStatus;
}

void SERCOM4_USART_Enable( void )
{
    if((SERCOM4_REGS->USART.SERCOM_CTRLA & SERCOM_USART_CTRLA_ENABLE_Msk) == 0U)
    {
        SERCOM4_REGS->USART.SERCOM_CTRLA |= SERCOM_USART_CTRLA_ENABLE_Msk;

        /* Wait for sync */
        while((SERCOM4_REGS->USART.SERCOM_SYNCBUSY) != 0U)
        {
            /* Do nothing */
        }
    }
}

void SERCOM4_USART_Disable( void )
{
    if((SERCOM4_REGS->USART.SERCOM_CTRLA & SERCOM_USART_CTRLA_ENABLE_Msk) != 0U)
    {
        SERCOM4_REGS->USART.SERCOM_CTRLA &= ~SERCOM_USART_CTRLA_ENABLE_Msk;

        /* Wait for sync */
        while((SERCOM4_REGS->USART.SERCOM_SYNCBUSY) != 0U)
        {
            /* Do nothing */
        }
    }
}

static void SERCOM4_USART_ErrorClear( void )
{
    uint16_t  u16dummyData = 0;

    /* Clear error flag */
    SERCOM4_REGS->USART.SERCOM_INTFLAG = SERCOM_USART_INTFLAG_ERROR_Msk;

    /* Clear all errors */
    SERCOM4_REGS->USART.SERCOM_STATUS = SERCOM_USART_STATUS_PERR_Msk | SERCOM_USART_STATUS_FERR_Msk | SERCOM_USART_STATUS_BUFOVF_Msk ;

    /* Flush existing error bytes from the RX FIFO */
    while((SERCOM4_REGS->USART.SERCOM_INTFLAG & SERCOM_USART_INTFLAG_RXC_Msk) == SERCOM_USART_INTFLAG_RXC_Msk)
    {
        u16dummyData = (uint16_t)SERCOM4_REGS->USART.SERCOM_DATA;
    }

    /* Ignore the warning */
    (void)u16dummyData;
}

USART_ERROR SERCOM4_USART_ErrorGet( void )
{
    USART_ERROR errorStatus = sercom4USARTObj.errorStatus;

    sercom4USARTObj.errorStatus = USART_ERROR_NONE;

    return errorStatus;
}


/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static inline bool SERCOM4_USART_RxPushByte(uint16_t rdByte)
{
    uint32_t tempInIndex;
    uint32_t rdInIdx;
    bool isSuccess = false;

    tempInIndex = sercom4USARTObj.rdInIndex + 1U;

    if (tempInIndex >= sercom4USARTObj.rdBufferSize)
    {
        tempInIndex = 0U;
    }

    if (tempInIndex == sercom4USARTObj.rdOutIndex)
    {
        /* Queue is full - Report it to the application. Application gets a chance to free up space by reading data out from the RX ring buffer */
        if(sercom4USARTObj.rdCallback != NULL)
        {
            uintptr_t rdContext = sercom4USARTObj.rdContext;
            sercom4USARTObj.rdCallback(SERCOM_USART_EVENT_READ_BUFFER_FULL, rdContext);

            /* Read the indices again in case application has freed up space in RX ring buffer */
            tempInIndex = sercom4USARTObj.rdInIndex + 1U;

            if (tempInIndex >= sercom4USARTObj.rdBufferSize)
            {
                tempInIndex = 0U;
            }
        }
    }

    /* Attempt to push the data into the ring buffer */
    if (tempInIndex != sercom4USARTObj.rdOutIndex)
    {
        if (((SERCOM4_REGS->USART.SERCOM_CTRLB & SERCOM_USART_CTRLB_CHSIZE_Msk) >> SERCOM_USART_CTRLB_CHSIZE_Pos) != 0x01U)
        {
            /* 8-bit */
            rdInIdx = sercom4USARTObj.rdInIndex;

            SERCOM4_USART_ReadBuffer[rdInIdx] = (uint8_t)rdByte;
        }
        else
        {
            /* 9-bit */
            rdInIdx = sercom4USARTObj.rdInIndex << 1U;

            SERCOM4_USART_ReadBuffer[rdInIdx] = (uint8_t)rdByte;
            SERCOM4_USART_ReadBuffer[rdInIdx + 1U] = (uint8_t)(rdByte >> 8U);
        }

        sercom4USARTObj.rdInIndex = tempInIndex;
        isSuccess = true;
    }
    else
    {
        /* Queue is full. Data will be lost. */
    }

    return isSuccess;
}

/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static void SERCOM4_USART_ReadNotificationSend(void)
{
    uint32_t nUnreadBytesAvailable;

    if (sercom4USARTObj.isRdNotificationEnabled == true)
    {
        nUnreadBytesAvailable = SERCOM4_USART_ReadCountGet();

        if(sercom4USARTObj.rdCallback != NULL)
        {
            uintptr_t rdContext = sercom4USARTObj.rdContext;

            if (sercom4USARTObj.isRdNotifyPersistently == true)
            {
                if (nUnreadBytesAvailable >= sercom4USARTObj.rdThreshold)
                {
                    sercom4USARTObj.rdCallback(SERCOM_USART_EVENT_READ_THRESHOLD_REACHED, rdContext);
                }
            }
            else
            {
                if (nUnreadBytesAvailable == sercom4USARTObj.rdThreshold)
                {
                    sercom4USARTObj.rdCallback(SERCOM_USART_EVENT_READ_THRESHOLD_REACHED, rdContext);
                }
            }
        }
    }
}

size_t SERCOM4_USART_Read(uint8_t* pRdBuffer, const size_t size)
{
    size_t nBytesRead = 0U;
    uint32_t rdOutIndex;
    uint32_t rdInIndex;
    uint32_t rdOutIdx;
    uint32_t nBytesReadIdx;

    /* Take a snapshot of indices to avoid creation of critical section */

    rdOutIndex = sercom4USARTObj.rdOutIndex;
    rdInIndex = sercom4USARTObj.rdInIndex;

    while (nBytesRead < size)
    {
        if (rdOutIndex != rdInIndex)
        {
            if (((SERCOM4_REGS->USART.SERCOM_CTRLB & SERCOM_USART_CTRLB_CHSIZE_Msk) >> SERCOM_USART_CTRLB_CHSIZE_Pos) != 0x01U)
            {
                pRdBuffer[nBytesRead] = SERCOM4_USART_ReadBuffer[rdOutIndex];
                nBytesRead += 1U;
                rdOutIndex += 1U;
            }
            else
            {
                rdOutIdx = rdOutIndex << 1U;
                nBytesReadIdx = nBytesRead << 1U;

                pRdBuffer[nBytesReadIdx] = SERCOM4_USART_ReadBuffer[rdOutIdx];
                pRdBuffer[nBytesReadIdx + 1U] = SERCOM4_USART_ReadBuffer[rdOutIdx + 1U];

                rdOutIndex += 1U;
                nBytesRead += 1U;
            }

            if (rdOutIndex >= sercom4USARTObj.rdBufferSize)
            {
                rdOutIndex = 0U;
            }
        }
        else
        {
            /* No more data available in the RX buffer */
            break;
        }
    }

    sercom4USARTObj.rdOutIndex = rdOutIndex;

    return nBytesRead;
}

size_t SERCOM4_USART_ReadCountGet(void)
{
    size_t nUnreadBytesAvailable;
    uint32_t rdOutIndex;
    uint32_t rdInIndex;

    /* Take a snapshot of indices to avoid creation of critical section */
    rdOutIndex = sercom4USARTObj.rdOutIndex;
    rdInIndex = sercom4USARTObj.rdInIndex;

    if ( rdInIndex >=  rdOutIndex)
    {
        nUnreadBytesAvailable =  rdInIndex - rdOutIndex;
    }
    else
    {
        nUnreadBytesAvailable =  (sercom4USARTObj.rdBufferSize -  rdOutIndex) + rdInIndex;
    }

    return nUnreadBytesAvailable;
}

size_t SERCOM4_USART_ReadFreeBufferCountGet(void)
{
    return (sercom4USARTObj.rdBufferSize - 1U) - SERCOM4_USART_ReadCountGet();
}

size_t SERCOM4_USART_ReadBufferSizeGet(void)
{
    return (sercom4USARTObj.rdBufferSize - 1U);
}

bool SERCOM4_USART_ReadNotificationEnable(bool isEnabled, bool isPersistent)
{
    bool previousStatus = sercom4USARTObj.isRdNotificationEnabled;

    sercom4USARTObj.isRdNotificationEnabled = isEnabled;

    sercom4USARTObj.isRdNotifyPersistently = isPersistent;

    return previousStatus;
}

void SERCOM4_USART_ReadThresholdSet(uint32_t nBytesThreshold)
{
    if (nBytesThreshold > 0U)
    {
        sercom4USARTObj.rdThreshold = nBytesThreshold;
    }
}

void SERCOM4_USART_ReadCallbackRegister( SERCOM_USART_RING_BUFFER_CALLBACK callback, uintptr_t context)
{
    sercom4USARTObj.rdCallback = callback;

    sercom4USARTObj.rdContext = context;
}


bool SERCOM4_USART_TransmitComplete( void )
{
    bool transmitComplete = false;

    if ((SERCOM4_REGS->USART.SERCOM_INTFLAG & SERCOM_USART_INTFLAG_TXC_Msk) == SERCOM_USART_INTFLAG_TXC_Msk)
    {
        transmitComplete = true;
    }

    return transmitComplete;
}

/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static bool SERCOM4_USART_TxPullByte(void* pWrData)
{
    bool isSuccess = false;
    uint32_t wrInIndex = sercom4USARTObj.wrInIndex;
    uint32_t wrOutIndex = sercom4USARTObj.wrOutIndex;
    uint32_t wrOutIdx;
    uint8_t* pWrByte = (uint8_t*)pWrData;

    if (wrOutIndex != wrInIndex)
    {
        if (((SERCOM4_REGS->USART.SERCOM_CTRLB & SERCOM_USART_CTRLB_CHSIZE_Msk) >> SERCOM_USART_CTRLB_CHSIZE_Pos) != 0x01U)
        {
            *pWrByte = SERCOM4_USART_WriteBuffer[wrOutIndex];
            wrOutIndex++;
        }
        else
        {
            wrOutIdx = wrOutIndex << 1U;
            pWrByte[0] = SERCOM4_USART_WriteBuffer[wrOutIdx];
            pWrByte[1] = SERCOM4_USART_WriteBuffer[wrOutIdx + 1U];

            wrOutIndex++;
        }


        if (wrOutIndex >= sercom4USARTObj.wrBufferSize)
        {
            wrOutIndex = 0U;
        }

        sercom4USARTObj.wrOutIndex = wrOutIndex;

        isSuccess = true;
    }

    return isSuccess;
}

static inline bool SERCOM4_USART_TxPushByte(uint16_t wrByte)
{
    uint32_t tempInIndex;
    uint32_t wrInIndex = sercom4USARTObj.wrInIndex;
    uint32_t wrOutIndex = sercom4USARTObj.wrOutIndex;
    uint32_t wrInIdx;

    bool isSuccess = false;

    tempInIndex = wrInIndex + 1U;

    if (tempInIndex >= sercom4USARTObj.wrBufferSize)
    {
        tempInIndex = 0U;
    }
    if (tempInIndex != wrOutIndex)
    {
        if (((SERCOM4_REGS->USART.SERCOM_CTRLB & SERCOM_USART_CTRLB_CHSIZE_Msk) >> SERCOM_USART_CTRLB_CHSIZE_Pos) != 0x01U)
        {
            SERCOM4_USART_WriteBuffer[wrInIndex] = (uint8_t)wrByte;
        }
        else
        {
            wrInIdx = wrInIndex << 1U;

            SERCOM4_USART_WriteBuffer[wrInIdx] = (uint8_t)wrByte;
            wrInIdx++;
            SERCOM4_USART_WriteBuffer[wrInIdx] = (uint8_t)(wrByte >> 8U);
        }

        sercom4USARTObj.wrInIndex = tempInIndex;

        isSuccess = true;
    }
    else
    {
        /* Queue is full. Report Error. */
    }

    return isSuccess;
}

/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static void SERCOM4_USART_SendWriteNotification(void)
{
    uint32_t nFreeWrBufferCount;

    if (sercom4USARTObj.isWrNotificationEnabled == true)
    {
        nFreeWrBufferCount = SERCOM4_USART_WriteFreeBufferCountGet();

        if(sercom4USARTObj.wrCallback != NULL)
        {
            uintptr_t wrContext = sercom4USARTObj.wrContext;

            if (sercom4USARTObj.isWrNotifyPersistently == true)
            {
                if (nFreeWrBufferCount >= sercom4USARTObj.wrThreshold)
                {
                    sercom4USARTObj.wrCallback(SERCOM_USART_EVENT_WRITE_THRESHOLD_REACHED, wrContext);
                }
            }
            else
            {
                if (nFreeWrBufferCount == sercom4USARTObj.wrThreshold)
                {
                    sercom4USARTObj.wrCallback(SERCOM_USART_EVENT_WRITE_THRESHOLD_REACHED, wrContext);
                }
            }
        }
    }
}

static size_t SERCOM4_USART_WritePendingBytesGet(void)
{
    size_t nPendingTxBytes;

    /* Take a snapshot of indices to avoid creation of critical section */
    uint32_t wrInIndex = sercom4USARTObj.wrInIndex;
    uint32_t wrOutIndex = sercom4USARTObj.wrOutIndex;

    if ( wrInIndex >= wrOutIndex)
    {
        nPendingTxBytes =  wrInIndex - wrOutIndex;
    }
    else
    {
        nPendingTxBytes =  (sercom4USARTObj.wrBufferSize -  wrOutIndex) + wrInIndex;
    }

    return nPendingTxBytes;
}

size_t SERCOM4_USART_WriteCountGet(void)
{
    size_t nPendingTxBytes;

    nPendingTxBytes = SERCOM4_USART_WritePendingBytesGet();

    return nPendingTxBytes;
}

size_t SERCOM4_USART_Write(uint8_t* pWrBuffer, const size_t size )
{
    size_t nBytesWritten  = 0U;

    while (nBytesWritten < size)
    {
        if (((SERCOM4_REGS->USART.SERCOM_CTRLB & SERCOM_USART_CTRLB_CHSIZE_Msk) >> SERCOM_USART_CTRLB_CHSIZE_Pos) != 0x01U)
        {
            if (SERCOM4_USART_TxPushByte(pWrBuffer[nBytesWritten]) == true)
            {
                nBytesWritten++;
            }
            else
            {
                /* Queue is full, exit the loop */
                break;
            }
        }
        else
        {
            uint16_t halfWordData = (uint16_t)(pWrBuffer[(2U * nBytesWritten) + 1U]);
            halfWordData <<= 8U;
            halfWordData |= (uint16_t)pWrBuffer[2U * nBytesWritten];
            if (SERCOM4_USART_TxPushByte(halfWordData) == true)
            {
                nBytesWritten++;
            }
            else
            {
                /* Queue is full, exit the loop */
                break;
            }
        }
    }

    /* Check if any data is pending for transmission */
    if (SERCOM4_USART_WritePendingBytesGet() > 0U)
    {
        /* Enable TX interrupt as data is pending for transmission */
        SERCOM4_USART_TX_INT_ENABLE();
    }

    return nBytesWritten;
}

size_t SERCOM4_USART_WriteFreeBufferCountGet(void)
{
    return (sercom4USARTObj.wrBufferSize - 1U) - SERCOM4_USART_WriteCountGet();
}

size_t SERCOM4_USART_WriteBufferSizeGet(void)
{
    return (sercom4USARTObj.wrBufferSize - 1U);
}

bool SERCOM4_USART_WriteNotificationEnable(bool isEnabled, bool isPersistent)
{
    bool previousStatus = sercom4USARTObj.isWrNotificationEnabled;

    sercom4USARTObj.isWrNotificationEnabled = isEnabled;

    sercom4USARTObj.isWrNotifyPersistently = isPersistent;

    return previousStatus;
}

void SERCOM4_USART_WriteThresholdSet(uint32_t nBytesThreshold)
{
    if (nBytesThreshold > 0U)
    {
        sercom4USARTObj.wrThreshold = nBytesThreshold;
    }
}

void SERCOM4_USART_WriteCallbackRegister( SERCOM_USART_RING_BUFFER_CALLBACK callback, uintptr_t context)
{
    sercom4USARTObj.wrCallback = callback;

    sercom4USARTObj.wrContext = context;
}



static void __attribute__((used)) SERCOM4_USART_ISR_ERR_Handler( void )
{
    USART_ERROR errorStatus = (USART_ERROR)(SERCOM4_REGS->USART.SERCOM_STATUS & (SERCOM_USART_STATUS_PERR_Msk | SERCOM_USART_STATUS_FERR_Msk | SERCOM_USART_STATUS_BUFOVF_Msk ));

    if(errorStatus != USART_ERROR_NONE)
    {
        /* Save the error to report later */
        sercom4USARTObj.errorStatus = errorStatus;

        /* Clear error flags and flush the error bytes */
        SERCOM4_USART_ErrorClear();

        if(sercom4USARTObj.rdCallback != NULL)
        {
            uintptr_t rdContext = sercom4USARTObj.rdContext;

            sercom4USARTObj.rdCallback(SERCOM_USART_EVENT_READ_ERROR, rdContext);
        }
    }
}

static void __attribute__((used)) SERCOM4_USART_ISR_RX_Handler( void )
{


    while ((SERCOM4_REGS->USART.SERCOM_INTFLAG & SERCOM_USART_INTFLAG_RXC_Msk) == SERCOM_USART_INTFLAG_RXC_Msk)
    {
        if (SERCOM4_USART_RxPushByte( (uint16_t)SERCOM4_REGS->USART.SERCOM_DATA) == true)
        {
            SERCOM4_USART_ReadNotificationSend();
        }
        else
        {
            /* UART RX buffer is full */
        }
    }
}

static void __attribute__((used)) SERCOM4_USART_ISR_TX_Handler( void )
{
    uint16_t wrByte;

    while ((SERCOM4_REGS->USART.SERCOM_INTFLAG & SERCOM_USART_INTFLAG_DRE_Msk) == SERCOM_USART_INTFLAG_DRE_Msk)
    {
        if (SERCOM4_USART_TxPullByte(&wrByte) == true)
        {
            if (((SERCOM4_REGS->USART.SERCOM_CTRLB & SERCOM_USART_CTRLB_CHSIZE_Msk) >> SERCOM_USART_CTRLB_CHSIZE_Pos) != 0x01U)
            {
                SERCOM4_REGS->USART.SERCOM_DATA = (uint8_t)wrByte;
            }
            else
            {
                SERCOM4_REGS->USART.SERCOM_DATA = wrByte;
            }

            SERCOM4_USART_SendWriteNotification();
        }
        else
        {
            /* Nothing to transmit. Disable the data register empty interrupt. */
            SERCOM4_USART_TX_INT_DISABLE();
            break;
        }
    }
}

void __attribute__((used)) SERCOM4_USART_InterruptHandler( void )
{
    bool testCondition = false;
    if(SERCOM4_REGS->USART.SERCOM_INTENSET != 0U)
    {
        /* Checks for error flag */
        testCondition = ((SERCOM4_REGS->USART.SERCOM_INTFLAG & SERCOM_USART_INTFLAG_ERROR_Msk) == SERCOM_USART_INTFLAG_ERROR_Msk);
        testCondition = ((SERCOM4_REGS->USART.SERCOM_INTENSET & SERCOM_USART_INTENSET_ERROR_Msk) == SERCOM_USART_INTENSET_ERROR_Msk) && testCondition;
        if(testCondition)
        {
            SERCOM4_USART_ISR_ERR_Handler();
        }

        testCondition = ((SERCOM4_REGS->USART.SERCOM_INTFLAG & SERCOM_USART_INTFLAG_DRE_Msk) == SERCOM_USART_INTFLAG_DRE_Msk);
        testCondition = ((SERCOM4_REGS->USART.SERCOM_INTENSET & SERCOM_USART_INTENSET_DRE_Msk) == SERCOM_USART_INTENSET_DRE_Msk) && testCondition;
        /* Checks for data register empty flag */
        if(testCondition)
        {
            SERCOM4_USART_ISR_TX_Handler();
        }

        /* Checks for receive complete empty flag */
        testCondition = ((SERCOM4_REGS->USART.SERCOM_INTFLAG & SERCOM_USART_INTFLAG_RXC_Msk) != 0U);
        testCondition = ((SERCOM4_REGS->USART.SERCOM_INTENSET & SERCOM_USART_INTENSET_RXC_Msk) != 0U) && testCondition;
        if(testCondition)
        {
            SERCOM4_USART_ISR_RX_Handler();
        }
    }
}