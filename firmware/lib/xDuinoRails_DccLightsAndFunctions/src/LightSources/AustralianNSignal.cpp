#include "AustralianNSignal.h"

namespace xDuinoRails {

AustralianNSignal::AustralianNSignal(uint8_t pin, uint16_t numPixels)
    : _strip(numPixels, pin, NEO_GRB + NEO_KHZ800), _numPixels(numPixels), _aspect(AU_NSW_ASPECT_STOP) {
}

void AustralianNSignal::begin() {
    _strip.begin();
    _strip.show(); // Initialize all pixels to 'off'
}

void AustralianNSignal::on() {
    // Re-apply the current aspect
    setAspect(_aspect);
}

void AustralianNSignal::off() {
    _strip.clear();
    _strip.show();
}

void AustralianNSignal::setLevel(uint8_t level) {
    _strip.setBrightness(level);
    _strip.show();
}

void AustralianNSignal::update(uint32_t delta_ms) {
    // No dynamic behavior for now
}

void AustralianNSignal::setAspect(AustralianNSignalAspect aspect) {
    _aspect = aspect;
    _strip.clear();

    switch (_aspect) {
        case AU_NSW_ASPECT_STOP:
            if (_numPixels >= 2) {
                _strip.setPixelColor(2, _strip.Color(255, 0, 0));
                _strip.setPixelColor(3, _strip.Color(255, 0, 0));
            }
            break;
        case AU_NSW_ASPECT_CAUTION:
            if (_numPixels >= 2) {
                _strip.setPixelColor(1, _strip.Color(255, 255, 0));
            }
            break;
        case AU_NSW_ASPECT_MEDIUM:
             if (_numPixels >= 1) {
                _strip.setPixelColor(2, _strip.Color(255, 255, 0));
            }
            break;
        case AU_NSW_ASPECT_CLEAR:
            if (_numPixels >= 1) {
                _strip.setPixelColor(0, _strip.Color(0, 255, 0));
            }
            break;
    }
    _strip.show();
}

}
