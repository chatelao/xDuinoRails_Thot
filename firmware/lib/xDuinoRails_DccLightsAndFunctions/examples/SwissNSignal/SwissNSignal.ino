#include <Arduino.h>
#include "LightSources/SwissNSignal.h"

#define NEOPIXEL_PIN 2
#define NUM_PIXELS 1

xDuinoRails::SwissNSignal swissSignal(NEOPIXEL_PIN, NUM_PIXELS);

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
}
