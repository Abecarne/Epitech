/*
** EPITECH PROJECT, 2021
** sem2 [WSL: Ubuntu-20.04]
** File description:
** simple_redir
*/

#include "include/minishell.h"

void simple_right(st_minishell *st, char **cmd1, char **cmd2)
{
    int fd = open(cmd2[0], O_CREAT | O_WRONLY | O_TRUNC, 0644);

    exec_cmd(st, cmd1, fd);
    close(fd);
}

void double_right(st_minishell *st, char **cmd1, char **cmd2)
{
    int fd = open(cmd2[0], O_CREAT | O_WRONLY | O_APPEND, 0644);

    exec_cmd(st, cmd1, fd);
    close(fd);
}

int right_redir(st_minishell *st)
{
    char **first = NULL;
    char **second = NULL;
    if (arg_in_tab(st->arg[st->cm], ">") == 0) {
        first = get_cmd(st, ">");
        second = get_next_cmd(st, ">");
        if (first[0] == NULL || second[0] == NULL)
            return (1);
        else
            simple_right(st, first, second);
        return (1);
    } else if (arg_in_tab(st->arg[st->cm], ">>") == 0) {
        first = get_cmd(st, ">>");
        second = get_next_cmd(st, ">>");
        if (first[0] == NULL || second[0] == NULL)
            return (1);
        else
            double_right(st, first, second);
        return (1);
    } else
        return (0);
}
