#ifndef KERNEL_H
#define KERNEL_H

#include "libc/types/ctypes.h"

#define NULL 0

#define VGA_ADDRESS 0xB8000
#define BUFSIZE 2200

uint16* vga_buffer;

enum vga_color {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};

#define BLACK            0x000000
#define BLUE             0x013571
#define GREEN            0x015229
#define CYAN             0x7fa49d
#define RED              0xf70f0f
#define MAGENTA          0x741b47
#define BROWN            0x8d6b00
#define GREY             0x999999
#define DARK_GREY        0x8f8f8f
#define BRIGHT_BLUE      0x65abe7
#define BRIGHT_GREEN     0xa3bd8d
#define BRIGHT_CYAN      0x00ffff
#define BRIGHT_RED       0xff5555
#define BRIGHT_MAGENTA   0xba9da2
#define YELLOW           0xeaa442
#define WHITE            0xffffff

#include "drivers/kb/keyboard.h"


#endif
