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
  signalManager.setAspect(xDuinoRails::N_ASPECT_STOP);
  delay(3000);
  signalManager.setAspect(xDuinoRails::N_ASPECT_CLEAR);
  delay(3000);
  signalManager.setAspect(xDuinoRails::N_ASPECT_SPEED_40);
  delay(3000);
  signalManager.setAspect(xDuinoRails::N_ASPECT_SPEED_60);
  delay(3000);
  signalManager.setAspect(xDuinoRails::N_ASPECT_SPEED_90);
  delay(3000);
  signalManager.setAspect(xDuinoRails::N_ASPECT_OBSTRUCTION_AHEAD);
  delay(3000);
  signalManager.setAspect(xDuinoRails::N_ASPECT_TRACK_OCCUPIED);
  delay(3000);
  signalManager.setAspect(xDuinoRails::N_ASPECT_PREWARNING);
  delay(3000);
}
