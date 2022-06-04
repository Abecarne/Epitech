/*
** EPITECH PROJECT, 2020
** printf_error.c
** File description:
** printf error engine
*/

#include "../my.h"

int is_flag(char c)
{
    char *flag = "idsc%";

    for (int i = 0; flag[i] != '\0'; i++)
        if (c == flag[i])
            return (1);
    return (0);
}
