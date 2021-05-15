#ifndef idt_H
#define idt_H

struct idt
{
  uint16 blow;  // lower 16 bits 0-15 of the address to jump to when this interrupt fires
  uint16 segsel;  // code segment selector in GDT
  uint8  zero;  // unused, always be zero
  uint8  type;  // types trap, interrupt gates
  uint16 base_high;  // upper 16 bits 16-31 of the address to jump to
} __attribute__((packed));


struct idtptr
{
   uint16 limsiz;  // limit size of all idt segments
   struct idt* base_address;  // base address of the first idt segment
} __attribute__((packed));

extern struct idt idt_entries[256];
extern struct idtptr idt_first;

extern void init_idt();

#endif
