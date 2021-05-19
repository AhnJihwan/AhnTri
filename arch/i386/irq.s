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

.global irq0handler
.global irq1handler
.global irq2handler
.global irq3handler
.global irq4handler
.global irq5handler
.global irq6handler
.global irq7handler
.global irq8handler
.global irq9handler
.global irq10handler
.global irq11handler
.global irq12handler
.global irq13handler
.global irq14handler
.global irq15handler
 
extern irq0handler
extern irq1handler
extern irq2handler
extern irq3handler
extern irq4handler
extern irq5handler
extern irq6handler
extern irq7handler
extern irq8handler
extern irq9handler
extern irq10handler
extern irq11handler
extern irq12handler
extern irq13handler
extern irq14handler
extern irq15handler
 
irq0:
  pusha
  call irq0handler
  popa
  iret
 
irq1:
  pusha
  call irq1handler
  popa
  iret
 
irq2:
  pusha
  call irq2handler
  popa
  iret
 
irq3:
  pusha
  call irq3handler
  popa
  iret
 
irq4:
  pusha
  call irq4handler
  popa
  iret
 
irq5:
  pusha
  call irq5handler
  popa
  iret
 
irq6:
  pusha
  call irq6handler
  popa
  iret
 
irq7:
  pusha
  call irq7handler
  popa
  iret
 
irq8:
  pusha
  call irq8handler
  popa
  iret
 
irq9:
  pusha
  call irq9handler
  popa
  iret
 
irq10:
  pusha
  call irq10handler
  popa
  iret
 
irq11:
  pusha
  call irq11handler
  popa
  iret
 
irq12:
  pusha
  call irq12handler
  popa
  iret
 
irq13:
  pusha
  call irq13handler
  popa
  iret
 
irq14:
  pusha
  call irq14handler
  popa
  iret
 
irq15:
  pusha
  call irq15handler
  popa
  iret
 
