#include "SwissLSignal.h"

namespace xDuinoRails {

SwissLSignal::SwissLSignal(uint8_t pin, uint16_t numPixels)
    : _strip(numPixels, pin, NEO_GRB + NEO_KHZ800), _numPixels(numPixels),
      _aspect(L_ASPECT_STOP), _lastBlinkTime(0), _isBlinking(false),
      _blinkState(false) {}

void SwissLSignal::begin() { _strip.begin(); }

void SwissLSignal::on() {
    setAspect(_aspect);
}

void SwissLSignal::off() {
  _strip.clear();
  _strip.show();
}

void SwissLSignal::setLevel(uint8_t level) { _strip.setBrightness(level); }

void SwissLSignal::update(uint32_t current_ms) {
    if (_isBlinking && (current_ms - _lastBlinkTime > 500)) {
        _lastBlinkTime = current_ms;
        _blinkState = !_blinkState;
        if (_blinkState) {
            setAspect(_aspect);
        } else {
            _strip.clear();
            _strip.show();
        }
    }
}

void SwissLSignal::setAspect(SwissLSignalAspect aspect) {
  _aspect = aspect;
  _isBlinking = false;
  _strip.clear();

  switch (_aspect) {
  case L_ASPECT_STOP:
    _strip.setPixelColor(0, _strip.Color(255, 0, 0)); // Red
    break;
  case L_ASPECT_CLEAR:
    _strip.setPixelColor(0, _strip.Color(0, 255, 0)); // Green
    break;
  case L_ASPECT_SPEED_40:
    _strip.setPixelColor(0, _strip.Color(0, 255, 0)); // Green
    _strip.setPixelColor(1, _strip.Color(255, 255, 0)); // Yellow
    break;
  case L_ASPECT_SPEED_60:
    _strip.setPixelColor(0, _strip.Color(0, 255, 0)); // Green
    _strip.setPixelColor(1, _strip.Color(0, 255, 0)); // Green
    break;
  case L_ASPECT_SPEED_90:
    _strip.setPixelColor(0, _strip.Color(0, 255, 0)); // Green
    _strip.setPixelColor(1, _strip.Color(0, 255, 0)); // Green
    _strip.setPixelColor(2, _strip.Color(0, 255, 0)); // Green
    break;
  case L_ASPECT_SHORT_PROCEED:
    _strip.setPixelColor(0, _strip.Color(255, 255, 0)); // Yellow
    _strip.setPixelColor(1, _strip.Color(255, 255, 0)); // Yellow
    break;
  case L_ASPECT_PROCEED_CAUTION:
    _strip.setPixelColor(0, _strip.Color(255, 255, 0)); // Yellow
    _isBlinking = true;
    break;

  // Zp System
  case L_ASPECT_ZP_ABFAHREN: // SMS (P0)
    _strip.setPixelColor(0, _strip.Color(255, 165, 0)); // Orange
    break;
  case L_ASPECT_ZP_APPLY: // Apply (P1)
    _strip.setPixelColor(1, _strip.Color(255, 255, 255));
    break;
  case L_ASPECT_ZP_RELEASE: // Release (P1 + P2)
    _strip.setPixelColor(1, _strip.Color(255, 255, 255));
    _strip.setPixelColor(2, _strip.Color(255, 255, 255));
    break;
  case L_ASPECT_ZP_OK: // OK (P1 + P2 + P3)
    _strip.setPixelColor(1, _strip.Color(255, 255, 255));
    _strip.setPixelColor(2, _strip.Color(255, 255, 255));
    _strip.setPixelColor(3, _strip.Color(255, 255, 255));
    break;
  }

  _strip.show();
}

} // namespace xDuinoRails