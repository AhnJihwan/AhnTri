//Lot of functions
//such like powers, square roots, division, (a+b)^3, and Quaderic Equation Root 1, 2.
// Define what ppl use a lot
#define Math_PI = 3.14159265359;					//Stable...
#define ROOT_TWO = 1.414213562373095048801688724209698079;
#define finity_bool true
#define infinity_bool false
#define infinity 1000000

int addnpth(int a, int b){						//This is for (a+b)^3
    int k;
    int m = a * a * a;
    int n = b * b * b;
    int mp = 3*a*a*b;
    int np = 3*a*b*b;
    k = m + n + np + mp;
    return k;
}

int sqrt(int number){								//Sqare root that I made
        int temp, sqrt;
        sqrt = number / 2;
        temp = 0;
        while(sqrt != temp){
                temp = sqrt;
                sqrt = (number/temp+temp)/2;
        }
        return sqrt;
}

int quareq_r1(int a, int b, int c){
        int D, r1;
        D = b * b - 4 * a * c;
        if( D > 0){
                r1 = (-b + sqrt(D)) / (2 * a);
        }else if(D == 0){
                r1 = -b / (2 * a);
        }else if(D < 0){
                r1 = 0;
        }
        return r1;
}

int quareq_r2(int a, int b, int c){
        int D, r2;
        D = b * b - 4 * a * c;
        if( D > 0){
                r2 = (-b - sqrt(D)) / (2 * a);
        }else if(D == 0){
                r2 = -b / (2 * a);
        }else if(D < 0){
                r2 = 0;
        }
        return r2;
}

int factorial(int n){												//Now factorial function added in math.h.
	int i;
	int fact = 1;
	int err = 666;
	if(n<0)
		return err;
	else{
		for(i = 1; i<=n; ++i){
			fact *= i;
		}
		return fact;
	}
	return fact;
}

int xpy(int x, int y){			//Get input: X^Y
        int res = 1;				  //Set result to 1 in case y is 0
        while(y!=0){				//While y is NOT 0 i did it when 0 above
                res *= x;			  //Result is x*result until y.
                --y;
        }
        return res;				  //Return the result
}

//  2, 3, 4
int powt(int a){
    xpy(a, 2);							//Better for functions which does not only works in ATOS.
}

int powth(int a){						//Three
    xpy(a, 3);
}

int powf(int a){						//4
    xpy(a, 4);
}

int powfi(int a){						//5
    xpy(a, 5);
}

int log(int a, int b){
                return (b > 1) ? 1 + log(a, b / a) : 0;
}

int LOGICAL(char *l, int a, int b){
	int x;
	if(strcmp(l, "and")==0){
		x = a & b;
		return x;
	}else if(strcmp(l, "or")==0){
		x = a | b;
		return x;
	}else if(strcmp(l, "xor")==0){
		x = a ^ b;
		return x;
	}else{
		x = 0;
		return x;
	}
	return x;
}

int sumofap(int a, int d, int n){
	int i, j;
	n--;
	i = n*d+2*a;
	n++;
	j=n*i/2;
	return j;
}

int soap(int a, int d, int n, int m){		//Sigma Of A.P.
	return sumofap(a, d, n)-sumofap(a, d, m);
}

int expfxlim(bool a, int b, int c, bool inf){				//lim f(x)            f(x)=b^c
	int i;										  //x-->a
	if(a==true){									    //if a is not ∞
		i = xpy(b, c);								//Ut us b^c
	}else if(a==false){								//if a is ∞
		if(inf==true){								//if a is ∞
			i = infinity;							//it is ∞
			return i;
		}else if(inf==false){						//if a is -∞
			i = 0;								//it is 0
			return i;
		}
		return i;
	}
	return i;
}

int devofqf(int a, int x){
	//f(x)=ax^2, then f'(x) = lim = {f(x)-f(k)}/(x-k)
	//			x-->k
	//So a(x+k)(x-k)/(x-k)
	//  = a(x+k)
	//  = ax+ak
	//But x was k bc x-->k when calculating
	//So it is 2ax
	return 2*a*x;	//returning 2ax
}

int fpx(int num1, int num2){
	return num2*xpy(num1, num2-1);
}

int integral(float num1, float num2){
	kk = num2+1;
	return xpy((int)num1, (int)kk)/kk;
}
