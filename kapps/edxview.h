

void display_menu_edx()
{
  framebuffer_clscr(0x000000);
  char edx;
  gotoxy(25, 0);
  printf("\n                    ");
  printf("       AhnTri EDX value viewer     ");
  printf("\n                    ");
  printf("   Input [<-Enter] twice to Exit   ");
  gotoxy(25, 0);
  printf("\n                    ");
  printf("       [ INPUT 4 EDX VALUE ]       ");
  printf("\n                    ");
  printf("    EDX value is a value of bits   ");
  print_new_line();
  printf("                    -> ");
  edx = read_int();
  print_edx(edx);
}

void pedx()
{
  display_menu_edx();
}

