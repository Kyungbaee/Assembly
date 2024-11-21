%include "io64.inc"

section .text
global main
main:    
    mov rbp, rsp; for correct debugging
    
    ; 함수 (프로시저 procedure 서브루틴 subroutine)
    
    call PRINT_MSG  ; 함수 호출
    
    mov eax, 10
    mov ebx, 5
    call MAX
    PRINT_DEC 4, ecx
    NEWLINE
    
    xor rax, rax
    ret
    
    PRINT_MSG:
        PRINT_STRING msg
        NEWLINE
        ret
    
    ; ex) 두 값중 더 큰 값을 반환하는 max 함수
    ; 근데 두 개의 값을 어떻게 넘겨 받지? 반환은 어떻게 할까?
    ; eax와 ebx 입력값을 ecx에 반환
    MAX:
        cmp eax, ebx
        jg L1
        mov ecx, ebx
        jmp L2
    L1:
        mov ecx, eax
    L2:
        ret
        
    ; 인자가 많은 경우는?
    ; eax, ebx에 이미 중요한 값이 있는 경우는?
    ; [!] .data .bss 사용하면?
    
    ; 다른 메모리 구조가 필요하다
    ; - 함수가 유효한 동안에는 변수 값을 유지 시켜야함 (유효 범위의 개념)
    ; - 함수가 끝나면 그 함수를 정리해도 됨
    ; - 함수 안에서도 함수 호출이 가능한 것을 고려해야 함 (유동적 유효범위 확장 가능)
    
    
    ; [!] 스택(stack)이라는 메모리 영역을 사용
    ; 함수가 사용하는 일종의 메모장
    ; - 매개 변수 전달
    ; - 돌아갈 주소 관리

section .data
    msg db 'Hello World', 0x00
    dd a 0
    dd b 0
    dd c 0
    
section .bss
    num resb 1