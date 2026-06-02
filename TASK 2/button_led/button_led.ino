// Debounced Button Toggle LED
// Button connected to D2 and GND
// LED connected to D13 (built-in LED can also be used)

const int buttonPin = 2;
const int ledPin = 13;

bool ledState = LOW;
bool buttonState = HIGH;
bool lastButtonReading = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // milliseconds

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, ledState);

  Serial.begin(9600);
  Serial.println("Button LED Toggle Started");
}

void loop() {
  int reading = digitalRead(buttonPin);

  // Reset debounce timer if button state changes
  if (reading != lastButtonReading) {
    lastDebounceTime = millis();
  }

  // Check if enough time has passed
  if ((millis() - lastDebounceTime) > debounceDelay) {

    // If button state has changed
    if (reading != buttonState) {
      buttonState = reading;

      // Button pressed (INPUT_PULLUP: LOW means pressed)
      if (buttonState == LOW) {
        ledState = !ledState;
        digitalWrite(ledPin, ledState);

        Serial.print("LED State: ");
        Serial.println(ledState ? "ON" : "OFF");
      }
    }
  }

  lastButtonReading = reading;
}
