#include <stdio.h>
#include "keyboard.h"

char keymap[50][3] = {
    {'a', 'A', false},
    {'b', 'B', false},
    {'c', 'C', false},
    {'d', 'D', false},
    {'e', 'E', false},
    {'f', 'F', false},
    {'g', 'G', false},
    {'h', 'H', false},
    {'i', 'I', false},
    {'j', 'J', false},
    {'k', 'K', false},
    {'l', 'L', false},
    {'m', 'M', false},
    {'n', 'N', false},
    {'o', 'O', false},
    {'p', 'P', false},
    {'q', 'Q', false},
    {'r', 'R', false},
    {'s', 'S', false},
    {'t', 'T', false},
    {'u', 'U', false},
    {'v', 'V', false},
    {'w', 'W', false},
    {'x', 'X', false},
    {'y', 'Y', false},
    {'z', 'Z', false},
    {' ', ' ', false},
    {'1', '!', false},
    {'2', '@', false},
    {'3', '#', false},
    {'4', '$', false},
    {'5', '%', false},
    {'6', '^', false},
    {'7', '&', false},
    {'8', '*', false},
    {'9', '(', false},
    {'0', ')', false},
    {'-', '_', false},
    {'=', '+', false},
    {'`', '~', false},
    {'[', '{', false},
    {']', '}', false},
    {'\\', '|', false},
    {';', ':', false},
    {'\'', '"', false},
    {',', '<', false},
    {'.', '>', false},
    {'/', '?', false},
    {'\n', '\n', false},
    {'\b', '\b', false}
};

void check_key(bool islet, int check, char lower, char upper, char* key);

char scan() {
    char key = '\x00';

    for (u32 i=0; i < 50; i++) {
        if (keyboard_char(keymap[i][0]) && keymap[i][2] == false) {
            keymap[i][2] = true;

            if (keyboard_key(KEY_LSHIFT) || keyboard_key(KEY_RSHIFT)) {
                key = keymap[i][1];
            } else {
                key = keymap[i][0];
            }
        } else if (!keyboard_char(keymap[i][0])) {
            keymap[i][2] = false;
        }
    }

    return key;
}
