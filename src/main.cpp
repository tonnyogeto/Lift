#include <Arduino.h>
#include "keypad/keypadHandler.h"
#include "ultrasonic/ultrasonicSensor.h"
#include "motor/motorControl.h"

// Target distances for each "floor" in cm
#define DIST_FLOOR_0 45
#define DIST_FLOOR_1 30
#define DIST_FLOOR_2 0

#define SPEED 100  // Motor speed (0–255)
#define TOLERANCE 1.0 // Acceptable margin in cm

void setup() {
    Serial.begin(115200);

    keypadSetup();
    ultrasonicSetup();
    motorSetup();

    Serial.println("Elevator system started");
}

void loop() {
    char key = getKeypadInput();

    if (key != '\0') {
        float targetDistance;

        if (key == '0') targetDistance = DIST_FLOOR_0;
        else if (key == '1') targetDistance = DIST_FLOOR_1;
        else if (key == '2') targetDistance = DIST_FLOOR_2;
        else return;

        Serial.print("Floor selected: ");
        Serial.println(key);

        float currentDistance = getDistance();
        Serial.print("Current Distance: ");
        Serial.print(currentDistance);
        Serial.println(" cm");

        // Move motor until we reach the target distance
        if (currentDistance < targetDistance - TOLERANCE) {
            moveBackward(SPEED);
            while (getDistance() < targetDistance - TOLERANCE) {
                delay(50);
            }
        } else if (currentDistance > targetDistance + TOLERANCE) {
            moveForward(SPEED);
            while (getDistance() > targetDistance + TOLERANCE) {
                delay(50);
            }
        }

        stopMotor();
        Serial.println("Arrived at desired floor\n");

        delay(1000); // Prevent bounce / multiple reads
    }
}












