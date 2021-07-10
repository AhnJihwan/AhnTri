#include "../boot/multiboot.h"
#include "../libc/atclib.h"
#include "tty.h"
#include "fb.h"
#include "../libc/gcc/stdint-gcc.h"
uint32_t current_fg;
uint32_t current_bg;

int init_tty(multiboot_info_t *mbootptr, uint32_t fg, uint32_t bg){
	int status = init_fb(mbootptr);
	current_fg = fg;
	current_bg = bg;
	tty_clscr(bg);
	return status;
}

void tty_putchar_color(char c, uint32_t color){
	if(c == '\b')
		fb_backspace(current_bg);
	else
		fb_putchar_color(c, color);
}

void tty_putstr_color(const char *str, uint32_t color){
	while(*str != 0){
		fb_putchar_color(*str, color);
		str++;
	}
}


void tty_putchar(char c){
	tty_putchar_color(c, current_fg);
}

void tty_putstr(const char *str){
	tty_putstr_color(str, current_fg);
}

void tty_setx(uint32_t value){
	if(tty_cursor(2) == 1) return;
	fb_setx(value);
}

void tty_sety(uint32_t value){
	if(tty_cursor(2) == 1) return;
	fb_sety(value);
}

uint32_t tty_getx(){
	return (uint32_t)fb_getx();
}

uint32_t tty_gety(){
	return (uint32_t)fb_gety();
}

void tty_setbg(uint32_t color){
	current_bg = color;
}

void tty_setfg(uint32_t color){
	current_fg = color;
}

uint32_t tty_fg(){
	return current_fg;
}

uint32_t tty_bg(){
	return current_bg;
}

void tty_clscr(uint32_t color){
	fb_clscr(color);
}

int tty_cursor(int status){
	static int Locked = 0;
	if(status == 1)
		Locked = 1;
	else if(status == 0)
		Locked = 0;
	else if(status > 1)
		return Locked;
	return Locked;
}
