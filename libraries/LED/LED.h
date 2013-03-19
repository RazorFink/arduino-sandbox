// LED.h: Simple C++ library for LEDs
// Public Domain, flibbity bibbity blah

#ifndef LED_h  //compiler directive, if LED_h is not defined
#define LED_h  //then define LED_h

#if ARDUINO < 100 //Workaround to enable compatibility with older bootloader versions
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

class LED {
		byte _pin;  	//private; the LED pin #
		byte _state; 	//private; current state of pin (on/off)
	public:
		LED(byte pin);	//constructor
		void on();		//turn LED on	
		void off();		//turn LED off
		void toggle();	//toggle LED state
		byte state();	//read current LED state
};

#endif 
