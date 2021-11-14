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

void rdmsr(uint32_t addr, uint32_t lo, uint32_t hi){
  asm volatile("rdmsr" : "=a"(lo), "=d"(hi) : "c"(addr));
}

void wrmsr(uint32_t addr, uint32_t lo, uint32_t hi){
  asm volatile("wrmsr" : "=a"(lo), "=d"(hi) : "c"(addr));
}
