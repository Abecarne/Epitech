##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile lib
##

SRC 	=	string.c		\
			assign.c		\
			append.c		\
			at.c			\
			clear_list.c	\
			length.c		\
			compare.c		\
			copy.c			\

OBJ		=	$(SRC:.c=.o)

NAME 	=	libstring.a

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:		
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)

re: fclean all
