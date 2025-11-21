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
  delay(3000);

#if defined(SIGNAL_TYPE_SWISS)
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
#elif defined(SIGNAL_TYPE_DUTCH)
  // Cycle through the signal aspects every 3 seconds
  signalManager.setAspect(xDuinoRails::NL_ASPECT_STOP);
  delay(3000);
  signalManager.setAspect(xDuinoRails::NL_ASPECT_PROCEED);
  delay(3000);
  signalManager.setAspect(xDuinoRails::NL_ASPECT_PROCEED_40);
  delay(3000);
  signalManager.setAspect(xDuinoRails::NL_ASPECT_SPEED_REDUCTION_40);
  delay(3000);
  signalManager.setAspect(xDuinoRails::NL_ASPECT_PROCEED_ON_SIGHT);
  delay(3000);
  signalManager.setAspect(xDuinoRails::NL_ASPECT_STOP_OUT_OF_ORDER);
  delay(3000);
#elif defined(SIGNAL_TYPE_FRENCH)
  // Cycle through the signal aspects every 3 seconds
  signalManager.setAspect(xDuinoRails::FR_ASPECT_STOP);
  delay(3000);
  signalManager.setAspect(xDuinoRails::FR_ASPECT_PROCEED);
  delay(3000);
  signalManager.setAspect(xDuinoRails::FR_ASPECT_STOP_PERMISSIVE);
  delay(3000);
  signalManager.setAspect(xDuinoRails::FR_ASPECT_PROCEED_SLOW_30);
  delay(3000);
  signalManager.setAspect(xDuinoRails::FR_ASPECT_PROCEED_SLOW_60);
  delay(3000);
  signalManager.setAspect(xDuinoRails::FR_ASPECT_EXPECT_STOP);
  delay(3000);
  signalManager.setAspect(xDuinoRails::FR_ASPECT_EXPECT_STOP_SHORT);
  delay(3000);
  signalManager.setAspect(xDuinoRails::FR_ASPECT_SLOW_30_REMINDER);
  delay(3000);
  signalManager.setAspect(xDuinoRails::FR_ASPECT_SLOW_60_REMINDER);
  delay(3000);
  signalManager.setAspect(xDuinoRails::FR_ASPECT_SHUNTING_PROCEED);
  delay(3000);
#elif defined(SIGNAL_TYPE_ITALIAN)
  // Cycle through the signal aspects every 3 seconds
  signalManager.setAspect(xDuinoRails::IT_ASPECT_STOP);
  delay(3000);
  signalManager.setAspect(xDuinoRails::IT_ASPECT_PROCEED);
  delay(3000);
  signalManager.setAspect(xDuinoRails::IT_ASPECT_PROCEED_SLOW);
  delay(3000);
  signalManager.setAspect(xDuinoRails::IT_ASPECT_PROCEED_100);
  delay(3000);
  signalManager.setAspect(xDuinoRails::IT_ASPECT_PROCEED_60);
  delay(3000);
  signalManager.setAspect(xDuinoRails::IT_ASPECT_PROCEED_30);
  delay(3000);
  signalManager.setAspect(xDuinoRails::IT_ASPECT_EXPECT_STOP);
  delay(3000);
  signalManager.setAspect(xDuinoRails::IT_ASPECT_EXPECT_STOP_ADVANCE);
  delay(3000);
  signalManager.setAspect(xDuinoRails::IT_ASPECT_PROCEED_CAUTION);
  delay(3000);
#elif defined(SIGNAL_TYPE_USA)
  // Cycle through the signal aspects every 3 seconds
  signalManager.setAspect(xDuinoRails::USA_ASPECT_STOP);
  delay(3000);
  signalManager.setAspect(xDuinoRails::USA_ASPECT_CLEAR);
  delay(3000);
  signalManager.setAspect(xDuinoRails::USA_ASPECT_APPROACH);
  delay(3000);
#elif defined(SIGNAL_TYPE_GERMAN)
  // Cycle through German signal aspects
  signalManager.setAspect(xDuinoRails::DE_ASPECT_HP0);
  delay(3000);
  signalManager.setAspect(xDuinoRails::DE_ASPECT_HP1);
  delay(3000);
  signalManager.setAspect(xDuinoRails::DE_ASPECT_HP2);
  delay(3000);
  signalManager.setAspect(xDuinoRails::DE_ASPECT_VR0);
  delay(3000);
  signalManager.setAspect(xDuinoRails::DE_ASPECT_VR1);
  delay(3000);
  signalManager.setAspect(xDuinoRails::DE_ASPECT_KS1);
  delay(3000);
  signalManager.setAspect(xDuinoRails::DE_ASPECT_KS2);
  delay(3000);
  signalManager.setAspect(xDuinoRails::DE_ASPECT_HL1);
  delay(3000);
  signalManager.setAspect(xDuinoRails::DE_ASPECT_HL13);
  delay(3000);
#endif
}
