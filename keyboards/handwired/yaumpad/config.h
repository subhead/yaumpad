// Copyright 2023 subhead (@subhead)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


#define USB_POLLING_INTERVAL_MS 1

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U // Timeout window in ms in which the double tap can occur.
#define SERIAL_USART_FULL_DUPLEX


// OLED
#define HAL_USE_I2C TRUE
#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP12
#define I2C1_SCL_PIN GP13

#define OLED_DISPLAY_128X64
#define OLED_UPDATE_INTERVAL 50



/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT


#ifdef CONSOLE_ENABLE
    #define CONSOLE_ENABLED
    #define DEBUG_ENABLE
#endif


// IDLE timeouts configuration
#ifdef IDLE_TIMEOUT_ENABLE
    // default timeout minutes
    #define TIMEOUT_THRESHOLD_DEFAULT 15
    // upper limits (2 hours and 10 minutes -- no rgb indicators above this value)
    #define TIMEOUT_THRESHOLD_MAX 140
#endif


#ifdef LEADER_ENABLE
    #define LEADER_PER_KEY_TIMING
    #define LEADER_TIMEOUT 800
#endif

// tapping toggle set to two taps
#define TAPPING_TOGGLE 3
// Tapping this number of times holds the key until tapped once again.
#define ONESHOT_TAP_TOGGLE 5
// Time (in ms) before the one shot key is released
#define ONESHOT_TIMEOUT 5000

// Emoticon Support
#define EMOTICON_ENABLE

#ifdef ENCODER_ENABLE
	#define ENCODERS_PAD_A { GP6 }
	#define ENCODERS_PAD_B { GP7 }
#endif