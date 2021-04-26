#include "kernel/idt.h"
#include "kernel/isr.h"
#include "kernel/irq.h"
#include "kernel/screen.h"
#include "main.h"

void c_main(u32 magic) {
    idt_init();
    isr_init();
    // fpu_init();
    irq_init();
    screen_init();
    // timer_init();
    // keyboard_init();
}
