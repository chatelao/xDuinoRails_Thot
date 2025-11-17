/**
 * @file SignalManager.h
 * @brief Manages the signal aspects and their corresponding LED outputs.
 */
#pragma once

#include <Arduino.h>
#include "xDuinoRails_DccLightsAndFunctions.h"
#include "LightSources/SingleLed.h"
#include "LogicalFunction.h"
#include "effects/Effect.h"
#include <memory>

// Define the signal aspects
enum SignalAspect {
  HP0,  // Stop
  KS1,  // Proceed
  KS2   // Proceed at reduced speed, expect stop
};

// Define the LED pins
#define LED_RED_PIN    2
#define LED_GREEN_PIN  3
#define LED_YELLOW_PIN 4

class SignalManager {
public:
  /**
   * @brief Initializes the SignalManager.
   */
  void begin() {
    lightManager.addLightSource(std::make_unique<xDuinoRails::SingleLed>(LED_RED_PIN));
    lightManager.addLightSource(std::make_unique<xDuinoRails::SingleLed>(LED_GREEN_PIN));
    lightManager.addLightSource(std::make_unique<xDuinoRails::SingleLed>(LED_YELLOW_PIN));

    redLight = new xDuinoRails::LogicalFunction(new xDuinoRails::EffectSteady(255));
    redLight->addOutput(lightManager.getOutputById(0));
    lightManager.addLogicalFunction(redLight);

    greenLight = new xDuinoRails::LogicalFunction(new xDuinoRails::EffectSteady(255));
    greenLight->addOutput(lightManager.getOutputById(1));
    lightManager.addLogicalFunction(greenLight);

    yellowLight = new xDuinoRails::LogicalFunction(new xDuinoRails::EffectSteady(255));
    yellowLight->addOutput(lightManager.getOutputById(2));
    lightManager.addLogicalFunction(yellowLight);

    setAspect(HP0);
  }

  /**
   * @brief Sets the signal aspect.
   * @param aspect The new signal aspect.
   */
  void setAspect(SignalAspect aspect) {
    // Turn off all LEDs first
    redLight->setActive(false);
    greenLight->setActive(false);
    yellowLight->setActive(false);

    switch (aspect) {
      case HP0:
        redLight->setActive(true);
        break;
      case KS1:
        greenLight->setActive(true);
        break;
      case KS2:
        yellowLight->setActive(true);
        break;
    }
  }

  /**
   * @brief Updates the light effects. Should be called in the main loop.
   */
  void update() {
    lightManager.update(millis());
  }

private:
  xDuinoRails::AuxController lightManager;
  xDuinoRails::LogicalFunction* redLight;
  xDuinoRails::LogicalFunction* greenLight;
  xDuinoRails::LogicalFunction* yellowLight;
};
