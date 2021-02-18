// include files by #include <neccessary file>
#include "kernel.h"
#include "kio/utils.h"
#include "kio/char.h"
#include "init/tinit_rpc.h"
#include "tcom/ccalcfi.h"
#include "tcom/osver.h"
#include "tcom/clscr.h"
#include "tcom/exit.h"
#include "tcom/cpuid.h"
#include "tcom/note.h"
#include "tcom/edxview.h"
#include "tcom/help.h"
#include "tcom/cbot.h"
#include "tcom/forker.h"
#include "homenu.h"

void display_menu()
{
  gotoxy(25, 0);
  os_print_color("\n                          ", BLACK, CYAN);
  os_print_color("-", YELLOW, BLACK);
  os_print_color("+", GREEN, BLACK);
  os_print_color("\t", RED, BLACK);
  os_print_color("\n    AhnTri Terminal 1.2      ", BLACK, WHITE);
  os_print_color("\n  -~=-~=~--~=~--~=~--~=~-=-  ", BLACK, WHITE);
  os_print_color("\n   Type help for help or o   ", BLACK, WHITE);
  os_print_color("\n   ther key for each apps.   ", BLACK, WHITE);
  os_print_color("\n   Copyright 2021 Jihwan Ahn ", BLACK, WHITE);
}

void kernmain(){
	char * choice;
	while(1){
		printf("\n\ntrikern~@ ");
		choice = read_char();
		if(strcmp(choice, "help")==0){
			help();
		} else if(strcmp(choice, "ccalc")==0 || strcmp(choice, "calc")==0){
			ccalc();
		} else if(strcmp(choice, "osver")==0 || strcmp(choice, "atfetch")==0){
			osver();
		} else if(strcmp(choice, "clscr")==0 || strcmp(choice, "clear")==0){
			clscr();
		} else if(strcmp(choice, "exit")==0){
			exit();
		} else if(strcmp(choice, "cputest")==0){
			cputest();
		} else if(strcmp(choice, "notes")==0){
			notes();
		} else if(strcmp(choice, "pedx")==0){
			pedx();
		} else if(strcmp(choice, "atroid"==0) || strcmp(choice, "ai")==0){
			ahntroid();
		} else if(strcmp(choice, "atfork")==0){
			fbomb();
		} else if(strcmp(choice, "homenu")==0){
			homem();
		}else{
			printf("\nCommand not found.");
		}
	}
}

void mkern_main()
{
  init_vga(CYAN, BLACK);
  display_menu();
  kernmain();
}
