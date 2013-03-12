// PWM Interrupt
// Use Pin Change Interrupt to PWM control D13
// Adjusted clock speed: 16000000 / 128 = 125000
// OVF occurs every 256 clocks
//

void setup() {
  bitSet(DDRB, 5); // Port B, Bit 5, output (aka toggle from initial value of 0)
  TCCR2A = 0; // Timer PWM Channel A set to Normal Mode
  TCCR2B = 5; // Timer PWM Channel B set to slow CK/128
  TIMSK2 = 1<<OCIE2A | 1<<TOIE2; // enable match and overflow interrupts
}

byte pwm = 0;

void loop() {
}

ISR(TIMER2_OVF_vect) {
  if(pwm) bitSet(PORTB, 5); //LED on, maybe
  OCR2A = pwm; // Output Compare Register A for Timer 2
  pwm++;
}

ISR(TIMER2_COMPA_vect) {
  if(pwm < 255) bitClear(PORTB, 5);
}

