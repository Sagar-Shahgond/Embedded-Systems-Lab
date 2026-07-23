#include <Arduino_APDS9960.h>

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

  if (!APDS.begin()) {
    Serial.println("Error initializing APDS9960!");
    while (1);
  }

  Serial.println("Gesture Sensor Ready");
}

void loop() {

  if (APDS.gestureAvailable()) {

    int gesture = APDS.readGesture();

    // OFF
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);

    switch (gesture) {

      case GESTURE_LEFT:
        Serial.println("LEFT");
        digitalWrite(RED, LOW);
        break;

      case GESTURE_RIGHT:
        Serial.println("RIGHT");
        digitalWrite(GREEN, LOW);
        break;

      case GESTURE_UP:
        Serial.println("UP");
        digitalWrite(BLUE, LOW);
        break;

      case GESTURE_DOWN:
        Serial.println("DOWN");
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, LOW);
        break;
    }
  }
}