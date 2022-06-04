##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## just a makefile
##

CRI =	tests/test_point.c 	\
		tests/test_vertex.c	\
		tests/test_int.c	\
		tests/test_float.c	\
		tests/test_char.c	\
		tests/test_array.c	\
		array.c				\
		char.c				\
		float.c				\
		int.c				\
		new.c				\
		point.c				\
		vertex.c

NAME	=	exe_test

FLAGS	=	-g -Wall -Wextra

criterion:
		cp tests/include/*.h .
		gcc -o $(NAME) $(CRI) $(FLAGS) -lcriterion --verbose -fprofile-arcs -ftest-coverage
		./exe_test
		gcovr -r . --html-details -o criterion.html --exclude=tests/
		firefox criterion.html

tests_run:
		cp tests/include/*.h .
		gcc -o $(NAME) $(CRI) $(FLAGS) -lcriterion -lgcov --coverage
		./exe_test
		gcovr -r . -e tests/

clean_tests:
		rm -f tests_my*
		rm -f *.g*
		rm -f *.html
		rm -f $(NAME)
