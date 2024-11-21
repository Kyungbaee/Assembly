%include "io64.inc"

section .text
global main
main:    
    mov rbp, rsp; for correct debugging
    
    ; 반복문 (while for)
    ; 특정 조건을 만족할때까지 반복해서 실행
    
    ; 연습문제) 1에서 100까지의 합을 구하는 프로그램
    
    mov ecx, 100
    mov edx, 0
    
    LABEL_LOOP:
        add edx, ecx
        dec ecx ; sub ecx,1 과 동일 (1을 빼주는 기능)
        cmp ecx, 0
        jne LABEL_LOOP
    
    PRINT_DEC 1, edx
    NEWLINE
    
    xor rax, rax
    ret
    
section .data
    msg db 'Hello World', 0x00
section .bss
    num resb 1