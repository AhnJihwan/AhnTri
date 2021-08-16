#include "../libc/atclib.h"

void printf_mmap_addr(multiboot_info_t *mbi, uint32_t mmap_printf, uint32_t end_mmap){
  if(CHECK_FLAG (mbi->flags, 6)){
    printf("memory map adress: 0x");
    print_int((int) mbi->mmap_adrr);
  }
}
