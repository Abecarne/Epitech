##
## EPITECH PROJECT, 2020
## lib_a
## File description:
## Makefile
##

NAME	=	arcade_pacman.so

SRC 	=	main.cpp		\
			move.cpp		\
			end.cpp			\
			timer.cpp		\
			moveGhost.cpp	\

OBJ		=	$(SRC:.cpp=.o)

CFLAGS	= 	-Wall -Wextra -Werror -fPIC

$(NAME):	$(OBJ)
			g++ -c $(CFLAGS) $(SRC)
			g++ -shared -o $(NAME) $(OBJ) -g
			mv $(NAME) ../../lib/

all:		$(NAME)

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -rf ../../lib/$(NAME)

re:			fclean all

.PHONY:		all clean fclean re
