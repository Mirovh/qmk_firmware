/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"
#include "features/custom_shift_keys.h"
#include "keymap_belgian.h"      // brings in FR_* aliases

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
};

const custom_shift_key_t custom_shift_keys[] = {
    {BE_AT, BE_TILD},
    {BE_ASTR, BE_0},
    {BE_DLR, BE_1},
    {BE_DCIR, BE_6},
    {BE_BSLS, BE_9},
    {BE_SCLN, BE_COLN},
    {BE_COMM, BE_LABK},
    {BE_DOT, BE_RABK},
    {BE_SLSH, BE_QUES},
    {BE_AMPR, BE_PIPE},
    {BE_LCBR, BE_LBRC},
    {BE_RCBR, BE_RBRC},
    {BE_HASH, BE_PERC},
    {BE_RPRN, BE_DIAE},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [MAC_BASE] = LAYOUT_iso_83(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,                      KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,             KC_HOME,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD,MO(MAC_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_iso_83(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_END,
        _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_iso_83(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,             KC_MUTE,
        BE_AT,   BE_DLR,     BE_EACU,     BE_DQUO,     BE_QUOT,     BE_LPRN,     BE_DCIR,     BE_EGRV,     BE_EXLM,     BE_BSLS,     BE_ASTR,     BE_RPRN,  BE_HASH,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     BE_LCBR,  BE_RCBR,                      KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  BE_AMPR,  BE_MINS,  KC_ENT,             KC_HOME,
        KC_LSFT,  BE_SCLN,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     BE_COMM,     BE_DOT,  BE_SLSH,   BE_EQL,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_iso_83(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_END,
        _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______)

};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }

    if ((keycode == BE_DCIR) & (record->event.pressed)) {
        // If Alt is held, let the OS see the dead-key as usual
        // Otherwise, send a plain '^' and consume the key
        if (get_mods() & (MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT))) {
            // Clear all modifiers to prevent interference
            // 1) Save the full mods (including Alt)
            uint8_t saved_mods = get_mods();
            // 2) Clear mods
            tap_code(KC_F16); //null tap to avoid seeing alt release as a tap
            clear_mods();
            // 3) Actual dead circonflex tap
            tap_code(BE_DCIR);
            // 4) Restore mods
            set_mods(saved_mods);
            tap_code(KC_F16); //null tap to avoid seeing next release as alt tap
            return false;
        } else {
            // 1) Ctrl+Shift+U to start Unicode hex input (LINUX ONLY)
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            tap_code(KC_U);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);

            // 2) Type 005E (hex for U+005E = ^)
            SEND_STRING("005E");
            return false;
        }
    }

    if ((keycode == BE_HASH) & (record->event.pressed)) {
        // If Alt is held, send degree symbol
        // Otherwise, pass on
        if (get_mods() & (MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT))) {
            // Clear all modifiers to prevent interference
            // 1) Save the full mods (including Alt)
            uint8_t saved_mods = get_mods();
            // 2) Clear mods
            tap_code(KC_F16); //null tap to avoid seeing alt release as a tap
            clear_mods();
            // 3) Actual symbol
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            tap_code(KC_U);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            // what follows is just B0, the unicode for °
            tap_code(BE_B);
            register_code(KC_LSFT);
            tap_code(BE_AGRV); 
            unregister_code(KC_LSFT);
            // 4) Restore mods
            set_mods(saved_mods);
            tap_code(KC_F16); //null tap to avoid seeing next release as alt tap
            return false;
        }
    }

    if ((keycode == BE_AMPR) & (record->event.pressed)) {
        // If Alt is held, send backtick symbol
        // Otherwise, pass on
        if (get_mods() & (MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT))) {
            // Clear all modifiers to prevent interference
            // 1) Save the full mods (including Alt)
            uint8_t saved_mods = get_mods();
            // 2) Clear mods
            tap_code(KC_F16); //null tap to avoid seeing alt release as a tap
            clear_mods();
            // 3) Actual symbol
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            tap_code(KC_U);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            SEND_STRING("0060");
            tap_code(KC_ENT);
            // 4) Restore mods
            set_mods(saved_mods);
            tap_code(KC_F16); //null tap to avoid seeing next release as alt tap
            return false;
        }
    }

    if ((keycode == BE_MINS) & (record->event.pressed)) {
        // If Alt is held, send accent
        // Otherwise, pass on
        if (get_mods() & (MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT))) {
            // Clear all modifiers to prevent interference
            // 1) Save the full mods (including Alt)
            uint8_t saved_mods = get_mods();
            // 2) Clear mods
            tap_code(KC_F16); //null tap to avoid seeing alt release as a tap
            clear_mods();
            // 3) Actual symbol
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            tap_code(KC_U);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            SEND_STRING("0301");
            tap_code(KC_ENT);
            // 4) Restore mods
            set_mods(saved_mods);
            tap_code(KC_F16); //null tap to avoid seeing next release as alt tap
            return false;
        }
    }
    
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

