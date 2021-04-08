extern	_malloc
extern	_ft_strlen
extern	_ft_strcpy
extern	___error

section	.text
	global	_ft_strdup

_ft_strdup:
	push	rbp
	mov		rbp, rsp

	sub		rsp, 0x8
	push	rdi

	call	_ft_strlen
	mov		rdi, rax
	inc		rdi

	call	_malloc
	jc		.err
	mov		rdi, rax

	pop		rsi
	call	_ft_strcpy

	jmp		.end

.err:
	push	rax
	call	___error
	pop		rbx
	mov		[rax], rbx
	mov		rax, -1

.end:
	leave
	ret
