#include "gcc/stdint-gcc.h"
#include "types/ctypes.h"
#define OS_suspend 16
#define NULL 0
//String
extern uint32 strlen(const char*);
extern long stoi(const char *s);
extern uint32 digit_count(int num);
extern int atoui(char* s);
extern int strcmp(char str1[], char str2[]);
extern int strrlen(const char* str);
//Math
extern int powt(int a);
extern int powth(int a);
extern int powf(int a);
extern int powfi(int a);
extern int addnpth(int a, int b);
extern int sqrt(int number);
extern int quareq_r1(int a, int b, int c);
extern int quareq_r2(int a, int b, int c);
extern int factorial(int n);
extern int xpy(int x, int y);
extern int log(int a, int b);
extern int LOGICAL(char *l, int a, int b);
//Advanced math
extern int kb2mb(int kb);
extern int mb2gb(int mb);
extern int cel2far(int c);
extern int kg2lb(int kg);
extern int lb2kg(int lb);
extern int in2cm(int in);
extern int cm2in(int cm);
//Memory
extern void free(void *mem);
extern void memcpy(void *dest, void *src, signed n);
//Stdio
extern uint16 vga_entry(unsigned char ch, uint8 fg_color, uint8 bg_color) ;
extern void clear_vga_buffer(uint16 **buffer, uint8 fg_color, uint8 bg_color);
extern void clear_screen();
extern void init_vga(uint8 fg_color, uint8 bg_color);
extern uint8 inb(uint16 port);
extern void outb(uint16 port, uint8 data);
extern void movcur(uint16 pos);
extern void movcur_next_line();
extern void gotoxy(uint16 x, uint16 y);
extern char get_input_keycode();
extern void wait_for_io(uint32 timer_count);
extern void suspend(uint32 timer_count);
extern void print_new_line();
extern void print_char(char ch);
extern void print_char_notepad(char ch);
extern void printf(char *str);
extern void os_print_color(char *str, uint8 fore_color, uint8 back_color);
extern void os_color_char(char ch, uint8 fore_color, uint8 back_color);
extern void print_int(int num);
extern int read_char();
extern int read_int();
extern int read_uint();
extern char getchar();
extern void strcpy(char dest[], const char source[]);
extern void itoa(int num, char *number);
extern int atoi(char* s);
