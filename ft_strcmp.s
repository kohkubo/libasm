section .text
	global _ft_strcmp

_ft_strcmp:
.loop:
	movsx	eax, BYTE[rdi]
	cmpsb
	jne		.end
	test	al, al
	jne		.loop
.end:
	movsx	ecx, BYTE [rsi - 1]
	sub		eax, ecx
	ret
