.global irq0
.global irq1
.global irq2
.global irq3
.global irq4
.global irq5
.global irq6
.global irq7
.global irq8
.global irq9
.global irq10
.global irq11
.global irq12
.global irq13
.global irq14
.global irq15

.extern irq0handler
.extern irq1handler
.extern irq2handler
.extern irq3handler
.extern irq4handler
.extern irq5handler
.extern irq6handler
.extern irq7handler
.extern irq8handler
.extern irq9handler
.extern irq10handler
.extern irq11handler
.extern irq12handler
.extern irq13handler
.extern irq14handler
.extern irq15handler
 
irq0:
  cli
  push $0
  push $32
  jmp irq_stub
 
irq1:
  cli
  push $0
  push $33
  jmp irq_stub

irq2:
  cli
  push $0
  push $34
  jmp irq_stub

irq3:
  cli
  push $0
  push $35
  jmp irq_stub

irq4:
  cli
  push $0
  push $36
  jmp irq_stub

irq5:
  cli
  push $0
  push $37
  jmp irq_stub

irq6:
  cli
  push $0
  push $38
  jmp irq_stub

irq7:
  cli
  push $0
  push $39
  jmp irq_stub

irq8:
  cli
  push $0
  push $40
  jmp irq_stub

irq9:
  cli
  push $0
  push $41
  jmp irq_stub

irq10:
  cli
  push $0
  push $42
  jmp irq_stub

irq11:
  cli
  push $0
  push $43
  jmp irq_stub

irq12:
  cli
  push $0
  push $44
  jmp irq_stub

irq13:
  cli
  push $0
  push $46
  jmp irq_stub

irq14:
  cli
  push $0
  push $47
  jmp irq_stub

irq15:
  cli
  push $0
  push $48
  jmp irq_stub
  

irq_stub: 
    pusha                    # Pushes edi,esi,ebp,esp,ebx,edx,ecx,eax

    movw %ds,%ax             # Lower 16-bits of eax = ds.
    pushl %eax               # save the data segment descriptor

    movw $0x10,%ax # load the kernel data segment descriptor
    movw %ax,%ds
    movw %ax,%es
    movw %ax,%fs
    movw %ax,%gs

    call irq_handler

    popl %ebx      # reload the original data segment descriptor
    movw %bx,%ds
    movw %bx,%es
    movw %bx,%fs
    movw %bx,%gs

    popa                     # Pops edi,esi,ebp...
    addl $8,%esp   # Cleans up the pushed error code and pushed ISR number
    sti
    iret           # pops 5 things at once: CS, EIP, EFLAGS, SS, and ESP


