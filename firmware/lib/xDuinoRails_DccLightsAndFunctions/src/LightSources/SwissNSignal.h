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
};

class SwissNSignal : public LightSource {
public:
    /**
     * @brief Construct a new Swiss N Signal object
     *
     * @param pin The pin the NeoPixel is connected to.
     * @param numPixels The number of pixels in the NeoPixel strip.
     */
    SwissNSignal(uint8_t pin, uint16_t numPixels);

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
    Adafruit_NeoPixel _strip;
    uint16_t _numPixels;
    SwissNSignalAspect _aspect;
};

}

#endif // SWISSNSIGNAL_H