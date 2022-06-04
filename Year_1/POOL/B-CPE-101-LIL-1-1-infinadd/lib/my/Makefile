##
## EPITECH PROJECT, 2020
## Anthony Becarne
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar	rc	$(NAME)	$(OBJ)
		cp	my.h	../../include/

clean:	$(OBJ)
	rm	-f	$(OBJ)

fclean:
	rm -rf $(NAME)