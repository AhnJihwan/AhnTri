#include "../kernel.h"
#include "../kinc/api.h"

void advset(){
	char cps = KEY_A;
	char cpsii = KEY_A;
	int i;
	clscr();
	gotoxy(25, 0);
	printf("AhnTri Advanced settings\n\n");
	printf("1. Change Text color - NOT WORKING\n");
	printf("2. Change Theme color - NOT WORKING\n");
	printf("3. Reload GDT\n");
	printf("4. Reload IDT\n");
	printf("5. Send byte to OS\n");
	printf("6. Operating System version\n");
	printf("7. Change keyboard layout\n");
	printf("8. PC CPU ID\n");
	printf("9. Go to kernel main\n");
	printf("a. Change Theme\n");
	printf("b. Change Language\n");
	printf("c. Physical Memory Manager\n");
	printf("d. Earth Save Mode(Eco Mode)(O)\n");
	printf("e. Earth Save Mode(Eco Mode)(X)\n");
	printf("f. Safe Termperature mode(O)\n");
	printf("g. Safe Termperature mode(X)\n");
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
	}else if(cps == KEY_C){
		printf("Physical Memory Manager.\n[0] Add Block\n[1] free block\n[2] Kernel Deinit\n[3] Print PMM Info\n");
		suspend(3);
		cpsii = get_input_keycode();
		suspend(3);
		if(cpsii == KEY_0){
			printf("Please enter the physical adress as a int(e.g. 0x98789 --> 624521)\n");
			i = read_int();
			pmm_add_block((uint32_t *)i);
		}else if(cpsii == KEY_1){
			printf("Please enter the physical adress as a int(e.g. 0x98789 --> 624521)\n");
			i = read_int();
			pmm_free_block((uint32_t *)i);
		}else if(cpsii == KEY_2){
			printf("Deiniting the kernel\n");
			pmm_kernel_deinit();
		}else if(cpsii == KEY_3){
			print_pmm_info();
		}else{
			printf("Input Not Vaild.\n");
		}
	}else if(cps == KEY_D){
		ia32_energy_pref_status_f(true);
	}else if(cps == KEY_E){
		ia32_energy_pref_status_f(false);
	}else if(cps == KEY_F){
		ia32_therm_interrupt_f(0, true);
		ia32_therm_interrupt_f(1, true);
		ia32_therm_interrupt_f(2, true);
	}else if(cps == KEY_G){
		ia32_therm_interrupt_f(0, false);
		ia32_therm_interrupt_f(1, false);
		ia32_therm_interrupt_f(2, false);
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
    clscr();
    printf("ISR phone\n");
    printf("(Besides, there are 31 ISRs)\n");
    isr_0_handler();
    printf("\n");
    isr_1_handler();
    printf("\n");
    isr_2_handler();
    printf("\n");
    isr_3_handler();
    printf("\n");
    isr_4_handler();
    printf("\n");
    isr_5_handler();
    printf("\n");
    isr_6_handler();
    printf("\n");
    isr_7_handler();
    printf("\n");
    isr_8_handler();
    printf("\n");
    isr_9_handler();
    printf("\n");
    isr_10_handler();
    printf("\n");
    suspend(50);
    clscr();
    isr_11_handler();
    printf("\n");
    isr_12_handler();
    printf("\n");
    isr_13_handler();
    printf("\n");
    isr_14_handler();
    printf("\n");
    isr_15_handler();
    printf("\n");
    isr_16_handler();
    printf("\n");
    isr_17_handler();
    printf("\n");
    isr_18_handler();
    printf("\n");
    isr_19_handler();
    printf("\n");
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
