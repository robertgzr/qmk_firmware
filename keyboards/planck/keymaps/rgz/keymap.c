// vim: fdm=marker

/* Copyright 2015-2017 Jack Humbert
 *           2019-2020 Robert Günzler
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

extern keymap_config_t keymap_config;

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT,
};

/* tap dance declarations */
enum {
    W15 = 0,
    W26,
    W37,
    W48,
};

/* tap dance definitions */
qk_tap_dance_action_t tap_dance_actions[] = {
    [W15] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_1), LGUI(KC_5)),
    [W26] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_2), LGUI(KC_6)),
    [W37] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_3), LGUI(KC_7)),
    [W48] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_4), LGUI(KC_8)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base => Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |GUI/Ec|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Sft/En|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GUI  | Ctrl | Alt  |      |Lower |    Space    |Raise |      | Alt  | Ctrl |GUI/En|
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_mit(
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    LGUI_ESC, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, RSFT_ENTER,
    KC_LGUI,  KC_LCTL, KC_LALT, _______, LOWER,     KC_SPC,     RAISE, _______, KC_RALT, KC_RCTL, RGUI_ENTER
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   `  |   ~  |   \  |   |  |  (   |   )  |   7  |   8  |   9  |   /  |Bkspc |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |  {   |   }  |   4  |   5  |   6  |   *  |  +   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   %  |   ^  |   &  |   _  |  [   |   ]  |   1  |   2  |   3  |   -  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | -*-  |      :      | -*-  |  0   |   .  |   ,  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
    _______, KC_GRV,  KC_TILD, KC_BSLS, KC_PIPE, KC_LPRN, KC_RPRN, KC_7,    KC_8, KC_9,   KC_SLSH, KC_BSPC,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_LCBR, KC_RCBR, KC_4,    KC_5, KC_6,   KC_ASTR, KC_PLUS,
    _______, KC_PERC, KC_CIRC, KC_AMPR, KC_UNDS, KC_LBRC, KC_RBRC, KC_1,    KC_2, KC_3,   KC_MINS, KC_EQL,
    _______, _______, _______, _______, _______,      KC_COLN,     _______, KC_0, KC_DOT, KC_COMM, XXXXXXX
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | W1/5 | W2/6 | W3/7 | W4/8 |      | Left | Down |  Up  |Right |      |S+Ins |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | BRIU |      |      |      |      |      |      |Pg Dn |Pg Up | Mute |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BRID |      |      |      | -*-  |             | -*-  | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
      KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_DEL,
    _______, TD(W15), TD(W26), TD(W37), TD(W48), XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, S(KC_INS),
    KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, KC_MUTE, XXXXXXX, XXXXXXX,
    KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, _______,      _______,     _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset| Debug|RgbTgl|RgbCyc|RgbHuI|RgbHuD|RgbSaI|RgbSaD|RgbVaI|RgbVaD|  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |MusCyc|Aud on|Audoff|      |      | Base |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | -*-  |             | -*-  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    XXXXXXX, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
    XXXXXXX, XXXXXXX, MU_MOD,  AU_ON,   AU_OFF,  XXXXXXX, XXXXXXX, BASE,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,      XXXXXXX,     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) { // {{{
    palClearPad(GPIOB, 8);
    palClearPad(GPIOB, 9);
    uint8_t layer = biton32(state);
    switch (layer) {
        case _LOWER:
            palSetPad(GPIOB, 9);
            break;
        case _RAISE:
            palSetPad(GPIOB, 8);
            break;
        case _ADJUST:
            palSetPad(GPIOB, 9);
            palSetPad(GPIOB, 8);
            break;
        default:
            break;
    }
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
} // }}}

bool process_record_user(uint16_t keycode, keyrecord_t *record) { // {{{
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_BASE);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
  }
  return true;
} // }}}

bool music_mask_user(uint16_t keycode) { // {{{
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
} // }}}
