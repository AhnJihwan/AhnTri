#include "../kinc/qemu.h"
#include "../kinc/serial.h"
#include "../kinc/api.h"

uint32 qemu_init_debug(){
    init_serial(QEMU_SERIAL_PORT);
    return 1;
}

void qemu_printc(char ch){
    while((inb(QEMU_SERIAL_PORT + 5) & 0x20) == 0);
    outb(QEMU_SERIAL_PORT, ch);
}

void qemu_printf_string(char *msg){
    while (*msg != '\0'){
        qemu_printf(*msg);
        msg++;
    }
}
