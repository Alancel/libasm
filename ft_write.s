section .text
global _ft_write
extern ___error

_ft_write:
			mov rax, 0x2000004 ;move write to rax
			syscall ;call write
			jc .error ;if overbuffing CF == 1 => err
			ret

.error:
			mov rax, -1
			ret