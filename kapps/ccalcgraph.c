/*
Copyright 2021 Jihwan Ahn

The permissions to copy, modify, use privately, and distribute are granted without permission
and limitations if Licence and Copyright information is noticed and the changes are noticed w
hen modified. However, Commercial use is granted provided that one has got the copyrighter's p
ermission. The use of trademarks 'CCALC' and 'CCALC for AhnTri' is prohibited without the copy
righer's permission. Liability and Warranty, as with trademark use, are limited. 
*/

void graph_putpixel(uint32_t x, uint32_t y, uint32_t c){
	uint32_t graphxx=203+x;
	uint32_t graphyy=203-y;
	if(c==NULL){
		c=0x7fa49d;
	}
	framebuffer_putpixel(graphxx, graphyy, c);
}

void ccalcgraph(){
        framebuffer_clscr(0xffffcc);
        int k;
        for(int i=3; i<400; i++){
                framebuffer_putpixel(203, i, 0x7fa49d);
                framebuffer_putpixel(i, 203, 0x7fa49d);
        }
        gotoxy(3, 420);
        printf(" [1] LINEAR FUNCTION\n [2] QUAD. FUNCTION\n [3] CUBIC FUNCTION\n [4] DERIVATIVE OF A QUAD. FUNCTION\n [5] DERIVATIVE OF A CUBIC FUNTION\n [6] COPYRIGHT INFO");
        int inputgrph;
        inputgraph = read_int();
        int a, b, c, d;
        printf("Your Input, input 0 if not be going to be used. y=ax+b, y=ax^2+bx+c, y=ax^3+bx^2+cx+d\nYour a:");
        a = read_int();
        printf("\nYour b: ");
        b = read_int();
        printf("\nYour c: ");
        c = read_int();
        printf("\nYour d: ");
        d = read_int();
        for(k = -203, k<204, k++){
                if(inputgrph==1){
                        graph_putpixel(i, a*k+b, 0x87aaa0);
		} else if(inputgrph==2){
			graph_putpixel(i, a*xpy(k, 2)+b*k+c, 0xbfbccb);
		} else if(inputgrph==3){
			graph_putpixel(i, a*xpy(k, 3)+b*xpy(k, 2)+c*k+d, 0x16a26c);
		} else if(inputgrph==4){
			graph_putpixel(i, 2*a*k+b, 0xbfbccb);
		} else if(inputgrph==5){
			graph_putpixel(i, 3*a*xpy(k, 2)+2*b*k, 0x16a26c);
		}
	}
	if(inputgrph!=1 | inputgrph!=2 | inputgrph!=3 | inputgrph!=4 | inputgrph!=5){
		printf("Invalid Input\n");
		printf("Please insert the valid input again.\n");
		kernmain();
	}
}
