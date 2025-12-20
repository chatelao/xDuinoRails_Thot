#ifndef FRENCHSIGNAL_H
#define FRENCHSIGNAL_H

#include "LightSource.h"
#include <Adafruit_NeoPixel.h>
#include <vector>

namespace xDuinoRails {

/**
 * @enum FrenchSignalAspect
 * @brief Defines the aspects for French type signals.
 */
enum FrenchSignalAspect {
    FR_ASPECT_STOP,
    FR_ASPECT_PROCEED,
    FR_ASPECT_STOP_PERMISSIVE,
    FR_ASPECT_PROCEED_SLOW_30,
    FR_ASPECT_PROCEED_SLOW_60,
    FR_ASPECT_EXPECT_STOP,
    FR_ASPECT_EXPECT_STOP_SHORT,
    FR_ASPECT_SLOW_30_REMINDER,
    FR_ASPECT_SLOW_60_REMINDER,
    FR_ASPECT_SHUNTING_PROCEED,
};

class FrenchSignal : public LightSource {
public:
    /**
     * @brief Construct a new French Signal object
     *
     * @param pin The pin the NeoPixel is connected to.
     * @param numPixels The number of pixels in the NeoPixel strip.
     */
    FrenchSignal(uint8_t pin, uint16_t numPixels);

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
    void setAspect(FrenchSignalAspect aspect);

private:
    Adafruit_NeoPixel _strip;
    uint16_t _numPixels;
    FrenchSignalAspect _aspect;
    uint32_t _lastBlinkTime;
    bool _isBlinking;
    bool _blinkState;
};

}

#endif // FRENCHSIGNAL_H