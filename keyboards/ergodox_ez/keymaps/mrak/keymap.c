#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define FNUM 1 // symbols
#define MOUSE 2 // mouse keys
#define MEDIA 3 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer

 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |   -  |           |  =   |   6  |   7  |   8  |   9  |   0  | Tog L1 |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   ~    |   Q  |   W  |   E  |   R  |   T  |   {  |           |  }   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   "    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|   [  |           |  ]   |------+------+------+------+------+--------|
 * |   (    |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   )    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Mouse | Shift| Ctrl | Alt  | GUI  |                                       | Left | Down | Up   |Right |MEDIA |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Tab  | F19  |       | Ins  |  Del |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |Shift/|Super/| Home |       | PgUp | Alt/   | Ctrl/|
 *                                 | Enter| Esc  |------|       |------| Bckspc |Space |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,      KC_2,     KC_3,   KC_4,   KC_5,   KC_MINS,
        KC_TILD,         KC_Q,      KC_W,     KC_E,   KC_R,   KC_T,   KC_LCBR,
        KC_DQUO,        KC_A,      KC_S,     KC_D,   KC_F,   KC_G,
        KC_LPRN,        KC_Z,      KC_X,     KC_C,   KC_V,   KC_B,   KC_LBRC,
        TT(MOUSE),        KC_LSFT,   KC_LCTL,  KC_LALT,KC_LGUI,
                                                    KC_TAB,   KC_F19,
                                                              KC_HOME,
                                   SFT_T(KC_ENT),GUI_T(KC_ESC),KC_END,
        // right hand
             KC_EQL,      KC_6,   KC_7,   KC_8,   KC_9,  KC_0,             TT(FNUM),
             KC_RCBR,    KC_Y,    KC_U,   KC_I,   KC_O,  KC_P,              KC_BSLS,
                          KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN,          KC_QUOT,
             KC_RBRC,     KC_N,   KC_M,   KC_COMM,KC_DOT,KC_SLSH,          KC_RPRN,
                                  KC_LEFT,KC_DOWN,KC_UP, KC_RIGHT,         TT(MEDIA),
             KC_INS,        KC_DEL,
             KC_PGUP,
             KC_PGDN,ALT_T(KC_BSPC),CTL_T(KC_SPC)
    ),
/* Keymap 1: Function and numpad Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  RESET  |      |  F10 |  F11 |  F12 |      |      |           | NmLck|      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |  F7  |  F8  |  F9  |      |      |           |      |      |   7  |   8  |   9  |   /  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |  F4  |  F5  |  F6  |      |------|           |------|      |   4  |   5  |   6  |   *  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |  F1  |  F2  |  F3  |      |      |           |      |      |   1  |   2  |   3  |   -  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |   0  |    . |  ENT |   +  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FNUM] = KEYMAP(
       // left hand
       RESET,  KC_TRNS,KC_F10, KC_F11, KC_F12,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_F7,  KC_F8,  KC_F9, KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_F4,  KC_F5,  KC_F6, KC_TRNS,
       KC_TRNS,KC_TRNS,KC_F1,  KC_F2,  KC_F3, KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_NLCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_TRNS,
                KC_TRNS, KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_TRNS,
                         KC_P0,   KC_PDOT, KC_PENT, KC_PPLS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |M Clik|      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Left |Right |ScUp  |       |      |      |      |
 *                                 | Click|Click |------|       |------|      |      |
 *                                 |      |      |ScDwn |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MOUSE] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_BTN3, KC_TRNS,
                                                    KC_WH_U,
                                  KC_BTN1, KC_BTN2, KC_WH_D,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: media keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | Mute | Play |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | Vol- |      |      |
 *                                 |      |      |------|       |------| Prev | Next |
 *                                 |      |      |      |       | Vol+ |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MEDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_MUTE, KC_MPLY,
       KC_VOLU,
       KC_VOLD, KC_MPRV, KC_MNXT
),
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    bool layer_1_on = (layer_state >> FNUM) & 1;
    bool layer_2_on = (layer_state >> MOUSE) & 1;
    bool layer_3_on = (layer_state >> MEDIA) & 1;

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    if (layer_1_on) {
        ergodox_right_led_1_on();
    }
    if (layer_2_on) {
        ergodox_right_led_2_on();
    }
    if (layer_3_on) {
        ergodox_right_led_3_on();
    }
};
