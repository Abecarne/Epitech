/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myftp-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** parser
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int count_args_in_tab(char **tokens);

char *remove_last_char(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            return (str);
        }
        i++;
    }
    return (str);
}

char **str_tokenise(char *str)
{
    int i = 0;
    char *word;
    char *tmp = strdup(str);
    char **tok = malloc(sizeof(char *) * 20);

    if (tok == NULL)
        exit(84);
    word = strtok(tmp, " \t\n");
    for (i; word != NULL; i++) {
        tok[i] = word;
        word = strtok(NULL, " \t\n");
    }
    tok[i] = NULL;
    return (tok);
}

char **str_tokenise_special(char *str)
{
    int i = 0;
    char *word;
    char *tmp = strdup(str);
    char **tok = malloc(sizeof(char *) * 20);

    if (tok == NULL)
        exit(84);
    word = strtok(tmp, "\"\n");
    for (i; word != NULL; i++) {
        tok[i] = word;
        word = strtok(NULL, "\"\n");
    }
    tok[i] = NULL;
    return (tok);
}

char **str_tokenise_quoted(char *str)
{
    int i = 0;
    char *word;
    char *tmp = strdup(str);
    char **tok = malloc(sizeof(char *) * 20);

    if (tok == NULL)
        exit(84);
    word = strtok(tmp, "\"");
    for (i; word != NULL; i++) {
        tok[i] = word;
        word = strtok(NULL, "\"");
    }
    tok[i] = NULL;
    return (tok);
}

char **fill_with_quoted(char **tokens)
{
    char **res = malloc(sizeof(char *) * count_args_in_tab(tokens) + 1);
    int index_fill = 0;

    tokens++;
    for (int i = 0; tokens[i] != NULL; i++) {
        res[index_fill] = strdup(str_tokenise_quoted(tokens[i])[0]);
        index_fill++;
    }
    res[index_fill + 1] = NULL;
    return (res);
}
