section .text
global _ft_strdup
extern _malloc
extern _ft_strlen

_ft_strdup:
			cmp rdi, 0
			jz .err
			xor rdx, rdx
			xor rcx, rcx
			call _ft_strlen
			add rax, 1
			push rdi
			mov rdi, rax
			call _malloc
			cmp rax, 0
			jz .err
			pop rdi

.loop:		
			mov dl, byte [rdi + rcx]
			mov byte [rax + rcx], dl
			cmp dl, 0
			jz .ret
			inc rcx
			jmp .loop

.err:
			xor rax, rax

.ret:
			ret