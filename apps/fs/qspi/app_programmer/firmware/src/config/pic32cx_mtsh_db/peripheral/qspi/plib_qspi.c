/*******************************************************************************
  QSPI Peripheral Library Source File

  Company
    Microchip Technology Inc.

  File Name
    plib_qspi.c

  Summary
    QSPI peripheral library interface.

  Description

  Remarks:

*******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#include "plib_qspi.h"
#include "string.h" // memmove


void QSPI_Initialize(void)
{
    // Reset and Disable the qspi Module
    QSPI_REGS->QSPI_CR = QSPI_CR_SWRST_Msk | QSPI_CR_QSPIDIS_Msk;

    while((QSPI_REGS->QSPI_SR & QSPI_SR_QSPIENS_Msk) != 0U)
    {
        /* Do Nothing */
    }


    /* DLYCS  = 0x0 */
    /* DLYBCT = 0x0 */
    /* NBBITS = 0x8 */
    /* CSMODE = 0x0 */
    /* WDRBT  = 0 */
    /* SMM    = MEMORY */
    QSPI_REGS->QSPI_MR = ( QSPI_MR_SMM_MEMORY | QSPI_MR_NBBITS(0x8U));


    /* Wait for synchronization */
    while((QSPI_REGS->QSPI_SR & QSPI_SR_SYNCBSY_Msk) != 0U)
    {
        /* Do Nothing */
    }

    /* Update Configuration */
    QSPI_REGS->QSPI_CR = QSPI_CR_UPDCFG_Msk;

    /* Wait for synchronization */
    while((QSPI_REGS->QSPI_SR & QSPI_SR_SYNCBSY_Msk) != 0U)
    {
        /* Do Nothing */
    }

    // Enable the qspi Module
    QSPI_REGS->QSPI_CR = QSPI_CR_QSPIEN_Msk;

    while((QSPI_REGS->QSPI_SR & QSPI_SR_QSPIENS_Msk) == 0U)
    {
        /* Do Nothing */
    }
}

static void qspi_memcpy_32bit(uint32_t* dst, uint32_t* src, uint32_t count)
{
    while (count != 0U)
    {
        *dst = *src;
        src++;
        dst++;
        count--;
    }
}

static void qspi_memcpy_8bit(uint8_t* dst, uint8_t* src, uint32_t count)
{
    while (count != 0U)
    {
        *dst = *src;
        src++;
        dst++;
        count--;
    }
}

static bool qspi_setup_transfer( qspi_memory_xfer_t *qspi_memory_xfer, QSPI_TRANSFER_TYPE tfr_type, uint32_t address )
{
    uint32_t mask = 0;

    /* Set instruction address register */
    QSPI_REGS->QSPI_IAR = QSPI_IAR_ADDR(address);

    /* Set Instruction code register */
    if ((tfr_type == QSPI_REG_READ) || (tfr_type == QSPI_MEM_READ))
    {
        QSPI_REGS->QSPI_RICR = (QSPI_RICR_RDINST((uint32_t)qspi_memory_xfer->instruction)) | (QSPI_RICR_RDOPT((uint32_t)qspi_memory_xfer->option));
    } else
    {
        QSPI_REGS->QSPI_WICR = (QSPI_WICR_WRINST((uint32_t)qspi_memory_xfer->instruction)) | (QSPI_WICR_WROPT((uint32_t)qspi_memory_xfer->option));
    }

    /* Set Instruction Frame register*/

    mask |= (uint32_t)qspi_memory_xfer->width;
    mask |= (uint32_t)qspi_memory_xfer->addr_len;

    if (qspi_memory_xfer->option_en)
    {
        mask |= (uint32_t)qspi_memory_xfer->option_len;
        mask |= QSPI_IFR_OPTEN_Msk;
    }

    if (qspi_memory_xfer->continuous_read_en)
    {
        mask |= QSPI_IFR_CRM_Msk;
    }

    mask |= QSPI_IFR_NBDUM((uint32_t)qspi_memory_xfer->dummy_cycles);

    mask |= QSPI_IFR_INSTEN_Msk | QSPI_IFR_ADDREN_Msk | QSPI_IFR_DATAEN_Msk;

    switch (tfr_type){
        case QSPI_REG_READ:
            mask |= QSPI_IFR_TFRTYP(QSPI_IFR_TFRTYP_TRSFR_REGISTER_Val);
            mask |= QSPI_IFR_SMRM(1U);
            mask |= QSPI_IFR_APBTFRTYP(1U);
            break;
        case QSPI_REG_WRITE:
            mask |= QSPI_IFR_TFRTYP(QSPI_IFR_TFRTYP_TRSFR_REGISTER_Val);
            mask |= QSPI_IFR_SMRM(1U);
            break;
        case QSPI_MEM_READ:
            mask |= QSPI_IFR_TFRTYP(QSPI_IFR_TFRTYP_TRSFR_MEMORY_Val);
            break;
        case QSPI_MEM_WRITE:
            mask |= QSPI_IFR_TFRTYP(QSPI_IFR_TFRTYP_TRSFR_MEMORY_Val);
            break;
        default :
                 /* Do Nothing */
            break;
    };

    if (qspi_memory_xfer->ddr_en)
    {
        mask |= QSPI_IFR_DDREN_Msk;
    }
    if (qspi_memory_xfer->dqs_en)
    {
        mask |= QSPI_IFR_DQSEN_Msk;
    }
    if (qspi_memory_xfer->ddr_cmd_en)
    {
        mask |= QSPI_IFR_DDRCMDEN_Msk;
    }

    mask |= (uint32_t)qspi_memory_xfer->protocol_type;

    QSPI_REGS->QSPI_IFR = mask;

    /* Wait for synchronization */
    while((QSPI_REGS->QSPI_SR & QSPI_SR_SYNCBSY_Msk) != 0U)
    {
        /* Do Nothing */
    }

    /* Update Configuration */
    QSPI_REGS->QSPI_CR = QSPI_CR_UPDCFG_Msk;

    /* Wait for synchronization */
    while((QSPI_REGS->QSPI_SR & QSPI_SR_SYNCBSY_Msk) != 0U)
    {
        /* Do Nothing */
    }

    return true;
}

void QSPI_EndTransfer( void )
{
    QSPI_REGS->QSPI_CR = QSPI_CR_LASTXFER_Msk;
}

bool QSPI_CommandWrite( qspi_command_xfer_t *qspi_command_xfer, uint32_t address )
{
    uint32_t mask = 0;

    /* Configure address */
    if(qspi_command_xfer->addr_en)
    {
        QSPI_REGS->QSPI_IAR = QSPI_IAR_ADDR(address);

        mask |= QSPI_IFR_ADDREN_Msk;
        mask |= (uint32_t)qspi_command_xfer->addr_len;
    }

    /* Configure instruction */
    QSPI_REGS->QSPI_WICR = QSPI_WICR_WRINST((uint32_t)qspi_command_xfer->instruction);

    /* Configure instruction frame */
    mask |= (uint32_t)qspi_command_xfer->width;
    mask |= QSPI_IFR_INSTEN_Msk;
    /* TFRTYP:0, SMRM:1, APBTFRTYP:0 */
    mask |= QSPI_IFR_SMRM(1U);
    if (qspi_command_xfer->ddr_en)
    {
        mask |= QSPI_IFR_DDREN_Msk;
    }
    if (qspi_command_xfer->ddr_cmd_en)
    {
        mask |= QSPI_IFR_DDRCMDEN_Msk;
    }
    mask |= (uint32_t)qspi_command_xfer->protocol_type;

    QSPI_REGS->QSPI_IFR = mask;

    /* Wait for synchronization */
    while((QSPI_REGS->QSPI_SR & QSPI_SR_SYNCBSY_Msk) != 0U)
    {
        /* Do Nothing */
    }

    /* Update Configuration */
    QSPI_REGS->QSPI_CR = QSPI_CR_UPDCFG_Msk;

    /* Wait for synchronization */
    while((QSPI_REGS->QSPI_SR & QSPI_SR_SYNCBSY_Msk) != 0U)
    {
        /* Do Nothing */
    }

    /* Start Transfer */
    QSPI_REGS->QSPI_CR = QSPI_CR_STTFR_Msk;

    /* Wait for chip select rise */
    while((QSPI_REGS->QSPI_ISR & QSPI_ISR_CSRA_Msk) == 0U)
    {
        /* Do Nothing */
    }

    return true;
}

bool QSPI_RegisterRead( qspi_register_xfer_t *qspi_register_xfer, uint32_t *rx_data, uint8_t rx_data_length )
{
    uint32_t mask = 0;
    uint8_t rx_data_len = rx_data_length;
    uint8_t *ptr_rx_data = (uint8_t *)rx_data;

    /* Configure address */
    if(qspi_register_xfer->addr_en)
    {
        QSPI_REGS->QSPI_IAR = QSPI_IAR_ADDR(qspi_register_xfer->address);

        mask |= QSPI_IFR_ADDREN_Msk;
        mask |= (uint32_t)qspi_register_xfer->addr_len;
    }

    /* Configure Instruction */
    QSPI_REGS->QSPI_RICR = QSPI_RICR_RDINST((uint32_t)qspi_register_xfer->instruction);

    /* Configure Instruction Frame */
    mask |= (uint32_t)qspi_register_xfer->width;

    mask |= QSPI_IFR_NBDUM((uint32_t)qspi_register_xfer->dummy_cycles);

    mask |= QSPI_IFR_INSTEN_Msk | QSPI_IFR_DATAEN_Msk;

    /* TFRTYP:0, SMRM:1, APBTFRTYP:1 */
    mask |= QSPI_IFR_SMRM(1U);
    mask |= QSPI_IFR_APBTFRTYP(1U);
    if (qspi_register_xfer->ddr_en)
    {
        mask |= QSPI_IFR_DDREN_Msk;
    }
    if (qspi_register_xfer->ddr_cmd_en)
    {
        mask |= QSPI_IFR_DDRCMDEN_Msk;
    }
    mask |= (uint32_t)qspi_register_xfer->protocol_type;

    QSPI_REGS->QSPI_IFR = mask;

    /* Wait for synchronization */
    while((QSPI_REGS->QSPI_SR & QSPI_SR_SYNCBSY_Msk) != 0U)
    {
        /* Do Nothing */
    }

    /* Update Configuration */
    QSPI_REGS->QSPI_CR = QSPI_CR_UPDCFG_Msk;

    /* Wait for synchronization */
    while((QSPI_REGS->QSPI_SR & QSPI_SR_SYNCBSY_Msk) != 0U)
    {
        /* Do Nothing */
    }

    /* Start Transfer */
    QSPI_REGS->QSPI_CR = QSPI_CR_STTFR_Msk;

    while (rx_data_len > 0U)
    {
        /* Wait for Receive Data Register Full Flag */
        while((QSPI_REGS->QSPI_ISR & QSPI_ISR_RDRF_Msk) == 0U)
        {
            /* Do Nothing */
        }

        if (rx_data_len == 1U)
        {
            /* Wait for synchronization */
            while((QSPI_REGS->QSPI_SR & QSPI_SR_SYNCBSY_Msk) != 0U)
            {
                /* Do Nothing */
            }

            /* Last Transfer */
            QSPI_EndTransfer();
        }

        /* Wait for synchronization */
        while((QSPI_REGS->QSPI_SR & QSPI_SR_SYNCBSY_Msk) != 0U)
        {
            /* Do Nothing */
        }

        /* Read the register content */
        *ptr_rx_data = (uint8_t)QSPI_REGS->QSPI_RDR;
        ptr_rx_data++;
        rx_data_len--;
    }

    /* Wait for chip select rise */
    while((QSPI_REGS->QSPI_ISR & QSPI_ISR_CSRA_Msk) == 0U)
    {
        /* Do Nothing */
    }

    return true;
}

bool QSPI_RegisterWrite( qspi_register_xfer_t *qspi_register_xfer, uint32_t *tx_data, uint8_t tx_data_length )
{
    uint32_t mask = 0;
    uint8_t tx_data_len = tx_data_length;
    uint8_t *ptr_tx_data = (uint8_t *)tx_data;

    /* Configure address */
    if(qspi_register_xfer->addr_en)
    {
        QSPI_REGS->QSPI_IAR = QSPI_IAR_ADDR(qspi_register_xfer->address);

        mask |= QSPI_IFR_ADDREN_Msk;
        mask |= (uint32_t)qspi_register_xfer->addr_len;
    }

    /* Configure Instruction */
    QSPI_REGS->QSPI_WICR = QSPI_WICR_WRINST((uint32_t)qspi_register_xfer->instruction);

    /* Number of Write Access */
    QSPI_REGS->QSPI_WRACNT = QSPI_WRACNT_NBWRA((uint32_t)tx_data_length);

    /* Configure Instruction Frame */
    mask |= (uint32_t)qspi_register_xfer->width;

    mask |= QSPI_IFR_INSTEN_Msk | QSPI_IFR_DATAEN_Msk;
    if (qspi_register_xfer->ddr_en)
    {
        mask |= QSPI_IFR_DDREN_Msk;
    }
    if (qspi_register_xfer->ddr_cmd_en)
    {
        mask |= QSPI_IFR_DDRCMDEN_Msk;
    }
    mask |= (uint32_t)qspi_register_xfer->protocol_type;

    /* TFRTYP:0, SMRM:1, APBTFRTYP:0 */
    mask |= QSPI_IFR_SMRM(1);
    QSPI_REGS->QSPI_IFR = mask;

    /* Wait for synchronization */
    while((QSPI_REGS->QSPI_SR & QSPI_SR_SYNCBSY_Msk) != 0U)
    {
        /* Do Nothing */
    }

    /* Update Configuration */
    QSPI_REGS->QSPI_CR = QSPI_CR_UPDCFG_Msk;

    /* Wait for synchronization */
    while((QSPI_REGS->QSPI_SR & QSPI_SR_SYNCBSY_Msk) != 0U)
    {
        /* Do Nothing */
    }

    while (tx_data_len > 0U)
    {
        /* Wait for Transmit Data Register Empty Flag */
        while((QSPI_REGS->QSPI_ISR & QSPI_ISR_TDRE_Msk) == 0U)
        {
            /* Do nothing */
        }

        /* Write the content to register */
        QSPI_REGS->QSPI_TDR = *ptr_tx_data;
        ptr_tx_data++;
        tx_data_len--;

        if (tx_data_len == 0U)
        {
            /* Wait for Transmission Registers Empty */
            while((QSPI_REGS->QSPI_ISR & QSPI_ISR_TXEMPTY_Msk) == 0U)
            {
                /* Do nothing */
            }

            /* Wait for synchronization */
            while((QSPI_REGS->QSPI_SR & QSPI_SR_SYNCBSY_Msk) != 0U)
            {
                /* Do nothing */
            }

            QSPI_EndTransfer();
        }
    }

    /* Wait for chip select rise */
    while((QSPI_REGS->QSPI_ISR & QSPI_ISR_CSRA_Msk) == 0U)
    {
        /* Do Nothing */
    }

    return true;
}

/* MISRA C-2012 Rule 11.3 deviated:2 Deviation record ID -  H3_MISRAC_2012_R_11_3_DR_1 */

bool
QSPI_MemoryRead(
    qspi_memory_xfer_t *    qspi_memory_xfer,
    uint32_t *              rx_data,
    uint32_t                rx_data_length,
    uint32_t                address
    )
{
    /*  This implements a transfer from device source to a destination memory buffer
        without an intermediate local buffer.  The algorithm is used for efficiency
        sake, allowing a maximum number of word transfers from the device; but,
        not requiring word alignment at either end of source, or destination,
        locations.
        The non-boundary aligned header and trailer element sizes are used to
        characterizes the number of word transfers for the body.  The body is
        transfered in a word wide fashion followed by an appropriate shift of the
        bytes in the destination buffer.
        Single byte accesses at the head, or tail, are done as necessary.  The
        coding attempts to minimize unnecessary byte manipulations.
    */
    uint8_t *   qspi_mem  = (uint8_t *) (QSPI_MEM_ADDR | address);
    uint8_t *   pRxBuffer = (uint8_t *) rx_data;
    uint32_t    numDstPreWordBytes;
    uint32_t    numSrcPreWordBytes;
    uint32_t    numDstPostWordBytes = 0;
    uint32_t    numSrcPostWordBytes = 0;
    uint32_t    numWordTransferBytes = 0;
    int32_t     shiftBytes = 0;             // gt(0)=>right, lt(0)=>left shift
    uint8_t     tmpBuffer[ sizeof( uint32_t) ];
    uint32_t    temp;

    ///// device preliminaries
    if( false == qspi_setup_transfer( qspi_memory_xfer,
                            QSPI_MEM_READ,
                            address
                        ) ) {
        return false;
    }

    ///// dst and src buffer characterization
    numDstPreWordBytes =  0x03U & (uint32_t) pRxBuffer;
    if(( numDstPreWordBytes ) != 0U)
    {
        numDstPreWordBytes =  sizeof( uint32_t ) - numDstPreWordBytes;
    }
    if( rx_data_length >= numDstPreWordBytes )
    {
        numDstPostWordBytes = 0x03U & (uint32_t) (pRxBuffer + rx_data_length);
    }
    //
    numSrcPreWordBytes =  0x03U & (uint32_t) qspi_mem;
    if(( numSrcPreWordBytes ) != 0U)
    {
        numSrcPreWordBytes =  sizeof( uint32_t ) - numSrcPreWordBytes;
    }
    if( rx_data_length >= numSrcPreWordBytes )
    {
        numSrcPostWordBytes = 0x03U & (uint32_t) (qspi_mem + rx_data_length);
    }
    else
    {
        numSrcPreWordBytes = rx_data_length;
    }

    if( rx_data_length > (numSrcPreWordBytes + numSrcPostWordBytes) ) {
        // number of word size transfers is equal to length of buffer
        // minus single byte transfers
        numWordTransferBytes = rx_data_length - (numSrcPreWordBytes + numSrcPostWordBytes);
    }

    // test if src has same number of word alignments as the dst buffer
    if( (numDstPreWordBytes + numDstPostWordBytes) != (numSrcPreWordBytes + numSrcPostWordBytes)) {
        // a word size space will be needed for shifting purposes; the
        // common case optimization for equal word alignments cannot be used
        if( numWordTransferBytes >= sizeof( uint32_t ) ) {
            numWordTransferBytes -= sizeof( uint32_t );
            numSrcPostWordBytes += sizeof( uint32_t );
        }
        else {
            numWordTransferBytes = 0U;
        }
    }

    temp = numSrcPreWordBytes - numDstPreWordBytes;
    shiftBytes = (int32_t)temp;

    ///// Transfer of data from src device to dst buffer
    // Perform single byte transfers necessary before word alignment begins
    if(( numSrcPreWordBytes ) != 0U)
    {
        // get these now so we don't have to backup the device access later
        qspi_memcpy_8bit( tmpBuffer, qspi_mem, numSrcPreWordBytes );
        qspi_mem += numSrcPreWordBytes;     // word alignment point for the src
    }
    pRxBuffer += numDstPreWordBytes;        // word alignment point for the dst

    // Perform word aligned transfers
    if(( numWordTransferBytes / 4U ) != 0U)
    {
        qspi_memcpy_32bit( (uint32_t *) pRxBuffer,
                (uint32_t *) qspi_mem,
                numWordTransferBytes / 4U
            );
        qspi_mem += numWordTransferBytes;
        pRxBuffer += numWordTransferBytes;
    }

    if( 0 >= shiftBytes ) {                 // left, or no, shift
        if(( shiftBytes )!= 0) {
            // Shift the data left to its final destination buffer location
           (void) memmove( ((uint8_t *) rx_data) + numDstPreWordBytes + shiftBytes,
                    ((uint8_t *) rx_data) + numDstPreWordBytes,
                    numWordTransferBytes
                );
            pRxBuffer += shiftBytes;        // adjust end point
        }
        // Now we have room at the end, perform the single byte transfers
        // necessary after word alignment ends
        if(( numSrcPostWordBytes ) != 0U)
        {
            qspi_memcpy_8bit( pRxBuffer, qspi_mem, numSrcPostWordBytes );
        }
    }
    else {                                  // right shift
        // Perform the single byte transfers necessary after word alignment ends
        if(( numSrcPostWordBytes ) != 0U)
        {
            qspi_memcpy_8bit( pRxBuffer, qspi_mem, numSrcPostWordBytes );
        }

        if((numWordTransferBytes + numSrcPostWordBytes) > 0U)
        {
            // Shift the data to right to its final destination buffer location
            (void) memmove( ((uint8_t *) rx_data) + numDstPreWordBytes + shiftBytes,
                ((uint8_t *) rx_data) + numDstPreWordBytes,
                numWordTransferBytes + numSrcPostWordBytes
            );
        }
    }

    if(( numSrcPreWordBytes ) != 0U)
    {
        // Now we have room at the beginning;
        // place the previously saved pre-word aligned bytes
       (void) memmove( (uint8_t *)rx_data, tmpBuffer, numSrcPreWordBytes );
    }

    /* Wait if Read Busy */
    while((QSPI_REGS->QSPI_SR & QSPI_SR_RBUSY_Msk)  != 0U)
    {
        /* Do Nothing */
    }

    /* Wait for synchronization */
    while((QSPI_REGS->QSPI_SR & QSPI_SR_SYNCBSY_Msk)  != 0U)
    {
        /* Do Nothing */
    }

    QSPI_EndTransfer();

    /* Wait for chip select rise */
    while((QSPI_REGS->QSPI_ISR & QSPI_ISR_CSRA_Msk) == 0U)
    {
        /* Do Nothing */
    }

    return true;
}

/* MISRAC 2012 deviation block end */

bool QSPI_MemoryWrite( qspi_memory_xfer_t *qspi_memory_xfer, uint32_t *tx_data, uint32_t tx_data_length, uint32_t address )
{
    uint32_t *qspi_mem = (uint32_t *)(QSPI_MEM_ADDR | address);
    uint32_t length_32bit, length_8bit;

    /* Number of Write Access */
    QSPI_REGS->QSPI_WRACNT = QSPI_WRACNT_NBWRA(tx_data_length);

    if (false == qspi_setup_transfer(qspi_memory_xfer, QSPI_MEM_WRITE, address))
    {
        return false;
    }

    /* Write to serial flash memory */
    length_32bit = tx_data_length / 4U;
    length_8bit= tx_data_length & 0x03U;

    if(length_32bit != 0U)
    {
        qspi_memcpy_32bit(qspi_mem, tx_data, length_32bit);
    }

    tx_data = tx_data + length_32bit;
    qspi_mem = qspi_mem + length_32bit;

    if(length_8bit != 0U)
    {
        qspi_memcpy_8bit((uint8_t *)qspi_mem, (uint8_t *)tx_data, length_8bit);
    }

    /* Wait for Last Write Access */
    while((QSPI_REGS->QSPI_ISR & QSPI_ISR_LWRA_Msk) == 0U)
    {
        /* Do Nothing */
    }


    /* Wait for synchronization */
    while((QSPI_REGS->QSPI_SR & QSPI_SR_SYNCBSY_Msk) != 0U)
    {
        /* Do Nothing */
    }

    QSPI_EndTransfer();

    /* Wait for chip select rise */
    while((QSPI_REGS->QSPI_ISR & QSPI_ISR_CSRA_Msk) == 0U)
    {
        /* Do Nothing */
    }

    return true;
}

/*******************************************************************************
 End of File
*/
