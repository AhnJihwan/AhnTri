#include "../init/stdio.h"
#include "isr.c"
#include "idt.h"

struct idt idt_entries[16];
struct idtptr idt_first;

extern void load_idt(struct idt*);

void set_idt_gate(int intnum, uint32 isr)
{
  idt_entries[intnum].blow = (isr & 0xFFFF);
  idt_entries[intnum].segsel = 0x08;
  idt_entries[intnum].zero = 0;
  idt_entries[intnum].type = 0x8E;
  idt_entries[intnum].base_high = (isr >> 16) & 0xFFFF;
}

void init_idt()
{
  set_idt_gate(0, (uint32)isr_0);
  set_idt_gate(1, (uint32)isr_1);
  set_idt_gate(2, (uint32)isr_2);
  set_idt_gate(3, (uint32)isr_3);
  set_idt_gate(4, (uint32)isr_4);
  set_idt_gate(5, (uint32)isr_5);
  set_idt_gate(6, (uint32)isr_6);
  set_idt_gate(7, (uint32)isr_7);
  set_idt_gate(8, (uint32)isr_8);
  set_idt_gate(9, (uint32)isr_9);
  set_idt_gate(10, (uint32)isr_10);
  set_idt_gate(11, (uint32)isr_11);
  set_idt_gate(12, (uint32)isr_12);
  set_idt_gate(13, (uint32)isr_13);
  set_idt_gate(14, (uint32)isr_14);
  set_idt_gate(15, (uint32)isr_15);
  set_idt_gate(20, (uint32)isr_20);
  set_idt_gate(21, (uint32)isr_21);
  set_idt_gate(22, (uint32)isr_22);
  set_idt_gate(23, (uint32)isr_23);
  set_idt_gate(24, (uint32)isr_24);
  set_idt_gate(25, (uint32)isr_25);
  set_idt_gate(26, (uint32)isr_26);
  set_idt_gate(27, (uint32)isr_27);
  set_idt_gate(28, (uint32)isr_28);
  set_idt_gate(29, (uint32)isr_29);
  set_idt_gate(30, (uint32)isr_30);
  set_idt_gate(31, (uint32)isr_31);

  idt_first.limsiz = sizeof(idt_entries) - 1;
  idt_first.base_address = (struct idt*)&idt_entries;

  load_idt((struct idt*)&idt_first);
}

