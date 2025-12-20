#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "LightSources/SwissCombinedSignalDiscrete.h"

// ---------------------------------------------------------------------------
// Configuration
// ---------------------------------------------------------------------------

// NeoPixel Matrix (9x9 = 81 pixels)
#define MATRIX_PIN      0
#define MATRIX_WIDTH    9
#define MATRIX_HEIGHT   9
#define NUM_PIXELS      (MATRIX_WIDTH * MATRIX_HEIGHT)

// Discrete Signal Pins
// Mapping: G_Top, Red, Yellow, G_Bot, Dist_Y_TL, Dist_Y_TR, Dist_G_BL, Dist_G_BR
const uint8_t SIGNAL_PINS[] = { 1, 2, 3, 4, 5, 6, 7, 26 };

// ---------------------------------------------------------------------------
// Objects
// ---------------------------------------------------------------------------

Adafruit_NeoPixel matrix(NUM_PIXELS, MATRIX_PIN, NEO_GRB + NEO_KHZ800);
xDuinoRails::SwissCombinedSignalDiscrete swissSignal(SIGNAL_PINS);

// ---------------------------------------------------------------------------
// Setup
// ---------------------------------------------------------------------------

void setup() {
    // Initialize Matrix
    matrix.begin();
    matrix.setBrightness(50);
    matrix.clear();

    // simple pattern on matrix to show it works
    for(int i=0; i<NUM_PIXELS; i++) {
        if ((i / 9) == (i % 9)) { // Diagonal
            matrix.setPixelColor(i, matrix.Color(0, 0, 255));
        }
    }
    matrix.show();

    // Initialize Signal
    swissSignal.begin();
    swissSignal.setLevel(255); // Full brightness
}

// ---------------------------------------------------------------------------
// Loop
// ---------------------------------------------------------------------------

void loop() {
    // Cycle through aspects every 2 seconds

    // 1. Stop
    swissSignal.setAspect(xDuinoRails::SCS_ASPECT_STOP);
    delay(2000);

    // 2. Clear
    swissSignal.setAspect(xDuinoRails::SCS_ASPECT_CLEAR);
    delay(2000);

    // 3. Expect 40
    swissSignal.setAspect(xDuinoRails::SCS_ASPECT_EXPECT_40);
    delay(2000);

    // 4. Speed 40
    swissSignal.setAspect(xDuinoRails::SCS_ASPECT_SPEED_40);
    delay(2000);

    // 5. Speed 60
    swissSignal.setAspect(xDuinoRails::SCS_ASPECT_SPEED_60);
    delay(2000);

    // 6. Warning
    swissSignal.setAspect(xDuinoRails::SCS_ASPECT_WARN);
    delay(2000);
}
