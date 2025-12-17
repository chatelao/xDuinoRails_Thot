# Signal Roadmap

## Architect's Vision
Als Senior Firmware Software Architekt für einen führenden Hersteller von DCC-Decodern ist es meine Aufgabe, die technologische Vision für die nächste Generation unserer Produkte zu gestalten. Das vorliegende Dokument dient nicht nur als Roadmap für neue Signaltypen, sondern auch als strategischer Plan zur Behebung der Mängel der aktuellen Lösung und zur Definition der technologischen Zukunft.

Unsere Vision ist es, von einem monolithischen Signal-Decoder zu einem hochmodularen, erweiterbaren und benutzerfreundlichen **DCC-System-Controller** zu transformieren. Der Fokus liegt auf den folgenden strategischen Zielen:
1.  **Modulare Firmware-Architektur:** Schaffung einer skalierbaren Software-Plattform, die eine einfache Integration neuer Funktionen und Signal-Systeme ohne tiefgreifende Eingriffe in den Kern ermöglicht.
2.  **Moderne Konfigurations-Schnittstellen:** Ablösung der traditionellen CV-Programmierung durch intuitive, grafische Oberflächen (Web-Interface, Mobile-App), die eine Konfiguration in Echtzeit erlauben.
3.  **Erweiterung des Ökosystems:** Unterstützung von mechanischen Signalen (Servos), Weichenantrieben und anderer Peripherie, um den Decoder zu einer zentralen Steuerungseinheit auf der Anlage zu machen.
4.  **Abstrakte Protokoll-Schnittstelle:** Anstatt Protokolle wie DCC oder mfx tief in der Firmware zu verankern, wird eine klare Befehls-API geschaffen (z.B. `setSignalAspect(signalId, aspectId)`). Externe Protokoll-Parser-Module (für DCC, mfx, etc.) werden gegen diese API entwickelt. Dies ermöglicht eine saubere Trennung und einfache Erweiterbarkeit für zukünftige Protokolle.

Dieses Dokument skizziert die Mängel, die wir beheben werden, und die wichtigsten Features, die uns dieser Vision näherbringen.

### Mängel der aktuellen Lösung (Stand Q3 2023)
Die aktuelle Firmware-Architektur ist das Ergebnis eines organischen Wachstums und weist mehrere grundlegende Schwächen auf, die die zukünftige Entwicklung hemmen:
- **Monolithische Kompilierung:** Das Signal-System wird zur Kompilierzeit per Build-Flag (`-D SIGNAL_TYPE_*`) fest einkodiert. Dies verhindert die dynamische Konfiguration verschiedener Signaltypen auf einem einzigen Decoder.
- **Starre Signal-Logik:** Die Implementierung neuer Signal-Systeme erfordert tiefgreifende Eingriffe in den C++ Code (`SignalManager.h`), was fehleranfällig und zeitaufwendig ist. Eine datengetriebene Logik fehlt.
- **Keine Servo-Unterstützung:** Die Architektur ist ausschließlich auf Lichtsignale (NeoPixel) ausgelegt. Die Ansteuerung von mechanischen Signalen über Servos ist nicht vorgesehen.
- **Abhängigkeit von CV-Programmierung:** Die Konfiguration erfolgt ausschließlich über DCC-CVs. Dies ist umständlich, schlecht dokumentiert und für Einsteiger nur schwer zugänglich. Es fehlt eine grafische Konfigurationsoberfläche.
- **Fehlende Bidirektionale Kommunikation:** Der Decoder unterstützt kein RailCom, was eine Auslesung von CVs "on-the-main" (PoM) oder eine anlagenweite Zustandsrückmeldung unmöglich macht.
- **Mangelnde Test-Automatisierung:** Unit-Tests sind nur rudimentär vorhanden. Dies erhöht das Risiko von Regressionen bei jeder Code-Änderung.

### Strategische Feature-Roadmap (Top 18)
Die folgende Liste ist priorisiert und repräsentiert die wichtigsten Entwicklungsschritte zur Transformation des Decoders.

**Phase 1: Architektur-Modernisierung & Kern-Features**
1.  [ ] **Dynamischer Signal-Dispatcher:** Entwicklung eines zentralen Dispatchers, der Signal-Objekte zur Laufzeit basierend auf CV-Werten instanziiert. Ermöglicht mehrere, verschiedene Signaltypen pro Decoder.
2.  [ ] **Hybride, datengetriebene Signal-Definitionen:** Entwicklung einer zweistufigen Architektur für maximale Flexibilität bei minimalem Speicherbedarf auf der MCU.
    - **Stufe 1 (Konfigurations-Tool):** Ein externes PC-Tool (oder das Web-Interface) ermöglicht die Definition von Signalen in einem benutzerfreundlichen Format (XML/JSON). Dieses Tool kompiliert die Definitionen in ein hochoptimiertes, speichersparendes binäres Format.
    - **Stufe 2 (Firmware):** Der Decoder enthält einen Satz an Standard-Signalen im binären Format. Über das Web-Interface können benutzerdefinierte binäre Definitionen auf den Decoder geladen werden, die die internen Definitionen überschreiben oder erweitern. Die Firmware parst ausschließlich dieses effiziente Binärformat.
3.  [ ] **Intelligentes Dimmen & Glühlampen-Simulation:** Überarbeitung der Dimm-Funktion, um das träge Auf- und Abglimmen von Glühlampen physikalisch korrekt zu simulieren.
4.  [ ] **Servo-Subsystem-Integration:** Implementierung einer robusten Servo-Ansteuerungsklasse, inklusive Endlagen-Justierung, Geschwindigkeitssteuerung und sanftem Anlauf/Stopp.
5.  [ ] **Erweiterung für mechanische Signale:** Definition und Implementierung der ersten mechanischen Signale (z.B. deutsches `Hp`-Formsignal) unter Nutzung des Servo-Subsystems.
6.  [ ] **Umfassendes Unit-Testing-Framework:** Aufbau einer soliden Test-Suite (z.B. mit GoogleTest) für die Kern-Logik (DCC-Parser, Signal-Dispatcher, etc.), um Stabilität zu gewährleisten.

**Phase 2: Konnektivität & Benutzererfahrung (UX)**
7.  [ ] **Ressourcensparendes Web-Interface:** Anstatt eines speicherintensiven On-Board-Webservers wird eine client-seitige Web-App (gehostet auf GitHub Pages) entwickelt. Diese kommuniziert lokal über WebUSB oder WebSerial mit dem Decoder und ermöglicht so eine grafische Konfiguration ohne hohe Last auf der MCU.
8.  [ ] **WLAN-Konnektivität (optional):** Für erweiterte Anwendungsfälle kann ein WLAN-fähiger Co-Prozessor oder eine alternative MCU (z.B. ESP32) genutzt werden, um eine drahtlose Konfiguration zu ermöglichen.
9.  [ ] **RailCom-Implementierung (Cutout & Channel 1):** Basis-Implementierung von RailCom zur Übermittlung der Decoder-Adresse und für PoM-CV-Lesen.
10. [ ] **Interaktiver Signal-Editor & Live-Vorschau:** Erweiterung des bestehenden Web-Tools zu einem vollwertigen Konfigurator. Benutzer können damit interaktiv auf einer X/Y-Matrix neue Signalbilder definieren, Aspekte zuweisen und diese live auf dem Decoder testen. Das Tool generiert die binäre Konfiguration (siehe Punkt 2).
11. [ ] **Firmware-Updates "Over-the-Rail" (OTR):** Ermöglichen von Firmware-Updates über die DCC-Schiene, was einen Ausbau des Decoders überflüssig macht.

**Phase 3: Funktionserweiterungen & Peripherie**
12. [ ] **Intelligenter Weichen-Decoder-Modus:** Implementierung eines Modus zur Ansteuerung von Weichen. Dieser Modus soll eine Rückmeldung der Weichen-Endlage (z.B. über Mikroschalter oder Strommessung am Servo) einlesen und die Signalaspekte entsprechend beeinflussen können (z.B. Fahrt nur bei korrekt anliegender Weiche).
13. [ ] **Sound-Unterstützung (Proof-of-Concept):** Ansteuerung eines kleinen Sound-Moduls (z.B. DFPlayer Mini), um signal-synchrone Sounds (z.B. Relais-Klicken, Glocke) abzuspielen.

**Phase 4: Protokoll-Erweiterung & Zukunftssicherheit**
14. [ ] **RailCom Channel 2 (BiDi-Daten):** Vollständige RailCom-Unterstützung ([S-9.3.2](https://www.nmra.org/sites/default/files/standards/sandrp/Draft/DCC/s-9.3.2_bi-directional_communication.pdf)) für bidirektionalen Datenaustausch.
15. [ ] **mfx-Anmeldung über Protokoll-API:** Implementierung der automatischen Anmeldung an mfx-Zentralen als Zubehör-Decoder (Spezifikation proprietär).
16. [ ] **CAN-Bus-Schnittstelle:** Hardware- und Software-Unterstützung für eine CAN-Bus-Schnittstelle (z.B. nach Spezifikation des "CAN-digital-Bahn Projekt").
17. [ ] **Leichtgewichtige Skripting-Engine:** Evaluierung und Integration einer speicherarmen Skript-Engine (z.B. eLua oder Pawn/AMX), die es fortgeschrittenen Benutzern ermöglicht, eigene Logiken (z.B. Bahnübergangs-Steuerung) zu implementieren. Die Skripte werden ebenfalls extern in das Binärformat vorkompiliert.
18. [ ] **JMRI-Decoder-Definitions-Dateien:** Erstellung und Pflege von [JMRI](https://www.jmri.org)-kompatiblen Decoder-Definitionsdateien, um die Konfiguration zu vereinfachen.

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
- [x] **Dwergsein** (Dwarf Signal) - `NL-Dwergsein`

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
