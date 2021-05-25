#include "../kinc/api.h"
#include "../arch/i386/isr.h"
#include "../arch/i386/irq.h"

int pit_frequency = 100;

unsigned read_pit_count(void) {
	unsigned count = 0;
	cli();
	outb(0x43,0b0000000);
 
	count = inb(0x40);		// Low byte
	count |= inb(0x40)<<8;		// High byte
 
	return count;
}

void spfreq(unsigned count) {
	// Interrupts interrupts
	cli();
	// Set low byte
	outb(0x40,count&0xFF);		// Low byte
	outb(0x40,(count&0xFF00)>>8);	// High byte
	return;
}

volatile int tick = 0;

void pit_driver(registers_t *reg){
    (void)reg;
    tick++;											//Ticks
    return tick;
}

int pbt(){
	return tick;									//PIT based timer
}

static void timer_callback(registers_t regs)
{
   tick++;
   printf("Tick: ");
   print_int(tick/18);
   printf("\n");
}

void pit(u32int frequency)
{

    // The value we send to the PIT is the value to divide it's input clock
    // (1193180 Hz) by, to get our required frequency. Important to note is
    // that the divisor must be small enough to fit into 16-bits.
    u32int divisor = 1193180 / frequency;

    // Send the command byte.
    outb(0x43, 0x36);

    // Divisor has to be sent byte-wise, so split here into upper/lower bytes.
    u8int l = (u8int)(divisor & 0xFF);
    u8int h = (u8int)( (divisor>>8) & 0xFF );
    // Firstly, register our timer callback.
    register_interrupt_handler(IRQ0, &timer_callback);
}

function uptime(){
	int sec = pbt() / pit_frequency;
	return sec;
}
