#include "../kernel.h"
#include "../kinc/api.h"

void advset(){
	char cps = KEY_A;
	clscr();
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
	printf("a. Change Theme\n");
	printf("b. Change Language\n");
	printf("AhnTroid AI is a part of AhnTri and is protected by the Apache 2.0 open source licence.\n");
	cps = get_input_keycode();
	if(cps == KEY_3){
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
	}else if(cps == KEY_A){
		printf("In construction");
	}else if(cps == KEY_B){
		printf("What Lanauge?");
		lang();
	} else{
		clscr();
		return;
	}
}
void lang(){
	char capsz = KEY_A;
	printf("Select Text color");
	printf("\nDeafult(1). English\n2. Italian\n3. Korean\n4. Turk\n");
	suspend(3);
	capsz = get_input_keycode();
	if(capsz == KEY_1){
		clscr();
		qemu_printf_string("Language: set to English.");
		kernmain();
	} else if(capsz == KEY_2){
		clscr();
		qemu_printf_string("Lingua: impostato su italiano.");
		kernmain_it();
	} else if(capsz == KEY_3){
		clscr();
		qemu_printf_string("언어: 한국어로 설정되었습니다.");
		kernmain_kr();
	} else if(capsz == KEY_4){
		clscr();
		qemu_printf_string("Dil: Türkçe olarak ayarlayın.");
		kernmain_tr();
	} else if(capsz == KEY_5){
		clscr();
	}else{
		printf("No such color. Try again.");
	}
	printf("Color set: Complete.");
}

void inbbyusr(){
	uint16 port;
	port = read_uint();
	inb(port);
}

void devtools(){
  int a, b, b2;
  char c;
  char d[] = "Hello World.";
  char e, f, g;
  printf("Developer tools\n");
  printf("ANT c library - 1\nISRs' Exceptions - 2\nCPU ID and Information - 3\nInit GDT - 4\nInit IDT - 5\n");
  printf("devtools~@ ");
  a = read_int();
  if(a==1){
    printf("Currently, memset is available in Developer tools.\n");
    printf("<><><@> MEMSET <@><><>\n");
    printf("void *memset(void *str, int a, uint8_t n)\n");
    printf("str: Hello World.\n");
    printf("int a: ");
    b = read_int();
    printf("\nuint8_t n: 5\n");
    memset(d, b, 5);
    printf(d);
  }else if(a==2){
    printf("ISR phone\n");
    printf("(Besides, there are 31 ISRs)\n");
    isr_0_handler();
    isr_1_handler();
    isr_2_handler();
    isr_3_hanlder();
  }else if(a==3){
     cputest();
  }else if(a==4){
     init_gdt();
  }else if(a==5){
     init_idt();
  }else{
     printf("Select 1~5");
  }
}
