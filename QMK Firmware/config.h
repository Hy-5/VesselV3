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
#define MATRIX_IO_DELAY 10
#define LOCKING_SUPPORT_ENABLE
#define IS_COMMAND() (get_mods() == MOD_MASK_SHIFT)
#define USB_MAX_POWER_CONSUMPTION 495
#define USB_POLLING_INTERVAL_MS 2
#define USB_SUSPEND_WAKEUP_DELAY 0
//#define NO_USB_STARTUP_CHECK
#define F_SCL 400000L
#define DEBOUNCE 15
#define TAPPING_TERM 200

// Define direct key switches (not in matrix)
// Rotary encoder push button
#define ENCODERS_PAD_A { A15 }
#define ENCODERS_PAD_B { B10 }
#define KC_ENCODER_PUSH B2
#define ENCODER_RESOLUTION 4
// Boot0 & NRST (for DFU) (Not useful anymore since row0/col12 pressed before plugging in launches bootmagic and goes to DFU bootloader mode)
// #define KC_BOOT0 B4
// #define KC_NRST B3


#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 12


// RGB Config
#define WS2812_DRIVER bitbang
#define WS2812_DI_PIN A5
#define RGBLIGHT RGBLIGHT_WS2812
#define RGBLIGHT_LED_COUNT 102
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 10
#define RGBLIGHT_VAL_STEP 10
// #define RGBLIGHT_DEFAULT_MODE 6
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_DEFAULT_VAL 100
#define RGBLIGHT_DEFAULT_ON true

// RGB Modes
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_MODE_STATIC_LIGHT
// #define RGBLIGHT_MODE_BREATHING
// #define RGBLIGHT_MODE_SNAKE
// #define RGBLIGHT_MODE_KNIGHT
// #define RGBLIGHT_MODE_CHRISTMAS
// #define RGBLIGHT_MODE_STATIC_GRADIENT
// #define RGBLIGHT_MODE_ALTERNATING
// #define RGBLIGHT_MODE_TWINKLE

// Updated timings from WS2812B 2020 datasheet
#define WS2812_TIMING 1100 // in nano-seconds. Total time for each bit (equals to TH+TL). TLs (T0L and T1L are not set here as they are calculated automatically by QMK. Eg: Timing=T0H+T1H or T1L+T0L)
#define WS2812_T0H 300 // in nano-seconds. Time driven high for logical 0
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
// #define OLED_FADE_OUT
// #define OLED_FADE_OUT_INTERVAL 5
// #define OLED_SCROLL_TIMEOUT 90000
// #define OLED_TIMEOUT 180000



//Set Transient Eeprom to unsigned 16bit
#define TRANSIENT_EEPROM_SIZE ((1U<<16)-1)