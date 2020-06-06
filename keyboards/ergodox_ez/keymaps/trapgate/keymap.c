#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// There are two base layers, BASE and GAME.
#define BASE 0 // default layer
#define GAME 1 // game layer
// Two overlay layers, symbols and media keys/movement.
#define SYMB 2 // symbols
#define MDIA 3 // media keys

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EPRM,
    VRSN,
    RGB_SLD
};

// Tapdance definitions.
enum dances {
    DLFT = 0,   // left bracket/brace/paren
    DRGHT,      // right bracket/brace/paren
    DLAYR       // layer toggle
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | Esc  |           | Lock |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  | LTD  |           | Enter|   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| [{(  |           | ]})  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|X/Alt |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  | ./Alt|//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1| '/L2 |AltGui| Left | Right|                                       | Down |  Up  | Left | Right| ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Alt/App|LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |Shift-| Home |       | PgUp |        |      |
 *                                 |Space | Tab  |------|       |------|  Tab   |Space |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(  // layer 0 : default
    KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,     KC_5,   KC_ESC,     KC_LOCK,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,       KC_MINS,
    KC_DELT,        KC_Q,         KC_W,   KC_E,   KC_R,     KC_T,   TD(DLAYR),  KC_ENT,      KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,       KC_BSLS,
    KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,     KC_G,                            KC_H,   KC_J,  KC_K,   KC_L,   LT(MDIA, KC_SCLN),GUI_T(KC_QUOT),
    KC_LSFT,        CTL_T(KC_Z),  ALT_T(KC_X),KC_C,KC_V,    KC_B,   TD(DLFT),   TD(DRGHT),   KC_N,   KC_M,  KC_COMM,ALT_T(KC_DOT), CTL_T(KC_SLSH),   KC_RSFT,
    LT(SYMB,KC_GRV),LT(MDIA,KC_QUOT),     LALT(KC_LGUI),    KC_LEFT,KC_RGHT,                         KC_DOWN, KC_UP,KC_LEFT,KC_RIGHT,   OSL(SYMB),
                                          ALT_T(KC_APP),    KC_LGUI,            KC_LALT, CTL_T(KC_ESC),
                                                            KC_HOME,            KC_PGUP,
                                          KC_SPC,LSFT(KC_TAB),KC_END,           KC_PGDN, KC_TAB, KC_SPC
),

[GAME] = LAYOUT_ergodox_pretty(  // game layer
    KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,     KC_5,   KC_ESC,     _______,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,       KC_MINS,
    KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,     KC_T,   _______,    KC_ENT,      KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,       KC_BSLS,
    KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,     KC_G,                            KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,    KC_QUOT,
    KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,     KC_B,   KC_ENT,     _______,     KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,    KC_RSFT,
    KC_LCTL,        KC_LALT,      MO(SYMB),       KC_LEFT,          KC_RGHT,                         KC_DOWN, KC_UP,KC_LEFT,KC_RIGHT,   OSL(SYMB),

                                            ALT_T(KC_NO),   KC_LGUI,            KC_LALT, CTL_T(KC_ESC),
                                                            KC_HOME,            KC_PGUP,
                                            KC_SPC,LSFT(KC_TAB),KC_END,         KC_PGDN,KC_TAB, KC_SPC
),


/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  | ESC  |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|  L2  |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |   0  |   ,  |   .  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
    VRSN,   KC_F1,     KC_F2,      KC_F3,      KC_F4,    KC_F5,    KC_ESC,      _______,KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______,KC_EXLM,   KC_AT,      KC_LCBR,    KC_RCBR,  KC_PIPE,  _______,     _______,KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
    _______,KC_HASH,   KC_DLR,     KC_LPRN,    KC_RPRN,  KC_GRV,                        KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, _______,
    _______,CTL_T(KC_PERC), ALT_T(KC_CIRC),KC_LBRC,KC_RBRC,KC_TILD,_______,     _______,KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, _______,
    _______,_______,_______,KC_LEFT,KC_RIGHT,                                                    KC_0,   KC_COMM, KC_DOT,  KC_EQL,  _______,
                                                         _______, _______,      _______, _______,
                                                                  _______,      _______,
                                                _______, _______, _______,      _______, _______, KC_WBAK
),

/* Keymap 2: Media and mouse keys
 *
 * This layer also has the RGB controls for the shine (RGBLIGHT_ENABLE) and the glow (RGB_MATRIX_ENABLE).
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |RESET |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| Left | Down |  Up  | Right|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox_pretty(
    EPRM,    _______, _______, _______, _______, _______, _______,      RESET,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_MS_U, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, KC_MPLY,
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______,
    _______, _______, _______, KC_BTN1, KC_BTN2,                                          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                                 RGB_MOD, _______,      RGB_TOG, RGB_SLD,
                                                          _______,      _______,
                                          RGB_VAD,RGB_VAI,_______,      _______, RGB_HUD, RGB_HUI
),

};

void dance_lyr_finished(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1) {
        if (layer_state_is(0)) {
            layer_on(SYMB);
        } else {
            layer_clear();
        }
    } else if (state->count == 2) {
        layer_on(GAME);
    }
}

void dance_lyr_reset(qk_tap_dance_state_t *state, void *user_data)
{}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DLFT] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LPRN),
    [DRGHT] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RPRN),
    // Set the active layer with a tap dance.
    [DLAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lyr_finished, dance_lyr_reset)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
    case 0:
        if (record->event.pressed) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
    case 1:
        if (record->event.pressed) { // For resetting EEPROM
            eeconfig_init();
        }
        break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
