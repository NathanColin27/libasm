extern ___error

global _ft_read

%define SYS_read 0x2000003

; ssize_t read(int fildes, void *buf, size_t nbyte);
;
; Inputs: RDI = int fildes, RSI = void *buf, RDX = size_t nbytes
; Return: RAX = ssize_t
_ft_read:
	mov		rax, SYS_read
	syscall
	jc		_ft_read_error
	ret

_ft_read_error:
	push	rbx
	mov		rbx, rax
	call	___error
	mov		[rax], rbx
	pop		rbx
	mov		rax, -1
	ret