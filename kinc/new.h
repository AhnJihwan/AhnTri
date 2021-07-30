//Advanced terminal&NewMain Menu

void newmain(){
	char capps = KEY_A;
	printf("AhnTri Applications Execute Menu\n");
	printf("Choose an application to continue...\n");
	framebuffer_putchar(178, 0x8f8f8f);
	printf("[a] AhnTri Terminal Interface\n");
	framebuffer_putchar(178, 0x8f8f8f);
	printf("[b] AhnTri C Calulator\n");
	framebuffer_putchar(178, 0x8f8f8f);
	printf("[c] AhnTri Memory Set \n");
	framebuffer_putchar(178, 0x8f8f8f);
	printf("[d] AhnTri Memory Print      \n");
	framebuffer_putchar(178, 0x8f8f8f);
	printf("[e] CPU ID     \n");
	framebuffer_putchar(178, 0x8f8f8f);
	printf("[f] AhnTroid AI Assistant    \n");
	framebuffer_putchar(178, 0x8f8f8f);
	printf("[g] AhnTri Notetaker  \n");
	framebuffer_putchar(178, 0x8f8f8f);
	printf("[h] AhnTri Apps(NumDOS/GeX) menu    \n");
	framebuffer_putchar(178, 0x8f8f8f);
	printf("[i] AhnTri Timer      \n");
	framebuffer_putchar(178, 0x8f8f8f);
	printf("[j] Halt the CPU(Shutdown)\n");
	framebuffer_putchar(178, 0x8f8f8f);
	printf(" \n");
	framebuffer_putchar(178, 0x8f8f8f);
	printf("Copyright 2021 Jihwan Ahn    \n");
	framebuffer_putchar(178, 0x8f8f8f);
	printf("\n\n");
	framebuffer_putchar(219, 0x000000);
	framebuffer_putchar(219, 0x013571);
	framebuffer_putchar(219, 0x015229);
	framebuffer_putchar(219, 0x7fa49d);
	framebuffer_putchar(219, 0xf70f0f);
	framebuffer_putchar(219, 0x741b47);
	framebuffer_putchar(219, 0x8d6b00);
	framebuffer_putchar(219, 0x999999);
	framebuffer_putchar(219, 0x8f8f8f);
	framebuffer_putchar(219, 0x65abe7);
	framebuffer_putchar(219, 0xa3bd8d);
	framebuffer_putchar(219, 0x55ffff);
	framebuffer_putchar(219, 0xe61e2b);
	framebuffer_putchar(219, 0xba9da2);
	framebuffer_putchar(219, 0xeaa442);
	framebuffer_putchar(219, 0xffffff);
	capps = get_input_keycode();
	if(capps == KEY_A){
		framebuffer_clscr();
		kernmain();
	} else if(capps == KEY_B){
		framebuffer_clscr();
		ccalc();
	} else if(capps == KEY_C){
		framebuffer_clscr();
		memanset();
	} else if(capps == KEY_D){
		framebuffer_clscr();
		memprintf();
	} else if(capps == KEY_E){
		framebuffer_clscr();
		cputest();
	} else if(capps == KEY_F){
		framebuffer_clscr();
		ahntroid();
	} else if(capps == KEY_G){
		framebuffer_clscr();
		notes();
	} else if(capps == KEY_I){
		framebuffer_clscr();
		timer();
	} else if(capps == KEY_J){
		framebuffer_clscr();
		shutdown();
	} else{
		framebuffer_clscr();
		newmain();
	}
}
