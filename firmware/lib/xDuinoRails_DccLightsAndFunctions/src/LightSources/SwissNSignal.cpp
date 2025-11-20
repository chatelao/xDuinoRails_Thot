#include "SwissNSignal.h"

namespace xDuinoRails {

//       A
//      ---
//   F |   | B
//     | G |
//      ---
//   E |   | C
//     |   |
//      ---
//       D
const byte seven_segment_map[10][7] = {
  { 1,1,1,1,1,1,0 },  // 0
  { 0,1,1,0,0,0,0 },  // 1
  { 1,1,0,1,1,0,1 },  // 2
  { 1,1,1,1,0,0,1 },  // 3
  { 0,1,1,0,0,1,1 },  // 4
  { 1,0,1,1,0,1,1 },  // 5
  { 1,0,1,1,1,1,1 },  // 6
  { 1,1,1,0,0,0,0 },  // 7
  { 1,1,1,1,1,1,1 },  // 8
  { 1,1,1,1,0,1,1 }   // 9
};

void SwissNSignal::displayDigit(int digit) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(_seven_segment_pins[i], seven_segment_map[digit][i]);
  }
}

SwissNSignal::SwissNSignal(uint8_t pin, uint16_t numPixels, const int* seven_segment_pins)
    : _strip(numPixels, pin, NEO_GRB + NEO_KHZ800), _numPixels(numPixels),
      _aspect(N_ASPECT_STOP), _lastBlinkTime(0), _isBlinking(false),
      _blinkState(false), _seven_segment_pins(seven_segment_pins) {
        for (int i = 0; i < 7; i++) {
            pinMode(_seven_segment_pins[i], OUTPUT);
        }
      }

void SwissNSignal::begin() { _strip.begin(); }

void SwissNSignal::on() {
  setAspect(_aspect);
}

void SwissNSignal::off() {
  _strip.clear();
  for (int i = 0; i < 7; i++) {
    digitalWrite(_seven_segment_pins[i], 0);
  }
  _strip.show();
}

void SwissNSignal::setLevel(uint8_t level) { _strip.setBrightness(level); }

void SwissNSignal::update(uint32_t current_ms) {
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

void SwissNSignal::setAspect(SwissNSignalAspect aspect) {
  _aspect = aspect;
  _isBlinking = false;
  _strip.clear();
  for (int i = 0; i < 7; i++) {
    digitalWrite(_seven_segment_pins[i], 0);
  }

  switch (_aspect) {
  case N_ASPECT_STOP:
    _strip.setPixelColor(0, _strip.Color(255, 0, 0)); // Red
    break;
  case N_ASPECT_CLEAR:
    _strip.setPixelColor(0, _strip.Color(0, 255, 0)); // Green
    break;
  case N_ASPECT_SPEED_40:
    _strip.setPixelColor(0, _strip.Color(0, 255, 0)); // Green
    displayDigit(4);
    break;
  case N_ASPECT_SPEED_60:
    _strip.setPixelColor(0, _strip.Color(0, 255, 0)); // Green
    displayDigit(6);
    break;
  case N_ASPECT_SPEED_90:
    _strip.setPixelColor(0, _strip.Color(0, 255, 0)); // Green
    displayDigit(9);
    break;
  case N_ASPECT_SPEED_ANNOUNCEMENT_40:
    _strip.setPixelColor(0, _strip.Color(255, 255, 0)); // Yellow
    displayDigit(4);
    break;
  case N_ASPECT_SPEED_ANNOUNCEMENT_60:
    _strip.setPixelColor(0, _strip.Color(255, 255, 0)); // Yellow
    displayDigit(6);
    break;
  case N_ASPECT_SPEED_ANNOUNCEMENT_90:
    _strip.setPixelColor(0, _strip.Color(255, 255, 0)); // Yellow
    displayDigit(9);
    break;
  case N_ASPECT_OBSTRUCTION_AHEAD:
    _strip.setPixelColor(0, _strip.Color(255, 255, 0)); // Yellow
    _isBlinking = true;
    break;
  case N_ASPECT_TRACK_OCCUPIED:
    _strip.setPixelColor(0, _strip.Color(255, 255, 0)); // Yellow
    break;
  case N_ASPECT_PREWARNING:
    _strip.setPixelColor(0, _strip.Color(255, 255, 0)); // Yellow
    break;
  }

  _strip.show();
}

} // namespace xDuinoRails