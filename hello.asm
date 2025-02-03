section .data
    hello db 'Hello, World!', 0

section .text
    global main

main:
    ; Write "Hello, World!" to stdout
    mov rax, 1          ; syscall: write
    mov rdi, 1          ; file descriptor: stdout
    mov rsi, hello      ; message to write
    mov rdx, 13         ; message length
    syscall             ; invoke syscall

    ; Exit program
    mov rax, 60         ; syscall: exit
    xor rdi, rdi        ; exit code 0
    syscall             ; invoke syscall