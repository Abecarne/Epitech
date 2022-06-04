/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_str_isalpha
*/

#include "../../include/my.h"

int  my_str_isalpha(char  const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z')
        || (str[i] >= 'A' && str[i] <= 'Z')) {
            return (1);
        }
    }
    return (0);
}

int my_str_is_alphanum(char *str)
{
    if (my_str_isalpha(str) == 0 && my_str_isnum(str) == 0)
        return (0);
    return (1);
}