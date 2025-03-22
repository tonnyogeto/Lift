#include <Arduino.h>
#include "servo/servoController.h"

const int servoPin = 14; 

void setup() {
  Serial.begin(115200);
  Serial.println("Servo Test: Running servo cycle");
  initServo(servoPin);  // Initialize the servo using our function
}

void loop() {
  runServoCycle();      // Call the function that moves the servo
}












