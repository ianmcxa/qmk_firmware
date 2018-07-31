#include "ergodox_ez.h"
#include "keymap_steno.h"

#define _DVORAK 0 // default layer
#define _PLOVER 2 // Plover Steno Virtual Serial
#define _SYMB 1 // symbols

#define KC_DVRK TO(_DVORAK)
#define KC_SYMB TO(_SYMB)
#define KC_PLOV TO(_PLOVER)

// use underscores for transperent keys
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |      |           | PLOV |   6  |   7  |   8  |   9  |   0  | Bkspc  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   '  |   ,  |   .  |   p  |   y  |  [   |           |  ]   |   f  |   g  |   c  |   r  |   l  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   a  |   o  |   e  |   u  |   i  |------|           |------|   d  |   h  |   t  |   n  |   s  | Enter  |
 * |--------+------+------+------+------+------|      |           | Bkspc|------+------+------+------+------+--------|
 * | LShift |   ;  |   q  |   j  |   k  |   x  |      |           |      |   b  |   m  |   w  |   v  |   z  | Shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctl  |Win/CMD|Right| Left |  \   |                                | Left | Down |  Up  |Right | Ctl  |
 *   `----------------------------------'                                `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Alt  | Cmd  |       | Del  |  Alt   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | SyRq |       | Esc  |        |      |
 *                                 | Space|Left  |------|       |------| Right  |Enter |
 *                                 |      |Shift | Ctl  |       | CTL  | LShift |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_DVORAK] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
      KC_GRAVE,    KC_1,     KC_2,   KC_3,   KC_4,  KC_5,  KC_SYMB,
        KC_TAB,  KC_QUOT,  KC_COMM, KC_DOT,   KC_P,  KC_Y,  KC_LBRC,
        KC_CAPS,    KC_A,     KC_O,   KC_E,   KC_U,  KC_I,
        KC_LSFT, KC_SCLN,     KC_Q,   KC_J,   KC_K,  KC_X,  MO(_SYMB),
        KC_LCTL,  KC_LGUI, KC_LEFT, KC_RGHT,  KC_BSLS,
                                                    KC_LALT, KC_LGUI,
                                                             KC_PSCR,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
             KC_PLOV,  KC_6,   KC_7,   KC_8,   KC_9,   KC_0,  KC_BSPC,
             KC_LBRC,  KC_F,   KC_G,   KC_C,   KC_R,   KC_L,  KC_SLSH,
                       KC_D,   KC_H,   KC_T,   KC_N,   KC_S,   KC_ENT,
             KC_BSPC,  KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,  KC_LSFT,
                            KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,  KC_RCTL,
             KC_DEL,  KC_RALT,
             KC_ESC,
             KC_RCTL,KC_RSFT, KC_ENT
    ),
/* Keymap 3: GeminiPR
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      | DVRK |           | SYMB |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   #  |   #  |   #  |   #  |   *  |           |   *  |   #  |   #  |   #  |   #  |   #  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   S  |   T  |   P  |   H  |------|           |------|   F  |   P  |   L  |   T  |   D  |        |
 * |--------+------+------+------+------+------|   *  |           |   *  |------+------+------+------+------+--------|
 * |        |      |   S  |   K  |   W  |   R  |      |           |      |   R  |   B  |   G  |   S  |   Z  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | ESC  |      |      |
 *                                 |   A  |   O  |------|       |------|   E  |   U  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// TxBolt over Serial
[_PLOVER] = LAYOUT_ergodox(
       KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_DVRK,
       KC_NO,  KC_NO,   STN_N1,  STN_N2,  STN_N3,  STN_N4, STN_ST1,
       KC_NO,  KC_NO,   STN_S1,  STN_TL,  STN_PL,  STN_HL,
       KC_NO,  KC_NO,   STN_S2,  STN_KL,  STN_WL,  STN_RL, STN_ST2,
       KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,
                                           KC_NO,   KC_NO,
                                                    KC_NO,
                                  STN_A,   STN_O,   KC_NO,
    // right hand
       KC_DVRK,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
       STN_ST3,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9, KC_NO,
                 STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR, KC_NO,
       STN_ST4,  STN_RR,  STN_RR,  STN_GR,  STN_SR,  STN_ZR, KC_NO,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
       KC_NO,   KC_NO,
       KC_TRNS,
       KC_NO,   STN_E,   STN_U
),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | PLOV |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[_SYMB] = LAYOUT_ergodox(
       // left hand
       M(0),   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_DVRK,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_DVRK, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  steno_set_mode(STENO_MODE_GEMINI);
};
