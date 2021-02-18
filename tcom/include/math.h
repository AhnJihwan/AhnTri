// Define what ppl use a lot
#define Math_PI = 3.14159265359;					//Stable...
#define ROOT_TWO = 1.414213562373095048801688724209698079;

// Powering 2, 3, 4
int powt(int a){
    return a * a;							//Better for functions which does not only works in ATOS.
}

int powth(int a){
    return a * a * a;
}

int powf(int a){
    return a * a * a * a;
}

int powfi(int a){
    return a * a * a * a * a;
}

int divf(int a, int b){
    if(b == 0){
	printf("Error : Divide by 0");
    }else{
        printf("Division : ");
        print_int(a / b);
    }
}

int addnpth(int a, int b){						//This is for (a+b)^3
    int m = a * a * a;
    int n = b * b * b;
    int mp = 3*a*a*b;
    int np = 3*a*b*b;
    print_int(m + n + mp + np);
}
