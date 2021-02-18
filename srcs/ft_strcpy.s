global ft_strcpy

; char *strcpy(char *dst, const char *src)
;
; Inputs: RDI = string dst, RSI = string src
; Return: RAX = string
ft_strcpy:
	push	rbx
	mov		rax, -1

_ft_strcpy_loop:
	inc		rax
	mov 	bl, byte [rsi + rax]
	mov		byte [rdi + rax], bl
	cmp		byte [rsi + rax], 0
	jne		_ft_strcpy_loop
	mov		rax, rdi
	pop		rbx
	ret