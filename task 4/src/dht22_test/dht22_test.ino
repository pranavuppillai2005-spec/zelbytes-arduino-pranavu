#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  Serial.print("Temperature: ");
  Serial.print(dht.readTemperature());

  Serial.print(" C  Humidity: ");
  Serial.print(dht.readHumidity());

  Serial.println(" %");

  delay(2000);
}
