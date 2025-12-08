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

## 🇧🇪 Belgium (BE)

### Light Signals (SNCB/NMBS)
- [ ] **Grand Signal d'Arrêt** (Main Stop Signal) - Often combined with warning aspects.
- [ ] **Signal d'Avertissement** (Warning Signal) - Precedes a stop signal.
- [ ] **Petit Signal d'Arrêt** (Small Stop Signal) - Used for shunting and minor movements (ground level).
- [ ] **Signal Simplifié** (Simplified Signal)
- [ ] **IOT** (Indicateur d'Opérations Terminées) - Completed operations indicator.

### Mechanical Signals
- [ ] **Semaphore** (Paddle Signals) - Historically used, largely replaced.

## 🇨🇿 Czech Republic (CZ)

### Light Signals (AŽD Types)
- [ ] **AŽD 71** (Standard Color Light) - Widely used, identifiable by specific shield shape.
- [ ] **AŽD 97** (Modern LED) - Newer generation of light signals.
- [ ] **Opakovací návěstidlo** (Repeater Signal) - Pre-distants or repeaters.
- [ ] **Seřaďovací návěstidlo** (Shunting Signal) - Blue/White lights.

### Mechanical Signals (Mechanická návěstidla)
- [ ] **Vjezdové návěstidlo** (Entry Semaphore) - Often two arms.
- [ ] **Odjezdové návěstidlo** (Exit Semaphore) - Often one arm.
- [ ] **Předvěst** (Mechanical Distant) - Disc signal.

## 🇩🇰 Denmark (DK)

### Light Signals (DSB/Banedanmark)
- [ ] **Daglyssignal** (Daylight Signal) - Main signal system (Entry, Exit, Block).
- [ ] **PU-signal** (Passage/Exit Signal) - Combined function.
- [ ] **I-signal** (Indkørselssignal) - Entry signal.
- [ ] **U-signal** (Udkørselssignal) - Exit signal.
- [ ] **Dvæergsignal** (Dwarf Signal) - Shunting.

### Mechanical Signals
- [ ] **Armsignal** (Semaphore) - Historical.

## 🇫🇷 France (FR)

### Light Signals
- [x] **Signalisation Lumineuse** (Main Signal) - `FR-Signalisation-Lumineuse-1`
- [x] **Carré Violet** (Shunting/Stop) - `FR-Carre-Violet-1`

### Mechanical Signals
- [ ] **Cible** (Target/Disc Signals)
- [ ] **Aile** (Semaphore Wings)

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

## 🇭🇺 Hungary (HU)

### Light Signals (MÁV)
- [ ] **Főjelző** (Main Signal) - Similar to OSShD / German H/V concepts but with speed signaling.
- [ ] **Előjelző** (Distant Signal)
- [ ] **Tolatásjelző** (Shunting Signal) - Blue/White lights.

### Mechanical Signals
- [ ] **Alakjelző** (Semaphore) - Still in use on secondary lines.

## 🇮🇹 Italy (IT)

### Light Signals
- [x] **Segnale Luminoso** (Main Signal) - `IT-Segnale-Luminoso-1`
- [x] **Marmotta** (Shunting Signal) - `IT-Marmotta`

## 🇯🇵 Japan (JP)

### Light Signals (JR Group)
- [ ] **Color Light Signal** (3, 4, 5, 6-Aspect) - For main lines and high-density traffic.
- [ ] **Repeater Signal** (Chūkei shingōki) - Repeating the aspect of the next signal.
- [ ] **Shunting Signal** (Irekae shingōki) - Position-light style dwarf signals.
- [ ] **Route Indicator** - Often alphanumeric or arrow based.

### Mechanical Signals
- [ ] **Semaphore** (Udegi shingōki) - Historically significant, rare today.

## 🇳🇱 Netherlands (NL)

### Light Signals
- [x] **Hoofdsein** (Main Signal) - `NL-Hoofdsein`
- [ ] **Dwergsein** (Dwarf Signal)

### Mechanical Signals
- [ ] **Armsein** (Semaphore)

## 🇳🇴 Norway (NO)

### Light Signals (Bane NOR)
- [ ] **Hovedsignal** (Main Signal) - Standard entry/exit/block signal (Red/Green).
- [ ] **Forsignal** (Distant Signal) - Yellow/Green flashing combinations.
- [ ] **Dvergsignal** (Dwarf Signal) - Shunting.

### Mechanical Signals
- [ ] **Semaforsignal** - Historical.

## 🇵🇱 Poland (PL)

### Light Signals
- [x] **Hauptsignal 5L** (Main Signal) - `PL-Hauptsignal-5L`
- [x] **Vorsignal** (Distant Signal) - `PL-Vorsignal`
- [x] **Manewrowa** (Shunting) - `PL-Manewrowa`

### Mechanical Signals
- [ ] **Kształtowe** (Semaphore Signals)

## 🇪🇸 Spain (ES)

### Light Signals (RENFE/ADIF)
- [ ] **Señal Principal** (Main Signal) - Standard color light (Green, Red, Yellow).
- [ ] **Señal de Maniobra** (Shunting Signal) - Often dwarf "Monobloque" style.
- [ ] **Indicador Alfanumérico** (Alphanumeric Indicator) - Speed or route info.
- [ ] **High Speed Signal** - Specific signaling for AVE lines (LZB/ETCS markers).

### Mechanical Signals
- [ ] **Señal Mecánica** - Historic semaphore types.

## 🇸🇪 Sweden (SE)

### Light Signals (Trafikverket)
- [ ] **Huvudsignal** (Main Signal) - 2 to 5 lights depending on function.
- [ ] **Försignal** (Distant Signal) - Blinking white light logic (unique to SE).
- [ ] **Dvärgsignal** (Dwarf Signal) - Used for shunting and as a "check" signal.

### Mechanical Signals
- [ ] **Semafor** - Historical.

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
