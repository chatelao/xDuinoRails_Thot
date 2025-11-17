/**
 * @file SignalManager.h
 * @brief Manages the signal aspects and their corresponding LED outputs.
 */
#pragma once

#include <Arduino.h>

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
    pinMode(LED_RED_PIN, OUTPUT);
    pinMode(LED_GREEN_PIN, OUTPUT);
    pinMode(LED_YELLOW_PIN, OUTPUT);
    setAspect(HP0);
  }

  /**
   * @brief Sets the signal aspect.
   * @param aspect The new signal aspect.
   */
  void setAspect(SignalAspect aspect) {
    // Turn off all LEDs first
    digitalWrite(LED_RED_PIN, LOW);
    digitalWrite(LED_GREEN_PIN, LOW);
    digitalWrite(LED_YELLOW_PIN, LOW);

    switch (aspect) {
      case HP0:
        digitalWrite(LED_RED_PIN, HIGH);
        break;
      case KS1:
        digitalWrite(LED_GREEN_PIN, HIGH);
        break;
      case KS2:
        digitalWrite(LED_YELLOW_PIN, HIGH);
        break;
    }
  }
};
