const int relayPin = 7;

void setup() {
  pinMode(relayPin, OUTPUT);

  digitalWrite(relayPin, LOW);

  Serial.begin(9600);
  Serial.println("Relay Valve Control Ready");
}

void loop() {

  Serial.println("Valve ON");
  digitalWrite(relayPin, HIGH);
  delay(5000);

  Serial.println("Valve OFF");
  digitalWrite(relayPin, LOW);
  delay(5000);
}
