#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "timer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

// #define LINUX_MODE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  | ENT  |           | BTN2 |   6  |   7  |   8  |   9  |   0  |  ESC   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  BTN1  |   Q  |   W  |   D  |   P  |   G  | DELT |           | BTN1 |   J  |   L  |   U  |   Y  |   Z  |  BTN1  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  L1    |   A  |   R  |   S  |   T  |   F  |------|           |------|   M  |   N  |   E  |   I  |   O  |   L1   |
 * |--------+------+------+------+------+------|  L2  |           | L2   |------+------+------+------+------+--------|
 * |    `   |  Tab |   X  |   C  |   V  |   B  |      |           |      |   K  |   H  |   ,  |   .  | ENT  |  BTN2  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | UP   | DOWN | LEFT | RIGHT| BSPC |                                       | SPC  | UP   | DOWN | WH_U | WH_D |
 *   `----------------------------------'                                       `----------------------------------'
 * OSX:
 *                                        ,-------------.       ,-------------.
 *                                        | RALT |      |       |      | RALT |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LCTL |       | RCTL |      |      |
 *                                 |LSHFT | LGUI |------|       |------| RGUI |RSHFT |
 *                                 |      |      | LALT |       | RALT |      |      |
 *                                 `--------------------'       `--------------------'
 *
 * Linux:
 *                                        ,-------------.       ,-------------.
 *                                        | RALT | LGUI |       | RGUI | RALT |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LALT |       | LALT |      |      |
 *                                 |LSHFT | LCTL |------|       |------| RCTL |RSHFT |
 *                                 |      |      | RALT |       | RALT |      |      |
 *                                 `--------------------'       `--------------------'

 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*

// tried: LT(SYMB, KC_TAB) instead of MO

// OLS vs. MO
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,           KC_1,      KC_2,    KC_3,    KC_4,   KC_5,    KC_ENT,
        KC_BTN1,          KC_Q,      KC_W,    KC_D,    KC_P,   KC_G,    KC_DELT,
        KC_TAB,           KC_A,      KC_R,    KC_S,    KC_T,   KC_F,
        // LT(SYMB, KC_TAB), KC_A,      KC_R,    KC_S,    KC_T,   KC_F,
        KC_GRV,           MO(SYMB),  KC_X,    KC_C,    KC_V,   KC_B,    MO(MDIA),
        KC_UP,            KC_DOWN,   KC_LEFT, KC_RGHT, KC_BSPC,
#ifndef LINUX_MODE
                                                     KC_LALT,   KC_NO,
                                                                KC_LCTL,
                                              KC_LSFT, KC_LGUI, KC_LALT,
#else
                                                     KC_RALT,   KC_LGUI,
                                                                KC_LALT,
                                              KC_LSFT, KC_LCTL, KC_RALT,
#endif
        // right hand
             KC_BTN2,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_ESC,
             KC_BTN1,     KC_J,    KC_L,    KC_U,    KC_Y,    KC_Z,       KC_BTN1,
                          KC_M,    KC_N,    KC_E,    KC_I,    KC_O,       KC_ENT,
                        //   KC_M,    KC_N,    KC_E,    KC_I,    KC_O,       LT(SYMB, KC_ESC),
             MO(MDIA),    KC_K,    KC_H,    KC_COMM, KC_DOT,  MO(SYMB),   KC_BTN2,
                                   KC_SPC,  KC_UP,   KC_DOWN, KC_WH_U,    KC_WH_D,
#ifndef LINUX_MODE
             KC_NO,   KC_RALT,
             KC_RCTL,
             KC_RALT, KC_RGUI, KC_RSFT
#else
             KC_RGUI, KC_RALT,
             KC_LALT,
             KC_RALT, KC_RCTL, KC_RSFT
#endif
    ),

/*
 *
  !@#$%^&*()
  `~-_;:<>?/\|'"

    >>=     bind
    >>      then
    *>      then
    ->      to                a -> b: a to b
    <-      bind              (as it desugars to >>=)
    <$>     (f)map
    <$      map-replace by    0 <$ f: "f map-replace by 0"
    <*>     ap(ply)           (as it is the same as Control.Monad.ap)
    $                         (none, just as " " [whitespace])
    .       pipe to           a . b: "b pipe-to a"
    !!      index
    !       index / strict    a ! b: "a index b", foo !x: foo strict x
    <|>     or / alternative  expr <|> term: "expr or term"
    ++      concat / plus / append
    []      empty list
    :       cons
    ::      of type / as      f x :: Int: f x of type Int
    \       lambda
    @       as                go ll@(l:ls): go ll as l cons ls
    ~       lazy              go ~(a,b): go lazy pair a, b
 */

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   ?  |   @  |   #  |   %  |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   &  |   |  |   \  |   ~  | INS  |           | WH_D |      |   "  |   [  |   ]  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  ESC   |   /  |   =  |   -  |   :  |   +  |------|           |------|   _  |   '  |   (  |   )  |   ?  |   ESC  |
 * |--------+------+------+------+------+------|      |           | WH_U |------+------+------+------+------+--------|
 * |        |   <  |   *  |   $  |   >  |   ^  |      |           |      |      |   `  |   {  |   }  |   !  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | Home | End  |  Del |                                       |      | PgUp | PgDn |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  -   |  -   |       |  -   |  -   |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  -   |       |  -   |      |      |
 *                                 |  -   |  -   |------|       |------|  -   |  -   |
 *                                 |      |      |  -   |       |  -   |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_NO,   KC_QUES, KC_AT,   KC_HASH, KC_PERC, KC_NO,   KC_NO,
       KC_NO,   KC_EXLM, KC_AMPR, KC_PIPE, KC_BSLS, KC_TILD, KC_INS,
       KC_ESC,  KC_SLSH, KC_EQL,  KC_MINS, KC_COLN, KC_PLUS,
       KC_NO,   KC_LABK, KC_ASTR, KC_DLR,  KC_RABK, KC_CIRC, KC_NO,
       KC_NO,   KC_NO,   KC_HOME, KC_END,  KC_DELT,
                                        KC_TRNS, KC_TRNS,
                                                 KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_WH_D, KC_NO,   KC_DQUO, KC_LBRC, KC_RBRC, KC_SCLN, KC_NO,
                KC_UNDS, KC_QUOT, KC_LPRN, KC_RPRN, KC_QUES, KC_ESC,
       KC_WH_U, KC_NO,   KC_GRV,  KC_LCBR, KC_RCBR, KC_EXLM, KC_NO,
                         KC_TRNS, KC_PGUP, KC_PGDN, KC_NO,   KC_NO,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | NumLk  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | PrScr  |      | Lclk | MsUp | Rclk | WhlD |      |           |      |      |   7  |   8  |   9  |   /  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   | Play |MsLeft|MsDown|MsRght| WhlU |------|           |------|   +  |   4  |   5  |   6  |   0  |    =   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BrwBk  | Mute | WhlL |      | WhlR |      |      |           |      |   -  |   1  |   2  |   3  |   *  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | VolUp| VolDn| Prev | Next |  -   |                                       |      |   ,  |   .  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | ScLk | Pause|       |  -   |  -   |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  -   |       |  -   |      |      |
 *                                 |  -   |  -   |------|       |------|  -   |  -   |
 *                                 |      |      |  -   |       |  -   |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_NLCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,
       KC_PSCR, KC_NO,   KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_D, KC_NO,
       KC_CAPS, KC_MPLY, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U,
       KC_WBAK, KC_MUTE, KC_WH_L, KC_NO,   KC_WH_R, KC_NO,   KC_NO,
       KC_VOLU, KC_VOLD, KC_MPRV, KC_MNXT, KC_TRNS,
                                           KC_SLCK, KC_PAUS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_NO,    KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
       KC_NO,    KC_UP,   KC_7,    KC_8,    KC_9,   KC_SLSH, KC_F12,
                 KC_PLUS, KC_4,    KC_5,    KC_6,   KC_0,    KC_EQL,
       KC_NO,    KC_MINS, KC_1,    KC_2,    KC_3,   KC_ASTR, KC_NO,
                          KC_TRNS, KC_COMM, KC_DOT, KC_NO,   KC_NO,
       KC_TRNS, KC_TRNS,
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

#define BLINK_BASE2_ON   6U
#define BLINK_BASE2_OFF 50U

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
