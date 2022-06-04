##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile lib
##

SRC 	=	my_put_nbr.c \
		my_putchar.c \
		my_putstr.c \
		my_strlen.c \
		my_printf.c	\
		my_int_to_char.c \

OBJ	=	$(SRC:.c=.o)

NAME 	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:	$(OBJ)
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ)
	rm -f $(NAME)
