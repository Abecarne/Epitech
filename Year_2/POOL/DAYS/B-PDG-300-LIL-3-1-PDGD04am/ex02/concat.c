/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** concat
*/

#include "concat.h"
#include <string.h>
#include <stdlib.h>

void concat_strings(const char *str1, const char *str2, char **res)
{
    *res = malloc(sizeof(char) * (strlen(str1) + strlen(str2)) + 1);
    strcpy(*res, str1);
    strcat(*res, str2);
}

void concat_struct(concat_t *str)
{
    int len1 = strlen(str->str1);
    int len2 = strlen(str->str2);

    str->res = malloc(sizeof(char) * (len1 + len2) + 1);
    strcpy(str->res, str->str1);
    strcat(str->res, str->str2);
}
