##
## EPITECH PROJECT, 2022
## delivery [WSL: Ubuntu-20.04]
## File description:
## Makefile
##

SRC		=	regex.c		\
			parser.c	\
			list_dir.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

all:    	$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:		$(OBJ)
			rm -f $(OBJ)

fclean:
			rm -f $(OBJ)
			rm -rf $(NAME)

re:			fclean all
