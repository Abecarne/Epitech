BITS 64

section .text

global strncmp:function

strncmp:
    XOR     RCX, RCX
    CMP     RDX, 0
    JE      _is_null

_while:
    CMP     RCX, RDX
    JGE     _end_while
    MOV     R8B, [RDI + RCX]
    MOV     R9B, [RSI + RCX]
    CMP     R8B, R9B
    JNE     _end_while
    CMP     [RDI + RCX], BYTE 0
    JE      _end_while
    CMP     [RSI + RCX], BYTE 0
    JE      _end_while
    INC     RCX
    JMP     _while

_is_null:
	XOR	    RAX, RAX	        ; On mets RAX à zéro si on a un NULL en chaine RDI ou alors si on n'a pas trouvé de resultat
	RET

_end_while:
    MOVSX   RAX, R8B
    MOVSX   RBX, R9B
    SUB     RAX, RBX
    RET
