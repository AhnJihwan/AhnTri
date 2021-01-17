/*
This is not mine, this is some code from other github content called 'OS' which I
Leaned from
*/

int digit_ascii_codes[10] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};

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

void cpuid(uint32 value, uint32 *eax, uint32 *ebx, unsigned int *ecx, uint32 *edx)
{
  uint32 eaxres, ebxres, ecxres, edxres;
  asm("xorl\t%eax, %eax");
  asm("xorl\t%ebx, %ebx");
  asm("xorl\t%ecx, %ecx");
  asm("xorl\t%edx, %edx");
  asm("movl\t%0, %%eax":"=m"(value));
  asm("cpuid");
  asm("movl\t%%eax, %0" : "=m" (eaxres));
  asm("movl\t%%ebx, %0" : "=m" (ebxres));
  asm("movl\t%%ecx, %0" : "=m" (ecxres));
  asm("movl\t%%edx, %0" : "=m" (edxres));
  *eax = eaxres;
  *ebx = ebxres;
  *ecx = ecxres;
  *edx = edxres;    
}

void print_eax(uint32 eax)
{
  uint32 step_id, model, family_id, proc_type, ext_mod_id, ext_fam_id;
  step_id = model = family_id = proc_type = ext_mod_id = ext_fam_id = eax;
  
  step_id &= (2 << 3) - 1;
  model >>= 4;	//bits 4-7
  model &= (2 << 3) - 1;
  family_id >>= 8;	//bits 8-11
  family_id &= (2 << 3) - 1;
  proc_type >>= 12;	//bits 12-13
  proc_type &= (2 << 1) - 1;
  ext_mod_id >>= 16;	//bits 16-19
  ext_mod_id &= (2 << 3) - 1;
  ext_fam_id >>= 20;	//bits 20-27
  ext_fam_id &= (2 << 7) - 1;

  os_print_string("\nEAX :-");
  os_print_string("\n\tStepping ID: ");
  print_int(step_id);
  os_print_string("\n\tModel: ");
  print_int(model);
  os_print_string("\n\tFamily ID: ");
  print_int(family_id);
  os_print_string("\n\tProcessor Type: ");
  print_int(proc_type);
  os_print_string("\n\tExtended Model ID: ");
  print_int(ext_mod_id);
  os_print_string("\n\tExtended Family ID: ");
  print_int(ext_fam_id);
}

void print_ebx(uint32 ebx)
{
  uint32 brand_index, cache_line_size, max_addr_id, init_apic_id;
  brand_index = cache_line_size = max_addr_id = init_apic_id = 0;
  char *bytes = (char*)&ebx;

  brand_index = bytes[0];	//bits 0-7
  cache_line_size = bytes[1];	//bits 8-15
  max_addr_id = bytes[2];	//bits 16-23
  init_apic_id = bytes[3];	//bits 24-31

  os_print_string("\nEBX :-");
  os_print_string("\n\tBrand Index: ");
  print_int(brand_index);
  os_print_string("\n\tCache Line Size: ");
  print_int(cache_line_size);
  os_print_string("\n\tMax Addressable ID for Logical Processors: ");
  print_int(max_addr_id);
  os_print_string("\n\tInitial APIC ID: ");
  print_int(init_apic_id);
}

void print_edx(uint32 edx)
{
  os_print_string("\nEDX :-");
  os_print_string("\n\tbit-31 [ ");
  print_binary(edx);
  os_print_string(" ] bit-0");
  os_print_string("\n\tBit 0 : FPU-x87 FPU on Chip");
  os_print_string("\n\tBit 1 : VME-Virtual-8086 Mode Enhancement");
  os_print_string("\n\tBit 2 : DE-Debugging Extensions");
  os_print_string("\n\tBit 3 : PSE-Page Size Extensions");
  os_print_string("\n\tBit 4 : TSC-Time Stamp Counter");
  os_print_string("\n\tBit 5 : MSR-RDMSR and WRMSR Support");
  os_print_string("\n\tBit 6 : PAE-Physical Address Extensions");
}

void cpuid_test()
{
  uint32 eax, ebx, ecx, edx;

  os_print_string("CPUID EAX = 01H");
  cpuid(0x01, &eax, &ebx, &ecx, &edx);

  print_eax(eax);
  print_ebx(ebx);
  print_edx(edx);
}

void cputest()
{
  init_vga(GREEN, BLACK);
  cpuid_test();
}


