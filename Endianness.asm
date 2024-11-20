%include "io64.inc"

section .text
global main
main:    mov rbp, rsp; for correct debugging
       
       
    PRINT_STRING msg
    
    xor rax, rax
    ret

;   Big-Endian 메모리주소 증가에 따라 정방향으로 데이터 저장
;   Little-Endian 메모리주소 증가에 따라 역방향으로 데이터 저장 (Intel은 리틀 엔디안)
;   장단점
;   - Little Endian : 캐스팅에 유리함
;   - Big Endian : 숫자 비교에 유리함

section .data
    msg db 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x0
    
    a db 17, 17, 17, 17 ; 0x11
    
    b dd 0x12345678 ; Little Endian
    
section .bss
    e resb 10