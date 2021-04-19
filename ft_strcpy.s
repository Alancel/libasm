section .text
global _ft_strcpy

_ft_strcpy:
			xor rcx, rcx
			xor rdx, rdx
			cmp rsi, 0
			jz .return

.loop:		
			mov dl, byte [rsi + rcx]
			mov byte [rdi + rcx], dl
			cmp dl, 0
			jz .return
			inc rcx
			jmp .loop

.return:
			mov rax, rdi
			ret