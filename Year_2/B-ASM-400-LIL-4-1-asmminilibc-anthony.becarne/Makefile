##
## EPITECH PROJECT, 2022
## delivery [WSL: Ubuntu-20.04]
## File description:
## Makefile
##

SRC	=	memcpy.asm		\
		memset.asm		\
		strchr.asm		\
		strcmp.asm		\
		strlen.asm		\
		memcpy.asm		\
		strstr.asm		\
		memmove.asm		\
		strrchr.asm		\
		strncmp.asm		\
		strpbrk.asm		\
		strcspn.asm		\
		strcasecmp.asm	\

OBJ		= 	$(SRC:.asm=.o)

NAME	=	libasm.so

%.o:		%.asm
	nasm -o $@ $< -f elf64

all:	$(OBJ)
		gcc -fpic -o $(NAME) *.o -nostdlib -shared

clean:
		rm -f $(OBJ)
		rm -f $(OBJC)

fclean:	clean
		rm -f $(NAME)

re: fclean all
