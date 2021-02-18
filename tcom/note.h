void display_help()
{
  gotoxy(25, 0);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color(" /-----------------------/ |", WHITE, BRIGHT_BLUE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color(" ------------------------| |", WHITE, BRIGHT_BLUE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("|    AhnTri NoteTaker    | |", WHITE, BRIGHT_BLUE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("|-~=-~=~--v1.2-~=~--~=~--| |", WHITE, BRIGHT_BLUE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("| Take notes and do not  | |", WHITE, BRIGHT_BLUE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("| shut down the PC then. | |", WHITE, BRIGHT_BLUE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("-------------------------|/ ", WHITE, BRIGHT_BLUE);
}
int NoTe;
void notes(){
	display_help();
	print_new_line();
	printf("                           -> ");
	NoTe = read_int();
}

