#include QMK_KEYBOARD_H
#include "ssgelm.h"

bool fnIsLocked = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
      case CLIP:
        if (record->event.pressed) {
          SEND_STRING(SS_LCTRL(SS_LALT("v")));
        }
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
  return true;
};
