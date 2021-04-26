#include <stdio.h>
#include "util.h"
#include "screen.h"

size_t cursor_x = 0;
size_t cursor_y = 0;

u8 terminal_text_color = COLOR(0, 0, 0);

void set_text_color(u8 color) {
    terminal_text_color = color;
}

void clear_terminal() {
    fill_screen(0, 0, 0);
    cursor_x = 0;
    cursor_y = 0;
}

void printf(const char* s) {
    for (u32 i=0; i < strlen(s); i++) {
        char key = s[i];

        if (key == '\n') {
            cursor_y += 8;
        } else if (key == '\r') {
            cursor_x = 0;
        } else {
            font_str(&s[i], cursor_x, cursor_y, terminal_text_color);
            cursor_x += 8;

            if (cursor_x > SCREEN_WIDTH) {
                cursor_x = 0;
                cursor_y += 8;
            }
        }
    }
}
