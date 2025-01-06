#include <Servo.h>
Servo Servo1;

int servoPin = 2;
int angle = 0;

void setup() {
  Servo1.attach(servoPin);
}

void loop() {
  for (angle = 0; angle <= 180; angle += 30) {
    Servo1.write(angle);
    delay(1000);
  }
  for (angle = 180; angle >= 0; angle -= 30) {
    Servo1.write(angle);
    delay(1000);
  }
}