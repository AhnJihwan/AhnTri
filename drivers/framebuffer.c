#include "boot/multiboot.h"

//Define Macros
#define CHECK_FLAG(flags,bit)   ((flags) & (1 << (bit)))

void framebuffer_check(multiboot_info_t* multiboot){
  if (CHECK_FLAG (multiboot->flags, 12)){
    suspend(1);
    qemu_printf_string("Framebuffer flags(12) checked! \\/");
    switch (mbi->framebuffer_type){
      case MULTIBOOT_FRAMEBUFFER_TYPE_RGB:
        qemu_printf_string("Framebuffer type is rgb");
    }
  }
}

void init_framebuffer(multiboot_info_t* mbi){
  multiboot_uint32_t color;
  unsigned i;
  void *fb = (void *) (unsigned long) mbi->framebuffer_addr;
}
