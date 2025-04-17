/* Copyright 2020 Geoff Hickey <trapgate@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "version.h"

enum layers {
    BASE,    // default layer
    COLEMAK, // colemak key layer
    GAME,    // alternate base layer
    SYMB,    // symbols
    MDIA,    // media keys
};

enum custom_keycodes {
    EPRM = SAFE_RANGE,
    VRSN
};

// Tapdance definitions.
enum dances {
    DLFT = 0,   // left bracket/brace/paren
    DRGHT,      // right bracket/brace/paren
    DLAYR       // layer toggle
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_EQL,         KC_1,            KC_2,         KC_3,   KC_4,   KC_5, KC_ESC,    CW_TOGG,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_MINS,
        KC_DEL,         KC_Q,            KC_W,         KC_E,   KC_R,   KC_T, TD(DLAYR), KC_ENT,    KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_BSLS,
        KC_BSPC,        KC_A,            KC_S,         KC_D,   KC_F,   KC_G, TD(DLFT),  TD(DRGHT), KC_H,   KC_J,   KC_K,   KC_L,   LT(MDIA, KC_SCLN),GUI_T(KC_QUOT),
        KC_LSFT,        CTL_T(KC_Z),     ALT_T(KC_X),  KC_C,   KC_V,   KC_B,                       KC_N,   KC_M,   KC_COMM,ALT_T(KC_DOT),CTL_T(KC_SLSH),KC_RSFT,
        LT(SYMB,KC_GRV),LT(MDIA,KC_QUOT),LALT(KC_LGUI),KC_LEFT,KC_RGHT,KC_LGUI,                    KC_RALT,KC_DOWN,KC_UP,  KC_LEFT,TT(MDIA),TT(SYMB),
                                                KC_TAB, LT(SYMB,KC_HOME), LT(MDIA,KC_END), LT(MDIA,KC_PGDN), LT(SYMB, KC_PGUP), KC_SPC
    ),

    [COLEMAK] = LAYOUT_moonlander(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC,    CW_TOGG,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_DEL,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    TD(DLAYR), KC_ENT,   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    TD(DLFT),  TD(DRGHT),KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    GUI_T(KC_QUOT),
        KC_LSFT, CTL_T(KC_Z), CTL_T(KC_X),  KC_C,    KC_V,    KC_B,                         KC_K,    KC_M,    KC_COMM, ALT_T(KC_DOT),CTL_T(KC_SLSH), KC_RSFT,
        LT(SYMB,KC_GRV),LT(MDIA,KC_QUOT),LALT(KC_LGUI),KC_LEFT,KC_RGHT,KC_LGUI,                      KC_RALT, KC_DOWN, KC_UP,   KC_LEFT,TT(MDIA),TT(SYMB),
                                                KC_TAB, LT(SYMB,KC_HOME), LT(MDIA,KC_END), LT(MDIA,KC_PGDN), LT(SYMB, KC_PGUP), KC_SPC
    ),

    [GAME] = LAYOUT_moonlander(
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,     KC_5,   KC_ESC,     _______,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,       KC_MINS,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,     KC_T,   _______,    KC_ENT,      KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,       KC_BSLS,
        KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,     KC_G,   KC_ENT,     _______,     KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,    KC_QUOT,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,     KC_B,                            KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,    KC_RSFT,
        KC_LCTL,        KC_LALT,      MO(SYMB),KC_LEFT,KC_RGHT, _______,            _______,     KC_DOWN,KC_UP, KC_LEFT,OSL(MDIA),OSL(SYMB),
                                                      KC_SPC, KC_HOME, KC_END,      KC_PGDN, KC_PGUP, KC_SPC
    ),

    [SYMB] = LAYOUT_moonlander(
        VRSN,    KC_F1,     KC_F2,      KC_F3,      KC_F4,    KC_F5,    _______,     _______,KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TAB,  _______,   _______,    _______,    _______,  _______,  _______,     _______,_______, KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
        _______, _______,   _______,    _______,    _______,  _______,  _______,     _______,_______, KC_4,   KC_5,    KC_6,    KC_MINS, KC_SLSH,
        _______, _______,   _______,    _______,    _______,  _______,                       _______, KC_1,   KC_2,    KC_3,    KC_PLUS, _______,
        _______, _______,   _______,    _______,    _______,  RGB_MOD,                       RGB_TOG, KC_0,   KC_COMM, KC_DOT,  KC_EQL,  _______,
                                               RGB_HUI,  RGB_VAI,   RGB_SPI,     TOGGLE_LAYER_COLOR,_______, _______
    ),

    [MDIA] = LAYOUT_moonlander(
        EPRM,    _______, _______, _______, _______, _______, QK_BOOT,      KC_PSCR, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_MS_U, _______, _______, _______,      _______, _______, KC_HOME, KC_UP,   KC_PGUP, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,      _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,_______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                        _______, KC_END,  _______, KC_PGDN, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2, _______,                        _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV, KC_MNXT,
                                        _______, _______, _______,      _______, _______, _______
    ),
};

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (layer_state_is(GAME)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(16, 0x00, 0xC0, 0x50);  // E
        RGB_MATRIX_INDICATOR_SET_COLOR(12, 0x00, 0xC0, 0x50);  // S
        RGB_MATRIX_INDICATOR_SET_COLOR(17, 0x00, 0xC0, 0x50);  // D
        RGB_MATRIX_INDICATOR_SET_COLOR(22, 0x00, 0xC0, 0x50);  // F
        RGB_MATRIX_INDICATOR_SET_COLOR(32, 0x00, 0xC0, 0x50);  // Left thumb cluster
        RGB_MATRIX_INDICATOR_SET_COLOR(33, 0x00, 0xC0, 0x50);  //
        RGB_MATRIX_INDICATOR_SET_COLOR(34, 0x00, 0xC0, 0x50);  //
        RGB_MATRIX_INDICATOR_SET_COLOR(35, 0x00, 0xC0, 0x50);  //
    }
    if (layer_state_is(SYMB)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(5,  0xFF, 0x00, 0x7F);  // 1
        RGB_MATRIX_INDICATOR_SET_COLOR(10, 0xFF, 0x00, 0x7F);  // 2
        RGB_MATRIX_INDICATOR_SET_COLOR(15, 0xFF, 0x00, 0x7F);  // 3
        RGB_MATRIX_INDICATOR_SET_COLOR(20, 0xFF, 0x00, 0x7F);  // 4
        RGB_MATRIX_INDICATOR_SET_COLOR(25, 0xFF, 0x00, 0x7F);  // 5
        RGB_MATRIX_INDICATOR_SET_COLOR(41, 0xFF, 0x00, 0x7F);  // 0
        RGB_MATRIX_INDICATOR_SET_COLOR(46, 0xFF, 0x00, 0x7F);  // 9
        RGB_MATRIX_INDICATOR_SET_COLOR(51, 0xFF, 0x00, 0x7F);  // 8
        RGB_MATRIX_INDICATOR_SET_COLOR(56, 0xFF, 0x00, 0x7F);  // 7
        RGB_MATRIX_INDICATOR_SET_COLOR(61, 0xFF, 0x00, 0x7F);  // 6
    }

    // if (userspace_config.rgb_layer_change) {
    //     switch (get_highest_layer(layer_state|default_layer_state)) {
    //         case _QWERTY:
    //             rgb_matrix_layer_helper(HSV_CYAN, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min, led_max);
    //             break;
    //         case _COLEMAK:
    //             rgb_matrix_layer_helper(HSV_MAGENTA, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min, led_max);
    //             break;
    //         case _DVORAK:
    //             rgb_matrix_layer_helper(HSV_SPRINGGREEN, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min, led_max);
    //             break;
    //         case _WORKMAN:
    //             rgb_matrix_layer_helper(HSV_GOLDENROD, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min, led_max);
    //             break;
    //         case _NORMAN:
    //             rgb_matrix_layer_helper(HSV_CORAL, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min, led_max);
    //             break;
    //         case _MALTRON:
    //             rgb_matrix_layer_helper(HSV_YELLOW, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min, led_max);
    //             break;
    //         case _EUCALYN:
    //             rgb_matrix_layer_helper(HSV_PINK, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min, led_max);
    //             break;
    //         case _CARPLAX:
    //             rgb_matrix_layer_helper(HSV_BLUE, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min, led_max);
    //             break;
    //         case _GAMEPAD:
    //             rgb_matrix_layer_helper(HSV_ORANGE, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min, led_max);
    //             break;
    //         case _DIABLO:
    //             rgb_matrix_layer_helper(HSV_RED, 1, rgb_matrix_config.speed * 8, LED_FLAG_MODIFIER, led_min, led_max);
    //             break;
    //         case _RAISE:
    //             rgb_matrix_layer_helper(HSV_YELLOW, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min, led_max);
    //             break;
    //         case _LOWER:
    //             rgb_matrix_layer_helper(HSV_GREEN, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min, led_max);
    //             break;
    //         case _ADJUST:
    //             rgb_matrix_layer_helper(HSV_RED, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min, led_max);
    //             break;
    //     }
    // }
    return false;
}
#endif


void dance_lyr_finished(tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1) {
        if (layer_state_is(0)) {
            layer_on(SYMB);
        } else {
            layer_clear();
        }
    } else if (state->count == 2) {
        layer_on(GAME);
        combo_disable();
    } else if (state->count == 3) {
        layer_on(COLEMAK);
    }
}

void dance_lyr_reset(tap_dance_state_t *state, void *user_data)
{}

tap_dance_action_t tap_dance_actions[] = {
    [DLFT] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LPRN),
    [DRGHT] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RPRN),
    // Set the active layer with a tap dance.
    [DLAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lyr_finished, dance_lyr_reset)
};

void keyboard_post_init_user(void) {
    // disable combos by default
    combo_disable();
}

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
    }
    return true;
}
