#ifndef SWISSLSIGNAL_H
#define SWISSLSIGNAL_H

#include "LightSource.h"
#include <Adafruit_NeoPixel.h>
#include <vector>

namespace xDuinoRails {

/**
 * @enum SwissLSignalAspect
 * @brief Defines the aspects for Swiss L type signals.
 */
enum SwissLSignalAspect {
    L_ASPECT_STOP,
    L_ASPECT_CLEAR,
    L_ASPECT_SPEED_40,
    L_ASPECT_SPEED_60,
    L_ASPECT_SPEED_90,
    L_ASPECT_SHORT_PROCEED,
    L_ASPECT_PROCEED_CAUTION,
};

class SwissLSignal : public LightSource {
public:
    /**
     * @brief Construct a new Swiss L Signal object
     *
     * @param pin The pin the NeoPixel is connected to.
     * @param numPixels The number of pixels in the NeoPixel strip.
     */
    SwissLSignal(uint8_t pin, uint16_t numPixels);

    /**
     * @brief Initializes the signal.
     */
    void begin() override;

    /**
     * @brief Turns the signal on.
     */
    void on() override;

    /**
     * @brief Turns the signal off.
     */
    void off() override;

    /**
     * @brief Sets the brightness of the signal.
     * @param level The brightness level (0-255).
     */
    void setLevel(uint8_t level) override;

    /**
     * @brief Updates the signal.
     * @param delta_ms The time since the last update in milliseconds.
     */
    void update(uint32_t delta_ms) override;

    /**
     * @brief Sets the aspect of the signal.
     * @param aspect The aspect to set.
     */
    void setAspect(SwissLSignalAspect aspect);

private:
    Adafruit_NeoPixel _strip;
    uint16_t _numPixels;
    SwissLSignalAspect _aspect;
    uint32_t _lastBlinkTime;
    bool _isBlinking;
    bool _blinkState;
};

}

#endif // SWISSLSIGNAL_H