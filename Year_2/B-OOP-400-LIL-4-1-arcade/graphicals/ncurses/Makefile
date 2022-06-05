##
## EPITECH PROJECT, 2020
## lib_a
## File description:
## Makefile
##

NAME		=	arcade_ncurses.so

SRC 		=	ncurses.cpp

OBJ			=	$(SRC:.cpp=.o)

CFLAGS		= 	-Wall -Wextra -fPIC

LIB_NCURSES	=	-lncurses

$(NAME):	$(OBJ)
			g++ -c $(CFLAGS) $(SRC)
			g++ -shared -o $(NAME) $(OBJ) $(LIB_NCURSES)
			mv $(NAME) ../../lib/

all:		$(NAME)

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -rf ../../lib/$(NAME)

re:			fclean all

.PHONY:		all clean fclean re
