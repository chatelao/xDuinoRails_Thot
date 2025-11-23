#include "PolishSignal.h"

namespace xDuinoRails {

PolishSignal::PolishSignal(uint8_t pin, uint16_t numPixels)
    : _strip(numPixels, pin, NEO_GRB + NEO_KHZ800), _numPixels(numPixels),
      _aspect(PL_ASPECT_S1), _lastBlinkTime(0), _isBlinking(false),
      _blinkState(false) {}

void PolishSignal::begin() { _strip.begin(); }

void PolishSignal::on() {
    setAspect(_aspect);
}

void PolishSignal::off() {
    _strip.clear();
    _strip.show();
}

void PolishSignal::setLevel(uint8_t level) { _strip.setBrightness(level); }

void PolishSignal::update(uint32_t current_ms) {
    if (_isBlinking && (current_ms - _lastBlinkTime > 500)) {
        _lastBlinkTime = current_ms;
        _blinkState = !_blinkState;
        render();
    }
}

void PolishSignal::setAspect(PolishSignalAspect aspect) {
    _aspect = aspect;

    switch(aspect) {
        case PL_ASPECT_S3:
        case PL_ASPECT_S4:
        case PL_ASPECT_S11:
        case PL_ASPECT_S12:
        case PL_ASPECT_SZ:
        case PL_ASPECT_OS3:
        case PL_ASPECT_OS4:
            _isBlinking = true;
            break;
        default:
            _isBlinking = false;
            break;
    }

    // Always start with blink ON phase
    _blinkState = true;
    render();
}

void PolishSignal::render() {
    _strip.clear();

    // Helper colors
    uint32_t cRed    = _strip.Color(255, 0, 0);
    uint32_t cGreen  = _strip.Color(0, 255, 0);
    uint32_t cOrange = _strip.Color(255, 140, 0);
    uint32_t cBlue   = _strip.Color(0, 0, 255);
    uint32_t cWhite  = _strip.Color(255, 255, 255);

    // Define pixel indices (based on assumption)
    // Main
    uint8_t pMainGreen  = 0;
    uint8_t pMainOrangeTop = 1;
    uint8_t pMainRed    = 2;
    uint8_t pMainOrangeBot = 3;
    uint8_t pMainWhite  = 4;

    // Shunt (Blue, White) - assuming separate hardware or indices 0,1
    uint8_t pShuntBlue  = 0;
    uint8_t pShuntWhite = 1;

    // Distant (Green, Orange) - assuming indices 0,1
    uint8_t pDistGreen  = 0;
    uint8_t pDistOrange = 1;

    switch (_aspect) {
        // Main Signal Aspects
        case PL_ASPECT_S1: // Red
            _strip.setPixelColor(pMainRed, cRed);
            break;
        case PL_ASPECT_S2: // Green Top
            _strip.setPixelColor(pMainGreen, cGreen);
            break;
        case PL_ASPECT_S3: // Green Top Blinking
            if (_blinkState) _strip.setPixelColor(pMainGreen, cGreen);
            break;
        case PL_ASPECT_S4: // Orange Top Blinking
            if (_blinkState) _strip.setPixelColor(pMainOrangeTop, cOrange);
            break;
        case PL_ASPECT_S5: // Orange Top
            _strip.setPixelColor(pMainOrangeTop, cOrange);
            break;
        case PL_ASPECT_S10: // Green Top + Orange Bottom
            _strip.setPixelColor(pMainGreen, cGreen);
            _strip.setPixelColor(pMainOrangeBot, cOrange);
            break;
        case PL_ASPECT_S11: // Green Top Blinking + Orange Bottom
            if (_blinkState) _strip.setPixelColor(pMainGreen, cGreen);
            _strip.setPixelColor(pMainOrangeBot, cOrange);
            break;
        case PL_ASPECT_S12: // Orange Top Blinking + Orange Bottom
            if (_blinkState) _strip.setPixelColor(pMainOrangeTop, cOrange);
            _strip.setPixelColor(pMainOrangeBot, cOrange);
            break;
        case PL_ASPECT_S13: // Orange Top + Orange Bottom
            _strip.setPixelColor(pMainOrangeTop, cOrange);
            _strip.setPixelColor(pMainOrangeBot, cOrange);
            break;
        case PL_ASPECT_SZ: // Red + White Blinking
            _strip.setPixelColor(pMainRed, cRed);
            if (_blinkState) _strip.setPixelColor(pMainWhite, cWhite);
            break;

        // Shunting
        case PL_ASPECT_MS1: // Blue
            _strip.setPixelColor(pShuntBlue, cBlue);
            break;
        case PL_ASPECT_MS2: // White
            _strip.setPixelColor(pShuntWhite, cWhite);
            break;

        // Distant
        case PL_ASPECT_OS1: // Orange
            _strip.setPixelColor(pDistOrange, cOrange);
            break;
        case PL_ASPECT_OS2: // Green
            _strip.setPixelColor(pDistGreen, cGreen);
            break;
        case PL_ASPECT_OS3: // Green Blinking
            if (_blinkState) _strip.setPixelColor(pDistGreen, cGreen);
            break;
        case PL_ASPECT_OS4: // Orange Blinking
            if (_blinkState) _strip.setPixelColor(pDistOrange, cOrange);
            break;
    }
    _strip.show();
}

} // namespace xDuinoRails
