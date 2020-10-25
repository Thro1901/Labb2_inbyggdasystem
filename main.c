#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
//volatile uint16_t count;

int main (void) {
    int count = 0;

	uart_init();
	LED_init();
    timer_init();
    
    while (1) {

        while ((TIFR0 & (1 << OCF0A)) > 0) {      // wait for the overflow event
            count++; //increment by 1
            if (count == 10) {
                TOGGLE_led();
                count = 0;
            }
            TIFR0 |= (1 << OCF0A);  // reset the overflow flag
        }
    }
}




