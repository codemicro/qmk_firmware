#include "layout.c"
#include "quantum.h"
#include "bit-c_led.h"

#define SR_LATCH C6 // ProMicro D5
#define SR_CLOCK D4 // ProMicro D4
#define SR_DATA F5  // ProMicro A5

#define CLOCK_DELAY 10 // microseconds
#define STUPID_DELAY 100 // milliseconds

void shiftOut(uint8_t data) {
    writePin(SR_LATCH, 0);

    // only four bits on the output LEDs
    for (uint8_t bit = 0; bit < 4; bit++) {
        writePin(SR_DATA, (data & (1 << bit)) >> bit);

        writePin(SR_CLOCK, 1);
        wait_us(CLOCK_DELAY);

        writePin(SR_CLOCK, 0);
        wait_us(CLOCK_DELAY);
    }

    writePin(SR_LATCH, 1);
}

// keyboard_post_init_user will run after matrix_init_user, and
// keyboard_post_init_user is the last-ish function that is run, therefore we
// light up the shift register ASAP, then clears it when the keyboard is ready
// to use in the keyboard_post_init_user function.

void matrix_init_user(void) {
    setPinOutput(SR_LATCH);
    setPinOutput(SR_CLOCK);
    setPinOutput(SR_DATA);

    shiftOut(0b1111);
}

void keyboard_post_init_user(void) {
    set_bit_c_LED(LED_OFF);

    wait_ms(STUPID_DELAY);
    shiftOut(0b1110);
    wait_ms(STUPID_DELAY);
    shiftOut(0b1100);
    wait_ms(STUPID_DELAY);
    shiftOut(0b1000);
    wait_ms(STUPID_DELAY);
    shiftOut(0b0000);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    shiftOut(get_highest_layer(state));
    return state;
}
