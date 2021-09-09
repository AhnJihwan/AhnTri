/*
Physical memory manager by Jihwan Ahn
Protected by Apache licence 2.0.
Copyright 2021 Jihwan Ahn
*/

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


void pmm_free_block(void *phy) {
    if(phy == NULL){
        return;
    }
    uint32_t paddr = (uint32_t) phy;
    int index = paddr / BLOCK_SIZE;
    bitmap_unset(pmmap, index);
    used_blocks--;
}
