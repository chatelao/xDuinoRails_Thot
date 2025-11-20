#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "LightSources/SwissLSignal.h"

#define NEOPIXEL_PIN 2
#define NUM_PIXELS 3

xDuinoRails::SwissLSignal signal(NEOPIXEL_PIN, NUM_PIXELS);

void setup() {
  signal.begin();
  signal.setLevel(50);
}

void loop() {
  signal.setAspect(xDuinoRails::L_ASPECT_STOP);
  delay(2000);
  signal.setAspect(xDuinoRails::L_ASPECT_CLEAR);
  delay(2000);
  signal.setAspect(xDuinoRails::L_ASPECT_SPEED_40);
  delay(2000);
  signal.setAspect(xDuinoRails::L_ASPECT_SPEED_60);
  delay(2000);
  signal.setAspect(xDuinoRails::L_ASPECT_SPEED_90);
  delay(2000);
  signal.setAspect(xDuinoRails::L_ASPECT_SHORT_PROCEED);
  delay(2000);
}