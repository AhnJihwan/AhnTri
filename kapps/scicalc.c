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

#define molarity(x) (x * 2)
//Never use this to H... H is still 1

#define NumAvogadroOversimplified 6 //.02*10^23

int findmolweight(int element, int numbers){
  if(element != H){
    return molarity(element) * numbers;
  }else if(element == H){
    return numbers;
  }
}
