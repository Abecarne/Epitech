##
## EPITECH PROJECT, 2020
## Anthony Becarne
## File description:
## Makefile
##

CFLAGS	= -W -Wall -Wextra

CFLAGS += -I./include/ -Llib/my -lmy -g

LIB_CSFML += -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

SRC	=	main.c	\
		window.c	\
		help.c	\
		perso.c	\
		floor.c	\
		anim.c	\
		background.c	\
		destroy.c	\
		init_struct.c	\
		init_struct2.c	\
		score.c	\
		clouds.c	\
		mountains.c \
		bushes.c	\
		shoot.c	\
		enemies.c	\
		wall.c	\
		check_game.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

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