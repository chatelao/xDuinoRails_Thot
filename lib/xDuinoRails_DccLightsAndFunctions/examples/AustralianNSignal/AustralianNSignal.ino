#include <Arduino.h>
#include "LightSources/AustralianNSignal.h"

#define NEOPIXEL_PIN 2
#define NUM_PIXELS 1

xDuinoRails::AustralianNSignal australianSignal(NEOPIXEL_PIN, NUM_PIXELS);

void setup() {
  australianSignal.begin();
}

void loop() {
  // Cycle through the signal aspects every 3 seconds
  australianSignal.setAspect(xDuinoRails::AU_NSW_ASPECT_STOP);
  delay(3000);
  australianSignal.setAspect(xDuinoRails::AU_NSW_ASPECT_CAUTION);
  delay(3000);
  australianSignal.setAspect(xDuinoRails::AU_NSW_ASPECT_MEDIUM);
  delay(3000);
  australianSignal.setAspect(xDuinoRails::AU_NSW_ASPECT_CLEAR);
  delay(3000);
}
