// Corne V3 / RP2040 Miryoku layout
// The six breakaway-column keys are fixed on every layer.

#pragma once

#define XXX KC_NO
#define GAME_TOGGLE QK_USER
#define OLED_IC OLED_IC_SSD1306
#define OLED_TIMEOUT 0

#define LAYOUT_miryoku( \
      K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09, \
      K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19, \
      K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29, \
      N30,  N31,  K32,  K33,  K34,         K35,  K36,  K37,  N38,  N39 \
) \
LAYOUT_split_3x6_3( \
 KC_TAB, K00, K01, K02, K03, K04,             K05, K06, K07, K08, K09, KC_BSLS, \
 KC_ESC, K10, K11, K12, K13, K14,             K15, K16, K17, K18, K19, KC_QUOT, \
 KC_LSFT,K20, K21, K22, K23, K24,             K25, K26, K27, K28, K29, GAME_TOGGLE, \
                         K32, K33, K34, K35, K36, K37 \
)

#define LAYOUT_miryoku_game( \
      K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09, \
      K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19, \
      K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29, \
      N30,  N31,  K32,  K33,  K34,         K35,  K36,  K37,  N38,  N39 \
) \
LAYOUT_split_3x6_3( \
 KC_TAB, K00, K01, K02, K03, K04,             K05, K06, K07, K08, K09, KC_BSLS, \
 KC_LSFT,K10, K11, K12, K13, K14,             K15, K16, K17, K18, K19, KC_QUOT, \
 KC_LCTL,K20, K21, K22, K23, K24,             K25, K26, K27, K28, K29, GAME_TOGGLE, \
                         KC_LALT, LT(U_GAME_FN, KC_SPC), KC_M, K35, K36, K37 \
)

#define LAYOUT_miryoku_game_fn( \
      K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09, \
      K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19, \
      K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29, \
      N30,  N31,  K32,  K33,  K34,         K35,  K36,  K37,  N38,  N39 \
) \
LAYOUT_split_3x6_3( \
 KC_ESC, K00, K01, K02, K03, K04,             K05, K06, K07, K08, K09, KC_TRNS, \
 KC_LSFT,K10, K11, K12, K13, K14,             K15, K16, K17, K18, K19, KC_TRNS, \
 KC_LCTL,K20, K21, K22, K23, K24,             K25, K26, K27, K28, K29, KC_TRNS, \
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
)

#include "users/manna-harbour_miryoku/config.h"
