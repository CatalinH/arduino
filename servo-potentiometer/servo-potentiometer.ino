#include <Servo.h>
Servo Servo1;

int servoPin = 2;
int potPin = A0;

void setup() {
  Servo1.attach(servoPin);
  //Serial.begin(9600);
}

void loop() {
    int reading = analogRead(potPin);
    int angle = map(reading, 0, 1023, 0, 180);
    Servo1.write(angle);
    //Serial.println("V: ");
    //Serial.println(reading);
    delay(1000);
}