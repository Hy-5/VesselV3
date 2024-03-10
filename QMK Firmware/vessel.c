// Setting pre init and post init board config

#include "quantum.h"
#include "ws2812.h"

// Setting output pins
void keyboard_pre_init_user(void) {
  setPinOutput(A5); // RGBPIN
}