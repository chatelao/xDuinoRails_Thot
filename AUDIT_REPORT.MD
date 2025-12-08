# Audit Report

Date: 2024-05-22
Scope: Full Codebase Review (Firmware, Webtool, Documentation, DevOps)

## Summary
The codebase contains a solid foundation for signal definitions (XML) and a functional Webtool for viewing them. However, the firmware implementation is largely a placeholder/demo, and the project suffers from significant technical debt in testing and CI/CD configuration.

## 1. Critical Defects (Mängel)

### Firmware
- **`src/main.cpp` is a Demo:** The main entry point `main.cpp` does not implement a DCC decoder. It runs a blocking `delay(3000)` loop that cycles aspects automatically. It ignores `SignalManager` updates from DCC (if any existed).
- **`DutchSignal` Implementation:** The `DutchSignal` class incorrectly drives all connected NeoPixels with the same color, failing to represent prototypical multi-light signals.
- **Hardcoded Configuration:** `SignalManager.h` contains hardcoded GPIO pins (`NEOPIXEL_PIN 2`, `seven_segment_pins`), making it impossible to change pin mapping without recompiling.
- **Missing Build Flags:** Code relies on `SIGNAL_TYPE_...` defines, but the implementation in `SignalManager.h` is a monolithic switch-case that instantiates the wrong class if the build flag mismatches the hardware.

### Webtool
- **Regression in Gallery:** `webtool/gallery.html` lacks the logic to render `<decoration>` elements (e.g., static crosses, rings), which causes signals like `CH-Rangierhaltsignal-V2` to appear incorrect compared to `index.html`.
- **Hardcoded Lists:** The list of supported countries is hardcoded in both `index.html` and `gallery.html`, requiring manual updates when adding new country XMLs.

### DevOps & CI
- **Broken CI Pipeline:** The GitHub Actions workflow `build.yml` fails to find `picotool`, causing build artifacts to potentially fail deployment (though validation passes).
- **Limited CI Scope:** The CI only builds the `xiao_signal_decoder` (Dutch) environment. Other country environments are not verified, increasing the risk of broken builds for other regions.
- **Unpinned Dependencies:** `requirements.txt` and `platformio.ini` do not pin dependency versions (e.g., `Adafruit NeoPixel`, `lxml`), leading to potential reproducibility issues.

## 2. Areas for Improvement (Verbesserungsbedarf)

### Testing
- **Extremely Low Coverage:** Only 3 test cases exist (`test_effects`, `test_rcn227`). Core signal logic is untested.
- **No CI Testing:** `pio test` is not executed in the CI pipeline.

### Documentation
- **Missing Tools:** `webtool/editor.html` is a placeholder.
- **Missing Integration Docs:** JMRI definition is missing (`docs/IMPLEMENTATION_STATUS.MD`).

### Architecture
- **Monolithic `SignalManager`:** The `SignalManager` class couples all signal types tightly. A Factory pattern or Dependency Injection would be cleaner.
- **Magic Numbers:** Extensive use of hardcoded values (colors, timings, pin numbers) throughout the `LightSources` library.

## 3. Recommendations

1.  **Refactor Firmware:** Rewrite `main.cpp` to implement actual DCC packet handling (using the `nmra-dcc` library or similar).
2.  **Fix `DutchSignal`:** Map aspects to specific pixels in `DutchSignal.cpp`.
3.  **Update CI:** Add `pio test` to the workflow and build all environments (`env:xiao_signal_decoder_de`, etc.).
4.  **Fix Webtool:** Synchronize rendering logic between `index.html` and `gallery.html` (completed in this audit).
5.  **Pin Dependencies:** Specify versions in `platformio.ini` and `requirements.txt`.
