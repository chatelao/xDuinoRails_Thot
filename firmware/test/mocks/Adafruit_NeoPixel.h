#pragma once
#include <stdint.h>

// Mock types
typedef uint16_t neoPixelType;
#define NEO_GRB 1
#define NEO_KHZ800 1

class Adafruit_NeoPixel {
public:
    Adafruit_NeoPixel(uint16_t n, int16_t p, neoPixelType t) {}
    Adafruit_NeoPixel() {}
    ~Adafruit_NeoPixel() {}

    void begin() {}
    void show() {}
    void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b) {}
    void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w) {}
    void setPixelColor(uint16_t n, uint32_t c) {}
    void setBrightness(uint8_t) {}
    void clear() {}
    void updateLength(uint16_t n) {}
    void updateType(neoPixelType t) {}
    uint16_t numPixels() const { return 0; }
    static uint32_t Color(uint8_t r, uint8_t g, uint8_t b) { return 0; }
    static uint32_t Color(uint8_t r, uint8_t g, uint8_t b, uint8_t w) { return 0; }
    uint32_t getPixelColor(uint16_t n) const { return 0; }
};
