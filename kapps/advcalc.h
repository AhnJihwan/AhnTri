//Ccalc for Advanced Calculations
void display_menu_ccalc_adv()
{
  printf("\n");
  printf("   CCalc for advanced calculations  ");
  printf("\n");
  printf("     [ Welcome to AhnTri Calc ]     ");
  printf("\n");
  printf("    --~=-~=~--~=~--~=~--~=~--~=~    ");
  printf("\n");
  printf("Press [1] for Data Transfer         ");
  printf("\n");
  printf("Press [2] for mass transfer         ");
  printf("\n");
  printf("Press [3] for Length Transfer       ");
  printf("\n");
  printf("Press [4] for Time transfer         ");
  printf("\n");
  printf("Press [5] for Temp transfer         ");
  printf("\n");
  printf("Press [6] for Deg <=> Rad           ");
  printf("\n");
  printf("Press [7] for Arthimatic Sequence   ");
  printf("\n");
  printf("Press [8] for Geometric Sequence   ");
  printf("\n");
  printf("Press [9] for Fibonacci Sequence   ");
  printf("\n");
  printf("Press [10] for Virtual Adress Translation   ");
  printf("\n");
  printf("Press [0] for Exit                  ");
}

int fib(int max){				//Fibonacci Seq I made using this:
        int n   = 1;				//a  = a    + a
        int n1  = 1;				// n+2  n+1    n
        int n2;
        printf("1, 1, ");
        while(n2<=max){
                n2 = n+n1;
                printf(", ");
                print_int(n2);
                n = n1;
                n1 = n2;
        }
}

void advccalc(){
	framebuffer_clscr(0x2b0303);				//Advanced CCALC does not rely on the default theme...
	int ccho, num1, num2;
	int i;
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
				num2=num1*180/3;
				print_int(num2);
				print_char(248);
				printf(" if Pi=3, and in general angle, ");
				print_int(num2%360);
				print_char(248);
				printf(".");
				break;
			case 7:
				printf("Arthmatic Sequence an=a1+(n-1)*d");
				printf("\nYour a1: ");
				num1 = read_int();
				printf("\nYour d: ");
				num2 = read_int();
				for(i=1;i<=20;i++){
					printf("\n");
					print_int(num1+i*num2-num2);
					if(i<20){
						printf(", ");
					}
					suspend(1);
				}
				break;
			case 8:
				printf("Geometric Sequence an=a1*r^(n-1)");
				printf("\nYour a1: ");
				num1 = read_int();
				printf("\nYour r: ");
				num2 = read_int();
				for(i=1;i<=20;i++){
					printf("\n");
					print_int(num1*xpy(num2, i-1));
					if(i<20){
						printf(", ");
					}
					suspend(1);
				}
				break;
			case 9:
				printf("max: ");
				num1 = read_int();
				fib(num1);
				break;
			case 10:
				printf("Virtual Adress in dec: ");
				num1 = read_int();
				printf("\nThe Page Directory Entry is: ");
				print_int(va2pa((void *)num1, 1)));
				printf("\nThe Page Table Entry is: ");
				print_int(va2pa((void *)num1, 2)));
				printf("\nThe Page Table Entry is: ");
				print_int(va2pa((void *)num1, 3)));
				break;
			case 0:
				ccalc();
				break;
		}
	}
}
