#define OS_VER 1.2
#define OS_API_VER 2.30
#define OS_TERCOM_VER 1.00
                   
int bitidentify(){
	unsigned int k = sizeof(int*);
	int a = (int) k;
	char c;
    	if(a==4){
		os_print_color("32-bit" , BRIGHT_BLUE, CYAN);
	}else if(a==8){
		os_print_color("64-bit" , BRIGHT_BLUE, CYAN);
	}else{
		os_print_color("Undefined" , BRIGHT_BLUE, CYAN);
	}
}

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
	os_print_color("        /\\       OS: AhnTri OS 1.2.3.2 i386        " , BRIGHT_BLUE, CYAN);
	os_print_color("\n       /  \\      Machine: " , BRIGHT_BLUE, CYAN);
	bitidentify();
	os_print_color("                   " , BRIGHT_BLUE, CYAN);
	os_print_color("\n      /    \\     Kernel: AhnTri 1.20 +             " , BRIGHT_BLUE, CYAN);
	os_print_color("\n     /      \\    Terminal: Terminal 123            " , BRIGHT_BLUE, CYAN);
	os_print_color("\n    /        \\   Themes: AhnTri                    " , BRIGHT_BLUE, CYAN);
	os_print_color("\n   /  AhnTri  \\                                    " , BRIGHT_BLUE, CYAN);
	os_print_color("\n  /____________\\                                   " , BRIGHT_BLUE, CYAN);
}