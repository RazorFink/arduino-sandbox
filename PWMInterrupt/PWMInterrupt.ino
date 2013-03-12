// PWM Interrupt
// Use Pin Change Interrupt to PWM control D13

void setup() {
  bitSet(DDRB, 5);
  bitSet(PCICR, PCIE0); //Enable Pin Change Interrupts on Bank 0
  bitSet(PCMSK0, PCINT3);  // enable PCINT (PB2) pin change interrupt
}

byte pwm = 0;

void loop() {
  analogWrite(11, pwm);
  delay(20);
  pwm++;
}

ISR(PCINT0_vect) {
  if(bitRead(PINB, 3)) {
    bitSet(PORTB, 5); // LED on
  } else {
    bitClear(PORTB, 5); // LED off
  }
}
