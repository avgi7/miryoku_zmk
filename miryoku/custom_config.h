// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

#define MIRYOKU_LAYER_NAV \
&kp END,          &kp PG_DN,         &kp PG_UP,         &kp HOME,           &kp INS,           U_NA,              &u_to_U_BASE,      &u_to_U_EXTRA,     &u_to_U_TAP,       U_BOOT,            \
&kp LEFT,          &kp DOWN,          &kp UP,            &kp RIGHT,         &u_caps_word,      U_NA,              &kp LSHFT,         &kp LCTRL,         &kp LALT,          &kp LGUI,          \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_NA,              &u_to_U_NAV,       &u_to_U_NUM,       &kp RALT,          U_NA,              \
U_NP,              U_NP,              &kp DEL,           &kp BSPC,          &kp RET,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_BUTTON \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             &soft_off,         \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         U_NU,              U_NU,              &kp LSHFT,         &kp LCTRL,         &kp LALT,          &kp LGUI,          \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
U_NP,              U_NP,              U_BTN3,            U_BTN1,            U_BTN2,            U_BTN2,            U_BTN1,            U_BTN3,            U_NP,              U_NP
