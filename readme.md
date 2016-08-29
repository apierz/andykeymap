# Keymap for Planck Keyboard

This is my custom keymap for my Planck keyboard. Right now it only has a few key swaps from the default layout.

To install:

1. Copy this directory to your .../qmk_firmware/keyboards/planck/keymaps/ directory
2. In the planck directory, in your terminal,  `make`. This should compile your keymaps into .hex files that can be flashed to your keyboad.

3. Press and hold the reset button on your Planck for ~3 seconds.

4. ``make KEYMAP=andykepmap dfu` should flash the keymap to your keyboard.
