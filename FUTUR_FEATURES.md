| #   | Feature                         | Sought After | Why? (Community Sentiment)                                                     |
| --- | ------------------------------- | ------------ | ------------------------------------------------------------------------------ |
| 1   | Realistic Fading (Soft Dimming) | ★★★★★        | The #1 requirement; instant on/off looks "toy-like."                           |
| 2   | Dark Phase                      | ★★★★★        | Short pause between aspects (red→dark→green) prevents color mixing.            |
| 3   | Separate Dimming per Output     | ★★★★☆        | Crucial for balancing Red LEDs (often too bright) vs. Green/Yellow.            |
| 4   | Fluorescent Tube Flicker        | ★★★☆☆        | Popular for modern era station/street lights (start-up flickering).            |
| 5   | Gas Lantern Simulation          | ★★★☆☆        | Unstable, warm "shimmering" for Era I-II layouts.                              |
| 6   | Defective Light Effect          | ★★☆☆☆        | Simulates a broken or randomly failing bulb for scenery.                       |
| 7   | Sodium Vapor (Yellow) Effect    | ★★☆☆☆        | Specific slow warm-up for modern street lamps.                                 |
| 8   | US Searchlight Effect           | ★★★☆☆        | Specific mechanic simulation for US modelers (one optic, changing colors).     |
| 9   | Asynchronous Flashing           | ★★★★☆        | Required for crossing lights so they don't sync perfectly.                     |
| 10  | Double Flash (Strobe)           | ★★☆☆☆        | Used for modern emergency vehicles or specific warning signals.                |
| 11  | Gyralight / Mars Light          | ★★★☆☆        | US-specific locomotive or scenic effect capability.                            |
| 12  | Random Lighting Timer           | ★★★☆☆        | For house lighting (rooms turning on/off randomly) via decoder.                |
| 13  | Welding Light Effect            | ★★☆☆☆        | Blue/White rapid random flickering for industrial scenes.                      |
| 14  | TV Simulation Effect            | ★★☆☆☆        | Blue-ish random flicker for inside house windows.                              |
| 15  | Firebox Flicker                 | ★★☆☆☆        | For steam service facilities (ash pits).                                       |
| 16  | Global Night Mode               | ★★★★☆        | Dim all signals at once for "night operations" on the layout.                  |
| 17  | Zoom Effect                     | ★★☆☆☆        | Slow brightening (simulating light bulb thermal inertia).                      |
| 18  | Q-Flux (Qdecoder specific)      | ★★★☆☆        | Ultra-smooth movement for mechanical signals (requires servo).                 |
| 19  | Phantom Signal Suppression      | ★★★☆☆        | Prevents LEDs glowing faintly when they should be off.                         |
| 20  | Cross-fading                    | ★★★★☆        | Smooth transition where one light fades out as the other fades in.             |
| 21  | Pluggable Screw Terminals       | ★★★★★        | Allows wiring on the workbench, then plugging into the layout.                 |
| 22  | Common Anode (+) Support        | ★★★★★        | Most commercial LED signals use Common Anode; native support is mandatory.     |
| 23  | Common Cathode (-) Support      | ★★★★☆        | Necessary for some brands (e.g., Viessmann, Chinese signals).                  |
| 24  | Push-Pull Outputs               | ★★★★☆        | "Universal" outputs handle both Anode and Cathode wiring.                      |
| 25  | Integrated Resistors            | ★★★★★        | Huge demand. Users hate soldering resistors to tiny wires.                     |
| 26  | Separate Power Input            | ★★★★☆        | Powers signals from external DC, saving expensive Digital Track Power.         |
| 27  | Overload Protection             | ★★★★★        | Prevents smoke if a wire shorts out (very common mistake).                     |
| 28  | Short Circuit Self-Reset        | ★★★★☆        | Decoder resets itself after a short is cleared (no fuse replacement).          |
| 29  | High Current Output (>2A)       | ★★★☆☆        | Needed only if driving light bulbs or many signals at once.                    |
| 30  | Small Form Factor               | ★★★★☆        | Important for hiding decoders inside buildings or C-Track roadbeds.            |
| 31  | Mounting Holes                  | ★★★☆☆        | Simple but often missed; easier under-layout mounting.                         |
| 32  | Protective Casing               | ★★★☆☆        | Prevents shorts from loose wires touching the PCB.                             |
| 33  | Solder Pads (Low Cost)          | ★★☆☆☆        | Preferred by budget users, hated by beginners.                                 |
| 34  | LocoNet Interface               | ★★★★☆        | Critical for Digitrax/US users for bus-based signal logic.                     |
| 35  | LED Status Indicators           | ★★★★☆        | Shows if power is on and if a signal packet is received (debugging).           |
| 36  | Programming Button              | ★★★★★        | Physical button to learn address (easier than CV calculation).                 |
| 37  | Screwless "Clamp" Terminals     | ★★★☆☆        | Spring-loaded terminals; faster than screws.                                   |
| 38  | Daisy-Chain Power               | ★★★☆☆        | Ability to loop power wires to the next decoder easily.                        |
| 39  | Internal Rectifier              | ★★★☆☆        | Ensures flicker-free LEDs even on older AC systems.                            |
| 40  | RJ45 Connectors                 | ★★☆☆☆        | Used in "Plug & Play" systems for fast wiring.                                 |
| 41  | Pre-loaded Signal Presets       | ★★★★★        | "Select 'DB Entry Signal' -> Done." No CV mapping required.                    |
| 42  | Programming on Main (POM)       | ★★★★★        | Adjust brightness/speed without moving decoder to a program track.             |
| 43  | DIP Switches                    | ★★☆☆☆        | "Old school" but loved by non-technical users for setting addresses.           |
| 44  | App-Based Programming           | ★★★★★        | Visual setup via phone/tablet is the modern gold standard.                     |
| 45  | PC Software Interface           | ★★★★☆        | E.g., LokProgrammer; drag-and-drop signal configuration.                       |
| 46  | Address Learning Mode           | ★★★★★        | "Press button, switch turnout on controller, address saved."                   |
| 47  | Firmware Updateable             | ★★★★☆        | Future-proofing for new signal types or protocol changes.                      |
| 48  | CV Readback                     | ★★★★☆        | Ability to read what is currently stored (requires RailCom).                   |
| 49  | Copy/Paste Config               | ★★★☆☆        | For setting up 20 identical block signals quickly.                             |
| 50  | Test Mode                       | ★★★☆☆        | Cycles all outputs so you can check wiring before programming.                 |
| 51  | Reset to Factory Default        | ★★★★☆        | Essential "Panic Button" when programming goes wrong.                          |
| 52  | QR Code Manuals                 | ★★☆☆☆        | Quick access to current PDF (paper manuals are often outdated).                |
| 53  | Plain Text Diagnostic           | ★★★☆☆        | Decoder speaks back status (rare, but loved in high-end).                      |
| 54  | Template Manager                | ★★★☆☆        | Save custom signal definitions (e.g., a specific country prototype).           |
| 55  | CV Calculator Tool              | ★★★★☆        | Manufacturer provides a web tool to calculate CV values.                       |
| 56  | One-Bit Configuration           | ★★★☆☆        | Simple "Invert Output" toggle without complex mapping.                         |
| 57  | Loco Address Mode               | ★★☆☆☆        | Control signals via F-keys (Loco address) instead of Turnout address.          |
| 58  | Jumpers for Termination         | ★★☆☆☆        | Bus termination for LocoNet/CAN systems.                                       |
| 59  | Color-Coded Terminals           | ★★★☆☆        | Helps prevent wiring mistakes (Red/Green/Black markings).                      |
| 60  | Multi-Language Manual           | ★★★★☆        | Critical for non-German speakers using German brands.                          |
| 61  | DCC Support                     | ★★★★★        | The global standard; mandatory.                                                |
| 62  | Motorola (MM) Support           | ★★★★☆        | Still vital for many Märklin users.                                            |
| 63  | mfx / mfx+ Registration         | ★★★★★        | Auto-registration with Märklin Central Stations.                               |
| 64  | RailCom (BiDi)                  | ★★★★☆        | Feedback on decoder health and address to the command station.                 |
| 65  | RailCom Plus                    | ★★★☆☆        | Auto-registration for DCC (ESU Command Station users).                         |
| 66  | LocoNet Compatibility           | ★★★★☆        | Essential for Digitrax and large modular layouts (Fremo).                      |
| 67  | Selectrix Support               | ★★☆☆☆        | Niche, but critical for users of this older reliable system.                   |
| 68  | Analog DC Operation             | ★★★☆☆        | Works on classic DC layouts (detects power automatically).                     |
| 69  | Automatic Protocol Detection    | ★★★★☆        | Decoder figures out if it's MM or DCC without user setting CVs.                |
| 70  | Extended Accessory Packet       | ★★★☆☆        | Allows controlling complex aspects (Aspect #, not just Red/Green).             |
| 71  | RocoNet / Z21 CAN               | ★★★☆☆        | High-speed bus integration for Roco users.                                     |
| 72  | Märklin k83 Compatible          | ★★★☆☆        | Drop-in replacement for standard solenoid decoders.                            |
| 73  | NMRA Compliant                  | ★★★★☆        | Guarantees it works with any standard DCC controller.                          |
| 74  | Long Address Support            | ★★★★☆        | Access addresses > 255 (vital for large layouts).                              |
| 75  | Broadcast Stop                  | ★★☆☆☆        | Signal reacts to global "Emergency Stop" (e.g., flashing red).                 |
| 76  | Brown-out Memory                | ★★★★☆        | Remembers state after power loss (doesn't reset to Red on startup).            |
| 77  | Output Mapping                  | ★★★★☆        | Assign any logical signal aspect to any physical pin.                          |
| 78  | Multiplex Signal Support        | ★★★☆☆        | Supports 2-wire multiplexed signals (Viessmann Ks-Signals).                    |
| 79  | Shift Register Support          | ★★☆☆☆        | Ability to extend outputs via cheap shift register chips.                      |
| 80  | Servo Protocol (Pulse)          | ★★★☆☆        | If the decoder also handles semaphore (mechanical) signals.                    |
| 81  | ABC Braking Generator           | ★★★★★        | Top Tier. Generates asymmetry signal to stop trains automatically at Red.      |
| 82  | Block Control Logic             | ★★★★☆        | Simple internal logic: "If Signal A is Green, Signal B can be Yellow."         |
| 83  | Distant Signal Dependency       | ★★★★★        | Distant signal auto-matches the Home signal (Red -> Distant Yellow/Green).     |
| 84  | Shunting Aspect Logic           | ★★★☆☆        | "Double Red" or "Red+White" specific grouping.                                 |
| 85  | Local Inputs (Push Buttons)     | ★★★☆☆        | Switch signals manually from the fascia panel without a throttle.              |
| 86  | Track Occupancy Feedback        | ★★★★☆        | Reports "Red" status back to PC software (TrainController/iTrain).             |
| 87  | Z21 "Q-Mode"                    | ★★★☆☆        | Advanced logic configuration for Roco Z21 users.                               |
| 88  | Route Storage                   | ★★☆☆☆        | Decoder remembers a "route" of multiple aspects.                               |
| 89  | Conditional Aspects             | ★★★☆☆        | "Show Green only if Turnout 5 is Straight."                                    |
| 90  | Speed Limit Aspects             | ★★★☆☆        | Display Hp2 (Green/Yellow) automatically for diverging routes.                 |
| 91  | Dark Switching (Blanking)       | ★★★☆☆        | Distant signal on the same mast goes dark if Home signal is Red.               |
| 92  | Opposing Signal Interlock       | ★★★☆☆        | Prevents two opposing signals from being Green simultaneously.                 |
| 93  | Start-up Delay                  | ★★☆☆☆        | Staggers signal turn-on to prevent power spikes at layout start.               |
| 94  | Emergency Stop Aspect           | ★★☆☆☆        | All signals turn Red on specific packet.                                       |
| 95  | Trigger Inputs                  | ★★☆☆☆        | Reed switch/Sensor input triggers signal change directly.                      |
| 96  | Crossing Logic                  | ★★★☆☆        | Built-in logic for level crossings (alternate flash until trigger off).        |
| 97  | Function Key Mapping            | ★★☆☆☆        | Map signal aspects to F0-F28 keys (rare but useful).                           |
| 98  | Signal Bus (Susan)              | ★☆☆☆☆        | Specific Dietz/Uhlenbrock bus for signal logic communication.                  |
| 99  | Pre-Signal Repetition           | ★★☆☆☆        | Support for repeating distant signals (Vorsignalwiederholer).                  |
| 100 | Timetable Logic                 | ★☆☆☆☆        | Very rare: Signals change based on internal clock (mostly PC software domain). |
