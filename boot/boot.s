#Assembly TriOS bootloader
// Made in Android
#include "multiboot.h"
.set FLAGS,    MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO | MULTIBOOT_VIDEO_MODE | AOUT_KLUDGE

.set MAGIC,    0x1BADB002           #Magic number

.set CHECKSUM, -(MAGIC + FLAGS)     # set the checksum

.section .multiboot                 # set multiboot enabled

.long MAGIC
.long FLAGS
.long CHECKSUM

 
stackBottom:

.skip 4096                          #512 B

stackTop:

.section .text
.global _start
.type _start, @function


_start:
	mov $stackTop, %esp

	call mkern_main

	cli

hltLoop:

	hlt
	jmp hltLoop                     # System Loop: infinity

.size _start, . - _start
