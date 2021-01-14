#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND) \
                                }
#endif

/* enable basic MIDI features */
#define MIDI_BASIC

#define TAPPING_TERM 175
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
