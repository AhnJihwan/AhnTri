#include "../kernel.h"
#include "../libc/atclib.h"

#define OS_VER 1.2
#define OS_API_VER 2.30
#define OS_TERCOM_VER 1.00
                   
int bitidentify(){
	unsigned int k = sizeof(int*);
	int a = (int) k;
	char c;
    	if(a==4){
		printf("32-bit    ");
	}else if(a==8){
		printf("64-bit    ");
	}else{
		printf("Undefined ");
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
	printf("        /\\       OS: AhnTri OS 1.2.5 i386 Fluent Flu     ");
	printf("\n       /  \\      System:  ");
	bitidentify();
	printf("                   ");
	printf("\n      /    \\     Kernel: AhnTri 1.20 +    ____    _____ ");
	printf("\n     /      \\    Terminal: Terminal 125   |___   |____  ");
	printf("\n    /        \\   Themes: AhnTri    \\ | / |      |      ");
	printf("\n   /  AhnTri  \\                   ={ o }= |luent | lu    ");
	printf("\n  /____________\\                   / | \\ |      |      ");
}
