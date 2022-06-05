BITS 64

extern strlen

section .text

global strrchr:function

strrchr:
    CALL    strlen wrt ..plt
    MOV     RCX, RAX

_while:
    CMP     RCX, 0
    JLE     _no_solution
    CMP     [RDI + RCX], BYTE 0
    JE      _end_while
    CMP     [RDI + RCX], SIL
    JE      _end_while
    DEC     RCX
    JMP     _while

_end_while:
    ADD     RDI, RCX
    MOV     RAX, RDI
    RET

_no_solution:
    XOR     RAX, RAX
    RET
