#include QMK_KEYBOARD_H
#include "keymap_steno.h"

enum planck_layers {
    _COLMKDH = 0,
    _QWERTY,
    _MUSIC,
    _LOWER,
    _RAISE,
    _PLOVER,
    _FUNCT,
    _ADJUST
};

enum custom_keys {
    COLMKDH = SAFE_RANGE,
    QWERTY,
    PLOVER,
    MUSIC,
    FUNCT,
    ADJUST,
    LEFTSPC,
    RGHTSPC,
    EXITPLV,
    AUDMUTE
};

#define CK_ESCT MT(MOD_LCTL, KC_ESC)
#define CK_LSFT	MT(MOD_LSFT, KC_TAB)
#define CK_RSFT	MT(MOD_RSFT, KC_BSPC)
#define CK_LALT	MT(MOD_LALT, KC_LBRC)
#define CK_RALT	MT(MOD_RALT, KC_RBRC)
#define CK_LGUI	MT(MOD_LGUI, KC_TAB)
#define CK_RGUI	MT(MOD_RGUI, KC_BSPC)

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
[_COLMKDH] = LAYOUT_planck_2x2u(
     KC_GRV,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,     KC_Y, KC_SCLN, KC_BSLS,
    CK_ESCT,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,     KC_I,    KC_O, KC_QUOT,
    KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H, KC_COMM,   KC_DOT, KC_SLSH, KC_RSPC,
      FUNCT, KC_LCTL, KC_LALT, CK_LGUI, LT(_LOWER, KC_SPC), LT(_RAISE, KC_ENT), KC_BSPC, KC_DEL, KC_RCTL, KC_RGUI
),

/* QWERTY */
[_QWERTY] = LAYOUT_planck_2x2u(
    CK_LSFT,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P, CK_RSFT,
    CK_ESCT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L, KC_SCLN, KC_QUOT,
    CK_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,   KC_DOT, KC_SLSH, CK_RSFT,
      FUNCT, KC_LCTL, KC_LALT, KC_LGUI, LT(_LOWER, KC_SPC), LT(_RAISE, KC_ENT), KC_RGUI, KC_RALT, KC_RCTL, FUNCT
),

/* LOWER */
[_LOWER] = LAYOUT_planck_2x2u(
    _______, KC_LPRN, KC_RPRN, KC_AMPR, KC_CIRC,    LSFT(KC_C), LSFT(KC_D),    KC_7,    KC_8,    KC_9, KC_ASTR, KC_BSPC,
    _______, KC_LBRC, KC_RBRC, KC_PIPE, KC_PERC,    LSFT(KC_B), LSFT(KC_E),    KC_4,    KC_5,    KC_6, KC_PLUS,  KC_ENT, 
    _______,   KC_LT,   KC_GT, KC_EXLM,    KC_X,    LSFT(KC_A), LSFT(KC_F),    KC_1,    KC_2,    KC_3, KC_MINS,  KC_EQL,
    _______, _______, _______, _______,           _______,         LT(_RAISE, KC_0),  KC_DOT, KC_COMM, KC_SLSH, KC_PERC
),

/* RAISE */
[_RAISE] = LAYOUT_planck_2x2u(
    _______, KC_LCBR, KC_RCBR,   KC_AT, KC_EXLM, KC_CIRC, _______, _______, KC_LCBR, KC_RCBR, _______, _______,
    _______, KC_LBRC, KC_RBRC, KC_AMPR, KC_UNDS, KC_PERC, _______, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, _______,
    _______, KC_MINS, KC_PLUS,  KC_DLR, KC_HASH,  KC_EQL, _______, _______,   KC_LT,   KC_GT, _______, _______,
    _______, _______, _______, _______,      _______,         _______,      _______, _______, _______, _______
),

/* PLOVER */
[_PLOVER] = LAYOUT_planck_2x2u(
  STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
  STN_S1,  STN_TL,  STN_PL,  STN_HL, STN_ST1,  STN_FN, STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  STN_S2,  STN_KL,  STN_WL,  STN_RL, STN_ST2, STN_PWR, STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
 EXITPLV, XXXXXXX,   STN_A,   STN_O,      XXXXXXX,           XXXXXXX,      STN_E,   STN_U, STN_RE1, STN_RE2
),

/* Function */
[_FUNCT] = LAYOUT_planck_2x2u(
      RESET, KC_PSCR,   KC_UP, KC_SLCK, KC_VOLU, KC_PAUS,  KC_INS,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MUTE, KC_HOME,  KC_END,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_PGUP, KC_PGDN,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, 
    _______, _______, _______, _______,      _______,         _______,      _______, _______, _______, _______
),

/* Adjust */
[_ADJUST] = LAYOUT_planck_2x2u(
      RESET, _______, _______, _______, _______, _______, RGB_HUI, RGB_VAI, RGB_M_P, RGB_M_R,   MUSIC, COLMKDH,
    _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_VAD, RGB_M_B,RGB_M_SW, AUDMUTE,  QWERTY,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_M_K, RGB_TOG,  PLOVER,
    _______, _______, _______, _______,      _______,        _______,      _______,  _______, _______, _______
)

};

void matrix_init_user() {
	steno_set_mode(STENO_MODE_GEMINI);
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
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
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXITPLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}
