BITS 64

section .text

global strlen:function

strlen:
    xor     RCX, RCX

_while:
    cmp     [RDI], byte 0
    je      _end_while
    inc     RCX
    inc     RDI
    jmp     _while

_end_while:
    mov     RAX, RCX
    ret