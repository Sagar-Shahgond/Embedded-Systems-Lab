void setup() {
  // Start Serial Communication
  Serial.begin(9600);

  // Wait for Serial Monitor to open
  while (!Serial);

  // Print your name once
  Serial.println("Hello!");
  Serial.println("My Name is Sagar Shahgond");
}

void loop() {
  // Nothing to do here
}