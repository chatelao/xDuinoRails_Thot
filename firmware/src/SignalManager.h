/**
 * @file SignalManager.h
 * @brief Manages the signal aspects and their corresponding LED outputs.
 */
#pragma once

#include <Arduino.h>
#include "xDuinoRails_DccLightsAndFunctions.h"

#if defined(SIGNAL_TYPE_SWISS)
#include "LightSources/SwissNSignal.h"
#elif defined(SIGNAL_TYPE_SWISS_L)
#include "LightSources/SwissLSignal.h"
#elif defined(SIGNAL_TYPE_DUTCH)
#include "LightSources/DutchSignal.h"
#elif defined(SIGNAL_TYPE_FRENCH)
#include "LightSources/FrenchSignal.h"
#elif defined(SIGNAL_TYPE_ITALIAN)
#include "LightSources/ItalianSignal.h"
#elif defined(SIGNAL_TYPE_AUSTRALIAN)
#include "LightSources/AustralianNSignal.h"
#elif defined(SIGNAL_TYPE_USA)
#include "LightSources/UsaSignal.h"
#elif defined(SIGNAL_TYPE_GERMAN)
#include "LightSources/GermanSignal.h"
#elif defined(SIGNAL_TYPE_POLISH)
#include "LightSources/PolishSignal.h"
#endif

#include <memory>

#define NEOPIXEL_PIN 2
#define NUM_PIXELS 1

const int seven_segment_pins[7] = {10, 11, 12, 13, 14, 15, 16}; // A, B, C, D, E, F, G

class SignalManager {
public:
  /**
   * @brief Initializes the SignalManager.
   */
  void begin() {
#if defined(SIGNAL_TYPE_SWISS)
    signal = new xDuinoRails::SwissNSignal(NEOPIXEL_PIN, NUM_PIXELS, seven_segment_pins);
#elif defined(SIGNAL_TYPE_SWISS_L)
    signal = new xDuinoRails::SwissLSignal(NEOPIXEL_PIN, NUM_PIXELS);
#elif defined(SIGNAL_TYPE_DUTCH)
    signal = new xDuinoRails::DutchSignal(NEOPIXEL_PIN, NUM_PIXELS);
#elif defined(SIGNAL_TYPE_FRENCH)
    signal = new xDuinoRails::FrenchSignal(NEOPIXEL_PIN, NUM_PIXELS);
#elif defined(SIGNAL_TYPE_ITALIAN)
    signal = new xDuinoRails::ItalianSignal(NEOPIXEL_PIN, NUM_PIXELS);
#elif defined(SIGNAL_TYPE_AUSTRALIAN)
    signal = new xDuinoRails::AustralianNSignal(NEOPIXEL_PIN, NUM_PIXELS);
#elif defined(SIGNAL_TYPE_USA)
    signal = new xDuinoRails::UsaSignal(NEOPIXEL_PIN, NUM_PIXELS);
#elif defined(SIGNAL_TYPE_GERMAN)
    signal = new xDuinoRails::GermanSignal(NEOPIXEL_PIN, NUM_PIXELS, seven_segment_pins);
#elif defined(SIGNAL_TYPE_POLISH)
    signal = new xDuinoRails::PolishSignal(NEOPIXEL_PIN, NUM_PIXELS);
#endif
    signal->begin();
  }

  /**
   * @brief Sets the signal aspect.
   * @param aspect The new signal aspect.
   */
#if defined(SIGNAL_TYPE_SWISS)
  void setAspect(xDuinoRails::SwissNSignalAspect aspect) {
    signal->setAspect(aspect);
  }
#elif defined(SIGNAL_TYPE_SWISS_L)
    void setAspect(xDuinoRails::SwissLSignalAspect aspect) {
    signal->setAspect(aspect);
  }
#elif defined(SIGNAL_TYPE_DUTCH)
  void setAspect(xDuinoRails::DutchSignalAspect aspect) {
    signal->setAspect(aspect);
  }
#elif defined(SIGNAL_TYPE_FRENCH)
    void setAspect(xDuinoRails::FrenchSignalAspect aspect) {
    signal->setAspect(aspect);
  }
#elif defined(SIGNAL_TYPE_ITALIAN)
    void setAspect(xDuinoRails::ItalianSignalAspect aspect) {
    signal->setAspect(aspect);
  }
#elif defined(SIGNAL_TYPE_AUSTRALIAN)
  void setAspect(xDuinoRails::AustralianNSignalAspect aspect) {
    signal->setAspect(aspect);
  }
#elif defined(SIGNAL_TYPE_USA)
  void setAspect(xDuinoRails::UsaSignalAspect aspect) {
    signal->setAspect(aspect);
  }
#elif defined(SIGNAL_TYPE_GERMAN)
  void setAspect(xDuinoRails::GermanSignalAspect aspect) {
    signal->setAspect(aspect);
  }
#elif defined(SIGNAL_TYPE_POLISH)
  void setAspect(xDuinoRails::PolishSignalAspect aspect) {
    signal->setAspect(aspect);
  }
#endif

  /**
   * @brief Updates the light effects. Should be called in the main loop.
   */
  void update() {
    signal->update(millis());
  }

private:
#if defined(SIGNAL_TYPE_SWISS)
  xDuinoRails::SwissNSignal* signal;
#elif defined(SIGNAL_TYPE_SWISS_L)
  xDuinoRails::SwissLSignal* signal;
#elif defined(SIGNAL_TYPE_DUTCH)
  xDuinoRails::DutchSignal* signal;
#elif defined(SIGNAL_TYPE_FRENCH)
  xDuinoRails::FrenchSignal* signal;
#elif defined(SIGNAL_TYPE_ITALIAN)
  xDuinoRails::ItalianSignal* signal;
#elif defined(SIGNAL_TYPE_AUSTRALIAN)
  xDuinoRails::AustralianNSignal* signal;
#elif defined(SIGNAL_TYPE_USA)
  xDuinoRails::UsaSignal* signal;
#elif defined(SIGNAL_TYPE_GERMAN)
  xDuinoRails::GermanSignal* signal;
#elif defined(SIGNAL_TYPE_POLISH)
  xDuinoRails::PolishSignal* signal;
#endif
};