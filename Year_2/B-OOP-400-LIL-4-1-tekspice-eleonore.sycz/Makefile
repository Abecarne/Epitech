##
## EPITECH PROJECT, 2020
## Anthony Becarne
## File description:
## Makefile
##

CFLAGS	= 	-Wall -Wextra -Werror

CFLAGS += 	-I./include/

SRC		=	src/main.cpp						\
			src/infos.cpp 						\
			src/Circuit.cpp						\
			src/Parser.cpp						\
			src/shell.cpp						\
			src/links.cpp						\
			src/errors/errors.cpp				\
			src/errors/errors_tab.cpp			\
			src/errors/errors_links.cpp			\
			src/Components/C_2716.cpp			\
			src/Components/C_4001.cpp			\
			src/Components/C_4008.cpp			\
			src/Components/C_4011.cpp			\
			src/Components/C_4013.cpp			\
			src/Components/C_4017.cpp			\
			src/Components/C_4030.cpp			\
			src/Components/C_4040.cpp			\
			src/Components/C_4069.cpp			\
			src/Components/C_4071.cpp			\
			src/Components/C_4081.cpp			\
			src/Components/C_4094.cpp			\
			src/Components/C_4512.cpp			\
			src/Components/C_4514.cpp			\
			src/Components/C_4801.cpp			\
			src/Components/C_true.cpp			\
			src/Components/C_clock.cpp			\
			src/Components/C_false.cpp			\
			src/Components/C_input.cpp			\
			src/Components/C_output.cpp			\
			src/Components/Component.cpp		\
			src/Components/ComponentFactory.cpp	\
			src/componentFunctions.cpp			\

OBJ		=	$(SRC:.cpp=.o)

NAME	=	nanotekspice

all:		$(NAME)

$(NAME):	$(OBJ)
			g++ $(OBJ) -o $(NAME) -g $(CFLAGS)

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
