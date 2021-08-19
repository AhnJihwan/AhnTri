#define CHECK_FLAG_MMAP(flags,bit)   ((flags) & (1 << (bit)))
void printf_mmap_addr(multiboot_info_t *mbi){
  if(CHECK_FLAG_MMAP (mbi->flags, 6)){
    printf("memory map adress: ");
    printf_hex(mbi->mmap_addr);
  }
}


extern uint8_t *_kernel_start;
extern uint8_t *_kernel_end;

extern uint8_t *_kernel_start_of_text;
extern uint8_t *_kernel_end_of_text;

extern uint8_t *_kernel_start_of_rodata;
extern uint8_t *_kernel_end_of_rodata;

extern uint8_t *_kernel_start_of_data;
extern uint8_t *_kernel_end_of_data;

extern uint8_t *_kernel_start_of_bss;
extern uint8_t *_kernel_end_of_bss;

void print_kernel_map(void) {
    printf("\n\nKernel Memory Map:\n\n");
    printf("kernel: ");
    printf_hex(&_kernel_start);
    printf("-");
    printf_hex(&_kernel_end);
    printf("\n\ntext: ");
    printf_hex(&_kernel_start_of_text);
    printf("-");
    printf_hex(&_kernel_end_of_text);
    printf("\n\nrodata: ");
    printf_hex(&_kernel_start_of_rodata);
    printf("-");
    printf_hex(&_kernel_end_of_rodata);
    printf("\n\ndata: ");
    printf_hex(&_kernel_start_of_data);
    printf("-");
    printf_hex(&_kernel_end_of_data);
    printf("\n\nbss: ");
    printf_hex(&_kernel_start_of_bss);
    printf("-");
    printf_hex(&_kernel_end_of_bss);
}


