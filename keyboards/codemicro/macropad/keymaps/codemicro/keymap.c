#include "layout.c"
#include "quantum.h"

#define RED_LED GP2
#define YELLOW_LED GP3
#define GREEN_LED GP4

void matrix_init_user(void) {
    setPinOutput(RED_LED);
    setPinOutput(YELLOW_LED);
    setPinOutput(GREEN_LED);


    writePin(YELLOW_LED, 1);
}

void keyboard_post_init_user(void) {
    writePin(YELLOW_LED, 0);
    writePin(GREEN_LED, 1);
    wait_ms(200);
    writePin(GREEN_LED, 0);
}
