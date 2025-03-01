#pragma once
#include "quantum.h"

typedef union {
  uint32_t raw;
  struct {
    bool read : 1;
    bool upside_down : 1;
  };
} user_config_t;

user_config_t user_config;

user_config_t read_user_config(void);
void update_user_config(user_config_t);

void toggle_upside_down(void);
