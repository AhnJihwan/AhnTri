#include "../libc/atclib.h"
#include "paging.h"


void clear_page_directory(uint32_t page_dir[]){
  uint32 i;
  for(i = 0; i < 1024; i++) {
    page_dir[i] = 0x00000002;
  }
}


void clear_page_table(uint32_t page_tble[]){
  uint32 i;
  for(i = 0; i < 1024; i++){
    page_tble[i] = (i * 0x1000) | 3;
  }
}

void ptinpd(uint32_t page_directory[], uint32_t page_table[]){
	page_directory[0] = ((unsigned int)page_table) | 3;
}
