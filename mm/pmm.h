static uint8_t   mem_size;    //Available memory in kilobytes
static uint32_t used_blocks;  //How much blocks are used/4096 blocks?
static uint32_t max_blocks;   //Maximum of used blocks/4096
static uint32_t *pmmap;       //Pysical memory map contaning state of the bitmap 0(free) or 1(used) of each block.
static uint8_t   pmmap_size;  //The size of the bitmap
