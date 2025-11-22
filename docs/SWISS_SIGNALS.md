# Swiss Railway Signals

This document describes the Swiss railway signals supported by this project, specifically focusing on **System L** and **System N**.

## References
- [Gleispläne Schweiz - Lichtsignal System L](https://www.gleisplaene-schweiz.ch/signale-weichen-geleise/signale-in-arbeit-1/lichtsignal-system-l-in-arbeit/)
- [Gleis 3a - Signalsystem in der Schweiz](https://gleis3a.de/threads/signalsystemschweiz)
- [Lokifahrer.ch - Fahrbegriffe am Signal Typ L](https://lokifahrer.ch/Signale/CH/Fahrbegriff.htm)

## Signal Systems

### System L (Lichtsignal)
The traditional light signal system used since the 1940s.
- **Main Signal Aspects (Fahrbegriffe):**
  - **Halt (Stop):** Red.
  - **Fb 1 (Freie Fahrt / Clear):** Green.
  - **Fb 2 (Ausführung 40 km/h):** Green over Yellow.
  - **Fb 3 (Ausführung 60 km/h):** Green over Green.
  - **Fb 5 (Ausführung 90 km/h):** Green over Green over Green.
  - **Fb 6 (Kurze Fahrt / Short Drive):** Green over Yellow (same appearance as Fb 2, but indicates short distance to next stop).

- **Distant Signal Aspects:**
  - **Warnung (Expect Stop):** Two Yellows (horizontal).
  - **Freie Fahrt (Expect Clear):** Two Greens (diagonal).
  - **Ankündigung 40 km/h (Expect 40):** Yellow and Green.

### System N (Numerisch)
The modern system introduced in the 1980s using single optics and numeric displays.
- **Halt:** Red.
- **Freie Fahrt:** Green.
- **Speed Aspects:** Green or Yellow combined with a numeric display.
- **Warnung (Expect Stop):** Single Yellow.

## XML Definitions

The signal definitions in `firmware/definitions/ch.xml` have been updated to support these systems.

### Attributes
- `outline`: An SVG path string (`d="..."`) defining the shape of the signal shield.
- `outlineColor`: The color code (e.g., `#000000`) for the outline.
- `d` (on lightbulb): An SVG path string defining the shape/diameter of the lightbulb.

### Defined Signals
- **`CH-L-Hauptsignal-3L`**: Standard 3-lamp System L main signal (Green, Red, Yellow). Supports Halt, Fb 1, Fb 2, Fb 6.
- **`CH-L-Hauptsignal-4L`**: 4-lamp System L main signal (Green, Red, Yellow, Green). Supports Halt, Fb 1, Fb 2, Fb 3, Fb 6.
- **`CH-L-Vorsignal-Standard`**: Standard System L distant signal. Supports Warnung (YY), Freie Fahrt (GG), Ankündigung 40 (YG).
- **`CH-N-Hauptsignal-1`**: System N main signal.
- **`CH-N-Vorsignal-1`**: System N distant signal.

## Usage
The signals are defined with accurate relative positions. The `d` attribute on lightbulbs ensures they can be rendered correctly in SVG visualizations with a diameter of 200mm (r=100).
