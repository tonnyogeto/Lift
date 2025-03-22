#ifndef SERVOCONTROLLER_H
#define SERVOCONTROLLER_H

#include <Arduino.h>
#include <ESP32Servo.h>

// Function declarations for initializing the servo and running the cycle
void initServo(int servoPin);
void runServoCycle();

#endif  // SERVOCONTROLLER_H