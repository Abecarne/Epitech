/*
** EPITECH PROJECT, 2020
** B-CPE-101-LIL-1-1-bistromatic-anthony.becarne
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromatic.h"
#include "my.h"

char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == NULL) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = '\0';
    return (expr);
}

void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

int error_input(char **av)
{
    for (int i = 0; av[1][i] != '\0'; i++) {
        for (int j = 0; av[2][j] != '\0'; j++) {
            if (av[1][i] == av[2][j])
                exit(84);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    unsigned int size = 0;
    char *expr;

    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        exit(EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2]);
    error_input(av);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    my_putstr(bistro(av, expr, size));
    my_putchar('\n');
    return (EXIT_SUCCESS);
}
