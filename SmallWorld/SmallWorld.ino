// Small World
// Optimized Serial Communication
//#define BAUD_RATE 9600
//#define BAUD_RATE_DIVISOR (b) (F_CPU / 16 / b -1)  

void usart_init(int baud_rate){
  UBRR0 = F_CPU / 16/baud_rate -1;
  
  UCSR0A = 0<<TXC0   
         | 0<<U2X0    
         | 0<<MPCM0;
         
  UCSR0B = 0<<RXCIE0 
         | 0<<TXCIE0  
         | 0<<UDRIE0 
         | 0<<RXEN0 
         | 1<<TXEN0  
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
void usart_putc(char c) {
//  loop_until_bit_is_set(UCSR0A, UDRE0);  //Wait for transmit buffer to be empty
  while(!bitRead(UCSR0A, UDRE0));  // alternative to above function (macro)
  UDR0 = c; //transmit character out of the serial port
}

void usart_puts(char *s) {
  while(*s) {
    usart_putc(*s);
    s++;
  }
  usart_putc('\n');
}

void usart_puti(long i) {
  char s[25]; //character buffer to build string in
  itoa(i, s, 10);  //convert integer to ASCII string, base 10
  usart_puts(s);  //not print the string on the serial port  
}

void usart_putitob(long i) {
  char s[25]; //character buffer to build string in
  itoa(i, s, 2);  //convert integer to ASCII string, base 10
  usart_puts(s);  //not print the string on the serial port  
}

void usart_putitox(long i) {
  char s[25]; //character buffer to build string in
  itoa(i, s, 16);  //convert integer to ASCII string, base 10
  usart_puts(s);  //not print the string on the serial port  
}
void setup() 
{
  usart_init(9600);
  for(int i = 0; i < 0xFFF; i++){
    usart_putitox(i); 
  }
}

void loop()
{
  
}
