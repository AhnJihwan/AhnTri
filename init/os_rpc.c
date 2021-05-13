// include files by #include <neccessary file>
#include "../kernel.h"
#include "../drivers/kb/char.h"	//So what?
#include "../2dt/idt.h"
#include "../tcom/isrphone.h"
#include "tinit_rpc.h"
#include "../tcom/clscr.h"
#include "../tcom/cpu/ports.h"
#include "../tcom/exit.h"
#include "../tcom/cpuid.h"
#include "../tcom/edxview.h"
#include "../tcom/help.h"
#include "../tcom/forker.h"
#include "../tcom/timermode.h"
#include "../tcom/mem.h"
#include "new.h"
#include "../homenu.h"
#include "../kio/types.h"
#include "../2dt/gdt.h"
#include "../AhnLibc/mem.h"

void display_menu()
{
  printf(" ");
  os_print_color("    Terminal - main menu  ", WHITE, GREY);
  os_print_color("-", YELLOW, BLACK);
  os_print_color("+", GREEN, BLACK);
  os_print_color("x\n", RED, BLACK);
  printf(" ");
  os_print_color("      AhnTri Terminal        \n", BLACK, WHITE);
  os_color_char(178, GREY, BLACK);
  os_print_color("  -~=-~=~--~=~--~=~--~=~-=-  \n", BLACK, WHITE);
  os_color_char(178, GREY, BLACK);
  os_print_color("   Type help for help or o   \n", BLACK, WHITE);
  os_color_char(178, GREY, BLACK);
  os_print_color("   ther key for each apps.   \n", BLACK, WHITE);
  os_color_char(178, GREY, BLACK);
  os_print_color("                             \n", BLACK, WHITE);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
  os_color_char(178, GREY, BLACK);
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
		} else if(strcmp(choice, "ccalc")==0 || strcmp(choice, "calc")==0 || strcmp(choice, "accalc")==0){
			ccalc();
		} else if(strcmp(choice, "exit")==0){
			exit();
		} else if(strcmp(choice, "osver")==0 || strcmp(choice, "atfetch")==0 || strcmp(choice, "aatfetch")==0){
			osver();
		} else if(strcmp(choice, "clscr")==0 || strcmp(choice, "clear")==0 || strcmp(choice, "aclear")==0 || strcmp(choice, "acls")==0){	//just 4 ppl who are used to dos
			clscr();
		} else if(strcmp(choice, "halt")==0 || strcmp(choice, "shutdown")==0 || strcmp(choice, "ashutdown")==0 || strcmp(choice, "ahalt")==0){
			shutdown();
		} else if(strcmp(choice, "cputest")==0 || strcmp(choice, "cpuid")==0 || strcmp(choice, "acpuid")==0){					//The real name of it was cpuid
			cputest();
		} else if(strcmp(choice, "notes")==0 || strcmp(choice, "anotes")==0){
			notes();
		} else if(strcmp(choice, "pedx")==0 || strcmp(choice, "apedx")==0){
			pedx();
		} else if(strcmp(choice, "atfork")==0 || strcmp(choice, "aatfork")==0){
			fbomb();
		} else if(strcmp(choice, "homenu")==0 || strcmp(choice, "ahomenu")==0){
			homem();
		} else if(strcmp(choice, "timer")==0 || strcmp(choice, "atimer")==0){
			timer();
		} else if(strcmp(choice, "memor")==0 || strcmp(choice, "amemor")==0 || strcmp(choice, "memset")==0){
			memanset();
		} else if(strcmp(choice, "mp")==0 || strcmp(choice, "memprintf")==0){
			memprintf();
		} else if(strcmp(choice, "game")==0){
			game();
		} else if(strcmp(choice, "sun")==0){
			art();
		} else if(strcmp(choice, "plant")==0){
			plant();
		} else if(strcmp(choice, "advset")==0){
			advset();
		} else if(strcmp(choice, "atroid")==0 || strcmp(choice, "ai")==0){
			ahntroid();
		} else if(strcmp(choice, "adic")==0 || strcmp(choice, "dict")==0){
			fdic();
		} else if(strcmp(choice, "cal 2021")==0){
			clscr();
			acal();
		} else if(strcmp(choice, "ci")==0){
			clscr();
			isrphone();
		}else if(strcmp(choice, "credit")==0 || strcmp(choice, "credits")==0){
			clscr();
			credits();
		}else{
			printf("\n");
			printf(choice);
			printf(": command not found");

		}
	}
}

void mkern_main()
{
  init_vga(CYAN, BLACK);
  printf("\nVGA initialization");
  suspend(1);
  printf(".");
  suspend(1);
  printf(".");
  suspend(1);
  printf(".");
  suspend(1);
  printf(" [OK]\n");
  suspend(2);
  init_gdt();
  printf("\nGDT initialization");
  suspend(1);
  printf(".");
  suspend(1);
  printf(".");
  suspend(1);
  printf(".");
  suspend(1);
  printf(" [OK]\n");
  suspend(2);
  init_idt();
  asm volatile("\tmov $12395, %eax");
  asm volatile("\tint $0");
  printf("\nIDT initialization");
  suspend(1);
  printf(".");
  suspend(1);
  printf(".");
  suspend(1);
  printf(".");
  suspend(1);
  printf(" [OK]\n");
  isr_0_handler();
  printf("Loading main menu.");
  suspend(1);
  printf(".");
  suspend(1);
  printf(".");
  suspend(1);
  printf(".");
  suspend(1);
  printf(".");
  suspend(2);
  clscr();
  #include "strtscrn.h"
  strt_scrn();
  clscr();
  newmain();
}
