/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_strdup
*/

#include <stdlib.h>
#include <stdio.h>

char *my_strdup(char const *src)
{
    int i = 0;
    char *dest = NULL;

    while (src[i] != '\0')
        i++;
    dest = malloc(sizeof(char) * (i + 1));
    for (int j = 0; j < i; j++)
        dest[j] = src[j];
    return (dest);
}