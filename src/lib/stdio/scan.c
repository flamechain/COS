#include <stdio.h>
#include "keyboard.h"

bool S_KEY_LSHIFT = false;
bool S_KEY_RSHIFT = false;
bool S_KEY_ENTER = false;
bool S_KEY_A = false;

void scan_init() {
    S_KEY_LSHIFT = false;
    S_KEY_RSHIFT = false;
    S_KEY_ENTER = false;
    S_KEY_A = false;
}

char scan() {
    char key = '\x00';

    if (keyboard_char('\n') && S_KEY_ENTER == false) {
        S_KEY_ENTER = true;
        key = KEY_ENTER;
    } else if (!keyboard_char('\n')) {
        S_KEY_ENTER = false;
    }

    if (keyboard_char('a') && S_KEY_A == false) {
        S_KEY_A = true;

        if (S_KEY_LSHIFT || S_KEY_RSHIFT) {
            key = 'A';
        } else {
            key = 'a';
        }
    } else if (!keyboard_char('a')) {
        S_KEY_A = false;
    }

    if (keyboard_key(KEY_LSHIFT) && S_KEY_LSHIFT == false) {
        S_KEY_LSHIFT = true;
        key = KEY_RSHIFT;
    } else if (!keyboard_key(KEY_LSHIFT)) {
        S_KEY_LSHIFT = false;
    }

    if (keyboard_key(KEY_RSHIFT) && S_KEY_RSHIFT == false) {
        S_KEY_RSHIFT = true;
        key = KEY_RSHIFT;
    } else if (!keyboard_key(KEY_RSHIFT)) {
        S_KEY_RSHIFT = false;
    }

    return (char)key;
}
