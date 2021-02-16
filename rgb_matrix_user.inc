// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(my_cool_effect)
RGB_MATRIX_EFFECT(my_cool)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e.g: A simple effect, self-contained within a single method
static bool my_cool_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max / 2; i++) {
    rgb_matrix_set_color(i, 0xff, 0x00, 0xff);
  }
  
  for (uint8_t i = led_max / 2 - 1; i < led_max; i++) {
    rgb_matrix_set_color(i, 0x00, 0xff, 0xff);
  }
  
  return led_max < DRIVER_LED_TOTAL;
}

static bool my_cool(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max / 2; i++) {
    rgb_matrix_set_color(i, 0xff, 0xff, 0x00);
  }
  
  for (uint8_t i = led_max / 2 - 1; i < led_max; i++) {
    rgb_matrix_set_color(i, 0x00, 0xff, 0xff);
  }
  
  return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS