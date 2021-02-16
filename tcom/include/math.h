// Define what ppl use a lot
#define Math_PI = 3.14159265359;
#define ROOT_TWO = 1.414213562373095048801688724209698079;

// Powering 2, 3, 4
void powt(int a){
    print_int(a * a);
}

void powth(int a){
    print_int(a * a * a);
}

void powf(int a){
    print_int(a * a * a * a);
}

void powfi(int a){
    print_int(a * a * a * a * a);
}

void addnpth(int a, int b){
    int m = a * a * a;
    int n = b * b * b;
    int mp = 3*a*a*b;
    int np = 3*a*b*b;
    print_int(m + n + mp + np);
}