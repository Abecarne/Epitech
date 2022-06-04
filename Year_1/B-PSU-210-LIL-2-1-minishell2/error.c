/*
** EPITECH PROJECT, 2021
** delivery [WSL: Ubuntu-20.04]
** File description:
** error
*/

#include "include/minishell.h"

int error_handler(int ac, char **av)
{
    if (ac != 1)
        return (84);
    (void)av;
    return (0);
}

int my_is_alphanum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (est_lettre(str[i]) != 0 && is_nbr(str[i]) != 0)
            return (1);
    return (0);
}

int error_setenv(st_minishell *st)
{
    int nbl = nb_lines_tab(st->arg[st->cm]);

    if (nbl > 3) {
        my_printf("setenv: Too many arguments.\n");
        return (1);
    } else if (nbl == 2 || nbl == 3) {
        if (my_is_alphanum(st->arg[st->cm][1]) != 0) {
            my_printf("setenv: Variable name must contain ");
            my_printf("alphanumeric characters.\n");
            return (1);
        } else if (is_nbr(st->arg[st->cm][1][0]) == 0) {
            my_printf("setenv: Variable name must begin with a letter.\n");
            return (1);
        }
    }
    return (0);
}

int error_unsetenv(st_minishell *st)
{
    if (nb_lines_tab(st->arg[st->cm]) == 1) {
        my_printf("unsetenv: Too few arguments.\n");
        return (1);
    }
    return (0);
}

char *check_valid_input(char *str)
{
    if (my_strcmp(str, "/bin/ls") == 0) {
        return ("ls");
    }
    return (str);
}