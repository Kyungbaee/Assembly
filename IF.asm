%include "io64.inc"

section .text
global main
main:    
    mov rbp, rsp; for correct debugging
    
    ; 분기문 (if)
    ; 특정 조건에 따라서 코드 흐름을 제어하는 것
    ; ex) 스킬 버튼 눌렀는가? YES -> 스킬 사용
    
    ; CMP dst, src (dst가 기준)
    ; 비교를 한 결과물은 Flag Register에 저장
    
    ; JMP [label] 시리즈
    ; JMP : 무조건 Jump
    ; JE : JumpEquals 같으면 jump
    ; JNE : JumpNotEquals 다르면 jump
    ; JG : JumpGreater 크면 jump
    ; JGE : JumpGreaterEqauls 크거나 같은면 jump
    ; JL, JLE ... etc
    
    ; 두 숫자가 같으면 1, 아니면 0을 출력하는 프로그램
    
    mov rax, 10
    mov rbx, 10
    
    cmp rax, rbx
    
    je LABEL_EQUAL
    ; je에 의해 점프를 안했다면, 같지 않다는 의미
    mov rcx, 0
    jmp LABEL_EQUAL_END
    
    LABEL_EQUAL:
        mov rcx, 1
    LABEL_EQUAL_END:
        PRINT_HEX 1, rcx
        NEWLINE
            
               
    xor rax, rax
    ret
    
section .bss
    num resb 1