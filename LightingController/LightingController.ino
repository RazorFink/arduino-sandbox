// An efficient light dimming controller
// PWM Clock = F_CPU / prescaler / phase-correct cycles (510)

void setup() {
  // output ports
  DDRB = 0xFF;       // all outputs PORTB - D8-D13
  DDRD = 0xFF;       // all outputs PORTD - D0-D7

  ADMUX  = 
           0<<REFS1   // Voltage "Reference Selection" set to (0, 1): AVcc
         | 1<<REFS0   //   with external capacitor at AREF pin
         | 1<<ADLAR;  // ADC Left Adjust Result (result bits are left justified)

  ADCSRA =           // "ADC Control and Status Register A"
           1<<ADEN   // "ADC Enable"
         | 1<<ADSC   // "ADC Start Conversion"
         | 1<<ADPS2  // "ADC Prescaler Select Bits"
         | 1<<ADPS1  //   set to (1, 1, 1):
         | 1<<ADPS0; //   Division Factor 128
        
  DIDR0  =            // "Digital Input Disable Register 0"
           1<<ADC5D   // disable Digital Pin 5
         | 1<<ADC4D   // disable Digital Pin 4 
         | 1<<ADC3D   // disable Digital Pin 3 
         | 1<<ADC2D   // disable Digital Pin 2 
         | 1<<ADC1D   // disable Digital Pin 1 
         | 1<<ADC0D;  // disable Digital Pin 0 
  
  TCCR0A =           // "Timer/Counter0 Control Register A"
           1<<COM0A1  // "Compare Match Output A Mode" Combined with PWM mode
         | 0<<COM0A0  //   set to (1, 0): Clear OC0A on Compare Match 
         | 1<<COM0B1  // "Compare Match Output B Mode" Combined with PWM mode
         | 0<<COM0B0  //   set to (1, 0): Clear OC0B on Compare Match
         | 0<<WGM01   // "Waveform Generation Mode"
         | 1<<WGM00;  // Combined with WGM02 bit in TCCR0B and PWM ode
        
        
  TCCR0B =           // "Timer/Counter0 Control Register B"
           0<<WGM02  // "Waveform Generation Mode" Combined with WGM0:1 bits in TCCR0A
         | 1<<CS02   // "Clock Select"
         | 0<<CS01   // Clock I/O / 256 (from prescaler)
         | 0<<CS00;  // 
         
  TCCR1A =           // "Timer/Counter1 Control Register A"
           1<<COM1A1  // "Compare Match Output A Mode" Combined with PWM mode
         | 0<<COM1A0  //   set to (1, 0): Clear OC1A on Compare Match 
         | 1<<COM1B1  // "Compare Match Output B Mode" Combined with PWM mode
         | 0<<COM1B0  //   set to (1, 0): Clear OC1B on Compare Match
         | 0<<WGM11   // "Waveform Generation Mode"
         | 1<<WGM10;  // Combined with WGM12:3 bits in TCCR1B and PWM ode
         
  TCCR1B =           // "Timer/Counter1 Control Register B"
           0<<WGM13  // "Waveform Generation Mode" Combined with 
         | 0<<WGM12  // WGM10:1 bits in TCCR1A
         | 1<<CS12   // "Clock Select"
         | 0<<CS11   // Clock I/O / 256 (from prescaler)
         | 0<<CS10;  //          

  TCCR2A =           // "Timer/Counter1 Control Register A"
           1<<COM2A1  // "Compare Match Output A Mode" Combined with PWM mode
         | 0<<COM2A0  //   set to (1, 0): Clear OC2A on Compare Match 
         | 1<<COM2B1  // "Compare Match Output B Mode" Combined with PWM mode
         | 0<<COM2B0  //   set to (1, 0): Clear OC2B on Compare Match
         | 0<<WGM21   // "Waveform Generation Mode"
         | 1<<WGM20;  // Combined with WGM12 bit in TCCR2B and PWM ode
        
  TCCR2B =           // "Timer/Counter1 Control Register B"
           0<<WGM22  // WGM20:1 bits in TCCR2A
         | 1<<CS22   // "Clock Select"
         | 1<<CS21   // ClkT2S / 256 (from prescaler)
         | 0<<CS20;  //          
       
  bitSet(TIMSK2, TOIE2); // enable Timer/counter2 overflow interrupt
  Serial.begin(9600);
}

void loop() {
}

ISR(TIMER2_OVF_vect) {
  //analogWrite(11, analogRead(0) >> 2); 
  static byte channel = 0;
  byte adc;
  adc = ADCH;  // read upper 8 bits of ADX conversion result
  //const byte pwm_pins[6] = { 11, 10, 9, 6, 5, 3 };
  
  switch(channel) {
    case 0: OCR2A = adc; break; // PWM pin D11 
    case 1: OCR1B = adc; break; // PWM pin D10
    case 2: OCR1A = adc; break; // PWM pin D9
    case 3: OCR0A = adc; break; // PWM pin D6
    case 4: OCR0B = adc; break; // PWM pin D5
    case 5: OCR2B = adc; break; // PWM pin D3
  }
  
  //analogWrite(pwm_pins[channel], analogRead(channel) >> 2);
  
  channel++;
  
  if(channel > 5) {
    channel = 0; // roll over
  }
  
  ADMUX  = 0<<REFS1   // Voltage "Reference Selection" set to (0, 1): AVcc
         | 1<<REFS0   //   with external capacitor at AREF pin
         | 1<<ADLAR   // ADC Left Adjust Result (result bits are left justified)
         | channel;   // Set channel bits 3:0
         
  ADCSRA =           // "ADC Control and Status Register A"
           1<<ADEN   // "ADC Enable"
         | 1<<ADSC   // "ADC Start Conversion"
         | 1<<ADPS2  // "ADC Prescaler Select Bits"
         | 1<<ADPS1  //   set to (1, 1, 1):
         | 1<<ADPS0; //   Division Factor 128
         
  Serial.println(OCR2A);
}

