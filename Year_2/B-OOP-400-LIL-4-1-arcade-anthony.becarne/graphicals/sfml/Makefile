##
## EPITECH PROJECT, 2020
## lib_a
## File description:
## Makefile
##

NAME		=	arcade_sfml.so

SRC 		=	sfml.cpp 		\
				Init_window.cpp \
				Init_menu.cpp	\
				Init_map.cpp	\
				Draw_map.cpp	\
				EndGame.cpp		\

OBJ			=	$(SRC:.cpp=.o)

CFLAGS		= 	-Wall -Wextra -Werror -fPIC

LIB_SFML	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

$(NAME):	$(OBJ)
			g++ -c $(CFLAGS) $(SRC)
			g++ -shared -o $(NAME) $(OBJ) $(LIB_SFML)
			mv $(NAME) ../../lib/

all:		$(NAME)

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -rf ../../lib/$(NAME)

re:			fclean all

.PHONY:		all clean fclean re
