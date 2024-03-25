// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "print.h"
#include "timer.h"


/***** rgblight_mode(mode)/rgblight_mode_noeeprom(mode) ****

SHOULD WORK with new name modes but for some reason won't compile unless I give it the number instead. Last time tested QMK 0.23.5

|-----------------|-----------------------------------|
| old mode number | new mode name                     |
|-----------------|-----------------------------------|
|        1        | RGBLIGHT_MODE_STATIC_LIGHT        |
|        2        | RGBLIGHT_MODE_BREATHING           |
|        3        | RGBLIGHT_MODE_BREATHING + 1       |
|        4        | RGBLIGHT_MODE_BREATHING + 2       |
|        5        | RGBLIGHT_MODE_BREATHING + 3       |
|        6        | RGBLIGHT_MODE_RAINBOW_MOOD        |
|        7        | RGBLIGHT_MODE_RAINBOW_MOOD + 1    |
|        8        | RGBLIGHT_MODE_RAINBOW_MOOD + 2    |
|        9        | RGBLIGHT_MODE_RAINBOW_SWIRL       |
|       10        | RGBLIGHT_MODE_RAINBOW_SWIRL + 1   |
|       11        | RGBLIGHT_MODE_RAINBOW_SWIRL + 2   |
|       12        | RGBLIGHT_MODE_RAINBOW_SWIRL + 3   |
|       13        | RGBLIGHT_MODE_RAINBOW_SWIRL + 4   |
|       14        | RGBLIGHT_MODE_RAINBOW_SWIRL + 5   |
|       15        | RGBLIGHT_MODE_SNAKE               |
|       16        | RGBLIGHT_MODE_SNAKE + 1           |
|       17        | RGBLIGHT_MODE_SNAKE + 2           |
|       18        | RGBLIGHT_MODE_SNAKE + 3           |
|       19        | RGBLIGHT_MODE_SNAKE + 4           |
|       20        | RGBLIGHT_MODE_SNAKE + 5           |
|       21        | RGBLIGHT_MODE_KNIGHT              |
|       22        | RGBLIGHT_MODE_KNIGHT + 1          |
|       23        | RGBLIGHT_MODE_KNIGHT + 2          |
|       24        | RGBLIGHT_MODE_CHRISTMAS           |
|       25        | RGBLIGHT_MODE_STATIC_GRADIENT     |
|       26        | RGBLIGHT_MODE_STATIC_GRADIENT + 1 |
|       27        | RGBLIGHT_MODE_STATIC_GRADIENT + 2 |
|       28        | RGBLIGHT_MODE_STATIC_GRADIENT + 3 |
|       29        | RGBLIGHT_MODE_STATIC_GRADIENT + 4 |
|       30        | RGBLIGHT_MODE_STATIC_GRADIENT + 5 |
|       31        | RGBLIGHT_MODE_STATIC_GRADIENT + 6 |
|       32        | RGBLIGHT_MODE_STATIC_GRADIENT + 7 |
|       33        | RGBLIGHT_MODE_STATIC_GRADIENT + 8 |
|       34        | RGBLIGHT_MODE_STATIC_GRADIENT + 9 |
|       35        | RGBLIGHT_MODE_RGB_TEST            |
|       36        | RGBLIGHT_MODE_ALTERNATING         |
|       37        | RGBLIGHT_MODE_TWINKLE             |
|       38        | RGBLIGHT_MODE_TWINKLE + 1         |
|       39        | RGBLIGHT_MODE_TWINKLE + 2         |
|       40        | RGBLIGHT_MODE_TWINKLE + 3         |
|       41        | RGBLIGHT_MODE_TWINKLE + 4         |
|       42        | RGBLIGHT_MODE_TWINKLE + 5         |
|-----------------|-----------------------------------|
 *****/
 
 static uint32_t keyboard_idle_timer = 0;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     
     /*
         *┌───┬───┐ ┌───┬───┐ ┌───┬───┐ ┌───┬───┐ ┌───┬───┐ ┌───┬───┐ ┌───┬───┬───┐
         *│M1 │M2 │ │M3 │M4 │ │M5 │M6 │ │M7 │M8 │ │M9 │M10│ │M11│M12│ │Pre│Pla│Nex│
         *└───┴───┘ └───┴───┘ └───┴───┘ └───┴───┘ └───┴───┘ └───┴───┘ └───┴───┴───┘
         *┌───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
         *│Esc│ │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │PSc│OC │Lay│
         *└───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
         *┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐   ┌───┬───┐
         *│ ² │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ° │ + │ Backsp│   │Hom│End│
         *├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤   ├───┼───┤
         *│ Tab │ A │ Z │ E │ R │ T │ Y │ U │ I │ O │ P │ ¨ │ £ │     │   │Ins│PUp│
         *├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐ Ent│   ├───┼───┤
         *│ Caps │ Q │ S │ D │ F │ G │ H │ J │ K │ L │ M │ % │ µ │    │   │Del│PDn│             
         *├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┤   └───┼───┤   
         *│Shft│ > │ W │ X │ C │ V │ B │ N │ ? │ . │ / │ § │Shift │ ↑ │       │T22│
         *├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┐ ┌─┴───┤
         *│Ctrl│GUI │Alt │          Space         │ Alt│Menu│ │ ← │ ↓ │ → │ │(Enc)│
         *└────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘ └─────┘
         *
     */
     
     
        [0] = LAYOUT_all(
        KC_F13,           KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_F21,   KC_F22,   KC_F23,  KC_F24,     KC_MPRV, KC_MPLY, KC_MNXT,
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_PSCR, PB_1, PB_2,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_HOME, KC_END,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_ENT,     KC_INS,  KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS,             KC_DEL,  KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  KC_UP,              PB_3,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_APP,  KC_LEFT, KC_DOWN, KC_RGHT
    )
};


#if defined(ENCODER_MAP_ENABLE)
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            uprintf("Encoder turned clockwise\n");
            tap_code(KC_VOLU); // temporary action for testing
        } else {
            uprintf("Encoder turned counter-clockwise\n");
            tap_code(KC_VOLD); // temporary action for testing
        }
    }
    return true;
}
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    if (!is_oled_on()) return false; // exit early if the OLED is off
    //Drawing position set to grid start
    oled_set_cursor(0,1);
    
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("No detectable layer\n"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    
    return false;
}
#endif

void matrix_scan_user(void) {
    static uint8_t encoder_button_state = 0;
    if (readPin(KC_ENCODER_PUSH) == 0) {
        if (encoder_button_state == 0) {
            encoder_button_state = 1;
            tap_code(KC_MPLY); // temporary action for testing
            uprintf("Encoder button pressed\n");
        }
    } else if (encoder_button_state == 1) {
        encoder_button_state = 0;
        uprintf("Encoder button released\n");
    }
    
    //Turn RGB off when not in use
    if (timer_elapsed32(keyboard_idle_timer) > 300000) { // 5 minutes
        if (rgblight_is_enabled()) {
            rgblight_disable();
        }
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {    
      // Prints matrix position and status key pressed when console is enabled
    #ifdef CONSOLE_ENABLE
        uprintf("KL: kc: 0x%04X, row: %2u, col: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.row, record->event.key.col, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    #endif
    
    // Turn RGB on when a key is pressed
    if (record->event.pressed) {
        keyboard_idle_timer = timer_read32();
        if (!rgblight_is_enabled()) {
            rgblight_enable();
        }
    }
    return true;

    return true;
}

void suspend_power_down_user(void) {
    // TODO when host computer is off
    oled_off();
    rgblight_disable();
}

void suspend_wakeup_init_user(void) {
    // TODO when host computer is back on
    oled_on();
    rgblight_enable();
}




void keyboard_post_init_user(void) {
    // Delay for OLED power stabilization (Otherwise OLED won't start on cold boot (when unplugged and plugged back in) and will only work after being flashed and after pc reboot)
    wait_ms(100);
    // Enable NKRO from boot
    keymap_config.nkro = 1;
    // RGB starting state:
    rgblight_enable();
    rgblight_mode(6); // Sets the mode to rainbow
    // rgblight_sethsv(HSV_WHITE); // Sets the color to static white; To replace later
    
    // Initialize OLED
    oled_init(OLED_ROTATION_0); // OLED_ROTATION_180 if flipping the display
    oled_on();
}
