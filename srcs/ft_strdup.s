extern ft_strlen
extern ft_strcpy
extern malloc
extern ___error

global ft_strdup

%define ENOMEM 12

; char *strdup(const char *s1)
;
; Inputs: RDI = char *s1
; Return: RAX = char *
ft_strdup:
	call	ft_strlen
	inc		rax
	push	rdi
	mov		rdi, rax
	call	malloc wrt ..plt
	pop		rdi
	cmp		rax, 0
	je		ft_strdup_error
	mov		rsi, rdi
	mov		rdi, rax
	call	ft_strcpy
	ret

ft_strdup_error:
	ret