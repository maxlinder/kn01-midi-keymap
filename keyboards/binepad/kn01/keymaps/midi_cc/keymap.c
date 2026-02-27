#include QMK_KEYBOARD_H

enum custom_keycodes {
    CC7_INC = SAFE_RANGE,
    CC7_DEC,
    CC21_TOGGLE
};

bool cc21_state = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CC7_INC:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 1, 7, midi_cc_increment(1, 7, 1));
            }
            return false;
        case CC7_DEC:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 1, 7, midi_cc_decrement(1, 7, 1));
            }
            return false;
        case CC21_TOGGLE:
            if (record->event.pressed) {
                cc21_state = !cc21_state;
                midi_send_cc(&midi_device, 1, 21, cc21_state ? 127 : 0);
            }
            return false;
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        midi_send_cc(&midi_device, 1, 7, midi_cc_increment(1, 7, 1));
    } else {
        midi_send_cc(&midi_device, 1, 7, midi_cc_decrement(1, 7, 1));
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_1x1(CC21_TOGGLE)
};