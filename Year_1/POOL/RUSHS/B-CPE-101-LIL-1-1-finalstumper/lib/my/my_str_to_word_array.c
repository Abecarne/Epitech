/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

int find_nalphanumeric(char c)
{
    if (c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a') || c > 'z')
        return (1);
    return (0);
}

int find_nb(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (find_nalphanumeric(str[i]) == 1)
            nb++;
        while (find_nalphanumeric(str[i]) == 1)
            i++;
    }
    return (nb + 1);
}

char **my_str_to_word_array(char  const *str)
{
    char **src = malloc(sizeof(char *) * find_nb(str) + 1);
    int nb2 = 0;
    int i = 0;
    int nb = 0;

    for (int nb1 = 0; nb1 < find_nb(str); nb1 = nb1 + 1)
    {
        nb2 = 0;
        while (find_nalphanumeric(str[nb]) == 1)
            nb = nb + 1;
        for (i = nb; find_nalphanumeric(str[i]) == 0; i++) {}
        src[nb1] = malloc(sizeof(char) * (i + 1));
        while (find_nalphanumeric(str[nb]) == 0) {
            src[nb1][nb2] = str[nb];
            nb2 = nb2 + 1;
            nb++;
        }
    }
    return (src);
}