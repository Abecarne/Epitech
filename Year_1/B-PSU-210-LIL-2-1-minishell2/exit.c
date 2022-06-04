/*
** EPITECH PROJECT, 2021
** sem2 [WSL: Ubuntu-20.04]
** File description:
** exit
*/

#include "include/minishell.h"

void get_return_value(st_minishell *st)
{
    if (my_str_isnbr(st->arg[st->cm][1]) == 0)
        st->return_value = my_getnbr(st->arg[st->cm][1]);
}

int breaker(st_minishell *st)
{
    if (my_strcmp(st->arg[st->cm][0], "exit\n") == 0) {
        if (st->arg[st->cm][1] != NULL)
            get_return_value(st);
        return (1);
    }
    return (0);
}
