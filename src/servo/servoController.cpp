#include "servoController.h"


Servo myServo;

void initServo(int servoPin) {
  myServo.attach(servoPin);
}

void runServoCycle() {

  myServo.write(0);
  Serial.println("Servo at 0°");
  delay(5000);  


  myServo.write(130);
  Serial.println("Servo at 130°");
  delay(5000);  
}

