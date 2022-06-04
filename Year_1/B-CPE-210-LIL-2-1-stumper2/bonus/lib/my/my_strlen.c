/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** Task 03
*/

#include <stddef.h>

int my_tablen(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return (i);
}

int my_strlen(char const *str)
{
    int a = 0;

    while (str[a] != '\0')
        a = a + 1;
    return (a);
}
