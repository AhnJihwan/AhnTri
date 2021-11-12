void print_binary(uint32 num)
{
  char bin_arr[32];
  uint32 index = 31;
  uint32 i;
  while (num > 0){
    if(num & 1){
      bin_arr[index] = '1';
    }else{
      bin_arr[index] = '0';
    }
    index--;
    num >>= 1;
  }

  for(i = 0; i < 32; ++i){
   if(i <= index)
      print_char('0');
   else
     print_char(bin_arr[i]);
  }
}

void print_edx(uint32 edx)
{
  printf("\nEDX :-");
  printf("\n\tbit-31 [ ");
  print_binary(edx);
  printf(" ] bit-0");
  printf("\n\tBit 0 : FPU-x87 FPU on Chip");
  printf("\n\tBit 1 : VME-Virtual-8086 Mode Enhancement");
  printf("\n\tBit 2 : DE-Debugging Extensions");
  printf("\n\tBit 3 : PSE-Page Size Extensions");
  printf("\n\tBit 4 : TSC-Time Stamp Counter");
  printf("\n\tBit 5 : MSR-RDMSR and WRMSR Support");
  printf("\n\tBit 6 : PAE-Physical Address Extensions");
}

static inline void cpuid_ii(int code, uint32_t *a, uint32_t *d) {
  asm volatile("cpuid":"=a"(*a),"=d"(*d):"a"(code):"ecx","ebx");
}

#define cpuid(in, eax, ebx, ecx, edx) __asm__("cpuid": "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (in));

void cpuid_test(void)
{
	uint32_t eax, ebx, ecx, edx;
	cpuid(0x00, eax, ebx, ecx, edx);
	printf("CPU YOU ARE USING:\n");
	switch(ebx) {
		case 0x756e6547:
		printf("You are using an Intel CPU.\n\n");
		break;
		case 0x68747541:
		printf("You are using an AMD CPU.\n");
		break;
		default:
		printf("You are using neither Intel or AMD processer.\n");
		break;
	}
	return 0;
}

void cputest()
{
  cpuid_test();
}


