/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _COLMKDH,
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _ADJUST
};

enum planck_keycodes {
  COLMKDH = SAFE_RANGE,
  QWERTY
};

#define LOWER TT(_LOWER)
#define RAISE TT(_RAISE)
#define FUNCT TT(_FUNCTION)
#define KC_ESCT MT(MOD_LCTL, KC_ESC)
#define KC_ENCT MT(MOD_RCTL, KC_ENT) 
#define KC_ENRS MT(MOD_RSFT, KC_ENT) 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Workman */
[_COLMKDH] = LAYOUT_planck_grid(
     KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
    KC_ESCT,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_ENRS,
    KC_LCTL, KC_LGUI, KC_LALT,   FUNCT,   LOWER,  KC_SPC,  KC_SPC,   RAISE, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT
),

/* Qwerty */
[_QWERTY] = LAYOUT_planck_grid(
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    KC_ESCT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_ENRS,
    KC_LCTL, KC_LGUI, KC_LALT,   FUNCT,   LOWER,  KC_SPC,  KC_SPC,   RAISE, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT
),

/* Lower */
[_LOWER] = LAYOUT_planck_grid(
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    _______, KC_NLCK, _______, _______, _______, _______, KC_PAST,    KC_4,    KC_5,    KC_6, KC_PPLS, KC_PENT,
    _______, _______, _______, _______, _______, _______, KC_PSLS,    KC_1,    KC_2,    KC_3, KC_PMNS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_0,  KC_DOT, KC_PEQL, _______
),

/* Raise */
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL,
    _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______, _______,  KC_GRV, KC_MINS,  KC_EQL, KC_BSLS, _______,
    _______,   KC_LT,   KC_GT, KC_LCBR, KC_RCBR, _______, _______, KC_TILD, KC_UNDS, KC_PLUS, KC_PIPE, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Function */
[_FUNCTION] = LAYOUT_planck_grid(
    _______, KC_PGUP, KC_HOME,   KC_UP,  KC_END,  KC_INS, _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_MUTE,
    KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_VOLU,
    _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_NLCK, KC_NUBS, _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_VOLD, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT
),

/* Adjust (Lower + Raise) */
[_ADJUST] = LAYOUT_planck_grid(
      RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, COLMKDH,
    _______,  MU_MOD,   AU_ON,  AU_OFF, _______, _______, _______, _______, _______, _______, _______,  QWERTY,
    _______,  MUV_DE,  MUV_IN,   MU_ON,  MU_OFF,   MI_ON,  MI_OFF, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

uint16_t led_flash_timer = 0;

void matrix_scan_user(void) {
	if (get_highest_layer(layer_state) == _ADJUST) {
		uint16_t elapsed = timer_elapsed(led_flash_timer);
		if (elapsed < 512) {
			planck_ez_left_led_level(128 - (elapsed / 4));
			planck_ez_right_led_level(elapsed / 4);
		} else if (elapsed < 1024) {
			planck_ez_left_led_level((elapsed - 512) / 4);
			planck_ez_right_led_level(128 - ((elapsed - 512) / 4));
		} else {
			led_flash_timer = timer_read();
		}
	}
}

layer_state_t layer_state_set_user(layer_state_t state) {
	state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
	planck_ez_left_led_level(100);
	planck_ez_right_led_level(100);
	planck_ez_left_led_off();
	planck_ez_right_led_off();
	switch (get_highest_layer(state)) {
		case _LOWER:
			planck_ez_left_led_on();
			break;
		case _RAISE:
			planck_ez_right_led_on();
			break;
		case _FUNCTION:
			planck_ez_right_led_on();
			planck_ez_left_led_on();
			break;
		case _ADJUST:
			led_flash_timer = timer_read();
			break;
		default:
			break;
	}
	return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case COLMKDH:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_COLMKDH);
			}
			return false;
			break;
		case QWERTY:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_QWERTY);
			}
			return false;
			break;
	}
	return true;
}

void keyboard_post_init_user(void) {
	planck_ez_left_led_level(100);
	planck_ez_right_led_level(100);
	planck_ez_left_led_off();
	planck_ez_right_led_off();
	timer_init();
}
