void remap_pic(){
	outb(0x20, 17);
	outb(0xA0, 17);
	outb(0x21, 32);
	outb(0xA1, 64);
	outb(0x21, 4);
	outb(0xA1, 2);
	outb(0x21, 1);
	outb(0xA1, 1);
	outb(0x21, 0);
	outb(0xA1, 0);
}


void irq0_handler(void) {
          outb(32, 32);
}
 
void irq1_handler(void) {
	  outb(32, 32);
}
 
void irq2_handler(void) {
          outb(32, 32);
}
 
void irq3_handler(void) {
          outb(32, 32);
}
 
void irq4_handler(void) {
          outb(32, 32);
}
 
void irq5_handler(void) {
          outb(32, 32);
}
 
void irq6_handler(void) {
          outb(32, 32);
}
 
void irq7_handler(void) {
          outb(32, 32);
}
 
void irq8_handler(void) {
          outb(160, 32);
          outb(32, 32);          
}
 
void irq9_handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq10_handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq11_handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq12_handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq13_handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq14_handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq15_handler(void) {
          outb(160, 32);
          outb(32, 32);
}
