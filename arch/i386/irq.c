#include "isr.h"
#include "irq.h"
#include "isr.h"
#include "../../kinc/api.h"
extern void set_idt_gate(uint8_t intnum, uint32 isr);

void remap_pic(){
	outb(0x20, 17);
	outb(0xA0, 17);
	outb(0x21, 32);
	outb(0xA1, 64);
	outb(0x21, 4);
	outb(0xA1, 2);
	outb(0x21, 1);
	outb(0xA1, 1);
	outb(0x21, 0);
	outb(0xA1, 0);
}

void irq_install(){
	remap_pic();
	set_idt_gate(IRQ0, (uint32_t)irq0);
	set_idt_gate(IRQI, (uint32_t)irq1);
	set_idt_gate(IRQII, (uint32_t)irq2);
	set_idt_gate(IRQIII, (uint32_t)irq3);
	set_idt_gate(IRQIV, (uint32_t)irq4);
	set_idt_gate(IRQV, (uint32_t)irq5);
	set_idt_gate(IRQVI, (uint32_t)irq6);
	set_idt_gate(IRQVII, (uint32_t)irq7);
	set_idt_gate(IRQVIII, (uint32_t)irq8);
	set_idt_gate(IRQIX, (uint32_t)irq9);
	set_idt_gate(IRQX, (uint32_t)irq10);
	set_idt_gate(IRQXI, (uint32_t)irq11);
	set_idt_gate(IRQXII, (uint32_t)irq12);
	set_idt_gate(IRQXIII, (uint32_t)irq13);
	set_idt_gate(IRQXIV, (uint32_t)irq14);
	set_idt_gate(IRQXV, (uint32_t)irq15);
	asm volatile ("sti");
}



/*The following code is borrowed from James Molloy's OSDev Tutorials mad in 2007.*/
isr_t interrupt_handlers[256];

void register_interrupt_handler(u8int n, isr_t handler)
{
    interrupt_handlers[n] = handler;
}

void irq_handler(registers_t regs)
{
    // Send an EOI (end of interrupt) signal to the PICs.
    // If this interrupt involved the slave.
    if (regs.int_no >= 40)
    {
        // Send reset signal to slave.
        outb(0xA0, 0x20);
    }
    // Send reset signal to master. (As well as slave, if necessary).
    outb(0x20, 0x20);

    if (interrupt_handlers[regs.int_no] != 0)
    {
        isr_t handler = interrupt_handlers[regs.int_no];
        handler(regs);
    }
}
/*End of Borrowing*/

/*The following code has been borrowed from https://github.com/ayush7788/discitix_kernel/blob/devel/cpu/irq.c, which is licensed under MIT.
*/
/*pointers to IRQ handlers in C*/
void *irq_routines[16] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

/*End of borrowing*/
