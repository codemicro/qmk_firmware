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
        MO(1),               KC_TRNS,             LCTL(KC_F2),
        SGUI(KC_SPACE),      LALT(KC_A),          LSFT(KC_F10),
        KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK
    ),
    [1] = LAYOUT_ortho_3x3(
	KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, LSFT(KC_F9),
	KC_TRNS, KC_TRNS, KC_TRNS
    )
};
