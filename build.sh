#!/usr/bin/env bash
set -euo pipefail

# Run this from a QMK firmware checkout, or set QMK_FIRMWARE explicitly.
ROOT="$(cd "$(dirname "$0")" && pwd)"
QMK_FIRMWARE="${QMK_FIRMWARE:-${HOME}/qmk_firmware}"
KEYMAP_DEST="${QMK_FIRMWARE}/keyboards/crkbd/rev1/keymaps/miryoku"

if [[ ! -d "${QMK_FIRMWARE}/keyboards/crkbd" ]]; then
  echo "QMK firmware checkout not found: ${QMK_FIRMWARE}" >&2
  exit 1
fi

mkdir -p "${KEYMAP_DEST}"
cp -r "${ROOT}/keyboards/crkbd/rev1/keymaps/miryoku/." "${KEYMAP_DEST}/"
mkdir -p "${QMK_FIRMWARE}/users"
rm -rf "${QMK_FIRMWARE}/users/manna-harbour_miryoku"
cp -r "${ROOT}/users/manna-harbour_miryoku" "${QMK_FIRMWARE}/users/"

cd "${QMK_FIRMWARE}"
qmk compile -kb crkbd/rev1 -km miryoku -e CONVERT_TO=elite_pi
