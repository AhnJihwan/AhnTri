//MSR to write while busy times

#define PENTIRUM4_INTELXEON_IA32_P5_MC_ADDR_MSR 0x0H

void rdmsr(uint32_t addr, uint32_t lo, uint32_t hi){
  asm volatile("rdmsr" : "=a"(*lo), "=b"(*hi) : "c"(msr));
}

void wrmsr(uint32_t addr, uint32_t lo, uint32_t hi){
  asm volatile("wrmsr" : "=a"(*lo), "=b"(*hi) : "c"(msr));
}
