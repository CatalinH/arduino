#include "DHT.h"
DHT dht(A0, DHT11); // A0 - sensor signal pin, DHT11 - DHT TYPE 11

//cathode common 4 digit display - 3461AS
#define DISPLAY_PORT_ON HIGH
#define DISPLAY_PORT_OFF LOW
//anode common 4 digit display
// #define DISPLAY_PORT_ON LOW;
// #define DISPLAY_PORT_OFF HIGH;

// display character segment to port map
int DSa = 2;
int DSb = 3;
int DSc = 4;
int DSd = 5;
int DSe = 6;
int DSf = 7;
int DSg = 8;

// display characters to port map
int DC1 = 9;
int DC2 = 10;
int DC3 = 11;
int DC4 = 12;

// values
int temperature;
int humidity;
int i;
int digit1;
int digit2;

enum chars {I_0, I_1, I_2, I_3, I_4, I_5, I_6, I_7, I_8, I_9, S_C, S_LOW_o, S_UP_o};

void setup() {
  dht.begin();
  pinMode(DSa, OUTPUT);
  pinMode(DSb, OUTPUT);
  pinMode(DSc, OUTPUT);
  pinMode(DSd, OUTPUT);
  pinMode(DSe, OUTPUT);
  pinMode(DSf, OUTPUT);
  pinMode(DSg, OUTPUT);
  pinMode(DC1, OUTPUT);
  pinMode(DC2, OUTPUT);
  pinMode(DC3, OUTPUT);
  pinMode(DC4, OUTPUT);
}

void loop() {
  displayTemperature();
  delay(5000);
  displayHumidity();
  delay(5000);
}
void displayTemperature() {
  temperature = dht.readTemperature();
  digit1 = temperature / 10;
  digit2 = temperature - (digit1 * 10);
  for (int i = 1; i <= 1000; i++) {
    displayPositionWrite(DC4, S_C); //digit 4 - most right character
    displayPositionWrite(DC3, S_UP_o); // digit 3
    displayPositionWrite(DC2, digit2); // digit 2
    displayPositionWrite(DC1, digit1); // digit 1 - most left character
  }
}
void displayHumidity() {
  humidity = dht.readHumidity();
  digit1 = humidity / 10;
  digit2 = humidity - (digit1 * 10);
  for (int i = 1; i <= 1000; i++) {
    displayPositionWrite(DC4, S_LOW_o); //digit 4 - most right character
    displayPositionWrite(DC3, S_UP_o); // digit 3
    displayPositionWrite(DC2, digit2); // digit 2
    displayPositionWrite(DC1, digit1); // digit 1 - most left character
  }
}
void digitalWriteCharacter(uint8_t *aVal, uint8_t *bVal, uint8_t *cVal, uint8_t *dVal, uint8_t *eVal, uint8_t *fVal, uint8_t *gVal) {
  digitalWrite(DSa, aVal);
  digitalWrite(DSb, bVal);
  digitalWrite(DSc, cVal);
  digitalWrite(DSd, dVal);
  digitalWrite(DSe, eVal);
  digitalWrite(DSf, fVal);
  digitalWrite(DSg, gVal);
}

void displayCharacter(chars str) {
  switch (str) {
    case I_0: digitalWriteCharacter(DISPLAY_PORT_ON,  DISPLAY_PORT_ON,  DISPLAY_PORT_ON,  DISPLAY_PORT_ON,  DISPLAY_PORT_ON,  DISPLAY_PORT_ON,  DISPLAY_PORT_OFF);  break;
    case I_1: digitalWriteCharacter(DISPLAY_PORT_OFF, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_OFF, DISPLAY_PORT_OFF, DISPLAY_PORT_OFF, DISPLAY_PORT_OFF); break;
    case I_2: digitalWriteCharacter(DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_OFF, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_OFF, DISPLAY_PORT_ON); break;
    case I_3: digitalWriteCharacter(DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_OFF, DISPLAY_PORT_OFF, DISPLAY_PORT_ON); break;
    case I_4: digitalWriteCharacter(DISPLAY_PORT_OFF, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_OFF, DISPLAY_PORT_OFF, DISPLAY_PORT_ON, DISPLAY_PORT_ON); break;
    case I_5: digitalWriteCharacter(DISPLAY_PORT_ON, DISPLAY_PORT_OFF, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_OFF, DISPLAY_PORT_ON, DISPLAY_PORT_ON); break;
    case I_6: digitalWriteCharacter(DISPLAY_PORT_ON, DISPLAY_PORT_OFF, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_ON); break;
    case I_7: digitalWriteCharacter(DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_OFF, DISPLAY_PORT_OFF, DISPLAY_PORT_OFF, DISPLAY_PORT_OFF); break;
    case I_8: digitalWriteCharacter(DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_ON); break;
    case I_9: digitalWriteCharacter(DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_OFF, DISPLAY_PORT_ON, DISPLAY_PORT_ON); break;
    case S_C: digitalWriteCharacter(DISPLAY_PORT_ON, DISPLAY_PORT_OFF, DISPLAY_PORT_OFF, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_OFF); break;
    case S_UP_o: digitalWriteCharacter(DISPLAY_PORT_ON,  DISPLAY_PORT_ON,  DISPLAY_PORT_OFF,  DISPLAY_PORT_OFF,  DISPLAY_PORT_OFF,  DISPLAY_PORT_ON,  DISPLAY_PORT_ON); break;
    case S_LOW_o: digitalWriteCharacter(DISPLAY_PORT_OFF, DISPLAY_PORT_OFF, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_ON, DISPLAY_PORT_OFF, DISPLAY_PORT_ON); break;
  }
}

void displayPositionWrite(int position, chars str) {
    digitalWrite(position, DISPLAY_PORT_OFF);
    displayCharacter(str);
    delay(4);
    digitalWrite(position, DISPLAY_PORT_ON);
}
