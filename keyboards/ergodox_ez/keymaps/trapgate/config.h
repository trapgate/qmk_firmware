#ifndef CONFIG_TRAPGATE_H
#define CONFIG_TRAPGATE_H

#include QMK_KEYBOARD_CONFIG_H

// from a comment in qmk's issue tracker:
// From my tests, the options mean the following
//
// PERMISSIVE_HOLD = Always the modified output
// IGNORE_MOD_TAP_INTERRUPT = Always the both keys, unless you hold both keys
//                            for at least TAPPING_TERM
// PERMISSIVE_HOLD + IGNORE_MOD_TAP_INTERRUPT = Modified output if the other key
//     is released before the tap key, or if both keys are held longer than
//     TAPPING_TERM. So both keys are output when releasing the tap key before
//     the other key and held lesss than TAPPING_TERM

#define PREVENT_STUCK_MODIFIERS
#define PERMISSIVE_HOLD
#undef TAPPING_TERM
#define TAPPING_TERM 200
// #undef IGNORE_MOD_TAP_INTERRUPT
// The default for debounce is 15, which can't be right. Trying much smaller value.
#undef DEBOUNCE
#define DEBOUNCE 4
// The default value for IS_COMMAND includes both shift keys, and that ends up
// getting tripped accidentally when holding right shift while hitting symbol
// keys, which include left shift.
#undef IS_COMMAND
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)) \
)

#endif
