# Signal Roadmap

This document outlines the current status of signal implementations and future plans, categorized by country and signal technology.

## Status Legend
- [x] Implemented (XML definition exists)
- [ ] Planned / Missing (Not yet implemented)

## 🇦🇹 Austria (AT)

### Light Signals
- [x] **Hauptsignal** (Standard Main Signal) - `AT-Hauptsignal-1`
- [x] **Vorsignal** (Standard Distant Signal) - *Implicitly supported via aspects? Need verification.*
- [x] **Schutzsignal / Zwergsignal** (Shunting Signal) - `AT-Zwergsignal-1`

### Mechanical Signals (Formsignale)
- [ ] **Hauptsignal** (Semaphore Main Signal)
- [ ] **Vorsignal** (Semaphore Distant Signal)

## 🇦🇺 Australia (AU)

### Light Signals (NSW)
- [x] **Single Light** - `AU-NSW-Single-Light`
- [x] **Double Light** - `AU-NSW-Double-Light`
- [x] **Shunt Signal** - `AU-NSW-Shunt-Color-Light`

### Mechanical Signals
- [ ] **Semaphore Signals** (Various types)

## 🇨🇭 Switzerland (CH)

### System L (Light Signals)
- [x] **Hauptsignal 2L** (2 Lamps) - `CH-L-Hauptsignal-2L`
- [x] **Hauptsignal 3L** (3 Lamps) - `CH-L-Hauptsignal-3L`
- [x] **Hauptsignal 4L** (4 Lamps) - `CH-L-Hauptsignal-4L`
- [x] **Hauptsignal 5L** (5 Lamps) - `CH-L-Hauptsignal-5L`
- [x] **Hauptsignal 7L** (7 Lamps) - `CH-L-Hauptsignal-7L`
- [x] **Vorsignal Standard** (Distant) - `CH-L-Vorsignal-Standard`
- [x] **Vorsignal Kombi** (Combined) - `CH-L-Vorsignal-Kombi`
- [x] **Zwergsignal** (Dwarf) - `CH-Zwergsignal`
- [x] **Rangierhaltsignal** (Shunting Stop) - `CH-Rangierhaltsignal`
- [x] **Räumungssignal** (Evacuation) - `CH-Raeumungssignal`

### System N (Numeric/Light)
- [x] **Hauptsignal** - `CH-N-Hauptsignal-1`
- [x] **Vorsignal** - `CH-N-Vorsignal-1`

### Auxiliary Signals
- [x] **Zp Signal** (Departure/Brake Test) - `CH-ZP-Signal`

### Mechanical Signals
- [ ] **Hipp'sche Wendescheibe** (Turning Disc Signal)
- [ ] **Semaphore** (Main & Distant)

## 🇩🇪 Germany (DE)

### H/V System (Lichtsignale)
- [x] **Hauptsignal** (Main Signal) - `DE-HV-Hauptsignal-1`
- [x] **Vorsignal** (Distant Signal) - `DE-HV-Vorsignal-1`
- [x] **Sperrsignal / Zwergsignal** (Shunting) - `DE-HV-Zwergsignal-1`

### Ks System (Kombinationssignale)
- [x] **Ks-Signal** (Main/Distant Combined) - `DE-KS-Signal`

### Hl System (DR - East Germany)
- [x] **Hl-Signal** - `DE-HL-Signal`

### Sv System (S-Bahn Hamburg/Berlin)
- [x] **Sv-Signal** - `DE-SV-Signal`

### Auxiliary & Level Crossing
- [x] **Bü-Signal** (Level Crossing) - `DE-BUE-Signal`
- [x] **Zp-Signal** (Train Personnel) - `DE-ZP-Signal`
- [x] **Zs-Signal** (Additional Signals) - `DE-ZS-Signal`

### Mechanical Signals (Formsignale)
- [ ] **Hp-Hauptsignal** (Semaphore) - *Hp 0, Hp 1, Hp 2*
- [ ] **Vr-Vorsignal** (Semaphore Distant) - *Vr 0, Vr 1, Vr 2*
- [ ] **Sh-Sperrsignal** (Mechanical Shunting)

## 🇫🇷 France (FR)

### Light Signals
- [x] **Signalisation Lumineuse** (Main Signal) - `FR-Signalisation-Lumineuse-1`
- [x] **Carré Violet** (Shunting/Stop) - `FR-Carre-Violet-1`

### Mechanical Signals
- [ ] **Cible** (Target/Disc Signals)
- [ ] **Aile** (Semaphore Wings)

## 🇮🇹 Italy (IT)

### Light Signals
- [x] **Segnale Luminoso** (Main Signal) - `IT-Segnale-Luminoso-1`
- [x] **Marmotta** (Shunting Signal) - `IT-Marmotta`

## 🇳🇱 Netherlands (NL)

### Light Signals
- [x] **Hoofdsein** (Main Signal) - `NL-Hoofdsein`
- [ ] **Dwergsein** (Dwarf Signal)

### Mechanical Signals
- [ ] **Armsein** (Semaphore)

## 🇵🇱 Poland (PL)

### Light Signals
- [x] **Hauptsignal 5L** (Main Signal) - `PL-Hauptsignal-5L`
- [x] **Vorsignal** (Distant Signal) - `PL-Vorsignal`
- [x] **Manewrowa** (Shunting) - `PL-Manewrowa`

### Mechanical Signals
- [ ] **Kształtowe** (Semaphore Signals)

## 🇬🇧 United Kingdom (UK)

### Light Signals
- [x] **4-Aspect Colour Light** - `UK-Colour-Light-Signal-4-Aspect`
- [x] **Position Light** (Ground Signal) - `UK-Ground-Position-Light`

### Mechanical Signals
- [ ] **Semaphore (Lower Quadrant)**
- [ ] **Semaphore (Upper Quadrant)**

## 🇺🇸 United States (US)

### Light Signals
- [x] **3-Aspect Vertical** (Color Light) - `US-3-aspect-vertical`
- [x] **Dwarf Signal** - `US-Dwarf-Color-Light`
- [ ] **Searchlight Signal**
- [ ] **Position Light** (PRR Style)
- [ ] **Color Position Light** (B&O Style)

### Mechanical Signals
- [ ] **Semaphore** (Upper/Lower Quadrant)

## Missing Countries (Examples)
Significant railway nations not yet represented:
- [ ] **Belgium (BE)** - SNCB/NMBS Signals
- [ ] **Spain (ES)** - RENFE Signals
- [ ] **Scandinavia (DK, SE, NO)** - Nordic Signal Systems
- [ ] **Czech Republic (CZ)** - CD Signals (similar to ancient AT/DE)
- [ ] **Japan (JP)** - JR Signals
