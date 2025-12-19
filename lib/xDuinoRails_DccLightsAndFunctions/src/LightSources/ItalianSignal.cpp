#include "ItalianSignal.h"

namespace xDuinoRails {

ItalianSignal::ItalianSignal(uint8_t pin, uint16_t numPixels)
    : _strip(numPixels, pin, NEO_GRB + NEO_KHZ800),
      _numPixels(numPixels),
      _aspect(IT_ASPECT_STOP),
      _lastBlinkTime(0),
      _isBlinking(false),
      _blinkState(false) {}

void ItalianSignal::begin() {
    _strip.begin();
    _strip.show(); // Initialize all pixels to 'off'
}

void ItalianSignal::on() {
    setAspect(_aspect);
}

void ItalianSignal::off() {
    _strip.clear();
    _strip.show();
}

void ItalianSignal::setLevel(uint8_t level) {
    _strip.setBrightness(level);
    if (!_isBlinking || _blinkState) {
        _strip.show();
    }
}

void ItalianSignal::update(uint32_t current_ms) {
    if (_isBlinking) {
        if (current_ms - _lastBlinkTime > 500) { // Blink every 500ms
            _lastBlinkTime = current_ms;
            _blinkState = !_blinkState;
            if (_blinkState) {
                uint32_t color1 = 0;
                uint32_t color2 = 0;
                switch (_aspect) {
                    case IT_ASPECT_PROCEED_100:
                        color1 = _strip.Color(0, 255, 0); // Green
                        if (_numPixels > 1) color2 = _strip.Color(255, 255, 0);
                        break;
                    case IT_ASPECT_PROCEED_60:
                        color1 = _strip.Color(0, 255, 0); // Green
                        if (_numPixels > 1) color2 = _strip.Color(255, 255, 0);
                        break;
                    case IT_ASPECT_EXPECT_STOP_ADVANCE:
                        color1 = _strip.Color(255, 255, 0); // Yellow
                        break;
                    case IT_ASPECT_PROCEED_CAUTION:
                        color1 = _strip.Color(0, 255, 0); // Green
                        if (_numPixels > 1) color2 = _strip.Color(0, 255, 0);
                        break;
                    default:
                        break;
                }
                 _strip.setPixelColor(0, color1);
                if (_numPixels > 1) _strip.setPixelColor(1, color2);
            } else {
                _strip.clear();
            }
            _strip.show();
        }
    }
}

void ItalianSignal::setAspect(ItalianSignalAspect aspect) {
    _aspect = aspect;
    _isBlinking = false;
    _strip.clear();

    uint32_t color1 = 0;
    uint32_t color2 = 0;

    switch (aspect) {
        case IT_ASPECT_STOP:
            color1 = _strip.Color(255, 0, 0); // Red
            break;
        case IT_ASPECT_PROCEED:
            color1 = _strip.Color(0, 255, 0); // Green
            break;
        case IT_ASPECT_PROCEED_SLOW:
            color1 = _strip.Color(255, 0, 0); // Red
            if(_numPixels > 1) color2 = _strip.Color(0, 255, 0);
            break;
        case IT_ASPECT_PROCEED_100:
        case IT_ASPECT_PROCEED_60:
            _isBlinking = true;
            break;
        case IT_ASPECT_PROCEED_30:
             color1 = _strip.Color(0, 255, 0); // Green
             if(_numPixels > 1) color2 = _strip.Color(255, 255, 0);
             break;
        case IT_ASPECT_EXPECT_STOP:
            color1 = _strip.Color(255, 255, 0); // Yellow
            break;
        case IT_ASPECT_EXPECT_STOP_ADVANCE:
            _isBlinking = true;
            color1 = _strip.Color(255, 255, 0); // Yellow
            break;
        case IT_ASPECT_PROCEED_CAUTION:
            _isBlinking = true;
            break;
        default:
            break;
    }

    _strip.setPixelColor(0, color1);
    if (_numPixels > 1) _strip.setPixelColor(1, color2);


    if (!_isBlinking) {
        _strip.show();
    }
}

} // namespace xDuinoRails