# Agent instructions

## Hardware

- Target: wired Corne V3 / `crkbd/rev1`.
- Controller: Elite-Pi RP2040 on both halves.
- Build conversion: `CONVERT_TO=elite_pi`.
- The keyboard uses the six breakaway-column positions.
- OLED modules are I2C SSD1306 displays using the 128x32 geometry.
- OLED rotation is `OLED_ROTATION_270`.
- Only the USB/master half should render OLED content; the secondary OLED is explicitly disabled.

## Source of truth

- The compiled keymap is `keyboards/crkbd/rev1/keymaps/miryoku/keymap.c`.
- The compiled layout macros and OLED settings are in `keyboards/crkbd/rev1/keymaps/miryoku/config.h`.
- The compiled keymap build options are in `keyboards/crkbd/rev1/keymaps/miryoku/rules.mk`.
- Do not assume files under `users/manna-harbour_miryoku/` are compiled. The repository contains duplicate Miryoku sources; verify the actual QMK checkout after `build.sh` copies files.
- The build wrapper copies the project keymap and user module into the QMK checkout at `$QMK_FIRMWARE`.

## Build and verification

1. Use the Miryoku QMK checkout, normally `$HOME/miryoku_qmk`, on the `miryoku` branch.
2. Build with:
   `QMK_FIRMWARE="$HOME/miryoku_qmk" ./build.sh`
3. The build wrapper uses:
   `qmk compile -kb crkbd/rev1 -km miryoku -e CONVERT_TO=elite_pi`
4. Because copied files preserve timestamps and QMK may reuse stale objects, remove `$QMK_FIRMWARE/.build` before rebuilding after source changes.
5. Copy the resulting `$QMK_FIRMWARE/crkbd_rev1_miryoku_elite_pi.uf2` to the project root.
6. Verify the UF2 exists, is non-empty, run `git diff --check`, and report its SHA-256 checksum.
7. A successful compile does not verify hardware behavior; do not claim flashing or hardware testing occurred.

## Current behavior

- Normal layers retain the existing Miryoku configuration and home-row mods.
- The outer-right-bottom key toggles `U_GAME`.
- Gaming layer changes on the left half:
  - outer middle: Left Shift
  - outer bottom: Left Ctrl
  - outer thumb: Left Alt
  - middle thumb: Space
  - inner thumb: M
- The right half remains unchanged.
- The OLED shows the highest active layer and gaming status (`Game: ON/OFF`) on the master half only.

## Flashing

- Flash the same UF2 to both Elite-Pi halves, one half at a time, with the halves disconnected.
- Confirm the exact UF2 path and checksum before flashing.
- Do not change OLED wiring based on firmware symptoms; the established OLED wiring is known-good.
- Keep the original firmware backup at:
  `crkbd_rev1_miryoku_elite_pi_original_backup.uf2`
