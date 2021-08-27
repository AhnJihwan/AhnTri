#include "paging.h"
#include "../libc/atclib.h"

page_dir_t page_directory[1024] __attribute__((aligned(4096)));

void clear_page_directory(uint32_t page_dir){
  int i;
  for(i = 0; i < 1024; i++) {
    page_dir[i] = 0x00000002;
  }
}

page_table_t page_table[1024] __attribute__((aligned(4096)));

void clear_page_table(uint32_t page_table){
  uint32 i;
  for(i = 0; i < 1024; i++){
    first_page_table[i] = (i * 0x1000) | 3;
  }
}
