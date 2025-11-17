/**
 * @file SignalManager.h
 * @brief Manages the signal aspects and their corresponding LED outputs.
 */
#pragma once

#include <Arduino.h>
#include "xDuinoRails_DccLightsAndFunctions.h"
#include "LightSources/SwissNSignal.h"
#include <memory>

#define NEOPIXEL_PIN 2
#define NUM_PIXELS 1

class SignalManager {
public:
  /**
   * @brief Initializes the SignalManager.
   */
  void begin() {
    swissSignal = new xDuinoRails::SwissNSignal(NEOPIXEL_PIN, NUM_PIXELS);
    swissSignal->begin();
  }

  /**
   * @brief Sets the signal aspect.
   * @param aspect The new signal aspect.
   */
  void setAspect(xDuinoRails::SwissNSignalAspect aspect) {
    swissSignal->setAspect(aspect);
  }

  /**
   * @brief Updates the light effects. Should be called in the main loop.
   */
  void update() {
    swissSignal->update(millis());
  }

private:
  xDuinoRails::SwissNSignal* swissSignal;
};
