// include files by #include <neccessary file>
#include "kernel.h"
#include "kio/utils.h"
#include "kio/char.h"
#include "init/tinit.h"
#include "tcom/ccalcfi.h"
#include "tcom/osver.h"
#include "tcom/clscr.h"
#include "tcom/exit.h"
#include "tcom/cpuid.h"
#include "tcom/note.h"

void display_menu()
{
  gotoxy(25, 0);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color(" (4-exit)        (3-clear) ", BLACK, WHITE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("    AhnTri NumDOS 1.2      ", BLACK, WHITE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color(" -~=-~=~--~=~--~=~--~=~-=- ", BLACK, WHITE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("  Press [0] for help or o  ", BLACK, WHITE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("  ther key for each apps.  ", BLACK, WHITE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("                           ", BLACK, WHITE);
}

void kernmain()
{
  int choice, num1, num2, po1;
  while(1){
    display_menu();
    os_print_string("\n\n                           trikern~@ ");
    choice = read_int();
    switch(choice){
      case 0:
        os_print_string("1 for ccalc, 2 for osver, 3 for clear screen, 4 for exit");
        break;
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
      case 5:
        cputest();
        break;
      case 7:
        notes();
        break;
      default:
        os_print_string("\nNo such command(number)!");
        break;
    }
    os_print_string("\n\nPress any key to contine...");
    getchar();
    clear_screen();
  }
}

void mkern_main()
{
  init_vga(CYAN, BLACK);
  kernmain();
}
