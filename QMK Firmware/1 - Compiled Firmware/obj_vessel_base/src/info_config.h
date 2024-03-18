// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
  88888888888 888      d8b                .d888 d8b 888               d8b
      888     888      Y8P               d88P"  Y8P 888               Y8P
      888     888                        888        888
      888     88888b.  888 .d8888b       888888 888 888  .d88b.       888 .d8888b
      888     888 "88b 888 88K           888    888 888 d8P  Y8b      888 88K
      888     888  888 888 "Y8888b.      888    888 888 88888888      888 "Y8888b.
      888     888  888 888      X88      888    888 888 Y8b.          888      X88
      888     888  888 888  88888P'      888    888 888  "Y8888       888  88888P'
                                                        888                 888
                                                        888                 888
                                                        888                 888
     .d88b.   .d88b.  88888b.   .d88b.  888d888 8888b.  888888 .d88b.   .d88888
    d88P"88b d8P  Y8b 888 "88b d8P  Y8b 888P"      "88b 888   d8P  Y8b d88" 888
    888  888 88888888 888  888 88888888 888    .d888888 888   88888888 888  888
    Y88b 888 Y8b.     888  888 Y8b.     888    888  888 Y88b. Y8b.     Y88b 888
     "Y88888  "Y8888  888  888  "Y8888  888    "Y888888  "Y888 "Y8888   "Y88888
         888
    Y8b d88P
     "Y88P"
*******************************************************************************/

#pragma once

#ifndef BOOTMAGIC_COLUMN
#    define BOOTMAGIC_COLUMN 12
#endif // BOOTMAGIC_COLUMN

#ifndef BOOTMAGIC_ROW
#    define BOOTMAGIC_ROW 0
#endif // BOOTMAGIC_ROW

#ifndef LOCKING_SUPPORT_ENABLE
#    define LOCKING_SUPPORT_ENABLE
#endif // LOCKING_SUPPORT_ENABLE

#ifndef DEBOUNCE
#    define DEBOUNCE 10
#endif // DEBOUNCE

#ifndef DIODE_DIRECTION
#    define DIODE_DIRECTION COL2ROW
#endif // DIODE_DIRECTION

#ifndef MATRIX_IO_DELAY
#    define MATRIX_IO_DELAY 30
#endif // MATRIX_IO_DELAY

#ifndef RGBLIGHT_HUE_STEP
#    define RGBLIGHT_HUE_STEP 8
#endif // RGBLIGHT_HUE_STEP

#ifndef RGBLIGHT_LED_COUNT
#    define RGBLIGHT_LED_COUNT 102
#endif // RGBLIGHT_LED_COUNT

#ifndef RGBLIGHT_LIMIT_VAL
#    define RGBLIGHT_LIMIT_VAL 60
#endif // RGBLIGHT_LIMIT_VAL

#ifndef RGBLIGHT_SAT_STEP
#    define RGBLIGHT_SAT_STEP 10
#endif // RGBLIGHT_SAT_STEP

#ifndef RGBLIGHT_VAL_STEP
#    define RGBLIGHT_VAL_STEP 10
#endif // RGBLIGHT_VAL_STEP

#ifndef RGBLIGHT_DEFAULT_ON
#    define RGBLIGHT_DEFAULT_ON false
#endif // RGBLIGHT_DEFAULT_ON

#ifndef RGBLIGHT_DEFAULT_VAL
#    define RGBLIGHT_DEFAULT_VAL 50
#endif // RGBLIGHT_DEFAULT_VAL

#ifndef USB_MAX_POWER_CONSUMPTION
#    define USB_MAX_POWER_CONSUMPTION 495
#endif // USB_MAX_POWER_CONSUMPTION

#ifndef USB_POLLING_INTERVAL_MS
#    define USB_POLLING_INTERVAL_MS 8
#endif // USB_POLLING_INTERVAL_MS

#ifndef USB_SUSPEND_WAKEUP_DELAY
#    define USB_SUSPEND_WAKEUP_DELAY 0
#endif // USB_SUSPEND_WAKEUP_DELAY

#ifndef WS2812_DI_PIN
#    define WS2812_DI_PIN A5
#endif // WS2812_DI_PIN

#ifndef DEVICE_VER
#    define DEVICE_VER 0x0100
#endif // DEVICE_VER

#ifndef MANUFACTURER
#    define MANUFACTURER "Ismael Coulibaly"
#endif // MANUFACTURER

#ifndef PRODUCT
#    define PRODUCT "VesselKB"
#endif // PRODUCT

#ifndef PRODUCT_ID
#    define PRODUCT_ID 0x0000
#endif // PRODUCT_ID

#ifndef VENDOR_ID
#    define VENDOR_ID 0xFEED
#endif // VENDOR_ID

#ifndef MATRIX_COLS
#    define MATRIX_COLS 17
#endif // MATRIX_COLS

#ifndef MATRIX_ROWS
#    define MATRIX_ROWS 7
#endif // MATRIX_ROWS

#ifndef MATRIX_COL_PINS
#    define MATRIX_COL_PINS { C10, C14, C11, B8, C1, B9, A1, A2, D2, C12, C6, C7, B12, B13, C9, A8, A9 }
#endif // MATRIX_COL_PINS

#ifndef MATRIX_ROW_PINS
#    define MATRIX_ROW_PINS { A6, B14, C8, B15, C4, A7, C5 }
#endif // MATRIX_ROW_PINS

#ifndef ENCODERS_PAD_A
#    define ENCODERS_PAD_A { A15 }
#endif // ENCODERS_PAD_A

#ifndef ENCODERS_PAD_B
#    define ENCODERS_PAD_B { B10 }
#endif // ENCODERS_PAD_B

#ifndef ENCODER_RESOLUTION
#    define ENCODER_RESOLUTION 4
#endif // ENCODER_RESOLUTION
