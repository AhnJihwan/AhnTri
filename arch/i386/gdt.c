#include "gdt.h"

struct GDT gdtent[3];
struct GDT_PTR gdt_first;

extern void load_gdt(struct GDT*);

void init_gdt()
{
  // set null segment
  gdtent[NS].segment_limit = 0;
  gdtent[NS].base_low = 0;
  gdtent[NS].base_middle = 0;
  gdtent[NS].access = 0;
  gdtent[NS].granularity = 0;
  gdtent[NS].base_high = 0;

  // set code segment
  gdtent[CS].segment_limit = 0xffff;
  gdtent[CS].base_low = 0;
  gdtent[CS].base_middle = 0;
  gdtent[CS].access = 0x9a;
  gdtent[CS].granularity = 0b11001111;
  gdtent[CS].base_high = 0;

  // set data segment
  gdtent[DS].segment_limit = 0xffff;
  gdtent[DS].base_low = 0;
  gdtent[DS].base_middle = 0;
  gdtent[DS].access = 0x92;
  gdtent[DS].granularity = 0b11001111;
  gdtent[DS].base_high = 0;


  gdt_first.limit_size = sizeof(gdtent) - 1;
  gdt_first.base_address = (struct GDT*)&gdtent;

  load_gdt((struct GDT*)&gdt_first);

}



