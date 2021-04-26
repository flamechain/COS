#ifndef SERIAL_H
#define SERIAL_H

#define PORT 0x3f8 // COM1

#include "util.h"

int serial_init();
int serial_received();
char read_serial();
int is_transmit_empty();
void write_serial(char a);
void write_serial_string(const char s[128]);

#endif
