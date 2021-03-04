#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _NUMPAD,
  _RAISE,
  _ADJUST,
  _MOUSE,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  NUMPAD,
  RAISE,
  ADJUST,
  MOUSKY
};

enum tapdance_keycodes {
  LS_CAPS = SAFE_RANGE,
};

// TAP DANCE DEFINITIONS
qk_tap_dance_action_t tap_dance_actions[] = {
  // tap once for left shift, twice for caps
  [LS_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TAB  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |lS/CAP|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | RSFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |MOUSKY |SUPER |  `   | LCTL |RAISE | BSPC |  SPC |NUMPAD| LALT |  =   |  [   |  ]   |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  TD(LS_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT , \
  MOUSKY,  KC_LGUI, KC_GRV, KC_LCTL, RAISE,   KC_BSPC,  KC_SPC,  NUMPAD,   KC_LALT, KC_EQL, KC_LBRC,   KC_RBRC \
),

/* COLEMAK
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |   -  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LS/CAP|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  | RSFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |MOUSKY |SUPER |   `  | LCTL |RAISE | BSPC |  SPC |NUMPAD| LALT |   =  |   [  |   ]  |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS, \
  KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  TD(LS_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT , \
  MOUSKY,  KC_LGUI, KC_GRV, KC_LCTL, RAISE,   KC_BSPC,  KC_SPC,  NUMPAD,   KC_LALT, KC_EQL, KC_LBRC,   KC_RBRC \
),

/* DVORAK
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  /   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TAB  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LS/CAP|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | RSFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |MOUSKY| GUI  |   `  | LCTL |RAISE | BSPC |  SPC |NUMPAD| LALT |   =  |  [   |  ]   |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, \
  KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, \
  TD(LS_CAPS), KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT , \
  MOUSKY,  KC_LGUI, KC_GRV, KC_LCTL, RAISE,   KC_BSPC,  KC_SPC,  NUMPAD,   KC_LALT, KC_EQL, KC_LBRC,   KC_RBRC \
),

/* NUMPAD
 * ,-----------------------------------------------------------------------------------.
 * |      |   /  |   7  |   8  |   9  |   -  | PGUP | HOME |  UP  | END  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   *  |   4  |   5  |   6  |   +  | PGDN |  LF  |  DN  |  RT  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |NUMLOK|   1  |   2  |   3  |   =  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  .   |   0  |      | DEL  |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_4x12( \
  _______, KC_PSLS, KC_P7,   KC_P8, KC_P9,   KC_PMNS,   KC_PGUP, KC_HOME, KC_UP, KC_END, _______, _______, \
  _______, KC_PAST, KC_P4,   KC_P5, KC_P6,   KC_PPLS,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, KC_NLCK, KC_P1,   KC_P2, KC_P3,   KC_PENT,   _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_PDOT, KC_P0, _______, KC_DEL,    _______, _______, _______, _______, _______, _______ \
),

/* RAISE
 * ,-----------------------------------------------------------------------------------.
 * |      |  !   |  @   |  #   |  $   |  %   |  ^   |  &   |  *   |  (   |  )   |   |  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |   \  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |ENTER |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] =  LAYOUT_ortho_4x12( \
  _______, KC_EXLM,   KC_AT, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_ENT,  _______, _______, _______, _______, _______ \
),

/* ADJUST (LOWER + RAISE)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | RESET|BRITE+|BRITE-|  F1  |  F2  |  F3  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |COLEMK|QWERTY|DVORAK|  F4  |  F5  |  F6  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | MUTE |VOL + |VOL - |  F7  |  F8  |  F9  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |  F10 |  F11 | F12  |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, RESET,   KC_BRIU, KC_BRID, KC_F1,  KC_F2,  KC_F3, \
  _______, _______, _______, _______, _______, _______, COLEMAK, QWERTY,  DVORAK,  KC_F4,  KC_F5,  KC_F6, \
  _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLU, KC_VOLD, KC_F7,  KC_F8,  KC_F9, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F10, KC_F11, KC_F12 \
),

/* MOUSE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |CLIKLF|MOUSUP|CLIKRT|SCRLUP|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |MOUSLT|MOUSDN|MOUSRT|SCRLDN|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, KC_ACL0, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, \
  _______, _______, _______, _______, _______, _______, KC_ACL1, KC_MS_L,  KC_MS_D, KC_MS_R, KC_WH_D, _______, \
  _______, _______, _______, _______, _______, _______, KC_ACL2, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
        update_tri_layer(_NUMPAD, _RAISE, _ADJUST);
      } else {
        layer_off(_NUMPAD);
        update_tri_layer(_NUMPAD, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_NUMPAD, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_NUMPAD, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case MOUSKY:
      if (record->event.pressed) {
        layer_on(_MOUSE);
      } else {
        layer_off(_MOUSE);
      }
      return false;
      break;
  }
  return true;
}
