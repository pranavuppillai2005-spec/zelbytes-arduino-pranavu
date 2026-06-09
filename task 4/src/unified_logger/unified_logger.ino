
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define TRIG_PIN 9
#define ECHO_PIN 10

#define LDR_PIN A0
#define SOIL_PIN A1

DHT dht(DHTPIN, DHTTYPE);

const int SOIL_DRY = 850;
const int SOIL_WET = 300;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.println("millis,temp,humidity,distance_cm,soil_raw");
}

float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  return duration * 0.034 / 2;
}

void loop() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  float distance = getDistance();

  int soilRaw = analogRead(SOIL_PIN);

  Serial.print(millis());
  Serial.print(",");

  Serial.print(temp);
  Serial.print(",");

  Serial.print(hum);
  Serial.print(",");

  Serial.print(distance);
  Serial.print(",");

  Serial.println(soilRaw);

  delay(1000);
}
