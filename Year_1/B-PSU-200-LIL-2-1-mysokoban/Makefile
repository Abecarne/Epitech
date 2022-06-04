##
## EPITECH PROJECT, 2020
## Anthony Becarne
## File description:
## Makefile
##

CFLAGS	= -W -Wall -Wextra -g

CFLAGS += -I./include/ -Llib/my -lmy -lncurses

SRC	=	main.c	\
		map.c	\
		cursor.c	\
		loading.c	\
		interactions.c	\
		objectives.c	\
		endgame.c	\
		gameloop.c	\
		boxes.c	\
		error/error_map.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		make -C lib/my clean
		gcc $(OBJ) -o $(NAME) $(CFLAGS) $(LIB_CSFML)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -rf $(NAME)
		make -C lib/my fclean

re:	fclean all