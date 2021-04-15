void exit(){
	printf("\nGoing back to AhnTri Main Kernel");
	suspend(OS_suspend*3);
 	clear_screen();
 	printf("Exited...");
	asm volatile("hlt");
}
