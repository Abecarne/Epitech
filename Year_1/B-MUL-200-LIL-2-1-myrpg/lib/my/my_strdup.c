/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** str dup
*/

#include <stdio.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *dup = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (dup == NULL)
        return (NULL);
    return (my_strcpy(dup, src));
}
