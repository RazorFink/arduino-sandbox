// LED.cpp - Example library for manipulating LEDs

#include "LED.h"

// the constructor

LED::LED(byte pin) {
	_pin = pin; 			//set private member to init value
	pinMode(pin, OUTPUT); 	//configure pin as output
}

// the public methods

void LED::on() {
	digitalWrite(_pin, HIGH); //turn on LED
	_state = HIGH;
}

void LED::off() {
	digitalWrite(_pin, LOW); // turn off LED
	_state = LOW;
}

void LED::toggle() {
	if(_state) {
		off();
	} else {
		on();
	}
}

byte LED::state() {
	return _state;
}