#ifndef SWISSNSIGNAL_H
#define SWISSNSIGNAL_H

#include "LightSource.h"
#include <Adafruit_NeoPixel.h>
#include <vector>

namespace xDuinoRails {

/**
 * @enum SwissNSignalAspect
 * @brief Defines the aspects for Swiss N type signals.
 */
enum SwissNSignalAspect {
    N_ASPECT_STOP,              ///< Stop
    N_ASPECT_CLEAR,             ///< Track clear
    N_ASPECT_SPEED_40,          ///< Speed restriction 40 km/h
    N_ASPECT_SPEED_60,          ///< Speed restriction 60 km/h
    N_ASPECT_SPEED_90,          ///< Speed restriction 90 km/h
    N_ASPECT_OBSTRUCTION_AHEAD, ///< Obstruction close ahead
    N_ASPECT_TRACK_OCCUPIED,    ///< Track occupied
    N_ASPECT_PREWARNING,        ///< Prewarning
    N_ASPECT_SPEED_ANNOUNCEMENT_40,
    N_ASPECT_SPEED_ANNOUNCEMENT_60,
    N_ASPECT_SPEED_ANNOUNCEMENT_90,
};

class SwissNSignal : public LightSource {
public:
    /**
     * @brief Construct a new Swiss N Signal object
     *
     * @param pin The pin the NeoPixel is connected to.
     * @param numPixels The number of pixels in the NeoPixel strip.
     * @param seven_segment_pins An array of 7 pins for the 7-segment display.
     */
    SwissNSignal(uint8_t pin, uint16_t numPixels, const int* seven_segment_pins);

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
    void setAspect(SwissNSignalAspect aspect);

private:
    void displayDigit(int digit);
    Adafruit_NeoPixel _strip;
    uint16_t _numPixels;
    SwissNSignalAspect _aspect;
    uint32_t _lastBlinkTime;
    bool _isBlinking;
    bool _blinkState;
    const int* _seven_segment_pins;
};

}

#endif // SWISSNSIGNAL_H