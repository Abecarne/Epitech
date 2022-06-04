/*
** EPITECH PROJECT, 2021
** delivery [WSL: fedora]
** File description:
** exec
*/

#include "minishell.h"

char last_car(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (str[i - 1]);
}

char *create(char *path, char *cmd)
{
    char *res = malloc(sizeof(char) * (my_strlen(path) + my_strlen(cmd)) + 2);

    if (!res)
        exit(84);
    if (last_car(path) == '/')
        res = my_strcat(path, cmd);
    else {
        res = my_strcat(path, "/");
        res = my_strcat(res, cmd);
    }
    res[(my_strlen(path) + my_strlen(cmd)) + 1] = '\0';
    return (res);
}

void forking(st_minishell *st, char *check, char **env)
{
    int term = 0;
    pid_t pid = 0;
    pid_t fin = 0;

    pid = fork();
    if (pid == 0) {
        execve(check, st->arg[st->cm], st->env);
        my_printf("%s\n", strerror(errno));
        exit(1);
    } else
        do {
            fin = waitpid(pid, &term, WUNTRACED);
        } while (WIFEXITED(term) != true && WIFSIGNALED(term) != true);
}

int execute(st_minishell *st)
{
    char *check = malloc(sizeof(char) * 256);
    char **paths = NULL;

    if (!check)
        return (84);
    paths = path(st->env);
    if (paths == NULL)
        my_printf("%s: Command not found.\n", st->arg[st->cm][0]);
    else {
        for (int i = 0; paths[i] != NULL; i++) {
            check = create(paths[i], st->arg[st->cm][0]);
            if (access(check, X_OK) == 0 && access(check, F_OK) == 0)
                break;
            check = NULL;
        }
        if (check == NULL)
            my_printf("%s: Command not found.\n", st->arg[st->cm][0]);
        else
            forking(st, check, st->env);
    }
    return (0);
}