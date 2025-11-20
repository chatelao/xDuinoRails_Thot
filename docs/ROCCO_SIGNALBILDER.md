# Roco Signalbilder für Streckensignale

Dieses Dokument beschreibt das Verhalten und die Konfiguration von Roco-Streckensignalen (Signale am Schienenrand) im Zusammenspiel mit einem stationären Signaldecoder.

## Grundlegendes Verhalten von Roco-Signalen

Roco-Streckensignale, insbesondere die neueren Modelle mit LEDs, sind oft so konzipiert, dass sie direkt von einem Decoder angesteuert werden können, der die entsprechenden Signalbilder erzeugen kann. Die Ansteuerung erfolgt typischerweise über separate Ausgänge für jede Farbe (z.B. Rot, Grün, Gelb).

## Ansteuerung mit einem stationären Signaldecoder

Ein stationärer Signaldecoder hat die Aufgabe, die Befehle von der Digitalzentrale (z.B. über Weichenadressen) in die korrekte Ansteuerung der Lichtausgänge für das Signal umzusetzen.

### Beispiel 1: Einfaches Blocksignal (Hp 0 / Hp 1)

Dieses Signal kann zwei Zustände anzeigen: "Halt" (rot) und "Fahrt" (grün).

*   **Gewünschtes Verhalten:**
    *   **Befehl 1 (z.B. Weichenadresse 1, rot):** Das rote Licht leuchtet (Hp 0). Das grüne Licht ist aus.
    *   **Befehl 2 (z.B. Weichenadresse 1, grün):** Das grüne Licht leuchtet (Hp 1). Das rote Licht ist aus.

*   **Decoder-Konfiguration:**
    *   **Ausgang 1:** Verbunden mit dem roten Licht des Signals.
    *   **Ausgang 2:** Verbunden mit dem grünen Licht des Signals.
    *   Der Decoder wird so konfiguriert, dass er je nach empfangenem Befehl entweder Ausgang 1 oder Ausgang 2 aktiviert.

### Beispiel 2: Ausfahrsignal mit Vorsignal (Hp 0 / Hp 1 / Hp 2 + Vr 0 / Vr 1 / Vr 2)

Dieses Signal kombiniert ein Hauptsignal mit einem Vorsignal für den nächsten Block.

*   **Gewünschtes Verhalten (vereinfacht):**
    *   **Hp 0 (Halt):** Rotes Licht an.
    *   **Hp 1 (Fahrt):** Grünes Licht an.
    *   **Hp 2 (Langsamfahrt):** Grünes und gelbes Licht an.
    *   Das Vorsignal am selben Mast zeigt an, was das nächste Hauptsignal anzeigen wird. Dies erfordert eine komplexere Logik im Decoder, die oft über CVs konfiguriert wird.

*   **Decoder-Konfiguration:**
    *   **Ausgang 1:** Rot (Hauptsignal)
    *   **Ausgang 2:** Grün (Hauptsignal)
    *   **Ausgang 3:** Gelb (Hauptsignal)
    *   **Ausgang 4:** Grün (Vorsignal)
    *   **Ausgang 5:** Gelb (Vorsignal)
    *   Die Decodereinstellungen (CVs) müssen gemäß der RCN-213 Spezifikation so eingestellt werden, dass die korrekten Kombinationen von Lichtern für jedes Signalbild aktiviert werden.

## Überblendeffekte

Moderne Signaldecoder können "weiche" Übergänge zwischen den Signalbildern erzeugen, bei denen die Lichter langsam ein- und ausgeblendet werden, anstatt hart zu schalten. Dies simuliert das Verhalten von Glühlampen und wirkt realistischer.

*   **Konfiguration:**
    *   Die Geschwindigkeit des Überblendens wird in der Regel über eine oder mehrere CVs im Decoder eingestellt.
