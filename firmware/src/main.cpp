/**
 * @file main.cpp
 * @brief Main firmware for the xDuinoRails_Thot signal decoder.
 */
#include <Arduino.h>
#include "SignalManager.h"

SignalManager signalManager;

/**
 * @brief Setup function, called once at startup.
 */
void setup() {
  signalManager.begin();
}

/**
 * @brief Main loop, called repeatedly.
 */
void loop() {
  signalManager.update();

  // Cycle through the signal aspects every 3 seconds
  signalManager.setAspect(HP0);
  delay(3000);
  signalManager.setAspect(KS1);
  delay(3000);
  signalManager.setAspect(KS2);
  delay(3000);
}
