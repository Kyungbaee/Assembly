%include "io64.inc"

section .text
global main
main:    
    mov rbp, rsp; for correct debugging
    
    ; 반복문 (while for)
    ; 특정 조건을 만족할때까지 반복해서 실행
    
    ; ex) Hello World를 10번 출력해야 한다면?
    
    mov ecx, 10
    
    LABEL_LOOP:
        PRINT_STRING msg
        NEWLINE
        dec ecx ; sub ecx,1 과 동일 (1을 빼주는 기능)
        cmp ecx, 0
        jne LABEL_LOOP
     
     
    ; loop [라벨]
    ; - ecx에 반복 횟수
    ; - loop 할때마다 ecx 1 감소. 0이면 탈출, 아니면 라벨로 이동
    
    mov ecx, 100
    xor ebx, ebx
    LABEL_LOOP_SUM:
        add ebx, ecx
        loop LABEL_LOOP_SUM
    
    PRINT_DEC 4, ebx
    NEWLINE
    
    xor rax, rax
    ret
    
section .data
    msg db 'Hello World', 0x00
section .bss
    num resb 1