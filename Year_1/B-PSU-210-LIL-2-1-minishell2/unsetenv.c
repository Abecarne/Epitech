/*
** EPITECH PROJECT, 2021
** minishell2 [WSL: Ubuntu-20.04]
** File description:
** unsetenv
*/

#include "include/minishell.h"

char **delete_var(st_minishell *st, char **src)
{
    int i = 0;
    int ind = 0;
    int lines = nb_lines_tab(src) + 1;
    char **cpy = copy_2d_array(src);
    char **res = malloc(sizeof(char *) * (lines));

    for (i = 0; cpy[i] != NULL; i++) {
        if (existing_var(cpy[i], st->arg[st->cm][1]) != 0) {
            res[ind] = my_strdup(src[i]);
            ind++;
        }
    }
    res[ind] = NULL;
    return (res);
}
