#include "../AhnLibc/math.h"

//Ccalc for include
//Made in Xubuntu
// Simple calculations
void adton(int a, int b){
    print_int(a + b);
}

void subton(int a, int b){
    print_int(a - b);
}

void multon(int a, int b){
    print_int(a * b);
}

void divion(int a, int b){
    print_int(a / b);
}

//Quarderic Equation Solver4 AhnTri
void quareq_ccalc(){
	int a, b, c;
	printf("Please enter a in equation ax^2+bx+c: ");
	a = read_int();
	printf("Please enter b in equation ax^2+bx+c: ");
	b = read_int();
	printf("Please enter c in equation ax^2+bx+c: ");
	c = read_int();
	print_int(quareq_r1(a, b, c));
	printf(" and ");
	print_int(quareq_r2(a, b, c));
	printf(" are the roots.");
}

void display_menu_ccalc()
{
  init_vga(WHITE, BLACK);
  gotoxy(25, 0);
  printf("\n");
  os_print_color("       AhnTri C caculator     ", BLACK, GREY);
  gotoxy(25, 0);
  printf("\n");
  os_print_color("  [ Welcome to AhnTri Calc ]  ", BLACK, WHITE);
  gotoxy(25, 0);
  printf("\n");
  os_print_color("  -~=-~=~--~=~--~=~--~=~--~=  ", BLACK, WHITE);
  printf("\n");
  os_print_color("For More, press [0] for help. ", BLACK, WHITE);
}

void rtn(int* num1, int *num2)
{
  printf("Enter first number : ");
  suspend(OS_suspend);
  *num1 = read_int();
  printf("Enter second number : ");
  suspend(OS_suspend);
  *num2 = read_int();
}

void abc(int * num1, int * num2, int * num3)
{
  printf("Enter first number : ");
  suspend(OS_suspend);
  *num1 = read_int();
  printf("Enter second number : ");
  suspend(OS_suspend);
  *num2 = read_int();
  printf("Enter third number : ");
  suspend(OS_suspend);
  *num3 = read_int();
}

void rtnp(int* po1)
{
  printf("Enter base : ");
  suspend(OS_suspend);
  *po1 = read_int();
}

#include "advcalc.h"

void ccalc(){
	int ccho, num1, num2, num3, po1;
	while(1){
		display_menu_ccalc();
		printf("\n\n> ");
		ccho = read_int();
		switch(ccho){
			case 0:
 			 	printf("\n");
  				os_print_color("Addition:1, Sub:2, Mul:3, Div:4, Power 2:5, Power 3:6, sqrt: [10]", BLACK, WHITE);
   			   printf("\n");
  				os_print_color("For (a+b)^3,  [8], GeX [9], TUI [7], factorial [11], Advanced calc [12]", BLACK, WHITE);
   			   printf("\n");
				break;
			case 1:
				rtn(&num1, &num2);
				printf("Addition : ");
				adton(num1, num2);
				break;
			case 2:
				rtn(&num1, &num2);
				printf("Substraction : ");
				subton(num1, num2);
				break;
			case 3:
				rtn(&num1, &num2);
				printf("Multiplication : ");
				multon(num1, num2);
				break;
			case 4:
				rtn(&num1, &num2);
				if(num2 == 0){
					printf("Error : Divide by 0");
				}else{
					printf("Division : ");
					print_int(num1 / num2);
				}
				break;
			case 5:
				rtnp(&po1);
				print_int(po1);
				print_char(253);					//The output will be po1^2 I mean real ^2.
				printf(" = ");
				print_int(powt(po1));
				break;
			case 6:
				rtnp(&po1);
				print_int(po1);
				print_char(253);					//The output will be po1^3 I mean real ^3.
				printf(" = ");
				print_int(powth(po1));
				break;
			case 7:
				init_vga(CYAN, BLACK);
				kernmain();
				break;
			case 8:
				rtn(&num1, &num2);
				printf("Result number : ");
				print_int(addnpth(num1, num2));
				break;
			case 10:
				rtnp(&po1);
				print_char(251);													//This is the real root sign    -\/--
				print_int(po1);
				printf(" = ");
				print_int(sqrt(po1));
				break;
			case 11:
				rtnp(&po1);
				print_int(po1);
				printf("! = ");
				print_int(factorial(po1));
				break;
			case 12:
				advccalc();
				break;
			case 13:
				quareq_ccalc();
			case 9:
				homem();
				break;
			default:
				ccalc();
				break;
		}
		printf("\n\nPress any key to reload screen...");
		getchar();
		clear_screen();
	}
}
