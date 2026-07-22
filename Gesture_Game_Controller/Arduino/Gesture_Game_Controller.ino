#include <Arduino.h>
#include <Arduino_APDS9960.h>
#include <Arduino_LSM9DS1.h>

//=====================================================
//                  CONFIGURATION
//=====================================================

// Potentiometer Pin
const int POT_PIN = A6;

// Brake Threshold
const int BRAKE_THRESHOLD = 150;

// Steering Thresholds
const float LEFT_THRESHOLD  = -0.30;
const float RIGHT_THRESHOLD =  0.30;

//=====================================================
//                  VARIABLES
//=====================================================

// Potentiometer
int potValue = 0;
int throttle = 0;

// Proximity
int proximity = 0;
bool brake = false;

// Accelerometer
float x, y, z;
int direction = 0;

//=====================================================
//                     SETUP
//=====================================================

void setup()
{
    Serial.begin(115200);
    while (!Serial);

    // Nano 33 BLE Sense uses a 12-bit ADC
    analogReadResolution(12);

    // Initialize Proximity Sensor
    if (!APDS.begin())
    {
        Serial.println("ERROR : APDS9960 not detected!");
        while (1);
    }

    // Initialize Accelerometer
    if (!IMU.begin())
    {
        Serial.println("ERROR : IMU not detected!");
        while (1);
    }

    Serial.println("----------------------------------------");
    Serial.println("Gesture Gaming Controller Started");
    Serial.println("----------------------------------------");
}

//=====================================================
//                      LOOP
//=====================================================

void loop()
{
    //-------------------------------------------------
    // Read Potentiometer
    //-------------------------------------------------

    potValue = analogRead(POT_PIN);

    throttle = map(potValue, 0, 4095, 0, 100);

    throttle = constrain(throttle, 0, 100);

    //-------------------------------------------------
    // Read Proximity Sensor
    //-------------------------------------------------

    if (APDS.proximityAvailable())
    {
        proximity = APDS.readProximity();

        if (proximity < BRAKE_THRESHOLD)
            brake = true;
        else
            brake = false;
    }

    //-------------------------------------------------
    // Read Accelerometer
    //-------------------------------------------------

    if (IMU.accelerationAvailable())
    {
        IMU.readAcceleration(x, y, z);

        if (x < LEFT_THRESHOLD)
        {
            direction = -1;
        }
        else if (x > RIGHT_THRESHOLD)
        {
            direction = 1;
        }
        else
        {
            direction = 0;
        }
    }

    //-------------------------------------------------
    // Send Packet
    // Format:
    // Throttle,Brake,Direction
    //
    // Example:
    // 75,0,1
    //-------------------------------------------------

    Serial.print(throttle);
    Serial.print(",");

    Serial.print(brake);
    Serial.print(",");

    Serial.println(direction);

    delay(20);
}