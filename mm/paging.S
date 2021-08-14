.global paging_enablement

paging_enablement:
  add $0x04, %esp
  mov %esp, %eax
  mov %cr3, %eax
  or $0x80000001, %eax
  mov %eax, %cr0
  mov %cr4, %eax
  or $0x00000010, %eax
  mov %eax, %cr4
  ret
