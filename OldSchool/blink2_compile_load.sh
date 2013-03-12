avr-gcc -mmcu=atmega328p blink2.c -o blink2.o
avr-objcopy -O ihex blink2.o blink2.hex
avrdude -p atmega328p -c arduino -P /dev/tty.usbmodemfa141 -U flash:w:blink2.hex:i