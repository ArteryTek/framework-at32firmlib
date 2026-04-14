/**
  **************************************************************************
  * @file     at32l021_misc.h
  * @brief    at32l021 misc header file
  **************************************************************************
  *
  * Copyright (c) 2025, Artery Technology, All rights reserved.
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */

/* define to prevent recursive inclusion -------------------------------------*/
#ifndef __AT32L021_MISC_H
#define __AT32L021_MISC_H

#ifdef __cplusplus
extern "C" {
#endif


/* includes ------------------------------------------------------------------*/
#include "at32l021.h"

/** @addtogroup AT32L021_periph_driver
  * @{
  */

/** @addtogroup MISC
  * @{
  */

/** @defgroup MISC_vector_table_base_address
  * @{
  */

#define NVIC_VECTTAB_RAM                 ((uint32_t)0x20000000) /*!< nvic vector table based ram address */
#define NVIC_VECTTAB_FLASH               ((uint32_t)0x08000000) /*!< nvic vector table based flash address */

/**
  * @}
  */

/** @defgroup MISC_exported_types
  * @{
  */

/**
  * @brief nvic low power mode
  */
typedef enum
{
  NVIC_LP_SLEEPONEXIT                    = 0x02, /*!< enable sleep-on-exit feature */
  NVIC_LP_SLEEPDEEP                      = 0x04, /*!< enable sleep-deep output signal when entering sleep mode */
  NVIC_LP_SEVONPEND                      = 0x10  /*!< send event on pending */
} nvic_lowpower_mode_type;

/**
  * @brief systick clock source
  */
typedef enum
{
  SYSTICK_CLOCK_SOURCE_AHBCLK_DIV8       = ((uint32_t)0x00000000), /*!< systick clock source from core clock div8 */
  SYSTICK_CLOCK_SOURCE_AHBCLK_NODIV      = ((uint32_t)0x00000004)  /*!< systick clock source from core clock */
} systick_clock_source_type;

/**
  * @}
  */

/** @defgroup MISC_exported_functions
  * @{
  */

void nvic_system_reset(void);
void nvic_irq_enable(IRQn_Type irqn, uint32_t preempt_priority, uint32_t sub_priority);
void nvic_irq_disable(IRQn_Type irqn);
void nvic_vector_table_set(uint32_t base, uint32_t offset);
void nvic_lowpower_mode_config(nvic_lowpower_mode_type lp_mode, confirm_state new_state);
void systick_clock_source_config(systick_clock_source_type source);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif
