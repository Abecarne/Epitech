BITS 64

section .text

global strcmp:function

strcmp:
    XOR     RCX, RCX

_while:
    MOV     R8B, [RDI + RCX]
    MOV     R9B, [RSI + RCX]
    CMP     R8B, R9B
    JNE     _end_while
    CMP     [RDI + RCX], BYTE 0
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
