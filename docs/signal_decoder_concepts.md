# Konzepte für Signaldecoder und Mapping-Methoden

Diese Datei sammelt Konzepte und Methoden, wie Signalbegriffe auf die Ausgänge von Signaldecodern in verschiedenen digitalen Modellbahnprotokollen abgebildet (gemappt) werden.

## Grundlagen des Mappings

Das Mapping ist der Prozess, bei dem ein gewünschter Signalbegriff (z.B. "Fahrt" oder "Halt") in die Ansteuerung der einzelnen Lichtausgänge (z.B. LEDs) eines Signaldecoders übersetzt wird. Ein Signaldecoder hat mehrere Ausgänge, und jeder Ausgang ist mit einer Lampe oder LED des Signals verbunden.

### Herausforderungen

*   **Vielfalt der Signalsysteme:** Es gibt unzählige Signalsysteme mit unterschiedlichen Signalbildern.
*   **Herstellerspezifische Decoder:** Jeder Hersteller hat seine eigene Philosophie, wie die Konfiguration des Mappings erfolgt.
*   **Komplexe Signalbilder:** Manche Signalbilder erfordern das Blinken oder Auf- und Abblenden von Lichtern, was der Decoder unterstützen muss.

## Protokolle und deren Mapping-Ansätze

### 1. DCC (Digital Command Control)

DCC ist das am weitesten verbreitete Protokoll. Das Mapping wird hier in der Regel über CVs (Configuration Variables) im Decoder konfiguriert.

*   **Klassischer Ansatz (z.B. Lenz, Littfinski):**
    *   Jedem Signalbegriff wird eine eigene Weichenadresse zugewiesen. Das Senden eines Weichenbefehls (gerade/Abzweig) schaltet den entsprechenden Signalbegriff.
    *   Die CVs legen fest, welche Ausgänge für welche Adresse und welchen Befehl aktiviert werden.
    *   **Quelle:** Lenz, Littfinski DatenTechnik (LDT).
*   **Erweiterter Ansatz (z.B. ESU, ZIMO):**
    *   **ESU (SignalPilot):**
        *   Bietet vordefinierte Signalbilder für viele europäische und nordamerikanische Signalsysteme. Der Benutzer wählt das Signalsystem und den Signaltyp aus, und der Decoder kennt die Logik.
        *   Das Mapping ist quasi "eingebaut". Eine Adresse wird für das Hauptsignal verwendet, und weitere Adressen können für Vorsignale oder Zusatzlichter genutzt werden.
        *   **Quelle:** ESU electronic solutions ulm GmbH & Co. KG.
    *   **ZIMO:**
        *   Bietet ein sehr flexibles, aber auch komplexes Mapping über CVs. Hier kann fast jede erdenkliche Logik über CVs programmiert werden, inklusive Blinken, Abhängigkeiten, etc.
        *   Oft wird eine "Schweizer Zuordnung" verwendet, bei der die Zustände der Weichenadressen bitweise kombiniert werden, um eine Vielzahl von Signalbildern darzustellen.
        *   **Quelle:** ZIMO Elektronik GmbH.
*   **Roco/Märklin (oftmals OEM-Produkte):**
    *   **Roco:** Verwendet oft Decoder, die ähnlich wie die von ZIMO oder ESU funktionieren, aber mit einer einfacheren Konfiguration.
    *   **Märklin:** Im mfx-System erfolgt die Konfiguration meist über die grafische Oberfläche der Central Station. Das Mapping ist oft fest an das gewählte Signalbild gekoppelt. Der Decoder (z.B. m84) kann so konfiguriert werden, dass er vordefinierte Signalbilder schaltet.
    *   **Quelle:** Gebr. Märklin & Cie. GmbH, Modelleisenbahn GmbH.

### 2. BiDiB (Bidirectional Bus)

BiDiB ist ein modernes, bidirektionales Protokoll. Das Mapping ist hier Teil des Gesamtkonzepts und nicht nur auf den Decoder beschränkt.

*   **LightControl (Fichtelbahn):**
    *   Das Mapping wird zentral in der Steuerungssoftware (z.B. Rocrail, iTrain) konfiguriert.
    *   Der Decoder (z.B. LightControl) ist ein reines "Ausgabemodul", das Befehle wie "Schalte Ausgang 3 an" oder "Lasse Ausgang 5 mit Frequenz X blinken" ausführt.
    *   Die Intelligenz für die Signalbilder liegt in der PC-Software, was die Konfiguration sehr flexibel macht.
    *   **Quelle:** Fichtelbahn, BiDiB-Projekt.

### 3. LocoNet

LocoNet ist ein von Digitrax entwickeltes System, das auch von anderen Herstellern genutzt wird.

*   **Uhlenbrock/Digitrax:**
    *   Ähnlich wie bei DCC werden Weichenadressen zur Ansteuerung verwendet.
    *   Die Konfiguration erfolgt über LNCVs (LocoNet CVs).
    *   Einige Decoder haben "Intelligenz" für bestimmte Signalsysteme eingebaut, andere sind universell über LNCVs programmierbar.
    *   **Quelle:** Uhlenbrock Elektronik GmbH, Digitrax, Inc.

### 4. RailCom Network (RCN) - Norm RCN-213

RCN ist eine offene Norm, die auf RailCom basiert und versucht, die Konfiguration zu standardisieren.

*   **RCN-213 (Signal-, Schalt- und Rückmeldedecoder):**
    *   Diese Norm definiert, wie ein Signaldecoder konfiguriert wird, unabhängig vom Hersteller.
    *   Das Mapping erfolgt über eine standardisierte CV-Struktur.
    *   Der Decoder kann verschiedene "Persönlichkeiten" annehmen (z.B. als Lichtsignaldecoder, Weichendecoder).
    *   Für Signale werden sogenannte "Signal-Aspekt-Tabellen" in den CVs hinterlegt, die festlegen, welcher Ausgang bei welchem Signalbegriff leuchtet.
    *   **Quelle:** RailCommunity e.V.

### 5. Lodi (Lordi)

Lodi ist ein neueres, auf CAN basierendes Bussystem.

*   **rautenhaus digital:**
    *   Das System ist modular aufgebaut. Die Konfiguration erfolgt über die zentrale Steuerungseinheit.
    *   Ähnlich wie bei BiDiB liegt die Logik oft in der Zentrale oder PC-Software, was das Mapping sehr flexibel macht.
    *   **Quelle:** rautenhaus digital Vertrieb.

## Zusammenfassung der Hersteller und Ansätze

| Hersteller/System | Protokoll(e)     | Mapping-Ansatz                                                              |
| ----------------- | ----------------- | --------------------------------------------------------------------------- |
| **ESU**           | DCC, MM, mfx      | Vordefinierte Signal-Modi, einfache Konfiguration.                          |
| **ZIMO**          | DCC, MM           | Hochflexibles, aber komplexes CV-Mapping, "Schweizer Zuordnung".            |
| **Lenz**          | DCC               | Klassisches Mapping über Weichenadressen und CVs.                           |
| **LDT**           | DCC, MM           | Einfaches Mapping über Adressen, oft für spezifische Signalsysteme optimiert. |
| **Märklin**       | mfx, MM           | Grafische Konfiguration über Central Station, oft feste Signalbilder.         |
| **Roco**          | DCC               | Oft OEM-Decoder (z.B. ZIMO), daher deren Mapping-Methoden.                  |
| **BiDiB/Fichtelbahn** | BiDiB           | Zentrale Logik in PC-Software, Decoder ist reines Ausgabemodul.           |
| **Uhlenbrock**    | DCC, LocoNet      | Konfiguration über CVs bzw. LNCVs.                                          |
| **RCN (Norm)**    | DCC (mit RailCom) | Standardisierte CV-Struktur für Signal-Aspekt-Tabellen (RCN-213).         |
| **Lodi/rautenhaus** | CAN (Lodi)      | Zentrale Logik in der Steuerung, hohe Flexibilität.                         |
