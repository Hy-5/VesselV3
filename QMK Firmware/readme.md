# vessel

![RgbOFF](https://i.imgur.com/sOulPB4.jpg)

![RgbON](https://i.imgur.com/NzUIEAL.jpg)

*ISO-FR 75-ish keyboard with I2C OLED, RGB (WS2812B-2020) and rotary encoder*

* Keyboard Maintainer: [Ismael Coulibaly](https://github.com/Hy-5)
* Hardware Supported: *STM32F446RET6TR*


[WIP]

Make example for this keyboard (after setting up your build environment):

    make vessel:default

Flashing example for this keyboard:

    make vessel:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available