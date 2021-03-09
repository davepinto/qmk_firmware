#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND) \
                                }
#endif

#define MIDI_BASIC

#define TAPPING_TERM 200
#define TAPPING_TOGGLE 3

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#define RGBLIGHT_LAYERS
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP
