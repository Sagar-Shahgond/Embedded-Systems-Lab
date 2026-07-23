#include <Arduino.h>

// Function to set RGB color
// NOTE: RGB LED on Nano 33 BLE Sense Lite is ACTIVE LOW
void setColor(bool red, bool green, bool blue)
{
    digitalWrite(LEDR, red ? LOW : HIGH);
    digitalWrite(LEDG, green ? LOW : HIGH);
    digitalWrite(LEDB, blue ? LOW : HIGH);
}

void setup()
{
    pinMode(LEDR, OUTPUT);
    pinMode(LEDG, OUTPUT);
    pinMode(LEDB, OUTPUT);

    // Turn all LEDs OFF initially
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDB, HIGH);
}

void loop()
{
    // RED
    setColor(true, false, false);
    delay(1000);

    // GREEN
    setColor(false, true, false);
    delay(1000);

    // BLUE
    setColor(false, false, true);
    delay(1000);

    // YELLOW (Red + Green)
    setColor(true, true, false);
    delay(1000);

    // MAGENTA (Red + Blue)
    setColor(true, false, true);
    delay(1000);

    // CYAN (Green + Blue)
    setColor(false, true, true);
    delay(1000);

    // WHITE (Red + Green + Blue)
    setColor(true, true, true);
    delay(1000);

    // OFF
    setColor(false, false, false);
    delay(1000);
}