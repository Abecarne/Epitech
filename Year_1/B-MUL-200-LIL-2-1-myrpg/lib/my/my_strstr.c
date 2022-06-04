/*
** EPITECH PROJECT, 2020
** my_strstr.c
** File description:
** strstr
*/

#include <stdio.h>

int search(char *str, char const *to_find, int i)
{
    int j = 0;

    for (; str[i] == to_find[j] && to_find[j] != '\0' && str[i] != '\0'; i++) {
        if (to_find[j + 1] == '\0' && str[i] == to_find[j])
            return (1);
        j++;
    }
    return (0);
}

int my_strstr(char *str, char const *to_find)
{
    int find = 0;
    int i = 0;

    for (; str[i] != '\0' && find == 0; i++)
        if (str[i] == to_find[0])
            find = search(str, to_find, i);
    return (find);
}
