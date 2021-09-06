#include "../../libc/atclib.h"
#include "isr.h"
#define INT_STOP asm volatile("cli") //Thank you, u/jtsiomb and u/Ayush7788!

static struct registers* current_regs = NULL;

void cli(){
  asm volatile("cli");                                 //Thank you, u/Bob-The-One!
}

// if no interrupt found then push interrupt no into stack
// for int instruction

void isr_0_handler(){
  if(current_regs == NULL)
    return;
  printf("isr 0 handler called\n");
  printf("#DE Division Error. You cannot divide by 0 obviously.\n");
}

void isr_1_handler(){
  printf("isr I handler called\n");
  printf("#DE Debug Exception. Reserved by ");
  framebuffer_putstr("intel\n", 0x0071c5);
}

void isr_2_handler(){
  printf("isr II handler called\n");
  printf("I'm a NMI Interrupt.\n");
}

void isr_3_handler(){
  printf("isr III handler called\n");
  printf("#BP Breakpoint Exception. Breakpoint is trapped.\n");
}

void isr_4_handler(){
  printf("isr IV handler called\n");
  printf("#OF An overflow trap occurred when an INTO instruction was executed.\n");
}

void isr_5_handler(){
  printf("isr V handler called\n");
  printf("#BR Bound Instruction executed fault.\n");
}

void isr_6_handler(){
  printf("isr VI handler called\n");
  printf("#UD Invalid Opcode Exception Fault.\n");
}

void isr_7_handler(){
  printf("isr VII handler called\n");
  printf("#NM Device Not Available right now.\n");
}

void isr_8_handler(){
  printf("isr VIII handler called\n");
  printf(":/ Double Fault.\n");
}

void isr_9_handler(){
  printf("isr IX handler called\n");
  printf("Coprocessor Segment Overrun.");
  framebuffer_putstr("intel\n", 0x0071c5);
}

void isr_10_handler(){
  printf("isr X handler called\n");
  printf("Task switch attempted, invalid information was detected in the TSS for the target task.\n");
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
