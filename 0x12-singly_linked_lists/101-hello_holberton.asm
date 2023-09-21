section .data
	hello db "Hello, Holberton,", 0  ; Null-terminated string

section .text
	global main

extern printf

main:
	push rbp
	mov edi, hello
	call printf

	mov rax, 60
	xor rdi, rdi
	syscall
