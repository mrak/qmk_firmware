#include "clueboard.h"

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define CTL_ESC CTL_T(KC_ESC)
#define SPC__FL LT(_FL,KC_SPC)
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _FK 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,--------------------------------------------------------------------------.  ,----.
   * |   `|   1|   2|   3|   4|   5|   6|   7|   8|   9|   0|   -|   =|    |  BS|  | Ins|
   * |--------------------------------------------------------------------------|  |----|
   * |   Tab|   Q|   W|   E|   R|   T|   Y|   U|   I|   O|   P|   [|   ]|      \|  | Del|
   * |--------------------------------------------------------------------------|  `----'
   * |Esc/Ctl|   A|   S|   D|   F|   G|   H|   J|   K|   L|   ;|   '|     |  Ent|
   * |-----------------------------------------------------------------------------.
   * |Shift|     |  Z|   X|   C|   V|   B|   N|   M|   ,|   .|   /|     |Shift|  UP|
   * |------------------------------------------------------------------------|----|----.
   * |Hyper| LGui| LAlt|     |         |    Space|     | RAlt| RCtl| _FL |LEFT|DOWN|RGHT|
   * `----------------------------------------------------------------------------------'
   */
[_BL] = KEYMAP(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC,          KC_INS, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,                   KC_DEL, \
  CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_FN0,                            \
  KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, KC_RSFT,          KC_UP,           \
  KC_HYPR, KC_LGUI, KC_LALT, XXXXXXX,          XXXXXXX, SPC__FL,                            XXXXXXX, KC_RALT, KC_RCTL, MO(_FL), KC_LEFT, KC_DOWN, KC_RGHT \
),

  /* Keymap _FL: Function Layer (Left)
   * ,--------------------------------------------------------------------------.  ,----.
   * |    |  F1|  F2|  F3|  F4|  F5|  F6|  F7|  F8|  F9| F10| F11| F12| Del| Del|  |  V+|
   * |--------------------------------------------------------------------------|  |----|
   * |      |    |  SL|  MU|  SR| SU |    |  M1|  M3|  M2|PScr|SLck|Paus|     V=|  |  V-|
   * |--------------------------------------------------------------------------|  `----'
   * |       |    |  ML|  MD|  MR| SD |LEFT|DOWN|  UP|RGHT|    |    |     |     |
   * |-----------------------------------------------------------------------------.
   * |     |    |    |    |    |    |    |PgUp|PgDn|Home| End|    |     | Caps|PGUP|
   * |------------------------------------------------------------------------|----|----.
   * |  _FK|     |     |     |         |         |     |     | Menu|     |HOME|PGDN| END|
   * `----------------------------------------------------------------------------------'
   */
[_FL] = KEYMAP(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  KC_DEL,          KC_VOLU, \
  _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______, KC_BTN1, KC_BTN3, KC_BTN2, KC_PSCR, KC_SLCK, KC_PAUS, KC_MUTE,                   KC_VOLD, \
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, _______,                            \
  _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, KC_HOME, KC_END,  _______, _______, KC_CAPS,          KC_PGUP,          \
  MO(_FK), _______, _______, _______,          _______, _______,                            _______, _______, KC_MENU, _______, KC_HOME, KC_PGDN, KC_END   \
),

  /* Keymap _FK: Function Layer (Keyboard)
   * ,--------------------------------------------------------------------------.  ,----.
   * |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |  |    |
   * |--------------------------------------------------------------------------|  |----|
   * |      |    |    |    |RSET|    |    |    |    |    |    |    |    |       |  |    |
   * |--------------------------------------------------------------------------|  `----'
   * |       |    |    |    |    |    |    |    |    |    |    |    |     |     |
   * |-----------------------------------------------------------------------------.
   * |     |    |    |    |    |    |    |    |    |    |    |    |     |     |    |
   * |------------------------------------------------------------------------|----|----.
   * |     |     |     |     |         |         |     |     |     |     |    |    |    |
   * `----------------------------------------------------------------------------------'
   */
[_FK] = KEYMAP(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,           _______, \
  _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                            \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          \
  _______, _______, _______, _______,          _______, _______,                            _______, _______, _______, _______, _______, _______, _______  \
),
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT),
};
