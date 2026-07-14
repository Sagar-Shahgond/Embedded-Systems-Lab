#include <Arduino_LSM9DS1.h>

// RGB LED pins (Active LOW)
#define RED   LEDR
#define GREEN LEDG
#define BLUE  LEDB

void setup() {
  Serial.begin(9600);
  while (!Serial);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  // Turn all colors OFF
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.println("Magnetometer RGB Demo");
}

void loop() {

  float x, y, z;

  if (IMU.magneticFieldAvailable()) {

    IMU.readMagneticField(x, y, z);

    Serial.print("X: ");
    Serial.print(x);
    Serial.print("  ");

    Serial.print("Y: ");
    Serial.print(y);
    Serial.print("  ");

    Serial.print("Z: ");
    Serial.println(z);

    // Turn everything OFF first
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);

    // Compare absolute values
    float ax = abs(x);
    float ay = abs(y);
    float az = abs(z);

    if (ax > ay && ax > az) {
      // X strongest -> RED
      digitalWrite(RED, LOW);
    }
    else if (ay > ax && ay > az) {
      // Y strongest -> GREEN
      digitalWrite(GREEN, LOW);
    }
    else {
      // Z strongest -> BLUE
      digitalWrite(BLUE, LOW);
    }
  }

  delay(100);
}