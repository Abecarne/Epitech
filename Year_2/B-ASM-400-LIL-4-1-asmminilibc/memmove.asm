BITS 64

section .text

global my_memmove:function

my_memmove:
    XOR     RCX, RCX
    CMP     RDX, BYTE 0
    JE      _end

_while_push:
    CMP     RCX, RDX
    JGE      _while_pop
    MOV     R8, [RSI + RCX]
    PUSH    R8
    INC     RCX
    JMP     _while_push

_while_pop:
    DEC     RCX
    POP     R8
    MOV     [RDI + RCX], R8B
    CMP     RCX, 0
    JE      _end
    JMP     _while_pop

_end:
    MOV     RAX, RDI
    RET
