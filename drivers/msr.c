//MSR to write while busy times

#include "../libc/atclib.h"

#define PENTIUM4_INTELXEON_IA32_P5_MC_ADDR_MSR 0x0H
#define PENTIUM4_INTELXEON_IA32_P5_MC_TYPE_MSR 0x1H
#define PENTIUM4_INTELXEON_IA32_TIME_STAMP_COUNTER_MSR 0x10H
#define PENTIUM_INTELXEON_IA32_PLATFORM_ID 0x17H
#define PENTIUM_INTELXEON_IA32_APIC_BASE 0x1BH
#define PENTIUM_INTELXEON_MSR_EBC_HARD_POWERON 0x2AH

void rdmsr(uint32_t addr, uint32_t lo, uint32_t hi){
  asm volatile("rdmsr" : "=a"(lo), "=d"(hi) : "c"(addr));
}

void wrmsr(uint32_t addr, uint32_t lo, uint32_t hi){
  asm volatile("wrmsr" : "=a"(lo), "=d"(hi) : "c"(addr));
}
