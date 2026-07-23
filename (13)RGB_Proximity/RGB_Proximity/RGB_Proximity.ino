#include <Arduino_APDS9960.h>

// RGB LED pins (active LOW)
#define RED   LEDR
#define GREEN LEDG
#define BLUE  LEDB

void setup() {
  Serial.begin(9600);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  // Turn all colors off
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);

  if (!APDS.begin()) {
    Serial.println("Error initializing APDS9960!");
    while (1);
  }

  Serial.println("Proximity Sensor Ready");
}

void loop() {

  if (APDS.proximityAvailable()) {

    int proximity = APDS.readProximity();

    Serial.print("Proximity: ");
    Serial.println(proximity);

    if (proximity < 80) {
      // Far -> Green
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(BLUE, HIGH);
    }
    else if (proximity < 180) {
      // Medium -> Blue
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, HIGH);
      digitalWrite(BLUE, LOW);
    }
    else {
      // Near -> Red
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, HIGH);
      digitalWrite(BLUE, HIGH);
    }
  }
}