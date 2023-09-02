// Obins stock firmware has something similar to this already enabled, but disabled by default in QMK
//#define PERMISSIVE_HOLD

#undef PERMISSIVE_HOLD

#define IGNORE_MOD_TAP_INTERRUPT

#define TAPPING_TERM 180

#ifdef COMBO_ENABLE
#    define COMBO_COUNT 8
#    define COMBO_TERM 50
#endif
