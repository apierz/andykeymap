#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum {
  TD_G_TILD = 0,
  TD_ESC_CAPS,
  TD_Q_SINGLE,
  TD_W_DOUBLE,
  TD_E_NDASH,
  TD_R_UNDS,
  TD_T_LEFTB,
  TD_Y_RIGHTB,
  TD_U_LEFTR,
  TD_I_RIGHTR_I,
  TD_O_BSLASH,
  TD_P_PIPE,
  TD_COL_SEMI,
  TD_F_ASTR,
  TD_G_TAPDANCE,
};

void g_tilde(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code (KC_G);
    unregister_code (KC_G);
    break;
  case 2:
    register_code (KC_LSFT);
    register_code (KC_TILD);
    unregister_code (KC_TILD);
    unregister_code (KC_LSFT);
  }
}

void i_rightr_I(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code (KC_I);
    unregister_code (KC_I);
    break;
  case 2:
    register_code (KC_LSFT);
    register_code (KC_RCBR);
    unregister_code (KC_RBRC);
    unregister_code (KC_RBRC);
    break;
  case 3:
    register_code (KC_LSFT);
    register_code (KC_I);
    unregister_code (KC_I);
    unregister_code (KC_LSFT);
    break;
  }
}
  

qk_tap_dance_action_t tap_dance_actions[] = {
  //tap one for ESC, twice for caps lock
  
   [TD_G_TILD] = ACTION_TAP_DANCE_DOUBLE(KC_G, KC_TILD)
   ,[TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
   ,[TD_Q_SINGLE] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_QUOT)
   ,[TD_W_DOUBLE] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_DQUO)
   ,[TD_E_NDASH] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_MINS)
   ,[TD_R_UNDS] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_UNDS)
   ,[TD_T_LEFTB] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_LBRC)
   ,[TD_Y_RIGHTB] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_RBRC)
   ,[TD_U_LEFTR] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_LCBR)
   ,[TD_I_RIGHTR_I] = ACTION_TAP_DANCE_FN(i_rightr_i)
   ,[TD_O_BSLASH] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_BSLS)
   ,[TD_P_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_PIPE)
   ,[TD_COL_SEMI] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN)
   ,[TD_F_ASTR] = ACTION_TAP_DANCE_DOUBLE(KC_F, KC_PAST)
   ,[TD_G_TAPDANCE] = ACTION_TAP_DANCE_FN(g_tilde) 
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

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
[0] = {
  {TD(TD_ESC_CAPS), TD(TD_Q_SINGLE), TD(TD_W_DOUBLE), TD(TD_E_NDASH), TD(TD_R_UNDS), TD(TD_T_LEFTB), TD(TD_Y_RIGHTB), TD(TD_U_LEFTR), TD(TD_I_RIGHTR_I), TD(TD_O_BSLASH), TD(TD_P_PIPE), KC_BSPC },
  {CTL_T(KC_TAB),  KC_A,    KC_S,    KC_D,  TD(TD_F_ASTR),   TD(TD_G_TAPDANCE),    KC_H , KC_J,    KC_K,    KC_L, TD(TD_COL_SEMI), KC_ENT },
  {KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC },
  {ALL_T(KC_DEL), KC_LCTL, KC_LALT, KC_LGUI, M(1),    KC_SPC,  KC_SPC,   M(2),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |  F1  |  F2  |  F3  |  F4  |   7  |   8  |   9  |  /   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   $  |   %  |   ^  |  F5  |  F6  |  F7  |  F8  |   4  |   5  |   6  |  *   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   &  |   *  |   `  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |             |      |   0  |   =  |   .  |  +   |
 * `-----------------------------------------------------------------------------------'
 */
[1] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_7, KC_8, KC_9, KC_PSLS},
  {KC_DEL,  KC_DLR,  KC_PERC, KC_CIRC,  KC_F5,  KC_F6,   KC_F7,   KC_F8,   KC_4, KC_5, KC_6, KC_PAST},
  {_______, KC_AMPR, KC_PAST, KC_GRV,  KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_1, KC_2, KC_3, KC_PMNS},
  {RESET,   _______, _______, _______, KC_TRNS, _______, _______, _______, KC_0, KC_PEQL, KC_DOT, KC_PPLS}
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
