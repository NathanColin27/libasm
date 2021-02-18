extern _ft_strlen
extern _ft_strcpy
extern _malloc
extern ___error

global ft_strdup

%define ENOMEM 12

; char *strdup(const char *s1)
;
; Inputs: RDI = char *s1
; Return: RAX = char *
ft_strdup:
	call	_ft_strlen
	inc		rax
	push	rdi
	mov		rdi, rax
	call	_malloc
	pop		rdi
	cmp		rax, 0
	je		_ft_strdup_error
	mov		rsi, rdi
	mov		rdi, rax
	call	_ft_strcpy
	ret

_ft_strdup_error:
	ret