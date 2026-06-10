```cpp
#include <DHT.h>

// -------------------- PIN DEFINITIONS --------------------
#define DHTPIN 2
#define DHTTYPE DHT22

#define SOIL_PIN A0
#define RELAY_PIN 8
#define LED_PIN 13

// -------------------- DHT SENSOR --------------------
DHT dht(DHTPIN, DHTTYPE);

// -------------------- SOIL CALIBRATION --------------------
// Change these after calibration if needed
const int DRY_VALUE = 850;   // Sensor reading in dry soil
const int WET_VALUE = 350;   // Sensor reading in wet soil

// Irrigate when moisture falls below this percentage
const int MOISTURE_THRESHOLD = 30;

// Humidity must be above this value
const float HUMIDITY_THRESHOLD = 40.0;

// -------------------- TIMERS --------------------
const unsigned long IRRIGATION_TIME = 10000; // 10 seconds
const unsigned long COOLDOWN_TIME   = 5000;  // 5 seconds

// -------------------- STATE MACHINE --------------------
enum State {
  IDLE,
  IRRIGATING,
  COOLDOWN,
  FAULT
};

State currentState = IDLE;

unsigned long stateStartTime = 0;
unsigned long blinkTimer = 0;

int dhtFailCount = 0;
bool faultLedState = false;

// ---------------------------------------------------------
void relayOn()
{
  digitalWrite(RELAY_PIN, HIGH);   // Active HIGH relay
}

void relayOff()
{
  digitalWrite(RELAY_PIN, LOW);    // Active HIGH relay
}

// ---------------------------------------------------------
void enterState(State newState)
{
  currentState = newState;
  stateStartTime = millis();

  switch (currentState)
  {
    case IDLE:
      relayOff();
      digitalWrite(LED_PIN, LOW);
      Serial.println("\nSTATE -> IDLE");
      break;

    case IRRIGATING:
      relayOn();
      digitalWrite(LED_PIN, HIGH);
      Serial.println("\nSTATE -> IRRIGATING");
      break;

    case COOLDOWN:
      relayOff();
      digitalWrite(LED_PIN, LOW);
      Serial.println("\nSTATE -> COOLDOWN");
      break;

    case FAULT:
      relayOff();
      Serial.println("\nSTATE -> FAULT");
      break;
  }
}

// ---------------------------------------------------------
void setup()
{
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  relayOff();
  digitalWrite(LED_PIN, LOW);

  dht.begin();

  Serial.println("================================");
  Serial.println("SMART IRRIGATION SYSTEM STARTED");
  Serial.println("================================");

  enterState(IDLE);
}

// ---------------------------------------------------------
void loop()
{
  int soilRaw = analogRead(SOIL_PIN);

  // Convert to percentage
  int moisturePercent =
      map(soilRaw, DRY_VALUE, WET_VALUE, 0, 100);

  moisturePercent =
      constrain(moisturePercent, 0, 100);

  float humidity = dht.readHumidity();

  // ---------------- DHT FAILURE CHECK ----------------
  if (isnan(humidity))
  {
    dhtFailCount++;

    Serial.print("DHT Failure Count: ");
    Serial.println(dhtFailCount);

    if (dhtFailCount >= 3 &&
        currentState != FAULT)
    {
      enterState(FAULT);
    }

    delay(1000);
    return;
  }

  dhtFailCount = 0;

  // ---------------- STATE MACHINE ----------------
  switch (currentState)
  {
    case IDLE:

      Serial.print("Raw Soil: ");
      Serial.print(soilRaw);

      Serial.print(" | Moisture: ");
      Serial.print(moisturePercent);
      Serial.print("%");

      Serial.print(" | Humidity: ");
      Serial.print(humidity);
      Serial.println("%");

      // Start irrigation
      if (moisturePercent < MOISTURE_THRESHOLD &&
          humidity > HUMIDITY_THRESHOLD)
      {
        enterState(IRRIGATING);
      }

      break;

    case IRRIGATING:

      if (millis() - stateStartTime >= IRRIGATION_TIME)
      {
        enterState(COOLDOWN);
      }

      break;

    case COOLDOWN:

      if (millis() - stateStartTime >= COOLDOWN_TIME)
      {
        enterState(IDLE);
      }

      break;

    case FAULT:

      // Fast LED Blink
      if (millis() - blinkTimer >= 250)
      {
        blinkTimer = millis();

        faultLedState = !faultLedState;
        digitalWrite(LED_PIN, faultLedState);
      }

      Serial.println("FAULT: DHT22 failed 3 times");

      break;
  }

  delay(1000);
}
```
