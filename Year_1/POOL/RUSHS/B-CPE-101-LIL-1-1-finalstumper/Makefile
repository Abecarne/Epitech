##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## task01
##

SRC     =      	main.c	\
				final.c

OBJ		=		$(SRC:.c=.o)

NAME    =       rush3

LIB     =       -L lib/my/ -lmy

CFLAGS  =       -I include

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	make -C lib/my clean
	rm -f *.o
	rm -f *~

fclean: clean
	make -C lib/my fclean
	rm -f $(NAME)

re:     fclean all
