void display_help()
{
  gotoxy(25, 0);
  os_print_color("\n /-----------------------/ |", WHITE, BLUE);
  os_print_color("\n ------------------------| |", WHITE, BLUE);
  os_print_color("\n|    AhnTri Notes 1.2    | |", WHITE, BLUE);
  os_print_color("\n|-~=-~=~--~=~--~=~--~=~--| |", WHITE, BLUE);
  os_print_color("\n| Take notes and do not  | |", WHITE, BLUE);
  os_print_color("\n| shut down the PC then. | |", WHITE, BLUE);
  os_print_color("\n-------------------------|/ ", WHITE, BLUE);
}

void notes(){
	int NoTe;
	clear_screen();
	display_help();
	print_new_line();
	NoTe = read_int();
}

