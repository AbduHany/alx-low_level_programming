section .text
	default rel
	extern printf
	global main
main:
	push rbp

	mov rdi, fmt
	mov rsi, text
	mov rax, 0

	call printf wrt ..plt

	pop rbp

	mov rax, 0
	ret
	

section .data
	text : db "Hello, Holberton", 10, 0
	fmt: db "%s"
