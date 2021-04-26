#include "util.h"
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

#define FPS 30

void hlt() {
    while (true);
}

void raise_debug(const char* msg) {
    write_serial_string(msg);
    assert(false, "ERROR 0");
}

void fill_screen(u8 r, u8 g, u8 b) {
    screen_clear(COLOR((int)(r / 8), (int)(g / 8), (int)(b / 8)));
    screen_swap();
}

void printf(const char* s, u8 r, u8 g, u8 b) {
    font_str(s, 0, 0, COLOR((int)(r / 8), (int)(g / 8), (int)(b / 8)));
}

void update() {
}

void render() {
    if (keyboard_char('\n')) {
        fill_screen(255, 255, 255);
    } else {
        fill_screen(0, 0, 0);
    }
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
        const char *msg = "ERROR 1: main.c: Failed to initalize kernel.serial\n";
        write_serial_string(msg);
        assert(false, "ERROR 1");
    }

    u32 last = 0;

    while (true) {
        const u32 now = (u32)timer_get();

        if ((now - last) > (TIMER_TPS / FPS)) {
            last = now;
            update();
            render();
        }
    }
}
