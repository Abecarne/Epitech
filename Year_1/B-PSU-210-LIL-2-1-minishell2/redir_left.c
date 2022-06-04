/*
** EPITECH PROJECT, 2021
** sem2 [WSL: Ubuntu-20.04]
** File description:
** redir_left
*/

#include "include/minishell.h"

void fork_cmd_left(st_minishell *st, char *check, char **cmd, int fd)
{
    int term = 0;
    pid_t pid = 0;
    pid_t fin = 0;

    pid = fork();
    if (pid == 0) {
        dup2(fd, 0);
        execve(check, cmd, st->env);
        my_printf("%s\n", strerror(errno));
        exit(1);
    } else
        do {
            fin = waitpid(pid, &term, WUNTRACED);
        } while (WIFEXITED(term) != true && WIFSIGNALED(term) != true);
}

void exec_cmd_left(st_minishell *st, char **cmd, int fd)
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
        if (check == NULL)
            my_printf("%s: Command not found.\n", cmd[0]);
        else
            fork_cmd_left(st, check, cmd, fd);
    }
}

void simple_left(st_minishell *st, char **cmd1, char **cmd2)
{
    int fd = open(cmd2[0], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    exec_cmd_left(st, cmd1, fd);
    close(fd);
}

void double_left(st_minishell *st, char **cmd1, char **cmd2)
{
    int fd = open(cmd2[0], O_CREAT | O_WRONLY | O_APPEND, 0644);
    exec_cmd_left(st, cmd1, fd);
    close(fd);
}

int left_redir(st_minishell *st)
{
    char **first = NULL;
    char **second = NULL;
    if (arg_in_tab(st->arg[st->cm], "<") == 0) {
        first = get_cmd(st, "<");
        second = get_next_cmd(st, "<");
        if (first[0] == NULL || second[0] == NULL)
            return (1);
        else
            simple_left(st, first, second);
        return (1);
    } else if (arg_in_tab(st->arg[st->cm], "<<") == 0) {
        first = get_cmd(st, "<<");
        second = get_next_cmd(st, "<<");
        if (first[0] == NULL || second[0] == NULL)
            return (1);
        else
            double_left(st, first, second);
        return (1);
    } else
        return (0);
}
