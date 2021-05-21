#include "../kinc/api.h"
#include "../arch/i386/isr.h"
#include "../arch/i386/irq.h"

volatile uint32 tick = 0;

void pit_driver(registers *reg){
    (void)reg;
    tick++;											//Ticks
}
void pbt(){
	return tick;									//PIT based timer
}
