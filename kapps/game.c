#include "../kernel.h"
#include "../libc/atclib.h"

//Mugunghwa Ccotchi Pheutseomnida AhnTri ver. Not officially accociated with Squid game or Netflix Inc.(I really enjoyed it, so I made this lol)
//Whole game revised by Jihwan Ahn, who is a Korean and revised from the original one.
void game(){
	char aa;
	char bb;
	clscr();
	printf("GAME RULES: PRESS A TO GO FORWARD. FIRST, CLICK A, AND YOU SHOULD CLICK A AND B ONCE. E.G.) A, B, A, B... IF YOU MOVE OTHER WAY, YOU WILL DIE.\n");
	printf("AHNTRI MUGUNGHWA CLASSIC VER 1.0\n");
	gotoxy(5, 3);
	printf("____________START LINE_______________\n");
	gotoxy(25, 5);
	printf("YOU\n");
	for(uint32_t i=6; i<24; i++) {
	aa = get_input_keycode();
		if(i==9 || i==14 || i==19){
			printf("MUGUNGHWA HAS BLOOMED");
			suspend(10);
		}else if(i<30 && i%2==0 && aa==KEY_A){
			gotoxy(25, i);
			printf("YOU");
			suspend(4);
		}else if(i<30 && i%2==1 && aa==KEY_B){
			gotoxy(25, i);
			printf("YOU");
			suspend(4);
		}else{
			printf("YOU R DEAD. \\=={}=== - - @ >O\n");
			suspend(20);
			asm volatile("hlt");
		}
	}
	printf("U SURVIVED.\n");
}
