#Assembly TriOS bootloader
// Made in Android

.set FLAGS,    0                    #Flags to 12 bit for frambuffer preparation

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
