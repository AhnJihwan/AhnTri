//Advanced terminal&NewMain Menu

void newmain(){
	char capps = KEY_A;
	gotoxy(25, 0);
	printf("AhnTri Applications Execute Menu");
	printf("\nChoose an application to continue...");
	printf("\n[a] AhnTri Terminal Interface");
	printf("\n[b] AhnTri C Calulator");
	printf("\n[c] AhnTri Memory Set");
	printf("\n[d] AhnTri Memory Print");
	printf("\n[e] CPU ID");
	printf("\n[f] AhnTroid AI Assistant");
	printf("\n[g] AhnTri Notetaker");
	printf("\n[h] AhnTri Apps(NumDOS/GeX) menu");
	printf("\n[i] AhnTri Timer");
	printf("\n[j] Halt the CPU(Shutdown)");
	printf("\n\n\n\n\n\nCopyright 2021 Jihwan Ahn");
	capps = get_input_keycode();
	if(capps == KEY_A){
		clscr();
		kernmain();
	} else if(capps == KEY_B){
		clscr();
		ccalc();
	} else if(capps == KEY_C){
		clscr();
		memanset();
	} else if(capps == KEY_D){
		clscr();
		memprintf();
	} else if(capps == KEY_E){
		clscr();
		cputest();
	} else if(capps == KEY_F){
		clscr();
		ahntroid();
	} else if(capps == KEY_G){
		clscr();
		notes();
	} else if(capps == KEY_H){
		clscr();
		homem();
	} else if(capps == KEY_I){
		clscr();
		timer();
	} else if(capps == KEY_J){
		clscr();
		shutdown();
	} else{
		kernmain();
	}
}