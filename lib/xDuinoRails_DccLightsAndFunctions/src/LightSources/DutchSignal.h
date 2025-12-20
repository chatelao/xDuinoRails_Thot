#ifndef DUTCHSIGNAL_H
#define DUTCHSIGNAL_H

#include "LightSource.h"
#include <Adafruit_NeoPixel.h>
#include <vector>

namespace xDuinoRails {

/**
 * @enum DutchSignalAspect
 * @brief Defines the aspects for Dutch type signals.
 */
enum DutchSignalAspect {
    NL_ASPECT_STOP,
    NL_ASPECT_PROCEED,
    NL_ASPECT_PROCEED_40,
    NL_ASPECT_SPEED_REDUCTION_40,
    NL_ASPECT_PROCEED_ON_SIGHT,
    NL_ASPECT_STOP_OUT_OF_ORDER,
};

class DutchSignal : public LightSource {
public:
    /**
     * @brief Construct a new Dutch Signal object
     *
     * @param pin The pin the NeoPixel is connected to.
     * @param numPixels The number of pixels in the NeoPixel strip.
     */
    DutchSignal(uint8_t pin, uint16_t numPixels);

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
    void setAspect(DutchSignalAspect aspect);

private:
    Adafruit_NeoPixel _strip;
    uint16_t _numPixels;
    DutchSignalAspect _aspect;
    uint32_t _lastBlinkTime;
    bool _isBlinking;
    bool _blinkState;
};

}

#endif // DUTCHSIGNAL_H