#ifndef USASIGNAL_H
#define USASIGNAL_H

#include "LightSource.h"
#include <Adafruit_NeoPixel.h>
#include <vector>

namespace xDuinoRails {

/**
 * @enum UsaSignalAspect
 * @brief Defines the aspects for USA type signals.
 */
enum UsaSignalAspect {
    USA_ASPECT_STOP,
    USA_ASPECT_CLEAR,
    USA_ASPECT_APPROACH
};

class UsaSignal : public LightSource {
public:
    /**
     * @brief Construct a new Usa Signal object
     *
     * @param pin The pin the NeoPixel is connected to.
     * @param numPixels The number of pixels in the NeoPixel strip.
     */
    UsaSignal(uint8_t pin, uint16_t numPixels);

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
    void setAspect(UsaSignalAspect aspect);

private:
    Adafruit_NeoPixel _strip;
    uint16_t _numPixels;
    UsaSignalAspect _aspect;
};

}

#endif // USASIGNAL_H
