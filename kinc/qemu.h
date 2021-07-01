#ifndef _QEMU_H
#define _QEMU_H

#define QEMU_SERIAL_PORT    0x3f8

uint32 qemu_init_debug();
void qemu_printf_string(char *msg);
void qemu_printc(char);

#endif
