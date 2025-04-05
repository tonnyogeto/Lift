#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <Arduino.h>

// Define Ultrasonic Sensor Pins (pick free GPIOs)
#define TRIG_PIN 26
#define ECHO_PIN 25

// Function prototypes
void ultrasonicSetup();
float getDistance();

#endif // ULTRASONIC_SENSOR_H
