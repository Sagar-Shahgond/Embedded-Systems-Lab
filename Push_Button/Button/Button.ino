// Pin definitions
const int buttonPin = 2;
const int ledPin = LED_BUILTIN;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);   // Internal pull-up resistor
  pinMode(ledPin, OUTPUT);
}

void loop() {

  // Button pressed (because INPUT_PULLUP makes pressed = LOW)
  if (digitalRead(buttonPin) == LOW) {

    digitalWrite(ledPin, HIGH);
    delay(300);

    digitalWrite(ledPin, LOW);
    delay(300);

  }
  else {
    // Button released
    digitalWrite(ledPin, LOW);
  }
}