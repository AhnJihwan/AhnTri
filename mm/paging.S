.text
.global paging_enablement
paging_enablement:
	mov %cr0, %ebx
	or $0x80000000, %ebx
	mov %ebx, %cr0
	ret
  
.text
.globl loadPageDirectory
loadPageDirectory:
	mov 4(%esp), %eax
	mov %eax, %cr3
	ret
