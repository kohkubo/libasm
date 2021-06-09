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


; extern  ___error
; section .text
; global  _ft_write

; _ft_write:
; 	mov  rax, 0x2000004
; 	syscall
; 	jc   .error
; 	jmp  .return

; .error:
; 	mov r8, rax
; 	sub  rsp, 8
; 	call ___error
; 	add  rsp, 8
; 	mov [rax], r8
; 	mov rax, -1

; .return:
; 	ret
