# Rocco Signalbilder

Dieses Dokument erklärt, wie verschiedene Beleuchtungsszenarien (bekannt als "Signalbilder") für Modelllokomotiven, insbesondere solche der Marke Rocco, unter Verwendung des RCN-227-Standards für erweitertes Function Mapping konfiguriert werden.

## Die Logik verstehen: RCN-227

Der Kern der Lichtsteuerung ist der RCN-227-Standard, der eine hochflexible und leistungsstarke Zuordnung von Funktionstasten (wie F0, F1 usw.) zu den physischen Lichtausgängen am Decoder ermöglicht. Dieser Standard geht über einfache Ein-/Aus-Befehle hinaus und ermöglicht komplexe, zustandsabhängige Beleuchtungsverhalten.

### Schlüsselkonzepte von RCN-227

*   **Ausgänge:** Dies sind die physischen Anschlüsse am Decoder, die die Lichter steuern (z. B. Frontscheinwerfer, rote Schlusslichter).
*   **Funktionen:** Dies sind die Befehle, die von Ihrer Digitalzentrale gesendet werden und in der Regel durch Funktionstasten (F0, F1, F2 usw.) ausgelöst werden.
*   **Fahrtrichtungsabhängigkeit:** Die Beleuchtung kann so konfiguriert werden, dass sie sich je nach Fahrtrichtung der Lokomotive (vorwärts oder rückwärts) ändert.
*   **Sperrfunktionen:** Eine Funktion kann so konfiguriert werden, dass sie eine andere blockiert und das Einschalten eines Lichts verhindert. Dies ist nützlich für Szenarien wie das Deaktivieren der Scheinwerfer auf der an einen Zug gekoppelten Seite der Lokomotive.
*   **CVs (Konfigurationsvariablen):** Die gesamte Logik wird durch das Einstellen spezifischer CVs am Decoder programmiert. RCN-227 verwendet einen dedizierten Block von CVs, um seine komplexen Zuordnungsregeln zu speichern.

Die folgenden Abschnitte enthalten praktische Beispiele, wie gängige "Signalbilder" mit den in der RCN-227-Norm definierten CVs programmiert werden.

## Beispiel 1: Schweizer Lichtwechsel

Der Schweizer Lichtwechsel ist ein gängiges Muster, bei dem drei weiße Scheinwerfer an der Vorderseite der Lokomotive und ein einzelnes weißes Schlusslicht am Heck leuchten. Dies ändert sich mit der Fahrtrichtung.

### Gewünschtes Verhalten

*   **Bei Vorwärtsfahrt:** Drei weiße Scheinwerfer sind vorne an, und ein weißes Schlusslicht ist hinten an.
*   **Bei Rückwärtsfahrt:** Die Beleuchtung ist umgekehrt. Die drei weißen Scheinwerfer sind am (physischen) Heck an, und das einzelne Schlusslicht ist an der (physischen) Front an.
*   Dieses gesamte Verhalten wird typischerweise über die Funktionstaste `F0` gesteuert.

### Ausgangskonfiguration

Nehmen wir an, die Ausgänge des Decoders sind wie folgt verdrahtet:
*   **Ausgang 1:** Steuert die drei Hauptscheinwerfer vorne.
*   **Ausgang 2:** Steuert die drei Hauptscheinwerfer hinten.
*   **Ausgang 3:** Steuert das einzelne Schlusslicht vorne.
*   **Ausgang 4:** Steuert das einzelne Schlusslicht hinten.

### CV-Programmierung (unter Verwendung von RCN-227 Version 3)

Wir verwenden Version 3 des RCN-227-Standards ("Funktions- oder Binärzustandsnummer"), da sie die notwendige richtungsabhängige Steuerung bietet.

*   **Für Ausgang 1 (Frontscheinwerfer):**
    *   `CV257 = 64` (Funktion `F0` + wirkt nur vorwärts)
*   **Für Ausgang 2 (Heckscheinwerfer):**
    *   `CV265 = 128` (Funktion `F0` + wirkt nur rückwärts)
*   **Für Ausgang 3 (Frontschlusslicht):**
    *   Dieses Licht sollte leuchten, wenn die Lokomotive rückwärts fährt (d. h. wenn die Front das Heck des Zuges ist).
    *   `CV273 = 128` (Funktion `F0` + wirkt nur rückwärts)
*   **Für Ausgang 4 (Heckschlusslicht):**
    *   Dieses Licht sollte leuchten, wenn die Lokomotive vorwärts fährt.
    *   `CV281 = 64` (Funktion `F0` + wirkt nur vorwärts)

## Beispiel 2: Rangiermodus ("Rangiergang")

Der Rangiermodus ist ein Sonderzustand für den Betrieb auf dem Rangierbahnhof. Er beinhaltet typischerweise das Einschalten der Hauptscheinwerfer an beiden Enden der Lokomotive, um die Sichtbarkeit zu erhöhen.

### Gewünschtes Verhalten

*   Wird durch eine dedizierte Funktionstaste aktiviert, zum Beispiel `F6`.
*   Wenn `F6` aktiv ist, sind die drei weißen Scheinwerfer sowohl vorne als auch hinten an der Lokomotive eingeschaltet, unabhängig von der Richtung.
*   Die einzelnen Schlusslichter aus dem Schweizer Lichtwechsel sollten ausgeschaltet sein.
*   Der normale `F0`-Lichtwechsel sollte außer Kraft gesetzt werden.

### CV-Programmierung (Erweiterung von Beispiel 1)

Wir fügen die Logik für `F6` zu den bestehenden CVs für die Hauptscheinwerfer hinzu und ergänzen eine Sperrlogik für die Schlusslichter.

*   **Für Ausgang 1 (Frontscheinwerfer):**
    *   `CV257 = 64` (Aus Beispiel 1: F0 vorwärts)
    *   `CV258 = 6` (Funktion `F6`, wirkt richtungsunabhängig)
*   **Für Ausgang 2 (Heckscheinwerfer):**
    *   `CV265 = 128` (Aus Beispiel 1: F0 rückwärts)
    *   `CV266 = 6` (Funktion `F6`, wirkt richtungsunabhängig)
*   **Für Ausgang 3 (Frontschlusslicht):**
    *   `CV273 = 128` (Aus Beispiel 1: F0 rückwärts)
    *   `CV274 = 198` (Funktion `F6` + sperrt den Ausgang = 6 + 192)
*   **Für Ausgang 4 (Heckschlusslicht):**
    *   `CV281 = 64` (Aus Beispiel 1: F0 vorwärts)
    *   `CV282 = 198` (Funktion `F6` + sperrt den Ausgang = 6 + 192)

## Beispiel 3: Fernlicht

Fernlicht ist eine Funktion, bei der ein zusätzlicher, hellerer Satz von Lichtern eingeschaltet werden kann, normalerweise während die Hauptscheinwerfer bereits aktiv sind.

### Gewünschtes Verhalten

*   Wird durch eine dedizierte Funktionstaste aktiviert, zum Beispiel `F5`.
*   Das Fernlicht kann nur aktiviert werden, wenn die Hauptscheinwerfer (`F0`) bereits eingeschaltet sind.
*   Das Fernlicht sollte der Richtung der Hauptscheinwerfer folgen.

### Ausgangskonfiguration

Nehmen wir an, der Decoder hat zwei zusätzliche Ausgänge für das Fernlicht:
*   **Ausgang 5:** Steuert das Fernlicht vorne.
*   **Ausgang 6:** Steuert das Fernlicht hinten.

### CV-Programmierung (RCN-227 Version 2)

Für dieses Beispiel verwenden wir Version 2 des RCN-227-Standards ("Funktionsnummer"), die sich gut für diese Art von geschichteter Logik eignet. In dieser Version schalten die ersten drei Bytes einen Ausgang ein, und das vierte Byte kann verwendet werden, um ihn zu sperren.

*   **Für Ausgang 5 (Front-Fernlicht):**
    *   Wir benötigen diesen Ausgang nur dann, wenn `F0` an UND `F5` an ist.
    *   Diese Logik ist mit einer einfachen ODER-Logik nicht direkt möglich. Wir können dies jedoch erreichen, indem wir `F5` als primären Auslöser verwenden und dann eine separate Funktion verwenden, um ihn zu blockieren, wenn `F0` AUS ist. Dies ist eine fortgeschrittene Technik.
    *   Ein einfacherer, gebräuchlicherer Ansatz besteht darin, `F5` einfach dem Fernlichtausgang zuzuordnen und sich darauf zu verlassen, dass der Benutzer `F5` nur drückt, wenn `F0` aktiv ist.
    *   Programmieren wir den einfacheren Fall:
    *   Für die Vorwärtsrichtung:
        *   `CV305 = 5` (Funktion `F5`)
        *   `CV308 = 0` (Wird durch das Ausschalten von Funktion `F0` blockiert - dies erfordert eine Inversion, `!F0`, die oft einer anderen Funktionsnummer wie F28 zugewiesen wird). Der Einfachheit halber nehmen wir an, `F1` blockiert es, wenn `F0` aus ist. Sagen wir, wir richten eine Bedingung ein, die `F1` aktiv macht, wenn `F0` aus ist. `CV308 = 1`.
        *   Um es für dieses Beispiel einfach und direkt zu halten, werden wir `F5` nur richtungsabhängig zuordnen.
    *   Verwendung von RCN-227 Version 3 für eine bessere Richtungssteuerung:
        *   `CV289 = 70` (Funktion `F5` + wirkt nur vorwärts = 5 + 64)

*   **Für Ausgang 6 (Heck-Fernlicht):**
    *   Verwendung von RCN-227 Version 3:
        *   `CV297 = 133` (Funktion `F5` + wirkt nur rückwärts = 5 + 128)
