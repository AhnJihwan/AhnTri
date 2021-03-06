#define IRQ0 32
#define IRQI 33
#define IRQII 34
#define IRQIII 35
#define IRQIV 36
#define IRQV 37
#define IRQVI 38
#define IRQVII 39
#define IRQVIII 40
#define IRQIX 41
#define IRQX 42
#define IRQXI 43
#define IRQXII 44
#define IRQXIII 45
#define IRQXIV 46
#define IRQXV 47

struct regs
{
    unsigned int gs, fs, es, ds;      /* pushed the segs last */
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
    unsigned int int_no, err_code;    /* our 'push byte #' and ecodes do this */
    unsigned int eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */ 
};

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

extern void irq_install();
