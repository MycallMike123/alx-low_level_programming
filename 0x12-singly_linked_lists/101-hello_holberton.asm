section .data
	hello db "Hello, Holberton,", 0  ; Null-terminated string

section .text
	global main

extern printf

main:
	mov edi, hello
	xor eax, eax
	call printf

	mov eax, 0
	xor edi, edi
	syscall
