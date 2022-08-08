# https://beta.docs.qmk.fm/reference/config-options#feature-options
# Features Specifically Wanted
EXTRAKEY_ENABLE = yes
STENO_ENABLE = yes
NKRO_ENABLE = yes
AUDIO_ENABLE = yes
MOUSEKEY_ENABLE = yes
MIDI_ENABLE = yes
# ENCODER_ENABLE = yes

# Features taking up space
CONSOLE_ENABLE = no
RAW_ENABLE = no
VIRTSER_ENABLE = no

SRC += muse.c
