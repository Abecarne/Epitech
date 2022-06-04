##
## EPITECH PROJECT, 2020
## lib_a
## File description:
## Makefile
##

NAME		=	arcade_sdl2.so

SRC 		=	sdl2.cpp 	\
				encapsulate/encapsulate.cpp

OBJ			=	$(SRC:.cpp=.o)

CFLAGS		= 	-Wall -Wextra -Werror -fPIC

LIB_SDL2	=	-lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

$(NAME):	$(OBJ)
			g++ -c $(CFLAGS) $(SRC)
			g++ -shared -o $(NAME) $(OBJ) $(LIB_SDL2)
			mv $(NAME) ../../lib/

all:		$(NAME)

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -rf ../../lib/$(NAME)

re:			fclean all

.PHONY:		all clean fclean re
