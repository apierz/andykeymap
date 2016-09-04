# Custom Keymap for My Planck Keyboard

This is my custom keymap for my Planck rev4 keyboard. It makes some signifigant changes to the default layout (mostly putting a numpad in the lower layer), but it also takes advantage of some of the [QMK Firmware's](https://github.com/jackhumbert/qmk_firmware) more advanced features.

~~~~ 
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | ESC  | Q / '| W / "| E / -| R / _| T / [| Y / ]| U / {| i/}/I| O / \| P / || Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Tb/Ctl|   A  |   S  |   D  | F / *| G / ~|   H  |   J  |   K  |   L  | ; / :|Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LS/ (|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RS/ ) |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |DL/HYP| Ctrl | Alt  | GUI  |Lower |    Space    | Lead | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |  F1  |  F2  |  F3  |  F4  |   7  |   8  |   9  |  /   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   $  |   %  |   ^  |  F5  |  F6  |  F7  |  F8  |   4  |   5  |   6  |  *   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   &  |   *  |   ~  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |             |      |   0  |   =  |   .  |  +   |
 * `-----------------------------------------------------------------------------------'
 */

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
~~~~
 

## Installation

To install:

1. Copy this directory to your .../qmk_firmware/keyboards/planck/keymaps/ directory. You should see several other keymaps in that folder. It's worth checking them out for ideas as you build your own custom layout.
2. In your terminal, in the `andykeymap` directory, run the command `make`. This should compile the keymap into a .hex file that can be flashed to your keyboad.

3. Navigate to the `planck` directory in the `qmk_firmware` folder ( `cd ../..` ).

3. Press and hold the reset button on your Planck for ~3 seconds.

4. `make KEYMAP=andykepmap dfu` should flash the keymap to your keyboard.

## Numpad

My `LOWER` key is set to toggle mode so pressing it once activates the Lower layer until it gets pressed again. This lets me use a modified numpad I have set up on the left side of the board

## Tap Dance

Tap Dance is one of QMK's cool features. Press a key once and it behaves normally, press it twice in rapid succession and it does something different. 

I use it for delimiters and symbols with hard to remember locations on the keymap. Press 'q' twice and I get a single quote. Press 'w' twice and I get a double quote, etc. If I press I three times it will output a `I`.

- q: '
- w: "
- e: -
- r: _
- t: [
- y: ]
- u: {
- i: }, I
- o: \
- p: |
- ;: :
- f: *
- g: ~

## Space Cadet

Space cadet has a simple premise but is hugely useful. If I hold left shift, it works like a normal shift key, if I press it and lift off with out pressing anything else it types a (. Right shift works the same way but I get a ) instead.

## Hidden Modifiers

Similar to Space Cadet, QMK lets you hide modifiers under certain keys. Currently, if I press and hold `TAB` it works like CTRL, which is very handy for TMUX and KWM shortcuts. If I hold my delete key it works like the `HYPER` modifier. Since `HYPER` is almost never used as a hotkey combo it works great for making global shortcuts. Currently I have `H-T` set to launch iTerm and `H-B` set to launch my browser.

