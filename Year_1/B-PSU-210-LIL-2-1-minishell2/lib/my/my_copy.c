/*
** EPITECH PROJECT, 2021
** delivery [WSL: Ubuntu-20.04]
** File description:
** my_copy
*/

#include "../../include/my.h"
#include <stdio.h>
#include <stdlib.h>

int nb_lines_tab(char **tab)
{
    int i = 0;

    for (i = 0; tab[i] != NULL; i++);
    return (i);
}

char **copy_2d_array(char **tab)
{
    int i = 0;
    int j = 0;
    int lines = nb_lines_tab(tab);
    char **res = malloc(sizeof(char *) * (lines + 1));

    if (!res)
        exit(84);
    for (i = 0; tab[i] != NULL; i++) {
        res[i] = malloc(sizeof(char) * 4096);
        if (!res[i])
            exit(84);
        res[i] = my_strcpy(res[i], tab[i]);
    }
    res[i] = NULL;
    return (res);
}

char **add_line_array(char **tab)
{
    int i = 0;
    int lines = nb_lines_tab(tab);
    char **res = malloc(sizeof(char *) * (lines + 2));

    if (!res)
        exit(84);
    for (i = 0; tab[i] != NULL; i++) {
        res[i] = malloc(sizeof(char) * my_strlen(tab[i]) + 1);
        if (!res[i])
            exit(84);
        res[i] = my_strcpy(res[i], tab[i]);
    }
    res[i + 1] = NULL;
    return (res);
}