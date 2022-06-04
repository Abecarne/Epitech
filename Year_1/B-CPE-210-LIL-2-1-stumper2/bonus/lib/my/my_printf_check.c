/*
** EPITECH PROJECT, 2020
** my_printf_check.c
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

int check_positive(int nb)
{
    if (nb < 0)
        nb *= -1;
    return (nb);
}

int my_put_mod(int i)
{
    my_putchar('%');
    i++;
    return (i);
}

int my_print_char(int i, const char *format)
{
    if (format[i] != '%') {
        if (format[i] == '\n' || (format[i] >= 32
            && format[i] <= 126)) {
            my_putchar(format[i]);
            i++;
        }
    }
    return (i);
}

char *fill_str(int b, char a)
{
    char *str = malloc(sizeof(char) * b);

    str[b] = '\0';
    for (int j = 0; j != (b - 1); j++)
        str[j] = a;
    return (str);
}

void my_print_hex(int nb)
{
    int rest;
    int a = 0;
    int b = 200;
    char *str = fill_str(b, '0');

    nb = check_positive(nb);
    while (nb != 0) {
        rest = nb % 16;
        nb /= 16;
        str[b - 1] = rest + 48;
        b -= 1;
    }
    while (str[a] == '0')
        a++;
    for (;str[a] != '\0'; a++)
        if (str[a] > 57)
            my_putchar(str[a] + 7);
        else
            my_putchar(str[a]);
}