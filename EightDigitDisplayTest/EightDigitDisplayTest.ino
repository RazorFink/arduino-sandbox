// 8 digit display test
// control 8 * 7-segment displays over SPI using LedControl library

#include "LedControl.h"
#define PIN_DIN 12
#define PIN_CLK 11
#define PIN_LOAD 10

LedControl lc = LedControl(PIN_DIN, PIN_CLK, PIN_LOAD, 1);

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0); 
}

void displayMessage(byte startDigit, String message) {
  for (int c = 0; c < message.length(); c++) {
    lc.setChar(0, startDigit - c, message[c], false);
  }  
}

void counter(byte digit) {
   lc.setDigit(0,digit,0,false);
   for (int i = 1; i < 11; i++) {
    if(digit){
      counter(digit-1);
    }
    lc.setDigit(0, digit, i, false); 
  }
}

void loop() { 
  counter(7);
}
