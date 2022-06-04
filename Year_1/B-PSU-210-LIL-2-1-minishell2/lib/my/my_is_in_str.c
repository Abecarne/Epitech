/*
** EPITECH PROJECT, 2021
** minishell2 [WSL: Ubuntu-20.04]
** File description:
** my_is_in_str
*/

#include "../../include/my.h"
#include <stddef.h>

int char_in_str(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return (0);
    return (1);
}

int arg_in_tab(char **tab, char *str)
{
    for (int i = 0; tab[i] != NULL; i++)
        if (my_strcmp(tab[i], str) == 0)
            return (0);
    return (1);
}
