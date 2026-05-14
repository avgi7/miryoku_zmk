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


/ {
    behaviors {
        // Κανονικό Auto-Shift ΜΟΝΟ για πλήκτρα (δεξί χέρι)
        as: auto_shift {
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            tapping-term-ms = <200>;
            quick-tap-ms = <0>;
            flavor = "tap-preferred";
            bindings = <&kp>, <&kp>;
        };
    };
};

/{
/ {
    behaviors {
        // 2. Το Macro Auto-Shift του urob απομονωμένο στο δικό του block
        ZMK_HOLD_TAP_BY_NAME(mas, &none, &none,
            flavor = "tap-preferred";
            tapping-term-ms = <135>;
        )
    };
};


#define MIRYOKU_LAYER_SYM \
&m_arrow,         &m_not_eq,           &m_hi2,           &m_hi1,         &as PRCNT TILDE,      &as PIPE BSLH,     &as MINUS UNDER,    &as CARET AMPS,   &as QUESTION EXCL,   &as SQT DQT,     \
&none,            &kp LALT,            &kp LCTRL,         &m_s4,         &mas m_hi2 m_hi1,     &as PLUS EQUAL,    &as RPAR LPAR,      &as RBKT LBKT,    &as GT LT,           &as RBRC LBRC,   \
&none,            &none,               &none,             &none,         &none,                &as AT DLLR,       &as ASTRK HASH,     &as COMMA SEMI,   &as DOT COLON,       &as GRAVE SLASH, \
U_NP,             U_NP,                &none,             &none,         &none,                &kp BSPC,          &kp SPACE,          &kp DEL,          U_NP,                U_NP

