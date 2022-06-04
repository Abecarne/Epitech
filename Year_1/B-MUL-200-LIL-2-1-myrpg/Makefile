##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##


SRC	=	src/main.c						\
		src/help.c						\
		src/free_var.c					\
		src/menu/text.c 				\
		src/menu/hover.c				\
		src/menu/events.c				\
		src/menu/musics.c				\
		src/menu/mallocs.c				\
		src/menu/load_var.c				\
		src/menu/load_var2.c        	\
		src/menu/init_var.c				\
		src/menu/positions.c			\
		src/menu/init_var2.c			\
		src/menu/main_menu.c			\
		src/menu/window_main.c			\
		src/menu/window_main_loop.c     \
		src/menu/display_scenes.c		\
		src/menu/hover_main_menu.c		\
		src/menu/hover_pause_menu.c 	\
		src/menu/hover_option.c     	\
		src/fight/fight_var.c			\
		src/fight/fight_pos.c			\
		src/fight/fight_loop.c			\
		src/fight/fight_loop_loop.c		\
		src/fight/fight_scene.c			\
		src/fight/fight_hover.c			\
		src/fight/fight_launch.c		\
		src/fight/fight_hover2.c		\
		src/animations/heal.c			\
		src/animations/charge.c			\
		src/animations/buff.c			\
		src/animations/get_attacked.c	\


CFLAGS	=	-I include

GRAPH = -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio

LIB	=	-L lib/ -l my

NAME	=	my_rpg

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc $(OBJ) -o $(NAME) $(LIB) $(CFLAGS) $(GRAPH)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -rf $(NAME)
		make -C lib/my fclean

re:	fclean all

valgrind : re
	gcc -Wall -Wextra -o $(NAME) $(SRC) $(LIB) -lm $(CFLAGS) $(GRAPH) -g
