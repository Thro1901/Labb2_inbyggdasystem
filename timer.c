#include <avr/io.h>

#include "timer.h"

void timer_init() {
    // Set the Timer Mode to CTC
    TCCR0A |= (1 << WGM01);

    // Set the value (155) that you want to count to
    OCR0A = 0x9B;
    // Counts up with each pulse. MAX 255
    TCNT0 = 0; 

    TCCR0B |= (1 << CS00) | (1 << CS02);
    // set prescaler to 1024 and start the timer
}

