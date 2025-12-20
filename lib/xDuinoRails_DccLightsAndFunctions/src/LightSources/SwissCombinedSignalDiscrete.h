#ifndef SWISSCOMBINEDSIGNALDISCRETE_H
#define SWISSCOMBINEDSIGNALDISCRETE_H

#include "LightSource.h"
#include <Arduino.h>
#include <vector>

namespace xDuinoRails {

/**
 * @enum SwissCombinedSignalAspect
 * @brief Aspects for the Swiss Combined Signal (Discrete LED version).
 */
enum SwissCombinedSignalAspect {
    SCS_ASPECT_STOP,                ///< Main: Red
    SCS_ASPECT_CLEAR,               ///< Main: Green, Distant: Off (Implied Clear)
    SCS_ASPECT_WARN,                ///< Main: Green, Distant: Warning (YY)
    SCS_ASPECT_EXPECT_40,           ///< Main: Green, Distant: Expect 40 (YG)
    SCS_ASPECT_SPEED_40,            ///< Main: Green + Yellow (40)
    SCS_ASPECT_SPEED_60,            ///< Main: Green + Green (60)
    SCS_ASPECT_SHORT_PROCEED        ///< Main: Yellow + Yellow? or specific short proceed pattern
};

class SwissCombinedSignalDiscrete : public LightSource {
public:
    /**
     * @brief Construct a new Swiss Combined Signal Discrete object
     *
     * @param pins An array of 8 pins:
     *             0: Main Green (Top)
     *             1: Main Red
     *             2: Main Yellow
     *             3: Main Green (Bottom)
     *             4: Distant Yellow (Top Left)
     *             5: Distant Yellow (Top Right)
     *             6: Distant Green (Bottom Left)
     *             7: Distant Green (Bottom Right)
     */
    SwissCombinedSignalDiscrete(const uint8_t* pins);

    void begin() override;
    void on() override;
    void off() override;
    void setLevel(uint8_t level) override;
    void update(uint32_t delta_ms) override;

    void setAspect(SwissCombinedSignalAspect aspect);

private:
    uint8_t _pins[8];
    SwissCombinedSignalAspect _aspect;
    uint8_t _level; // Brightness is simulated via PWM if supported, or just ON/OFF

    // Helper to write to pins considering "level" (if we use PWM)
    // For discrete concept, we might just use digital writes for now,
    // or analogWrite if pins support it.
    void writePin(uint8_t pinIndex, bool state);
};

}

#endif // SWISSCOMBINEDSIGNALDISCRETE_H
