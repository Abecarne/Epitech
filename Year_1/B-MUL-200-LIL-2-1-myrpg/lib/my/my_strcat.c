/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** str cat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int start = my_strlen(dest);

    for (int i = 0; src[i] != '\0'; i++) {
        dest[start] = src[i];
        start++;
    }
    dest[start] = '\0';
    return (dest);
}
