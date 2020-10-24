#include <avr/io.h>
#include "led.h"

void LED_init() {

	DDRB |= (1 << PB0); //PORTB To output
}


void blink_led() {

	PORTB |= (1 << PB0); //put bit PB0 to HIGH
	_delay_ms(500);
	PORTB &= ~(1 << PB0); //put bit PB0 to LOW
	_delay_ms(500);
}

void LED_on() {

	PORTB |= (1 << PB0); //put bit PB0 to HIGH
}

void LED_off() {

	PORTB &= ~(1 << PB0); //put bit PB0 to LOW
}