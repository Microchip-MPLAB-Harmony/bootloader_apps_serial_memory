/*******************************************************************************
  MPU PLIB Implementation

  Company:
    Microchip Technology Inc.

  File Name:
    plib_mpu.h

  Summary:
    MPU PLIB Source File

  Description:
    None

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

#include "plib_mpu.h"
#include "plib_mpu_local.h"


// *****************************************************************************
// *****************************************************************************
// Section: MPU Implementation
// *****************************************************************************
// *****************************************************************************

void MPU_Initialize(void)
{
    /*** Disable MPU            ***/
    MPU->CTRL = 0;

    /*** Configure MPU Regions  ***/

    /* Disable Region 0*/
    MPU->RBAR = MPU_RBAR_REGION(0U) | MPU_RBAR_VALID_Msk;
    MPU->RASR &= ~MPU_ATTR_ENABLE;

    /* Disable Region 1*/
    MPU->RBAR = MPU_RBAR_REGION(1U) | MPU_RBAR_VALID_Msk;
    MPU->RASR &= ~MPU_ATTR_ENABLE;

    /* Disable Region 2*/
    MPU->RBAR = MPU_RBAR_REGION(2U) | MPU_RBAR_VALID_Msk;
    MPU->RASR &= ~MPU_ATTR_ENABLE;

    /* Disable Region 3*/
    MPU->RBAR = MPU_RBAR_REGION(3U) | MPU_RBAR_VALID_Msk;
    MPU->RASR &= ~MPU_ATTR_ENABLE;

    /* Disable Region 4*/
    MPU->RBAR = MPU_RBAR_REGION(4U) | MPU_RBAR_VALID_Msk;
    MPU->RASR &= ~MPU_ATTR_ENABLE;

    /* Disable Region 5*/
    MPU->RBAR = MPU_RBAR_REGION(5U) | MPU_RBAR_VALID_Msk;
    MPU->RASR &= ~MPU_ATTR_ENABLE;

    /* Disable Region 6*/
    MPU->RBAR = MPU_RBAR_REGION(6U) | MPU_RBAR_VALID_Msk;
    MPU->RASR &= ~MPU_ATTR_ENABLE;

    /* Disable Region 7*/
    MPU->RBAR = MPU_RBAR_REGION(7U) | MPU_RBAR_VALID_Msk;
    MPU->RASR &= ~MPU_ATTR_ENABLE;









    /* Enable Memory Management Fault */
    SCB->SHCSR |= (SCB_SHCSR_MEMFAULTENA_Msk);

    /* Enable MPU */
    MPU->CTRL = MPU_CTRL_ENABLE_Msk  | MPU_CTRL_PRIVDEFENA_Msk;

    __DSB();
    __ISB();
}

