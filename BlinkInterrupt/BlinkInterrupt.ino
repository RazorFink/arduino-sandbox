/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  Serial.begin(9600);
  bitSet(PCICR, PCIE0); // enable pin change interrupt bank 0
  bitSet(PCMSK0, PCINT5); // enable pin change interrupt on PCINT5/D13
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}

ISR(PCINT0_vect) {
  if(digitalRead(13) == HIGH) {
    Serial.println("LED is ON");
  } else {
    Serial.println("LED is OFF");
  }    
}

