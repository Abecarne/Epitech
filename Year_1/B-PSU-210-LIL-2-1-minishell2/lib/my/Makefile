##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile lib
##

SRC 	=	my_swap.c 				\
			my_copy.c				\
			my_isneg.c 				\
			my_getnbr.c				\
			my_putstr.c 			\
			my_revstr.c 			\
			my_strcat.c 			\
			my_strcmp.c 			\
			my_strcpy.c 			\
			my_strlen.c 			\
			my_strdup.c 			\
			my_strstr.c 			\
			my_printf.c				\
			my_putchar.c 			\
			my_put_nbr.c 			\
			my_strncat.c 			\
			my_strncpy.c 			\
			my_strncmp.c 			\
			my_is_prime.c 			\
			my_put_hexa.c 			\
			my_put_unbr.c 			\
			my_is_in_str.c			\
			my_put_maj_s.c			\
			my_strupcase.c			\
			my_str_isnum.c			\
			my_strlowcase.c			\
			my_int_to_char.c		\
			my_str_isalpha.c		\
			my_change_base.c		\
			my_strcapitalize.c		\
			my_str_to_word_array.c	\

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
