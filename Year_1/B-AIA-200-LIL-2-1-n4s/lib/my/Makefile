##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile lib
##

SRC 	=	my_getnbr.c \
		my_is_prime.c \
		my_isneg.c \
		my_put_nbr.c \
		my_putchar.c \
		my_putstr.c \
		my_revstr.c \
		my_showmem.c \
		my_showstr.c \
		my_sort_int_array.c \
		my_str_isalpha.c \
		my_str_isnum.c \
		my_str_isalphanum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncpy.c \
		my_strstr.c \
		my_strupcase.c \
		my_swap.c \
		my_put_long.c \
		my_str_to_word_array.c \
		folder_printf/base.c \
		folder_printf/check_forma.c \
		folder_printf/check_number.c \
		folder_printf/forma.c \
		folder_printf/my_printf.c \
		folder_printf/no_printable.c \
		long_to_char.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:	$(OBJ)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)