section .text
	global _ft_strcmp

_ft_strcmp:
	xor		eax, eax
	xor		ebx, ebx
	xor		ecx, ecx
.loop:
	mov		al, BYTE[rdi + rcx]
	mov		bl, BYTE[rsi + rcx]
	cmp		al, 0
	je		.end
	cmp		al, bl
	jne		.end
	inc		rcx
	jmp		.loop
.end:
	sub		eax, ebx
	ret
