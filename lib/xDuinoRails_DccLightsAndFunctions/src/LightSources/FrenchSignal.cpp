#include "FrenchSignal.h"

namespace xDuinoRails {

FrenchSignal::FrenchSignal(uint8_t pin, uint16_t numPixels)
    : _strip(numPixels, pin, NEO_GRB + NEO_KHZ800),
      _numPixels(numPixels),
      _aspect(FR_ASPECT_STOP),
      _lastBlinkTime(0),
      _isBlinking(false),
      _blinkState(false) {}

void FrenchSignal::begin() {
    _strip.begin();
    _strip.show(); // Initialize all pixels to 'off'
}

void FrenchSignal::on() {
    setAspect(_aspect);
}

void FrenchSignal::off() {
    _strip.clear();
    _strip.show();
}

void FrenchSignal::setLevel(uint8_t level) {
    _strip.setBrightness(level);
    if (!_isBlinking || _blinkState) {
        _strip.show();
    }
}

void FrenchSignal::update(uint32_t current_ms) {
    if (_isBlinking) {
        if (current_ms - _lastBlinkTime > 500) { // Blink every 500ms
            _lastBlinkTime = current_ms;
            _blinkState = !_blinkState;
            if (_blinkState) {
                uint32_t color;
                switch (_aspect) {
                    case FR_ASPECT_STOP_PERMISSIVE:
                        color = _strip.Color(255, 0, 0); // Red
                        break;
                    case FR_ASPECT_PROCEED_SLOW_60:
                    case FR_ASPECT_EXPECT_STOP_SHORT:
                    case FR_ASPECT_SLOW_60_REMINDER:
                        color = _strip.Color(255, 255, 0); // Yellow
                        break;
                    case FR_ASPECT_SHUNTING_PROCEED:
                        color = _strip.Color(255, 255, 255); // White
                        break;
                    default:
                        color = _strip.Color(0,0,0); // Off
                        break;
                }
                for (int i=0; i<_numPixels; i++) {
                    _strip.setPixelColor(i, color);
                }
            } else {
                _strip.clear();
            }
            _strip.show();
        }
    }
}

void FrenchSignal::setAspect(FrenchSignalAspect aspect) {
    _aspect = aspect;
    _isBlinking = false;
    _strip.clear();

    uint32_t color1 = 0;
    uint32_t color2 = 0;
    switch (aspect) {
        case FR_ASPECT_STOP:
            color1 = _strip.Color(255, 0, 0); // Red
            if (_numPixels > 1) color2 = _strip.Color(255, 0, 0);
            break;
        case FR_ASPECT_PROCEED:
            color1 = _strip.Color(0, 255, 0); // Green
            break;
        case FR_ASPECT_STOP_PERMISSIVE:
            _isBlinking = true;
            color1 = _strip.Color(255, 0, 0); // Red
            break;
        case FR_ASPECT_PROCEED_SLOW_30:
            color1 = _strip.Color(255, 255, 0); // Yellow
            if (_numPixels > 1) color2 = _strip.Color(255, 255, 0);
            break;
        case FR_ASPECT_PROCEED_SLOW_60:
            _isBlinking = true;
            color1 = _strip.Color(255, 255, 0); // Yellow
            if (_numPixels > 1) color2 = _strip.Color(255, 255, 0);
            break;
        case FR_ASPECT_EXPECT_STOP:
            color1 = _strip.Color(255, 255, 0); // Yellow
            break;
        case FR_ASPECT_EXPECT_STOP_SHORT:
            _isBlinking = true;
            color1 = _strip.Color(255, 255, 0); // Yellow
            break;
        case FR_ASPECT_SLOW_30_REMINDER:
            color1 = _strip.Color(255, 255, 0); // Yellow
            if (_numPixels > 1) _strip.setPixelColor(1, color1);
            break;
        case FR_ASPECT_SLOW_60_REMINDER:
            _isBlinking = true;
            color1 = _strip.Color(255, 255, 0); // Yellow
             if (_numPixels > 1) _strip.setPixelColor(1, color1);
            break;
        case FR_ASPECT_SHUNTING_PROCEED:
            _isBlinking = true;
            color1 = _strip.Color(255, 255, 255); // White
            break;
        default:
            break;
    }

    _strip.setPixelColor(0, color1);
    if (_numPixels > 1 && color2 != 0) {
        _strip.setPixelColor(1, color2);
    }


    if (!_isBlinking) {
        _strip.show();
    }
}

} // namespace xDuinoRails