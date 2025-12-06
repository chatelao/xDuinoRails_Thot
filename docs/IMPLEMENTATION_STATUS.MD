# Implementation Status of LIGHT_AND_AUX_CONCEPT.MD

This document outlines the current implementation status of the features described in `LIGHT_AND_AUX_CONCEPT.MD`.

## 2. Core Concepts

### 2.1. Physical Outputs

- [x] **`PhysicalOutput` Class**: Supports basic types.
- [x] **`PWM` Output Type**
- [x] **`SERVO` Output Type**
- [ ] **`PWM_HIGH_SIDE` Output Type**
- [ ] **`PWM_LOW_SIDE` Output Type**
- [ ] **`ON_OFF` Output Type**
- [ ] **Configurable PWM Frequency**
- [ ] **Configurable Brightness/Speed Curve**

### 2.2. Logical Functions

- [x] **`LogicalFunction` Class**: Implemented as described.
- [x] **Decoupling**: Successfully separates logical features from physical outputs.
- [x] **Core Logic**: Activation, deactivation, and updates are fully functional.

## 3. Advanced Lighting Effects

- [x] **Steady** (`EffectSteady`)
- [x] **Dimming** (`EffectDimming`)
- [x] **Flicker/Firebox Glow** (`EffectFlicker` with Perlin noise)
- [x] **Strobe / Beacon** (`EffectStrobe`)
- [x] **Mars Light / Gyralite** (`EffectMarsLight`)
- [x] **Soft Start/Stop** (`EffectSoftStartStop`)
- [ ] **Neon Tube Simulation**

## 4. Auxiliary Functions

### 4.1. Servo Control

- [x] **Basic Servo Control** (`EffectServo`)
- [ ] **Momentary Mode**
- [ ] **Latching Mode** (Current implementation defaults to latching-style)

### 4.2. Smoke Generator Control

- [x] **Basic Smoke Generator** (`EffectSmokeGenerator`)
- [x] **Heater On/Off**
- [x] **Static Fan Speed** (Variant A)
- [ ] **Speed Synchronized Fan** (Variant B)

## 5. Function Mapping System

### 5.1. Internal Architecture: Multi-Level Table Logic

- [x] **Core Data Structures**: `Condition`, `ConditionVariable`, `MappingRule`.
- [x] **Enums**: `TriggerSource`, `TriggerComparator`, `MappingAction`.
- [x] **Logic Engine**: `FunctionManager` processes rules correctly.

### 5.2. RCN-227 Implementation Roadmap

- [x] **Phase 1: Core Infrastructure & RCN-225**
    - `CVLoader` parses RCN-225 CVs (33-46).
- [x] **Phase 2: RCN-227 - System per Function**
    - `parseRcn227PerFunction` implemented including blocking logic.
- [x] **Phase 3: RCN-227 - System per Output (Versions 1 & 2)**
    - *Status: Stable*
    - `ConditionVariable` ID generation upgraded to `uint16_t` to prevent overflows and collisions.
- [x] **Phase 4: RCN-227 - System per Output (Version 3)**
    - *Status: Implemented*
    - `Condition` parameters upgraded to `uint16_t` to support values up to 32767.
    - Skeleton implementation verified and updated.
- [ ] **Phase 5: Tooling & Documentation**
    - JMRI definition missing.
    - `webtool/editor.html` is a placeholder.

## 6. Summary

The project has a strong foundation that aligns well with the core architectural principles of the concept document. The separation of logical functions from physical outputs is well-established, and the internal "Multi-Level Table Logic" engine is in place.

- **Strengths**: A significant number of the advanced lighting effects have been implemented. The RCN-225 and the first stage of RCN-227 function mapping are complete, providing a solid, standards-compliant base.

- **Areas for Development**: The main areas for future work are the completion of the RCN-227 standard (Phases 3 and 4), the implementation of the more advanced features for auxiliary functions (servo modes and smoke sync), and the enhancement of the `PhysicalOutput` class to support more detailed hardware configurations. The `Neon Tube Simulation` effect is the only lighting effect not yet implemented.
