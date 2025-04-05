#include "keypadHandler.h"
#include <Arduino.h>

// Define keypad pins (choose GPIOs that are not used by LoRa)
#define ROW1 18  // GPIO 18
#define ROW4 19  // GPIO 19
#define COL1 21  // GPIO 21
#define COL2 22  // GPIO 22

void keypadSetup() {
    pinMode(ROW1, INPUT_PULLUP);
    pinMode(ROW4, INPUT_PULLUP);
    pinMode(COL1, OUTPUT);
    pinMode(COL2, OUTPUT);
    digitalWrite(COL1, HIGH);
    digitalWrite(COL2, HIGH);
}

char getKeypadInput() {
    digitalWrite(COL1, LOW);
    digitalWrite(COL2, HIGH);
    if (!digitalRead(ROW1)) return '1';

    digitalWrite(COL1, HIGH);
    digitalWrite(COL2, LOW);
    if (!digitalRead(ROW1)) return '2';
    if (!digitalRead(ROW4)) return '0';

    return '\0';  // No key pressed
}
