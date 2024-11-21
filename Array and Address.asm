%include "io64.inc"

section .text
global main
main:    
    mov rbp, rsp; for correct debugging
    
    ; 배열과 주소
    
    ; 배열 : 동일한 타입의 데이터 묶음
    ; - 배열을 구성하는 각 값을 배열 요소(element)라고 함
    ; - 배열의 위치를 가리키는 숫자를 인덱스(index)라고 함

    ; 주소
    ; [시작 주소 + 인덱스 * 크기]
            
    ; 연습문제 : a배열의 모든 데이터 출력해보기
    mov rcx, 5
    xor rdx, rdx
    
    LABEL_LOOP:
        PRINT_HEX 1, [a+rdx]
        NEWLINE
        inc rdx
        cmp rdx, rcx
        jne LABEL_LOOP 
    
    xor rax, rax
    ret
    
section .data
    msg db 'Hello World', 0x00
    a db 0x01,0x02,0x03,0x04,0x05   ; 5 * 1 = 5 byte
    b times 5 dw 1  ; 5 * 2(word) = 10 byte
    
section .bss
    num resb 10