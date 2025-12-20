#include <Arduino.h>
#include "LightSources/DutchSignal.h"

#define NEOPIXEL_PIN 2
#define NUM_PIXELS 1

xDuinoRails::DutchSignal dutchSignal(NEOPIXEL_PIN, NUM_PIXELS);

void setup() {
  dutchSignal.begin();
}

void loop() {
  // Cycle through the signal aspects every 3 seconds
  dutchSignal.setAspect(xDuinoRails::NL_ASPECT_STOP);
  delay(3000);
  dutchSignal.setAspect(xDuinoRails::NL_ASPECT_PROCEED);
  delay(3000);
  dutchSignal.setAspect(xDuinoRails::NL_ASPECT_PROCEED_40);
  delay(3000);
  dutchSignal.setAspect(xDuinoRails::NL_ASPECT_SPEED_REDUCTION_40);
  delay(3000);
  dutchSignal.setAspect(xDuinoRails::NL_ASPECT_PROCEED_ON_SIGHT);
  delay(3000);
  dutchSignal.setAspect(xDuinoRails::NL_ASPECT_STOP_OUT_OF_ORDER);
  delay(3000);
}
