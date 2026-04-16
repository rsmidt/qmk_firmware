// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NAV,
    _NUM,
    _FN
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,         KC_W,         KC_E,             KC_R,         KC_T,                   KC_Y,   KC_U,         KC_I,         KC_O,         KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D),     LSFT_T(KC_F), KC_G,                   KC_H,   RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
        KC_Z,         KC_X,         KC_C,             KC_V,         KC_B,                   KC_N,   KC_M,         KC_COMM,      KC_DOT,       LT(1, KC_SLSH),
                                    LT(_NAV, KC_SPC), MO(_NUM),     XXXXXX,                 XXXXXX, LT(),         KC_RGUI
    ),
    [_NAV] = LAYOUT_split_3x5_3(
        _______, _______, _______, _______, _______,                 KC_HOME, _______, _______, KC_END,   _______,
        _______, _______, _______, _______, _______,                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,
        _______, _______, _______, _______, _______,                 _______, KC_PGDN, KC_PGUP, _______,  _______,
                          _______, _______, _______,                 _______, _______, _______
    ),
    [_NUM] = LAYOUT_split_3x5_3(
        QK_BOOT, _______, _______, _______, _______,                 _______, KC_7,         KC_8,         KC_9,         _______,
        _______, _______, _______, _______, _______,                 KC_0,    RSFT_T(KC_4), RCTL_T(KC_5), RALT_T(KC_6), _______,
        _______, _______, _______, _______, _______,                 _______, KC_1,         KC_2,         KC_3,         _______,
                          _______, _______, _______,                 _______, _______,      _______
    ),
    [_FN] = LAYOUT_split_3x5_3(
        KC_F12,         KC_F7,         KC_F8,         KC_F9,         _______,                 _______, KC_VOLD,         KC_VOLU,         _______,         _______,
        LGUI_T(KC_F11), LALT_T(KC_F4), LCTL_T(KC_F5), LSFT_T(KC_F6), _______,                 KC_MPRV, RSFT_T(KC_MPLY), RCTL_T(KC_MUTE), RALT_T(KC_MNXT), _______,
        KC_F10,         KC_F1,         KC_F2,         KC_F3,         _______,                 _______, _______,         _______,         _______,         _______,
                                       _______,       _______,       _______,                 _______, _______,         _______
    ),
};

const uint16_t PROGMEM combo_we_escape[] = {KC_W, KC_E, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_we_escape, KC_ESC)
};
