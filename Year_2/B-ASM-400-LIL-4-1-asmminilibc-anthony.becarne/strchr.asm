BITS 64

section .text

global strchr:function

strchr:
	MOV		RAX, RDI

_while:
	CMP		[RAX], SIL			; SIL prend le dernier registre de RSI (on veut un char --> donc 8bits)
	JE		_end_while
	CMP		[RAX], BYTE 0
	JE		_is_null
	INC		RAX
	JMP		_while

_is_null:
	XOR	    RAX, RAX	        ; On mets RAX à zéro si on a un NULL en chaine RDI ou alors si on n'a pas trouvé de resultat
	RET

_end_while:
	RET
