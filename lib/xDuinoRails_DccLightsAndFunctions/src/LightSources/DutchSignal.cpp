#include "DutchSignal.h"

namespace xDuinoRails {

DutchSignal::DutchSignal(uint8_t pin, uint16_t numPixels)
    : _strip(numPixels, pin, NEO_GRB + NEO_KHZ800),
      _numPixels(numPixels),
      _aspect(NL_ASPECT_STOP),
      _lastBlinkTime(0),
      _isBlinking(false),
      _blinkState(false) {}

void DutchSignal::begin() {
    _strip.begin();
    _strip.show(); // Initialize all pixels to 'off'
}

void DutchSignal::on() {
    setAspect(_aspect);
}

void DutchSignal::off() {
    _strip.clear();
    _strip.show();
}

void DutchSignal::setLevel(uint8_t level) {
    _strip.setBrightness(level);
    if (!_isBlinking || _blinkState) {
        _strip.show();
    }
}

void DutchSignal::update(uint32_t current_ms) {
    if (_isBlinking) {
        if (current_ms - _lastBlinkTime > 500) { // Blink every 500ms
            _lastBlinkTime = current_ms;
            _blinkState = !_blinkState;
            if (_blinkState) {
                uint32_t color;
                switch (_aspect) {
                    case NL_ASPECT_PROCEED_40:
                        color = _strip.Color(0, 255, 0); // Green
                        break;
                    case NL_ASPECT_PROCEED_ON_SIGHT:
                        color = _strip.Color(255, 255, 0); // Yellow
                        break;
                    case NL_ASPECT_STOP_OUT_OF_ORDER:
                        color = _strip.Color(255, 0, 0); // Red
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

void DutchSignal::setAspect(DutchSignalAspect aspect) {
    _aspect = aspect;
    _isBlinking = false;
    _strip.clear();

    uint32_t color;
    switch (aspect) {
        case NL_ASPECT_STOP:
            color = _strip.Color(255, 0, 0); // Red
            break;
        case NL_ASPECT_PROCEED:
            color = _strip.Color(0, 255, 0); // Green
            break;
        case NL_ASPECT_PROCEED_40:
            _isBlinking = true;
            color = _strip.Color(0, 255, 0); // Green
            break;
        case NL_ASPECT_SPEED_REDUCTION_40:
            color = _strip.Color(255, 255, 0); // Yellow
            break;
        case NL_ASPECT_PROCEED_ON_SIGHT:
            _isBlinking = true;
            color = _strip.Color(255, 255, 0); // Yellow
            break;
        case NL_ASPECT_STOP_OUT_OF_ORDER:
            _isBlinking = true;
            color = _strip.Color(255, 0, 0); // Red
            break;
        default:
            color = _strip.Color(0,0,0);
            break;
    }

    for (int i=0; i<_numPixels; i++) {
        _strip.setPixelColor(i, color);
    }

    if (!_isBlinking) {
        _strip.show();
    }
}

} // namespace xDuinoRails