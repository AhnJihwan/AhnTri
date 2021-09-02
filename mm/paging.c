#include "../libc/atclib.h"
#include "paging.h"

page_table_t page_table_i[1024];

int init_page_table(page_table_t page_table){
  int i;
  for(i=0; i<1024; i++){
    page_table[i].present = 1;
    page_table[i].readwrite = 1;
    page_table[i].usersupervisor = 1;
    page_table[i].writethrough = 1;
    page_table[i].cachedisabled = 0;
    page_table[i].accessed = 0;
    page_table[i].dirty = 0;
    page_table[i].dirty = 0;
    page_table[i].pat = 0;
    page_table[i].global = 0;
  }
}
