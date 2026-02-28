#include QMK_KEYBOARD_H
#include "midi.h"

extern MidiDevice midi_device;  // Declare the MIDI device

enum {
    MUTE_TOGGLE = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_1x1(MUTE_TOGGLE)
};

// Encoder code (clamped at 0-127, start at 13 for 10%)
static uint8_t cc_value = 13;

void keyboard_post_init_user(void) {
    midi_send_cc(&midi_device, 1, 7, cc_value);  // Init CC7 to 10% on channel 1
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise && cc_value < 127) {
            cc_value += 1;
        } else if (!clockwise && cc_value > 0) {
            cc_value -= 1;
        }
        midi_send_cc(&midi_device, 1, 7, cc_value);  // CC7 for volume on channel 1
    }
    return true;
}

// Button code: Toggle mute on CC21
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == MUTE_TOGGLE && record->event.pressed) {
        static bool mute_state = false;
        mute_state = !mute_state;
        midi_send_cc(&midi_device, 1, 21, mute_state ? 127 : 0);  // Toggle mute on channel 1
    }
    return true;
}
