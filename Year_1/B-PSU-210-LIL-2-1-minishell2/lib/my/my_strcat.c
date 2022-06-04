/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** project
*/
#include <stdlib.h>

int my_strlen(char *);

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *res = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (j; dest[j] != '\0';j++)
        res[j] = dest[j];
    for (i; src[i] != '\0'; i++)
        res[j + i] = src[i];
    res[j + i] = '\0';
    return (res);
}