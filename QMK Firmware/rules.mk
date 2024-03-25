# This file intentionally left blank

# ---MCU---
MCU = STM32F446

# ---Bootloader selection---
BOOTLOADER = stm32-dfu
BOOTMAGIC_ENABLE = yes

# ---Basics---
#DEBOUNCE_TYPE = sym_eager_pk
DEBOUNCE_TYPE = sym_defer_pk
PROGRAMMABLE_BUTTON_ENABLE = yes
LTO_ENABLE = yes
NKRO_ENABLE = yes
EXTRAKEY_ENABLE = yes
# ---Below Option, if set to "vendor" would save data to internal EEPROM when available, if not, acts as "transient" (fake eeprom discarded when turned off). STM32F446 only works on transient as it does not have EEPROM---
EEPROM_DRIVER = transient
# ---Below option commented out because only useful if want to turn on nkro when pressing a button (double check)---
NK_ON = yes

# ---OLED---
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
OLED_TRANSPORT = i2c

# ---Rotary Encoder---
ENCODER_ENABLE = yes

# ---RGB---
RGBLIGHT_ENABLE = yes
RGBLIGHT_ANIMATIONS  = yes
WS2812_DRIVER = bitbang

# --- MISC ---
# VIA compatibility
# VIA_ENABLE = yes


# ---Debugging solutions---
# CONSOLE_ENABLE = yes
# DEBUG_ENABLE = yes