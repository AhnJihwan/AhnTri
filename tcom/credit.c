#include "../kernel.h"
#include "../init/api.h"

void apache(){
	printf("                                 Apache License\n                           Version 2.0, January 2004\n                        http://www.apache.org/licenses/");
	os_print_color("\nPermissions\n", WHITE, BLACK);
	os_color_char(251, GREEN, BLACK);
	os_print_color(" Commercial use\n", WHITE, BLACK);
	os_color_char(251, GREEN, BLACK);
	os_print_color(" Modification\n", WHITE, BLACK);
	os_color_char(251, GREEN, BLACK);
	os_print_color(" Distribution\n", WHITE, BLACK);
	os_color_char(251, GREEN, BLACK);
	os_print_color(" Patent use\n", WHITE, BLACK);
	os_color_char(251, GREEN, BLACK);
	os_print_color(" Private use\n", WHITE, BLACK);
	os_print_color("\nLimitations", WHITE, BLACK);
	os_print_color("\nx", RED, BLACK);
	os_print_color(" Trademark use", WHITE, BLACK);
	os_print_color("\nx", RED, BLACK);
	os_print_color(" Liability", WHITE, BLACK);
	os_print_color("\nx", RED, BLACK);
	os_print_color(" Warranty", WHITE, BLACK);
	os_print_color("\nx", RED, BLACK);
	os_print_color(" Trademark use", WHITE, BLACK);
	os_print_color("\n\nConditions\n", WHITE, BLACK);
	os_print_color("(i)", BRIGHT_BLUE, BLACK);
	os_print_color(" License and copyright notice", WHITE, BLACK);
	os_print_color("\n(i)", BRIGHT_BLUE, BLACK);
	os_print_color(" State changes", WHITE, BLACK);
}


void credits(){
	printf(">>>>>>>>>>>AhnTri Hall of fame<<<<<<<<<\n");
	printf("=============Developers================\n");
	printf("Creator: Jihwan Ahn(I am KOREAN guy)\n");
	printf("Developer: Ivan G.\n");
	printf("The Developer's piece of code is protected by the Apache 2.0 licence and it needs warranty from the following code's creator.");
	printf("=======Additional thanks to ...========\n");
	printf("BK Ahn(Dad gave me some money)\n");
	printf("Ethan Recendez(friend in US who made the first Fish Dictionary together(2017))\n");
	printf("u/fir4rfin for README.md typo\n");
	printf("My math (academy) teacher (SJ Kim) helped me in factorial\n");
	printf("I saw the osdev wiki ");
	os_print_color("https://wiki.osdev.org/Main_Page\n", BLUE, BLACK);
	printf("==Stargazers, who make AhnTri AhnTri.==\n");
	printf("parsa011, He lives in Iran\n");
	printf("Riahiamirreza Joined on Aug 26, 2019\n");
	printf("BOBBYWY Joined on Apr 2, 2015\n");
	printf("unsafecast Joined on Dec 18, 2020\n");
	printf("ehalferty who lives in San Francisco, CA\n");
	printf("dreamos82 who lives in Dublin\n");
	printf("programmeruser2 who lives in /dev/tty\n");
	printf("0xdeit who lives in Mexico\n");
	printf("growlnx who lives in Rio de Janeiro, Brazil\n");
	printf("AhnJihwan who lives in Seoul, South Korea\n");
	printf("Thank you for all, who helped me XD! \nMay you be in AhnTri...\n[a] for Return, [b] for Apache 2.0 licence");
	char licnce = KEY_A;
	licnce = get_input_keycode();
	if(licnce == KEY_A){
		clscr();
		kernmain();
	} else if(licnce == KEY_B){
		clscr();
		apache();
	} else{
		clscr();
		kernmain();
	}
}
