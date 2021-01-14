#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

/* custom keycodes and combinations */
#define RSFT_ENTER RSFT_T(KC_ENTER)
#define RGUI_ENTER RGUI_T(KC_ENTER)
#define LGUI_ESC LGUI_T(KC_ESC)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

/* custom maximum time between tap dance taps, in ms */
#define TAPPING_TERM 150
