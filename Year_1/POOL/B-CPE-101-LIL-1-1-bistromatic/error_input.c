/*
** EPITECH PROJECT, 2020
** B-CPE-101-LIL-1-1-bistromatic-anthony.becarne
** File description:
** error_expr
*/

#include "my.h"
#include "bistromatic.h"
#include <stdlib.h>

int error_same_base_op(char **av)
{
    for (int i = 0; av[1][i] != '\0'; i++) {
        for (int j = 0; av[2][j] != '\0'; j++) {
            if (av[1][i] == av[2][j]) {
                my_putstr(SYNTAX_ERROR_MSG);
                my_putchar('\n');
                exit(84);
            }
        }
    }
    return (0);
}

int error_paren(char *buff)
{
    int op_paren = 0;
    int cl_paren = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '(')
            op_paren++;
        if (buff[i] == ')')
            cl_paren++;
    }
    if (op_paren != cl_paren) {
        my_putstr(SYNTAX_ERROR_MSG);
        my_putchar('\n');
        exit(84);
    }
    return (0);
}

int zero(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/' && str[i + 1] == '0') {
            my_putstr("syntax error\n");
            return (84);
        }
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && str[i + 1] == '0') {
            my_putstr("syntax error\n");
            return (84);
        }
    }
    return (0);
}

int do_check_error(char **av, char *buff)
{
    error_same_base_op(av);
    error_paren(buff);
    return (0);
}
