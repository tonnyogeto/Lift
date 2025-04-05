#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <Arduino.h>

// Define motor control pins (ESP32 supports PWM on most GPIOs)
#define EN1 13   // PWM pin for motor speed
#define IN1 14   // Direction control
#define IN2 27   // Direction control

// Function prototypes
void motorSetup();
void moveForward(int speed);   // speed: 0-255
void moveBackward(int speed);
void stopMotor();

#endif // MOTORCONTROL_H
