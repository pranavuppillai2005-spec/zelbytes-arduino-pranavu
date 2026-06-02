// Relay Controlled Solenoid Valve
// Relay IN -> Arduino D7
// Relay VCC -> 5V
// Relay GND -> GND
//
// IMPORTANT:
// Solenoid valve must be powered using an external supply.
// Never connect the valve directly to an Arduino GPIO pin.

const int relayPin = 7;

void setup() {
  pinMode(relayPin, OUTPUT);

  // Relay OFF initially
  digitalWrite(relayPin, LOW);

  Serial.begin(9600);
  Serial.println("Relay Valve Control Ready");
}

void loop() {

  // Turn valve ON
  Serial.println("Valve ON");
  digitalWrite(relayPin, HIGH);
  delay(5000);

  // Turn valve OFF
  Serial.println("Valve OFF");
  digitalWrite(relayPin, LOW);
  delay(5000);
}
