global main
extern printf

section .data
	greeting_Hoberton db "Hello, Holberton", 10, 0

section .text
main:
	mov edi, greeting_Hoberton
	xor eax, eax
	call printf
	mov eax, 0
	ret
