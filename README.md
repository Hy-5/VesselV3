# vessel

![RgbOFF](https://i.imgur.com/sOulPB4.jpg)

![RgbON](https://i.imgur.com/NzUIEAL.jpg)

*ISO-FR 75-ish keyboard with I2C OLED, RGB (WS2812B-2020) and rotary encoder*

* Keyboard Maintainer: [Hy-5 (Ismael Coulibaly)](https://github.com/Hy-5)
* Hardware Supported: *STM32F446RET6TR*


[WIP]

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb vessel -km base 2>&1 | ts '%Y-%m-%d %H:%M:%S

Flashing example for this keyboard:

    A - Initial flashing
        1 - Bridge "boot0 to 3v3_1" solder jumper to pull boot0 high
        2 - Desolder logic level shifter to keep boot1 pin low
        3 - Plug in the keyboard, it will boot in dfu bootloader mode
        4 - Use whatever program you prefer, QMK Toolbox, STM32 Programmer, STLink V2 etc.
    B - After initial flashing
        1 - Keep M12 button (row0, col11) pressed while plugging in the keyboard to launch in bootloader mode
        2 - Use QMK Toolbox for flashing

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 1 way:

* **Bootmagic reset**: Hold down the M12 key at (0,11) in the matrix and plug in the keyboard