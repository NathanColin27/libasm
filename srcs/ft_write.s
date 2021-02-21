extern __errno_location

global ft_write

%define SYS_write 1

; ssize_t write(int fildes, const void *buf, size_t nbyte)
;
; Inputs: RDI = int fildes, RSI = void *buf, RDX = size_t nbytes
; Return: RAX = ssize_t
ft_write:
	mov		rax, SYS_write					; moving 1 (system write instruction) into rax
	syscall									; calling system
	cmp		rax, 0 							; what is the return value ?
	jl		_ft_write_error					; if negative -> error
	ret 									; else end

_ft_write_error:
	push	rbx								; saving rbx
	neg  	rax 							; because error code is negative
	mov		rbx, rax 						; saving error code into rbx
	call	__errno_location wrt ..plt		; setting errno
	mov		[rax], rbx 						; ⚠️⚠️⚠️ REMOVE BEFORE PUSHING ⚠️⚠️⚠️ ask ce cher ancoulon because là I am un brin lost
	pop		rbx								; getting back rbx original value
	mov		rax, -1							; setting -1 as return value
	ret 									; end