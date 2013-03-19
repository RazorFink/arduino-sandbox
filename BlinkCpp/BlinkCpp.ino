/// Test Blink sketch with LED cpp library

//include LED library
#include <LED.h>
// create a new LED object
  LED led = LED(13); // new LED on pin 13  
// the setup routine runs once when you press reset:
void setup() {                
  
}

// the loop routine runs over and over again forever:
void loop() {
  led.on();
  delay(1000);               // wait for a second
  led.off();
  delay(1000);               // wait for a second
}
