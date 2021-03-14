// include files by #include <neccessary file>
#include "../kernel.h"
#include "../kio/char.h"
#include "tinit_vmpc.h"
#include "../tcom/ccalcfi.h"
#include "../tcom/osver.h"
#include "../tcom/clscr.h"
#include "../tcom/cpu/ports.h"
#include "../tcom/exit.h"
#include "../tcom/cpuid.h"
#include "../tcom/note.h"
#include "../tcom/edxview.h"
#include "../tcom/help.h"
#include "../tcom/cbot.h"
#include "../tcom/forker.h"
#include "../tcom/timermode.h"
#include "../tcom/mem.h"
#include "../tcom/game.h"
#include "new.h"
#include "../homenu.h"
#include "../kio/types.h"
#include "gdt.h"
#include "../AhnLibc/mem.h"

void display_menu()
{
  gotoxy(25, 0);
  os_print_color("\n                          ", BLACK, CYAN);
  os_print_color("-", YELLOW, BLACK);
  os_print_color("+", GREEN, BLACK);
  os_print_color("x", RED, BLACK);
  os_print_color("\n      AhnTri Terminal        ", BLACK, WHITE);
  os_print_color("\n  -~=-~=~--~=~--~=~--~=~-=-  ", BLACK, WHITE);
  os_print_color("\n   Type help for help or o   ", BLACK, WHITE);
  os_print_color("\n   ther key for each apps.   ", BLACK, WHITE);
  os_print_color("\n                             ", BLACK, WHITE);
}

void kernmain(){
	char * choice;
	display_menu();
	while(1){
		printf("\n\n@kern~");
		print_char(30);
		printf(" ");
		choice = read_char();
		if(strcmp(choice, "help")==0){
			help();
		} else if(strcmp(choice, "ccalc")==0 || strcmp(choice, "calc")==0){
			ccalc();
		} else if(strcmp(choice, "osver")==0 || strcmp(choice, "atfetch")==0){
			osver();
		} else if(strcmp(choice, "clscr")==0 || strcmp(choice, "clear")==0 || strcmp(choice, "cls")==0){	//just 4 ppl who are used to dos
			clscr();
		} else if(strcmp(choice, "halt")==0 || strcmp(choice, "shutdown")==0){
			shutdown();
		} else if(strcmp(choice, "cputest")==0 || strcmp(choice, "cpuid")==0){					//The real name of it was cpuid
			cputest();
		} else if(strcmp(choice, "notes")==0){
			notes();
		} else if(strcmp(choice, "pedx")==0){
			pedx();
		} else if(strcmp(choice, "atfork")==0){
			fbomb();
		} else if(strcmp(choice, "homenu")==0){
			homem();
		} else if(strcmp(choice, "timer")==0){
			timer();
		} else if(strcmp(choice, "memor")==0){
			memanset();
		} else if(strcmp(choice, "mp")==0){
			memprintf();
		} else if(strcmp(choice, "game")==0){
			game();
		} else if(strcmp(choice, "atroid")==0 || strcmp(choice, "ai")==0){
			ahntroid();
		}else{
			printf("\n");
			printf(choice);
			printf(": command not found");

		}
	}
}

void mkern_main()
{
  init_gdt();
  init_vga(CYAN, BLACK);
  newmain();
}