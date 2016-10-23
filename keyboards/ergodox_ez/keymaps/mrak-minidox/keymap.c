#include "ergodox_ez.h"

#define _______ KC_TRNS
#define BASE 0 // default layer
#define SYM 1 // symbols
#define FKEYS 2 // symbols

// Macro IDs
#define M_LGUI_BANG 1
#define M_LCTL_LCBR 2
#define M_LALT_PIPE 3
#define M_RGUI_RPRN 4

// Macro keycodes
// named as MOD_KEY - MOD when held, KEY when tapped
// These are *shifted* characters, and cannot be used
// with the regular LGUI_T macros
#define LGUI_BANG MACROTAP(M_LGUI_BANG)
#define LCTL_LCBR MACROTAP(M_LCTL_LCBR)
#define LALT_PIPE MACROTAP(M_LALT_PIPE)
#define RGUI_RPRN MACROTAP(M_RGUI_RPRN)

const uint16_t PROGMEM fn_actions[] = {
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer

 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |GUI/Q |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |GUI P |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |CTL/A |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |CTL ; |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |ALT/Z |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |ALT / |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | S  - |                                       | S  = |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | L1/  | L2/  |      |       |      | L2/    | L1/  |
 *                                 | Enter| Esc  |------|       |------| Bckspc |Space |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        _______, _______,      _______, _______, _______,       _______,       _______,
        _______, LGUI_T(KC_Q), KC_W,    KC_E,    KC_R,          KC_T,          _______,
        _______, LCTL_T(KC_A), KC_S,    KC_D,    KC_F,          KC_G,
        _______, LALT_T(KC_Z), KC_X,    KC_C,    KC_V,          KC_B,          _______,
        _______, _______,      _______, _______, LSFT_T(KC_MINS),
                                                                _______,       _______,
                                                                               _______,
                                                 LT(SYM,KC_ENT),LT(FKEYS,KC_ESC),_______,
        // right hand
             _______, _______,        _______,       _______, _______, _______,         _______,
             _______, KC_Y,           KC_U,          KC_I,    KC_O,    RGUI_T(KC_P),    _______,
                      KC_H,           KC_J,          KC_K,    KC_L,    RCTL_T(KC_SCLN), _______,
             _______, KC_N,           KC_M,          KC_COMM, KC_DOT,  RALT_T(KC_SLSH), _______,
                                      RSFT_T(KC_EQL),_______, _______, _______,         _______,
             _______, _______,
             _______,
             _______, LT(FKEYS,KC_BSPC),LT(SYM,KC_SPC)
),
/* Keymap 1: Symbols and arrows
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |GUI ! |  @   |  #   |  $   |  %   |      |           |      |  ^   |   &  |   *  |   (  |GUI ) |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |CTL 1 |  2   |  3   |  4   |  5   |------|           |------|  6   |  7   |  8   |  9   |CTL 0 |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |ALT | |  "   |  {   |  }   |  _   |      |           |      |  +   |  [   |  ]   |  '   |ALT \ |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      | S/TB |                                       | S/TB |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |  `   |------|       |------|  ~   |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYM] = LAYOUT_ergodox(
       // left hand
       _______, _______,      _______, _______, _______,         _______, _______,
       _______, LGUI_BANG,    KC_AT,   KC_HASH, KC_DLR,          KC_PERC, _______,
       _______, LCTL_T(KC_1), KC_2,    KC_3,    KC_4,            KC_5,
       _______, LALT_PIPE,    KC_DQUO, KC_LCBR, KC_RCBR,         KC_UNDS, _______,
       _______, _______,      _______, _______, LSFT_T(KC_TAB),
                                                                 _______, _______,
                                                                          _______,
                                                        _______, KC_GRV,  _______,
       // right hand
       _______, _______, _______,        _______, _______, _______,         _______,
       _______, KC_CIRC, KC_AMPR,        KC_ASTR, KC_LPRN, RGUI_RPRN,       _______,
                KC_6,    KC_7,           KC_8,    KC_9,    RCTL_T(KC_0),    _______,
       _______, KC_PLUS, KC_LBRC,        KC_RBRC, KC_QUOT, RALT_T(KC_BSLS), _______,
                         RSFT_T(KC_TAB), _______, _______, _______,         _______,
       _______, _______,
       _______,
       _______, KC_TILD, _______
),
/* Keymap 2: Numbers and F-keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | G/F1 |  F2  |  F3  |  F4  |  Ins |      |           |      |      | PScr | SLck | Paus | GUI  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | C/F5 |  F6  |  F7  |  F8  |  Del |------|           |------| Left |  Dn  |  Up  | Rght | CTRL |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | A/F9 |  F10 |  F11 |  F12 |      |      |           |      | Home | PgDn | PgUp l End  | Alt  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | Shft |                                       | Shft |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FKEYS] = LAYOUT_ergodox(
       _______, _______,       _______, _______, _______, _______, _______,
       _______, LGUI_T(KC_F1), KC_F2,   KC_F3,   KC_F4,   KC_INS,  _______,
       _______, LCTL_T(KC_F5), KC_F6,   KC_F7,   KC_F8,   KC_DEL,
       _______, LALT_T(KC_F9), KC_F10,  KC_F11,  KC_F12,  _______, _______,
       _______, _______,       _______, _______, KC_LSFT,
                                                          _______, _______,
                                                                   _______,
                                                 _______, _______, _______,
    // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_RGUI, _______,
                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RCTL, _______,
       _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_RALT, _______,
                         KC_RSFT, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case M_LGUI_BANG:
            return MACRO_TAP_SHFT_KEY_HOLD_MOD(record, 1, LGUI);
        case M_LCTL_LCBR:
            return MACRO_TAP_SHFT_KEY_HOLD_MOD(record, LBRC, LCTL);
        case M_LALT_PIPE:
            return MACRO_TAP_SHFT_KEY_HOLD_MOD(record, BSLS, LALT);
        case M_RGUI_RPRN:
            return MACRO_TAP_SHFT_KEY_HOLD_MOD(record, 0, RGUI);
    }
    return MACRO_NONE;
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    //bool layer_1_on = (layer_state >> SYM) & 1;
    //bool layer_2_on = (layer_state >> FKEYS) & 1;
    //bool layer_3_on = (layer_state >> 3) & 1;

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_1_on();
    }

    if (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) {
        ergodox_right_led_2_on();
    }

    if (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) {
        ergodox_right_led_3_on();
    }

    //if (layer_1_on) {
    //    ergodox_right_led_1_on();
    //}
    //if (layer_2_on) {
    //    ergodox_right_led_2_on();
    //}
    //if (layer_3_on) {
    //    ergodox_right_led_3_on();
    //}
};
