##
## EPITECH PROJECT, 2020
## Anthony Becarne
## File description:
## Makefile
##

CFLAGS	= -std=c++20 -Wall -Wextra -Werror

SRC	=	main.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	my_cat

all:	$(NAME)

$(NAME):	$(OBJ)
		g++ $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:	fclean all