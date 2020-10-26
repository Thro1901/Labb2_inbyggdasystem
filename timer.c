#include <avr/io.h>

#include "timer.h"

void timer_init() {
    // set fast PWM Mode, non-inverting
    TCCR0A |= (1 << WGM01) | (1 << WGM00) | (1 << COM0A1);

    TCCR0B |= (1 << CS00) | (1 << CS01);
    // set prescaler to 64
}

