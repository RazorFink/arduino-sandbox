//SerialInterrupt
//  Test USART interrupts

void usart_init(int baud_rate){
  UBRR0 = (F_CPU / 16/baud_rate -1);
  
  UCSR0A = 0<<TXC0   
         | 0<<U2X0    
         | 0<<MPCM0;
         
  UCSR0B = 1<<RXCIE0 
         | 0<<TXCIE0  
         | 0<<UDRIE0 
         | 1<<RXEN0 
         | 0<<TXEN0  
         | 0<<UCSZ02  
         | 0<<TXB80;
         
  UCSR0C = 0<<UMSEL01
         | 0<<UMSEL00 
         | 0<<UPM01  
         | 0<<UPM00 
         | 0<<USBS0  
         | 1<<UCSZ01  
         | 1<<UCSZ00  
         | 0<<UCPOL0;
}

void setup() {
  bitSet(DDRB, 5);
  usart_init(9600); 
  //Serial.begin(9600);
}

void loop() {
//    bitSet(PINB, 5);
//  delay(500);
}

ISR(USART_RX_vect) {
  unsigned char c = UDR0; // read incoming byte to clear interrupt flag
  if(c == '1' && !bitRead(PINB, 5)) {
      bitWrite(PINB, 5, 1);
  }else if(c == '0') {
    bitClear(PORTB, 5);
  }
}
