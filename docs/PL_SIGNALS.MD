# Polish Signals (Ie-1)

## Overview
Polish signals (System Ie-1) implementation for xDuinoRails.

## Supported Signals

### PL-Hauptsignal-5L (Main Signal)
Standard 5-chamber main signal.
- **S1 (Stój)**: Red
- **S2 (Vmax)**: Green Top
- **S3 (Vmax, next 100)**: Green Top (Blinking)
- **S4 (Vmax, next 60/40)**: Orange Top (Blinking)
- **S5 (Vmax, next Stop)**: Orange Top
- **S10 (40, next Vmax)**: Green Top + Orange Bottom
- **S11 (40, next 100)**: Green Top (Blinking) + Orange Bottom
- **S12 (40, next 60/40)**: Orange Top (Blinking) + Orange Bottom
- **S13 (40, next Stop)**: Orange Top + Orange Bottom
- **Sz (Call-on)**: Red + White (Blinking)

### PL-Manewrowa (Shunting Signal)
Shunting signal.
- **Ms1 (Stop)**: Blue
- **Ms2 (Proceed)**: White

### PL-Vorsignal (Distant Signal)
Distant signal (2-chamber).
- **Os1 (Expect Stop)**: Orange
- **Os2 (Expect Vmax)**: Green
- **Os3 (Expect 100)**: Green (Blinking)
- **Os4 (Expect 60/40)**: Orange (Blinking)

## Configuration
Use `SIGNAL_TYPE_POLISH` build flag in `platformio.ini`.
