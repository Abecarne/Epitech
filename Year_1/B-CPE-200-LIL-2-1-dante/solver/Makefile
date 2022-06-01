##
## EPITECH PROJECT, 2020
## Anthony Becarne
## File description:
## Makefile
##

CFLAGS	= 	-W -Wall -Wextra -I./../include -L./../lib/my -lmy

SRC		=	main.c		\
			load_map.c	\
			error_map.c \
			solving.c	\
			free.c 		\
			checking.c

OBJ		=	$(SRC:.c=.o)

NAME	=	solver

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C ./../lib/my
			make -C ./../lib/my clean
			gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
			rm -f $(OBJ)
			rm -f libmy.a
			rm -f *.o
			rm -f *~
			rm -f *#
			rm -f lib/my/*.o

fclean: 	clean
			rm -rf $(NAME)
			make -C ./../lib/my fclean

re:			fclean all

debug:		re
			gcc $(OBJ) -o $(NAME) $(CFLAGS) -g