# Corne V3 Miryoku QMK configuration

Target: Corne V3 (`crkbd/rev1`) with an RP2040 Pro Micro-compatible controller, such as Elite-Pi.

The configuration preserves the existing 36-key Miryoku arrangement:

- QWERTY alphas
- VI navigation
- Miryoku home-row mods and layers
- Six previously disabled outer positions enabled as fixed keys

Outer keys:

```text
Left                         Right
TAB   [Q W E R T]       [Y U I O P]   \\
ESC   [A S D F G]       [H J K L ;]   '
LSHFT [Z X C V B]       [N M , . /]   RSHFT
```

The added keys are fixed on every Miryoku layer. `KC_BSLS` produces backslash; with Shift it produces pipe.

## Build

Use the Miryoku QMK development branch, whose source matches the vendored Miryoku module:

```sh
git clone --branch miryoku https://github.com/manna-harbour/miryoku_qmk.git "$HOME/miryoku_qmk"
cd "$HOME/miryoku_qmk"
qmk setup
make git-submodule
```

Then build this configuration:

```sh
QMK_FIRMWARE="$HOME/miryoku_qmk" ./build.sh
```

The script copies this keymap and the vendored Miryoku user module into the QMK checkout and builds:

```sh
qmk compile -kb crkbd/rev1 -km miryoku -e CONVERT_TO=elite_pi
```

For an RP2040 controller whose QMK converter is not named `elite_pi`, change only the `CONVERT_TO` value after confirming the controller's QMK converter name.

Do not flash until the generated firmware has been tested and the exact controller/bootloader is confirmed. Corne V3 uses the `rev1` hardware definition; Corne V4 uses a different target.

Left                         Right
TAB   [Q W E R T]       [Y U I O P]   Backslash
ESC   [A S D F G]       [H J K L ;]   '
Shift [Z X C V B]       [N M , . /]   Shift
