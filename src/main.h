#ifndef C_MAIN_H
#define C_MAIN_H

#include "kernel/idt.h"
#include "kernel/isr.h"
#include "kernel/irq.h"
#include "kernel/screen.h"
#include "kernel/fpu.h"
#include "kernel/timer.h"
#include "kernel/keyboard.h"
#include "kernel/util.h"

int c_main(u32 magic);

#endif
