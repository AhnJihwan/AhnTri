#include "../kinc/api.h"
#include "../arch/i386/isr.h"
#include "../arch/i386/irq.h"

volatile int tick = 0;

void pit_driver(registers_t *reg){
    (void)reg;
    tick++;											//Ticks
}
void pbt(){
	return tick;									//PIT based timer
}

void init_pit(){
	irq_install_handler(IRQ0, pit_driver);
}
