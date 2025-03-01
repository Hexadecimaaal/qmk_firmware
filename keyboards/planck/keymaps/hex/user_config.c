#include "user_config.h"
#include "eeconfig.h"
#include "keycode.h"
#include "action_code.h"
#include "keymap_introspection.h"

user_config_t user_config = { .raw = 0 };

uint16_t keycode_at_keymap_location(uint8_t layer_num, uint8_t row, uint8_t column) {
  (void) read_user_config();

  if (user_config.upside_down) {
    return keycode_at_keymap_location_raw(layer_num, MATRIX_ROWS - row - 1, MATRIX_COLS - column - 1);
  } else {
    return keycode_at_keymap_location_raw(layer_num, row, column);
  }
}

user_config_t read_user_config(void) {
  if (!user_config.read) {
    if (!eeconfig_is_enabled()) {
      eeconfig_init();
    }
    user_config.raw = eeconfig_read_user();
    user_config.read = 1;
    eeconfig_update_user(user_config.raw);
  }
  return user_config;
}

void update_user_config(user_config_t cfg) {
  if (cfg.raw != user_config.raw) {
    if (!eeconfig_is_enabled()) {
      eeconfig_init();
    }
    cfg.read = 1;
    eeconfig_update_user(cfg.raw);
    user_config = cfg;
  }
}

void toggle_upside_down(void) {
  user_config_t curr = read_user_config();
  curr.upside_down = !curr.upside_down;
  update_user_config(curr);
}
