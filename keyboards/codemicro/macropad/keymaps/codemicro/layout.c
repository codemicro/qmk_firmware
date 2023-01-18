#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ l │ i │ k │
     * ├───┼───┼───┤
     * │ e │ t │ h │
     * ├───┼───┼───┤
     * │ i │ s │ ! │
     * └───┴───┴───┘
     */
    [0] = LAYOUT_ortho_3x3(
        KC_TRNS,             KC_TRNS,             KC_TRNS,
        KC_TRNS,             KC_TRNS,             KC_TRNS,
        KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK
    )
};