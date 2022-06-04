/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** strncpy
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    if (my_strlen(src) <= n)
        dest[my_strlen(src)] = '\0';
    return (dest);
}
