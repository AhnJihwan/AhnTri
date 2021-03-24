#define OS_VER 1.2
#define OS_API_VER 2.30
#define OS_TERCOM_VER 1.00
                   
int bitidentify(){
	unsigned int k = sizeof(int*);
	int a = (int) k;
	char c;
    	if(a==4){
		os_print_color("32-bit    " , BLACK, CYAN);
	}else if(a==8){
		os_print_color("64-bit    " , BLACK, CYAN);
	}else{
		os_print_color("Undefined " , BLACK, CYAN);
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
	os_print_color("        /\\       OS: AhnTri OS 1.2.4 i386 Crap Covid   " , BLACK, CYAN);
	os_print_color("\n       /  \\      Machine: " , BLACK, CYAN);
	bitidentify();
	os_print_color("                   " , BLACK, CYAN);
	os_print_color("\n      /    \\     Kernel: AhnTri 1.20 +                 " , BLACK, CYAN);
	os_print_color("\n     /      \\    Terminal: Terminal 124                " , BLACK, CYAN);
	os_print_color("\n    /        \\   Themes: AhnTri                        " , BLACK, CYAN);
	os_print_color("\n   /  AhnTri  \\                                        " , BLACK, CYAN);
	os_print_color("\n  /____________\\                                       " , BLACK, CYAN);
}
