#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


enum {
  TD_ESC_CAPS = 0,
  TD_Q_SINGLE,
  TD_W_DOUBLE,
  TD_E_NDASH,
  TD_R_UNDS,
  TD_T_LEFTB,
  TD_Y_RIGHTB,
  TD_U_LEFTR,
  TD_I_RIGHTR,
  TD_O_BSLASH,
  TD_P_PIPE,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  //tap one for ESC, twice for caps lock
   [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
   ,[TD_Q_SINGLE] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_QUOT)
   ,[TD_W_DOUBLE] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_DQUO)
   ,[TD_E_NDASH] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_MINS)
   ,[TD_R_UNDS] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_UNDS)
   ,[TD_T_LEFTB] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_LBRC)
   ,[TD_Y_RIGHTB] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_RBRC)
   ,[TD_U_LEFTR] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_LCBR)
   ,[TD_I_RIGHTR] = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_RCBR)
   ,[TD_O_BSLASH] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_BSLS)
   ,[TD_P_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_PIPE)
  
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | ESC  | Q / '| W / "| E / -| R / _| T / [| Y / ]| U / {| I / }| O / \| P / || Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | RS/ (|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |LS/ ) |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | DEL  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[0] = {
  {TD(TD_ESC_CAPS), TD(TD_Q_SINGLE), TD(TD_W_DOUBLE), TD(TD_E_NDASH), TD(TD_R_UNDS), TD(TD_T_LEFTB), TD(TD_Y_RIGHTB), TD(TD_U_LEFTR), TD(TD_I_RIGHTR), TD(TD_O_BSLASH), TD(TD_P_PIPE), KC_BSPC },
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC },
  {KC_HYPR, KC_LCTL, KC_LALT, KC_LGUI, M(1),    KC_SPC,  KC_SPC,   M(2),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[1] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______},
  {RESET,   _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

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
[2] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______},
  {RESET,   _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},


};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 1:
      if (record->event.pressed) {
        layer_on(1);
      } else {
        layer_off(1);
      }
      break;
    case 2:
      if (record->event.pressed) {
        layer_on(2);
      } else {
        layer_off(2);
      }
      break;
  }
  return MACRO_NONE;
};
