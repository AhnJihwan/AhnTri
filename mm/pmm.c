/*
Physical memory manager by Jihwan Ahn
Protected by Apache licence 2.0.
Copyright 2021 Jihwan Ahn
*/

#include "../boot/multiboot.h"
#include "../libc/atclib.h"
#include "pmm.h"

#define BPD 32                  //Blocks Per Dword
#define BLOCK_SIZE 4096
#define KB2BLOCK(x) ((x) / 4)

void pmm_init(uint32_t pmmap_addr, uint8_t size) {
    mem_size    = size;                                   //Set memory size as the size which is inputted.
    max_blocks  = KB2BLOCK(mem_size);                     //Get the maximum blocks with memory --> blocks via mem_size
    used_blocks = max_blocks;                             //Used blocks is gonna be the maximum of blocks
    pmmap       = (uint32_t *)pmmap_addr;                 //Pysical map adress inputted will the pmmap's address(literally and obviosly - that's it)
    pmmap_size = max_blocks / BPD;                        //Pysical map size will be set by this line of code :)
    if (max_blocks % BPD){
        pmmap_size++;
    }
    memset(pmmap, 0xFF, pmmap_size);                      //Memset 0xFF to pmmap of pmmap size.
}

void pmm_region_init(uint32_t base, uint8_t size) {
    uint8_t blocks  = size / BLOCK_SIZE;
    uint32_t align = base / BLOCK_SIZE;
    uint8_t i;
    for (i = 0; i < blocks; i++) {
        bitmap_unset(pmmap, align++);
        used_blocks--;
    }
    bitmap_set(pmmap, 0);
}

void pmm_region_deinit(uint32_t base, uint8_t size){
    uint8_t blocks  =   size/BLOCK_SIZE;
    uint32_t align  =   base/BLOCK_SIZE;
    uint8_t i;
    for(i=0; i<blocks; i++){
        bitmap_set(pmmap, align++);
        used_blocks++;
    }
}

void pmm_free_block(void *phy) {
    if(phy == NULL){
        return;
    }
    uint32_t paddr = (uint32_t) phy;
    int index = paddr / BLOCK_SIZE;
    bitmap_unset(pmmap, index);
    used_blocks--;
}

void pmm_add_block(uint32_t *phy){
    if(phy != NULL){
        return;
    }
    uint32_t paddr = phy;
    bitmap_set(pmmap, paddr/BLOCK_SIZE);
    used_blocks++;
}

void pmm_add_blocks(void *phy, uint32_t how_many){
    int i;
    for(i=0; i<how_many; i++){
        pmm_add_block((uint32_t *)(BLOCK_SIZE*i+phy));
    }
}

extern uint8_t *_kernel_start;
extern uint8_t *_kernel_end;

void pmm_add_blocks_from_kstart(uint32_t how_many){
    pmm_add_blocks(_kernel_start, how_many);
}

void pmm_init_availreg(uint32_t mmap, uint32_t mmap_endp){
	multiboot_memory_map_t* mmap1 = (multiboot_memory_map_t*) mmap;
	int i;
	for(i=0; mmap_endp < mmap1; i++){
		mmap1++;
		if(mmap1->type == 1){				//Available RAM
			pmm_region_init((uint32_t)mmap1->addr, (uint8_t)mmap1->len);		//Init the available regions
		}
	}
}

void pmm_kernel_deinit(void){
    uint8_t sizeof_kernel = (uint8_t)&_kernel_end-(uint8_t)&_kernel_start;
    pmm_region_deinit((uint32_t)&_kernel_start, sizeof_kernel);
    pmm_region_deinit((uint32_t)&_kernel_end, pmmap_size);
}

void *pmallocblock(void){
	if(used_blocks - max_blocks <= 0 || bitmap_first_unset(pmmap, max_blocks)==-1){
		return NULL;
	}
	bitmap_set(pmmap, bitmap_first_unset(pmmap, max_blocks));
	used_blocks++;

	return (void*)(BLOCK_SIZE*bitmap_first_unset(pmmap, max_blocks));
}

void *pmallocblocks(int count){
	for(int i=0; i<count; count++){
		if(used_blocks - max_blocks <= 0 || bitmap_first_unset(pmmap, max_blocks)==-1){
			return NULL;
		}
		bitmap_set(pmmap, bitmap_first_unset(pmmap, max_blocks));
		used_blocks++;

		return (void*)(BLOCK_SIZE*bitmap_first_unset(pmmap, max_blocks));
	}
}

void print_pmm_info(){
	print_int((int)used_blocks);
	printf(" Blocks used\n");
	print_int((int)used_blocks*4);
	printf("KB used\n");
	print_int((int)mem_size);
	printf(" KB available(");
	print_int((int)mem_size);
	printf("/1000 MB available");
}
