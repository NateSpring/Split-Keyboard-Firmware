#include QMK_KEYBOARD_H

// Note for later:
// Bongo Cat Example
// https://github.com/Ocelot08/QMKanim/blob/cbca5969abba9900665e25918c4ba809350fa063/keymap.c
//

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes { KC_QWERTY = SAFE_RANGE, KC_COLEMAK, KC_LOWER, KC_RAISE, KC_ADJUST, KC_PRVWD, KC_NXTWD, KC_LSTRT, KC_LEND, KC_DLINE, KC_GIT };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |ENTER |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | Bspc | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [_QWERTY] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LGUI, KC_BSPC, KC_LCTRL, KC_LOWER, KC_ENT, KC_SPC, KC_RAISE, KC_RCTRL, KC_RALT, KC_RGUI),
    /*
     * COLEMAK
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [_COLEMAK] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                           KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, 
        KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_G,                           KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC, 
        KC_TAB, KC_A, KC_R, KC_S, KC_T, KC_D,                           KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, 
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE,        XXXXXXX, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
        KC_LGUI, KC_LALT, KC_LCTRL, KC_LOWER, KC_ENT,          KC_SPC, KC_RAISE, KC_RCTRL, KC_RALT, KC_RGUI),
    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |UNDO  | CUT  | COPY |PASTE  |   GIT  |-------.    ,-------|   ^  |   _  |     |   +  |   )  |   |  |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [_LOWER] = LAYOUT(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                     KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
        KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,               KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
        _______, KC_UNDO, KC_UNDO, KC_COPY, KC_PASTE, KC_GIT,          KC_CIRC, KC_MINS, KC_EQL, KC_PLUS, KC_RPRN, KC_PIPE, 
        _______, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______, 
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /* RAISE
     * ,----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
     * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
     * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_RAISE] = LAYOUT
    (_______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, 
    _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                     KC_PGUP, KC_PRVWD, KC_UP, KC_NXTWD, KC_DLINE, KC_BSPC, 
    _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                 KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_BSPC, 
    _______, KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX, _______, _______, XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND, XXXXXXX, _______, 
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | RESET|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |Brkt  |Curly | Pths |  LT  |-------.    ,-------|  GT  | Pths | Curly| Brkt |      |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_ADJUST] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        RESET, XXXXXXX, KC_QWERTY, XXXXXXX, CG_TOGG, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, XXXXXXX, KC_LBRC, KC_LCBR, KC_LPRN, KC_LT,                 KC_GT, KC_RPRN, KC_RCBR, KC_RBRC, XXXXXXX, XXXXXXX, 
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, 
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)};

#ifdef OLED_DRIVER_ENABLE

// #define ANIM_FRAME_DURATION 250
// #define ANIM_SIZE 520 // number of bytes in array, minimize for adequate firmware size, max is 1024. originally 636
// #define XANIM_SIZE 650
// #define CAT_FRAMES 2
// #define TAP_FRAMES 3
// #define X_FRAMES 6
// uint32_t anim_timer = 0;
// uint32_t anim_sleep = 0;
// uint8_t current_tap_frame = 0;
// bool anim_phase = false;

// void animation_run(void) {
// 	if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
// 		oled_off();
// 	} else {
// 		if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
// 			anim_timer = timer_read32();
// 			anim_phase = true;
// 			}
// 		}
// }

// static void render_anim_cat(void) {
// 	static const char PROGMEM tap[CAT_FRAMES][ANIM_SIZE] = {
// 		{
//         // 'CAT_01', 128x32px
// 		0, 0, 0, 0, 0, 0, 0, 0, 0x80, 0x40, 0x40, 0xe0, 0x20, 0x10, 0, 0, 0xf0, 0x90, 0x60, 0xc4, 0x8a, 0x12, 0x32, 0x4c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x80, 0x80, 
// 		0, 0, 0, 0, 0, 0x80, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x04, 0x02, 0x01, 0x01, 0x02, 0x0c, 0x30, 0x40, 0x80, 0, 0, 0, 0, 0, 0, 0, 0xf8, 0xf8, 0xf8, 0xf8, 0, 0, 0, 0, 0, 0x80, 0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x03, 0x06, 0, 0, 
// 		0x03, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x1e, 0xe1, 0, 0, 0x01, 0x01, 0x02, 0x02, 0x81, 0x80, 0x80, 0, 0, 0x80, 0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x80, 0, 0x30, 0x30, 0, 0, 0x01, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x43, 0x87, 0x07, 0x01, 0, 0xb8, 0xbc, 0xbe, 0x9f, 0x5f, 0x5f, 0x4f, 0x4c, 0x20, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x02, 
// 		0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x80, 0x70, 0x0c, 0x03, 0, 0, 0x18, 0x06, 0x01, 0x80, 0x80, 0x80, 0x43, 0x7c, 0x41, 0x41, 0x40, 0x40, 0x20, 0x21, 0x22, 0x12, 0x11, 0x11, 0x11, 0x09, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x10, 
// 		0x10, 0x10, 0x11, 0x0f, 0x01, 0x3d, 0x7c, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x3c, 0x0c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x02, 0x01, 0x01, 
// 		0x01, 0x01, 0x01, 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x01, 0x03, 0x03, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
// 		},
//         {
// 		// 'CAT_02', 128x32px
// 		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x80, 0x80, 0, 0, 0, 0, 0, 0x80, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x04, 0x02, 0x01, 0x01, 0x02, 0x0c, 0x30, 0x40, 0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
// 		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x40, 0x20, 0x20, 0x60, 0x90, 0x10, 0, 0, 0xf0, 0x48, 0x50, 0x30, 0xe0, 0x82, 0x0e, 0x3b, 0x69, 0x0f, 0x06, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x1e, 0xe1, 0, 0, 0x01, 0x01, 0x02, 0x02, 0x01, 0, 0, 0, 0, 0x80, 0x80, 0, 0, 0, 0, 0, 
// 		0, 0, 0, 0, 0x80, 0, 0x30, 0x30, 0, 0, 0x01, 0xe1, 0x1a, 0x06, 0x01, 0x01, 0x01, 0x01, 0x82, 0x7c, 0, 0, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x03, 0, 0, 0, 0x03, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
// 		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x80, 0x70, 0x0c, 0x03, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x01, 0x01, 0, 0x40, 0xa0, 0x21, 0x22, 0x12, 0x11, 0x11, 0x11, 0x09, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
// 		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x7a, 0x7a, 0x79, 0x79, 0x79, 0x79, 0x39, 0x31, 0x02, 0x02, 0x04, 0x04, 0x08, 0x08, 0x08, 0x88, 0x88, 0x87, 0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
// 		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
//         },
//     };
	
// 	if(anim_phase == true) {
// 		current_tap_frame = (current_tap_frame + 1) % CAT_FRAMES;
// 		oled_write_raw_P(tap[abs((CAT_FRAMES-1)-current_tap_frame)], ANIM_SIZE);
// 		anim_phase = false;
// 	}

// 	animation_run();
// }


static void render_logo(void) {
    static const char PROGMEM nofle_logo[] = {
// 'happy-smmak', 128x32px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0x00, 0x00, 0xe3, 0x63, 0x33, 0x3f, 0x1f, 0x1b, 0x33, 0x73, 0x00, 0x00, 0x00, 0x31, 
0x31, 0x49, 0x49, 0x4e, 0x46, 0x46, 0x02, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0x00, 0x00, 0xfc, 0xfc, 0x0c, 0x7c, 0x7c, 0x0c, 0xfc, 0xfc, 0x00, 0x00, 0x00, 0x73, 
0x95, 0x19, 0x12, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x01, 
0xfe, 0xfe, 0x3e, 0xde, 0xfe, 0x7e, 0xfe, 0x7e, 0x6e, 0xee, 0xfe, 0xfe, 0x00, 0xff, 0xff, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0x00, 0x00, 0xfc, 0xfc, 0x0c, 0x7c, 0x7c, 0x0c, 0xfc, 0xfc, 0x00, 0x00, 0x00, 0xfe, 
0x12, 0x73, 0x92, 0xe4, 0x3f, 0x04, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff, 0x80, 
0x7f, 0x7f, 0x7e, 0x7d, 0x7f, 0x7f, 0x7f, 0x7f, 0x7b, 0x7b, 0x7f, 0x7f, 0x00, 0xff, 0xff, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0x00, 0x00, 0x7e, 0xfe, 0xc6, 0xfe, 0x7e, 0xc6, 0x7e, 0x7e, 0x00, 0x00, 0x0c, 0x1c, 
0x33, 0x4c, 0x88, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00
    };

    oled_write_raw_P(nofle_logo, sizeof(nofle_logo));
}


// Master OLED
static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    // oled_write_P(PSTR("N"), false);
    // oled_write_P(PSTR(" Keeb"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("DUBS\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}


// static void slave_status(void) {
//     oled_write_P(PSTR("NATES"), false); 
//     oled_write_P(PSTR("\n\n"), false);
//     oled_write_P(PSTR(" KEEB"), false);
    
// }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } 
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        // render_anim_cat();
        render_logo();
        // slave_status();
        // oled_scroll_left();
    }
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
            break;
        case KC_GIT:
            if (record->event.pressed){
                SEND_STRING("git add . && git commit -m 'Automated Keeb Commit' && git push origin master");
            }else {
            // when keycode QMKBEST is released
            }
            break;

    }
    return true;
}

#ifdef ENCODER_ENABLE
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
void encoder_update_user(uint8_t index, _Bool clockwise) {
    if (index == 0) {
        if (clockwise) {
        tap_code(KC_RIGHT);
        } else {
        tap_code(KC_LEFT);
        }
    } else if (index == 1) {
        if (clockwise) {
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                register_code(KC_LALT);
            }
            alt_tab_timer = timer_read();
            tap_code16(KC_TAB);
            } else {
            alt_tab_timer = timer_read();
            tap_code16(S(KC_TAB));
            }
                }
        }

        void matrix_scan_user(void) {
            if (is_alt_tab_active) {
                if (timer_elapsed(alt_tab_timer) > 650) {
                unregister_code(KC_LALT);
                is_alt_tab_active = false;
                }
            }
        }

#endif
