#include QMK_KEYBOARD_H

enum planck_layers {
    _COLMKDH = 0,
    _LOWER,
    _RAISE,
    _FUNCT,
    _ADJUST
};

enum custom_keys {
    LEFTSPC = SAFE_RANGE,
    RGHTSPC
};

#define LOWER 	TT(_LOWER)
#define RAISE 	TT(_RAISE)
#define FUNCT 	TT(_FUNCT)
#define KC_ESCT MT(MOD_LCTL, KC_ESC)
#define KC_ENCT MT(MOD_RCTL, KC_ENT) 
#define KC_ENRS MT(MOD_RSFT, KC_ENT) 
#define LSPC	LT(_LOWER, KC_SPC)
#define RSPC	LT(_RAISE, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak Mod-DH */
[_COLMKDH] = LAYOUT_planck_grid(
     KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_QUOT,
    KC_ESCT,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_ENCT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
      FUNCT, KC_LCTL, KC_LALT, KC_LGUI,    LSPC,    LSPC,    RSPC,    RSPC, KC_RGUI, KC_RALT, KC_RCTL, _______
),

/* LOWER */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_LBRC, KC_RBRC, KC_AMPR,  KC_DLR,    LSFT(KC_C), LSFT(KC_D),    KC_7,    KC_8,    KC_9, KC_PLUS, KC_ASTR,
     KC_SPC, KC_LPRN, KC_RPRN, KC_PIPE, KC_CIRC,    LSFT(KC_B), LSFT(KC_E),    KC_4,    KC_5,    KC_6,  KC_EQL,  KC_ENT, 
    _______,   KC_LT,   KC_GT, KC_EXLM, LSFT(KC_X), LSFT(KC_A), LSFT(KC_F),    KC_1,    KC_2,    KC_3, KC_MINS, KC_SLSH,
    _______, _______, _______, _______, _______,    _______,          KC_0,    KC_0,  KC_DOT, KC_PERC, KC_BSLS, KC_TILD
),

/* RAISE */
[_RAISE] = LAYOUT_planck_grid(
    KC_TILD, KC_ASTR, KC_AMPR, KC_CIRC, KC_PERC,  KC_GRV, _______, KC_PIPE, KC_LCBR, KC_RCBR, KC_SCLN, _______,
    KC_BSPC,  KC_DLR, KC_HASH,   KC_AT, KC_EXLM, KC_UNDS, _______, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, _______, 
    _______, KC_BSLS, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, _______, KC_BSLS,   KC_LT,   KC_GT, KC_SLSH, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/* Function */
[_FUNCT] = LAYOUT_planck_grid(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
    KC_CAPS, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_MUTE, KC_VOLD, KC_VOLD, _______, _______, _______, _______, _______,   KC_UP, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______
),

/* Adjust (Lower + Raise) */
[_ADJUST] = LAYOUT_planck_grid(
      RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DF(_COLMKDH),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool     interrupt   = false;
    static bool     ltapped     = false;
    static bool     rtapped     = false;
    static uint16_t ltime       = 0;
    static uint16_t rtime       = 0;

    switch(keycode) {
        case LEFTSPC:
            if (record->event.pressed) {
                layer_on(_LOWER);
                if (ltapped && !interrupt
                            && record->event.time - ltime < TAPPING_TERM) {
                        register_code(KC_SPC);
                }
            } else {
                layer_off(_LOWER);
                if (record->event.time - ltime < TAPPING_TERM && !interrupt) {
                    tap_code(KC_SPC);
                    ltapped = true;
                } else if (ltapped) {
                    unregister_code(KC_SPC);
                    ltapped = false;
                }
            }
            ltime = record->event.time;
            return false;
            break;
        case RGHTSPC:
            if (record->event.pressed) {
                layer_on(_RAISE);
                if (rtapped && !interrupt
                            && record->event.time - rtime < TAPPING_TERM) {
                        register_code(KC_BSPC);
                }
            } else {
                layer_off(_RAISE);
                if (record->event.time - rtime < TAPPING_TERM && !interrupt) {
                    tap_code(KC_BSPC);
                    rtapped = true;
                } else if (rtapped) {
                    unregister_code(KC_BSPC);
                    rtapped = false;
                }
            }
            rtime = record->event.time;
            return false;
            break;
	case LSFT:
	case RSFT:
        default:
            interrupt = true;
            break;
    }
    return true;
}
