#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND) \
                                }
#endif

#define MIDI_BASIC

#define TAPPING_TERM 200
#define TAPPING_TOGGLE 4
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

#define ONESHOT_TAP_TOGGLE  4
#define ONESHOT_TIMEOUT     3000

#define RGBLIGHT_LAYERS
