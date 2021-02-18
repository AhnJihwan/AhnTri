

void display_menu_edx()
{
  char edx;
  gotoxy(25, 0);
  printf("\n                    ");
  os_print_color("       AhnTri EDX value viewer     ", BLACK, WHITE);
  printf("\n                    ");
  os_print_color("   Input [<-Enter] twice to Exit   ", BLACK, BRIGHT_MAGENTA);
  gotoxy(25, 0);
  os_print_color("\n                    ", BLACK, BLACK);
  os_print_color("       [ INPUT 4 EDX VALUE ]       ", BLACK, BRIGHT_MAGENTA);
  os_print_color("\n                    ", BLACK, BLACK);
  os_print_color("    EDX value is a value of bits   ", BLACK, BRIGHT_MAGENTA);
  print_new_line();
  printf("                    -> ");
  edx = read_int();
  print_edx(edx);
}

void pedx()
{
  display_menu_edx();
}

