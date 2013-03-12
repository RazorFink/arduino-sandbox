// A shrunken version of Blink

// make timer0_milis available for inappropriate manipulation
extern volatile unsigned long timer0_millis;

void setup() {                
  // initialize the digital pin as an output.
 bitSet(DDRB, 5); // DDR (Port) B, Bit 5 (D13), set to 1 (OUTPUT)
}


void loop() {
  bitSet(PINB, 5);  //Toggle Pin (Port) B, Bit 5 (D13)
  while(timer0_millis < 1000); // wait 1 second
  timer0_millis = 0; // Reset arduino millisecond counter
}
