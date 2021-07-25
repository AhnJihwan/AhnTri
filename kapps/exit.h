void exit(){
	printf("\nGoing back to AhnTri Main Kernel");
	suspend(OS_suspend*3);
 	printf("Exited...");
	asm volatile("hlt");
}
