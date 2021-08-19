ENTRY(_start)

SECTIONS
{
	. = 1M;
	_kernel_start = .;		/* Start of the Kernel! */
	
	_kernel_start_of_text = .;	/* Start of the Kernel Text! */
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	}
	_kernel_end_of_text = .;	/* End of the Kernel Text! */
	
	_kernel_start_of_rodata = .;
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}
	_kernel_end_of_rodata = .;

	_kernel_start_of_data = .;
	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}
	_kernel_end_of_data = .;

	_kernel_start_of_bss = .;
	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
	}
	_kernel_end_of_bss = .;

	_kernel_end = .;
}
