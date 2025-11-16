# Core Concepts

This document explains the fundamental design principles and core concepts behind the xDuinoRails_Thot signal decoder.

## 1. Modular Architecture

The firmware is built upon a modular architecture that separates concerns and promotes extensibility. The key components are:

*   **Protocol Handlers:** Dedicated modules for processing DCC and Märklin-Motorola (MM) signals. These modules are responsible for extracting signal commands from the track signal.
*   **Signal Logic:** A library of signal systems that translates the incoming commands into specific signal aspects. Each signal system (e.g., German H/V, Swiss) is implemented as a separate module, making it easy to add new systems.
*   **Output Manager:** A hardware abstraction layer that controls the physical outputs (LEDs). This allows the signal logic to be independent of the specific hardware implementation.

## 2. Protocol Handling

The decoder is designed to be protocol-agnostic. It can be configured to operate in one of three modes:

*   **DCC Only:** The decoder will only respond to DCC commands.
*   **Märklin-Motorola (MM) Only:** The decoder will only respond to MM commands.
*   **Automatic Detection:** The decoder will listen for both DCC and MM commands and respond accordingly. This is the default mode.

## 3. Signal Logic and Configuration

The heart of the decoder is the signal logic. The behavior of the decoder is determined by the selected signal system and the configured CVs.

*   **Signal Systems:** The decoder supports a growing number of international signal systems. The desired system is selected via a CV.
*   **CV Configuration:** A comprehensive set of CVs allows for detailed configuration of the decoder's behavior. This includes setting the address, selecting the signal system, and configuring effects like dimming speed.
*   **Extensibility:** The modular design of the signal logic makes it easy to add new signal systems. Developers can create a new module that implements the logic for a specific system and integrate it into the firmware.

## 4. Hardware Design

The hardware is designed to be simple, flexible, and cost-effective.

*   **Microcontroller:** The decoder is based on the Seeed Studio XIAO RP2040, a powerful and affordable microcontroller.
*   **Outputs:** The decoder provides a number of outputs for connecting LEDs. The exact number of outputs can be customized depending on the hardware configuration.
*   **Open Source:** The hardware design is open source, allowing users to build their own decoders or modify the design to suit their needs.
