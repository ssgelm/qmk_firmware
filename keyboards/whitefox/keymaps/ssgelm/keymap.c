/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

enum custom_keycodes {
  CLIP = SAFE_RANGE
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,---------------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| Backsp|~ `|
     * |---------------------------------------------------------------|
     * | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del|
     * |---------------------------------------------------------------|
     * |Ctrl/E|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Enter  |PgU|
     * |---------------------------------------------------------------|
     * | Shift |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| Shift |Up |PgD|
     * |---------------------------------------------------------------|
     * | FN |Alt |Gui |         Space         |Gui |Alt |  |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [0] = LAYOUT( \
        KC_GESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,KC_NO,KC_BSPC,KC_GRV, \
        KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,   KC_BSLS,  KC_DEL, \
        CTL_T(KC_ESC), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_NO,  KC_ENT,    KC_PGUP,\
        KC_LSFT, KC_NO,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,    KC_RSFT, KC_UP,  KC_PGDN,\
        MO(1), KC_LALT,KC_LGUI,                    LT(1, KC_SPC),              KC_RGUI,KC_RALT,KC_NO,       KC_LEFT,KC_DOWN,KC_RGHT \
    ),
    /* Layer 1: FN Layer
     * ,---------------------------------------------------------------.
     * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       |   |
     * |---------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |
     * |---------------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |   |
     * |---------------------------------------------------------------|
     * |       |   |   |   |   |   |   |   |   |   |   |       |pup|   |
     * |---------------------------------------------------------------|
     * |    |    |    |                       |    |    |  |hom|pdn|end|
     * `---------------------------------------------------------------'
     */
    [1] = LAYOUT( \
        KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,_______,KC_MPLY,\
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        KC_MUTE,\
        _______,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,_______,_______,_______,_______,        KC_VOLU,\
        MO(2),  _______,_______,_______,_______,   CLIP,_______,_______,_______,_______,_______,_______,_______,        KC_PGUP,KC_VOLD,\
        _______,_______,_______,                        _______,                _______,_______,_______,        KC_HOME,KC_PGDN,KC_END  \
    ),
    /* Layer 2: Extra FN Layer
     * ,---------------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |   |
     * |---------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |B0 |
     * |---------------------------------------------------------------|
     * |      |   |   |   |FLS|   |   |   |   |   |   |   |        |B+ |
     * |---------------------------------------------------------------|
     * |       |   |   |   |   |   |   |   |   |   |   |       |   |B- |
     * |---------------------------------------------------------------|
     * |    |    |    |                       |    |    |  |   |   |   |
     * `---------------------------------------------------------------'
     */
    [2] = LAYOUT( \
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, _______,_______,BL_ON  ,\
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        BL_OFF ,\
        _______,_______,_______,_______,  RESET,_______,_______,_______,_______,_______,_______,_______,_______,_______,         BL_INC,\
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______, BL_DEC,\
        _______,_______,_______,                        _______,                _______,_______,_______,        _______,_______,_______ \
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case CLIP:
        SEND_STRING(SS_LCTRL(SS_LALT("v")));
        return false;
    }
  }
  return true;
};
