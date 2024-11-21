%include "io64.inc"

section .text
global main
main:    
    mov rbp, rsp; for correct debugging
    
    ; 쉬프트(shitf) 연산, 논리(logical) 연산
    
    mov eax, 0x12345678
    PRINT_HEX 4, eax
    NEWLINE
    
    ; 왼쪽 쉬프트 연산
    shl eax, 8
    PRINT_HEX 4, eax
    NEWLINE
    
    ; 오른쪽 쉬프트 연산    
    shr eax, 8
    PRINT_HEX 4, eax
    NEWLINE    
                    
    ; not and or xor
    ; 조건 A : 잘생겼다
    ; 조건 B : 키가 크다
    
    ; not A : 잘생겼다의 반대 -> (0 이면 1, 1이면 0)
    ; A and B : 잘생겼다 and 키가 크다 -> 모두 1이면 1, 아니면 0
    ; A or B : 잘생겼거나 or 키가 크거나 -> 둘중 하나라도 1이면 1, 아니면 0
    ; A xor B : 서로 다르면 1, 둘다 1이거나 0이면 0
        
    mov al, 0b10010101
    mov bl, 0b01111100
    
    ; 0b0001 0100 = 0x14
    and al, bl  ; al = al and bl
    PRINT_HEX 1, al
    NEWLINE

    ; 0b1110 1011 = 0xeb
    NOT al
    PRINT_HEX 1, al
    NEWLINE

    ; 응용 사례 : bitflag
    
    ; 동일한 값으로 xor 두번하면 자기 자신으로 되돌아오는 특성이 있음
    ; 암호학에서 유용하다! (value xor key)
    mov al, 0b10010101
    mov bl, 0b01111100
    
    NEWLINE
    PRINT_HEX 1, al
    NEWLINE
    xor al, bl
    PRINT_HEX 1, al
    NEWLINE
    xor al, bl    
    PRINT_HEX 1, al
    NEWLINE            
    
    ; mov al, 0과 같은 기능
    xor al, al
    PRINT_HEX 1, al
    
    xor rax, rax    ; rax에 0을 넣겠다는 의미..
    ret
    
section .bss
    num resb 1