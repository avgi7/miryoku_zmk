// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

// Ensure we are applying this specific fix to the Corne keyboard
#if defined(MIRYOKU_KEYBOARD_CORNE)

/ {
    // Delete the original external power switch node if it exists
    /delete-node/ ext-power;

    // Re-create the external power node bound to pin P0.29
    ext-power {
        compatible = "zmk,ext-power-generic";
        label = "OLED_REMAP_POWER";
        control-gpios = <&gpio0 29 GPIO_ACTIVE_HIGH>;
        init-delay-ms = <50>;
    };
};

#endif

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



#define MIRYOKU_LAYER_SYM \
&m_arrow,         &m_s 0 0,            &m_lg 0 0,         &m_hi 0 0,     &as PRCNT TILDE,      &as PIPE BSLH,     &as MINUS UNDER,    &as CARET AMPS,   &as QUESTION EXCL,   &as SQT DQT,     \
&m_not_eq,        &kp LALT,            &kp LCTRL,         &none,         &none,                &as PLUS EQUAL,    &as RPAR LPAR,      &as RBKT LBKT,    &as GT LT,           &as RBRC LBRC,   \
&none,            &none,               &none,             &none,         &none,                &as AT DLLR,       &as ASTRK HASH,     &as COMMA SEMI,   &as DOT COLON,       &as GRAVE SLASH, \
U_NP,             U_NP,                &none,             &none,         &none,                &kp BSPC,          &kp SPACE,          &kp DEL,          U_NP,                U_NP

