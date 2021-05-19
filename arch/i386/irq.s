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

irq0:
  pusha
  outb %0x20, %0x20
  popa
  iret
 
irq1:
  pusha
  outb %0x20, %0x20
  popa
  iret
 
irq2:
  pusha
  outb %0x20, %0x20
  popa
  iret
 
irq3:
  pusha
  outb %0x20, %0x20
  popa
  iret
 
irq4:
  pusha
  outb %0x20, %0x20
  popa
  iret
 
irq5:
  pusha
  outb %0x20, %0x20
  popa
  iret
 
irq6:
  pusha
  outb %0x20, %0x20
  popa
  iret
 
irq7:
  pusha
  outb %0x20, %0x20
  popa
  iret
 
irq8:
  pusha
  outb %0x20, %0xA0
  outb %0x20, %0x20
  popa
  iret
 
irq9:
  pusha
  outb %0x20, %0xA0
  outb %0x20, %0x20
  popa
  iret
 
irq10:
  pusha
  outb %0x20, %0xA0
  outb %0x20, %0x20
  popa
  iret
 
irq11:
  pusha
  outb %0x20, %0xA0
  outb %0x20, %0x20
  popa
  iret
 
irq12:
  pusha
  outb %0x20, %0xA0
  outb %0x20, %0x20
  popa
  iret
 
irq13:
  pusha
  outb %0x20, %0xA0
  outb %0x20, %0x20
  popa
  iret
 
irq14:
  pusha
  outb %0x20, %0xA0
  outb %0x20, %0x20
  popa
  iret
 
irq15:
  pusha
  outb %0x20, %0xA0
  outb %0x20, %0x20
  popa
  iret
 
