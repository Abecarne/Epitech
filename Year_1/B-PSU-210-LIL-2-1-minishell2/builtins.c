/*
** EPITECH PROJECT, 2021
** delivery [WSL: Ubuntu-20.04]
** File description:
** builtins
*/

#include "include/minishell.h"

typedef void (*command)(st_minishell *);

static void *builtin_tab[][2] = {
    {"cd", exec_cd}, {"env", exec_env}, {"setenv", exec_setenv},
    {"unsetenv", exec_unsetenv}, {NULL, NULL}
};

int check_builtin(st_minishell *st)
{
    for (int i = 0; builtin_tab[i][0]; i++) {
        if (my_strcmp(st->arg[st->cm][0], (char *)builtin_tab[i][0]) == 0) {
            ((command)builtin_tab[i][1])(st);
            return (1);
        }
    }
    return (0);
}
