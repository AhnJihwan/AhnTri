void outw_old(uint16 port, uint16 data) 
{
    asm("out %%ax, %%dx" : : "a" (data), "d" (port));
}

void shutdown() 
{
        printf("Shutting down\n");
        printf(".");
	suspend(2);
        printf(".");
	suspend(2);
        printf(".");
	suspend(2);
        printf(".");
	suspend(2);
        printf(".");
	suspend(2);
        printf(".");
	suspend(2);
        outw_old(0xB004, 0x2000);
        outw_old(0x0604, 0x2000);
        outw_old(0x4004, 0x3400);

}
