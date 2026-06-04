#define BUTTON_PIN 2
#define RELAY_PIN 8
#define IRRIGATION_TIME 5000

bool relayActive = false;
unsigned long startTime = 0;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

int lastButtonState = HIGH;
int buttonState = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);

  Serial.begin(9600);

  Serial.println("Manual Irrigation Controller");
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW && !relayActive) {

        relayActive = true;
        startTime = millis();

        digitalWrite(RELAY_PIN, HIGH);

        Serial.println("Valve OPENED");
        Serial.print("Timestamp: ");
        Serial.print(startTime);
        Serial.println(" ms");
      }
    }
  }

  lastButtonState = reading;

  if (relayActive &&
      (millis() - startTime >= IRRIGATION_TIME)) {

    relayActive = false;

    digitalWrite(RELAY_PIN, LOW);

    Serial.println("Valve CLOSED");
    Serial.print("Timestamp: ");
    Serial.print(millis());
    Serial.println(" ms");
  }
}
