/*******************************************************************************
  SQI Peripheral Library Source File

  Company
    Microchip Technology Inc.

  File Name
    plibsqi.c

  Summary
    SQI peripheral library interface.

  Description

  Remarks:

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
#include "interrupts.h"
#include "plib_sqi.h"

#define SQI_CFG_CHIP_SELECT         (0x2 << SQICFG_CSEN_POSITION)

typedef struct
{
    SQI_EVENT_HANDLER EventHandler;
    uintptr_t Context;
}sqiCallbackObjType;

volatile static sqiCallbackObjType SQICallbackObj;

void SQI_Initialize(void)
{
    // Reset and Disable SQI
    SQI_REGS->SQI_CTRLA =  SQI_CTRLA_SWRST_Msk  ;

    while((SQI_REGS->SQI_SYNCBUSY & SQI_SYNCBUSY_SWRST_Msk) == SQI_SYNCBUSY_SWRST_Msk)
    {
        //wait for synchronization
    }

    // Set Config Register values
    SQI_REGS->SQI_CFG =  SQI_CFG_MODE(0x02U)  | SQI_CFG_BURSTEN_Msk |
                SQI_CFG_DATAEN(0x2U) | SQI_CFG_CSEN(0x2U)   ;

     // SQICLK configuration
    SQI_REGS->SQI_CLKCON      = SQI_CLKCON_EN_Msk;              // Enable Clock

    while ((SQI_REGS->SQI_CLKCON & SQI_CLKCON_STABLE_Msk) == 0U)
    {
        // Wait for clock to become stable
    }

    SQI_REGS->SQI_CLKCON      |= SQI_CLKCON_CLKDIV(0x1U);

    // Enable the SQI Module
    SQI_REGS->SQI_CFG         |= SQI_CFG_SQIEN_Msk;

    SQI_REGS->SQI_INTSIGEN             = 0x00000000;
    SQI_REGS->SQI_INTEN                = 0x00000000;
    SQI_REGS->SQI_INTSTAT              = 0;

    SQI_REGS->SQI_CMDTHR               = SQI_CMDTHR_RXCMDTHR(0x20U) | SQI_CMDTHR_TXCMDTHR(0x20U);
    SQI_REGS->SQI_INTTHR               = SQI_INTTHR_RXINTTHR(0x01U) | SQI_INTTHR_TXINTTHR(0x01U);
    SQI_REGS->SQI_THR                  = SQI_THR_THRES(0x01U);

    SQI_REGS->SQI_INTEN                = (SQI_INTEN_PKTCOMPIE_Msk | SQI_INTEN_BDDONEIE_Msk);
    SQI_REGS->SQI_INTSIGEN             = (SQI_INTSIGEN_PKTCOMPISE_Msk | SQI_INTSIGEN_BDDONEISE_Msk);

    // Flash status check
    SQI_REGS->SQI_MEMSTAT              = SQI_MEMSTAT_STATCMD(0x5U) | SQI_MEMSTAT_STATBYTES(0x2U) | SQI_MEMSTAT_TYPESTAT(0x2U) | SQI_MEMSTAT_STATPOS(0x1U);

    SQI_REGS->SQI_INTFLAG              = SQI_INTFLAG_SQI_Msk;
    SQI_REGS->SQI_INTENSET             = SQI_INTENSET_SQI_Msk;

}

void SQI_DMASetup(void)
{
    SQI_REGS->SQI_CFG              |= SQI_CFG_MODE(0x02U);

    SQI_REGS->SQI_INTEN            &= ~SQI_INTEN_PKTCOMPIE_Msk;
    SQI_REGS->SQI_INTEN            |= SQI_INTEN_PKTCOMPIE_Msk;

    SQI_REGS->SQI_INTEN            &= ~SQI_INTEN_BDDONEIE_Msk;
    SQI_REGS->SQI_INTEN            |= SQI_INTEN_BDDONEIE_Msk;

    SQI_REGS->SQI_INTFLAG          = SQI_INTFLAG_SQI_Msk;
    SQI_REGS->SQI_INTENSET         = SQI_INTENSET_SQI_Msk;
}

void SQI_DMATransfer(sqi_dma_desc_t *sqiDmaDesc)
{
    // Reset RX FIFO before starting DMA
    SQI_REGS->SQI_CFG              |= SQI_CFG_RXBUFRST_Msk;

    // Initialize the root buffer descriptor
    SQI_REGS->SQI_BDBASEADD         = (uint32_t)sqiDmaDesc;

    // Enable DMA and start the Buffer descriptor processing
    SQI_REGS->SQI_BDCON             = SQI_BDCON_START_Msk | SQI_BDCON_DMAEN_Msk;
}

void SQI_XIPSetup(uint32_t sqiXcon1Val, uint32_t sqiXcon2Val)
{
    SQI_REGS->SQI_XCON1           = sqiXcon1Val;
    SQI_REGS->SQI_XCON2           = sqiXcon2Val;

    SQI_REGS->SQI_CFG            |= SQI_CFG_MODE(0x03U);
}

void SQI_RegisterCallback(SQI_EVENT_HANDLER event_handler, uintptr_t context)
{
    SQICallbackObj.EventHandler = event_handler;
    SQICallbackObj.Context      = context;
}

void __attribute__((used)) SQI_InterruptHandler(void)
{
    uintptr_t context_var;
    SQI_REGS->SQI_INTFLAG          = SQI_INTFLAG_SQI_Msk;

    if (((SQI_REGS->SQI_INTSTAT & SQI_INTSTAT_PKTCOMPIF_Msk) != 0U) || ((SQI_REGS->SQI_INTSTAT & SQI_INTSTAT_BDDONEIF_Msk) != 0U))
    {
        SQI_REGS->SQI_INTSTAT      &= ~SQI_INTSTAT_PKTCOMPIF_Msk;
        SQI_REGS->SQI_INTEN        &= ~SQI_INTEN_PKTCOMPIE_Msk;
        SQI_REGS->SQI_INTEN        |= SQI_INTEN_PKTCOMPIE_Msk;

        SQI_REGS->SQI_INTSTAT      &= ~SQI_INTSTAT_BDDONEIF_Msk;
        SQI_REGS->SQI_INTEN        &= ~SQI_INTEN_BDDONEIE_Msk;
        SQI_REGS->SQI_INTEN        |= SQI_INTEN_BDDONEIE_Msk;

        // Disable DMA
        SQI_REGS->SQI_BDCON        = 0x0;

        if (SQICallbackObj.EventHandler != NULL)
        {
            context_var = SQICallbackObj.Context;
            SQICallbackObj.EventHandler(context_var);
        }
    }
}
