#include "iris.h"
#include "keymap_steno.h"

#define _DVORAK 0
#define _SYMB 1
#define _FUNC 2
#define _PLOVER 3

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_SYMB MO(_SYMB)
#define KC_FUNL MO(_FUNC)
#define KC_DVRK TO(_DVORAK)
#define KC_PLOV TO(_PLOVER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    GESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB ,QUOT,COMM,DOT , P  , Y  ,                F  , G  , C  , R  , L  ,SLSH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, A  , O  , E  , U  , I  ,                D  , H  , T  , N  , S  ,MINS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL,SCLN, Q  , J  , K  , X  ,SYMB ,    PLOV, B , M  , W  , V  , Z  ,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,LALT,SPC ,         ENT ,UP ,DOWN
  //                  `----+----+----'        `----+----+----'
  ),

  [_SYMB] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    GRAVE,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT,HOME,    , UP ,EQL ,PLUS,               LBRC,RBRC, P5 , P6 ,PLUS,PIPE,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL,END ,LEFT,DOWN,RGHT,MINS,    ,     FUNL,LCBR,RCBR, P2 , P3 ,MINS,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,SPC ,         ENT ,LEFT,RGHT
  //                  `----+----+----'        `----+----+----'
  ),

  [_FUNC] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,MPRV,MNXT,VOLU,PGUP,UNDS,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     MUTE,MSTP,MPLY,VOLD,PGDN,MINS,     ,        ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  // not using LAYOUT_kc here because the steno keys are not prefixed with KC_
  [_PLOVER] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
     _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     _______,STN_N1 ,STN_N2 ,STN_N3 ,STN_N4 ,STN_N5 ,                     STN_N6 ,STN_N7 ,STN_N8 ,STN_N9 ,STN_NA ,STN_NB ,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   KC_LSHIFT,STN_S1 ,STN_TL ,STN_PL ,STN_HL ,STN_ST1,                     STN_ST3,STN_FR ,STN_PR ,STN_LR ,STN_TR ,STN_DR ,
  //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
     KC_LCTL,STN_S2 ,STN_KL ,STN_WL ,STN_RL ,STN_ST2,KC_DVRK,     KC_DVRK,STN_ST4,STN_RR ,STN_BR ,STN_GR ,STN_SR ,STN_ZR ,
  //`-------+-------+-------+--+----+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
                                 STN_A , STN_O ,_______,            _______, STN_E , STN_U
  //                           `-------+-------+-------'           `-------+-------+-------'
  )

};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  steno_set_mode(STENO_MODE_GEMINI);
};
