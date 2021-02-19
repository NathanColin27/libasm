global ft_strcmp

; int strcmp(const char *s1, const char *s2);
;
; Inputs: RDI = char *s1, RSI = char *s2
; Return: RAX = int

ft_strcmp:
	push	rbx
	push	rcx
	mov		rax, 0
	mov		rbx, 0
	mov		rcx, -1

_ft_strcmp_loop:
	inc		rcx
	mov		al, byte [rdi + rcx]
	mov		bl, byte [rsi + rcx]
	cmp		al, 0
	jz		_ft_strcmp_end
	cmp		bl, 0
	jz		_ft_strcmp_end
	cmp		al, bl
	jz		_ft_strcmp_loop

_ft_strcmp_end:
	sub		rax, rbx
	pop		rcx
	pop		rbx
	ret
