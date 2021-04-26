#include "serial.h"

int serial_init() {
    outportb(PORT + 1, 0x00);
    outportb(PORT + 3, 0x80);
    outportb(PORT + 0, 0x03);
    outportb(PORT + 1, 0x00);
    outportb(PORT + 3, 0x03);
    outportb(PORT + 2, 0xc7);
    outportb(PORT + 4, 0x0b);
    outportb(PORT + 4, 0x1e);
    outportb(PORT + 0, 0xae);

    if(inportb(PORT + 0) != 0xae) {
        return 1;
    }

    outportb(PORT + 4, 0x0f);

    return 0;
}

int serial_received() {
    return inportb(PORT + 5) & 1;
}

char read_serial() {
    while (!serial_received());

    return inportb(PORT);
}

int is_transmit_empty() {
    return inportb(PORT + 5) & 0x20;
}

void write_serial(char a) {
    while (!is_transmit_empty());

    outportb(PORT, a);
}

void write_serial_string(const char s[128]) {
    for (u32 i=0; i < strlen(s); i++) {
        write_serial(s[i]);
    }
}
