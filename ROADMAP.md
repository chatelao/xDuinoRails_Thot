# Project Roadmap

This document outlines the development plan for the xDuinoRails_Thot, a cutting-edge, multi-protocol signal decoder based on the Seeed Studio XIAO RP2040.

## Phase 1: Core Functionality (MVP)

- [x] **1. Project Foundation**
    - [x] Integrate necessary libraries for DCC and Märklin-Motorola (MM) signal processing.
    - [x] Establish a basic firmware structure with protocol detection.
    - [x] Set up a robust build and test workflow using GitHub Actions.
- [x] **2. Basic Signal Control**
    - [x] Implement control for a simple 2-aspect (red/green) signal.
    - [x] Define hardware pins for signal outputs on the XIAO RP2040.
    - [x] Implement basic PWM control for LED brightness.
- [x] **3. Initial CV Configuration**
    - [x] Implement a basic CV structure for setting the decoder's address.
    - [x] Allow configuration of the signal type (e.g., 2-aspect, 3-aspect).

## Phase 2: Advanced Signal Features

- [ ] **1. Expanded Signal Logic**
    - [ ] Add support for 3- and 4-aspect signals.
    - [ ] Implement logic for common German (H/V, Ks) and Swiss signal systems.
    - [ ] Introduce a modular structure for easily adding new signal systems.
- [ ] **2. Realistic Effects**
    - [ ] Implement smooth dimming and transitions to simulate incandescent bulbs.
    - [ ] Add configurable effects like flickering for warning signals.
- [ ] **3. Comprehensive CV Table**
    - [ ] Develop a detailed CV table for configuring all aspects of the decoder, including signal types, dimming speeds, and special effects.
    - [ ] Create a user-friendly guide to the CV settings in `docs/CV_MAPPING.MD`.

## Phase 3: System Integration and Usability

- [ ] **1. Multi-Protocol Capability**
    - [ ] Implement runtime detection of DCC and MM signals.
    - [ ] Create a unified interface for signal control, independent of the underlying protocol.
- [ ] **2. Computer Control Integration**
    - [ ] Ensure full compatibility with popular control software like JMRI and Rocrail.
    - [ ] Develop a JMRI DecoderPro definition file for easy configuration.
- [ ] **3. User Documentation**
    - [ ] Create a comprehensive user manual in `docs/USER_MANUAL.MD`.
    - [ ] Provide detailed wiring diagrams and examples in the `hardware/` directory.

## Phase 4: Hardware Development

- [ ] **1. Design and Prototyping**
    - [ ] Define hardware requirements for a compact and versatile signal decoder.
    - [ ] Design a custom PCB with dedicated outputs for multiple signal heads.
    - [ ] Assemble and test the first hardware prototypes.
- [ ] **2. Production and Distribution**
    - [ ] Refine the hardware design for manufacturability.
    - [ ] Create a complete Bill of Materials (BOM) and assembly instructions.
    - [ ] Publish all hardware design files under an open-source license.

## Future Ideas

- [ ] RailCom Support for on-the-main programming and feedback.
- [ ] A network-based configuration interface (e.g., via Wi-Fi or Bluetooth).
- [ ] Support for complex signal scenarios, such as block signaling and interlocking.
- [ ] Integration with other xDuinoRails components for a complete layout control system.
