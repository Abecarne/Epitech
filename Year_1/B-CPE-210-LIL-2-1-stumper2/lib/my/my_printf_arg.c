/*
** EPITECH PROJECT, 2020
** my_printf_arg.c
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

void my_print_binary(int nb)
{
    int rest;
    int a = 0;
    int i = 200;
    char *str = malloc(sizeof(char) * i);

    nb = check_positive(nb);
    str[i] = '\0';
    for (int j = 0; j != (i - 1); j++)
        str[j] = '0';
    while (nb != 0) {
        rest = nb % 2;
        nb /= 2;
        str[i - 1] = rest + 48;
        i -= 1;
    }
    while (str[a] == '0')
        a++;
    for (;str[a] != '\0'; a++)
        my_putchar(str[a]);
}

void my_print_nonascii(const char *s)
{
    for (int j = 0; s[j] != '\0'; j++) {
        if (s[j] < 32 || s[j] >= 127)
            my_print_oct(s[j]);
        else
            my_putchar(s[j]);
    }
}

void my_print_oct(int nb)
{
    int rest;
    char *str = malloc(sizeof(char) * 4);
    int a = 1;
    int i = 3;

    for (int j = 0; j != i; j++)
        str[j] = '0';
    while (nb != 0) {
        rest = nb % 8;
        nb /= 8;
        str[i] = rest + 48;
        i -= 1;
    }
    str[0] = 92;
    my_putstr(str);
}

void my_print_positive(int nb)
{
    nb = check_positive(nb);
    my_put_nbr(nb);
}

void my_print_oct2(int nb)
{
    int rest;
    int a = 0;
    int i = 200;
    char *str = fill_str(i, '.');

    while (nb != 0) {
        rest = nb % 8;
        nb /= 8;
        str[i] = rest + 48;
        i -= 1;
    }
    while (str[a] == '.')
        a++;
    while (a <= 200) {
        my_putchar(str[a]);
        a++;
    }
}
