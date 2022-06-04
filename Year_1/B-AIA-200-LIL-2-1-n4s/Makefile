##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC =		main.c \
			init_struct.c \
			ia.c \
			wheels_dir.c \
			change_speed.c \
			recup_lidar.c \
			check_lap.c \
			turning.c \
			get_stdin.c
			

OBJ =		$(SRC:.c=.o)

NAME =		ai

CFLAGS =	-Iinclude -Llib/my -lmy

DEBUGFLAGS = -g

all:	$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			make -C lib/my clean
			gcc -o $(NAME) $(SRC) $(CFLAGS)

debug:
			make -C lib/my
			make -C lib/my clean
			gcc -o $(NAME) $(SRC) $(CFLAGS) $(DEBUGFLAGS)

clean:
			rm -f $(OBJ)

fclean:clean
			rm -f $(NAME)

re:			fclean all
