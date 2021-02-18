global ft_strlen

; size_t ft_strlen(const char *s)
;
; Inputs: RDI = string s
; Return: RAX = length of the string
ft_strlen:
	mov		rax, 0				; setting return value to 0

_ft_strlen_loop:
	cmp		byte [rdi + rax], 0	; comparing byte at string[rax] with 0
	je		_ft_strlen_ret		; if string[rax] == 0, returning rax
	inc		rax					; rax++
	jmp		_ft_strlen_loop		; go to the start of the loop

_ft_strlen_ret:
	ret							; return