##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## task01
##

SRC	=	my_putchar.c	\
		my_getnbr.c	\
		my_getsigne.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_str_to_word_array.c	\
		my_strlen.c	\
		my_revstr.c

CFLAGS	=	-I../../include

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) copylibmy

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

copylibmy:
	cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
