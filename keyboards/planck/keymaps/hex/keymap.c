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
#include QMK_KEYBOARD_H
#include "keymap_steno.h"
#include "muse.h"

enum planck_layers {
  _BASE,
  _NUM,
  _FUNC,
  _ADJUST,
  _PLOVER,
  _MIDI,
};

enum planck_keycodes {
  PLOVER = SAFE_RANGE,
  EXT_PLV,
  MIDI,
  EXT_MIDI,
  DISCO
};

#define FUNC MO(_FUNC)
#define NUM MO(_NUM)
#define C_T_ESC LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_planck_grid(
   KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  C_T_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,
  KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
   KC_ESC, XXXXXXX, KC_LGUI, KC_LALT,    FUNC,  KC_SPC,  KC_SPC,     NUM, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT
),

[_NUM] = LAYOUT_planck_grid(
   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSLS,
  _______, KC_INT1, KC_INT2, KC_INT3, KC_INT4, KC_INT5, _______, KC_LBRC, KC_RBRC, KC_MINS,  KC_EQL, KC_QUOT,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NUBS, KC_NUHS, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

[_FUNC] = LAYOUT_planck_grid(
  KC_CAPS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_PSCR,
  _______,  KC_INS, KC_MUTE, KC_VOLD, KC_VOLU,  KC_BRK, KC_WH_L, KC_BTN3, KC_WH_U,  KC_F11,  KC_F12, _______,
  _______,  KC_APP, KC_MPLY, KC_MPRV, KC_MNXT,  KC_APP, KC_WH_R, _______, KC_WH_D, KC_BTN1, KC_BTN2, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R
),

[_ADJUST] = LAYOUT_planck_grid(
  XXXXXXX, QK_BOOT, DB_TOGG, XXXXXXX,    MIDI,   AU_ON,  AU_OFF, RGB_HUI, RGB_HUD, RGB_MOD,RGB_RMOD, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  MUV_IN,  MUV_DE, RGB_SAI, RGB_SAD, RGB_SPI, RGB_SPD, XXXXXXX,
  XXXXXXX,   PLOVER,  DISCO, XXXXXXX,  MU_MOD,   MU_ON,  MU_OFF, RGB_VAI, RGB_VAD, RGB_TOG, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_PLOVER] = LAYOUT_planck_grid(
   STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
   STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL, STN_ST1, STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  XXXXXXX,  STN_S2,  STN_KL,  STN_WL,  STN_RL, STN_ST2, STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
  EXT_PLV, XXXXXXX, XXXXXXX,   STN_A,   STN_O, XXXXXXX, XXXXXXX,   STN_E,   STN_U, STN_PWR, STN_RE1, STN_RE2
),

[_MIDI] = LAYOUT_planck_grid(
    MI_As,    MI_B,   MI_C1,  MI_Cs1,   MI_D1,  MI_Ds1,   MI_E1,   MI_F1,  MI_Fs1,   MI_G1,  MI_Gs1,   MI_A1,
     MI_F,   MI_Fs,    MI_G,   MI_Gs,    MI_A,   MI_As,    MI_B,   MI_C1,  MI_Cs1,   MI_D1,  MI_Ds1,   MI_E1,
     MI_C,   MI_Cs,    MI_D,   MI_Ds,    MI_E,    MI_F,   MI_Fs,    MI_G,   MI_Gs,    MI_A,   MI_As,    MI_B,
  EXT_MIDI, MI_MOD, MI_MODD, MI_MODU, MI_BNDD, MI_BNDU, MI_TRSD, MI_TRSU, MI_OCTD, MI_OCTU, MI_VELD, MI_VELU
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
  float disco[][2] = SONG(PLATINUM_DISCO);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NUM, _FUNC, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_NUM);
        layer_off(_FUNC);
        layer_off(_ADJUST);
        layer_off(_MIDI);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
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

    case MIDI:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_NUM);
        layer_off(_FUNC);
        layer_off(_ADJUST);
        layer_off(_PLOVER);
        layer_on(_MIDI);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_MIDI:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_MIDI);
      }
      return false;
      break;

    case DISCO:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(disco);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// bool muse_mode = false;
// uint8_t last_muse_note = 0;
// uint16_t muse_counter = 0;
// uint8_t muse_offset = 70;
// uint16_t muse_tempo = 50;

// void matrix_scan_user(void) {
// #ifdef AUDIO_ENABLE
//     if (muse_mode) {
//         if (muse_counter == 0) {
//             uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//             if (muse_note != last_muse_note) {
//                 stop_note(compute_freq_for_midi_note(last_muse_note));
//                 play_note(compute_freq_for_midi_note(muse_note), 0xF);
//                 last_muse_note = muse_note;
//             }
//         }
//         muse_counter = (muse_counter + 1) % muse_tempo;
//     } else {
//         if (muse_counter) {
//             stop_all_notes();
//             muse_counter = 0;
//         }
//     }
// #endif
// }

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case FUNC:
    case NUM:
      return false;
    default:
      return true;
  }
}

RGB rgb_matrix_hsv_to_rgb(HSV hsv) {
  RGB rgb = hsv_to_rgb(hsv);
  uint16_t rr = rgb.r * 19;
  rr /= 32;
  rgb.r = rr;
  return rgb;
}
