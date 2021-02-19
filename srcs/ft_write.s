extern __errno_location

global ft_write

%define SYS_write 1

; ssize_t write(int fildes, const void *buf, size_t nbyte)
;
; Inputs: RDI = int fildes, RSI = void *buf, RDX = size_t nbytes
; Return: RAX = ssize_t
ft_write:
	mov		rax, SYS_write
	syscall
	cmp		rax, 0
	jl		_ft_write_error
	ret

_ft_write_error:
	push	rbx
	neg  	rax
	mov		rbx, rax
	call	__errno_location wrt ..plt
	mov		[rax], rbx
	pop		rbx
	mov		rax, -1
	ret