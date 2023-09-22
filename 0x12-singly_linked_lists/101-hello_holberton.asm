	global main
	extern printf

main:
	mov edi, greeting_Hoberton
	xor eax, eax
	call printf
	mov eax, 0
	ret

greeting_Hoberton: db `Hello, Holberton\n`,0
