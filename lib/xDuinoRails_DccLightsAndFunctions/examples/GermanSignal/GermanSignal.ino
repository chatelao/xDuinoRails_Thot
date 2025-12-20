#include <Arduino.h>
#include "LightSources/GermanSignal.h"

#define NEOPIXEL_PIN 2
#define NUM_PIXELS 4

// 7-segment pins (dummy values for example, adjust as needed)
const int seven_segment_pins[7] = {10, 11, 12, 13, 14, 15, 16};

xDuinoRails::GermanSignal germanSignal(NEOPIXEL_PIN, NUM_PIXELS, seven_segment_pins);

void setup() {
  germanSignal.begin();
}

void loop() {
  // Cycle through German signal aspects

  // --- H/V System ---
  // Hauptsignal
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_HP0);
  delay(2000);
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_HP1);
  delay(2000);
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_HP2);
  delay(2000);

  // Vorsignal
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_VR0);
  delay(2000);
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_VR1);
  delay(2000);
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_VR2);
  delay(2000);

  // Zwergsignal
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_SH0);
  delay(2000);
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_SH1);
  delay(2000);

  // --- Ks System ---
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_KS1);
  delay(2000);
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_KS2);
  delay(2000);
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_KS1_BLINK);
  delay(2000);

  // Ks with Zs3 (Speed Indicator)
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_KS1_ZS3_4);
  delay(2000);
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_KS1_ZS3_6);
  delay(2000);
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_KS1_ZS3_8);
  delay(2000);
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_KS2_ZS3_4);
  delay(2000);

  // --- Hl System ---
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_HL1);
  delay(2000);
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_HL13);
  delay(2000);
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_HL10);
  delay(2000);
  germanSignal.setAspect(xDuinoRails::DE_ASPECT_HL12A);
  delay(2000);
}
