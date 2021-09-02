#include "../libc/atclib.h"
#include "paging.h"

page_table_t page_table_i[1024];
page_dir_t page_dir_i[1024];
page_directory_t page_directory_i[1024];

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

void init_page_dir(page_dir_t page_dir){
	int i;
	for(i=0;i<1024;i++){
		init_page(page_dir.pages[i]);
	}
}
