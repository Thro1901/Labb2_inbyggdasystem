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

    while (1) {
         while ((TIFR2 & (1 << OCF2A)) > 0) { //While TIFR2 register is more than 0. Wait for the overflow event

            OCR0A = simple_ramp();
            TIFR2 |= (1 << OCF2A); // This resets the flag
         }   
    }
}




