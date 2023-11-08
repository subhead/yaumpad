// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "subhead.h"
#include "strings.c"
#include "private.c"

#ifdef CONSOLE_ENABLE
    /*
    print("string"): Print a simple string.
    uprintf("%s string", var): Print a formatted string
    dprint("string") Print a simple string, but only when debug mode is enabled
    dprintf("%s string", var): Print a formatted string, but only when debug mode is enabled
    */
    #include "print.h"
#endif

#define ARRAYSIZE(arr) sizeof(arr) / sizeof(arr[0])

#ifdef OLED_ENABLE
    static int oled_offset_layer = 0;
#endif


// define layers
enum custom_user_layers {
    _BASE,
    _FN1,
    _FN2,
    _FN3
};

enum custom_keycodes {
    __PLACEHOLDER__ = SAFE_RANGE,
    KC_CF_MOD,
    KC_LAYER_RESET,
    KC_TEST,
    KC_MOD_TEST,
    KC_MOD_BTN1,
    KC_MOD_BTN2,
    KC_MOD_BTN3,
    KC_MOD_BTN4,
    KC_MOD_BTN5,
    KC_MOD_BTN6,
    KC_MOD_BTN7,
    KC_MOD_BTN8,
    KC_MOD_BTN9,
    KC_MOD_BTN10,
    KC_MOD_BTN11,
    KC_MOD_BTN12,
    KC_MOD_BTN13,
    KC_MOD_BTN14,
    KC_MOD_BTN15,
    KC_MOD_BTN16,
    KC_MOD_BTN17,
    KC_MOD_BTN18,
    KC_MOD_BTN19,
    KC_MOD_BTN20,
    KC_MOD_BTN21,
    KC_MOD_BTN22,
    KC_MOD_BTN23,
    KC_MOD_BTN24,
    KC_MOD_BTN25,
    KC_MOD_BTN26,
    KC_MOD_BTN27,
    KC_MOD_BTN28,
    KC_MOD_BTN29,
    KC_MOD_BTN30,
    KC_MOD_BTN31,
    KC_MOD_BTN32,
    KC_MOD_BTN33,
    KC_MOD_BTN34,
    FOO
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │   │   │   │   │
     * ├───┼───┼───┼───┤
     * │   │   │   │   │
     * ├───┼───┼───┼───┤
     * │   │   │   │   │
     * ├───┼───┼───┼───┤
     * │   │   │   │   │
     * └───┴───┴───┴───┘
     */
    [_BASE] = LAYOUT_4x4(        
        KC_PENT,   KC_PAST,   KC_PSLS,   TO(0),
        KC_PMNS,   KC_7,      KC_8,      KC_9,
        KC_PPLS,   KC_4,      KC_5,      KC_6,
        KC_0,      KC_1,      KC_2,      KC_3
        ),
    [_FN1] = LAYOUT_4x4(
        KC_MOD_BTN1,   KC_MOD_BTN2,   KC_MOD_BTN3,   TO(0),
        KC_MOD_BTN4,   KC_MOD_BTN5,   KC_MOD_BTN6,   KC_MOD_BTN7,
        KC_MOD_BTN8,   KC_MOD_BTN9,   KC_MOD_BTN10,  KC_MOD_BTN11,
        KC_MOD_BTN2,   KC_MOD_BTN13,        KC_MOD_BTN14,  KC_MOD_BTN15
    ),
    [_FN2] = LAYOUT_4x4(
        _______,   _______,   _______,   TO(0),
        _______,   _______,   _______,   _______,
        KC_TEST,   _______,   _______,   _______,
        _______,   _______,   _______,   _______
    ),
    [_FN3] = LAYOUT_4x4(
        KC_LALT,   _______,   KC_LSFT,   TO(0),
        KC_LCTL,   _______,   KC_UP,   KC_RCTL,
        _______,   KC_LEFT,   _______,   KC_RIGHT,
        KC_TEST,   _______,   KC_DOWN,   _______
    )
};

#ifdef ENCODER_MAP_ENABLE
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
        [_BASE] = { ENCODER_CCW_CW(TO(_FN3), TO(_FN1)) },
        [_FN1] = { ENCODER_CCW_CW(TO(_BASE), TO(_FN2)) },
        [_FN2] = { ENCODER_CCW_CW(TO(_FN1), TO(_FN3)) },
        [_FN3] = { ENCODER_CCW_CW(TO(_FN2), TO(_BASE)) }
    };
#endif

void keyboard_post_init_user(void) {
    #ifdef DEBUG_ENABLE
        // Customise these values to desired behaviour
        debug_enable=true;
        //debug_matrix=true;
        debug_keyboard=true;
        //debug_mouse=true;
    #endif

    #ifdef OLED_ENABLE
        oled_clear();
    #endif
}


void matrix_init_user(void) {
}


void matrix_scan_user(void) {
}

#ifdef OLED_ENABLE
bool oled_task_user() {

    oled_write_P(PSTR("\n"), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE :
            oled_offset_layer = (oled_max_chars() - strlen("* BASE *")) / 2;
            uprintf(" %i layer,", oled_offset_layer);
            oled_set_cursor(oled_offset_layer, 0);
            oled_write_P(PSTR("* BASE *\n"), false);
            oled_write_P(PSTR("ENT  AST  SLHS  RST\n\n"), false);
            oled_write_P(PSTR("MIN   7    8    9\n\n"), false);
            oled_write_P(PSTR("PLS   4    5    6\n\n"), false);
            oled_write_P(PSTR(" 0    1    2    3\n"), false);
            break;

        case _FN1:
            oled_offset_layer = (oled_max_chars() - strlen("* FN1 *")) / 2;
            oled_set_cursor(oled_offset_layer, 0);
            oled_write_P(PSTR("* FN1 *\n"), false);
            oled_write_P(PSTR("___  ___  ___  RST\n\n"), false);
            oled_write_P(PSTR("___  ___  ___  ___\n\n"), false);
            oled_write_P(PSTR("___  ___  ___  ___\n\n"), false);
            oled_write_P(PSTR("___  F24  BFS  SPD\n"), false);
            break;

        case _FN2:
            oled_offset_layer = (oled_max_chars() - strlen("* FN2 *")) / 2;
            oled_set_cursor(oled_offset_layer, 0);
            oled_write_P(PSTR("* FN2 *\n"), false);
            oled_write_P(PSTR("___  ___  ___  RST\n\n"), false);
            oled_write_P(PSTR("___  ___  ___  ___\n\n"), false);
            oled_write_P(PSTR("TST  ___  ___  ___\n\n"), false);
            oled_write_P(PSTR("___  ___  ___  ___\n"), false);

        case _FN3:
            oled_offset_layer = (oled_max_chars() - strlen("* FN3 *")) / 2;
            oled_set_cursor(oled_offset_layer, 0);
            oled_write_P(PSTR("* FN3 *\n"), false);
            oled_write_P(PSTR("ALT  ___  SFT  RST\n\n"), false);
            oled_write_P(PSTR("LCT  ___   UP  RCT\n\n"), false);
            oled_write_P(PSTR("___  LFT  ___  RHT\n\n"), false);
            oled_write_P(PSTR("TST  ___  DWN  ___\n"), false);
            break;
    }
    return false;
}
#endif



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // debug output
    #ifdef CONSOLE_ENABLED
        uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %u, time: %u, interrupt: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    #endif

    switch (keycode) {
        // sending modifier keys + switch parameter
        // with that we can use a single Fkey and map 
        // additional features behind it
        case KC_CF_MOD:
            if(record->event.pressed) {
                register_code16(KC_F19);
                print("F19 pressed");
            } else {
                unregister_code16(KC_F19);
            }
            return false;
            break;

        case KC_MOD_BTN1:
            if(record->event.pressed) {
                tap_code16(KC_HYPR);
                SEND_STRING("a.");
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        case KC_MOD_BTN2:
            if(record->event.pressed) {
                register_code16(KC_HYPR);
                SEND_STRING("1 2.");
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        case KC_MOD_BTN3:
            if(record->event.pressed) {
                register_code16(KC_HYPR);
                SEND_STRING("1 3.");
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        case KC_MOD_BTN4:
            if(record->event.pressed) {
                register_code16(KC_HYPR);
                SEND_STRING("1 4.");
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        case KC_MOD_BTN5:
            if(record->event.pressed) {
                register_code16(KC_HYPR);
                SEND_STRING("1 5.");
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        case KC_MOD_BTN6:
            if(record->event.pressed) {
                register_code16(KC_HYPR);
                SEND_STRING("1 6.");
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        case KC_MOD_BTN7:
            if(record->event.pressed) {
                register_code16(KC_HYPR);
                SEND_STRING("1 7.");
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        case KC_MOD_BTN8:
            if(record->event.pressed) {
                register_code16(KC_HYPR);
                SEND_STRING("1 8.");
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        case KC_MOD_BTN9:
            if(record->event.pressed) {
                register_code16(KC_HYPR);
                SEND_STRING("1 9.");
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        
        case KC_MOD_BTN10:
            if(record->event.pressed) {
                register_code16(KC_HYPR);
                SEND_STRING("1 10.");
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        case KC_MOD_BTN11:
            if(record->event.pressed) {
                register_code16(KC_HYPR);
                SEND_STRING("1 11.");
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        case KC_MOD_BTN12:
            if(record->event.pressed) {
                register_code16(KC_HYPR);
                SEND_STRING("1 12.");
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        case KC_MOD_BTN13:
            if(record->event.pressed) {
                tap_code16(KC_F24);
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        case KC_MOD_BTN14:
            if(record->event.pressed) {
                tap_code16(KC_F23);
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        // suspend macro for ahk
        case KC_MOD_BTN15:
            if(record->event.pressed) {
                tap_code16(KC_HYPR);
                SEND_STRING("suspend.");
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        case KC_MOD_BTN16:
            if(record->event.pressed) {
                register_code16(KC_HYPR);
                SEND_STRING("1 16.");
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        case KC_MOD_BTN17:
            if(record->event.pressed) {
                register_code16(KC_HYPR);
                SEND_STRING("1 17.");
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;

        case KC_MOD_BTN18:
            if(record->event.pressed) {
                register_code16(KC_F19);
                SEND_STRING("1 18.");
            } else {
                unregister_code16(keycode);
            }
            return false;
            break;



        // resetting the selected layer to the base layer
        case KC_LAYER_RESET:
            if (record->event.pressed) register_code16(TO(_BASE));
            else unregister_code16(keycode);
            return false;

        case KC_TEST:
            if (record->event.pressed) {
                print("KCTEST");
            } else {
                unregister_code16(keycode);
            }
            return false;

        case QK_BOOTLOADER:  // when activating RESET mode for flashing
        if (record->event.pressed) {
            print("BOOT");
        }
        return false;

        // Process all other keycodes normally
        default:
            return true;
    }
}

// encoder updates
bool encoder_update_user(uint8_t index, bool clockwise) {
    
    //uint8_t mods_state = get_mods();
    
    if (clockwise) {
        tap_code(KC_PGDN);
    } else {
        tap_code(KC_PGUP);
    }

    return false;
}