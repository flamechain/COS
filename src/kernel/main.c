#include "util.h"
#include "idt.h"
#include "isr.h"
#include "irq.h"
#include "screen.h"
#include "fpu.h"
#include "timer.h"
#include "keyboard.h"

#define FPS 30

void update() {
}

void render() {
    if (keyboard_char('\n')) {
        screen_clear(COLOR(255, 0, 0));
    } else {
        screen_clear(COLOR(0, 255, 0));
    }
}

int _main(u32 magic) {
    idt_init();
    isr_init();
    fpu_init();
    irq_init();
    screen_init();
    timer_init();
    keyboard_init();
    screen_clear(COLOR(255, 255, 255));

    u32 last = 0;

    while (true) {
        const u32 now = (u32)timer_get();

        if ((now - last) > (TIMER_TPS / FPS)) {
            last = now;
            update();
            render();
        }
    }

    return 0;
}
