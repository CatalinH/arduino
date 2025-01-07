#include <IRremote.hpp>
//#include <Servo.h>

#define IR_RECEIVE_PIN 3

//Servo Servo1;

//int servoPin = 2;
//int angle = 0;


void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  //Servo1.attach(servoPin);
}

void loop() {
  if (IrReceiver.decode()){
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
    IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
    Serial.println("Other");
    Serial.println(IrReceiver.decodedIRData.protocol);

    IrReceiver.resume();
  }

  /*
  for (angle = 0; angle <= 180; angle += 30) {
    Servo1.write(angle);
    delay(1000);
  }
  for (angle = 180; angle >= 0; angle -= 30) {
    Servo1.write(angle);
    delay(1000);
  }
  */
}