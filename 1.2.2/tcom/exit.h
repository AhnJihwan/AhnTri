void exit(){
	os_print_string("\nExiting from AhnTriOS...");
	suspend(OS_suspend*3);
 	clear_screen();
 	os_print_string("Exited...");
	return;
}

/*
For LS@
void exit(){
	printf("Exiting from LS@...");
}
*/
