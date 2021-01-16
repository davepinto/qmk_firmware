#include QMK_KEYBOARD_H
#include "keymap_steno.h"

enum planck_layers {
    _COLMKDH = 0,
    _LOWER,
    _RAISE,
    _FUNCT,
    _ADJUST,
    _PLOVER
};

enum custom_keys {
    COLMKDH = SAFE_RANGE,
    PLOVER,
    EXT_PLV,
    LEFTSPC,
    RGHTSPC,
    BACKLIT,
};

#define LOWER 	TT(_LOWER)
#define RAISE 	TT(_RAISE)
#define FUNCT 	TT(_FUNCT)
#define KC_ESCT MT(MOD_LCTL, KC_ESC)
#define LSPC	LT(_LOWER, KC_SPC)
#define RSPC	LT(_RAISE, KC_ENT)
#define CK_LSFT	OSM(MOD_LSFT)
#define CK_RSFT	OSM(MOD_RSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak Mod-DH */
[_COLMKDH] = LAYOUT_planck_grid(
     KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
    KC_ESCT,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
    CK_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, CK_RSFT,
      FUNCT, KC_LCTL, KC_LALT, KC_LGUI,    LSPC,  KC_ENT,  KC_ENT,    RSPC, KC_RGUI, KC_RALT, KC_RCTL,   FUNCT
),

/* LOWER */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_LBRC, KC_RBRC, KC_AMPR, KC_TILD,    LSFT(KC_C), LSFT(KC_D),    KC_7,    KC_8,    KC_9, KC_ASTR, KC_BSPC,
    _______, KC_LPRN, KC_RPRN, KC_PIPE, KC_CIRC,    LSFT(KC_B), LSFT(KC_E),    KC_4,    KC_5,    KC_6, KC_PLUS,  KC_ENT, 
    _______,   KC_LT,   KC_GT, KC_EXLM, LSFT(KC_X), LSFT(KC_A), LSFT(KC_F),    KC_1,    KC_2,    KC_3, KC_MINS,  KC_EQL,
    _______, _______, _______, _______, _______,    _______,       _______,    KC_0,  KC_DOT, KC_COMM, KC_SLSH, KC_PERC
),

/* RAISE */
[_RAISE] = LAYOUT_planck_grid(
    KC_TILD,  KC_GRV, KC_ASTR, KC_AMPR, KC_CIRC, KC_PERC, _______, _______, KC_LCBR, KC_RCBR, _______, _______,
    _______,  KC_DLR, KC_HASH,   KC_AT, KC_EXLM, KC_PLUS, _______, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, KC_ESCT,
    _______, KC_BSLS, KC_PIPE, KC_UNDS, KC_MINS,  KC_EQL, _______, _______,   KC_LT,   KC_GT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/* Function */
[_FUNCT] = LAYOUT_planck_grid(
      RESET, KC_PSCR,   KC_UP, KC_SLCK, KC_MNXT,  KC_INS, KC_PAUS,   KC_F1,   KC_F2,   KC_F3,   KC_F4, COLMKDH,
    BACKLIT, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, KC_HOME,  KC_END,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_PGUP, KC_PGDN,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  PLOVER, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   S  |   T  |   P  |   H  |   *  |  FN  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   S  |   K  |   W  |   R  |   *  |  PWR |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |   A  |   O  |      |             |      |   E  |   U  | RES1 | RES2 |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = LAYOUT_planck_grid(
  STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
  STN_S1,  STN_TL,  STN_PL,  STN_HL, STN_ST1,  STN_FN, STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  STN_S2,  STN_KL,  STN_WL,  STN_RL, STN_ST2, STN_PWR, STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
 EXT_PLV, XXXXXXX,   STN_A,   STN_O, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   STN_E,   STN_U, STN_RE1, STN_RE2
),

/* Adjust (Lower + Raise) */
[_ADJUST] = LAYOUT_planck_grid(
      RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DF(_COLMKDH),
    BACKLIT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, PLOVER,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

void matrix_init_user() {
	steno_set_mode(STENO_MODE_GEMINI);
}

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLMKDH:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLMKDH);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
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
        layer_off(_ADJUST);
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
    case EXT_PLV:
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
