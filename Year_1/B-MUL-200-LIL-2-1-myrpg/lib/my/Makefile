##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	my_compute_power_rec.c							\
		my_compute_square_root.c						\
		my_getnbr.c										\
		my_is_prime.c									\
		my_isneg.c										\
		my_itoa.c										\
		my_put_error.c									\
		my_put_nbr.c									\
		my_putchar.c									\
		my_putstr.c										\
		my_revstr.c										\
		my_sort_int_array.c								\
		my_show_word_array.c							\
		my_str_isalpha.c								\
		my_str_islower.c								\
		my_str_isnum.c									\
		my_str_isprintable.c							\
		my_str_isupper.c								\
		my_strcapitalize.c								\
		my_strcat.c										\
		my_strcmp.c										\
		my_strcpy.c										\
		my_strdup.c										\
		my_strlen.c										\
		my_strlowcase.c									\
		my_strncat.c									\
		my_strncmp.c									\
		my_strncpy.c									\
		my_strstr.c										\
		my_strupcase.c									\
		my_swap.c										\
		my_printf/my_printf.c							\
		my_printf/printf_error.c						\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/
	rm $(NAME)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:    clean
	rm -f ../libmy.a

re:    fclean    all
