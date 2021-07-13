//Ccalc for Advanced Calculations
void display_menu_ccalc_adv()
{
  gotoxy(25, 0);
  printf("\n");
  os_print_color("   CCalc for advanced calculations  ", BLACK, GREY);
  gotoxy(25, 0);
  printf("\n");
  os_print_color("     [ Welcome to AhnTri Calc ]     ", BLACK, WHITE);
  gotoxy(25, 0);
  printf("\n");
  os_print_color("    --~=-~=~--~=~--~=~--~=~--~=~    ", BLACK, WHITE);
  printf("\n");
  os_print_color("Press [1] for Data Transfer  ", BLACK, WHITE);
  printf("\n");
  os_print_color("Press [2] for mass transfer ", BLACK, WHITE);
  printf("\n");
  os_print_color("Press [3] for Length Transfer", BLACK, WHITE);
  printf("\n");
  os_print_color("Press [4] for Time transfer ", BLACK, WHITE);
  printf("\n");
  os_print_color("Press [5] for Temp transfer ", BLACK, WHITE);
  printf("\n");
  os_print_color("Press [6] for Deg <=> Rad   ", BLACK, WHITE);
  printf("\n");
  os_print_color("Press [0] for Exit          ", BLACK, WHITE);
}

void advccalc(){
	int ccho, num1;
	while(1){
		display_menu_ccalc_adv();
		printf("\n\nADV> ");
		ccho = read_int();
		switch(ccho){
			case 1:
				printf("Data in kilobytes: ");
				num1 = read_int();
				print_int(kb2mb(num1));
				printf("MB");
				break;
			case 2:
				printf("Mass in lb: ");
				num1 = read_int();
				print_int(lb2kg(num1));
				printf("kg");
				break;
			case 3:
				printf("Length in inches: ");
				num1 = read_int();
				print_int(in2cm(num1));
				printf("cm");
				break;
			case 4:
				printf("Second to min/Minuite to hour: ");
				num1 = read_int();
				print_int(num1*60);
				break;
			case 5:
				printf("Celsius to Fahrenheit: ");
				num1  = read_int();
				print_int(cel2far(num1));
				break;
			case 6:
				printf("Radian to Degrees: ");
				num1=read_int();
				print_int(num1*180/3);
				printf(" if Pi=3);
			case 0:
				ccalc();
				break;
		}
	}
}
