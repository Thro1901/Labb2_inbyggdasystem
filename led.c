#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

void LED_init() {

	DDRD |= (1 << PD6); //PORTD To output pwn pin 6
}

void TOGGLE_led() {

	PORTB ^= (1 << PB0);
}

void LED_on() {

	PORTB |= (1 << PB0); //put bit PB0 to HIGH
}

void LED_off() {

	PORTB &= ~(1 << PB0); //put bit PB0 to LOW
}

void BLINK_led() {
	PORTB |= (1 << PB0); //put bit PB0 to HIGH
	_delay_ms(50);
	PORTB &= ~(1 << PB0); //put bit PB0 to LOW
	_delay_ms(50);
}
