#ifndef PHYSICALOUTPUT_H
#define PHYSICALOUTPUT_H

#include <cstdint>
#include <memory>
#include "LightSources/LightSource.h"

namespace xDuinoRails {

class PhysicalOutput {
public:
    PhysicalOutput(std::unique_ptr<LightSource> lightSource);
    void begin();
    void setValue(uint8_t value);
    void update(uint32_t delta_ms);

private:
    std::unique_ptr<LightSource> _lightSource;
};

}

#endif // PHYSICALOUTPUT_H
