/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

int upperLimit = 100;
int lowerLimit = 0;
int factor = -15;
int duration = lowerLimit;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);
  Serial.println(9991034);
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  if (duration >= upperLimit || duration <= lowerLimit) {
    factor = factor * -1;
  }
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(duration/2);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(duration);    // wait for a second
  duration = duration + factor;
}
