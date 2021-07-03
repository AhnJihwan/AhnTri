#include "../kinc/api.h"
#include "../kinc/qemu.h"
#include "../kinc/serial.h"

uint32 qemu_init_debug(){
    init_serial(QEMU_SERIAL_PORT);
}

void qemu_printc(char ch){
    while((inb(QEMU_SERIAL_PORT + 5) & 0x20) == 0);
    outb(QEMU_SERIAL_PORT, ch);
}

void qemu_printf_string(char *msg){
    while (*msg != '\0'){
        qemu_printc(*msg);
        msg++;
    }
}
