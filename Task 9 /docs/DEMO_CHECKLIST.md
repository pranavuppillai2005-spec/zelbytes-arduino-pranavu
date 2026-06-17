# Demo Checklist

## Firmware v1.0 Capstone Verification

### Hardware Verification

* [ ] Arduino UNO powered successfully
* [ ] DHT11 sensor connected correctly
* [ ] Soil moisture sensor operational
* [ ] LDR sensor operational
* [ ] Relay module operational
* [ ] Solenoid valve operational
* [ ] Manual override button operational

---

### Automatic Irrigation

* [ ] Soil moisture above threshold keeps valve OFF
* [ ] Soil moisture below threshold activates valve
* [ ] Relay changes state correctly
* [ ] Valve responds correctly

---

### Manual Override

* [ ] Button press enables manual mode
* [ ] Button press disables manual mode
* [ ] Manual mode overrides automatic mode

---

### Serial Commands

#### STATUS

* [ ] STATUS command accepted
* [ ] System status displayed

#### FORCE_ON

* [ ] FORCE_ON command accepted
* [ ] Valve turns ON

#### FORCE_OFF

* [ ] FORCE_OFF command accepted
* [ ] Valve turns OFF

---

### Final Verification

* [ ] Firmware uploaded successfully
* [ ] Serial monitor output verified
* [ ] Irrigation control verified
* [ ] Demo video recorded

---

Mentor Signature: gokul

Date: 16/06/26
