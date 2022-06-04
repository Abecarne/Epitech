/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** put str
*/

#include "my.h"

int my_putstr(char const * str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        write(1, &str[i], 1);
    return (i);
}
