
#include "../libc/atclib.h"
#include "paging.h"

void *va2pa(void *vaddr, int a) {
	unsigned long output;
	unsigned long pdei = (unsigned long)vaddr >> 22;
	unsigned long ptei = (unsigned long)vaddr >> 12 & 0x3FF;
	unsigned long offset = (unsigned long)vaddr & 0xFFF;
	if(a==1){						//Page Directory Entry Index
		output = pdei;
		return output;
	}else if(a==2){				//Page Table Entry Index
		output = ptei;
		return output;
	}else if(a==3){				//Offset
		output = offset;
		return offset;
	}
}

/*
void init_page(page_t page){
	int i;
	page.present = 1;
	page.readwrite = 1;
	page.usersupervisor = 1;
	page.writethrough = 1;
	page.cachedisabled = 0;
	page.accessed = 0;
	page.dirty = 0;
	page.dirty = 0;
	page.pat = 0;
	page.global = 0;
}
*/
/*
void init_page(page_t page){
	int i;
	page.present = 0;
	page.readwrite = 0;
	page.usersupervisor = 0;
	page.writethrough = 0;
	page.cachedisabled = 0;
	page.accessed = 0;
	page.dirty = 0;
	page.dirty = 0;
	page.pat = 0;
	page.global = 0;
}

void init_page_table(page_table_t page_table){
	int i;
	for(i=0;i<1024;i++){
		init_page(page_table.pages[i]);
	}
}

void init_page_dir(page_dir_t page_dir){
	int i;
	for(i=0;i<1024;i++){
		init_page(page_dir.pages[i]);
	}
}
*/




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
