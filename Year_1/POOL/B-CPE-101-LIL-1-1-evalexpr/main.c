/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** main
*/

#include "my.h"
#include <stdlib.h>

#include <stdio.h>
#include <unistd.h>

int find_calcul(char **av);

int first_calcul(char *str);

int eval_expr(char *str);

int  main(int ac , char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);

}
