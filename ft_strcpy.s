section .text
	global _ft_strcpy

_ft_strcpy:
	push	rbp
	mov		rbp, rsp
	push	rdi
	cld
.copy:
	cmp		BYTE [rsi], 0
	je		.end
	movsb
	jmp		.copy
.end:
	mov		BYTE [rdi], 0
	pop		rax
	leave
	ret
