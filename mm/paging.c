#include "paging.h"

page_dir_t page_directory[1024] __attribute__((aligned(4096)));

void clear_page_directory(uint32_t page_dir){
  int i;
  for(i = 0; i < 1024; i++) {
    page_dir[i] = 0x00000002;
  }
}
