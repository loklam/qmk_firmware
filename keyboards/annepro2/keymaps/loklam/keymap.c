#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

//combos
const uint16_t PROGMEM combo_we[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_ds[] = {KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM combo_er[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_io[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_kl[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_commdot[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_ds, KC_ESC),
    COMBO(combo_er, KC_TAB), 
    COMBO(combo_io, KC_BSPC), 
    COMBO(combo_kl, KC_ENT), 
    COMBO(combo_commdot, KC_RSFT), 
};

enum anne_pro_layers {
  _BASE_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
  _UPR_LAYER,
  _NUM_LAYER,
  _FNN_LAYER,
};

// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* | esc~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp  |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  | (w) |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | FN1     |  a  |  s  |  d  | (f) |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      | (z) | (x) |  c  | (v) |  b  |  n  |  m  |  ,  | (.) | (/) |      Shift     |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               _UPR_             | Menu  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* | CapL    |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |             Space               |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
    KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    MT(MOD_LCTL|MOD_LSFT,KC_TAB), KC_Q, WIN_T(KC_W), KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    CTL_T(KC_CAPS), KC_A, KC_S, KC_D, LT(_NUM_LAYER,KC_F), KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, ALT_T(KC_Z), RCS_T(KC_X), LT(_FNN_LAYER,KC_C), KC_V, KC_B, KC_N, KC_M, KC_COMM, RCS_T(KC_DOT), RALT_T(KC_SLSH), RSFT_T(KC_UP),
    KC_LCTL, KC_LGUI, KC_LALT, LT(_UPR_LAYER,KC_SPC), KC_APP, LT(_FN1_LAYER,KC_LEFT), LT(_FN2_LAYER,KC_DOWN), RCTL_T(KC_RGHT)
),
  /*
  * Layer _FN1_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-UP |V-DWN|MUTE |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN1_LAYER] = KEYMAP( /* Base */
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
    KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_TRNS,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN2_LAYER), KC_TRNS
),
  /*
  * Layer _FN2_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  | BT1 | BT2 | BT3 | BT4 | USB |  F6 |LedSpd|LedPv |LedNx|Bri|LedOF|LedON|    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |BTunP|  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | CapL    |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |             FnSpace             |  App  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN2_LAYER] = KEYMAP( /* Base */
    KC_TRNS, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_AP2_USB, KC_TRNS, KC_AP_LED_SPEED, KC_AP_LED_PREV_PROFILE, KC_AP_LED_NEXT_PROFILE , KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_OFF, KC_AP_LED_ON, KC_TRNS,
    MO(_FN2_LAYER), KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AP2_BT_UNPAIR, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_TRNS,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN1_LAYER), MO(_FN2_LAYER), KC_TRNS
 ),
  /*
  * Layer _UPR_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  BskSpc   |
  * |-----------------------------------------------------------------------------------------+
  * |        | esc |  w  |  e  |  r  |  t  |HOME | PgUp| INS | END | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * |         |  a  |  s  |  -  |  =  |  g  | LEFT| DOWN|  UP |RIGHT|Enter|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  [  |  ]  |  \  | Bksp| PgDn| DEL |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |             FnSpace             |  App  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_UPR_LAYER] = KEYMAP( /* Base */
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_BSPC,
    KC_TRNS, KC_GESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP, KC_INS, KC_END, KC_PSCR, KC_HOME, KC_END, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_BSPC, KC_PGDN, KC_DEL, KC_INS, KC_DEL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN2_LAYER), KC_TRNS
 ),
  /*
  * Layer _NUM_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  *  |  F9 | F10 | F11 | F12 |  BskSpc   |
  * |-----------------------------------------------------------------------------------------+
  * |        |  q  |  w  |  e  |  r  |  t  |  =  |  7  |  8 |  9  |  +  |  [   |  ]  |   \    |
  * |-----------------------------------------------------------------------------------------+
  * |         |  a  |  s  |  d  |  f  |  g  |  -  |  4  |  5  |  6  |  .  |  `  |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  \  |  0  |  1  |  2  |  3  |  /  |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |             FnSpace             |  App  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_NUM_LAYER] = KEYMAP( /* Base */
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_PAST, KC_F9, KC_F10, KC_F11, KC_F12, KC_BSPC,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EQL, KC_7, KC_8, KC_9, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_4, KC_5, KC_6, KC_DOT, KC_GRV, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_0, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN2_LAYER), KC_TRNS
 ),
  /*
  * Layer _FNN_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  BskSpc   |
  * |-----------------------------------------------------------------------------------------+
  * |        |  q  |  w  |  e  |  r  |  t  | F12 |  F7 | F8 | F9  |  [  |  [   |  ]  |   \    |
  * |-----------------------------------------------------------------------------------------+
  * |         |  a  |  s  |  d  |  f  |  g  | F11 | F4  | F5  | F6  |  ]  |  `  |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  \  | F10 | F1  | F2  | F3  |  /  |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |             FnSpace             |  App  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FNN_LAYER] = KEYMAP( /* Base */
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_BSPC,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12, KC_F7, KC_F8, KC_F9, KC_LBRC, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11, KC_F4, KC_F5, KC_F6, KC_RBRC, KC_GRV, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_F10, KC_F1, KC_F2, KC_F3, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN2_LAYER), KC_TRNS
 ),
};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
    // Here are two common functions that you can use. For more LED functions, refer to the file "qmk_ap2_led.h"

    // annepro2-shine disables LEDs by default. Uncomment this function to enable them at startup.
    // annepro2LedEnable();

    // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
    // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
    // annepro2LedSetProfile(i);
}

const annepro2Led_t my_red = {
   .p.blue  = 0x00,
   .p.red   = 0xff,
   .p.green = 0x00,
   .p.alpha = 0xff,
};

const annepro2Led_t my_green = {
   .p.blue  = 0x00,
   .p.red   = 0x00,
   .p.green = 0xff,
   .p.alpha = 0xff,
};

const annepro2Led_t my_yellow = {
   .p.blue  = 0x00,
   .p.red   = 0xff,
   .p.green = 0xff,
   .p.alpha = 0xff,
};


layer_state_t layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(state)) {
    	case _UPR_LAYER:
	    annepro2LedStickySetKey(4, 6, my_green);
	    break;
    	case _NUM_LAYER:
	    annepro2LedStickySetKey(4, 6, my_yellow);
	    break;
    	case _FNN_LAYER:
	    annepro2LedStickySetKey(4, 6, my_red);
	    break;
	default:
     	    annepro2LedStickyUnsetKey(4, 6);
	    break;

    }
    return state;
}

// The function to handle the caps lock logic
bool led_update_user(led_t leds) {
  if (leds.caps_lock) {
    // Set the leds to red
    annepro2LedStickySetKey(2, 0, my_red);
  } else {
    annepro2LedStickyUnsetKey(2, 0);
  }

  return true;
}

