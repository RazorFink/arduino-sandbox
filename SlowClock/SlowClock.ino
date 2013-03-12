// SlowClock
// Slowing Down the Arduino system clock

void setup() {
  Serial.begin(9600);
  Serial.println("Normal serial comm at 9600bps");
  //bitSet(DDRB, 5);   //Set Pin 13 to OUTPUT
  pinMode(13, OUTPUT);
  noInterrupts();
  CLKPR = 1<<CLKPCE;  //enable clock prescaler write sequence
  CLKPR = 4;          // select clock divisor of 256
  interrupts(); 
}

void loop() {
  //bitSet(PINB, 5);
  digitalWrite(13, HIGH);
  delay(10);
  digitalWrite(13, LOW);
  delay(10);
}


