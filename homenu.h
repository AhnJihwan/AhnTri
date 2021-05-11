#include "drivers/kb/keyboard.h"
void gui(){
	int guis;
        while(1){
            os_print_color("\n", BLACK, BLACK);
            guis = read_int();
            switch(guis){
          	case 1:
            		ccalc();
              		break;
         	case 2:
              		osver();
               		break;
            	case 3:
               		clscr();
               		break;
            	case 4:
			exit();
			break;
          	case 99:
            		kernmain();
              		break;
      		case 5:
        		cputest();
        		break;
      		case 6:
        		notes();
        		break;
      		case 7:
        		pedx();
        		break;
      		case 8:
        		ahntroid();
        		break;
      		case 9:
        		fbomb();
        		break;
      		case 10:
        		kernmain();
        		break;
		default:
			homem();
		}
	}
}
void homem(){
	clear_screen();
	os_print_color("/\\ :: \t | \t | \t                                                       AhnTri GeX ", BLACK, WHITE);  //Like KeX and DeX
	os_print_color("\n 1 for CCALC      ", WHITE, CYAN);
	os_print_color(" GeX: GUI Experience ", WHITE, GREY);
        os_print_color("\n 2 for OSVER      ", WHITE, CYAN);
	os_print_color(" Input a number and  ", WHITE, GREY);
        os_print_color("\n 3 for CLSCR      ", WHITE, CYAN);
	os_print_color(" enter ENTER to run. ", WHITE, GREY);
        os_print_color("\n 4 for EXIT       ", WHITE, CYAN);
	os_print_color("      AhnTri News    ", WHITE, GREY);
        os_print_color("\n 5 for CPU TEST   ", WHITE, CYAN);
	os_print_color(" =+=+=+=+=+=+=+=+=+= ", WHITE, GREY);
        os_print_color("\n 6 for NoteTaker  ", WHITE, CYAN);
	os_print_color(" AhnTroid Arrives @  ", WHITE, GREY);
        os_print_color("\n 7 for EDX value  ", WHITE, CYAN);
	os_print_color(" AhnTri OS.          ", WHITE, GREY);
        os_print_color("\n 8 for AhnTroid   ", WHITE, CYAN);
	os_print_color(" AhnGUI arrives AhnT ", WHITE, GREY);
	os_print_color("\n 9 for fork bomb  ", WHITE, CYAN);
	os_print_color(" ri OS               ", WHITE, GREY);
        os_print_color("\n10 for NumDOS     ", WHITE, CYAN);
	os_print_color("                     ", WHITE, GREY);
	gui();
}


