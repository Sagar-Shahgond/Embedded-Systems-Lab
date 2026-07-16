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
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.println("Magnetometer Started");
}

void loop() {

  float x, y, z;

  if (IMU.magneticFieldAvailable()) {

    IMU.readMagneticField(x, y, z);

    float strength = sqrt(x*x + y*y + z*z);

    Serial.print("Strength: ");
    Serial.println(strength);

    // Turn OFF all LEDs
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);

    if (strength < 40) {
      digitalWrite(GREEN, LOW);
    }
    else if (strength < 60) {
      digitalWrite(BLUE, LOW);
    }
    else {
      digitalWrite(RED, LOW);
    }
  }

  delay(200);
}