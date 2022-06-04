/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** Task 01
*/
#include <stdlib.h>

int my_strlen(char const *str);

int my_tablen(char **tab);

char *my_strcpy(char const *src)
{
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);

    for (int a = 0; src[a] != '\0'; a++)
        dest[a] = src[a];
    dest[my_strlen(src)] = '\0';
    return (dest);
}

char **my_tabcpy(char **tab)
{
    char **new_tab = malloc(sizeof(char *) * (my_tablen(tab) + 1));

    for (int a = 0; tab[a] != NULL; a++)
        new_tab[a] = my_strcpy(tab[a]);
    new_tab[my_tablen(tab)] = NULL;
    return (new_tab);
}