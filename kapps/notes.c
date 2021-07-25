#include "../kernel.h"
#include "../libc/atclib.h"

void notetake()
{
  char ch = 0;
  char inp = 0;
  do{
    inp = get_input_keycode();
    if(inp == KEY_ENTER){
    	printf("\n");
     } else if(inp == KEY_ESC || inp == KEY_TAB){
     	clscr();
     	kernmain();
    }else{
      ch = get_ascii_char(inp);
      print_char(ch);
    }
    suspend(8);
  }while(ch > 0);
}

void display_help()
{
  gotoxy(25, 0);
  framebuffer_putstr("\n                           ", 0x65abe7);
  framebuffer_putstr(" /-----------------------/ |", 0x65abe7);
  framebuffer_putstr("\n                           ", 0x65abe7);
  framebuffer_putstr(" ------------------------| |", 0x65abe7);
  framebuffer_putstr("\n                           ", 0x65abe7);
  framebuffer_putstr("|    AhnTri NoteTaker    | |", 0x65abe7);
  framebuffer_putstr("\n                           ", 0x65abe7);
  framebuffer_putstr("|-~=-~=~--v1.3-~=~--~=~--| |", 0x65abe7);
  framebuffer_putstr("\n                           ", 0x65abe7);
  framebuffer_putstr("| Take notes and do not  | |", 0x65abe7);
  framebuffer_putstr("\n                           ", 0x65abe7);
  framebuffer_putstr("| shut down the PC then. | |", 0x65abe7);
  framebuffer_putstr("\n                           ", 0x65abe7);
  framebuffer_putstr("-------------------------|/ ", 0x65abe7);
}

void notes(){
	display_help();
	printf("\nStarting Notetaker");
	suspend(100);
	clscr();
	framebuffer_putstr("\nWelcome to AhnTri NoteTaker.\n", BLACK, GREY);
	printf("Hint: press [Esc] or [Tab] to exit AhnTri NoteTaker\n================================================================================");
	notetake();
}
