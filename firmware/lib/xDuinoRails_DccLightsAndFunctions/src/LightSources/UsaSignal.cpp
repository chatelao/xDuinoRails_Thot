#include "UsaSignal.h"

namespace xDuinoRails {

UsaSignal::UsaSignal(uint8_t pin, uint16_t numPixels) : _strip(numPixels, pin, NEO_GRB + NEO_KHZ800), _numPixels(numPixels) {
}

void UsaSignal::begin() {
    _strip.begin();
    _strip.show(); // Initialize all pixels to 'off'
}

void UsaSignal::on() {
    setAspect(USA_ASPECT_STOP);
}

void UsaSignal::off() {
    _strip.clear();
    _strip.show();
}

void UsaSignal::setLevel(uint8_t level) {
    _strip.setBrightness(level);
    _strip.show();
}

void UsaSignal::update(uint32_t delta_ms) {
    // Nothing to do here for now
}

void UsaSignal::setAspect(UsaSignalAspect aspect) {
    _aspect = aspect;
    _strip.clear();

    switch (_aspect) {
        case USA_ASPECT_STOP:
            _strip.setPixelColor(2, _strip.Color(255, 0, 0)); // Red
            break;
        case USA_ASPECT_CLEAR:
            _strip.setPixelColor(0, _strip.Color(0, 255, 0)); // Green
            break;
        case USA_ASPECT_APPROACH:
            _strip.setPixelColor(1, _strip.Color(255, 255, 0)); // Yellow
            break;
    }
    _strip.show();
}

}
