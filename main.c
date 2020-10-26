#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

int main (void) {  
    
	uart_init();
	LED_init();
    timer_init();
    LED_on();
    
    while (1) { 
        int Duty = 0;
        for (Duty = 0; Duty <= 255; Duty++)   // 0 to max duty cycle
        {
            OCR0A = Duty;     //slowly increase the LED brightness
            _delay_ms(10);
        }
        for (Duty = 255; Duty >= 0; Duty--)   // max to 0 duty cycle
        {
            OCR0A = Duty;     //slowly decrease the LED brightness
            _delay_ms(10);
        }
    }
}




