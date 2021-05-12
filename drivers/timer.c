#include "../init/api.h"

//My PIT driver code 
unsigned read_pit_count(void) {
	unsigned count = 0;
	cli();
	outb(0x43,0b0000000);
 
	count = inb(0x40);		// Low byte
	count |= inb(0x40)<<8;		// High byte
 
	return count;
}

void set_pit_count(unsigned count) {
	// Interrupts interrupts
	cli();
	// Set low byte
	outb(0x40,count&0xFF);		// Low byte
	outb(0x40,(count&0xFF00)>>8);	// High byte
	return;
}
