#include "include/math.h"
//Ccalc for include
//Made in VS code
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
void display_menu_ccalc()
{
  gotoxy(25, 0);
  os_print_string("\n                           ");
  os_print_color("       AhnTri C caculator     ", BLACK, GREY);
  gotoxy(25, 0);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("  [ Welcome to AhnTri Calc ]  ", BLACK, CYAN);
  gotoxy(25, 0);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("  -~=-~=~--~=~--~=~--~=~--~=  ", BLACK, CYAN);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("1 for addition, 2 for subtract", BLACK, CYAN);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("ion, 3 for multiplication, 4 f", BLACK, CYAN);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("or division, 5 for Power 2, 6 ", BLACK, CYAN);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("for Power 3, 7 to return.     ", BLACK, CYAN);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("For Cubic (a+b)^3, press [8]. ", BLACK, CYAN);
}

void rtn(int* num1, int *num2)
{
  os_print_string("                           Enter first number : ");
  suspend(OS_suspend);
  *num1 = read_int();
  os_print_string("                           Enter second number : ");
  suspend(OS_suspend);
  *num2 = read_int();
}

void rtnp(int* po1)
{
  os_print_string("                           Enter base : ");
  suspend(OS_suspend);
  *po1 = read_int();
}

void ccalc(){
	int ccho, num1, num2, po1;
	while(1){
		display_menu_ccalc();
		os_print_string("\n\n                           > ");
		ccho = read_int();
		switch(ccho){
			case 1:
				rtn(&num1, &num2);
				os_print_string("                           Addition : ");
				adton(num1, num2);
				break;
			case 2:
				rtn(&num1, &num2);
				os_print_string("                           Substraction : ");
				subton(num1, num2);
				break;
			case 3:
				rtn(&num1, &num2);
				os_print_string("                           Multiplication : ");
				multon(num1, num2);
				break;
			case 4:
				rtn(&num1, &num2);
				if(num2 == 0){
					os_print_string("                           Error : Divide by 0");
				}else{
					os_print_string("                           Division : ");
					print_int(num1 / num2);
				}
			case 5:
				rtnp(&po1);
				os_print_string("                           Powered 2 result : ");
				powt(po1);
				break;
			case 6:
				rtnp(&po1);
				os_print_string("                           Powered 3 result : ");
				powth(po1);
				break;
			case 7:
				kernmain();
			case 8:
				rtn(&num1, &num2);
				os_print_string("                           Result number : ");
				addnpth(num1, num2);
				break;
			default:
				ccalc();
				break;
		}
		os_print_string("\n\nPress any key to reload screen...");
		getchar();
		clear_screen();
	}
}

