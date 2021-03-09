#include QMK_KEYBOARD_H

enum planck_layers {
    _COLMKDH = 0,
    _QWERTY,
    _LOWER,
    _RAISE,
    _MUSIC,
    _FUNCT,
    _ADJUST
};

enum custom_keys {
    COLMKDH = SAFE_RANGE,
    QWERTY,
    MUSIC,
    ADJUST,
    KILL,
    POINT
};

#define CK_ESLW LT(_LOWER,   KC_ESC)
#define LOWER   TT(_LOWER)
#define RAISE   TT(_RAISE)
#define FUNCT   TT(_FUNCT)

#define CK_QTRS LT(_RAISE,   KC_QUOT)
#define CK_ESLW LT(_LOWER,   KC_ESC)
#define CK_TBLS MT(MOD_LSFT, KC_TAB)
#define CK_DLRS MT(MOD_RSFT, KC_DEL)

const rgblight_segment_t PROGMEM rgb_raise[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 8, HSV_BLUE}
);

const rgblight_segment_t PROGMEM rgb_lower[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 8, HSV_RED}
);

const rgblight_segment_t PROGMEM rgb_adjust[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 8, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM rgb_funct[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 8, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_raise,
    rgb_lower,
    rgb_adjust,
    rgb_funct
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak Mod-DH */
[_COLMKDH] = LAYOUT_planck_1x2uL(
     KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, KC_CAPS,
    CK_ESLW,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,   RAISE,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SCLN, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI,   RAISE,       KC_SPC,     KC_BSPC,  KC_ENT,   LOWER, KC_RALT, KC_RCTL,   FUNCT
),

/* QWERTY */
[_QWERTY] = LAYOUT_planck_1x2uL(
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_QUOT,
    CK_ESLW,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,   RAISE,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI,   RAISE,       KC_SPC,     KC_BSPC,  KC_ENT,   LOWER, KC_RALT, KC_RCTL,   FUNCT
),

/* LOWER */
[_LOWER] = LAYOUT_planck_1x2uL(
    KC_TILD, KC_EXLM, KC_QUES, KC_ASTR, KC_SLSH, KC_CIRC, KC_PERC,    KC_7,    KC_8,    KC_9,  KC_GRV,  KC_DEL,
    _______, KC_LPRN, KC_RPRN, KC_PLUS, KC_MINS, KC_AMPR, KC_BSLS,    KC_4,    KC_5,    KC_6,   POINT, _______,
    _______,   KC_LT,   KC_GT,  KC_EQL, KC_AMPR, KC_PIPE,    KC_0,    KC_1,    KC_2,    KC_3,  KC_DOT, _______,
    _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______, _______
),

/* RAISE */
[_RAISE] = LAYOUT_planck_1x2uL(
    KC_TILD, KC_EXLM, KC_QUES, KC_ASTR, KC_SLSH, KC_CIRC, KC_PERC, KC_HASH,   KC_AT,  KC_DLR,  KC_INS,  KC_DEL,
    _______, KC_LPRN, KC_RPRN, KC_PLUS, KC_MINS, KC_AMPR, KC_BSLS, KC_LBRC, KC_RBRC, KC_HOME,  KC_END, _______,
    _______,   KC_LT,   KC_GT,  KC_EQL, KC_UNDS, KC_PIPE,  KC_GRV, KC_LCBR, KC_RCBR, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______,      _______,      _______, _______, _______, _______, _______, _______
),

/* Function */
[_FUNCT] = LAYOUT_planck_1x2uL(
      RESET, KC_WBAK,   KC_UP, KC_WFWD, KC_BRIU, KC_PSCR, KC_VOLU,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_SLEP, _______, KC_MUTE,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,
    _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_BRID,    KILL, KC_VOLD,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, 
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
    rgblight_layers = rgb_layers;
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
    case COLMKDH:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLMKDH);
      }
      return false;
      break;
    case KILL:
      if (!record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LALT) SS_TAP(X_F4) SS_UP(X_LALT) );
      }
      break;
    case POINT:
      if (!record->event.pressed) {
        SEND_STRING("->");
      }
      break;
  }
  return true;
}
