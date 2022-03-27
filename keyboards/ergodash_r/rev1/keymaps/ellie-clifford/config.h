/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


/* Use I2C or Serial, not both */

#define USE_SERIAL
//#define USE_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define ENCODERS_PAD_A { C6 }
#define ENCODERS_PAD_B { B6 }
#define ENCODER_RESOLUTIONS { 2 }
#define TAPPING_TOGGLE 2

// Optimisation
#define NO_ACTION_ONESHOT

// RGB
#define RGBLIGHT_DEFAULT_HUE 188
#define RGBLIGHT_DEFAULT_SAT 255
#define RGBLIGHT_DEFAULT_VAL 164
#define RGBLIGHT_LAYERS
#define SPLIT_LAYER_STATE_ENABLE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_GRADIENT

#define MK_3_SPEED
#define MK_C_OFFSET_0 10
#define MK_C_OFFSET_1 50
#define MK_C_OFFSET_2 100
