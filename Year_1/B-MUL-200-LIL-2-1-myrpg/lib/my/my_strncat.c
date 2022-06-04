/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** strncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int start = my_strlen(dest);

    for (int i = 0; src[i] != '\0' && i < n; i++) {
        dest[start] = src[i];
        start++;
    }
    dest[start] = '\0';
    return (dest);
}
