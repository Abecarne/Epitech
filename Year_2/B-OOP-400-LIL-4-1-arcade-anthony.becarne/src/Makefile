##
## EPITECH PROJECT, 2020
## Anthony Becarne
## File description:
## Makefile
##

CFLAGS	= 	-Wall -Wextra -Werror -fno-gnu-unique

CFLAGS 	+= -I../include/

LIB_FLAGS	=	

SRC		=	main.cpp	\
			Core.cpp		\
			Errors.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	arcade

all:		$(NAME)

$(NAME):	$(OBJ)
			g++ $(OBJ) -o $(NAME) $(CFLAGS) -ldl
			mv $(NAME) ../

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -rf ../$(NAME)

re:			fclean all

.PHONY:		all clean fclean re
