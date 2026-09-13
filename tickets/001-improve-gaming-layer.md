# Improve Corne gaming layer

Status: Done

## Context

The current gaming layer is difficult to use with only the left half of the Corne. It needs a directly usable Tab key, an accessible Escape key, and number keys without disrupting movement controls.

## Desired behavior

Update only the gaming layer and add a momentary secondary gaming-function layer.

Gaming base layer, left half:

```text
TAB   Q W E R T
LSHFT A S D F G
LCTRL Z X C V B

LALT  SPACE  M
```

Secondary gaming-function layer, active while holding the left-middle thumb key:

```text
ESC   1 - 2 3 4
LSHFT - - - 5 6
LCTRL 7 8 9 0 F1

LALT  (held layer key)  M
```

Transparent positions must continue to resolve to the gaming base layer. The left-middle thumb key must remain `KC_SPC` when tapped and activate the secondary layer when held.

The right half must remain unchanged.

## Acceptance criteria

- `U_GAME` remains toggled by the existing outer-right-bottom key.
- The gaming base layer has `TAB` on the left outer-top key.
- The gaming base layer has plain `W`, `A`, `S`, and `D` keys.
- The gaming base layer keeps left `SHIFT`, left `CTRL`, `LALT`, `SPACE`, and `M` in their current gaming positions.
- The current gaming-only tap-hold and alternate-mod behaviors on the left alpha keys are removed.
- Holding the left-middle gaming thumb activates the secondary gaming-function layer.
- Tapping that thumb still sends `SPACE`.
- The secondary layer provides `ESC`, `1` through `0`, and `F1` at the positions specified above.
- `W`, `A`, `S`, `D`, `SHIFT`, and `CTRL` remain usable while the secondary layer is held.
- All normal Miryoku layers and home-row mods remain unchanged.
- The right half remains unchanged.
- OLED rendering remains unchanged: only the master OLED renders, layer status remains visible, and `Game: ON/OFF` remains correct.
- The exact target builds successfully with `CONVERT_TO=elite_pi`.
- The generated UF2 is non-empty and passes `git diff --check`.

## Non-goals

- Do not redesign normal Miryoku layers.
- Do not change the gaming toggle key.
- Do not change the OLED geometry, rotation, wiring assumptions, or display content.
- Do not change the right-half gaming layout.
- Do not flash firmware as part of this ticket.

## Implementation notes

- Add a new layer index after `U_GAME`, for example `U_GAME_FN`.
- Keep gaming-layer changes in the compiled keymap and user definitions copied by `build.sh`; verify the actual QMK checkout source before building.
- Use a transparent keycode for intentionally preserved gaming-base positions on the secondary layer.
- Clear the QMK build cache before rebuilding so stale copied sources cannot be reused.
