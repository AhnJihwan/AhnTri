//Advanced terminal&NewMain Menu

void newmain(){
	char capps = KEY_A;
	gotoxy(25, 0);
	os_print_color("AhnTri Applications Execute Menu", BLACK, CYAN);
	os_print_color("\nChoose an application to continue...                                            ", BLACK, CYAN);
	os_print_color("\n[a] AhnTri Terminal Interface                                                   ", BLACK, CYAN);
	os_print_color("\n[b] AhnTri C Calulator                                                          ", BLACK, CYAN);
	os_print_color("\n[c] AhnTri Memory Set                                                           ", BLACK, CYAN);
	os_print_color("\n[d] AhnTri Memory Print                                                         ", BLACK, CYAN);
	os_print_color("\n[e] CPU ID                                                                      ", BLACK, CYAN);
	os_print_color("\n[f] AhnTroid AI Assistant                                                       ", BLACK, CYAN);
	os_print_color("\n[g] AhnTri Notetaker                                                            ", BLACK, CYAN);
	os_print_color("\n[h] AhnTri Apps(NumDOS/GeX) menu                                                ", BLACK, CYAN);
	os_print_color("\n[i] AhnTri Timer                                                                ", BLACK, CYAN);
	os_print_color("\n[j] Halt the CPU(Shutdown)                                                      ", BLACK, CYAN);
	os_print_color("\n                                                                                \n                                                                                \n                                                                                \n                                                                                \n                                                                                \nCopyright 2021 Jihwan Ahn                                                       ", BLACK, CYAN);
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