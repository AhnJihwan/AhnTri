//MSR READ/WRITE(RDMSR WRMSR) FUNTIONS
//MSR to write while busy times

#include "../libc/atclib.h"

#define IA32_P5_MC_ADDR_MSR 0x0H
#define IA32_P5_MC_TYPE_MSR 0x1H
#define IA32_TIME_STAMP_COUNTER_MSR 0x10H
#define IA32_PLATFORM_ID 0x17H
#define IA32_APIC_BASE 0x1BH
#define IA32_TSC_ADJUST 0x3BH
#define IA32_BIOS_UPDt_TRIG 0x79H
#define MSR_EBC_HARD_POWERON 0x2AH
#define IA32_CLOCK_MODULATION 0x19AH
#define IA32_THERM_INTERRUPT 0x198H
#define IA32_THERM_STATUS 0x19CH
#define IA32_MISC_ENABLE 0x1A0H
#define IA32_ENERGY_PERF_BIAS 0x1B0H
#define IA32_PACKAGE_THERM_STATUS 0x1B1H
uint64_t doesthiswork;
//FROM HERE IS THE RDMSR AND WRMSR FUNCTIONS
void rdmsr(uint32_t addr, uint32_t lo, uint32_t hi){
  asm volatile("rdmsr" : "=a"(lo), "=d"(hi) : "c"(addr));
}

void wrmsr(uint32_t addr, uint32_t lo, uint32_t hi){
  asm volatile("wrmsr" : "=a"(lo), "=d"(hi) : "c"(addr));
}

