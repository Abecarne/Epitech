/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** project
*/

#include <stdlib.h>

int my_strlen(char const *);

char *my_strdup(char const *src)
{
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src)+ 1));
    while (i < src[i])
    {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
