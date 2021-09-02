#include "../libc/atclib.h"
#include "paging.h"

page_table_t page_table_i[1024];

void init_page_table(page_t *page){
  int i;
  for(i=0; i<1024; i++){
    page->present = 1;
    page_table->readwrite = 1;
    page_table->usersupervisor = 1;
    page_table->writethrough = 1;
    page_table->cachedisabled = 0;
    page_table->accessed = 0;
    page_table->dirty = 0;
    page_table->dirty = 0;
    page_table->pat = 0;
    page_table->global = 0;
  }
}
