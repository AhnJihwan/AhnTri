#include "../kernel.h"
#include "../libc/atclib.h"

void covidhelper(int temp, int spo2){
  if(temp <= 98){
    printf("Normal Temperature\n");
  } else{
    printf("Might be infected. Take the COVID test!\n");
  }
  if(spo2 >= 94){
    printf("SpO2 Normal\n");
  }else if(spo2 < 94 && spo2 >= 90){
    printf("SpO2 Not bad...\n");
  }else{
    printf("Might be dangerous.\n");
  }
}

void covidhelperkapp(){
  int temp_covid, spo2_covid;
  printf("Your Temperature(*F): ");
  temp_covid = read_int();
  printf("SpO2 number given: ");
  spo2_covid = read_int();
  covidhelper(temp_covid, spo2_covid);
  printf("If you use celcius, consider that normal temp of C is 36~37 degrees celcius.\n");
}
