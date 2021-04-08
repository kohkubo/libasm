extern ___error
section .text
	global _ft_write

_ft_write:
	push	rbp
	mov		rbp, rsp
	push	rbx
	mov	rax, 0x2000004
	syscall
	jc		.err
	jmp		.end

.err:
	push	rax
	call	___error
	pop		rbx
	mov		[rax], rbx
	mov		rax, -1

.end:
	pop		rbx
	leave
	ret
