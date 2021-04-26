#ifndef STDIO_H
#define STDIO_H

#include "../../util.h"
#include <font.h>
#include <keyboard.h>
#include <screen.h>

void printf(const char* s);
void set_text_color(u8 color);
void clear_terminal();

char scan();
void scan_init();

#endif
