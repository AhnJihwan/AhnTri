#include "../libc/atclib.h"
#include "paging.h"

uint32_t page_table_i;

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


void init_page_table(page_table_t page_table){
	int i;
	for(i=0;i<1024;i++){
		init_page(page_table.pages[i]);
	}
}

page_dir_t page_dir_i[1024];
