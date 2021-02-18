void exit(){
	printf("\nExiting from AhnTriOS...");
	suspend(OS_suspend*3);
 	clear_screen();
 	printf("Exited...");
	return;
}

/*
For LS@
void exit(){
	printf("Exiting from LS@...");
}
*/
