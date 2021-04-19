section .text
global _ft_read
extern ___error

_ft_read:
			mov rax, 0x2000003 ;move read to rax
			syscall ;call 
			jc .error ;if overbuffing CF == 1 => err
			ret

.error:
			mov rax, -1
			ret	