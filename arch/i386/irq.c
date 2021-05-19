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

void irq0handler(void) {
          outb(32, 32);
}
 
void irq1handler(void) {
	  outb(32, 32);
}
 
void irq2handler(void) {
          outb(32, 32);
}
 
void irq3handler(void) {
          outb(32, 32);
}
 
void irq4handler(void) {
          outb(32, 32);
}
 
void irq5handler(void) {
          outb(32, 32);
}
 
void irq6handler(void) {
          outb(32, 32);
}
 
void irq7handler(void) {
          outb(32, 32);
}
 
void irq8handler(void) {
          outb(160, 32);
          outb(32, 32);          
}
 
void irq9handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq10handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq11handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq12handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq13handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq14handler(void) {
          outb(160, 32);
          outb(32, 32);
}
 
void irq15handler(void) {
          outb(160, 32);
          outb(32, 32);
}
