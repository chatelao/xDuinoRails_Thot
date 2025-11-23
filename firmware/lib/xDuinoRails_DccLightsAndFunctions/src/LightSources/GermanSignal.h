#ifndef GERMANSIGNAL_H
#define GERMANSIGNAL_H

#include "LightSource.h"
#include <Adafruit_NeoPixel.h>

namespace xDuinoRails {

/**
 * @enum GermanSignalAspect
 * @brief Defines the aspects for German HV, Ks, and Hl signals.
 */
enum GermanSignalAspect {
    // H/V System
    DE_ASPECT_HP0, // Stop
    DE_ASPECT_HP1, // Clear
    DE_ASPECT_HP2, // Slow
    DE_ASPECT_VR0, // Expect Stop
    DE_ASPECT_VR1, // Expect Clear
    DE_ASPECT_VR2, // Expect Slow
    DE_ASPECT_SH0, // Stop Shunting
    DE_ASPECT_SH1, // Clear Shunting

    // Ks System
    DE_ASPECT_KS1,       // Clear (Green)
    DE_ASPECT_KS2,       // Expect Stop (Yellow)
    DE_ASPECT_KS1_BLINK, // Clear + Expect Reduced (Green Blinking)
    // Ks with Zs3 (Speed Display)
    DE_ASPECT_KS1_ZS3_4, // Clear + 40km/h
    DE_ASPECT_KS1_ZS3_6, // Clear + 60km/h
    DE_ASPECT_KS1_ZS3_8, // Clear + 80km/h
    DE_ASPECT_KS2_ZS3_4, // Expect Stop + 40km/h

    // Hl System
    DE_ASPECT_HL1,   // Clear (Green)
    DE_ASPECT_HL13,  // Stop (Red)
    DE_ASPECT_HL10,  // Expect Stop (Yellow)
    DE_ASPECT_HL12A, // 40km/h + Expect Stop (Yellow + Yellow)

    // Zp System (Zugpersonalsignale)
    DE_ASPECT_ZP9, // Abfahren (Green Ring)
    DE_ASPECT_ZP6, // Bremse anlegen (One White)
    DE_ASPECT_ZP7, // Bremse lösen (Two Whites)
    DE_ASPECT_ZP8  // Bremse in Ordnung (Three Whites)
};

class GermanSignal : public LightSource {
public:
    /**
     * @brief Construct a new German Signal object
     *
     * @param pin NeoPixel pin
     * @param numPixels Number of NeoPixels
     * @param seven_segment_pins Array of 7 pins for Zs3 display (optional, can be nullptr if not used)
     */
    GermanSignal(uint8_t pin, uint16_t numPixels, const int* seven_segment_pins = nullptr);

    void begin() override;
    void on() override;
    void off() override;
    void setLevel(uint8_t level) override;
    void update(uint32_t delta_ms) override;
    void setAspect(GermanSignalAspect aspect);

private:
    void displayDigit(int digit);
    Adafruit_NeoPixel _strip;
    uint16_t _numPixels;
    GermanSignalAspect _aspect;
    uint32_t _lastBlinkTime;
    bool _isBlinking;
    bool _blinkState;
    const int* _seven_segment_pins;
};

}

#endif // GERMANSIGNAL_H
