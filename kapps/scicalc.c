//SCIENCE CALCULATOR
//CHEMISTRY | PYSICS
//MADE FOR MY REAL-LIFE SCIENCE SKILL PRACTICE AS WELL AS I DID FOR CCALC-MATH AND FDIC(NEW, THE OLD ONES AREN'T FOR MY REAL-LIFE)-ENGLISH
//COPYRIGHT 2021 JIHWAN AHN
//AHNTRI SCIENCE CALCULATOR IS A PART OF AHNTRI OS AND IS ALSO PROTECTED BY APACHE 2.0 LICENCE AS WELL AS OTHER CHUNKS OF CODE.

//Elements
#define H 1
#define He 2
#define Li 3
#define Be 4
#define B 5
#define C 6
#define N 7
#define O 8
#define F 9
#define Ne 10
#define Na 11
#define Mg 12
#define Al 13
#define Si 14
#define P 15
#define S 16
#define Cl 17
#define Ar 18
#define K 19
#define Ca 20

int metal[6] = {Li, Be, Na, Mg, K, Ca};
int nonmetal[11] = {H, He, C, N, O, F, Ne, P, S, Cl, Ar};

char periodic[19][2] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca"};

struct chem{
  int h;
  int he;
  int li;
  int be;
  int b;
  int c;
  int n;
  int o;
  int f;
  int ne;
  int na;
  int mg;
  int al;
  int si;
  int p;
  int s;
  int cl;
  int ar;
  int k;
  int ca;
} chem_t;

void chem_periodic(){
  int i;
  for(i=0; i<=20; i++){
    printf(periodic[i][2]);
    printf(", ");
  }
}
