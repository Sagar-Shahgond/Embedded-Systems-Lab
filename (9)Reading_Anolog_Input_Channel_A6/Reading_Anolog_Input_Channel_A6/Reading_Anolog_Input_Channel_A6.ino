const int analogPin = A6;

void setup() {
  Serial.begin(9600);
}

void loop() {

  int sensorValue = analogRead(analogPin);

  Serial.print("A6 Value: ");
  Serial.println(sensorValue);

  delay(200);
}