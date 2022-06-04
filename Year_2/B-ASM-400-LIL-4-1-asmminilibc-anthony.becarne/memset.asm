BITS 64

section .text

global memset:function

memset:
    XOR     RCX, RCX

_while:
    CMP     RCX, RDX
    JGE      _end_while
    MOV     [RDI + RCX], RSI
    inc     RCX
    jmp     _while

_end_while:
    MOV     RAX, RDI
    RET
