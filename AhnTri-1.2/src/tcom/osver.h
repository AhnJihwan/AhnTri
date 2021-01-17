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
	os_print_color("        /\\         OS: AhnTri NumDOS 1.2.2           " , BLACK, CYAN);
	os_print_color("\n       /  \\      GUI type: NumDOS corona-2         " , BLACK, CYAN);
	os_print_color("\n      /    \\     Kernel: AhnTri 1.20 +             " , BLACK, CYAN);
	os_print_color("\n     / beta \\    Terminal: NumDOS 1.2.2            " , BLACK, CYAN);
	os_print_color("\n    /  1.20  \\   Themes: DOSBOX GUI                " , BLACK, CYAN);
	os_print_color("\n   / AhnTri 1 \\                                    " , BLACK, CYAN);
	os_print_color("\n  /____________\\                                   " , BLACK, CYAN);
}