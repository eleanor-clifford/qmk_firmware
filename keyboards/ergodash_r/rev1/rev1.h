#ifndef REV1_H
#define REV1_H

#include "ergodash_r.h"

#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
    #include <avr/io.h>
    #include <avr/interrupt.h>
#endif
#endif

#ifndef FLIP_HALF
// Standard Keymap
// (TRRS jack on the left half is to the right, TRRS jack on the right half is to the left)
#define LAYOUT_4key( \
    L00, L01, L02, L03, L04, L05, L06,           R00, R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15, L16,           R10, R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25, L26,           R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35, L36,           R30, R31, R32, R33, R34, R35, R36, \
    L40, L41, L42, L43,      L44, L45, L46, R40, R41, R42,      R43, R44, R45, R46  \
    ) \
    { \
        { L00, L01, L02, L03, L04, L05, L06 }, \
        { L10, L11, L12, L13, L14, L15, L16 }, \
        { L20, L21, L22, L23, L24, L25, L26 }, \
        { L30, L31, L32, L33, L34, L35, L36 }, \
        { L40, L41, L42, L43, L44, L45, L46 }, \
        { R06, R05, R04, R03, R02, R01, R00 }, \
        { R16, R15, R14, R13, R12, R11, R10 }, \
        { R26, R25, R24, R23, R22, R21, R20 }, \
        { R36, R35, R34, R33, R32, R31, R30 }, \
        { R46, R45, R44, R43, R42, R41, R40 }  \
    }

// Just defined for configurator support, the matrix is identical to LAYOUT_4key
#define LAYOUT_4key_2u_inner( \
    L00, L01, L02, L03, L04, L05, L06,           R00, R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15, L16,           R10, R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25, L26,           R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35,      L36, R30,      R31, R32, R33, R34, R35, R36, \
    L40, L41, L42, L43,      L44, L45, L46, R40, R41, R42,      R43, R44, R45, R46  \
    ) \
    { \
        { L00, L01, L02, L03, L04, L05, L06 }, \
        { L10, L11, L12, L13, L14, L15, L16 }, \
        { L20, L21, L22, L23, L24, L25, L26 }, \
        { L30, L31, L32, L33, L34, L35, L36 }, \
        { L40, L41, L42, L43, L44, L45, L46 }, \
        { R06, R05, R04, R03, R02, R01, R00 }, \
        { R16, R15, R14, R13, R12, R11, R10 }, \
        { R26, R25, R24, R23, R22, R21, R20 }, \
        { R36, R35, R34, R33, R32, R31, R30 }, \
        { R46, R45, R44, R43, R42, R41, R40 }  \
    }

#define LAYOUT_3key_2us( \
    L00, L01, L02, L03, L04, L05, L06,           R00, R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15, L16,           R10, R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25, L26,           R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35,                     R31, R32, R33, R34, R35, R36, \
    L40, L41, L42, L43,      L44, L45, L46, R40, R41, R42,      R43, R44, R45, R46  \
    ) \
    { \
        { L00, L01, L02, L03, L04, L05, L06 }, \
        { L10, L11, L12, L13, L14, L15, L16 }, \
        { L20, L21, L22, L23, L24, L25, L26 }, \
        { L30, L31, L32, L33, L34, L35, KC_NO }, \
        { L40, L41, L42, L43, L44, L45, L46 }, \
        { R06, R05, R04, R03, R02, R01, R00 }, \
        { R16, R15, R14, R13, R12, R11, R10 }, \
        { R26, R25, R24, R23, R22, R21, R20 }, \
        { R36, R35, R34, R33, R32, R31, KC_NO }, \
        { R46, R45, R44, R43, R42, R41, R40 }  \
    }


#define LAYOUT_3key_1us( \
    L00, L01, L02, L03, L04, L05, L06, R00, R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15, L16, R10, R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25, L26, R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35, L36, R30, R31, R32, R33, R34, R35, R36, \
    L40, L41, L42, L43,      L44, L45, R41, R42,      R43, R44, R45, R46  \
    ) \
    { \
        { L00, L01, L02, L03, L04, L05, L06 }, \
        { L10, L11, L12, L13, L14, L15, L16 }, \
        { L20, L21, L22, L23, L24, L25, L26 }, \
        { L30, L31, L32, L33, L34, L35, L36 }, \
        { L40, L41, L42, L43, L44, L45, KC_NO }, \
        { R06, R05, R04, R03, R02, R01, R00 }, \
        { R16, R15, R14, R13, R12, R11, R10 }, \
        { R26, R25, R24, R23, R22, R21, R20 }, \
        { R36, R35, R34, R33, R32, R31, R30 }, \
        { R46, R45, R44, R43, R42, R41, KC_NO }  \
    }

#define LAYOUT_2key( \
    L00, L01, L02, L03, L04, L05, L06, R00, R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15, L16, R10, R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25, L26, R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35,           R31, R32, R33, R34, R35, R36, \
    L40, L41, L42, L43,      L44, L45, R41, R42,      R43, R44, R45, R46  \
    ) \
    { \
        { L00, L01, L02, L03, L04, L05, L06 }, \
        { L10, L11, L12, L13, L14, L15, L16 }, \
        { L20, L21, L22, L23, L24, L25, L26 }, \
        { L30, L31, L32, L33, L34, L35, KC_NO }, \
        { L40, L41, L42, L43, L44, L45, KC_NO }, \
        { R06, R05, R04, R03, R02, R01, R00 }, \
        { R16, R15, R14, R13, R12, R11, R10 }, \
        { R26, R25, R24, R23, R22, R21, R20 }, \
        { R36, R35, R34, R33, R32, R31, KC_NO }, \
        { R46, R45, R44, R43, R42, R41, KC_NO }  \
    }

#define LAYOUT LAYOUT_4key

#else
// Keymap with right side flipped
// (TRRS jack on both halves are to the right)
#define LAYOUT( \
    L00, L01, L02, L03, L04, L05, L06, R00, R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15, L16, R10, R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25, L26, R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35, L36, R30, R31, R32, R33, R34, R35, R36, \
    L40, L41, L42, L43, L44, L45, L46, R40, R41, R42, R43, R44, R45, R46  \
    ) \
    { \
        { L00, L01, L02, L03, L04, L05, L06 }, \
        { L10, L11, L12, L13, L14, L15, L16 }, \
        { L20, L21, L22, L23, L24, L25, L26 }, \
        { L30, L31, L32, L33, L34, L35, L36 }, \
        { L40, L41, L42, L43, L44, L45, L46 }, \
        { R00, R01, R02, R03, R04, R05, R06 }, \
        { R10, R11, R12, R13, R14, R15, R16 }, \
        { R20, R21, R22, R23, R24, R25, R26 }, \
        { R30, R31, R32, R33, R34, R35, R36 }, \
        { R40, R41, R42, R43, R44, R45, R46 }  \
    }
#endif

#endif
