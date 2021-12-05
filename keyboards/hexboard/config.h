#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Hexadecimaaal
#define PRODUCT         Hexboard
#define DESCRIPTION     QMK Hexboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/* key matrix pins */
#define MATRIX_ROW_PINS { D2, D3, C6, C7, D5 }
#define MATRIX_COL_PINS { E6, F7, D0, F6, B7, F5, B3, F4, B2, F1, B1, F0, B0, B6, D1 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

// #ifdef BACKLIGHT_PIN
// #define BACKLIGHT_LEVELS 3
// #endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

// #define RGB_DI_PIN F4
// #ifdef RGB_DI_PIN
// #define RGBLIGHT_ANIMATIONS
// #define RGBLED_NUM 5
// #define RGBLIGHT_HUE_STEP 8
// #define RGBLIGHT_SAT_STEP 8
// #define RGBLIGHT_VAL_STEP 8
// #endif

#endif
