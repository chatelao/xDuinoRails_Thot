#include "PhysicalOutput.h"

namespace xDuinoRails {

PhysicalOutput::PhysicalOutput(std::unique_ptr<LightSource> lightSource) :
    _lightSource(std::move(lightSource))
{}

void PhysicalOutput::begin() {
    _lightSource->begin();
}

void PhysicalOutput::setValue(uint8_t value) {
    if (value > 0) {
        _lightSource->on();
        _lightSource->setLevel(value);
    } else {
        _lightSource->off();
    }
}

void PhysicalOutput::update(uint32_t delta_ms) {
    _lightSource->update(delta_ms);
}

}
