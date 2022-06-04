/*
** EPITECH PROJECT, 2021
** sem2 [WSL: Ubuntu-20.04]
** File description:
** get_cmd
*/

#include "include/minishell.h"

char **get_cmd(st_minishell *st, char *src)
{
    int ind = 0;
    char **command = NULL;

    command = malloc(sizeof(char *) * (nb_lines_tab(st->arg[st->cm])));
    if (!command)
        exit(84);
    for (int i = 0; st->arg[st->cm][i] != NULL; i++) {
        if (my_strcmp(st->arg[st->cm][i], src) == 0) {
            break;
        } else {
            command[ind] = my_strdup(st->arg[st->cm][i]);
            ind++;
        }
    }
    return (command);
}

char **get_next_cmd(st_minishell *st, char *src)
{
    int x = 0;
    int ind = 0;
    char **command = malloc(sizeof(char *) * (nb_lines_tab(st->arg[st->cm])));

    if (!command)
        exit(84);
    for (x = 0; my_strcmp(st->arg[st->cm][x], src) != 0; x++);
    for (int i = x + 1; st->arg[st->cm][i] != NULL; i++) {
        command[ind] = my_strdup(st->arg[st->cm][i]);
        ind++;
    }
    command[ind] = NULL;
    return (command);
}