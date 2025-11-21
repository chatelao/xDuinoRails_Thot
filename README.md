# xDuinoRails_Thot: A Multi-Protocol Signal Decoder

Welcome to the repository for xDuinoRails_Thot, a revolutionary, multi-protocol signal decoder designed to bring your model railway's signaling system to life. Named after the Egyptian god of wisdom, Thot is engineered for intelligence, flexibility, and realism.

## Features

*   **Multi-Protocol Support:** Natively understands both DCC and Märklin-Motorola (MM) signal commands.
*   **Advanced Signal Logic:** Supports a wide and growing range of international signal systems, including German H/V, Ks, Swiss, and Dutch signals. The logic is designed to be easily extendable.
*   **Highly Configurable:** A comprehensive CV table allows for detailed configuration of signal types, dimming speeds, special effects, and protocol settings.
*   **Realistic Effects:** Features smooth transitions and dimming for simulating the behavior of incandescent bulbs, bringing a new level of realism to your layout.
*   **Modular Design:** The hardware and firmware are designed to be modular, allowing for easy adaptation to different types of signals and custom installations.
*   **Modern Hardware:** Built upon the powerful and cost-effective Seeed Studio XIAO RP2040 microcontroller.

## Signal Viewer

Explore the supported signals and their aspects using our online [Signal Viewer](https://chatelao.github.io/xDuinoRails_Thot/webtool/).

## Repository Structure

*   `docs/`: Contains all project documentation, including signal system concepts, CV tables, and wiring diagrams.
*   `firmware/`: The PlatformIO project for the decoder's firmware.
*   `hardware/`: Schematics, PCB layouts, and other hardware-related files.

## Getting Started

### Hardware

The decoder is designed for the Seeed Studio XIAO RP2040. You can find detailed schematics and wiring instructions in the `hardware/` directory.

### Firmware

The firmware is a PlatformIO project. To build the firmware, you will need to have PlatformIO installed.

1.  **Install PlatformIO:** If you don't have it installed, you can install it via pip:
    ```bash
    pip install platformio
    ```
2.  **Build the firmware:** You can build the firmware with the following command:
    ```bash
    python -m platformio run -d firmware -e xiao_signal_decoder
    ```

## Long-Term Vision

Our vision is to create the most powerful and flexible signal decoder on the market. Future plans include:

*   Support for a vast library of international signal systems.
*   Seamless integration with popular computer control software like JMRI and Rocrail.
*   An intuitive, network-based configuration interface for easy setup.
*   Full RailCom support for bidirectional communication and on-the-main programming.
