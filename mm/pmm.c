/*
Physical memory manager by Jihwan Ahn
Protected by Apache licence 2.0.
Copyright 2021 Jihwan Ahn
*/

#include "../libc/atclib.h"

#define BPD 32                  //Blocks Per Dword
#define BLOCK_SIZE 4096
#define KB2BLOCK(x) ((x) / 4)

static uint8_t   mem_size;    //Available memory in kilobytes
static uint32_t used_blocks;  //How much blocks are used/4096 blocks?
static uint32_t max_blocks;   //Maximum of used blocks/4096
static uint32_t *pmmap;       //Pysical memory map contaning state of the bitmap 0(free) or 1(used) of each block.
static uint8_t   pmmap_size;  //The size of the bitmap

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
