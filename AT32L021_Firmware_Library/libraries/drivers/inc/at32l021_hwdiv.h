/**
  **************************************************************************
  * @file     at32l021_hwdiv.h
  * @brief    at32l021 hwdiv header file
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
#ifndef __AT32L021_HWDIV_H
#define __AT32L021_HWDIV_H

#ifdef __cplusplus
extern "C" {
#endif


/* includes ------------------------------------------------------------------*/
#include "at32l021.h"

/** @addtogroup AT32L021_periph_driver
  * @{
  */

/** @addtogroup HWDIV
  * @{
  */

/** @defgroup HWDIV_flags_definition
  * @brief hwdiv flag
  * @{
  */

#define HWDIV_DIV0F_FLAG                 ((uint32_t)0x00000001) /*!< hwdiv division by zero fault status flag */

/**
  * @}
  */
  
/** @defgroup HWDIV_exported_types
  * @{
  */

/**
  * @brief type define hwdiv register all
  */
typedef struct
{
  /**
    * @brief hwdiv dividend register, offset:0x00
    */
  union
  {
    __IO uint32_t dvdd;
    struct
    {
      __IO uint32_t dvdd                 : 32; /* [31:0] */
    } dvdd_bit;
  };

  /**
    * @brief hwdiv divisor register, offset:0x04
    */
  union
  {
    __IO uint32_t dvsr;
    struct
    {
      __IO uint32_t dvsr                 : 32; /* [31:0] */
    } dvsr_bit;
  };

  /**
    * @brief hwdiv quotient register, offset:0x08
    */
  union
  {
    __IO uint32_t quot;
    struct
    {
      __IO uint32_t quot                 : 32;/* [31:0] */
    } quot_bit;
  };

  /**
    * @brief hwdiv remainder register, offset:0x0C
    */
  union
  {
    __IO uint32_t remd;
    struct
    {
      __IO uint32_t remd                 : 1; /* [31:0] */
    } remd_bit;
  };

  /**
    * @brief hwdiv ctrl register, offset:0x10
    */
  union
  {
    __IO uint32_t ctrl;
    struct
    {
      __IO uint32_t reserved1            : 1; /* [0] */
      __IO uint32_t sign                 : 1; /* [1] */
      __IO uint32_t intdis               : 1; /* [2] */
      __IO uint32_t reserved2            : 29;/* [31:3] */
    } ctrl_bit;
  };

  /**
    * @brief hwdiv sts register, offset:0x14
    */
  union
  {
    __IO uint32_t sts;
    struct
    {
      __IO uint32_t div0f                : 1; /* [0] */
      __IO uint32_t reserved             : 31;/* [31:1] */
    } sts_bit;
  };
} hwdiv_type;

/**
  * @}
  */

#define HWDIV                            ((hwdiv_type *) HWDIV_BASE)

/** @defgroup HWDIV_exported_functions
  * @{
  */

void hwdiv_dividend_set(uint32_t value);
void hwdiv_divisor_set(uint32_t value);
uint32_t hwdiv_quotient_get(void);
uint32_t hwdiv_remainder_get(void);
void hwdiv_interrupt_enable(confirm_state new_state);
void hwdiv_signed_operate_enable(confirm_state new_state);
flag_status hwdiv_flag_get(uint32_t flag);
flag_status hwdiv_interrupt_flag_get(uint32_t flag);
void hwdiv_flag_clear(uint32_t flag);

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
