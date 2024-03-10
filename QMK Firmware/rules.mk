# This file intentionally left blank

#MCU
MCU = STM32F446

# Bootloader selection
BOOTLOADER = stm32-dfu
BOOTMAGIC_ENABLE = yes

PROGRAMMABLE_BUTTON_ENABLE = yes
CONSOLE_ENABLE = yes
#DEBUG_ENABLE = yes


#VIA compatibility
#VIA_ENABLE = yes
LTO_ENABLE = yes
# NKRO_ENABLE = yes
NK_ON = yes
EXTRAKEY_ENABLE = yes
RGBLIGHT_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
OLED_TRANSPORT = i2c
EEPROM_DRIVER = transient
WS2812_DRIVER_REQUIRED = yes
WS2812_DRIVER = bitbang