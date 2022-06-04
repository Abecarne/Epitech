##
## EPITECH PROJECT, 2020
## Anthony Becarne
## File description:
## Makefile
##

CFLAGS	= -std=c++20 -Wall -Wextra -Werror -g

SRC	=	main.cpp						\
		ex02/CommunicationAPI.cpp		\
		ex02/Errors.cpp					\
		ex02/CommunicationDevice.cpp	\
		

OBJ	=	$(SRC:.cpp=.o)

NAME	=	test

all:	$(NAME)

$(NAME):	$(OBJ)
		g++ $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -rf $(NAME)

run: all
	@./$(NAME)

re:	fclean all