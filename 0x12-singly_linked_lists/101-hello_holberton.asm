.data
msg: db "Hello, Holberton!", 10 ; Message to print

.text
global _start ; Declare entry point

section .text
_start:
    ; Move the address of the message to rax
    mov rax, msg

    ; Move the format string to rdi
    mov rdi, fmt

    ; Print the message
    call printf

    ; Exit the program with status code 0
    mov rax, 60
    mov rdi, 0
    syscall

fmt: db "%s\n", 0 ; Format string for printf
