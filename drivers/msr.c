//MSR READ/WRITE(RDMSR WRMSR) FUNTIONS
//MSR to write while busy times

#include "../libc/atclib.h"

#define IA32_P5_MC_ADDR_MSR 0x0
#define IA32_P5_MC_TYPE_MSR 0x1
#define IA32_TIME_STAMP_COUNTER_MSR 0x10
#define IA32_PLATFORM_ID 0x17
#define IA32_APIC_BASE 0x1B
#define IA32_TSC_ADJUST 0x3B
#define IA32_BIOS_UPDt_TRIG 0x79
#define MSR_EBC_HARD_POWERON 0x2A
#define IA32_CLOCK_MODULATION 0x19A
#define IA32_THERM_INTERRUPT 0x198
#define IA32_THERM_STATUS 0x19C
#define IA32_MISC_ENABLE 0x1A0
#define IA32_ENERGY_PERF_BIAS 0x1B0
#define IA32_PACKAGE_THERM_STATUS 0x1B1

//FROM HERE IS THE RDMSR AND WRMSR FUNCTIONS
uint64_t rdmsr(uint32_t addr){
  uint32_t lo, hi;
  asm volatile("rdmsr" : "=a"(lo), "=d"(hi) : "c"(addr));
  return lo | ((uint64_t)hi << 32);
}

void wrmsr(uint32_t addr, uint32_t lo, uint32_t hi){
  asm volatile("wrmsr" : "=a"(lo), "=d"(hi) : "c"(addr));
}

void ia32_therm_interrupt_f(int numob, bool setornt){
	if(setornt == true){
		if(numob == 0){
			uint64_t hts = rdmsr(IA32_THERM_INTERRUPT);
 		   hts |= (1 << 0);
 		   wrmsr(IA32_THERM_INTERRUPT, (uint32_t)hts, hts >> 32);
 		   printf("High Temperature Interrupt Set.");
		}else if(numob == 1){
 		   uint64_t lts = rdmsr(IA32_THERM_INTERRUPT);
 		   lts |= (1 << 1);
 		   wrmsr(IA32_THERM_INTERRUPT, (uint32_t)lts, lts >> 32);
 		   printf("Low Temperature Interrupt Set.");
 		 }else if(numob == 2 || numob == 3){
 		   uint64_t lts = rdmsr(IA32_THERM_INTERRUPT);
 		   lts |= (1 << 2);
 		   lts |= (1 << 3);
 		   wrmsr(IA32_THERM_INTERRUPT, (uint32_t)lts, lts >> 32);
 		   printf("PROCHOT# and FORCEPR# Log Enabled.");
 		 }
	}else if(setornt == false){
		if(numob == 0){
			uint64_t hts = rdmsr(IA32_THERM_INTERRUPT);
 		   hts |= (0 << 0);
 		   wrmsr(IA32_THERM_INTERRUPT, (uint32_t)hts, hts >> 32);
 		   printf("High Temperature Interrupt Unset.");
		}else if(numob == 1){
 		   uint64_t lts = rdmsr(IA32_THERM_INTERRUPT);
 		   lts |= (0 << 1);
 		   wrmsr(IA32_THERM_INTERRUPT, (uint32_t)lts, lts >> 32);
 		   printf("Low Temperature Interrupt Unset.");
 		 }else if(numob == 2 || numob == 3){
 		   uint64_t lts = rdmsr(IA32_THERM_INTERRUPT);
 		   lts |= (0 << 2);
 		   lts |= (0 << 3);
 		   wrmsr(IA32_THERM_INTERRUPT, (uint32_t)lts, lts >> 32);
 		   printf("PROCHOT# and FORCEPR# Log Disabled.");
 		 }
	}
}

void ia32_energy_pref_status_f(bool set_or_not){
	if(set_or_not == true){
		uint64_t energy = rdmsr(IA32_ENERGY_PERF_BIAS);
		energy |= (1001 << 0);                // Your Eco-friendly 🍀☘🍀☘
		wrmsr(IA32_ENERGY_PERF_BIAS, (uint32_t)energy, energy >> 32);
		printf("Eco mode...");
	} else if(set_or_not == false){
		uint64_t energy = rdmsr(IA32_ENERGY_PERF_BIAS);
		energy |= (0000 << 0);                // Save Energy X
		wrmsr(IA32_ENERGY_PERF_BIAS, (uint32_t)energy, energy >> 32);
		printf("Eco mode off...");
	}
}
