/*
** EPITECH PROJECT, 2021
** minishell2 [WSL: Ubuntu-20.04]
** File description:
** parse
*/

#include "include/minishell.h"

char **parse_pt_v(char *str)
{
    int i = 0;
    char *word = NULL;
    char **tok = malloc(sizeof(char *) * 20);

    if (!tok)
        exit(84);
    word = strtok(str, ";");
    for (i = 0; word != NULL; i++) {
        tok[i] = word;
        word = strtok(NULL, ";");
    }
    tok[i] = NULL;
    return (tok);
}

char **parse(char *str)
{
    int i = 0;
    char *word = NULL;
    char **tok = malloc(sizeof(char *) * 20);

    if (!tok)
        exit(84);
    word = strtok(str, " \t\n");
    for (i = 0; word != NULL; i++) {
        tok[i] = word;
        word = strtok(NULL, " \t\n");
    }
    tok[i] = NULL;
    return (tok);
}

char ***triple_parse(st_minishell *st)
{
    int i = 0;
    char ***res = malloc(sizeof(char **) * 30);
    char **pt_v = parse_pt_v(st->input);

    if (!res || !pt_v)
        exit(84);
    for (i = 0; pt_v[i] != NULL; i++) {
        res[i] = parse(pt_v[i]);
    }
    res[i] = NULL;
    return (res);
}