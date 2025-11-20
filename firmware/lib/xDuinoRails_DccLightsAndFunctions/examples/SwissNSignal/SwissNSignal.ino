#include <Arduino.h>
#include "LightSources/SwissNSignal.h"

#define NEOPIXEL_PIN 2
#define NUM_PIXELS 1
const int seven_segment_pins[7] = {10, 11, 12, 13, 14, 15, 16}; // A, B, C, D, E, F, G

xDuinoRails::SwissNSignal swissSignal(NEOPIXEL_PIN, NUM_PIXELS, seven_segment_pins);

void setup() {
  swissSignal.begin();
}

void loop() {
  // Cycle through the signal aspects every 3 seconds
  swissSignal.setAspect(xDuinoRails::N_ASPECT_STOP);
  delay(3000);
  swissSignal.setAspect(xDuinoRails::N_ASPECT_CLEAR);
  delay(3000);
  swissSignal.setAspect(xDuinoRails::N_ASPECT_SPEED_40);
  delay(3000);
  swissSignal.setAspect(xDuinoRails::N_ASPECT_SPEED_60);
  delay(3000);
  swissSignal.setAspect(xDuinoRails::N_ASPECT_SPEED_90);
  delay(3000);
  swissSignal.setAspect(xDuinoRails::N_ASPECT_OBSTRUCTION_AHEAD);
  delay(3000);
  swissSignal.setAspect(xDuinoRails::N_ASPECT_TRACK_OCCUPIED);
  delay(3000);
  swissSignal.setAspect(xDuinoRails::N_ASPECT_PREWARNING);
  delay(3000);
  swissSignal.setAspect(xDuinoRails::N_ASPECT_SPEED_ANNOUNCEMENT_40);
  delay(3000);
  swissSignal.setAspect(xDuinoRails::N_ASPECT_SPEED_ANNOUNCEMENT_60);
  delay(3000);
  swissSignal.setAspect(xDuinoRails::N_ASPECT_SPEED_ANNOUNCEMENT_90);
  delay(3000);
}