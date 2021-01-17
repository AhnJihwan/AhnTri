
void pedx()
{
  display_menu_edx();
}

void display_menu_edx()
{
  char edx;
  gotoxy(25, 0);
  os_print_string("\n                    ");
  os_print_color("       AhnTri EDX value viewer     ", BLACK, WHITE);
  os_print_string("\n                    ");
  os_print_color("   Input [<-Enter] twice to Exit   ", BLACK, BRIGHT_MAGENTA);
  gotoxy(25, 0);
  os_print_color("\n                    ", BLACK, BLACK);
  os_print_color("       [ INPUT 4 EDX VALUE ]       ", BLACK, BRIGHT_MAGENTA);
  os_print_color("\n                    ", BLACK, BLACK);
  os_print_color("    EDX value is a value of bits   ", BLACK, BRIGHT_MAGENTA);
  print_new_line();
  os_print_string("                    -> ");
  edx = read_int();
  print_edx(edx);
}
