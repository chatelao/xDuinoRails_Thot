# Test Board Concept

This document outlines the concept for a test board featuring a 9x9 NeoPixel matrix and a discrete LED implementation of a complex Swiss railway signal.

## Overview

The test board is designed to verify the functionality of the signal decoder firmware, specifically focusing on:
1.  **Matrix Display Control:** Using a 9x9 NeoPixel matrix (81 LEDs).
2.  **Discrete Signal Control:** Driving a complex Swiss signal using individual GPIO pins for each light source, rather than NeoPixels.

## Hardware Components

### 1. 9x9 NeoPixel Matrix
*   **Type:** WS2812B (or compatible) addressable LEDs.
*   **Configuration:** 9 rows x 9 columns = 81 pixels.
*   **Connection:** Single Data Pin (e.g., GPIO 0).
*   **Power:** 5V External power supply recommended due to high current draw (approx. 4.8A max for 81 pixels white).

### 2. Discrete LED Swiss Signal
The signal selected for this concept is the **Swiss System L** configuration, specifically a **Main Signal (Hauptsignal)** combined with a **Distant Signal (Vorsignal)**. This configuration offers the highest count of discrete optical elements (lights) typically found in this system.

#### Signal Layout
The signal consists of two distinct heads (or a combined shield representation) with the following LED mapping:

**Main Signal (Hauptsignal - Type 4L):**
*   **LED 1 (Green):** Top - Proceed / Speed 60 (upper)
*   **LED 2 (Red):** Upper Middle - Stop
*   **LED 3 (Yellow):** Lower Middle - Caution / Short Proceed
*   **LED 4 (Green):** Bottom - Speed 60 (lower) / Speed 40 (lower?)

**Distant Signal (Vorsignal - Standard):**
*   **LED 5 (Yellow):** Top Left - Warning / Expect Stop
*   **LED 6 (Yellow):** Top Right - Warning / Expect Stop
*   **LED 7 (Green):** Bottom Left - Expect Proceed
*   **LED 8 (Green):** Bottom Right - Expect Proceed

*Note: In a physical "Combined Signal" (Kombisignal), some optics might be shared or arranged on a single square plate, but for this discrete LED test board, we treat them as 8 individual controlled light sources to maximize testing capability.*

#### Pin Mapping (Example for RP2040)
| Component | Function | Pin (GPIO) |
| :--- | :--- | :--- |
| **Matrix** | Data Input | 0 |
| **Signal** | Main Green (Top) | 1 |
| **Signal** | Main Red | 2 |
| **Signal** | Main Yellow | 3 |
| **Signal** | Main Green (Bot) | 4 |
| **Signal** | Dist Yellow (TL) | 5 |
| **Signal** | Dist Yellow (TR) | 6 |
| **Signal** | Dist Green (BL) | 7 |
| **Signal** | Dist Green (BR) | 26 |
| **Ground** | GND | GND |

*(Pins can be adjusted based on available GPIOs)*

## Signal Logic
The firmware will implement a new class `SwissCombinedSignalDiscrete` which controls these 8 discrete LEDs to form valid Swiss signal aspects.

### Supported Aspects (Subset)
*   **Halt (Stop):** Main Red.
*   **Freie Fahrt (Proceed):** Main Green (Top).
*   **Warnung (Caution):** Main Green (Top) + Distant Yellows.
*   **Kurze Fahrt (Short Proceed):** Main Yellow + Main Green (depending on exact definition).
*   **Speed 40:** Main Green (Top) + Main Yellow.
*   **Speed 60:** Main Green (Top) + Main Green (Bot).
