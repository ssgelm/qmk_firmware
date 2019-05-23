#include QMK_KEYBOARD_H

#define _______ KC_TRNS

bool fnIsLocked = false;

enum custom_keycodes {
  CLIP = SAFE_RANGE,
  FN_KEY,
  FN_LOCK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |Ctrl/E |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|  Shift   |
   * |-----------------------------------------------------------|
   * |FN  |Opt |Cmd |        Space           |Cmd |Opt |Fn  |Ctrl|
   * `-----------------------------------------------------------'
   */
	[0] = LAYOUT_60_ansi(
      KC_GESC,      KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
      KC_TAB,        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT,         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
      FN_KEY, KC_LALT, KC_LGUI,             LT(1,KC_SPC),                KC_RGUI, KC_RALT, FN_KEY, KC_RCTL
    ),
  /* Keymap 1: Function Layer
   * ,-----------------------------------------------------------.
   * |~ ` |F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Del    |
   * |-----------------------------------------------------------|
   * |     |R_T|R_M|RH+|RH-|RS+|RS-|RV+|RV-|   |PrS|SLc|Pau|RESET|
   * |-----------------------------------------------------------|
   * |       |Mut|Vo-|Vo+|Ply|PgU|<- |Dwn|Up | ->|Hom|Pgu|       |
   * |-----------------------------------------------------------|
   * |        |   |   |   |CLP|PgD|   |   |Del|End|PgD|          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
	[1] = LAYOUT_60_ansi(
      KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
      _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR, KC_SLCK, KC_PAUS, RESET,
      _______,  KC__MUTE, KC__VOLDOWN, KC__VOLUP, KC_MPLY, KC_PGUP, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_HOME, KC_PGUP, _______,
      _______,   _______, _______, _______,    CLIP, KC_PGDN, _______, _______, KC_DEL, KC_END, KC_PGDN, _______,
      _______, _______, _______,               FN_LOCK,                                _______, _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case CLIP:
        SEND_STRING(SS_LCTRL(SS_LALT("v")));
        return false;
      case FN_KEY:
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
        return false;
    }
  }
  return true;
};
