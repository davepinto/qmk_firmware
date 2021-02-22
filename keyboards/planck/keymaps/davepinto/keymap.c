#include QMK_KEYBOARD_H

enum planck_layers {
    _COLMKDH = 0,
    _QWERTY,
    _MUSIC,
    _LOWER,
    _RAISE,
    _FUNCT,
    _ADJUST
};

enum custom_keys {
    COLMKDH = SAFE_RANGE,
    QWERTY,
    MUSIC,
    FUNCT,
    ADJUST,
    LEFTSPC,
    RGHTSPC,
    AUDMUTE
};

#define CK_ENCT MT(MOD_RCTL, KC_ENT)
#define CK_ESCT MT(MOD_LCTL, KC_ESC)
#define CK_FNCT LT(_FUNCT,   KC_DEL)
#define CK_ESRS LT(_RAISE,   KC_ESC)
#define CK_ENRS LT(_RAISE,   KC_ENT)

#define CK_QTRS LT(_RAISE,   KC_QUOT)
#define CK_ESLW LT(_LOWER,   KC_ESC)
#define CK_TBLS MT(MOD_LSFT, KC_TAB)
#define CK_DLRS MT(MOD_RSFT, KC_DEL)

const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 8, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 8, HSV_RED}
);

const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 8, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM my_funct_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 8, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_raise_layer,
    my_lower_layer,
    my_adjust_layer,
    my_funct_layer
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak Mod-DH */
[_COLMKDH] = LAYOUT_planck_1x2uL(
     KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_QUOT,
    CK_ESRS,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, TT(_RAISE),
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI, TT(_LOWER),   KC_SPC,  KC_BSPC,  KC_ENT,     KC_RCTL, KC_RALT, KC_RGUI,   FUNCT
),

/* QWERTY */
[_QWERTY] = LAYOUT_planck_1x2uL(
    KC_LBRC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_RBRC,
    CK_ESLW,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, CK_QTRS,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL,   FUNCT, KC_LALT, KC_LGUI,        KC_SPC,    KC_BSPC,  KC_ENT, KC_RGUI, KC_RALT,   FUNCT, KC_RCTL
),

/* LOWER */
[_LOWER] = LAYOUT_planck_1x2uL(
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    _______, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, _______, _______,    KC_4,    KC_5,    KC_6, KC_COMM, _______,
    _______, KC_LPRN, KC_RPRN, KC_CIRC, KC_PERC, _______,    KC_0,    KC_1,    KC_2,    KC_3,  KC_DOT, _______,
    _______, _______, _______, _______,      _______,     _______, _______, _______, _______,  _______, _______
),

/* RAISE */
[_RAISE] = LAYOUT_planck_1x2uL(
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS,  KC_EQL, _______,
    _______, KC_LPRN, KC_RPRN, KC_UNDS, KC_MINS,  KC_GRV, _______, KC_LBRC, KC_RBRC, _______, KC_BSLS, _______,
    _______,   KC_LT,   KC_GT,  KC_EQL, KC_PLUS, _______, _______, KC_LCBR, KC_RCBR, _______, KC_PIPE, _______,
    _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______, _______
),

/* Function */
[_FUNCT] = LAYOUT_planck_1x2uL(
      RESET, _______,   KC_UP, _______, _______, _______, _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,
    _______, _______, _______, _______, _______, _______, _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, 
    _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______, _______
),

/* Adjust */
[_ADJUST] = LAYOUT_planck_1x2uL(
      RESET, _______, _______, _______, _______, _______, RGB_M_X, RGB_M_SW, RGB_M_P, RGB_HUI,   MUSIC, COLMKDH,
    _______, _______, _______, _______, _______, _______, RGB_M_G, RGB_M_SN, RGB_M_B, RGB_SAI, RGB_MOD,  QWERTY,
    _______, _______, _______, _______, _______, _______, _______,  RGB_M_K, RGB_M_R, RGB_VAI, RGB_TOG, _______,
    _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______, _______
)

};

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    rgblight_mode(1);
    rgblight_enable();
}

#ifdef AUDIO_ENABLE
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  rgblight_set_layer_state(0, layer_state_cmp(state, _RAISE));
  rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
  rgblight_set_layer_state(2, layer_state_cmp(state, _ADJUST));
  rgblight_set_layer_state(3, layer_state_cmp(state, _FUNCT));
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FUNCT:
      if (record->event.pressed) {
        layer_on(_FUNCT);
      } else {
        layer_off(_FUNCT);
      }
      return false;
      break;
    case COLMKDH:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLMKDH);
      }
      return false;
      break;
  }
  return true;
}
