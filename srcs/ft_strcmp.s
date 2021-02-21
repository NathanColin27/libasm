global ft_strcmp

; int strcmp(const char *s1, const char *s2);
;
; Inputs: RDI = char *s1, RSI = char *s2
; Return: RAX = int

ft_strcmp:
	push	rbx						; saving rbx
	push	rcx						; same
	mov		rax, 0					; initializing at 0
	mov		rbx, 0					; same
	mov		rcx, -1					; counter

_ft_strcmp_loop:
	inc		rcx						; incrementing counter
	mov		al, byte [rdi + rcx]	; moving next char of *s1 into al 
	mov		bl, byte [rsi + rcx]	; moving next char of *s2 into bl 
	cmp		al, 0					; is it the end of *s1?
	jz		_ft_strcmp_end			; if so jump to end
	cmp		bl, 0					; is it the end of *s2?
	jz		_ft_strcmp_end			; if so jump to end
	cmp		al, bl					; comparing char of *s1 to char of *s2
	jz		_ft_strcmp_loop			; if same, goes to next iteration. Otherwise, continue to end 

_ft_strcmp_end:
	sub		rax, rbx				; difference between the two chars
	pop		rcx						; putting rcx back to its previous state
	pop		rbx						; putting rbx back to its previous state
	ret								; rax is sent back
