section .data
	hello db "Hello, Holberton,", 0  ; Null-terminated string

section .text
	global main

extern printf

main:
	mov edi, hello  ; Load the address of the string into edi
	xor eax, eax    ; Clear the eax register
	call printf     ; Call the printf function

	; Exit the program
	mov eax, 60     ; Syscall number for exit (60 on x86-64)
	xor edi, edi    ; Status code 0
	syscall         ; Invoke syscall to exit
