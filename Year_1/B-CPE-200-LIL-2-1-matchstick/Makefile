##
## EPITECH PROJECT, 2020
## Anthony Becarne
## File description:
## Makefile
##

CFLAGS	= -W -Wall -Wextra -g

CFLAGS += -I./include/ -Llib/my -lmy

SRC	=	main.c	\
		game.c	\
		map.c	\
		bot.c	\
		player.c	\
		init_variables.c	\
		check_input_player.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

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