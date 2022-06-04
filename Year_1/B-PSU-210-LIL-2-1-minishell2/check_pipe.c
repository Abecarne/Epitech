/*
** EPITECH PROJECT, 2021
** sem2 [WSL: Ubuntu-20.04]
** File description:
** check_pipe
*/

#include "include/minishell.h"

int check_valid_redir(st_minishell *st)
{
    if (missing_name(st) == 0)
        return (0);
    if (ambiguous_cmd(st) == 0)
        return (0);
    if (many_redir(st) == 0)
        return (0);
    return (1);
}

int symbol_redir(st_minishell *st)
{
    for (int i = 0; st->arg[i] != NULL; i++) {
        if (arg_in_tab(st->arg[i], "<") == 0)
            return (left_redir(st));
        if (arg_in_tab(st->arg[i], ">") == 0)
            return (right_redir(st));
    }
    return (0);
}

int is_symbol(st_minishell *st)
{
    if (arg_in_tab(st->arg[st->cm], "|") == 0) {
        pipe_handler(st);
        return (1);
    } else if (symbol_redir(st) == 1) {
        right_redir(st);
        left_redir(st);
        return (1);
    }
    return (0);
}

int nb_pipe(char **tab)
{
    int cpt = 0;

    for (int i = 0; tab[i] != NULL; i++)
        if (my_strcmp(tab[i], "|") == 0)
            cpt++;
    return (cpt);
}