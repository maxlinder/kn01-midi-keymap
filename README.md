# KN01 MIDI Keymap

A custom QMK keymap for the Binepad KN01 keyboard, enabling MIDI control for volume and mute. Unlike the factory firmware (which sends only fixed CC values), this keymap supports continuous CC values for smooth rotary encoder operation.

## Features
- **Encoder**: Sends continuous MIDI CC7 (0-127) for volume on channel 1.
- **Button**: Toggles MIDI CC21 (127=on, 0=off) for mute on channel 1.
- **No Vial Support**: Requires custom QMK build.

## Requirements
- QMK firmware (clone https://github.com/qmk/qmk).
- Copy the `keyboards/` folder from this repo into your QMK setup.

## Build & Flash
1. Copy `keyboards/` from this repo to your QMK repo.
2. Run: `make binepad/kn01:midi_cc`
3. Flash: `make binepad/kn01:midi_cc:flash`

## Usage
- Connect KN01 as MIDI device.
- Use with DAWs or apps like UA Console (via UA Midi Control for mapping).

## Files Included
- `keyboards/binepad/kn01/keyboard.json`: Board config with MIDI/encoder.
- `keyboards/binepad/kn01/rules.mk`: Enables MIDI.
- `keyboards/binepad/kn01/keymaps/midi_cc/keymap.c`: MIDI logic.
- `keyboards/binepad/kn01/keymaps/midi_cc/README.md`: This doc.

Created by Max Linder. GPL-2.0 License.