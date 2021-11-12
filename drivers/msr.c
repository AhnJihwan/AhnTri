//MSR to write while busy times

#include "../libc/atclib.h"

#define PENTIRUM4_INTELXEON_IA32_P5_MC_ADDR_MSR 0x0H

void rdmsr(uint32_t addr, uint32_t lo, uint32_t hi){
  asm volatile("rdmsr" : "=a"(lo), "=d"(hi) : "c"(addr));
}

void wrmsr(uint32_t addr, uint32_t lo, uint32_t hi){
  asm volatile("wrmsr" : "=a"(lo), "=d"(hi) : "c"(addr));
}
