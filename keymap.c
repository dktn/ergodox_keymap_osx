#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "timer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  | Enter|           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    `   |   Q  |   W  |   D  |   P  |   G  | Del  |           | L2   |   J  |   L  |   U  |   Y  |   ;  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Tab   |   A  |   R  |   S  |   T  |   F  |------|           |------|   M  |   N  |   E  |   I  |   O  | Enter  |
 * |--------+------+------+------+------+------| L1   |           | L1   |------+------+------+------+------+--------|
 * |   '    |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   H  |   ,  |   .  |  /   |   \    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | WH_D | WH_U | Left | Right| Back |                                       | Space| Up   | Down |  =   |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | BTN1 | BTN2 |       | BTN1 | BTN2  |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | LCtrl|       | RCtrl|       |      |
 *                                 |LShift|LCmd  |------|       |------| RCmd  |RShift|
 *                                 |      |      | RAlt |       | RAlt |       |      |
 *                                 `--------------------'       `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,    KC_3,    KC_4,   KC_5,   KC_ENT,
        KC_GRV,         KC_Q,         KC_W,    KC_D,    KC_P,   KC_G,    KC_DELT,
        KC_TAB,         KC_A,         KC_R,    KC_S,    KC_T,   KC_F,
        KC_QUOT,        KC_Z,         KC_X,    KC_C,    KC_V,   KC_B,    MO(SYMB),
        KC_WH_D,        KC_WH_U,      KC_LEFT, KC_RGHT, KC_BSPC,
                                                     KC_BTN1,   KC_BTN2,
                                                                KC_LCTL,
                                              KC_LSFT, KC_LGUI, KC_LALT,
        // right hand
             KC_NO,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_NO,
             MO(MDIA),    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_MINS,
                          KC_M,    KC_N,    KC_E,    KC_I,    KC_O,       KC_ENT,
             MO(SYMB),    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,    KC_BSLS,
                                   KC_SPC,  KC_UP,   KC_DOWN, KC_EQL,     KC_NO,
             KC_BTN1, KC_BTN2,
             KC_RCTL,
             KC_RALT, KC_RGUI, KC_RSFT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      | Ins  |           |      |      |   [  |  ]   |      |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |------|           |------|   ^  |   &  |   *  |   (  |   )  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   {  |   }  |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | Home | End  |      |                                       |      | PgUp | PgDn |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  -   |       |   -  |      |      |
 *                                 |  -   |  -   |------|       |------|  -   |  -   |
 *                                 |      |      |  -   |       |   -  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_INS,
       KC_NO,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_HOME, KC_END,  KC_NO,
                                        KC_NO,   KC_NO,
                                                 KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_NO,   KC_NO,   KC_F12,
                KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_NO,
       KC_NO,   KC_NO,   KC_LCBR, KC_RCBR, KC_NO,   KC_NO,   KC_NO,
                         KC_NO,   KC_PGUP, KC_PGDN, KC_NO,   KC_NO,
       KC_NO,   KC_NO,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | NumLk  | ScLk | Pause|      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | PrScr  |      | Lclk | MsUp | Rclk | WhlD |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |      |MsLeft|MsDown|MsRght| WhlU |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Play   | Mute | WhlL |      | WhlR |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | VolUp| VolDn| Prev | Next | BrwBk|                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  -   |       |   -  |      |      |
 *                                 |  -   |  -   |------|       |------|  -   |  -   |
 *                                 |      |      |  -   |       |   -  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_NLCK, KC_SLCK, KC_PAUS, KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_PSCR, KC_NO,   KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_D, KC_NO,
       KC_CAPS, KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U,
       KC_MPLY, KC_MUTE, KC_WH_L, KC_NO,   KC_WH_R, KC_NO,   KC_NO,
       KC_VOLU, KC_VOLD, KC_MPRV, KC_MNXT, KC_WBAK,
                                           KC_NO,   KC_NO,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

#define caps_led_on  ergodox_right_led_2_on
#define caps_led_off ergodox_right_led_2_off

typedef enum onoff_t {OFF, ON} onoff;

const macro_t *action_get_macro_old(keyrecord_t *record, uint8_t id, uint8_t opt)
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

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

#define BLINK_BASE1_ON   1U
#define BLINK_BASE1_OFF 10U

#define BLINK_BASE2_ON  120U
#define BLINK_BASE2_OFF 220U

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    static onoff board_led_state = OFF;
    static uint16_t dt = 0;
    static uint8_t oldlayer = 0;

    if (oldlayer != layer) {
        // Layer was just toggled.
        if (layer == BASE) {
            ergodox_board_led_off();
            board_led_state = OFF;
        }
    } else if (layer == SYMB) {
        if (board_led_state == OFF) {
            if (timer_elapsed(dt) > BLINK_BASE1_OFF) {
                dt = timer_read();
                ergodox_board_led_on();
                board_led_state = ON;
            }
        } else {
            if (timer_elapsed(dt) > BLINK_BASE1_ON) {
                dt = timer_read();
                ergodox_board_led_off();
                board_led_state = OFF;
            }
        }
    } else if (layer >= MDIA) {
        if (board_led_state == OFF) {
            if (timer_elapsed(dt) > BLINK_BASE2_OFF) {
                dt = timer_read();
                ergodox_board_led_on();
                board_led_state = ON;
            }
        } else {
            if (timer_elapsed(dt) > BLINK_BASE2_ON) {
                dt = timer_read();
                ergodox_board_led_off();
                board_led_state = OFF;
            }
        }
    }
    oldlayer = layer;
}
