#include "../kernel.h"
#include "../libc/atclib.h"

void game(){
	int i;
	i = (int)xor32() % 10;
	int ii;
	printf("Guess a natural number in the set X(X={x|0<=x<=10}) ... ");
	ii = read_int();
	if(i == ii){
		printf("The number picked is right!");
	} else {
		printf("Your guess is wrong...");
	}
}
