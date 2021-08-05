#include "../libc/atclib.h"
#include "../kernel.h"
#include "../kinc/api.h"
#include "advcalc.h"
#define ccalsusp 10
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
  framebuffer_clscr(0xeaa442);
  gotoxy(25, 0);
  printf("\n    Start - AhnTri CCalc      ");
  printf("\n  [ Welcome to AhnTri Calc ]  ");
  printf("\n");
  printf("  -~=-~=~--~=~--~=~--~=~--~=  ");
  printf("\n");
  printf("For More, press [0] for help. ");
  suspend(20);
  framebuffer_clscr(0x2b0303);
}

void rtn(int* num1, int *num2)
{
  printf("\nEnter first number");
  suspend(ccalsusp);
  *num1 = read_int();
  printf("\nEnter second number");
  suspend(ccalsusp);
  *num2 = read_int();
}

process logf()
{
	int a, b, x;
	printf("Your a ");
	a = read_int();
	printf("Your b ");
	b = read_int();
	print_int(log(a, b));
}

void abc(int * num1, int * num2, int * num3)
{
  printf("Enter first number : ");
  suspend(ccalsusp);
  *num1 = read_int();
  printf("Enter second number : ");
  suspend(ccalsusp);
  *num2 = read_int();
  printf("Enter third number : ");
  suspend(ccalsusp);
  *num3 = read_int();
}

void rtnp(int* po1)
{
  printf("Enter base : ");
  suspend(ccalsusp);
  *po1 = read_int();
}

void ccalc(){
	int ccho, num1, num2, num3, po1;
	char *h;
	while(1){
		display_menu_ccalc();
		printf("\n\n[                         ] ");
		gotoxy(2, 2);
		ccho = read_int();
		switch(ccho){
			case 0:
 			 	printf("\n");
  				printf("Addition:1, Sub:2, Mul:3, Div:4, Power 2:5, Power 3:6, sqrt: [10]");
   			   printf("\n");
  				printf("For (a+b)^3,  [8], GeX [9], TUI [7], factorial [11], Advanced calc [12], for ax^2+bx+c [13], for x^y [14], for logab [15], and for Logical AND, OR, XOR respectively, [16], [17], [18]");
   			   printf("\n");
				break;
			case 1:
				printf("\nADDING 2 NUMERALS");
				rtn(&num1, &num2);
				adton(num1, num2);
				break;
			case 2:
				printf("\nSUBTRACTING 2 NUMERALS");
				rtn(&num1, &num2);
				subton(num1, num2);
				break;
			case 3:
				printf("\nMULTIPLYING 2 NUMERALS");
				rtn(&num1, &num2);
				gotoxy(2, 2);
				multon(num1, num2);
				break;
			case 4:
				rtn(&num1, &num2);
				if(num2 == 0){
					printf("Error : Divide by 0");
				}else{
					printf("DIVIDING 2 NUMERALS");
					gotoxy(2, 2);
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
			case 14:
				rtn(&num1, &num2);
				print_int(xpy(num1, num2));
				break;
			case 9:
				printf("Not supported anymore.");
			case 15:
				logf();		//Log b = x function
				break;		//   a
			case 16:
				printf("Logical AND");
				h = read_char();
				rtn(&num1, &num2);
				print_int(LOGICAL("and", num1, num2));
				break;
			case 17:
				printf("Logical OR");
				h = read_char();
				rtn(&num1, &num2);
				print_int(LOGICAL("or", num1, num2));
				break;
			case 18:
				printf("Logical XOR");
				h = read_char();
				rtn(&num1, &num2);
				print_int(LOGICAL("xor", num1, num2));
				break;
			case 19:
				printf("n\n");
				print_char(228);
				printf(" = {a+(n-1)d}\n");
				printf("i=m\n");
				printf("Your a: ");
				read_int(&num1);
				printf("Your d: ");
				read_int(&num2);
				printf("Your n: ");
				read_int(&po1);
				printf("Your m: ");
				read_int(&num3);
				print_int(soap(num1, num2, po1, num3));
				break;
			default:
				ccalc();
				break;
		}
		printf("\n\nPress any key to reload screen...");
		getchar();
		framebuffer_clscr(0x2b0303);
	}
}
