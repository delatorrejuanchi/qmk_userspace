#include QMK_KEYBOARD_H

enum layers {
    LAYER_MAIN,
    LAYER_SYMBOL,
    LAYER_NAV,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_MAIN] = LAYOUT_voyager(
        _______,         _______, _______, _______,       _______,      _______, _______, _______, _______, _______, _______, _______,
        _______,         KC_X,    KC_W,    KC_M,          KC_G,         KC_J,    _______, _______, _______, _______, _______, _______,
        KC_ESC,          KC_S,    KC_C,    KC_N,          KC_T,         KC_K,    _______, KC_A,    KC_E,    KC_I,    KC_H,    KC_ENT,
        KC_Z,            KC_B,    KC_P,    KC_L,          KC_D,         KC_V,    _______, KC_U,    KC_O,    KC_Y,    KC_F,    KC_Q,
        LT(LAYER_SYMBOL, KC_R),   KC_BSPC, OSM(MOD_RSFT), LT(LAYER_NAV, KC_SPACE)
    ),
    [LAYER_SYMBOL] = LAYOUT_voyager(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_SLSH, KC_LBRC, KC_LCBR, KC_LPRN, _______, _______, QK_AREP, KC_COLN, _______, _______, _______,
        _______, KC_GRV,  KC_PERC, KC_AMPR, KC_ASTR, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______
    ),
    [LAYER_NAV] = LAYOUT_voyager(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    KC_8,    KC_0,    KC_2,    KC_4,    KC_6,    _______,
        _______, _______, _______, _______
    ),
};
// clang-format on

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_LEFT_PAREN:
            return KC_RIGHT_PAREN;
        case KC_LEFT_CURLY_BRACE:
            return KC_RIGHT_CURLY_BRACE;
        case KC_LEFT_BRACKET:
            return KC_RIGHT_BRACKET;
        case KC_LEFT_ANGLE_BRACKET:
            return KC_RIGHT_ANGLE_BRACKET;
        case KC_QUOTE:
            return KC_QUOTE;
        case KC_DOUBLE_QUOTE:
            return KC_DOUBLE_QUOTE;
    }

    return KC_KP_EQUAL;
}

#ifdef COMBO_ENABLE
enum combos {
    COMBO_Z,
    COMBO_QU,
    COMBO_TH,
    COMBO_CH,
    COMBO_SH,
    COMBO_WH,
    COMBO_GH,
    COMBO_PH,
    COMBO_MEH_1,
    COMBO_MEH_2,

    COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combo_GW[] = {KC_G, KC_W, COMBO_END};
const uint16_t PROGMEM combo_TC[] = {KC_T, KC_C, COMBO_END};
const uint16_t PROGMEM combo_TN[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM combo_CN[] = {KC_C, KC_N, COMBO_END};
const uint16_t PROGMEM combo_SC[] = {KC_S, KC_C, COMBO_END};
const uint16_t PROGMEM combo_WM[] = {KC_W, KC_M, COMBO_END};
const uint16_t PROGMEM combo_GM[] = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM combo_PL[] = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM combo_AE[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM combo_EI[] = {KC_E, KC_I, COMBO_END};

// clang-format off
combo_t key_combos[] = {
    [COMBO_Z] = COMBO_ACTION(combo_GW),
    [COMBO_QU] = COMBO_ACTION(combo_TC),
    [COMBO_TH] = COMBO_ACTION(combo_TN),
    [COMBO_CH] = COMBO_ACTION(combo_CN),
    [COMBO_SH] = COMBO_ACTION(combo_SC),
    [COMBO_WH] = COMBO_ACTION(combo_WM),
    [COMBO_GH] = COMBO_ACTION(combo_GM),
    [COMBO_PH] = COMBO_ACTION(combo_PL),
    [COMBO_MEH_1] = COMBO_ACTION(combo_AE),
    [COMBO_MEH_2] = COMBO_ACTION(combo_EI),
};
// clang-format on

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case COMBO_Z:
            if (pressed) {
                tap_code16(KC_Z);
            }
            break;

        case COMBO_QU:
            if (pressed) {
                tap_code16(KC_Q);
                tap_code16(KC_U);
            }
            break;

        case COMBO_TH:
            if (pressed) {
                tap_code16(KC_T);
                tap_code16(KC_H);
            }
            break;

        case COMBO_CH:
            if (pressed) {
                tap_code16(KC_C);
                tap_code16(KC_H);
            }
            break;

        case COMBO_SH:
            if (pressed) {
                tap_code16(KC_S);
                tap_code16(KC_H);
            }
            break;

        case COMBO_WH:
            if (pressed) {
                tap_code16(KC_W);
                tap_code16(KC_H);
            }
            break;

        case COMBO_GH:
            if (pressed) {
                tap_code16(KC_G);
                tap_code16(KC_H);
            }
            break;

        case COMBO_PH:
            if (pressed) {
                tap_code16(KC_P);
                tap_code16(KC_H);
            }
            break;

        case COMBO_MEH_1:
            if (pressed) {
                tap_code16(MEH(KC_1));
            }
            break;

        case COMBO_MEH_2:
            if (pressed) {
                tap_code16(MEH(KC_2));
            }
            break;
    }
}
#endif
