/*
** EPITECH PROJECT, 2021
** sem2 [WSL: Ubuntu-20.04]
** File description:
** pipe
*/

#include "include/minishell.h"

char *get_path(st_minishell *st, char **cmd)
{
    char *check = malloc(sizeof(char) * 256);
    char **paths = NULL;

    if (!check)
        exit(84);
    paths = path(st->env);
    if (paths == NULL)
        my_printf("%s: Command not found.\n", cmd[0]);
    else {
        for (int i = 0; paths[i] != NULL; i++) {
            check = create(paths[i], cmd[0]);
            if (access(check, X_OK) == 0 && access(check, F_OK) == 0)
                break;
            check = NULL;
        }
        return (check);
    }
    return (check);
}

int alone_pipe(st_minishell *st)
{
    char **first = NULL;
    char **second = NULL;

    if (arg_in_tab(st->arg[st->cm], "|") == 0) {
        first = copy_2d_array(get_cmd(st, "|"));
        second = copy_2d_array(get_next_cmd(st, "|"));
        prepare_pipe(st, first, second);
        return (1);
    } else
        return (0);
}

void pipe_handler(st_minishell *st)
{
    char **tab_path = NULL;

    tab_path = path(st->env);
    if (nb_pipe(st->arg[st->cm]) == 1)
        alone_pipe(st);
}

void special_pipe(st_minishell *st, char **cmd, int *fd, int status)
{
    int term = 0;
    pid_t pid = 0;
    pid_t fin = 0;

    if ((pid = fork()) == -1) {
        perror("fork");
    }
    else if (pid == 0)
        simple_pipe(st, cmd, fd, 0);
    else {
        close(fd[0]);
        close(fd[1]);
        while (waitpid(-1, NULL, 0) > 0);
    }
}