/*
** EPITECH PROJECT, 2020
** my_put_error.c
** File description:
** put error
*/

#include "my.h"

int my_put_error(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str[i], 1);
    return (84);
}
