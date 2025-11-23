#include "GermanSignal.h"

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

GermanSignal::GermanSignal(uint8_t pin, uint16_t numPixels, const int* seven_segment_pins)
    : _strip(numPixels, pin, NEO_GRB + NEO_KHZ800), _numPixels(numPixels),
      _aspect(DE_ASPECT_HP0), _lastBlinkTime(0), _isBlinking(false),
      _blinkState(false), _seven_segment_pins(seven_segment_pins) {
        if (_seven_segment_pins) {
            for (int i = 0; i < 7; i++) {
                pinMode(_seven_segment_pins[i], OUTPUT);
            }
        }
      }

void GermanSignal::begin() { _strip.begin(); }

void GermanSignal::on() {
    setAspect(_aspect);
}

void GermanSignal::off() {
  _strip.clear();
  if (_seven_segment_pins) {
      for (int i = 0; i < 7; i++) {
        digitalWrite(_seven_segment_pins[i], 0);
      }
  }
  _strip.show();
}

void GermanSignal::setLevel(uint8_t level) { _strip.setBrightness(level); }

void GermanSignal::displayDigit(int digit) {
    if (!_seven_segment_pins) return;
    for (int i = 0; i < 7; i++) {
        digitalWrite(_seven_segment_pins[i], seven_segment_map[digit][i]);
    }
}

void GermanSignal::update(uint32_t current_ms) {
    if (_isBlinking && (current_ms - _lastBlinkTime > 500)) {
        _lastBlinkTime = current_ms;
        _blinkState = !_blinkState;
        if (_blinkState) {
            setAspect(_aspect);
        } else {
            _strip.clear();
            if (_seven_segment_pins) {
                for (int i = 0; i < 7; i++) {
                    digitalWrite(_seven_segment_pins[i], 0);
                }
            }
            _strip.show();
        }
    }
}

void GermanSignal::setAspect(GermanSignalAspect aspect) {
  _aspect = aspect;
  _isBlinking = false;
  _strip.clear();
  if (_seven_segment_pins) {
      for (int i = 0; i < 7; i++) {
        digitalWrite(_seven_segment_pins[i], 0);
      }
  }

  switch (_aspect) {
  // H/V
  case DE_ASPECT_HP0: // Stop: Red (L2)
    _strip.setPixelColor(1, _strip.Color(255, 0, 0));
    break;
  case DE_ASPECT_HP1: // Clear: Green (L1)
    _strip.setPixelColor(0, _strip.Color(0, 255, 0));
    break;
  case DE_ASPECT_HP2: // Slow: Green (L1) + Yellow (L3)
    _strip.setPixelColor(0, _strip.Color(0, 255, 0));
    _strip.setPixelColor(2, _strip.Color(255, 255, 0));
    break;

  case DE_ASPECT_VR0: // Expect Stop: Yellow (L2) + Yellow (L4)
    _strip.setPixelColor(1, _strip.Color(255, 255, 0));
    _strip.setPixelColor(3, _strip.Color(255, 255, 0));
    break;
  case DE_ASPECT_VR1: // Expect Clear: Green (L1) + Green (L3)
    _strip.setPixelColor(0, _strip.Color(0, 255, 0));
    _strip.setPixelColor(2, _strip.Color(0, 255, 0));
    break;
  case DE_ASPECT_VR2: // Expect Slow: Green (L1) + Yellow (L4)
    _strip.setPixelColor(0, _strip.Color(0, 255, 0));
    _strip.setPixelColor(3, _strip.Color(255, 255, 0));
    break;

  case DE_ASPECT_SH0: // Stop Shunting: Red (L2) + Red (L3)
    _strip.setPixelColor(1, _strip.Color(255, 0, 0));
    _strip.setPixelColor(2, _strip.Color(255, 0, 0));
    break;
  case DE_ASPECT_SH1: // Clear Shunting: White (L1) + White (L4)
    _strip.setPixelColor(0, _strip.Color(255, 255, 255));
    _strip.setPixelColor(3, _strip.Color(255, 255, 255));
    break;

  // Ks
  case DE_ASPECT_KS1: // Green (L1)
    _strip.setPixelColor(0, _strip.Color(0, 255, 0));
    break;
  case DE_ASPECT_KS2: // Yellow (L3)
    _strip.setPixelColor(2, _strip.Color(255, 255, 0));
    break;
  case DE_ASPECT_KS1_BLINK: // Green (L1) Blinking
    _strip.setPixelColor(0, _strip.Color(0, 255, 0));
    _isBlinking = true;
    break;
  case DE_ASPECT_KS1_ZS3_4: // Green (L1) + Digit 4
    _strip.setPixelColor(0, _strip.Color(0, 255, 0));
    displayDigit(4);
    break;
  case DE_ASPECT_KS1_ZS3_6: // Green (L1) + Digit 6
    _strip.setPixelColor(0, _strip.Color(0, 255, 0));
    displayDigit(6);
    break;
  case DE_ASPECT_KS1_ZS3_8: // Green (L1) + Digit 8
    _strip.setPixelColor(0, _strip.Color(0, 255, 0));
    displayDigit(8);
    break;
  case DE_ASPECT_KS2_ZS3_4: // Yellow (L3) + Digit 4
    _strip.setPixelColor(2, _strip.Color(255, 255, 0));
    displayDigit(4);
    break;

  // Hl
  case DE_ASPECT_HL1: // Green Top (L2/P1)
    _strip.setPixelColor(1, _strip.Color(0, 255, 0));
    break;
  case DE_ASPECT_HL13: // Red (L3/P2)
    _strip.setPixelColor(2, _strip.Color(255, 0, 0));
    break;
  case DE_ASPECT_HL10: // Yellow Top (L1/P0)
    _strip.setPixelColor(0, _strip.Color(255, 255, 0));
    break;
  case DE_ASPECT_HL12A: // Yellow Top (L1/P0) + Yellow Bot (L4/P3)
    _strip.setPixelColor(0, _strip.Color(255, 255, 0));
    _strip.setPixelColor(3, _strip.Color(255, 255, 0));
    break;

  // Zp System
  case DE_ASPECT_ZP9: // Green Ring (P0)
    _strip.setPixelColor(0, _strip.Color(0, 255, 0));
    break;
  case DE_ASPECT_ZP6: // White Top (P1)
    _strip.setPixelColor(1, _strip.Color(255, 255, 255));
    break;
  case DE_ASPECT_ZP7: // White Top (P1) + Mid (P2)
    _strip.setPixelColor(1, _strip.Color(255, 255, 255));
    _strip.setPixelColor(2, _strip.Color(255, 255, 255));
    break;
  case DE_ASPECT_ZP8: // White Top (P1) + Mid (P2) + Bot (P3)
    _strip.setPixelColor(1, _strip.Color(255, 255, 255));
    _strip.setPixelColor(2, _strip.Color(255, 255, 255));
    _strip.setPixelColor(3, _strip.Color(255, 255, 255));
    break;
  }

  _strip.show();
}

} // namespace xDuinoRails
