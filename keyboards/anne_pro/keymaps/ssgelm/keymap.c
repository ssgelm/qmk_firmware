/* Copyright 2019 Michiel Visser
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

bool fnIsLocked = false;

/* TODO: figure out how to separa anne_pro.h
 *
 * enum custom_keycodes {
 *   CLIP = SAFE_RANGE,
 *   FN_KEY,
 *   FN_LOCK,
 * };
 */

/* Default Anne Pro layout, macOS style with LALT and LWIN switched */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
      KC_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
      KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
      LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
      KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,
      MO(1),          KC_LALT, KC_LGUI,               LT(1,KC_SPC),                                    KC_RGUI, KC_LALT, MO(2),   KC_RCTL
  ),
  [1] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_DEL,
      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, APL_RGB, APL_RAT, APL_BRT, APL_MOD, KC_UP,   KC_SLCK, KC_PAUS, KC_HOME, KC_END,  KC_PSCR,
      XXXXXXX, KC__MUTE, KC__VOLDOWN, KC__VOLUP, KC_MPLY, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, KC_PGDN,          XXXXXXX,
      _______, XXXXXXX, XXXXXXX, XXXXXXX,   CLIP, TG(3),   XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  KC_DEL,                    _______,
      _______, _______, _______,                   XXXXXXX,                                     _______, _______, _______, _______
  ),
  [2] = LAYOUT(
      RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, A(KC_LEFT), A(S(KC_DOWN)), A(S(KC_UP)), A(KC_RGHT), XXXXXXX, XXXXXXX,          XXXXXXX,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______,
      _______, _______, _______,                   XXXXXXX,                                     _______, _______, _______, _______
  ),
  [3] = LAYOUT(
      TG(3),   APB_HC1, APB_HC2, APB_HC3, APB_HC4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, APB_LGC, APB_OFF, APB_ON,  XXXXXXX,
      XXXXXXX, APB_HS1, APB_HS2, APB_HS3, APB_HS4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, APB_HD1, APB_HD2, APB_HD3, APB_HD4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,
      APB_HLQ, XXXXXXX, XXXXXXX,                   XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case CLIP:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LALT("v")));
      }
      return false;
    /*case FN_KEY:
      if (record->event.pressed) {
        layer_on(1);
        fnIsLocked = false;
      } else {
        if (!fnIsLocked) {
          layer_off(1);
        }
      }
      return false;
    case FN_LOCK:
      if (record->event.pressed) {
        fnIsLocked = !fnIsLocked;

        if (!fnIsLocked) {
          layer_off(1);
        }
      }
      return false;*/
  }
  return true;
};
