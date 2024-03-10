#pragma once

#include_next <mcuconf.h>

#ifndef MCUCONF_H
#define MCUCONF_H
#endif /* MCUCONF_H */

#define STM32F4xx_MCUCONF
#define STM32F446_MCUCONF

//Setting 48MHz PLLM as main clock. Otherwise defaults to PLLI2S
#ifdef STM32_CK48MSEL
#undef STM32_CK48MSEL
#endif
#define STM32_CK48MSEL STM32_CK48MSEL_PLL


//Setting 25MHz clock (default is 16MHz)
#ifdef STM32_HSECLK
#undef STM32_HSECLK
#endif
#define STM32_HSECLK 25000000

//Values obtained from STM32CubeMX to match 25Mhz. Could be removed if using default 16MHz external oscillator. Undef all default values
#ifdef STM32_PLLSRC
#undef STM32_PLLSRC
#endif
#define STM32_PLLSRC STM32_PLLSRC_HSE

#ifdef STM32_PLLM_VALUE
#undef STM32_PLLM_VALUE
#endif
#define STM32_PLLM_VALUE 15

#ifdef STM32_PLLN_VALUE
#undef STM32_PLLN_VALUE
#endif
#define STM32_PLLN_VALUE 144

#ifdef STM32_PLLP_VALUE
#undef STM32_PLLP_VALUE
#endif
#define STM32_PLLP_VALUE 2

#ifdef STM32_PLLQ_VALUE
#undef STM32_PLLQ_VALUE
#endif
#define STM32_PLLQ_VALUE 5

#ifdef STM32_HPRE
#undef STM32_HPRE
#endif
#define STM32_HPRE STM32_HPRE_DIV1

#ifdef STM32_PPRE1
#undef STM32_PPRE1
#endif
#define STM32_PPRE1 STM32_PPRE1_DIV4

#ifdef STM32_PPRE2
#undef STM32_PPRE2
#endif
#define STM32_PPRE2 STM32_PPRE2_DIV2

#ifdef STM32_PLLI2SN_VALUE
#undef STM32_PLLI2SN_VALUE
#endif
#define STM32_PLLI2SN_VALUE                 192


#ifdef STM32_PLLI2SM_VALUE
#undef STM32_PLLI2SM_VALUE
#endif
#define STM32_PLLI2SM_VALUE                 16


#ifdef STM32_PLLI2SR_VALUE
#undef STM32_PLLI2SR_VALUE
#endif
#define STM32_PLLI2SR_VALUE                 2


#ifdef STM32_PLLI2SP_VALUE
#undef STM32_PLLI2SP_VALUE
#endif
#define STM32_PLLI2SP_VALUE                 2


#ifdef STM32_PLLI2SQ_VALUE
#undef STM32_PLLI2SQ_VALUE
#endif
#define STM32_PLLI2SQ_VALUE                 2


#ifdef STM32_PLLSAIN_VALUE
#undef STM32_PLLSAIN_VALUE
#endif
#define STM32_PLLSAIN_VALUE                 192


#ifdef STM32_PLLSAIM_VALUE
#undef STM32_PLLSAIM_VALUE
#endif
#define STM32_PLLSAIM_VALUE                 16


#ifdef STM32_PLLSAIP_VALUE
#undef STM32_PLLSAIP_VALUE
#endif
#define STM32_PLLSAIP_VALUE                 2


#ifdef STM32_PLLSAIQ_VALUE
#undef STM32_PLLSAIQ_VALUE
#endif
#define STM32_PLLSAIQ_VALUE                 2


#define STM32_USB_USE_OTG1                  TRUE
#define STM32_USB_USE_OTG2                  FALSE
#define STM32_USB_OTG1_IRQ_PRIORITY         14
#define STM32_USB_OTG2_IRQ_PRIORITY         14
#define STM32_USB_OTG1_RX_FIFO_SIZE         512
#define STM32_USB_OTG2_RX_FIFO_SIZE         1024
#define STM32_USB_HOST_WAKEUP_DURATION      2


//Oled
#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE

//RGB
#undef STM32_PWM_USE_TIM2
#define STM32_PWM_USE_TIM2 TRUE
