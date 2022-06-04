/*
** EPITECH PROJECT, 2020
** unix system
** File description:
** my_printf
*/
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include "../../include/my.h"

void display1(char c, void *arg)
{
    switch (c)
    {
    case 'c':
        my_putchar((uintptr_t)arg);
        break;
    case 'd':
        my_put_nbr((uintptr_t)arg);
        break;
    default:
        break;
    }
}

void display2(char c, void *arg)
{
    switch (c)
    {
    case 's':
        my_putstr(arg);
        break;
    default:
        break;
    }
}

void my_printf(char *str, ...)
{
    int i = 0;
    void *copy;
    va_list arg;

    va_start(arg, str);
    for (i; str[i] != '\0'; i++) {
        if ((str[i] == '%' && (!(str[i + 1] == '#')))) {
            copy = (str[i + 1] == '%' ? 0 : va_arg(arg, void *));
            display1(str[i + 1], copy);
            display2(str[i + 1], copy);
            i += 1;
        } else
            my_putchar(str[i]);
    }
    va_end(arg);
}