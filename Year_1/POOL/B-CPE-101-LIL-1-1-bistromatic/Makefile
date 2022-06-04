##
## EPITECH PROJECT, 2020
## Anthony Becarne
## File description:
## Makefile
##

CFLAGS	= -W -Wall -Wextra

CFLAGS += -I./include/ -Llib/my -lmy -g

SRC	=	main.c \
		base.c \
		bistro.c \
		error_input.c \
		eval/eval_expr.c \
		eval/replace.c \
		eval/fur.c \
		eval/my_spe_getnbr.c \
		eval/my_spe_strlen.c \
		eval/str_operands.c \
		eval/replace_str_calc.c \
		eval/replace_dest.c \
		eval/parenthesis.c \
		eval/operations.c \
		eval/final_calcul.c

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

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