%include "io64.inc"

section .text
global main
main:    
    mov rbp, rsp; for correct debugging
    
    ; [!] 스택(stack)이라는 메모리 영역을 사용
    ; 함수가 사용하는 일종의 메모장
    ; - 매개 변수 전달
    ; - 돌아갈 주소 관리
    
    ; 스택 메모리, 스택 프레임
    
    ; 레지스터는 다양한 용도로 사용
    ; - a b c d 범용 레지스터
    ; - 포인터 레지스터 (포인터 = 위치를 가리키는)
    ; -- ip (Instruction Pointer) : 다음 수행 명령어의 위치
    ; -- sp (Stack Pointer) : 현재 스택 top 위치 (일종의 cursor)
    ; -- bp (Base Pointer) : 스택 상대주소 계산용
    
    push 1
    push 2
    call MAX
    PRINT_DEC 8, rax
    NEWLINE
    ; 스택을 썼으면 종료할 때 정리도 해줘야 함
    ; 2개 사용했으니 8*2 = 16만큼 sp 올려줘야 함
    ADD rsp, 16
   
    xor rax, rax
    ret
    
    MAX:
        push rbp
        mov rbp, rsp
        
        mov rax, [rbp+16]
        mov rbx, [rbp+24]
        cmp rax, rbx
        jg L1
        MOV rax, rbx
    L1:
        pop rbp
        ret
    
section .data
    msg db 'Hello World', 0x00

section .bss
    num resb 1