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
	call	ft_strlen				; calling ft_strlen -> *s1's length in rax
	inc		rax 					; len ++
	push	rdi 					; saving rdi value
	mov		rdi, rax 				; saving len into rdi (arg for malloc)
	call	malloc wrt ..plt 		; calling malloc (pointer in rax)
	pop		rdi 					; restoring rdi to original value
	cmp		rax, 0 					; did mallox return NULL?
	je		ft_strdup_error 		; if so, straight to jail
	mov		rsi, rdi 				; if not, moving rdi (ft_strdup's argument) into rsi (ft_strcpy's src field)
	mov		rdi, rax 				; moving rax (malloced adress) into rdi (ft_strcpy's dest field)
	call	ft_strcpy 				; calling ft_strcpy
	ret 							; end

ft_strdup_error:
	ret 							; end (returning 0)