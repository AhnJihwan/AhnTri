//Advanced terminal&NewMain Menu

void newmain(){
	char capps = KEY_A;
	gotoxy(25, 0);
	os_print_color("AhnTri Applications Execute Menu\n", WHITE, BLACK);
	printf("  ");
	os_print_color("Choose an application to continue...                                        \n", BLACK, CYAN);
	printf(" ");
	os_color_char(178, GREY, BLACK);
	os_print_color("[a] AhnTri Terminal Interface                                               \n", BLACK, CYAN);
	printf(" ");
	os_color_char(178, GREY, BLACK);
	os_print_color("[b] AhnTri C Calulator                                                      \n", BLACK, CYAN);
	printf(" ");
	os_color_char(178, GREY, BLACK);
	os_print_color("[c] AhnTri Memory Set                                                       \n", BLACK, CYAN);
	printf(" ");
	os_color_char(178, GREY, BLACK);
	os_print_color("[d] AhnTri Memory Print                                                     \n", BLACK, CYAN);
	printf(" ");
	os_color_char(178, GREY, BLACK);
	os_print_color("[e] CPU ID                                                                  \n", BLACK, CYAN);
	printf(" ");
	os_color_char(178, GREY, BLACK);
	os_print_color("[f] AhnTroid AI Assistant                                                   \n", BLACK, CYAN);
	printf(" ");
	os_color_char(178, GREY, BLACK);
	os_print_color("[g] AhnTri Notetaker                                                        \n", BLACK, CYAN);
	printf(" ");
	os_color_char(178, GREY, BLACK);
	os_print_color("[h] AhnTri Apps(NumDOS/GeX) menu                                            \n", BLACK, CYAN);
	printf(" ");
	os_color_char(178, GREY, BLACK);
	os_print_color("[i] AhnTri Timer                                                            \n", BLACK, CYAN);
	printf(" ");
	os_color_char(178, GREY, BLACK);
	os_print_color("[j] Halt the CPU(Shutdown)                                                  \n", BLACK, CYAN);
	printf(" ");
	os_color_char(178, GREY, BLACK);
	os_print_color("                                                                            \n", BLACK, CYAN);
	printf(" ");
	os_color_char(178, GREY, BLACK);
	os_print_color("Copyright 2021 Jihwan Ahn                                                   \n", BLACK, CYAN);
	printf(" ");
	os_color_char(178, GREY, BLACK);
	#include "nd.h"
	ndraw();
	capps = get_input_keycode();
	if(capps == KEY_A){
		clscr();
		kernmain();
	} else if(capps == KEY_B){
		clscr();
		ccalc();
	} else if(capps == KEY_C){
		clscr();
		memanset();
	} else if(capps == KEY_D){
		clscr();
		memprintf();
	} else if(capps == KEY_E){
		clscr();
		cputest();
	} else if(capps == KEY_F){
		clscr();
		ahntroid();
	} else if(capps == KEY_G){
		clscr();
		notes();
	} else if(capps == KEY_H){
		clscr();
		homem();
	} else if(capps == KEY_I){
		clscr();
		timer();
	} else if(capps == KEY_J){
		clscr();
		shutdown();
	} else{
		kernmain();
	}
}