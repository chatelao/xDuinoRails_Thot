#include <Arduino.h>
#include "LightSources/ItalianSignal.h"

#define NEOPIXEL_PIN 2
#define NUM_PIXELS 1

xDuinoRails::ItalianSignal italianSignal(NEOPIXEL_PIN, NUM_PIXELS);

void setup() {
  italianSignal.begin();
}

void loop() {
  // Cycle through the signal aspects every 3 seconds
  italianSignal.setAspect(xDuinoRails::IT_ASPECT_STOP);
  delay(3000);
  italianSignal.setAspect(xDuinoRails::IT_ASPECT_PROCEED);
  delay(3000);
  italianSignal.setAspect(xDuinoRails::IT_ASPECT_PROCEED_SLOW);
  delay(3000);
  italianSignal.setAspect(xDuinoRails::IT_ASPECT_PROCEED_100);
  delay(3000);
  italianSignal.setAspect(xDuinoRails::IT_ASPECT_PROCEED_60);
  delay(3000);
  italianSignal.setAspect(xDuinoRails::IT_ASPECT_PROCEED_30);
  delay(3000);
  italianSignal.setAspect(xDuinoRails::IT_ASPECT_EXPECT_STOP);
  delay(3000);
  italianSignal.setAspect(xDuinoRails::IT_ASPECT_EXPECT_STOP_ADVANCE);
  delay(3000);
  italianSignal.setAspect(xDuinoRails::IT_ASPECT_PROCEED_CAUTION);
  delay(3000);
}
