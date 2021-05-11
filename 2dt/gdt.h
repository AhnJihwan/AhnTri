#ifndef GDT_H
#define GDT_H

#include "../kio/types.h"

#define NS 0
#define CS 1
#define DS 2

struct GDT
{
   uint16 segment_limit;  // segment limit first 0-15 bits
   uint16 base_low;  // base first 0-15 bits
   uint8  base_middle; // base 16-23 bits
   uint8  access;  // access byte
   uint8  granularity;  // high 4 bits (flags) low 4 bits (limit 4 last bits)(limit is 20 bit wide)
   uint8  base_high;  // base 24-31 bits
} __attribute__((packed));


struct GDT_PTR
{
   uint16 limit_size;  // limit size of all GDT segments
   struct GDT* base_address;  // base address of the first GDT segment
} __attribute__((packed));

extern struct GDT gdtent[3];
extern struct GDT_PTR gdt_first;

extern void init_gdt();

#endif



