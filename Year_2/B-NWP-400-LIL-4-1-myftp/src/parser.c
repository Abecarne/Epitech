/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myftp-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** parser
*/

#include "../include/main.h"

int count_args(char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            nb++;
        i++;
    }
    return (nb + 1);
}

char *remove_last_char(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\r') {
            str[i] = '\0';
            return (str);
        }
        i++;
    }
    return (str);
}

char **str_to_word_array(char *str)
{
    int i = 0;
    int j = 0;
    char **tokens = malloc(sizeof(char *) * (count_args(str) + 1));

    str = remove_last_char(str, );
    if (tokens == NULL)
        return (NULL);
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t') {
            str[i] = '\0';
            tokens[j] = strdup(str);
            str = &str[i + 1];
            j++;
        }
        i++;
    }
    tokens[j] = strdup(str);
    tokens[j + 1] = NULL;
    return (tokens);
}
