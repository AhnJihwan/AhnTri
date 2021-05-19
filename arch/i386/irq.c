#include "irq.h"
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

void irq0handler(void) {
          outb(32, 32);
}
 
void irq1handler(void) {
	  outb(32, 32);
}
 
void irq2handler(void) {
          outb(32, 32);
}
 
void irq3handler(void) {
          outb(32, 32);
}
 
void irq4handler(void) {
          outb(32, 32);
}
 
void irq5handler(void) {
          outb(32, 32);
}
 
void irq6handler(void) {
          outb(32, 32);
}
 
void irq7handler(void) {
          outb(32, 32);
}
 
void irq8handler(void) {
          outb(160, 32);
          outb(32, 32);          
}
 
void irq9handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq10handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq11handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq12handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq13handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq14handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq15handler(void) {
          outb(160, 32);
          outb(32, 32);
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
}
