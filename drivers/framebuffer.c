#include "../boot/multiboot.h"
#include "../kinc/romfont.h"
#include "../libc/atclib.h"
#include "fb.h"
#include "../libc/gcc/stdint-gcc.h"

//Had a hard time finding out all the stuff
//https://github.com/clawbhaiya/discitix_kernel was a good example to learn frambuffer and tty stuff

uint32_t *framebuffer_buffer = NULL;
uint32_t framebuffer_width;
uint32_t framebuffer_height;
uint32_t framebuffer_bpp;
uint32_t framebuffer_pitch;


uint32_t x_cur = 0;
uint32_t y_cur = 0;

int init_fb(multiboot_info_t* mboot){
    framebuffer_buffer = (uint32_t*)((uintptr_t)mboot->framebuffer_addr);
    framebuffer_bpp = mboot->framebuffer_bpp;
    framebuffer_pitch = mboot->framebuffer_pitch;
    framebuffer_height = mboot->framebuffer_height;
framebuffer_width = mboot->framebuffer_width;
    return 1;
}

void fb_put_pixel(uint32_t x, uint32_t y, uint32_t color){
    *(uint32_t*)(x + y * framebuffer_width + framebuffer_buffer) = color;
}

void fb_draw_rect(uint32_t initx, uint32_t inity, uint32_t suspendx, uint32_t suspendy, uint32_t color){
    for(uint32_t i = initx; i <= suspendx; i++){
        fb_put_pixel(i, inity, color);
    }
    for(uint32_t i = inity; i <= suspendy; i++){
        fb_put_pixel(suspendx, i, color);
    }
    for(uint32_t i = suspendx; i >= initx; i--){
        fb_put_pixel(i, suspendy, color);
    }
    for(uint32_t i = suspendy; i >= inity; i--){
        fb_put_pixel(initx, i, color);
    }
}

void fb_backspace(uint32_t clr){
    x_cur--;
    fb_putchar_col(1, clr);
    x_cur--;
}


void fb_putchar_color(char c, uint32_t color){
    uint8_t iy, ix;
    if(c == '\n'){
        x_cur = 0;
        y_cur += 1;
    } else if(c == '\t'){
        x_cur = (x_cur - (x_cur % 8)) + 8;
    }else{
        for(iy = 0; iy < 8; iy++){
            for(ix = 0; ix < 8; ix++){
                if((font[(uint8_t)c][iy] >> ix) & 1){
                    fb_put_pixel(ix + x_cur*FONT_WIDTH, iy + y_cur*FONT_HEIGHT, color);
                }
            }
        }
        x_cur += 1;
    }
    if(x_cur >= framebuffer_width/FONT_WIDTH){
        x_cur = 0;
        y_cur += 1;
    }
}

void fb_putstr_color(char *str, uint32_t color){
    while(*str!=0){
        fb_putchar_col(*str, color);
        str++;
    }
}

void fb_clscr(uint32_t color){
    for(uint32_t i = 0; i < (framebuffer_height * framebuffer_width); i++){
        framebuffer_buffer[i] = color;
    }
    x_cur = 0;
    y_cur = 0;
}

uint32_t fb_getx(){
    return x_cur;
}

uint32_t fb_gety(){
    return y_cur;
}

void fb_setx(uint32_t value){
    x_cur = value;
}

void fb_sety(uint32_t value){
    y_cur = value;
}
