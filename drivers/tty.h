#ifndef _TTY_H_
#define _TTY_H_
#include "../boot/multiboot.h"
int init_tty(multiboot_info_t *mbootptr, uint32_t fg_color, uint32_t bg_color);
void tty_putchar_color(char c, uint32_t color);
void tty_putstr_color(const char *str, uint32_t color);
void tty_putchar(char c);
void tty_putstr(const char *str);
void tty_setx(uint32_t value);
void tty_sety(uint32_t value);
uint32_t tty_getx();
uint32_t tty_gety();
uint32_t tty_fg();
uint32_t tty_bg();
void tty_setfg();
void tty_setbg();
void tty_clscr(uint32_t color);
int tty_cursor(int status);

#endif /* tty.h */
