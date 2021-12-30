#include QMK_KEYBOARD_H
#include "print.h"
#include "sendstring_uk.h"

#define _NORMAL  0
#define _QWERTY  1
#define _NUM     2
#define _CTL     3
#define _ADJUST  4
/*#define _US      1*/

extern keymap_config_t keymap_config;

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT( \
		KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                            KC_EQL , KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                            KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, \
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_DEL ,                            KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_BSLS,                            KC_ENT , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
		KC_LCTL, KC_LGUI,TO(_NORMAL),KC_LALT,        _______, KC_SPC , _______,          _______, KC_SPC , _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
	),

	/*[_US] = LAYOUT( \*/
		/*KC_GRV,  KC_EXLM, KC_TILD, KC_PERC, KC_AMPR, KC_LBRC, KC_EQL,                             KC_MINS, KC_RBRC, KC_AT,   KC_DLR,  KC_CIRC, KC_ASTR, KC_DEL,  \*/
		/*KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_BSLS,                            KC_SLSH, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \*/
		/*KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_LPRN,                            KC_RPRN, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \*/
		/*KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TT(_NUM),                          TT(_CTL), KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_HASH, KC_RSFT, \*/
		/*KC_LCTL, KC_CAPS, MO(_CTL),KC_LALT,          KC_LGUI, KC_SPC,  _______,          _______, KC_ENT,  KC_LCTL,          TT(_CTL),KC_DOWN, KC_UP,   KC_RGHT  \*/
	/*),*/

	/* Normal
	* +--------------------------------------------------------------------------------------------------------------------------------------------------------+
	* |     `  |   ! 1  |   £ 3  |   % 5  |   & 7  |   [ 9  |   = +  |                          |   - _  |   ] 0  |   @ 2  |   $ 4  |   ^ 6  |   * 8  |   Del  |
	* |--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------+--------+--------+--------+--------+--------|
	* |   Tab  |     Q  |     W  |     F  |     P  |     G  |   \ |  |                          |   / ?  |     J  |     L  |     U  |     Y  |     ;  |   Bksp |
	* |--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------+--------+--------+--------+--------+--------|
	* |   ESC  |     A  |     R  |     S  |     T  |     D  |   ( {  |                          |   ) }  |     H  |     N  |     E  |     I  |     O  |    '   |
	* |--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------+--------+--------+--------+--------+--------|
	* |   Shift|     Z  |     X  |     C  |     V  |     B  |   Lower|                          |   Raise|     #  |     K  |     M  |     ,  |     .  |   Shift|
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
	* |   Caps |        |        |    Alt ||||||||||    GUI |   Space|   rot  ||||||||||   rot  |   Enter|   Ctrl ||||||||||   Left |   Down |    Up  |   Right|
	* +--------------------------------------------------------------------------------------------------------------------------------------------------------+
	*/

	[_NORMAL] = LAYOUT(\
		UK_GRV,  UK_EXLM, S(UK_3), UK_PERC, UK_AMPR, UK_LBRC, UK_EQL,                             UK_MINS, UK_RBRC, UK_AT,   UK_DLR,  UK_CIRC, UK_ASTR, KC_DEL,  \
		KC_TAB,  UK_Q,    UK_W,    UK_F,    UK_P,    UK_G,    UK_BSLS,                            UK_SLSH, UK_J,    UK_L,    UK_U,    UK_Y,    UK_SCLN, KC_BSPC, \
		KC_ESC,  UK_A,    UK_R,    UK_S,    UK_T,    UK_D,    UK_LPRN,                            UK_RPRN, UK_H,    UK_N,    UK_E,    UK_I,    UK_O,    UK_QUOT, \
		KC_LSFT, UK_Z,    UK_X,    UK_C,    UK_V,    UK_B,    TT(_NUM),                          TT(_CTL), UK_K,    UK_M,    UK_COMM, UK_DOT,  UK_HASH, KC_RSFT, \
		KC_LCTL, KC_CAPS, MO(_CTL),KC_LALT,          KC_LGUI, KC_SPC,  _______,          _______, KC_ENT,  KC_LCTL,          TT(_CTL),DM_REC1, DM_RSTP, DM_PLY1  \
	),


	/* Num
	* +--------------------------------------------------------------------------------------------------------------------------------------------------------+
	* |        |        |        |        |        |        |        |                          |        |        |        |        |        |        |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------+--------+--------+--------+--------+--------|
	* |        |        |        |        |        |        |        |                          |        |        |    7   |    8   |    9   |        |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------+--------+--------+--------+--------+--------|
	* |        |        |        |        |        |        |        |                          |        |        |    4   |    5   |    6   |        |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------+--------+--------+--------+--------+--------|
	* |        |        |        |        |        |        |        |                          |        |        |    1   |    2   |    3   |        |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
	* |        |        |        |        ||||||||||        |        |        ||||||||||        |        |        ||||||||||        |        |        |        |
	* +--------------------------------------------------------------------------------------------------------------------------------------------------------+
	*/
	[_NUM] = LAYOUT(
		_______, _______, KC_F12,  KC_F11,  KC_F10,  _______, _______,                            _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, KC_F9,   KC_F8,   KC_F7,   _______, _______,                            _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, \
		_______, _______, KC_F6,   KC_F5,   KC_F4,   _______, _______,                            _______, _______, KC_4,    KC_5,    KC_6,    _______, _______, \
		_______, _______, KC_F3,   KC_F2,   KC_F1,   _______, _______,                            _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, \
		_______, _______, _______, _______,          _______, _______, _______,          _______, _______, _______,          KC_0,    _______, _______, _______  \
	),

	/* Control
	* +--------------------------------------------------------------------------------------------------------------------------------------------------------+
	* |        |        |        |        |        |        |        |                          |        |        |        |        |        |        |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------+--------+--------+--------+--------+--------|
	* |        |        |        |        |        |        |        |                          |        |        |        |        |        |        |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------+--------+--------+--------+--------+--------|
	* |        |        |        |        |        |        |        |                          |        |        |        |        |        |        |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------+--------+--------+--------+--------+--------|
	* |        |        |        |        |        |        |        |                          |        |        |        |        |        |        |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
	* |        |        |        |        ||||||||||        |        |        ||||||||||        |        |        ||||||||||        |        |        |        |
	* +--------------------------------------------------------------------------------------------------------------------------------------------------------+
	*/
	[_CTL] = LAYOUT(
	TO(_QWERTY), _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, KC_HOME, \
		_______, DM_REC1, DM_REC2, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, KC_PGUP, \
		_______, DM_PLY1, DM_PLY2, _______, _______, _______, _______,                           _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGDN, \
		_______, _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, KC_END,  \
		_______, _______, _______, _______,          _______, DM_RSTP, _______,         _______, _______, _______,          _______, _______, _______, _______  \
	),

	/* Adjust
	* ,----------------------------------------------------------------------------------------------------------------------.
	* |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
	* |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
	* |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
	* |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
	* |      |      | BL ON|  BRTG|   INC|   DEC|      |                    |      |      |      |      |      |      |      |
	* |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
	* |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
	* |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
	* ,----------------------------------------------------------------------------------------------------------------------.
	*/
	[_ADJUST] = LAYOUT(
		_______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
		_______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
		_______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
	)
};

key_override_t key_override_1 = ko_make_with_layers_negmods_and_options(MOD_MASK_CSAG, UK_EXLM, UK_1,    1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t key_override_3 = ko_make_with_layers_negmods_and_options(MOD_MASK_CSAG, S(UK_3), UK_3,    1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t key_override_5 = ko_make_with_layers_negmods_and_options(MOD_MASK_CSAG, UK_PERC, UK_5,    1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t key_override_7 = ko_make_with_layers_negmods_and_options(MOD_MASK_CSAG, UK_AMPR, UK_7,    1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t key_override_9 = ko_make_with_layers_negmods_and_options(MOD_MASK_CSAG, UK_LBRC, UK_9,    1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t key_override_L = ko_make_with_layers_negmods_and_options(MOD_MASK_SHIFT,UK_LPRN, UK_LBRC, 1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t key_override_R = ko_make_with_layers_negmods_and_options(MOD_MASK_SHIFT,UK_RPRN, UK_RBRC, 1<<_NORMAL, 0, ko_options_default | ko_option_one_mod); // results in curly since shift is pressed
key_override_t key_override_0 = ko_make_with_layers_negmods_and_options(MOD_MASK_CSAG, UK_RBRC, UK_0,    1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t key_override_2 = ko_make_with_layers_negmods_and_options(MOD_MASK_CSAG, UK_AT,   UK_2,    1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t key_override_4 = ko_make_with_layers_negmods_and_options(MOD_MASK_CSAG, UK_DLR,  UK_4,    1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t key_override_6 = ko_make_with_layers_negmods_and_options(MOD_MASK_CSAG, UK_CIRC, UK_6,    1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t key_override_8 = ko_make_with_layers_negmods_and_options(MOD_MASK_CSAG, UK_ASTR, UK_8,    1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t key_override_Q = ko_make_with_layers_negmods_and_options(MOD_MASK_SHIFT,UK_QUOT, UK_2,    1<<_NORMAL, 0, ko_options_default | ko_option_one_mod); // results in @ since shift is pressed

const key_override_t **key_overrides = (const key_override_t *[]){
	&key_override_1,
	&key_override_3,
	&key_override_5,
	&key_override_7,
	&key_override_9,
	&key_override_L,
	&key_override_R,
	&key_override_0,
	&key_override_2,
	&key_override_4,
	&key_override_6,
	&key_override_8,
	&key_override_Q,
	NULL
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(NORMAL_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
	eeconfig_update_default_layer(default_layer);
	default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

	return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
	if (index == 0) { /* First encoder */
		if (clockwise) {
			tap_code(KC_MS_WH_UP);
		} else {
			tap_code(KC_MS_WH_DOWN);
		}
	} else if (index == 1) { /* Second encoder */
		if (clockwise) {
			tap_code(KC_DOWN);
		} else {
			tap_code(KC_UP);
		}
	}
	return false;
}

void keyboard_post_init_user(void) {
	// Customise these values to desired behaviour
	key_override_1.suppressed_mods = MOD_MASK_SHIFT;
	key_override_3.suppressed_mods = MOD_MASK_SHIFT;
	key_override_5.suppressed_mods = MOD_MASK_SHIFT;
	key_override_7.suppressed_mods = MOD_MASK_SHIFT;
	key_override_9.suppressed_mods = MOD_MASK_SHIFT;
	key_override_L.suppressed_mods = 0;
	key_override_R.suppressed_mods = 0;
	key_override_0.suppressed_mods = MOD_MASK_SHIFT;
	key_override_2.suppressed_mods = MOD_MASK_SHIFT;
	key_override_4.suppressed_mods = MOD_MASK_SHIFT;
	key_override_6.suppressed_mods = MOD_MASK_SHIFT;
	key_override_8.suppressed_mods = MOD_MASK_SHIFT;
	key_override_Q.suppressed_mods = 0;

	/*eeconfig_init();*/

	/*debug_enable=true;*/
	/*debug_keyboard=true;*/
	/*debug_matrix=true;*/
	/*debug_mouse=true;*/

	/*for (uint8_t i = 0; i < 24; ++i)*/
		/*sethsv(188, 255, 164, (LED_TYPE *)&led[i]);*/
	/*rgblight_set();*/
}
