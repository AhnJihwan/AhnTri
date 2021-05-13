#include "../kernel.h"
#include "../init/api.h" 
#include "isr.h"
#define INT_STOP asm volatile("cli") //Thank you, u/jtsiomb and u/Ayush7788!

static struct registers* current_regs = NULL;

void cli(){
  asm volatile("cli");                                 //Thank you, u/Bob-The-One!
}

isr_t ihs[256];

void irq_handler(registers_t regs)
{
    // Send an EOI (end of interrupt) signal to the PICs.
    // If this interrupt involved the slave.
    if (regs.int_no >= 40)
    {
        // Send reset signal to slave.
        outb(0xA0, 0x20);
    }
    // Send reset signal to master. (As well as slave, if necessary).
    outb(0x20, 0x20);

    if (ihs[regs.int_no] != 0)
    {
        isr_t handler = ihs[regs.int_no];
        handler(regs);
    }

}

// if no interrupt found then push interrupt no into stack
// for int instruction
void isr_0(){
  asm volatile("\tcli");
  asm volatile("\tpush $0");
  asm volatile("\tpush $0");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_1(){
  asm volatile("\tcli");
  asm volatile("\tpush $1");
  asm volatile("\tpush $1");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_2(){
  asm volatile("\tcli");
  asm volatile("\tpush $2");
  asm volatile("\tpush $2");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_3(){
  asm volatile("\tcli");
  asm volatile("\tpush $3");
  asm volatile("\tpush $3");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_4(){
  asm volatile("\tcli");
  asm volatile("\tpush $4");
  asm volatile("\tpush $4");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_5(){
  asm volatile("\tcli");
  asm volatile("\tpush $5");
  asm volatile("\tpush $5");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_6(){
  asm volatile("\tcli");
  asm volatile("\tpush $6");
  asm volatile("\tpush $6");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_7(){
  asm volatile("\tcli");
  asm volatile("\tpush $7");
  asm volatile("\tpush $7");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_8(){
  asm volatile("\tcli");
  asm volatile("\tpush $8");
  asm volatile("\tpush $8");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_9(){
  asm volatile("\tcli");
  asm volatile("\tpush $9");
  asm volatile("\tpush $9");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_10(){
  asm volatile("\tcli");
  asm volatile("\tpush $10");
  asm volatile("\tpush $10");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_11(){
  asm volatile("\tcli");
  asm volatile("\tpush $11");
  asm volatile("\tpush $11");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_12(){
  asm volatile("\tcli");
  asm volatile("\tpush $12");
  asm volatile("\tpush $12");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_13(){
  asm volatile("\tcli");
  asm volatile("\tpush $13");
  asm volatile("\tpush $13");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_14(){
  asm volatile("\tcli");
  asm volatile("\tpush $14");
  asm volatile("\tpush $14");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_15(){
  asm volatile("\tcli");
  asm volatile("\tpush $15");
  asm volatile("\tpush $15");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_16(){
  asm volatile("\tcli");
  asm volatile("\tpush $16");
  asm volatile("\tpush $16");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_17(){
  asm volatile("\tcli");
  asm volatile("\tpush $17");
  asm volatile("\tpush $17");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_18(){
	asm volatile("\tcli");
	asm volatile("\tpush $18");
	asm volatile("\tpush $18");
	asm volatile("\tjmp common_isr_stub_handler");
}

void isr_19(){
	asm volatile("\tcli");
	asm volatile("\tpush $19");
	asm volatile("\tpush $19");
	asm volatile("\tjmp common_isr_stub_handler");
}

void isr_20(){
  asm volatile("\tcli");
  asm volatile("\tpush $20");
  asm volatile("\tpush $20");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_21(){
  asm volatile("\tcli");
  asm volatile("\tpush $21");
  asm volatile("\tpush $21");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_22(){
  asm volatile("\tcli");
  asm volatile("\tpush $22");
  asm volatile("\tpush $22");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_23(){
  asm volatile("\tcli");
  asm volatile("\tpush $23");
  asm volatile("\tpush $23");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_24(){
  asm volatile("\tcli");
  asm volatile("\tpush $24");
  asm volatile("\tpush $24");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_25(){
  asm volatile("\tcli");
  asm volatile("\tpush $25");
  asm volatile("\tpush $25");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_26(){
  asm volatile("\tcli");
  asm volatile("\tpush $26");
  asm volatile("\tpush $26");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_27(){
  asm volatile("\tcli");
  asm volatile("\tpush $27");
  asm volatile("\tpush $27");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_28(){
  asm volatile("\tcli");
  asm volatile("\tpush $28");
  asm volatile("\tpush $28");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_29(){
  asm volatile("\tcli");
  asm volatile("\tpush $29");
  asm volatile("\tpush $29");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_30(){
  asm volatile("\tcli");
  asm volatile("\tpush $30");
  asm volatile("\tpush $30");
  asm volatile("\tjmp common_isr_stub_handler");
}

void isr_31(){
  asm volatile("\tcli");
  asm volatile("\tpush $31");
  asm volatile("\tpush $31");
  asm volatile("\tjmp common_isr_stub_handler");
}
//My hand hurts a lot...

void common_isr_stub_handler(){
  // save all registers
  asm volatile("\tpusha");
  // save ds segment
  asm volatile("\tmov %ds, %eax");
  asm volatile("\tpush %eax");
  // load new data segment for handling interrupt
  asm volatile("\tmov $0x10, %eax");
  asm volatile("\tmov %eax, %ds");
  asm volatile("\tmov %eax, %es");
  asm volatile("\tmov %eax, %fs");
  asm volatile("\tmov %eax, %gs");
  // call common interrupt handler
  asm volatile("\tcall isr_handler");
  // get original ds segment
  asm volatile("\tpop %eax");
  // set its value to other segments
  asm volatile("\tmov %eax, %ds");
  asm volatile("\tmov %eax, %es");
  asm volatile("\tmov %eax, %fs");
  asm volatile("\tmov %eax, %gs");
  // restore all registers
  asm volatile("\tpopa");
  // restore stack space pushed by isr_n() routines
  // by pushing its isr number into stack
  asm volatile("\tadd $8, %esp");
  // store interrupt which was cleared by isr_n()
  asm volatile("\tsti");
  // return after handling interrupt
  asm volatile("\tiret");
}

void isr_0_handler(){
  if(current_regs == NULL)
    return;
  printf("isr_0_handler called,  ");
  printf("Value of eax: ");
  print_int(current_regs->eax);
  printf("\n");
}

void isr_1_handler(){
  printf("isr_1_handler called\n");
}

void isr_2_handler(){
  printf("isr_2_handler called\n");
}

void isr_3_handler(){
  printf("isr_3_handler called\n");
}

void isr_4_handler(){
  printf("isr_4_handler called\n");
}

void isr_5_handler(){
  printf("isr_5_handler called\n");
}

void isr_6_handler(){
  printf("isr_6_handler called\n");
}

void isr_7_handler(){
  printf("isr_7_handler called\n");
}

void isr_8_handler(){
  printf("isr_8_handler called\n");
}

void isr_9_handler(){
  printf("isr_9_handler called\n");
}

void isr_10_handler(){
  printf("isr_10_handler called\n");
}

void isr_11_handler(){
  printf("isr_11_handler called\n");
}

void isr_12_handler(){
  printf("isr_12_handler called\n");
}

void isr_13_handler(){
  printf("isr_13_handler called\n");
}

void isr_14_handler(){
  printf("isr_14_handler called\n");
}

void isr_15_handler(){
  printf("isr_15_handler called\n");
}

void isr_16_handler(){
  printf("isr_16_handler called\n");
}

void isr_17_handler(){
  printf("isr_17_handler called\n");
}

void isr_18_handler(){
  printf("isr_18_handler called\n");
}

void isr_19_handler(){
  printf("isr_19_handler called\n");
}

void isr_20_handler(){
  printf("isr_20_handler called\n");
}
void isr_21_handler(){
  printf("isr_21_handler called\n");
}

void isr_22_handler(){
  printf("isr_22_handler called\n");
}

void isr_23_handler(){
  printf("isr_23_handler called\n");
}

void isr_24_handler(){
  printf("isr_24_handler called\n");
}

void isr_25_handler(){
  printf("isr_25_handler called\n");
}

void isr_26_handler(){
  printf("isr_26_handler called\n");
}

void isr_27_handler(){
  printf("isr_27_handler called\n");
}

void isr_28_handler(){
  printf("isr_28_handler called\n");
}

void isr_29_handler(){
  printf("isr_29_handler called\n");
}

void isr_30_handler(){
  printf("isr_30_handler called\n");
}

void isr_31_handler(){
  printf("isr_31_handler called\n");
}

void isr_handler(struct registers regs){
  current_regs = (struct registers*)&regs;
  switch(regs.int_no){
    case 0:
      isr_0_handler();
      break;
    case 1:
      isr_1_handler();
      break;
    case 2:
      isr_2_handler();
      break;
    case 3:
      isr_3_handler();
      break;
    case 4:
      isr_4_handler();
      break;
    case 5:
      isr_5_handler();
      break;
    case 6:
      isr_6_handler();
      break;
    case 7:
      isr_7_handler();
      break;
    case 8:
      isr_8_handler();
      break;
    case 9:
      isr_9_handler();
      break;
    case 10:
      isr_10_handler();
      break;
    case 11:
      isr_11_handler();
      break;
    case 12:
      isr_12_handler();
      break;
    case 13:
      isr_13_handler();
      break;
    case 14:
      isr_14_handler();
      break;
    case 15:
      isr_15_handler();
      break;
    case 16:
      isr_16_handler();
      break;
    case 17:
      isr_17_handler();
      break;
    case 18:
      isr_18_handler();
      break;
    case 19:
      isr_19_handler();
      break;
    case 20:
      isr_20_handler();
      break;
    case 21:
      isr_21_handler();
      break;
    case 22:
      isr_22_handler();
      break;
    case 23:
      isr_23_handler();
      break;
    case 24:
      isr_24_handler();
      break;
    case 25:
      isr_25_handler();
      break;
    case 26:
      isr_26_handler();
      break;
    case 27:
      isr_27_handler();
      break;
    case 28:
      isr_28_handler();
      break;
    case 29:
      isr_29_handler();
      break;
    case 30:
      isr_30_handler();
      break;
    case 31:
      isr_31_handler();
      break;
    default:
      printf("interrupt handler");
      break;
  }
  current_regs = NULL;
} 
