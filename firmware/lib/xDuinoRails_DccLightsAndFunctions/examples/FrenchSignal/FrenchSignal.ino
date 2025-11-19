#include <Arduino.h>
#include "LightSources/FrenchSignal.h"

#define NEOPIXEL_PIN 2
#define NUM_PIXELS 1

xDuinoRails::FrenchSignal frenchSignal(NEOPIXEL_PIN, NUM_PIXELS);

void setup() {
  frenchSignal.begin();
}

void loop() {
  // Cycle through the signal aspects every 3 seconds
  frenchSignal.setAspect(xDuinoRails::FR_ASPECT_STOP);
  delay(3000);
  frenchSignal.setAspect(xDuinoRails::FR_ASPECT_PROCEED);
  delay(3000);
  frenchSignal.setAspect(xDuinoRails::FR_ASPECT_STOP_PERMISSIVE);
  delay(3000);
  frenchSignal.setAspect(xDuinoRails::FR_ASPECT_PROCEED_SLOW_30);
  delay(3000);
  frenchSignal.setAspect(xDuinoRails::FR_ASPECT_PROCEED_SLOW_60);
  delay(3000);
  frenchSignal.setAspect(xDuinoRails::FR_ASPECT_EXPECT_STOP);
  delay(3000);
  frenchSignal.setAspect(xDuinoRails::FR_ASPECT_EXPECT_STOP_SHORT);
  delay(3000);
  frenchSignal.setAspect(xDuinoRails::FR_ASPECT_SLOW_30_REMINDER);
  delay(3000);
  frenchSignal.setAspect(xDuinoRails::FR_ASPECT_SLOW_60_REMINDER);
  delay(3000);
  frenchSignal.setAspect(xDuinoRails::FR_ASPECT_SHUNTING_PROCEED);
  delay(3000);
}
