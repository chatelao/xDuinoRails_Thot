#ifndef POLISHSIGNAL_H
#define POLISHSIGNAL_H

#include "LightSource.h"
#include <Adafruit_NeoPixel.h>

namespace xDuinoRails {

/**
 * @enum PolishSignalAspect
 * @brief Defines the aspects for Polish signals.
 */
enum PolishSignalAspect {
    // Main Signal (5 lights)
    PL_ASPECT_S1,   // Stop (Red)
    PL_ASPECT_S2,   // Proceed Vmax (Green Top)
    PL_ASPECT_S3,   // Proceed Vmax, next 100 (Green Top Blinking)
    PL_ASPECT_S4,   // Proceed Vmax, next 60/40 (Orange Top Blinking)
    PL_ASPECT_S5,   // Proceed Vmax, next Stop (Orange Top)
    PL_ASPECT_S10,  // Proceed 40, next Vmax (Green Top + Orange Bottom)
    PL_ASPECT_S11,  // Proceed 40, next 100 (Green Top Blinking + Orange Bottom)
    PL_ASPECT_S12,  // Proceed 40, next 60/40 (Orange Top Blinking + Orange Bottom)
    PL_ASPECT_S13,  // Proceed 40, next Stop (Orange Top + Orange Bottom)
    PL_ASPECT_SZ,   // Call-on (Red + White Bottom Blinking)

    // Shunting Signal
    PL_ASPECT_MS1,  // Shunting Forbidden (Blue)
    PL_ASPECT_MS2,  // Shunting Allowed (White)

    // Distant Signal
    PL_ASPECT_OS1,  // Expect Stop (Orange)
    PL_ASPECT_OS2,  // Expect Vmax (Green)
    PL_ASPECT_OS3,  // Expect 100 (Green Blinking)
    PL_ASPECT_OS4   // Expect 60/40 (Orange Blinking)
};

class PolishSignal : public LightSource {
public:
    PolishSignal(uint8_t pin, uint16_t numPixels);

    void begin() override;
    void on() override;
    void off() override;
    void setLevel(uint8_t level) override;
    void update(uint32_t delta_ms) override;
    void setAspect(PolishSignalAspect aspect);

private:
    void render();
    Adafruit_NeoPixel _strip;
    uint16_t _numPixels;
    PolishSignalAspect _aspect;
    uint32_t _lastBlinkTime;
    bool _isBlinking;
    bool _blinkState;
};

}

#endif // POLISHSIGNAL_H
