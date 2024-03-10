// Copyright 2024 Ismael Coulibaly (@Hy-5)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT

#define MATRIX_IO_DELAY 30
#define LOCKING_SUPPORT_ENABLE
#define IS_COMMAND() (get_mods() == MOD_MASK_SHIFT)
#define USB_MAX_POWER_CONSUMPTION 495
#define USB_POLLING_INTERVAL_MS 8
#define USB_SUSPEND_WAKEUP_DELAY 0
#define F_SCL 400000L
#define DEBOUNCE 10
// #define BACKLIGHT_PIN A5

// Define direct key switches (not in matrix)
// Rotary encoder push button
#define KC_ENCODER_PUSH B2
// Boot0 & NRST (for DFU)
// #define KC_BOOT0 B4
// #define KC_NRST B3


#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 12


// RGB Config

//#define DRIVER_LED_TOTAL 102
//#define RGB_MATRIX_LED_COUNT 102

#define WS2812_DRIVER bitbang
#define WS2812_DI_PIN A5
#define RGBLIGHT RGBLIGHT_WS2812
//#define RGBLED_NUM 1
#define RGBLIGHT_LED_COUNT 102
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#define RGBLIGHT_LIMIT_VAL 60
// #define WS2812_EXTERNAL_PULLUP

#define RGBLIGHT_DEFAULT_VAL 40
#define RGBLIGHT_DEFAULT_ON true

// Updated timings from WS2812B 2020 datasheet
#define WS2812_TIMING 1250 // in nano-seconds. Total time for each bit (equals to TH+TL). TLs (T0L and T1L are not set here as they are calculated automatically by QMK. Eg: Timing=T0H+T1H or T1L+T0L)
#define WS2812_T0H 450 // in nano-seconds. Time driven high for logical 0
#define WS2812_T1H 800 // in nano-seconds. Time driven high for logical 1
#define WS2812_TRST_US 300 // in micro-seconds. time driven (low?) for reset. Should be above 280us
#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_GRB
// Other timings (T0L and T1L) derived automatically by QMK, no need to set them


// OLED Config
#define OLED_DISPLAY_128X64
#define OLED_DISPLAY_ADDRESS 0x3D
#define OLED_IC OLED_IC_SSD1306
#define OLED_MATRIX_SIZE 1024
#define OLED_BRIGHTNESS 128
#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 5
#define OLED_SCROLL_TIMEOUT 90000
#define OLED_TIMEOUT 180000



//Set Transient Eeprom to unsigned 16bit
#define TRANSIENT_EEPROM_SIZE ((1U<<16)-1)