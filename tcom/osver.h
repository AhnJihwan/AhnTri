#define OS_VER 1.2
#define OS_API_VER 2.30
#define OS_TERCOM_VER 1.00

/*
How kernels are named
AhnTri   BUILD_NAME     + or none (edition)
How GUI type is named
NumDOS: NumDOS      biggest issue at start of year
How OS type is named
AhnTri   GUI type
Terminal name rules
Terminal name       OS_NUM
*/

void osver(){
	os_print_color("        /\\       OS: AhnTri OS 1.2.3               " , BRIGHT_BLUE, CYAN);
	os_print_color("\n       /@ \\      GUI type: ATGUI corona-2          " , BRIGHT_BLUE, CYAN);
	os_print_color("\n      /    \\     Kernel: AhnTri 1.20 +             " , BRIGHT_BLUE, CYAN);
	os_print_color("\n     /      \\    Terminal: Terminal 123            " , BRIGHT_BLUE, CYAN);
	os_print_color("\n    /  1.20  \\   Themes: AhnTri                    " , BRIGHT_BLUE, CYAN);
	os_print_color("\n   /  AhnTri  \\                                    " , BRIGHT_BLUE, CYAN);
	os_print_color("\n  /____________\\                                   " , BRIGHT_BLUE, CYAN);
}