#include "SwissCombinedSignalDiscrete.h"

namespace xDuinoRails {

SwissCombinedSignalDiscrete::SwissCombinedSignalDiscrete(const uint8_t* pins) : _aspect(SCS_ASPECT_STOP), _level(255) {
    for (int i = 0; i < 8; i++) {
        _pins[i] = pins[i];
    }
}

void SwissCombinedSignalDiscrete::begin() {
    for (int i = 0; i < 8; i++) {
        pinMode(_pins[i], OUTPUT);
        digitalWrite(_pins[i], LOW);
    }
}

void SwissCombinedSignalDiscrete::on() {
    setAspect(_aspect);
}

void SwissCombinedSignalDiscrete::off() {
    for (int i = 0; i < 8; i++) {
        digitalWrite(_pins[i], LOW);
    }
}

void SwissCombinedSignalDiscrete::setLevel(uint8_t level) {
    _level = level;
    on(); // Update outputs
}

void SwissCombinedSignalDiscrete::update(uint32_t delta_ms) {
    // No blinking implemented in this basic concept
    (void)delta_ms;
}

void SwissCombinedSignalDiscrete::writePin(uint8_t pinIndex, bool state) {
    if (state) {
        analogWrite(_pins[pinIndex], _level);
    } else {
        digitalWrite(_pins[pinIndex], LOW);
    }
}

void SwissCombinedSignalDiscrete::setAspect(SwissCombinedSignalAspect aspect) {
    _aspect = aspect;

    // Turn all off first (internal state)
    bool states[8] = {0}; // G_T, R, Y, G_B, DY_TL, DY_TR, DG_BL, DG_BR

    switch (_aspect) {
        case SCS_ASPECT_STOP:
            states[1] = true; // Red
            break;
        case SCS_ASPECT_CLEAR:
            states[0] = true; // Green Top
            // Distant implicitly clear (all off)
            break;
        case SCS_ASPECT_WARN:
            states[0] = true; // Green Top
            states[4] = true; // Distant Yellow TL
            states[5] = true; // Distant Yellow TR
            break;
        case SCS_ASPECT_EXPECT_40:
            states[0] = true; // Green Top
            states[4] = true; // Distant Yellow TL
            states[7] = true; // Distant Green BR
            break;
        case SCS_ASPECT_SPEED_40:
            states[0] = true; // Green Top
            states[2] = true; // Main Yellow
            break;
        case SCS_ASPECT_SPEED_60:
            states[0] = true; // Green Top
            states[3] = true; // Main Green Bottom
            break;
        case SCS_ASPECT_SHORT_PROCEED:
             // Fallback representation
             states[2] = true; // Main Yellow
             states[4] = true; // Distant Yellow TL
             break;
    }

    for (int i = 0; i < 8; i++) {
        writePin(i, states[i]);
    }
}

} // namespace xDuinoRails
