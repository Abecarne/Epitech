/*
** EPITECH PROJECT, 2021
** delivery [WSL: Ubuntu-20.04]
** File description:
** built_cd
*/

#include "include/minishell.h"

void error_cd(st_minishell *st)
{
    if (my_strcmp(st->arg[st->cm][1], "-") == 0) {
        chdir(st->previous);
    } else if (chdir(st->arg[st->cm][1]) != 0)
        my_printf("%s: %s.\n", st->arg[st->cm][1], strerror(errno));
}

void exec_cd(st_minishell *st)
{
    if (nb_lines_tab(st->arg[st->cm]) == 2) {
        error_cd(st);
    } else if (st->arg[st->cm][1] == NULL) {
        chdir("/home");
    } else
        my_printf("cd: Too many arguments.\n");
    st->previous = malloc(sizeof(char) * 512);
    if (!st->previous)
        exit(84);
    st->previous = my_strcpy(st->previous, st->current);
}
