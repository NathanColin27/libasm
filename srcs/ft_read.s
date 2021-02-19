extern __errno_location

global ft_read

%define SYS_read 0

; ssize_t read(int fildes, void *buf, size_t nbyte);
;
; Inputs: RDI = int fildes, RSI = void *buf, RDX = size_t nbytes
; Return: RAX = ssize_t
ft_read:
	mov		rax, SYS_read
	syscall
	cmp		rax, 0
	jl		_ft_read_error
	ret

_ft_read_error:
	push	rbx
	neg		rax
	mov		rbx, rax
	call	__errno_location wrt ..plt
	mov		[rax], rbx
	pop		rbx
	mov		rax, -1
	ret