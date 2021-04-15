#include "../kernel.h"
#include "../init/api.h"

void advset(){
	char cps = KEY_A;
	gotoxy(25, 0);
	printf("AhnTri Advanced settings\n\n");
	printf("1. Change Text color\n");
	printf("2. Change Theme color\n");
	printf("3. Reload GDT\n");
	printf("4. Reload IDT\n");
	printf("5. Send byte to OS\n");
	printf("6. Operating System version\n");
	printf("7. Change keyboard layout\n");
	printf("8. PC CPU ID\n");
	printf("9. Go to kernel main\n");
	printf("AhnTroid AI is a part of AhnTri and is protected by the Apache 2.0 open source licence.\n");
	cps = get_input_keycode();
	if(cps == KEY_1){
		clscr();
		txtcolr();
	} else if(cps == KEY_2){
		clscr();
		thxcolr();
	} else if(cps == KEY_3){
		clscr();
		init_gdt();
	} else if(cps == KEY_4){
		clscr();
		init_idt();
	} else if(cps == KEY_6){
		clscr();
		osver();
	} else if(cps == KEY_8){
		clscr();
		cputest();
	} else if(cps == KEY_9){
		clscr();
		return;
	} else{
		clscr();
		return;
	}
}

void txtcolr(){
	char caps = KEY_A;
	printf("Select Text color");
	printf("\nDeafult(1). CYAN\n2. BLACK\n3. GREEN\n4. RED\n5. MAGENTA\n6. BROWN");
	suspend(3);
	caps = get_input_keycode();
	if(caps == KEY_1){
		clscr();
		init_vga(CYAN, BLACK);
	} else if(caps == KEY_2){
		clscr();
		init_vga(BLACK, BLACK);
	} else if(caps == KEY_3){
		clscr();
		init_vga(GREEN, BLACK);
	} else if(caps == KEY_4){
		clscr();
		init_vga(RED, BLACK);
	} else if(caps == KEY_5){
		clscr();
		init_vga(MAGENTA, BLACK);
	} else if(caps == KEY_6){
		clscr();
		init_vga(BROWN, BLACK);
	}else{
		printf("No such color. Try again.");
	}
	printf("Color set: Complete.");
}

void thxcolr(){
	char cathx = KEY_A;
	printf("Select Background color");
	printf("\nDeafult(1). BLACK\n2. CYAN\n3. GREEN\n4. RED\n5. MAGENTA\n6. BROWN");
	suspend(3);
	cathx = get_input_keycode();
	if(cathx == KEY_1){
		clscr();
		init_vga(CYAN, BLACK);
	} else if(cathx == KEY_2){
		clscr();
		init_vga(CYAN, CYAN);
	} else if(cathx == KEY_3){
		clscr();
		init_vga(CYAN, GREEN);
	} else if(cathx == KEY_4){
		clscr();
		init_vga(CYAN, RED);
	} else if(cathx == KEY_5){
		clscr();
		init_vga(CYAN, MAGENTA);
	} else if(cathx == KEY_6){
		clscr();
		init_vga(CYAN, BROWN);
	}else{
		printf("No such color. Try again.");
	}
	printf("Color set: Complete.");
}
