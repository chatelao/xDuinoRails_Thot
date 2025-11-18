#ifndef ITALIANSIGNAL_H
#define ITALIANSIGNAL_H

#include "LightSource.h"
#include <Adafruit_NeoPixel.h>
#include <vector>

namespace xDuinoRails {

/**
 * @enum ItalianSignalAspect
 * @brief Defines the aspects for Italian type signals.
 */
enum ItalianSignalAspect {
    IT_ASPECT_STOP,
    IT_ASPECT_PROCEED,
    IT_ASPECT_PROCEED_SLOW,
    IT_ASPECT_PROCEED_100,
    IT_ASPECT_PROCEED_60,
    IT_ASPECT_PROCEED_30,
    IT_ASPECT_EXPECT_STOP,
    IT_ASPECT_EXPECT_STOP_ADVANCE,
    IT_ASPECT_PROCEED_CAUTION,
};

class ItalianSignal : public LightSource {
public:
    /**
     * @brief Construct a new Italian Signal object
     *
     * @param pin The pin the NeoPixel is connected to.
     * @param numPixels The number of pixels in the NeoPixel strip.
     */
    ItalianSignal(uint8_t pin, uint16_t numPixels);

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
    void setAspect(ItalianSignalAspect aspect);

private:
    Adafruit_NeoPixel _strip;
    uint16_t _numPixels;
    ItalianSignalAspect _aspect;
    uint32_t _lastBlinkTime;
    bool _isBlinking;
    bool _blinkState;
};

}

#endif // ITALIANSIGNAL_H