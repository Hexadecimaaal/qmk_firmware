#include QMK_KEYBOARD_H

#define HOME 0
#define MODIFIER 1

enum custom_keycodes {
	MACRO1 = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch (keycode) {

		}
	}
	return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[HOME] = LAYOUT(
         KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,     KC_0, KC_MINS, KC_EQL,   KC_BSPC, KC_HOME,
         KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,     KC_P, KC_LBRC, KC_RBRC,  KC_BSLS, KC_END,
        KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, KC_QUOT,     KC_ENT,        KC_PGUP,
        KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT,KC_SLSH,      KC_RSFT,      KC_UP,   KC_PGDN,
        KC_CAPS,MO(MODIFIER),KC_LGUI,KC_LALT,                    KC_SPC,                            KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [MODIFIER] = LAYOUT(
        KC_GRAVE,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,  KC_F12,   RESET,    KC_TRNS,
        KC_TRNS,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,     KC_P, KC_LBRC, KC_RBRC,  KC_BSLS,  KC_TRNS,
        KC_TRNS,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, KC_QUOT,     KC_ENT,         KC_TRNS,
        KC_TRNS,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT,KC_SLSH,      KC_TRNS,       KC_UP,   KC_TRNS,
        KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,                    KC_SPC,                             KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT
    )
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}
