extern ___error

global _ft_write

%define SYS_write 0x2000004

; ssize_t write(int fildes, const void *buf, size_t nbyte)
;
; Inputs: RDI = int fildes, RSI = void *buf, RDX = size_t nbytes
; Return: RAX = ssize_t
ft_write:
	mov		rax, SYS_write
	syscall
	jc		_ft_write_error
	ret

_ft_write_error:
	push	rbx
	mov		rbx, rax
	call	___error
	mov		[rax], rbx
	pop		rbx
	mov		rax, -1
	ret