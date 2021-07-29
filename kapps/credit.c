#include "../kernel.h"
#include "../libc/atclib.h"


void apache(){
	printf("                                 Apache License\n                           Version 2.0, January 2004\n                        http://www.apache.org/licenses/");
	printf("\nPermissions\n");
	framebuffer_putchar(251, 0x015229);
	printf(" Commercial use\n");
	framebuffer_putchar(251, 0x015229);
	printf(" Modification\n");
	framebuffer_putchar(251, 0x015229);
	printf(" Distribution\n");
	framebuffer_putchar(251, 0x015229);
	printf(" Patent use\n");
	framebuffer_putchar(251, 0x015229);
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
	printf("The Developer's piece of code is protected by the Apache 2.0 licence and it needs warranty from the following code's creator.");
	printf("English Language Pack: Jihwan A. Ivan G. Ethan R.\n");
	printf("Spanish Language Pack: Atie P.\n");
	printf("Korean Language Pack: Jihwan A.");
	printf("Turk Language Pack: Umut Y.\n");
	printf("=======Additional thanks to ...========\n");
	printf("BK Ahn(Computer)\n");
	printf("Ethan Recendez and Justin Y.(made the first Fish Dictionary(2017) with core dev)\n");
	printf("u/fir4rfin for typos\n");
	printf("SJ Kim helped me in factorial\n");
	printf("OSDev Wiki");
	printf("https://wiki.osdev.org/Main_Page\n");
	printf("Ivan G. helped me for QEMU serial ports.\n");
	printf("https://www.geeksforgeeks.org/ for Log inspiration\n");
	printf("E.S Lee (lending PC for real PC iso file)\n");
	printf("Thank you u/Bob-The-One, u/jtsiomb, and u/Ayush7788!\n");
	printf("Thank you Ayush Yadav for helping for ISRs.");
	printf("James Molloy's OSDEv tutorials");
	printf("www.jamesmolloy.co.uk\n");
	printf("==Stargazers, who make AhnTri AhnTri.==\n");
	printf("Parsa Mahmoudy who lives in Iran\n");
	printf("Riahiamirreza Joined on Aug 26, 2019\n");
	printf("BOBBYWY Joined on Apr 2, 2015\n");
	printf("Thanks to color contributer: Ethan R. Umut Y, Jihwan A. BK A.");
	suspend(1000);
	clscr();
	printf("==Stargazers, who make AhnTri AhnTri.==\n");
	printf("unsafecast Joined on Dec 18, 2020\n");
	printf("ehalferty who lives in San Francisco, CA\n");
	printf("Ivan Gualandri who lives in Dublin\n");
	printf("programmeruser2 who lives in /dev/tty\n");
	printf("Diego Garza who lives in Mexico\n");
	printf("growlnx who lives in Rio de Janeiro, Brazil\n");
	printf("Sanchit Kalra who lives in Chandigarh, India\n");
	printf("scpmx who Joined on August 1, 2015\n");
	printf("Thesodadrinkerswho lives in Los Angeles, CA - Justin Y.\n");
	printf("CyborgXB4ing who Joined on May 13, 2021\n");
	printf("CaydendW who lives in South Africa\n");
	printf("DamieFC\n");
	printf("owtla who lives in Los Angeles, CA USA");
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
