#include <avr/io.h>

#include "timer.h"

void timer_init() {
    // set fast PWM Mode, non-inverting
    TCCR0A |= (1 << WGM01) | (1 << WGM00) | (1 << COM0A1);
    // set timer2 to ctc mode
    TCCR2A |= (1 << WGM21);

    OCR2A = 249; // Top value

    TCNT2 = 0; // start the counter

    // set prescaler to 1024
    TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);
    // set prescaler to 64
    TCCR0B |= (1 << CS01) | (1 << CS00);
    
}

