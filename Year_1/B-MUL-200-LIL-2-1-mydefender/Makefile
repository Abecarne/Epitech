##
## EPITECH PROJECT, 2020
## Anthony Becarne
## File description:
## Makefile
##

CFLAGS	= -W -Wall -Wextra -g

CFLAGS += -I./include/ -Llib/my -lmy

LIB_CSFML += -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

SRC	=	main.c	\
		sun.c	\
		help.c	\
		loops.c	\
		free.c	\
		music.c \
		event.c \
		hover.c \
		loading.c	\
		loading2.c \
		display.c	\
		positions.c	\
		zombie.c	\
		zomb.c	\
		zomb2.c \
		clocks.c	\
		positions2.c	\
		load_sprite.c	\
		how_to_play.c	\
		mouse_hover.c	\
		icones_perso.c	\
		hover_pause.c	\
		change_zomb.c	\
		init_variables.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

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