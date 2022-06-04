/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** rev str
*/

#include "my.h"

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    char c;
    int len = my_strlen(str);

    for (int j = my_strlen(str); j != 0; j--) {
        for (int i = len; str[i] != '\0'; i++) {
            c = str[i - 1];
            str[i - 1] = str[i];
            str[i] = c;
        }
        len--;
    }
    return (str);
}
