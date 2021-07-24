#include "../boot/multiboot.h"
#include "../libc/gcc/stdint-gcc.h"
#include "../libc/types/ctypes.h"
#include "../kinc/qemu.h"
#include "romfont.h"

multiboot_uint32_t* framebuffer_buffer;
multiboot_uint32_t framebuffer_bpp;
multiboot_uint32_t framebuffer_pitch;
multiboot_uint32_t framebuffer_height;
multiboot_uint32_t framebuffer_width;

uint32_t cur_x = 0;
uint32_t cur_y = 0;

//Define Macros
#define CHECK_FLAG(flags,bit)   ((flags) & (1 << (bit)))
#define FONT_HEIGHT 8
#define FONT_WIDTH 8
int framebuffer_check(multiboot_info_t* multiboot){
  int framebuffer_type;
  if (CHECK_FLAG (multiboot->flags, 12)){
    suspend(1);
    qemu_printf_string("Framebuffer flags(12) checked! \\/");
    switch (multiboot->framebuffer_type){
      case MULTIBOOT_FRAMEBUFFER_TYPE_RGB:
        qemu_printf_string("Framebuffer type is rgb");
        framebuffer_type = 1;
        return framebuffer_type;
    }
    return framebuffer_type;
  }
  return framebuffer_type;
}

int init_framebuffer(multiboot_info_t* mbi){
  if(framebuffer_check(mbi)==1){
    framebuffer_buffer = (uint32_t*)((uintptr_t)mbi->framebuffer_addr);
    framebuffer_bpp = mbi->framebuffer_bpp;
    framebuffer_pitch = mbi->framebuffer_pitch;
    framebuffer_height = mbi->framebuffer_height;
    framebuffer_width = mbi->framebuffer_width;
  }
}

void framebuffer_putpixel(uint32_t x, uint32_t y, uint32_t color){  /*this plots a single pixel to the given coordinates with the given color*/
    *(uint32_t*)(x + y * framebuffer_width + framebuffer_buffer) = color;
}

void framebuffer_putchar(char ch, uint32_t color){
  uint8_t xx, yy;
  if(ch=="\n"|cur_x>=framebuffer_width/FONT_WIDTH){
    cur_x=0;
    cru_y+=1;
  }else{
    for(xx=0;xx<8;xx++){
      for(yy=0;yy<8;yy++){
        framebuffer_putpixel(xx + cur_x*FONT_WIDTH, yy + cur_y*FONT_HEIGHT, color);
      }
    }
    cur_x += 1;
  }
}
