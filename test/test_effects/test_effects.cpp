/**
 * @file test_effects.cpp
 * @brief Unit tests for Lighting Effects.
 */

#include <unity.h>
#include <ArduinoFake.h>
#include "effects/Effect.h"
#include "PhysicalOutput.h"
#include "LightSources/LightSource.h"
#include <vector>
#include <memory>

using namespace xDuinoRails;
using namespace fakeit;

// --- Mocks ---

class MockLightSource : public LightSource {
public:
    uint8_t currentLevel = 0;
    void begin() override {}
    void on() override { currentLevel = 255; }
    void off() override { currentLevel = 0; }
    void setLevel(uint8_t level) override { currentLevel = level; }
    void update(uint32_t delta_ms) override {}
};

// --- Test Fixture ---

std::vector<PhysicalOutput*> outputs;
std::vector<std::unique_ptr<PhysicalOutput>> output_owners;
MockLightSource* mockLS;

void setUp(void) {
    ArduinoFakeReset();
    outputs.clear();
    output_owners.clear();

    auto ls = std::unique_ptr<LightSource>(new MockLightSource());
    mockLS = static_cast<MockLightSource*>(ls.get());
    output_owners.push_back(std::unique_ptr<PhysicalOutput>(new PhysicalOutput(std::move(ls))));
    outputs.push_back(output_owners.back().get());
}

void tearDown(void) {
    outputs.clear();
    output_owners.clear();
}

// --- Tests ---

void test_neon_flicker_effect(void) {
    // Goal: Verify that the Neon Flicker effect transitions from flickering to steady.
    // Steps:
    // 1. Initialize effect with 1000ms ignition time, 255 brightness.
    // 2. Set active.
    // 3. Mock random() to control toggle timing.
    // 4. Update and check output values (flickering).
    // 5. Advance time past ignition time.
    // 6. Check output is steady 255.

    // Mock random(min, max) to always return 50ms
    When(OverloadedMethod(ArduinoFake(), random, long(long, long))).AlwaysReturn(50);

    EffectNeonFlicker effect(1000, 255);
    effect.setActive(true);

    // Initial state: IGNITING, timer=0, current_on=false (default in constructor)
    // Update 10ms. Timer=10. flicker_timer=10. next_toggle=0.
    // 10 >= 0 -> toggle! current_on=true. next_toggle=50.

    // First update: Should turn ON immediately
    effect.update(10, outputs);
    TEST_ASSERT_EQUAL_UINT8(255, mockLS->currentLevel);

    // Update 50ms.
    // flicker_timer = 0 + 50 = 50. >= 50.
    // Toggle! current_on=false. next=50.
    // output = 0.
    effect.update(50, outputs);
    TEST_ASSERT_EQUAL_UINT8(0, mockLS->currentLevel);

    // Update 40ms. flicker_timer=40. < 50.
    // No toggle. Output = 0.
    effect.update(40, outputs);
    TEST_ASSERT_EQUAL_UINT8(0, mockLS->currentLevel);

    // Update 10ms. flicker_timer=50. >= 50.
    // Toggle! current_on=true. next=50.
    // Output = 255.
    effect.update(10, outputs);
    TEST_ASSERT_EQUAL_UINT8(255, mockLS->currentLevel);

    // Fast forward to > 1000ms.
    // Total elapsed so far: 110ms.
    // Update 1000ms. Timer=1110. State -> STEADY.
    effect.update(1000, outputs);
    TEST_ASSERT_EQUAL_UINT8(255, mockLS->currentLevel);

    // Verify it stays ON
    effect.update(100, outputs);
    TEST_ASSERT_EQUAL_UINT8(255, mockLS->currentLevel);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_neon_flicker_effect);
    return UNITY_END();
}
