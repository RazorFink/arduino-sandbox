// 8 digit display test
// control 8 * 7-segment displays over SPI using LedControl library

#include "LedControl.h"
#define PIN_DIN = 12
#define PIN_CLK = 11
#define PIN_LOAD = 10

LedControl lc = LedControl(12, 11, 10, 1);

//char message[8] = {'b','0','0','b','1','E','5'};
String message = "b00b1E5";
byte delayTime = 250;

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


void loop() { 
  for (int d = 0; d < 8 + message.length(); d++){
    lc.clearDisplay(0);
    displayMessage(d, message);
    delay(delayTime);
  }
}
