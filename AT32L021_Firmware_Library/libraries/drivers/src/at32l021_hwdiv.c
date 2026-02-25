/**
  **************************************************************************
  * @file     at32l021_hwdiv.c
  * @brief    contains all the functions for the hwdiv firmware library
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

/* includes ------------------------------------------------------------------*/
#include "at32l021_conf.h"

/** @addtogroup AT32L021_periph_driver
  * @{
  */

/** @defgroup HWDIV
  * @brief HWDIV driver modules
  * @{
  */

#ifdef HWDIV_MODULE_ENABLED

/** @defgroup HWDIV_private_functions
  * @{
  */

/**
  * @brief  set 32-bit dividend.
  * @param  value: dividend value, it will be signed or unsigned
  * @retval none
  */
void hwdiv_dividend_set(uint32_t value)
{
  HWDIV->dvdd = value;
}

/**
  * @brief  set 32-bit divisor.
  * @param  value: divisor value, it will be signed or unsigned,
  *         operation will auto execute after setting value.
  * @retval none
  */
void hwdiv_divisor_set(uint32_t value)
{
  HWDIV->dvsr = value;
}

/**
  * @brief  get 32-bit quotient.
  * @param  none
  * @retval 32-bit quotient value, it will be signed or unsigned.
  */
uint32_t hwdiv_quotient_get(void)
{
  return (HWDIV->quot);
}

/**
  * @brief  get 32-bit remainder.
  * @param  none
  * @retval 32-bit remainder value, it will be signed or unsigned.
  */
uint32_t hwdiv_remainder_get(void)
{
  return (HWDIV->remd);
}

/**
  * @brief  enables or disables the hwdiv interrupt.
  * @param  newstate: new state of the specified hwdiv interrupts.
  *         this parameter can be: TRUE or FALSE.
  * @retval none
  */
void hwdiv_interrupt_enable(confirm_state new_state)
{
  if(new_state == FALSE)
  {
    HWDIV->ctrl_bit.intdis = TRUE;
  }
  else
  {
    HWDIV->ctrl_bit.intdis = FALSE;
  }
}

/**
  * @brief  enables or disables the hwdiv signed operation.
  * @param  newstate: new state of hwdiv signed operation.
  *         this parameter can be: TRUE or FALSE.
  * @retval none
  */
void hwdiv_signed_operate_enable(confirm_state new_state)
{
  HWDIV->ctrl_bit.sign = new_state;
}

/**
  * @brief  check whether the specified hwdiv flag is set or not.
  * @param  flag: specifies the flag to check.
  *         this parameter can be one of the following values:
  *         - HWDIV_DIV0F_FLAG:  hwdiv division by zero fault status flag
  * @retval SET or RESET
  */
flag_status hwdiv_flag_get(uint32_t flag)
{
  if(HWDIV->sts & flag)
  {
    return SET;
  }
  else
  {
    return RESET;
  }
}

/**
  * @brief  check whether the specified hwdiv interrupt flag is set or not.
  * @param  flag: specifies the flag to check.
  *         this parameter can be one of the following values:
  *         - HWDIV_DIV0F_FLAG:  hwdiv division by zero fault status flag
  * @retval SET or RESET
  */
flag_status hwdiv_interrupt_flag_get(uint32_t flag)
{
  if((HWDIV->sts & flag) && (HWDIV->ctrl_bit.intdis == 0))
  {
    return SET;
  }
  else
  {
    return RESET;
  }
}

/**
  * @brief  clear the hwdiv's pending flags.
  * @param  flag: specifies the flag to clear.
  *         this parameter can be any combination of the following values:
  *         - HWDIV_DIV0F_FLAG:
  * @retval none
  */
void hwdiv_flag_clear(uint32_t flag)
{
  if(flag == HWDIV_DIV0F_FLAG)
  {
    HWDIV->sts_bit.div0f = SET;
  }
}

/**
  * @}
  */

#endif

/**
  * @}
  */

/**
  * @}
  */
