/*
** EPITECH PROJECT, 2021
** sem2 [WSL: Ubuntu-20.04]
** File description:
** clean
*/

#include "include/minishell.h"

char *clean_spaces(char *str)
{
    int ind = 0;
    char *res = malloc(sizeof(char) * my_strlen(str) + 1);

    for (int i = 0; str[i] != '\0'; i++, ind++) {
        if (str[i] == ' ')
            while (str[i + 1] == ' ')
                i++;
        res[ind] = str[i];
    }
    return (res);
}

int next_char(const char *str, int i)
{
    while (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == ';')
        i++;
    return (i);
}

char *clean_input(const char *str)
{
    int ind = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!tmp)
        exit(84);
    for (int i = 0; str[i] != '\0'; i++, ind++) {
        if (str[i] == ';') {
            tmp[ind] = str[i];
            i = next_char(str, i);
            ind++;
            tmp[ind] = ' ';
        } else
            tmp[ind] = str[i];
    }
    tmp[ind] = '\0';
    return (tmp);
}
