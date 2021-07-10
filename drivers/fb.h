#ifndef _fb_H_
#define _fb_H_

#define FONT_HEIGHT    8
#define FONT_WIDTH     8
#include "../boot/multiboot.h"
extern uint32_t* fb_buffer;
int init_fb(multiboot_info_t* mboot);
void fb_put_pixel(uint32_t x, uint32_t y, uint32_t color);
void fb_draw_rect(uint32_t initx, uint32_t inity, uint32_t suspendx, uint32_t suspendy, uint32_t color);
void fb_putchar_color(char c, uint32_t color);
void fb_putstr_color(char *str, uint32_t color);
void fb_backspace(uint32_t color);
uint32_t fb_getx();
uint32_t fb_gety();
void fb_setx(uint32_t value);
void fb_sety(uint32_t value);
void fb_cls(uint32_t color);
#endif /* fb.h */
