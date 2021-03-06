#include "kinesis.h"

#define QWERTY 0 // Base qwerty
#define NAV 1
#define RGB 2

#define KC_RGB RGB

// Fillers to make layering more clear
#define ____ KC_TRNS
#define XXXXX KC_NO

//Tap mods
#define KC_SPNV LT(NAV,KC_SPC)
#define KC_DLRG LT(RGB,KC_DEL)


//These keycodes are macros for Windows-style home and end functionality on a Mac.
#define KC_MHME LGUI(KC_LEFT)
#define KC_MEND LGUI(KC_RGHT)

/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    | MUTE | VOLD | VOLU | MPRV  | MPLY | MNXT |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NAV |  RGB  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | CTRL   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | Enter| Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | LGUI | LAlt |         | LALT | LGUI |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | MHME |         | Home |      |      |
*                                 | BkSp | DLRG |------|         |------| Enter| SPNV |
*                                 |      |      | MEND |         | End  |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = KEYMAP(
           KC_ESC, KC_MUTE,KC_VOLD,KC_VOLU,KC_MPRV,KC_MPLY,KC_MNXT,XXXXX  ,XXXXX,
           KC_PLUS,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
           KC_LCTL,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
           KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_ENT ,KC_LEFT,KC_RGHT,
			                     KC_LGUI,KC_LALT,
                                   KC_MHME,
                   KC_BSPC,KC_DLRG ,KC_MEND,
          XXXXX  ,XXXXX  ,XXXXX  ,XXXXX  ,XXXXX  ,XXXXX  ,XXXXX, NAV, RGB,
	        KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
	        KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
	        KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
	        KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
		              KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
                          KC_LALT,KC_LGUI,
                                  KC_HOME,
                  KC_END ,KC_ENTER ,KC_SPNV
    ),


/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | F7  | F8   |      |      |      |      |      |      |        |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* |        |      |      |      |      |      |                           |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* |        |      |  UP  |      |      |      |                           |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |        | LEFT | DOWN | RIGHT|      |      |                           |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |        |      |      |      |      |      |                           |      |      |      |      |      |        |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          |      |      |      |      |                                         |      |      |      |      |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        |      |      |         |      |      |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      |      |         |      |      |      |
*                                 |      |      |------|         |------|      |      |
*                                 |      |      |      |         |      |      |      |
*                                 `--------------------'         `--------------------'
*/


[NAV] = KEYMAP(
           ____, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7 ,KC_F8,
           ____, ____   ,____   ,____  ,____  ,____   ,
           ____, ____   ,KC_UP  ,____  ,____  ,____   ,
        KC_CAPS, KC_LEFT,KC_DOWN,KC_RGHT ,____  ,____  ,
           ____, ____   ,____   ,____  ,____  ,____   ,
                  ____  ,____   ,____  ,____,
			     ____, ____  ,
                                    ____,
                           ____,____ ,____ ,
  ____  ,____  ,____  ,____ ,____ ,____ ,____, ____, ____,
  ____  ,____  ,____  ,____ ,____ ,____ ,
	____  ,____  ,____  ,____ ,____ ,____,
	____  ,____  ,____  ,____ ,____ ,____,
	____  ,____  ,____ ,____ ,____, ____,
		____  ,____,____,____,
           ____  ,____,
           ____  ,
           ____  ,____,____
    ),



/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,------------------------------------------------------------------------------------------------------------------------.
* | Esc    |       |       |       |       |       |      |      |      |      |      |      |      |      |      |        |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+-------------|
* |        |RGB_TOG|RGB_MOD|RGB_HUI|RGB_SAI|RGB_VAI|                           |  F13 |  TAB  |  TAB |SLASH| BSPC |        |
* |--------+------+------+------+------+-----------|                           +------+------+------+------+------+--------|
* |        |       |       |RGB_HUD|RGB_SAD|RGB_VAD|                           |      |   7  |   8  |   9  | MINS |        |
* |--------+------+------+------+------+-----------|                           |------+------+------+------+------+--------|
* |        |       |       |       |       |       |                           |      |   4  |   5  |   6  | PLUS |        |
* |--------+------+------+------+------+-----------|                           |------+------+------+------+------+--------|
* |        |       |       |       |       |       |                           | SPACE|   1  |   2  |   3  | ENTER|        |
* `--------+------+------+------+------+-----------                           `------+------+------+------+------+--------'
*          |       |       |       |       |                                         |      |      |  DOT | ENTER|
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        |      |      |         |      |      |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      |      |         |      |      |      |
*                                 |      |      |------|         |------|      |   0  |
*                                 |      |      |      |         |      |      |      |
*                                 `--------------------'         `--------------------'
*/


[RGB] = KEYMAP(
           ____, ____  ,____   ,____   ,____   ,____   ,____  ,____  ,____,
           ____,RGB_TOG,RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI,
           ____, ____  ,____   ,RGB_HUD,RGB_SAD,RGB_VAD,
           ____, ____  ,____   ,____   ,____   ,____  ,
           ____, ____  ,____   ,____   ,____   ,____   ,
                  ____  ,____  ,____  ,____,
			     ____, ____  ,
                                    ____,
                           ____,____ ,____ ,
  KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,____ ,____ ,____, ____, ____,
  KC_F13  ,KC_TAB  ,KC_TAB  ,KC_SLSH ,KC_BSPC ,____,
	____    ,KC_7    ,KC_8    ,KC_9    ,KC_MINS ,____,
	____    ,KC_4    ,KC_5    ,KC_6    ,KC_PLUS ,____,
	KC_SPC  ,KC_1    ,KC_2    ,KC_3    ,KC_ENT  ,____,
		      ____     ,____    ,KC_DOT    ,KC_ENT  ,
           ____  ,____,
           ____  ,
           ____  ,____,KC_0
    )
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
