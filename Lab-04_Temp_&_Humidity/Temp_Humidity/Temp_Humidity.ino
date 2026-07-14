#include <Arduino_HS300x.h>

void setup() {

  Serial.begin(9600);

  while (!Serial);

  if (!HS300x.begin()) {
    Serial.println("Failed to initialize humidity sensor!");
    while (1);
  }

  Serial.println("Temperature and Humidity Monitor");
}

void loop() {

  float temperature = HS300x.readTemperature();
  float humidity = HS300x.readHumidity();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C");

  Serial.print("    Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(1000);
}