//This Translation is copyrighted by Umut Yavuz.
void display_menu_tr()
{
  printf(" ");
  printf("    Terminal - ana menu    ");
  printf("-");
  printf("+");
  printf("x\n");
  printf(" ");
  printf("      AhnTri Terminal         \n");
  framebuffer_putchar(178, 0x8f8f8f);
  printf("  -~=-~=~--~=~--~=~--~=~-=-   \n");
  framebuffer_putchar(178, 0x8f8f8f);
  printf(" Yardim icin yardim yazin ve  \n");
  framebuffer_putchar(178, 0x8f8f8f);
  printf(" her uygulama icin digerleri. \n");
  framebuffer_putchar(178, 0x8f8f8f);
  printf("                              \n");
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
}

void kernmain_tr(){
	char * choice;
	display_menu_tr();
	while(1){
		printf("\n\n@kern~");
		print_char(30);
		printf(" ");
		choice = read_char();
		if(strcmp(choice, "help")==0){
			help();
		} else if(strcmp(choice, "ccalc")==0 || strcmp(choice, "calc")==0 || strcmp(choice, "accalc")==0){
			ccalc();
		} else if(strcmp(choice, "exit")==0){
			exit();
		} else if(strcmp(choice, "osver")==0 || strcmp(choice, "atfetch")==0 || strcmp(choice, "aatfetch")==0){
			osver();
		} else if(strcmp(choice, "clscr")==0 || strcmp(choice, "clear")==0 || strcmp(choice, "aclear")==0 || strcmp(choice, "acls")==0){	//just 4 ppl who are used to dos
			clscr();
		} else if(strcmp(choice, "halt")==0 || strcmp(choice, "shutdown")==0 || strcmp(choice, "ashutdown")==0 || strcmp(choice, "ahalt")==0){
			shutdown();
		} else if(strcmp(choice, "cputest")==0 || strcmp(choice, "cpuid")==0 || strcmp(choice, "acpuid")==0){					//The real name of it was cpuid
			cputest();
		} else if(strcmp(choice, "notes")==0 || strcmp(choice, "anotes")==0){
			notes();
		} else if(strcmp(choice, "pedx")==0 || strcmp(choice, "apedx")==0){
			pedx();
		} else if(strcmp(choice, "atfork")==0 || strcmp(choice, "aatfork")==0){
			fbomb();
		} else if(strcmp(choice, "memor")==0 || strcmp(choice, "amemor")==0 || strcmp(choice, "memset")==0){
			memanset();
		} else if(strcmp(choice, "mp")==0 || strcmp(choice, "memprintf")==0){
			memprintf();
		} else if(strcmp(choice, "game")==0){
			game();
		} else if(strcmp(choice, "sun")==0){
			art();
		} else if(strcmp(choice, "plant")==0){
			plant();
		} else if(strcmp(choice, "advset")==0){
			advset();
		} else if(strcmp(choice, "atroid")==0 || strcmp(choice, "ai")==0){
			ahntroid();
		} else if(strcmp(choice, "adic")==0 || strcmp(choice, "dict")==0){
			fdic();
		} else if(strcmp(choice, "cal 2021")==0){
			clscr();
			acal();
		}else if(strcmp(choice, "pit")==0 || strcmp(choice, "timer")==0 || strcmp(choice, "atimer")==0){
			clscr();
			pit(18);
		}else if(strcmp(choice, "credit")==0 || strcmp(choice, "credits")==0){
			clscr();
			credits();
		}else{
			printf("\n");
			printf(choice);
			printf(": komut bulunamadi");

		}
	}
}
