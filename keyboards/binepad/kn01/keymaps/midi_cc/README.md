# KN01 MIDI Keymap

This is a custom firmware keymap for the Binepad KN01 keyboard, adding MIDI control support for volume and mute.

## Features
- **Encoder**: Controls volume via MIDI CC7 (channel 1, 0-127 range).
- **Button**: Toggles mute via MIDI CC21 (channel 1, 127=on, 0=off).
- **No Vial Support**: This keymap does not include Vial configurator integration.

## Build Instructions
1. Ensure MIDI is enabled in `keyboard.json` and `rules.mk`.
2. Run `make binepad/kn01:midi_cc` to build.
3. Flash with `make binepad/kn01:midi_cc:flash`.

## Usage
- Connect KN01 as a MIDI device in your DAW or controller software.
- Rotate the encoder to adjust volume.
- Press the button to mute/unmute.
- **Customization**: CC numbers (7 for volume, 21 for mute) can be changed in the code for your setup.
- **Future Improvements**: For runtime configuration without reflashing, consider adding SysEx support to change CC numbers dynamically (e.g., send `F0 7D 01 [new_mute_cc] F7` via MIDI to update mute CC).
Compatible with QMK firmware for STM32F103.

## Credits
Created by Max Linder.

## License
This keymap is part of the QMK firmware project and is licensed under the GNU General Public License v2.0 (GPL-2.0). See the main QMK repository for details.
