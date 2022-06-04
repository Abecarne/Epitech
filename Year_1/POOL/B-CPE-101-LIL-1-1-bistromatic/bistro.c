/*
** EPITECH PROJECT, 2020
** B-CPE-101-LIL-1-1-bistromatic-anthony.becarne
** File description:
** bistro
*/

#include "my.h"
#include "bistromatic.h"

char *eval_expr(char *str);

char *bistro(char **av, char *expr, int size)
{
    char *expr_calc = change_str(expr, av[1], "0123456789");
    expr_calc = change_str(expr_calc, av[2], "()+-*/%");
    do_check_error(av, expr_calc);
    expr_calc = my_strncpy(expr_calc, expr_calc, size);
    return (eval_expr(expr_calc));
}