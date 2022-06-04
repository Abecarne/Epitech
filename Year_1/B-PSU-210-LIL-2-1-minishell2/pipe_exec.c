/*
** EPITECH PROJECT, 2021
** sem2 [WSL: Ubuntu-20.04]
** File description:
** pipe_exec
*/

#include "include/minishell.h"

void fork_cmd(st_minishell *st, char *check, char **cmd, int fd)
{
    int term = 0;
    pid_t pid = 0;
    pid_t fin = 0;

    pid = fork();
    if (pid == 0) {
        dup2(fd, 1);
        execve(check, cmd, st->env);
        my_printf("%s\n", strerror(errno));
        exit(1);
    } else
        do {
            fin = waitpid(pid, &term, WUNTRACED);
        } while (WIFEXITED(term) != true && WIFSIGNALED(term) != true);
}

void exec_cmd(st_minishell *st, char **cmd, int fd)
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
            fork_cmd(st, check, cmd, fd);
    }
}

void simple_pipe(st_minishell *st, char **cmd, int *fd, int status)
{
    char *well = NULL;

    if (status == 1) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
    } else {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
    }
    // dprintf(2, "JE SUIS LA\n");
    well = get_path(st, cmd);
    // dprintf(2, "cmd = %s\n", well);
    execve(well, cmd, st->env);
    my_printf("%s\n", strerror(errno));
    exit(1);
}

void prepare_pipe(st_minishell *st, char **cmd1, char **cmd2)
{
    int fd[2];
    pid_t pid = 0;

    if (pipe(fd) == -1) {
        perror("pipe");
        return;
    }
    if ((pid = fork()) == -1) {
        perror("fork");
        return;
    }
    if (pid == 0) {
        simple_pipe(st, cmd1, fd, 1);
    } else {
        if (my_strcmp(cmd2[0], "cat") == 0)
            special_pipe(st, cmd2, fd, 1);
        else
            special_pipe(st, cmd2, fd, 0);
    }
}
