.global isr_0
.global isr_1
.global isr_2
.global isr_3
.global isr_4
.global isr_5
.global isr_6
.global isr_7
.global isr_8
.global isr_9
.global isr_10
.global isr_11
.global isr_12
.global isr_13
.global isr_14
.global isr_15
.global isr_16
.global isr_17
.global isr_18
.global isr_19
.global isr_20
.global isr_21
.global isr_22
.global isr_23
.global isr_24
.global isr_25
.global isr_26
.global isr_27
.global isr_28
.global isr_29
.global isr_30
.global isr_31

isr_0:
	cli
	push $0
	push $0
	jmp common_isr_stub_handler

isr_1:
	cli
	push $1
	push $1
	jmp common_isr_stub_handler

isr_2:
	cli
	push $2
	push $2
	jmp common_isr_stub_handler

isr_3:
	cli
	push $3
	push $3
	jmp common_isr_stub_handler

isr_4:
	cli
	push $4
	push $4
	jmp common_isr_stub_handler

isr_5:
	cli
	push $5
	push $5
	jmp common_isr_stub_handler

isr_6:
	cli
	push $6
	push $6
	jmp common_isr_stub_handler

isr_7:
	cli
	push $7
	push $7
	jmp common_isr_stub_handler

isr_8:
	cli
	push $8
	push $8
	jmp common_isr_stub_handler

isr_9:
	cli
	push $9
	push $9
	jmp common_isr_stub_handler

isr_10:
	cli
	push $10
	push $10
	jmp common_isr_stub_handler

isr_11:
	cli
	push $11
	push $11
	jmp common_isr_stub_handler

isr_12:
	cli
	push $12
	push $12
	jmp common_isr_stub_handler

isr_13:
	cli
	push $13
	push $13
	jmp common_isr_stub_handler

isr_14:
	cli
	push $14
	push $14
	jmp common_isr_stub_handler

isr_15:
	cli
	push $15
	push $15
	jmp common_isr_stub_handler

isr_16:
	cli
	push $16
	push $16
	jmp common_isr_stub_handler

isr_17:
	cli
	push $17
	push $17
	jmp common_isr_stub_handler

isr_18:
	cli
	push $18
	push $18
	jmp common_isr_stub_handler

isr_19:
	cli
	push $19
	push $19
	jmp common_isr_stub_handler

isr_20:
	cli
	push $20
	push $20
	jmp common_isr_stub_handler

isr_21:
	cli
	push $21
	push $21
	jmp common_isr_stub_handler

isr_22:
	cli
	push $22
	push $22
	jmp common_isr_stub_handler

isr_23:
	cli
	push $23
	push $23
	jmp common_isr_stub_handler

isr_24:
	cli
	push $24
	push $24
	jmp common_isr_stub_handler

isr_25:
	cli
	push $25
	push $25
	jmp common_isr_stub_handler

isr_26:
	cli
	push $26
	push $26
	jmp common_isr_stub_handler

isr_27:
	cli
	push $27
	push $27
	jmp common_isr_stub_handler

isr_28:
	cli
	push $28
	push $28
	jmp common_isr_stub_handler

isr_29:
	cli
	push $29
	push $29
	jmp common_isr_stub_handler

isr_30:
	cli
	push $30
	push $30
	jmp common_isr_stub_handler

isr_31:
	cli
	push $31
	push $31
	jmp common_isr_stub_handler

common_isr_stub_handler:
	pusha
	mov %ds, %eax
	push %eax
	mov $0x10, %eax
	mov %eax, %ds
	mov %eax, %es
	mov %eax, %fs
	mov %eax, %gs
	call isr_handler
	pop %eax
	mov %eax, %ds
	mov %eax, %es
	mov %eax, %fs
	mov %eax, %gs
	popa
	add $8, %esp
	sti
	iret

