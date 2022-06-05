BITS 64

section .text

global memcpy:function

memcpy:
    XOR     RCX, RCX

_while:
    CMP     RCX, RDX
    JGE      _end_while
    MOV     R9B, [RSI + RCX]
    MOV     [RDI + RCX], R9B
    inc     RCX
    jmp     _while

_end_while:
    MOV     RAX, RDI
    RET
