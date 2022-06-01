##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 101pong
##

DIR_S = ./solver/
DIR_G = ./generator/
NAME_S = $(DIR_S)solver
NAME_G = $(DIR_G)generator

all:	$(NAME_S)	\
		$(NAME_G)

$(NAME_S):
			make -C $(DIR_S)
			make -C $(DIR_S) clean

$(NAME_G):
			make -C $(DIR_G)
			make -C $(DIR_G) clean

clean:
			make -C $(DIR_G) clean
			make -C $(DIR_S) clean

fclean:		clean
			make -C $(DIR_G) fclean
			make -C $(DIR_S) fclean

re:			fclean all
