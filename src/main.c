#include "screen.h"
#include "idt.h"
#include "isr.h"
#include "irq.h"
#include "timer.h"
#include "font.h"
#include "system.h"
#include "keyboard.h"
#include "fpu.h"
#include "serial.h"
#include "util.h"
#include <stdio.h>

#define FPS 30

char screen[400];
int counter = 0;

void raise_error(const char* msg) {
    write_serial_string(msg);
    fill_screen(255, 0, 0);
    printf(msg);
    load_screen();
    HLT();
}

void raise_debug(const char* s) {
    write_serial_string(s);
    raise_error(s);
}

void update() {
    char key = scan();

    if (key != '\x00' && key != '\b' && key != '\n') {
        screen[counter++] = key;
    } else if (key == '\b') {
        if (counter > 0) {
            screen[--counter] = '\x00';

            if (screen[counter-1] == '\n') {
                screen[--counter] = '\x00';
            }
        }
    } else if (key == '\n') {
        screen[counter++] = '\n';
        screen[counter++] = '\r';
    } else if (key != '\x00') {
        write_serial_string("ERROR 2: main.c: Unknown character given by stdio.scan\n");
    }
}

void render() {
    clear_terminal();
    printf(screen);
    load_screen();
}

void _main(u32 magic) {
    idt_init();
    isr_init();
    fpu_init();
    irq_init();
    timer_init();
    screen_init();
    keyboard_init();

    if (serial_init()) {
        raise_error("ERROR 1: main.c: Failed to initalize kernel.serial");
    }

    u32 last = 0;
    set_text_color(COLOR(7, 7, 7));

    while (true) {
        const u32 now = (u32)timer_get();

        if ((now - last) > (TIMER_TPS / FPS)) {
            last = now;
            update();
            render();
        }
    }
}
