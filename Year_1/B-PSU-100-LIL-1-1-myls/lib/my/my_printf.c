/*
** EPITECH PROJECT, 2020
** unix system
** File description:
** my_printf
*/
#include <stdarg.h>
#include <stdio.h>
#include "../../include/my.h"

void display1(char c, void *arg)
{
    switch (c)
    {
    case 'c':
        my_putchar((char)arg);
        break;
    case 'd':
        my_put_nbr((int)arg);
        break;
    case 'i':
        my_put_nbr((int)arg);
        break;
    case 'o':
        my_change_base((int)arg, 8);
        break;
    case 'u':
        my_put_unbr((int)arg);
        break;
    default:
        break;
    }
}

void display2(char c, void *arg)
{
    switch (c)
    {
    case 'x':
        my_put_hexa((int)arg);
        break;
    case 'X':
        my_put_maj_hexa((int)arg);
        break;
    case 'p':
        my_put_hexa_pointer((unsigned long long int)arg);
        break;
    case 's':
        my_putstr(arg);
        break;
    case 'S':
        my_put_maj_s(arg);
        break;
    default:
        break;
    }
}

void display3(char c, char d, void *arg)
{
    switch (c)
    {
    case '%':
        if (d == '%');
            my_putchar('%');
        break;
    case 'b':
        my_change_base((int)arg, 2);
        break;
    default:
        break;
    }
}

void display4(char c, char d, void *arg)
{
    switch (c)
    {
    case '#':
        switch (d)
        {
        case 'o':
            my_putchar('0');
            my_change_base(arg, 8);
            break;
        case 'x':
            my_put__hexa(arg);
            break;
        case 'X':
            my_put_maj__hexa(arg);
            break;
        }
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
            display3(str[i + 1], str[i + 2], copy);
            i += 1;
        } else if (str[i] == '%' && str[i + 1] == '#') {
            copy = va_arg(arg, void *);
            display4(str[i + 1], str[i + 2], copy);
            i += 2;
        } else {
            my_putchar(str[i]);
        }
    }
    va_end(arg);
}