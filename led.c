#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h> 

#include "led.h"


static bool Increasing = true; 
static uint8_t Brightness = 0;
static uint8_t Period = 255;  // max brightness

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

 uint8_t simple_ramp() {

    if (Brightness <= Period && Increasing == true) {
        Brightness++;
    }
    else if (Brightness <= Period && Increasing == false) {
        Brightness--;
    }
    
    if (Brightness == 255) {
        Increasing = false;            
    }
    else if (Brightness == 0) {
        Increasing = true;
    }
   
    return Brightness;
}
