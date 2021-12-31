#include "multiboot.h"

.extern mkern_main

.section .multiboot                 # set multiboot enabled

multiboot_header_start:
.long    0xe85250d6           # Magic number
.long	0
.long	multiboot_header_end - multiboot_header_start
.long	-(0xe85250d6 + (multiboot_header_end - multiboot_header_start))     # set the checksum
multiboot_header_end:

stackBottom:

.skip 4096                          #512 B

stackTop:

.section .text
.global _start
.type _start, @function


_start:
    mov $stackTop, %esp
    pushl %ebx
    call mkern_main
    cli

hltLoop:

    hlt
    jmp hltLoop                     # System Loop: infinity

.size _start, . - _start
