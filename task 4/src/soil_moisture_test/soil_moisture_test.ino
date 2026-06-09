#define SOIL_PIN A1

void setup() {
  Serial.begin(9600);
}

void loop() {

  int soil = analogRead(SOIL_PIN);

  Serial.print("Soil Raw: ");
  Serial.println(soil);

  delay(1000);
}
