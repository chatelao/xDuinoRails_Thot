#ifndef AUSTRALIANSIGNAL_H
#define AUSTRALIANSIGNAL_H

#include "LightSource.h"
#include <Adafruit_NeoPixel.h>
#include <vector>

namespace xDuinoRails {

/**
 * @enum AustralianNSignalAspect
 * @brief Defines the aspects for Australian NSW type signals.
 */
enum AustralianNSignalAspect {
    AU_NSW_ASPECT_STOP,
    AU_NSW_ASPECT_CAUTION,
    AU_NSW_ASPECT_MEDIUM,
    AU_NSW_ASPECT_CLEAR
};

class AustralianNSignal : public LightSource {
public:
    /**
     * @brief Construct a new Australian N Signal object
     *
     * @param pin The pin the NeoPixel is connected to.
     * @param numPixels The number of pixels in the NeoPixel strip.
     */
    AustralianNSignal(uint8_t pin, uint16_t numPixels);

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
    void setAspect(AustralianNSignalAspect aspect);

private:
    Adafruit_NeoPixel _strip;
    uint16_t _numPixels;
    AustralianNSignalAspect _aspect;
};

}

#endif // AUSTRALIANSIGNAL_H