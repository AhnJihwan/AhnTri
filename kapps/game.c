#include "../kernel.h"
#include "../libc/atclib.h"

void game(){
	int i;
	i = (int)xor32() % 10;
	int ii;
	ii = read_int();
	if(i = ii){
		printf("The number picked is right!");
	} else {
		printf("Your guess is wrong...");
	}
}
