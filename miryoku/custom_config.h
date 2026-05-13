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
            tapping-term-ms = <180>;
            quick-tap-ms = <0>;
            flavor = "tap-preferred";
            bindings = <&kp>, <&kp>;
        };
    };

    macros {
        // JavaScript Arrow Function: =>
        m_arrow: m_arrow {
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            wait-ms = <10>;
            bindings = <&kp EQUAL &kp GT>;
        };

        // JavaScript Strict Equality: ===
        m_eq3: m_eq3 {
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            wait-ms = <10>;
            bindings = <&kp EQUAL &kp EQUAL &kp EQUAL>;
        };

        // JS/Python Not Equal: !=
        m_not_eq: m_not_eq {
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            wait-ms = <10>;
            bindings = <&kp EXCL &kp EQUAL>;
        };

        // Τα δικά σου macros για tags (π.χ. <html>)
        m_hi1: m_hi1 {
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            wait-ms = <10>;
            bindings = <&kp LT &kp M &kp A &kp R &kp K &kp GT>; 
        };
        m_hi2: m_hi2 {
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            wait-ms = <10>;
            bindings = <&kp LT &kp SLASH &kp M &kp A &kp R &kp K &kp GT>; 
        };

        // ΠΑΡΑΜΕΤΡΟΠΟΙΗΜΕΝΟ MACRO (Αντικαθιστά το mas)
        // Πατώντας το εκτελεί το 2ο όρισμα, κρατώντας το εκτελεί το 1ο όρισμα
        mas: macro_auto_shift {
            compatible = "zmk,behavior-macro-two-param";
            #binding-cells = <2>;
            wait-ms = <0>;
            tap-ms = <0>;
            bindings
                = <&macro_param_2to1>
                , <&macro_press &none MACRO_PLACEHOLDER> // Placeholder για v0.3
                , <&macro_pause_for_release>
                , <&macro_param_1to1>
                , <&macro_tap &none MACRO_PLACEHOLDER>
                ;
        };
    };
};



#define MIRYOKU_LAYER_SYM \
&m_not_eq,        &m_arrow,            &mas m_hi2 m_hi1,  &m_py_def,     &as PRCNT TILDE,      &as PIPE BSLH,     &as MINUS UNDER,    &as CARET AMPS,   &as EXCL QUESTION,   &as SQT DQT,     \
&m_eq3,           &kp LALT,            &kp LCTRL,         &none,         &none,                &as PLUS EQUAL,    &as RPAR LPAR,      &as RBKT LBKT,    &as GT LT,           &as RBRC LBRC,   \
&none,            &none,               &none,             &none,         &none,                &as AT DLLR,       &as ASTRK HASH,     &as COMMA SEMI,   &as DOT COLON,       &as GRAVE SLASH, \
U_NP,             U_NP,                &none,             &none,         &none,                &kp BSPC,          &kp SPACE,          &kp DEL,          U_NP,                U_NP

