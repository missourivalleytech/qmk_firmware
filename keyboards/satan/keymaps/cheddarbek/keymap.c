#include "satan.h"


// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _MV 2

#define ____ KC_TRNS

//These keycodes act as function keys. Tap tap for space/backspace, hold for NAV layer
#define KC_SPBL LT(_FL,KC_SPC)

//These keycodes are macros for Windows-style home and end functionality on a Mac.
#define KC_MHME LGUI(KC_LEFT)
#define KC_MEND LGUI(KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Delete |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| BSPC|
   * |-----------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Alt |Gui |      Space/FN         |Gui |Alt |FN  |Ctrl |
   * `-----------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  F(0),    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_DEL, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSPC, \
  KC_LCTL, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,         KC_RSFT, \
  KC_LCTL, KC_LALT,KC_LGUI,                KC_SPBL,                               KC_LGUI,KC_LALT, MO(_FL),MO(_MV)),

  /* Keymap _FL: Function Layer
  * ,-----------------------------------------------------------.
  * |GRV  |MUTE|VOLD|VOLU|MPRV|MPLY|MNXT| 7| 8| 9| 0| -| +  |Bsp|
  * |-----------------------------------------------------------|
  * |     |   | UP|   |HOME|   |   |  4|  5|  6|  P|  *|  ]|  \ |
  * |-----------------------------------------------------------|
  * |Caps |LEFT|DOWN|RIGHT|END|   |  1|  2|  3|  L|  /|  '|     |
  * |-----------------------------------------------------------|
  * |        |    |   |   |   |   |   |  0|  ,|  .|  /|         |
  * |-----------------------------------------------------------'
  * |Ctrl|Gui |Alt |         Space         |Gui |Alt |GUI |F13  |
  * `-----------------------------------------------------------'
  */
[_FL] = KEYMAP_ANSI(
  KC_GRV,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_7, KC_8, KC_9,  KC_0,   KC_BSPC, ____, ____, \
  ____,    ____,    KC_UP,   ____,    KC_MHME,  KC_MEND, ____,   KC_4, KC_5, KC_6,  KC_MINS,   ____, ____,KC_BSLS, \
  KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME, KC_END,  ____,    KC_1, KC_2, KC_3,  KC_ENT,    ____,      KC_ENT,  \
  ____,    ____,    ____,    ____,    ____,    ____,    ____,    KC_0, KC_0, KC_DOT,____,       ____, \
  ____,    ____,    ____,                KC_SPBL,                                  ____, ____, ____, ____),

/* Keymap _MV: RGB Control Layer
* ,-----------------------------------------------------------.
* |GRV  |MUTE|VOLD|VOLU|MPRV|MPLY|MNXT| 7| 8| 9| 0| -| +  |Bsp|
* |-----------------------------------------------------------|
* |Tab  |   | UP|   |HOME|   |   |  4|  5|  6|  P|  *|  ]|  \ |
* |-----------------------------------------------------------|
* |Caps |LEFT|DOWN|RIGHT|END|   |  1|  2|  3|  L|  /|  '|Enter|
* |-----------------------------------------------------------|
* |Shft    |    |   |   |   |   |   |  0|  ,|  .|  /|Shift    |
* |-----------------------------------------------------------'
* |Ctrl|Gui |Alt |         Space         |Gui |Alt |GUI |F13  |
* `-----------------------------------------------------------'
*/
[_MV] = KEYMAP_ANSI(
#ifdef RGBLIGHT_ENABLE
KC_GRV, ____,____,____,____,____,____,____,____,____,____,____,____,RESET,  \
____,____,____,____,____,____,____,____,____,____,____, BL_DEC,BL_INC, BL_TOGG, \
____,____,____,____,____,____,____,____,____,____,____,____,        ____, \
____,RGB_TOG,RGB_MOD,RGB_HUI,RGB_HUD,RGB_SAI,RGB_SAD,RGB_VAI,RGB_VAD,____,____,____, \
____,____,____,                 ____,                       ____,____,____, ____),
#else
KC_GRV, ____,____,____,____,____,____,____,____,____,____,____,____,RESET,  \
____,____,____,____,____,____,____,____,____,____,____, BL_DEC, BL_INC,BL_TOGG, \
____,____,____,____,____,____,____,____,____,____,____,____,____, \
____,____,____,____,____,____,____,____,____,____,____,____, \
____,____,____,                ____,
              ____,____,____,____),
#endif
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
