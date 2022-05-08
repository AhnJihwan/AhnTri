#include "atlogo.h"

void draw_logo(uint32_t startpointx, uint32_t startpointy) {
	char pixel[4];
	for (uint32_t y = 0; y < height; y++) {
		for(uint32_t x = 0; x < width; x++) {
			HEADER_PIXEL(header_data, pixel); 
			pixel[3] = 0;
			uint32_t num = (uint32_t) pixel[0] << 24 |
			(uint32_t)pixel[1] << 16 |
			(uint32_t)pixel[2] << 8	|
			(uint32_t)pixel[3];
			framebuffer_putpixel(startpointx + x, startpointy + y, num);
		}
	}
}

void strt_scrn(){
	draw_logo(105, 0);
	suspend(4);
	gotoxy(25, 45);
	printf("Freedom of your life.\n\n\n");
	suspend(4);
	gotoxy(25, 48);
	printf("System is starting...\n\n\n");
	gotoxy(28, 50);
	printf("");
	print_char(176);
	suspend(1);
	print_char(177);
	suspend(1);
	print_char(178);
	suspend(1);
	print_char(219);
	suspend(1);
	print_char(178);
	suspend(1);
	print_char(177);
	suspend(1);
	print_char(176);
	gotoxy(28, 50);
	printf("");
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	gotoxy(28, 50);
	printf("");
	print_char(176);
	suspend(1);
	print_char(177);
	suspend(1);
	print_char(178);
	suspend(1);
	print_char(219);
	suspend(1);
	print_char(178);
	suspend(1);
	print_char(177);
	suspend(1);
	print_char(176);
	gotoxy(28, 50);
	printf("");
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	gotoxy(28, 50);
	printf("");
	print_char(176);
	suspend(1);
	print_char(177);
	suspend(1);
	print_char(178);
	suspend(1);
	print_char(219);
	suspend(1);
	print_char(178);
	suspend(1);
	print_char(177);
	suspend(1);
	print_char(176);
	gotoxy(28, 50);
	printf("");
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	gotoxy(28, 50);
	printf("");
	print_char(176);
	suspend(1);
	print_char(177);
	suspend(1);
	print_char(178);
	suspend(1);
	print_char(219);
	suspend(1);
	print_char(178);
	suspend(1);
	print_char(177);
	suspend(1);
	print_char(176);
	gotoxy(28, 50);
	printf("");
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
	suspend(1);
	framebuffer_putchar(219, 0x000000);
}
