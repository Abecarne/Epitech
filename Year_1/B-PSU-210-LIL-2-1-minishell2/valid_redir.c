/*
** EPITECH PROJECT, 2021
** sem2 [WSL: Ubuntu-20.04]
** File description:
** valid redir
*/

#include "include/minishell.h"

int missing_name(st_minishell *st)
{
    for (int i = 0; st->arg[i] != NULL; i++)
        for (int j = 0; st->arg[i][j] != NULL; j++)
            if (my_strcmp(st->arg[i][j], ">") == 0
            && my_strcmp(st->arg[i][j + 1], ">") == 0) {
                my_printf("Missing name for redirect.\n");
                return (0);
            }
    return (1);
}

int ambiguous_cmd(st_minishell *st)
{
    int max = 0;
    int actual = 0;

    for (int i = 0; st->arg[i] != NULL; i++) {
        for (int j = 0; st->arg[i][j] != NULL; j++)
            if (my_strcmp(st->arg[i][j], ">"))
                actual++;
        if (actual > max)
            max = actual;
        else
            actual = 0;
    }
    if (max > 2) {
        my_printf("Ambiguous output redirect.\n");
        return (0);
    }
    else
        return (1);
}

int many_redir(st_minishell *st)
{
    for (int i = 0; st->arg[i] != NULL; i++)
        for (int j = 0; st->arg[i][j] != NULL; j++)
            if (my_strcmp(st->arg[i][j], ">") == 0
            && my_strcmp(st->arg[i][j + 1], ">") == 0) {
                my_printf("Missing name for redirect.\n");
                return (0);
            }
    return (1);
}