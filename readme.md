# Custom Keymap for My Planck Keyboard

This is my custom keymap for my Planck rev4 keyboard. In most respects it is similar to the default layout, but it also takes advantage of some of the [QMK Firmware's](https://github.com/jackhumbert/qmk_firmware) more advanced features.

## Installation

To install:

1. Copy this directory to your .../qmk_firmware/keyboards/planck/keymaps/ directory. You should see several other keymaps in that folder. It's worth checking them out for ideas as you build your own custom layout.
2. In your terminal, in the `andykeymap` directory, run the command `make`. This should compile the keymap into a .hex file that can be flashed to your keyboad.

3. Navigate to the `planck` directory in the `qmk_firmware` folder ( `cd ../..` ).

3. Press and hold the reset button on your Planck for ~3 seconds.

4. `make KEYMAP=andykepmap dfu` should flash the keymap to your keyboard.

## Tap Dance

Tap Dance is one of QMK's cool features. Press a key once and it behaves normally, press it twice in rapid succession and it does something different. 

I use it for delimiters and symbols with hard to remember locations on the keymap. Press 'q' twice and I get a single quote. Press 'w' twice and I get a double quote, etc.

- q: '
- w: "

