#ifndef ISR_H
#define ISR_H
/*Organizing the Source Code of OS*/
#include "../kio/types.h"
/*Defining IRQs with roman numerals*/
#define IRQ0 32		//Programmable Interrupt Timer Interrupt
#define IRQI 33		//Keyboard Interrupt	
#define IRQII 34	//Cascade (used internally by the two PICs. never raised)
#define IRQIII 35	//COM2 - enabled (x)
#define IRQIV 36	//COM1 - enabled (x)
#define IRQV 37		//LPT2 - enabled (x)
#define IRQVI 38	//Floppy Disk
#define IRQVII 39	//LPT1 / Unreliable "spurious" interrupt (usually)
#define IRQVIII 40	//CMOS real-time clock (if enabled)
#define IRQIX 41	//Free for peripherals / legacy SCSI / NIC
#define IRQX 42
#define IRQXI 43
#define IRQXII 44
#define IRQXIII 45
#define IRQXIV 46
#define IRQXV 47
/*Defining Resisters*/
typedef struct registers
{
  uint32 ds;
  uint32 edi, esi, ebp, esp, ebx, edx, ecx, eax;  // pushed by pusha
  uint32 int_no, err_code;  // interrupt number and error code
  uint32 eip, cs, eflags, useresp, ss;  // pushed by the processor automatically
} registers_t;
/*Defining ISR_T*/
typedef void (*isr_t)(registers_t);
/*============================Handlers=================================*/
extern void isr_0();
extern void isr_1();
extern void isr_2();
extern void isr_3();
extern void isr_4();
extern void isr_5();
extern void isr_6();
extern void isr_7();
extern void isr_8();
extern void isr_9();
extern void isr_10();
extern void isr_11();
extern void isr_12();
extern void isr_13();
extern void isr_14();
extern void isr_15();
extern void isr_16();
extern void isr_17();
extern void isr_18();
extern void isr_19();
extern void isr_20();
extern void isr_21();
extern void isr_22();
extern void isr_23();
extern void isr_24();
extern void isr_25();
extern void isr_26();
extern void isr_27();
extern void isr_28();
extern void isr_29();
extern void isr_30();
extern void isr_31();

extern void common_isr_stub_handler();
void isr_handler(struct registers);

void isr_0_handler();
void isr_1_handler();
void isr_2_handler();
void isr_3_handler();
void isr_4_handler();
void isr_5_handler();
void isr_6_handler();
void isr_7_handler();
void isr_8_handler();
void isr_9_handler();
void isr_10_handler();
void isr_11_handler();
void isr_12_handler();
void isr_13_handler();
void isr_14_handler();
void isr_15_handler();
void isr_16_handler();
void isr_17_handler();
void isr_18_handler();
void isr_19_handler();
void isr_20_handler();
void isr_21_handler();
void isr_22_handler();
void isr_23_handler();
void isr_24_handler();
void isr_25_handler();
void isr_26_handler();
void isr_27_handler();
void isr_28_handler();
void isr_29_handler();
void isr_30_handler();
void isr_31_handler();

#endif
