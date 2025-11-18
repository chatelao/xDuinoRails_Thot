# Swiss N Signal

The `SwissNSignal` class provides an implementation of the Swiss N type railway signals. This class is designed to be used with NeoPixel LEDs to display the various signal aspects.

## Usage

To use the `SwissNSignal` class, you must first create an instance of the class, specifying the pin the NeoPixel is connected to and the number of pixels.

```cpp
#include "LightSources/SwissNSignal.h"

#define NEOPIXEL_PIN 2
#define NUM_PIXELS 1

xDuinoRails::SwissNSignal swissSignal(NEOPIXEL_PIN, NUM_PIXELS);
```

Once you have created an instance of the class, you can set the signal aspect using the `setAspect` method.

```cpp
swissSignal.setAspect(xDuinoRails::N_ASPECT_CLEAR);
```

The available aspects are defined in the `SwissNSignalAspect` enum.

## Aspects

| Aspect | Description |
| --- | --- |
| `N_ASPECT_STOP` | Stop |
| `N_ASPECT_CLEAR` | Track clear |
| `N_ASPECT_SPEED_40` | Speed restriction 40 km/h |
| `N_ASPECT_SPEED_60` | Speed restriction 60 km/h |
| `N_ASPECT_SPEED_90` | Speed restriction 90 km/h |
| `N_ASPECT_OBSTRUCTION_AHEAD` | Obstruction close ahead |
| `N_ASPECT_TRACK_OCCUPIED` | Track occupied |
| `N_ASPECT_PREWARNING` | Prewarning |
