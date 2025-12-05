/**
 * @file test_rcn227.cpp
 * @brief Unit tests for RCN-227 Function Mapping logic in AuxController.
 */

#include <unity.h>
#include <ArduinoFake.h>
#include "AuxController.h"
#include "interfaces/ICVAccess.h"
#include "LightSources/LightSource.h"
#include <map>
#include <memory>

using namespace xDuinoRails;
using namespace fakeit;

// --- Mocks ---

class PageAwareMockCVAccess : public ICVAccess {
public:
    std::map<uint32_t, std::map<uint16_t, uint8_t>> pages;
    uint16_t current_high = 0;
    uint16_t current_low = 0;
    uint8_t defaultValue = 0;

    uint8_t readCV(uint16_t cv_number) override {
        if (cv_number == 31) return (uint8_t)current_high;
        if (cv_number == 32) return (uint8_t)current_low;

        uint32_t page = (current_high << 8) | current_low;
        if (pages[page].find(cv_number) != pages[page].end()) {
            return pages[page][cv_number];
        }
        return defaultValue;
    }

    void writeCV(uint16_t cv_number, uint8_t value) override {
        if (cv_number == 31) { current_high = value; return; }
        if (cv_number == 32) { current_low = value; return; }

        uint32_t page = (current_high << 8) | current_low;
        pages[page][cv_number] = value;
    }

    void clear() { pages.clear(); current_high = 0; current_low = 0; }

    void setCV(uint32_t page, uint16_t cv, uint8_t value) {
        pages[page][cv] = value;
    }
};

class MockLightSource : public LightSource {
public:
    bool isOn = false;
    uint8_t currentLevel = 0;

    void begin() override {}
    void on() override { isOn = true; currentLevel = 255; }
    void off() override { isOn = false; currentLevel = 0; }
    void setLevel(uint8_t level) override { currentLevel = level; isOn = (level > 0); }
    void update(uint32_t delta_ms) override {}
};

// --- Test Fixture ---

AuxController* controller;
PageAwareMockCVAccess* mockCV;

void setUp(void) {
    ArduinoFakeReset();
    controller = new AuxController();
    mockCV = new PageAwareMockCVAccess();
}

void tearDown(void) {
    delete controller;
    delete mockCV;
}

// --- Tests ---

void test_rcn227_per_output_v1_parsing(void) {
    mockCV->setCV(0, 96, 3); // Method V1

    // Page 41: Output 1 (Index 0), Fwd (0)
    // base_cv = 257
    // Map to F0 (Bit 0)
    mockCV->setCV(41, 257, 1);

    // Effect Page 50 for Output 1
    // Type = 0 (Steady)
    mockCV->setCV(50, 257, 0);

    // Add Mock Output
    auto ls = std::unique_ptr<LightSource>(new MockLightSource());
    MockLightSource* lsPtr = static_cast<MockLightSource*>(ls.get());
    controller->addLightSource(std::move(ls));

    // Load
    controller->loadFromCVs(*mockCV);

    // Verify
    TEST_ASSERT_NOT_NULL(controller->getLogicalFunction(0));

    // F0 = true -> Output ON
    controller->setFunctionState(0, true);
    controller->setDirection(DECODER_DIRECTION_FORWARD);
    controller->update(100);
    TEST_ASSERT_EQUAL_UINT8(255, lsPtr->currentLevel);

    // F0 = false -> Output OFF
    controller->setFunctionState(0, false);
    controller->update(100);
    TEST_ASSERT_EQUAL_UINT8(0, lsPtr->currentLevel);
}

void test_rcn227_per_output_v2_parsing(void) {
    mockCV->defaultValue = 255;
    mockCV->setCV(0, 96, 4); // Method V2

    // Page 42
    // Output 1 (Index 0), Fwd (0)
    // base_cv = 257 + (0*2 + 0)*4 = 257
    // Funcs: F1 (1), F2 (2), None
    mockCV->setCV(42, 257, 1);
    mockCV->setCV(42, 258, 2);
    mockCV->setCV(42, 259, 255);
    mockCV->setCV(42, 260, 255); // No blocking

    // Effect Page 50 for Output 1
    mockCV->setCV(50, 257, 0);

    auto ls = std::unique_ptr<LightSource>(new MockLightSource());
    MockLightSource* lsPtr = static_cast<MockLightSource*>(ls.get());
    controller->addLightSource(std::move(ls));

    controller->loadFromCVs(*mockCV);

    // F1 -> ON
    controller->setFunctionState(1, true);
    controller->setDirection(DECODER_DIRECTION_FORWARD);
    controller->update(100);
    TEST_ASSERT_EQUAL_UINT8(255, lsPtr->currentLevel);

    // F1 OFF -> OFF
    controller->setFunctionState(1, false);
    controller->update(100);
    TEST_ASSERT_EQUAL_UINT8(0, lsPtr->currentLevel);

    // F2 -> ON
    controller->setFunctionState(2, true);
    controller->update(100);
    TEST_ASSERT_EQUAL_UINT8(255, lsPtr->currentLevel);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_rcn227_per_output_v1_parsing);
    RUN_TEST(test_rcn227_per_output_v2_parsing);
    return UNITY_END();
}
