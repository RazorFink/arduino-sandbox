/// Test Blink sketch with LED cpp library

//include LED library
#include <LED.h>

// create a new LED object
LED led(13); // new LED on pin 13  

void setup() {}

void loop() {
  led.on();      //turn LED on
  delay(1000);   // wait for a second
  led.off();     //turn LED off
  delay(1000);   // wait for a second
}
