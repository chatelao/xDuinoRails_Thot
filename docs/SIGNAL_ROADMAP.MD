# Signal Roadmap

This document outlines the steps to implement various German and Swiss signal types for the stationary signal decoder.

## German Signal Types

### Phase 1: Ks-Signale (Kombinationssignale)
- [ ] Implement basic Ks-Signal aspects (Hp 0, Ks 1, Ks 2)
- [ ] Implement advanced Ks-Signal aspects (e.g., with Zs 3, Zs 6)
- [ ] Add support for different light configurations (e.g., LED, bulb)
- [ ] Test against RCN-213 specification

### Phase 2: Hp-Signale (Hauptsignale)
- [ ] Implement basic Hp-Signal aspects (Hp 0, Hp 1, Hp 2)
- [ ] Implement Sh-Signale (Schutzsignale)
- [ ] Add support for different light configurations
- [ ] Test against RCN-213 specification

### Phase 3: Vr-Signale (Vorsignale)
- [ ] Implement basic Vr-Signal aspects (Vr 0, Vr 1, Vr 2)
- [ ] Implement Vorsignalwiederholer
- [ ] Add support for different light configurations
- [ ] Test against RCN-213 specification

### Phase 4: Zs-Signale (Zusatzsignale)
- [ ] Implement Zs 1 (Ersatzsignal)
- [ ] Implement Zs 3 (Geschwindigkeitsanzeiger)
- [ ] Implement Zs 6 (Gegengleisanzeiger)
- [ ] Implement Zs 7 (Vorsichtsignal)
- [ ] Test against RCN-213 specification

### Phase 5: Zp-Signale (Zugpersonalsignale)
- [x] Implement Zp 9 (Abfahren)
- [x] Implement Zp 6 (Bremse anlegen)
- [x] Implement Zp 7 (Bremse lösen)
- [x] Implement Zp 8 (Bremse in Ordnung)
- [x] Define XML structure and generate assets

## Swiss Signal Types

### Phase 5: System L (Lichtsignale)
- [ ] Implement basic signal aspects (Fahrt, Halt, Warnung)
- [ ] Implement advanced signal aspects (e.g., with speed announcements)
- [ ] Implement auxiliary signals
- [ ] Test against relevant specifications

### Phase 6: System N (mechanische Signale)
- [ ] Implement basic signal aspects
- [ ] This might be out of scope for a signal decoder, but needs evaluation.
