/*
** EPITECH PROJECT, 2021
** delivery [WSL: fedora]
** File description:
** path
*/

#include "include/minishell.h"

int exist_path(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            return (1);
        }
    return (0);
}

char **path(char **env)
{
    int ind = 0;
    char *way = malloc(sizeof(char) * 256);
    char *tok = malloc (sizeof(char) * 256);
    char **dest = malloc(sizeof(char *) * 64);
    char **cpy = copy_2d_array(env);

    if (!way || !tok || !dest || !cpy)
        exit(84);
    if (exist_path(env) == 0)
        return (NULL);
    for (int i = 0; env[i] != NULL; i++)
        if (my_strncmp(env[i], "PATH=", 5) == 0)
            way = cpy[i] + 5;
    tok = strtok(way, ":");
    for (ind = 0; tok != NULL; ind++) {
        dest[ind] = tok;
        tok = strtok(NULL, ":");
    }
    return (dest);
}