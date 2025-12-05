# How To Use

## Installation
1. Flash the firmware using PlatformIO for your target board (e.g., Seeed XIAO RP2040).
   Example for German Signals:
   ```bash
   python -m platformio run -d firmware -e xiao_signal_decoder_de -t upload
   ```
2. Connect the decoder to the DCC track signal (Default Pin: D2).
3. Connect LEDs to the outputs (Pins depend on configured signal).

## Configuration (CVs)
The decoder supports RCN-213 (Signals) and RCN-227 (Function Mapping) standards.

### Addressing
- **CV 1**: Primary Address (Default: 3)
- **CV 17/18**: Extended Address
- **CV 29**: Configuration (Bit 5 enables Extended Address)

### Signal Configuration
- Signals are defined in XML files (`firmware/definitions/`).
- The active signal system is determined by the build environment (e.g., `SIGNAL_TYPE_GERMAN`).

### Function Mapping
- The decoder implements RCN-227 Function Mapping (System per Output V1 & V2).
- This allows mapping any DCC function (F0-F28) to any physical output, including conditions like direction.
