#include "main.h"

#define FPS 30

static void fill_screen(u8 r, u8 g, u8 b) {
    const size_t w = SCREEN_WIDTH / 3;
    const size_t h = SCREEN_HEIGHT / 3;
    screen_fill(COLOR(r, g, b), (SCREEN_WIDTH - w) / 2, (SCREEN_HEIGHT - h) / 2, w, h);
}

void update() {
}

void render() {
    if (keyboard_char('\n')) {
        fill_screen(0, 255, 0);
    } else {
        fill_screen(0, 0, 255);
    }
}

int c_main(u32 magic) {
    idt_init();
    isr_init();
    fpu_init();
    irq_init();
    screen_init();
    timer_init();
    keyboard_init();
    fill_screen(255, 255, 255);

    u64 last = 0;
    u64 now = 0;

    while (true) {
        now = timer_get();

        if ((now - last) > (TIMER_TPS / FPS)) {
            last = now;
            update();
            render();
        }
    }

    return 0;
}
