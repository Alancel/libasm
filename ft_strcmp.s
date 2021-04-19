section .text
global _ft_strcmp

_ft_strcmp:
			xor rax, rax
			xor rdx, rdx
			xor rcx, rcx
			cmp rsi, 0
			jz  .null
			cmp rdi, 0
			jz  .null

.null:
			cmp rdi, rsi
			jz  .equal
			jg  .above
			jmp .below 

.loop:
			mov al, byte[rsi + rcx]
			mov dl, byte[rdi + rcx]
			cmp al, dl
			jg .below
			jb .above
			cmp al, 0
			jz .equal
			inc rcx
			jmp .loop

.below:
			mov rax, -1
			ret

.above:
			mov rax, 1
			ret

.equal:
			mov rax, 0
			ret