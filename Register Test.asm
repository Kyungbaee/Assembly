%include "io64.inc"

section .text
global main
main:
    mov rbp, rsp; for correct debugging
    ; 8 bit = 1 byte
    ; 16 bit = 2 byte = 1 word
    ; 32 bit = 4 byte = 2 word = 1 dword (double-word)
    ; 64 bit = 8 byte = 4 word = 1 qword (quad-word)
    
    ; mov는 move. 값을 넣어준다(오른쪽에서 왼쪽으로)
    ; rbx = 64bit, eax = 32bit, cl = 8bit
    mov eax, 0x1234
    mov rbx, 0x12345678
    mov cl, 0xff
    
    mov al, 0x00
    mov rax, rdx
    
    xor rax, rax
    ret