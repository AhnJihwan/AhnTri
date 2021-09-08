#include "../kernel.h"
#include "../libc/atclib.h"


void apache(){
	printf("                                 Apache License\n                           Version 2.0, January 2004\n                        http://www.apache.org/licenses/");
	printf("\nPermissions\n");
	framebuffer_putchar(251, 0x0e9f68);
	printf(" Commercial use\n");
	framebuffer_putchar(251, 0x0e9f68);
	printf(" Modification\n");
	framebuffer_putchar(251, 0x0e9f68);
	printf(" Distribution\n");
	framebuffer_putchar(251, 0x0e9f68);
	printf(" Patent use\n");
	framebuffer_putchar(251, 0x0e9f68);
	printf(" Private use\n");
	printf("\nLimitations");
	printf("\nx");
	printf(" Trademark use");
	printf("\nx");
	printf(" Liability");
	printf("\nx");
	printf(" Warranty");
	printf("\nx");
	printf(" Trademark use");
	printf("\n\nConditions\n");
	printf("(i)");
	printf(" License and copyright notice");
	printf("\n(i)");
	printf(" State changes");
}

process creditz(){
	printf("    _________     ______   ______     ______       ________  _______\n");
	printf("    |             |    |   |          |     |   *     |      |\n");
	printf("    |             |    |   |          |     |   |     |      |______\n");
	printf("    |             |____|   |_____     |     |   |     |             |\n");
	printf("    |             |  \\     |          |     |   |     |             |\n");
	printf("    |             |   \\    |          |     |   |     |             |\n");
	printf("    |________     |    \\   |_____     |_____|   |     |      _______|\n");
}

void credits(){
	creditz();
	clscr();
	printf(">>>>>>>>>>>AhnTri Hall of fame<<<<<<<<<\n");
	printf("=============Developers================\n");
	printf("Creator: Jihwan Ahn(I am KOREAN guy)\n");
	printf("Developer: Ivan G.\n");
	printf("Developer: Ethan R.\n");
	printf("Developer: Gauravsingh S.\n");
	printf("English Language Pack: Jihwan A. Ivan G. Ethan R.\n");
	printf("Italian Language Pack: Ivan G.\n");
	printf("Korean Language Pack: Jihwan A.");
	printf("Turk Language Pack: Umut Y.\n");
	printf("Thanks to color contributer: Ethan R. Umut Y, Jihwan A. BK A.");
	printf("The Developer's piece of code is protected by the Apache 2.0 licence and it needs warranty from the following code's creator.");
	printf("=======Additional thanks to ...========\n");
	printf("Thank you u/Bob-The-One, u/jtsiomb, and u/Ayush7788!\n");
	printf("Thank you Ayush Yadav for helping for ISRs.");
	printf("u/DeanBurrito for Paging and Page fault help\n");
	suspend(1000);
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
