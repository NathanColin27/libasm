global ft_strcpy

; char *strcpy(char *dst, const char *src)
;
; Inputs: RDI = string dst, RSI = string src
; Return: RAX = string
ft_strcpy:
	push	rbx						; saving rbx
	mov		rax, -1					; using rax as counter

_ft_strcpy_loop:
	inc		rax 					; rax ++
	mov 	bl, byte [rsi + rax]	; getting char from string src
	mov		byte [rdi + rax], bl	; setting that char into string dst
	cmp		byte [rsi + rax], 0		; is it the end of the string ('\0') ?
	jne		_ft_strcpy_loop			; if not, next iteration
	mov		rax, rdi 				; moving string dst into rax 
	pop		rbx 					; putting rbx back to its previous state
	ret 							; returning string dst (rax)