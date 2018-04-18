#include "zen.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NAV 1
#define _RGB 2

//Tap mods
#define KC_SPNV LT(_NAV,KC_SPC)
#define KC_DLRG LT(_RGB,KC_DEL)


//These keycodes are macros for Windows-style home and end functionality on a Mac.
#define KC_MHME LGUI(KC_LEFT)
#define KC_MEND LGUI(KC_RGHT)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAV,

};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.             .-----------------------------------------.
 * | =+   |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | - _  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |Ctrl  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
 * | Esc | `~  | Enter | LALT | LGUI | BSPC | DLRG  ||Enter| SPNV |  LGUI |LALT |  [{  | ]}   | NO   |
 * `------------------------------------------------''-----------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_EQL,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                       KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT , \
  KC_ESC,   KC_GRV,  KC_ENT,  KC_LALT, KC_LGUI,  KC_BSPC,  KC_DLRG,  KC_ENT, KC_SPNV,  KC_LGUI,  KC_LALT, KC_LBRC, KC_RBRC, KC_NO \
),

/* NAV
 * ,-----------------------------------------.             .-----------------------------------------.
 * | MUTE | VOLD | VOLU | MPRV | MPLY | MNXT |             | F6   |  F7  | F8   | F9   | F10  | F11  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |  Up  |      | MHME | MEND |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      | Left | Down |Right | HOME | END  |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      ||     |      |      |      |      |      |      |
 * `------------------------------------------------''-----------------------------------------------'
 */
[_NAV] = KEYMAP( \
  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT,                   KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11 ,  \
  KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_MHME, KC_MEND,                   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , \
  KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME, KC_END,                    KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
),

/* RGB
 * ,-----------------------------------------.             .-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             | F13  |  TAB |  TAB | SLSH | BSPC |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |RGBSAI|RGBVAI|RGBSAD| RESET|      |             |      |    7 |    8 |    9 | MINS |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |RGBHUD|RGBVAD|RGBHUI|      |      |             |      |    4 |    5 |    6 | PLUS |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             | Space|    1 |    2 |    3 | ENTER|      |
 * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
 * |      |      |      |RGBMOD|RGBTOG|      |      ||     |    0 |      |      |  DOT | ENTER|      |
 * `------------------------------------------------''-----------------------------------------------'
 */
[_RGB] = KEYMAP( \
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F13,  KC_TAB,  KC_TAB,  KC_SLSH, KC_BSPC, KC_TRNS ,  \
  KC_TRNS, RGB_SAI, RGB_VAI, RGB_SAD, RESET,   KC_TRNS,                   KC_TRNS, KC_7,    KC_8,    KC_9,    KC_MINS, KC_TRNS , \
  KC_TRNS, RGB_HUD, RGB_VAD, RGB_HUI, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS , \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_SPC,  KC_1,    KC_2,    KC_3,    KC_ENT,  KC_TRNS , \
  KC_TRNS, KC_TRNS, KC_TRNS, RGB_MOD, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_0,    KC_TRNS, KC_TRNS, KC_DOT,  KC_ENT,  KC_TRNS \
),

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    //case COLEMAK:
      //if (record->event.pressed) {
        //#ifdef AUDIO_ENABLE
          //PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        //#endif
        //persistant_default_layer_set(1UL<<_COLEMAK);
      //}
      //return false;
      //break;
  }
  return true;
}
