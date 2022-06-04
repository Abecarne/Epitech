##
## EPITECH PROJECT, 2020
## Anthony Becarne
## File description:
## Makefile
##

CFLAGS	= -W -Wall -Wextra

CFLAGS += -I./include/ -Llib/my -lmy -g

SRC	=	main.c \
		eval_expr.c \
		replace.c \
		fur.c \
		my_spe_getnbr.c \
		my_spe_strlen.c \
		str_operands.c \
		replace_str_calc.c \
		replace_dest.c \
		parenthesis.c \
		operations.c \
		final_calcul.c

OBJ	=	$(SRC:.c=.o)

NAME	=	eval_expr

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		make -C lib/my clean
		gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -rf $(NAME)
		make -C lib/my fclean

re:	fclean all