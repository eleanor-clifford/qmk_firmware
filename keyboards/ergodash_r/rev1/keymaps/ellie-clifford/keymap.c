#include QMK_KEYBOARD_H
#include "print.h"
#include "sendstring_uk.h"
#include "overrides.c"

#define _NORMAL  0
#define _US      1
#define _QWERTY  2
#define _NUM     3
#define _CTL     4
#define _ADJUST  5
#define _MOUSE   6

// hotfix annoying LSP error
#ifdef __clang__
#  undef PROGMEM
#  define PROGMEM
#endif

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_NORMAL] = LAYOUT(
		UK_GRV,  UK_EXLM, S(UK_3), UK_PERC, UK_AMPR, UK_LBRC, UK_EQL,                       UK_MINS, UK_RBRC, UK_AT,   UK_DLR,  UK_CIRC, UK_ASTR, _______, \
		KC_TAB,  UK_Q,    UK_W,    UK_F,    UK_P,    UK_G,    UK_BSLS,                      UK_SLSH, UK_J,    UK_L,    UK_U,    UK_Y,    UK_SCLN, KC_BSPC, \
		KC_ESC,  UK_A,    UK_R,    UK_S,    UK_T,    UK_D,    UK_LPRN,                      UK_RPRN, UK_H,    UK_N,    UK_E,    UK_I,    UK_O,    UK_QUOT, \
		KC_LSFT, UK_Z,    UK_X,    UK_C,    UK_V,    UK_B,    TT(_NUM),                    TT(_CTL), UK_K,    UK_M,    UK_COMM, UK_DOT,  UK_HASH, KC_RSFT, \
		KC_LCTL, KC_CAPS, MO(_CTL),KC_LALT,          KC_LGUI, KC_SPC,  _______,    _______, KC_ENT,  KC_LCTL,          TT(_CTL),DM_REC1, DM_RSTP, DM_PLY1  \
	),

	[_US] = LAYOUT(
		KC_GRV,  KC_EXLM, S(KC_3), KC_PERC, KC_AMPR, KC_LBRC, KC_EQL,                       KC_MINS, KC_RBRC, KC_AT,   KC_DLR,  KC_CIRC, KC_ASTR, _______, \
		_______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_BSLS,                      KC_SLSH, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______, \
		_______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_LPRN,                      KC_RPRN, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
		_______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,                      _______, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_HASH, _______, \
		_______, _______, _______, _______,          _______, _______, _______,    _______, _______, _______,          _______, _______, _______, _______  \
	),

	[_QWERTY] = LAYOUT(
		_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                      _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
		_______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,                      _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, \
		_______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,                      _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, \
		_______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,                      _______, KC_N,    KC_M,    _______, _______, _______, _______, \
		_______, _______, _______, _______,          _______, _______, _______,    _______, _______, _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
	),

	[_NUM] = LAYOUT(
		_______, _______, KC_F12,  KC_F11,  KC_F10,  _______, _______,                      _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, KC_F9,   KC_F8,   KC_F7,   _______, _______,                      _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, \
		_______, _______, KC_F6,   KC_F5,   KC_F4,   _______, _______,                      _______, _______, KC_4,    KC_5,    KC_6,    _______, _______, \
		_______, _______, KC_F3,   KC_F2,   KC_F1,   _______, _______,                      _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, \
		_______, _______, _______, _______,          _______, _______, _______,    _______, _______, _______,          KC_0,    _______, _______, _______  \
	),

	[_CTL] = LAYOUT(
	TO(_QWERTY), _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, KC_HOME, \
		_______, DM_REC1, DM_REC2, _______, KC_MPLY, _______, _______,                     _______, _______, KC_MPRV, KC_MPLY, _______, KC_MNXT, KC_PGUP, \
		_______, DM_PLY1, DM_PLY2, _______, _______, _______, _______,                     _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGDN, \
		_______, _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, KC_END,  \
		_______, _______, _______, _______,          _______, DM_RSTP, _______,   _______, _______, _______,          _______, _______, _______, _______  \
	),

	[_ADJUST] = LAYOUT(
		_______, _______, _______, _______, _______, _______, TG(_US),                 TG(_QWERTY), _______, _______, _______, _______, _______, _______, \
		_______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, _______,                     _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
		_______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC , _______,                     _______,TG(_MOUSE),_______,_______, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______,          _______, _______, _______,   _______, _______, _______,          _______, _______, _______, EEP_RST  \
	),

	[_MOUSE] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______,                     _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______,                     _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______,          _______, _______, _______,   _______, _______, _______,          _______, _______, _______, _______  \
	)
};

const rgblight_segment_t PROGMEM caps_rgb[] = {
    {4, 4, HSV_RED},
	RGBLIGHT_END_SEGMENTS
};
const rgblight_segment_t PROGMEM num_rgb[] = {
    {9, 3, HSV_GREEN},
	RGBLIGHT_END_SEGMENTS
};
const rgblight_segment_t PROGMEM ctl_rgb[] = {
    {12, 3, HSV_GREEN},
	RGBLIGHT_END_SEGMENTS
};
const rgblight_segment_t PROGMEM us_rgb[] = {
    {0, 4, HSV_BLUE},
	RGBLIGHT_END_SEGMENTS
};
const rgblight_segment_t PROGMEM qwerty_rgb[] = {
    {20, 4, HSV_BLUE},
	RGBLIGHT_END_SEGMENTS
};
const rgblight_segment_t PROGMEM mouse_rgb[] = {
    {9,  3, HSV_YELLOW},
    {12, 3, HSV_YELLOW},
	RGBLIGHT_END_SEGMENTS
};

const rgblight_segment_t* const PROGMEM rgb_layers[] = {
	[0]       = caps_rgb, // note 0 is _NORMAL
	[_US]     = us_rgb,
	[_QWERTY] = qwerty_rgb,
	[_NUM]    = num_rgb,
	[_CTL]    = ctl_rgb,
	[_MOUSE]  = mouse_rgb,
	NULL
};

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(_US,     layer_state_cmp(state, _US));
	rgblight_set_layer_state(_QWERTY, layer_state_cmp(state, _QWERTY));
	rgblight_set_layer_state(_MOUSE, layer_state_cmp(state, _MOUSE));
	rgblight_set_layer_state(_NUM,    layer_state_cmp(state, _NUM));
	rgblight_set_layer_state(_CTL,    layer_state_cmp(state, _CTL));
    return state;
}

bool led_update_user(led_t led_state) {
	rgblight_set_layer_state(0, led_state.caps_lock);
	return true;
}

void suppress_mods_tap_code(uint16_t keycode, uint8_t mod_mask) {
	uint8_t mods = get_mods();
	del_mods(mods & mod_mask);
	tap_code(keycode);
	set_mods(mods);
}

void unshift_tap_code(uint16_t keycode) {
	suppress_mods_tap_code(keycode, MOD_MASK_SHIFT);
}

bool delkey_registered = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	update_tri_layer(_NUM, _CTL, _ADJUST);
	uint8_t mod_state = get_mods();
	switch (keycode) {
		case KC_BSPC:
			if (record->event.pressed) {
				if (mod_state & MOD_MASK_SHIFT) {
					// Delete on shifted backspace
					del_mods(MOD_MASK_SHIFT);
					register_code(KC_DEL);
					delkey_registered = true;
					set_mods(mod_state);
					return false; // don't continue to process_record_kb
				}
			} else {
				if (delkey_registered) {
					unregister_code(KC_DEL);
					delkey_registered = false;
					return false;
				}
			}
			return true;
	}
	return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
	if ((layer_state & 1<<_CTL) == 1<<_CTL && index == 0) {
		clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
	} else if ((layer_state & 1<<_NUM) == 1<<_NUM && index == 1) {
		clockwise ? tap_code(KC_BRID) : tap_code(KC_BRIU);
	} else if (get_mods() & MOD_MASK_SHIFT) {
		if (index == 0) {
			// Left encoder
			clockwise ? unshift_tap_code(KC_UP) : unshift_tap_code(KC_DOWN);
		} else if (index == 1) {
			// Right encoder
			clockwise ? unshift_tap_code(KC_LEFT) : unshift_tap_code(KC_RGHT);
		}
	} else if ((layer_state & 1<<_MOUSE) == 1<<_MOUSE) {
		if (index == 0) {
			// Left encoder
			clockwise ? tap_code(KC_MS_U) : tap_code(KC_MS_D);
		} else if (index == 1) {
			// Right encoder
			clockwise ? tap_code(KC_MS_L) : tap_code(KC_MS_R);
		}
	} else {
		if (index == 0) {
			// Left encoder
			clockwise ? tap_code(KC_WH_U) : tap_code(KC_WH_D);
		} else if (index == 1) {
			// Right encoder
			clockwise ? tap_code(KC_WH_L) : tap_code(KC_WH_R);
		}
	}
	return false;
}

void keyboard_post_init_user(void) {
	key_overrides_extra_setup();

	rgblight_layers = rgb_layers;

	/*eeconfig_init();*/

	/*debug_enable=true;*/
	/*debug_keyboard=true;*/
	/*debug_matrix=true;*/
	/*debug_mouse=true;*/
}
