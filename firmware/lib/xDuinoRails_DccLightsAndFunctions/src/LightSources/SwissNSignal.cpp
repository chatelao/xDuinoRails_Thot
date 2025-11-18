#include "SwissNSignal.h"

namespace xDuinoRails {

SwissNSignal::SwissNSignal(uint8_t pin, uint16_t numPixels)
    : _strip(numPixels, pin, NEO_GRB + NEO_KHZ800),
      _numPixels(numPixels),
      _aspect(N_ASPECT_STOP),
      _lastBlinkTime(0),
      _isBlinking(false),
      _blinkState(false) {}

void SwissNSignal::begin() {
    _strip.begin();
    _strip.show(); // Initialize all pixels to 'off'
}

void SwissNSignal::on() {
    setAspect(_aspect);
}

void SwissNSignal::off() {
    _strip.clear();
    _strip.show();
}

void SwissNSignal::setLevel(uint8_t level) {
    _strip.setBrightness(level);
    if (!_isBlinking || _blinkState) {
        _strip.show();
    }
}

void SwissNSignal::update(uint32_t current_ms) {
    if (_isBlinking) {
        if (current_ms - _lastBlinkTime > 500) { // Blink every 500ms
            _lastBlinkTime = current_ms;
            _blinkState = !_blinkState;
            if (_blinkState) {
                // This will set the color
                uint32_t color;
                switch (_aspect) {
                    case N_ASPECT_OBSTRUCTION_AHEAD:
                        color = _strip.Color(255, 165, 0); // Orange
                        break;
                    case N_ASPECT_PREWARNING:
                        color = _strip.Color(255, 255, 0); // Yellow
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

void SwissNSignal::setAspect(SwissNSignalAspect aspect) {
    _aspect = aspect;
    _isBlinking = false;
    _strip.clear();

    // Simplified representation of Swiss N signals.
    // Does not include digit display or complex symbols.
    uint32_t color;
    switch (aspect) {
        case N_ASPECT_STOP:
            color = _strip.Color(255, 0, 0); // Red
            break;
        case N_ASPECT_CLEAR:
            color = _strip.Color(0, 255, 0); // Green
            break;
        case N_ASPECT_SPEED_40:
            color = _strip.Color(255, 255, 0); // Yellow
            break;
        case N_ASPECT_SPEED_60:
            color = _strip.Color(0, 255, 255); // Cyan
            break;
        case N_ASPECT_SPEED_90:
            color = _strip.Color(255, 0, 255); // Magenta
            break;
        case N_ASPECT_OBSTRUCTION_AHEAD:
            _isBlinking = true;
            color = _strip.Color(255, 165, 0); // Orange
            break;
        case N_ASPECT_TRACK_OCCUPIED:
            color = _strip.Color(255, 165, 0); // Orange
            break;
        case N_ASPECT_PREWARNING:
            _isBlinking = true;
            color = _strip.Color(255, 255, 0); // Yellow
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