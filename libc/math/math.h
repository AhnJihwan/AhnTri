//Lot of functions
//such like powers, square roots, division, (a+b)^3, and Quaderic Equation Root 1, 2.
// Define what ppl use a lot
#define Math_PI = 3.14159265359;					//Stable...
#define ROOT_TWO = 1.414213562373095048801688724209698079;

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
