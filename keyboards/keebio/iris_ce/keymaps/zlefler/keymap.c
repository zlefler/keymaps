// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers { _QWERTY, _LOWER, _RAISE };

const uint16_t PROGMEM enter_combo[] = {KC_K, KC_L, COMBO_END};
combo_t                key_combos[]  = {
    COMBO(enter_combo, KC_ENT),

};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            QK_GESC,  KC_1,     KC_2,   KC_3,   KC_4,     KC_5,                               KC_6,     KC_7,   KC_8,    KC_9,    KC_0,   KC_MINUS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            CW_TOGG,  KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_LSFT, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,     KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             KC_LSFT, KC_Z,     KC_X,   KC_C,     KC_V,    KC_B,   KC_HOME,          KC_END, KC_N,      KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            KC_LGUI, TL_LOWR, LCTL(KC_TAB),               KC_BSPC, LT(2, KC_SPC), KC_RALT
        //                                  └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_LOWER] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_TILD, KC_EXLM,  KC_AT,  KC_HASH, KC_DLR, KC_PERC,                             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_GRV,  KC_EXLM,  KC_AT,  KC_LBRC, KC_RBRC, _______,                            _______, KC_P7,    KC_P8,   KC_P9,  KC_P0,   KC_PGDN,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_DEL,  KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_LBRC,                            KC_RBRC,  KC_P4,   KC_P5,   KC_P6,  KC_PLUS, KC_PIPE,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            RGB_MOD, EE_CLR,  _______, KC_LCBR, KC_RCBR, KC_LCBR, KC_LPRN,          KC_RPRN, KC_RCBR, KC_P1,    KC_P2,  KC_P3,    KC_MINS, _______,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                                 _______, _______, KC_DEL,                     KC_DEL, _______, KC_P0
        //                                      └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_RAISE] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_F12,  KC_F1,   KC_F2,   KC_F3,    KC_F4,  KC_F5,                               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            RGB_TOG, RGB_M_K, KC_VOLD, KC_VOLU, KC_MUTE, KC_PERC,                            KC_CIRC, KC_HOME,  KC_UP,  KC_END,  KC_RPRN, QK_BOOT,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            RGB_MOD, RGB_HUI, RGB_VAI, RGB_SPI, KC_MPRV, KC_MNXT,                            KC_EQL,  KC_LEFT, KC_DOWN, KC_RGHT, RCS_T(KC_TRNS), KC_BSLS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            RGB_RMOD, RGB_HUD, RGB_VAD, RGB_SPD, KC_MPLY, KC_LPRN, _______,         KC_PLUS, KC_END, RGB_HUD, RGB_SAD,  RGB_VAD, EE_CLR, _______,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                             _______, _______, _______,                   _______, _______, _______
                                         // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        )};
