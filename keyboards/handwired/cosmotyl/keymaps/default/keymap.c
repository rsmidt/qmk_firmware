// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    VIM_SV = SAFE_RANGE
};

enum layer_names {
    _BASE,
    _NAV,
    _SYM,
    _NUM,
    _FN,
    _HYPR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,         KC_W,         KC_E,             KC_R,         KC_T,                                KC_Y,    KC_U,            KC_I,            KC_O,         KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D),     LSFT_T(KC_F), KC_G,                                KC_H,    RSFT_T(KC_J),    RCTL_T(KC_K),    RALT_T(KC_L), RGUI_T(KC_SCLN),
        KC_Z,         KC_X,         KC_C,             KC_V,         KC_B,                                KC_N,    KC_M,            KC_COMM,         KC_DOT,       LT(1, KC_SLSH),
                                    LT(_NAV, KC_SPC), MO(_NUM),     LM(_HYPR, MOD_LGUI),                 XXXXXXX, LT(_FN, KC_TAB), LT(_SYM, KC_ENT)
    ),
    [_NAV]  = LAYOUT_split_3x5_3(
        _______, _______, _______, _______, _______,                 KC_HOME, KC_BSPC, KC_DEL,  KC_END,   _______,
        _______, _______, _______, _______, _______,                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,
        _______, _______, _______, _______, _______,                 _______, KC_PGDN, KC_PGUP, _______,  _______,
                          _______, _______, _______,                 KC_INS,  KC_TAB,  _______
    ),
    [_SYM]  = LAYOUT_split_3x5_3(
        KC_ESC,  KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD,                 KC_CIRC, KC_RPRN,          KC_RCBR,        KC_RBRC, KC_GRV,
        KC_MINS, KC_ASTR, KC_EQL,  KC_UNDS, KC_DLR,                  KC_HASH, RSFT_T(KC_QUOTE), RCTL_T(KC_DQT), KC_RALT, _______,
        KC_PLUS, KC_PIPE, KC_AT,   KC_BSLS, KC_PERC,                 XXXXXXX, KC_AMPR,          KC_SCLN,        KC_COLN, KC_EXLM,
                          _______, _______, _______,                 _______, _______,          _______
    ),
    [_NUM]  = LAYOUT_split_3x5_3(
        QK_BOOT, _______, _______, _______, _______,                 _______, KC_7,         KC_8,         KC_9,         _______,
        _______, _______, _______, _______, _______,                 KC_0,    RSFT_T(KC_4), RCTL_T(KC_5), RALT_T(KC_6), _______,
        _______, _______, _______, _______, _______,                 _______, KC_1,         KC_2,         KC_3,         _______,
                          _______, _______, _______,                 _______, _______,      _______
    ),
    [_FN]   = LAYOUT_split_3x5_3(
        KC_F12,         KC_F7,         KC_F8,         KC_F9,         _______,                 _______, KC_VOLD,         KC_VOLU,         _______,         _______,
        LGUI_T(KC_F11), LALT_T(KC_F4), LCTL_T(KC_F5), LSFT_T(KC_F6), _______,                 KC_MPRV, RSFT_T(KC_MPLY), RCTL_T(KC_MUTE), RALT_T(KC_MNXT), _______,
        KC_F10,         KC_F1,         KC_F2,         KC_F3,         _______,                 _______, _______,         _______,         _______,         _______,
                                       _______,       _______,       _______,                 _______, _______,         _______
    ),
    [_HYPR] = LAYOUT_split_3x5_3(
        _______, _______, _______, _______, _______,                 _______, KC_7,    KC_8,   KC_9, _______,
        _______, _______, _______, _______, _______,                 KC_0,    KC_4,    KC_5,   KC_6, _______,
        _______, _______, _______, _______, _______,                 _______, KC_1,    KC_2,   KC_3, _______,
                          _______, _______, _______,                 _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case VIM_SV:
        if (record->event.pressed) {
            SEND_STRING(":w"SS_TAP(X_ENTER));
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM combo_escape[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_bspc[]   = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_del[]    = {KC_I, KC_O, COMBO_END};

const uint16_t PROGMEM combo_vim_sv[]    = {KC_M, KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_escape, KC_ESC),
    COMBO(combo_bspc, KC_BSPC),
    COMBO(combo_del, KC_DEL),
    COMBO(combo_vim_sv, VIM_SV),
};
