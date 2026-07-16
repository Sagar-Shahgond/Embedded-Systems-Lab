#include <Arduino_LSM9DS1.h>

#define RED LEDR
#define GREEN LEDG
#define BLUE LEDB

void setup() {

  Serial.begin(9600);
  while (!Serial);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);

  if (!IMU.begin()) {
    Serial.println("IMU Failed!");
    while (1);
  }

  Serial.println("Tilt Detector");
}

void loop() {

  float x, y, z;

  if (IMU.accelerationAvailable()) {

    IMU.readAcceleration(x, y, z);

    Serial.print("X: ");
    Serial.print(x);

    Serial.print("\tY: ");
    Serial.print(y);

    Serial.print("\tZ: ");
    Serial.println(z);

    // OFF
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);

    if (x > 0.6) {

      digitalWrite(RED, LOW);

    }
    else if (x < -0.6) {

      digitalWrite(GREEN, LOW);

    }
    else if (y > 0.6) {

      digitalWrite(BLUE, LOW);

    }
    else {

      // White
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
      digitalWrite(BLUE, LOW);
    }
  }

  delay(100);
}