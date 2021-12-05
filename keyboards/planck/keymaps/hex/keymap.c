/* Copyright 2015-2017 Jack Humbert
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

// #pragma message "You may need to add LAYOUT_planck_grid to your keymap layers - see default for an example"
#include "planck.h"
#include "action_layer.h"
#include "keymap_steno.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _BASE,
  _PLOVER,
  _NUMBERS,
  _FUNCTION,
  _ADJUST
};

enum planck_keycodes {
  BASE = SAFE_RANGE,
  PLOVER,
  EXT_PLV,
  NUMBERS,
  FUNCTION,
  NAVIGATE
};

bool bnumlock = false;
bool numlock_changed = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_planck_1x2uC(
   KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,
  KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,   KC_UP, KC_RSFT,
  MOD_MEH,NAVIGATE,MOD_HYPR,FUNCTION, KC_LALT,           KC_SPC, NUMBERS, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
),

[_NUMBERS] = LAYOUT_planck_1x2uC(
   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_P7,   KC_P8,   KC_P9,    KC_0, KC_BSLS,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC,   KC_P4,   KC_P5,   KC_P6, KC_MINS,  KC_EQL,
  _______, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN,   KC_P1,   KC_P2,   KC_P3, KC_SLSH, _______,
  _______, _______, _______, _______, _______,          KC_QUOT, _______,   KC_P0,    KC_7,    KC_8,    KC_9
),

[_FUNCTION] = LAYOUT_planck_1x2uC(
   KC_ESC,  KC_DEL, KC_MPRV, KC_MPLY, KC_MNXT, KC_SLCK, KC_WH_U,   KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F12,
  _______,  KC_INS, KC_MUTE, KC_VOLD, KC_VOLU,  KC_BRK, KC_BTN3,   KC_F4,   KC_F5,  KC_F6,   KC_F11, KC_BTN2,
  _______, KC_PSCR, KC_MRWD, KC_MPLY, KC_MFFD,  KC_APP, KC_WH_D,   KC_F1,   KC_F2,  KC_F3,  KC_MS_U, KC_BTN1,
  _______, _______, _______, _______, _______,          KC_DEL, _______, _______, KC_MS_L,  KC_MS_D, KC_MS_R
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  FN  |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |      |      |   E  |   U  |  PWR | RES1 | RES2 |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = LAYOUT_planck_1x2uC(
  STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
  STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
  EXT_PLV, XXXXXXX, XXXXXXX, STN_A,   STN_O,            XXXXXXX, STN_E,   STN_U,   STN_PWR, STN_RE1, STN_RE2
),

[_ADJUST] = LAYOUT_planck_1x2uC(
  XXXXXXX,   RESET,  PLOVER, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX,  AU_TOG, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAD, RGB_VAI, RGB_SPD, RGB_SPI, XXXXXXX,
  XXXXXXX,  MUV_DE,  MUV_IN,  MU_TOG,  MU_MOD, XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

void led_set_kb(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_NUM_LOCK)) {
        bnumlock = true;
    } else {
        bnumlock = false;
    }

    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        register_code(KC_CAPS);
        unregister_code(KC_CAPS);
    }
}

uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, _NUMBERS, _FUNCTION, _ADJUST);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NUMBERS:
      if (record->event.pressed) {
        if(!bnumlock) {
            numlock_changed = true;
            register_code(KC_NLCK);
            unregister_code(KC_NLCK);
        }
        layer_on(_NUMBERS);
      } else {
        if(bnumlock && numlock_changed) {
            numlock_changed = false;
            register_code(KC_NLCK);
            unregister_code(KC_NLCK);
        }
        layer_off(_NUMBERS);
      }
    break;
    case FUNCTION:
      if (record->event.pressed) {
        layer_on(_FUNCTION);
      } else {
        layer_off(_FUNCTION);
      }
      return false;
      break;
    case PLOVER:
      if (!record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_on(_PLOVER);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI);
}
