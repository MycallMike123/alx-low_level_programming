section .data
	hello db "Hello, Holberton,", 0  ; Null-terminated string

section .text
	global main

extern printf

main:
	push rbp        ; Save the base pointer
	mov rdi, hello  ; Load the address of the string into rdi
	call printf     ; Call the printf function
	add rsp, 8      ; Clean up the stack

	mov rax, 60     ; Syscall number for exit (60 on x86-64)
	xor rdi, rdi    ; Status code 0
	syscall         ; Invoke syscall to exit
