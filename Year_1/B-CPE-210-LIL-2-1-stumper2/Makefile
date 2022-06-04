##
## EPITECH PROJECT, 2020
## Duo stumper 1
## File description:
## Makefile
##

SRC	=	main.c	\
		map.c	\
		error.c \

NAME	=	gameoflife

LIBRARY	=	-Llib/my -lmy

W_FLAGS	=	-W -Wall -Wextra

all:	$(NAME)

$(NAME):
	make -C ./lib/my
	gcc -o $(NAME) $(SRC) $(LIBRARY) $(W_FLAGS)

clean:
	rm -f libmy.a
	rm -f *.o
	rm -f *~
	rm -f *#
	rm -f lib/my/*.o

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re: fclean all