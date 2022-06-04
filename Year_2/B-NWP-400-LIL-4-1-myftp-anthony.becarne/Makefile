##
## EPITECH PROJECT, 2020
## Anthony Becarne
## File description:
## Makefile
##

CFLAGS 	+= 	-I../include/ -Wall -Wextra -Werror -g

# Main files
SRC		=	src/main.c 					\
			src/error.c					\
			src/free_ressources.c		\
			src/init.c					\
			src/linked_list.c			\
			src/linked_list2.c			\
			src/parser.c				\

# Server files
SRC		+=	src/server/server.c			\
			src/server/main_server.c	\

# Client files
SRC		+= 	src/client/client.c			\
			src/client/commands.c		\
			src/client/commands2.c		\
			src/client/commands3.c		\


OBJ		=	$(SRC:.c=.o)

NAME	=	myftp

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
