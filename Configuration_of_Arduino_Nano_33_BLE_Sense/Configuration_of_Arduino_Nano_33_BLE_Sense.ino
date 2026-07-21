#include <Arduino_LSM9DS1.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.println("Arduino Nano 33 BLE Sense Configured Successfully");

  Serial.print("Accelerometer Sample Rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");

  Serial.print("Gyroscope Sample Rate = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");

  Serial.print("Magnetometer Sample Rate = ");
  Serial.print(IMU.magneticFieldSampleRate());
  Serial.println(" Hz");
}

void loop() {
}