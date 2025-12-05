#pragma once
#include <stdint.h>

class Servo {
public:
    uint8_t attach(int pin) { return 1; }
    uint8_t attach(int pin, int min, int max) { return 1; }
    void detach() {}
    void write(int value) {}
    void writeMicroseconds(int value) {}
    int read() { return 90; }
    int readMicroseconds() { return 1500; }
    bool attached() { return true; }
};
