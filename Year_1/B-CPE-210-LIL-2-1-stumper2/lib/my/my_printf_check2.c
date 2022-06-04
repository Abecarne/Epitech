/*
** EPITECH PROJECT, 2020
** my_printf_check2.c
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

int check_mod(int i, const char *s)
{
    int a = 0;
    int b = 0;

    if (s[i] == '%' && s[i + 1] == '%') {
        while (s[i] == '%' && (s[i + 1] < 97 || s[i + 1] > 122)
                && s[i + 1] != 'X') {
            i++;
            a++;
        }
        b = a / 2;
        while (b > 0) {
            my_putchar('%');
            b--;
        }
    }
    return (i);
}

int my_print_other(int i, const char *s, int content, int x)
{
    i = my_print_mod(i, s);
    switch (s[i]) {
        case '0' :
            my_print_zero(i, s, content, x);
            break;
        case '#' :
            my_print_hash(i, s, content, x);
            break;
    }
    i++;
    return (i);
}

void my_print_zero(int i, const char *s, int content, int x)
{
    i = skip_space(i, s);
    if (s[i + 1] >= 65 && s[i + 1] <= 122)
        my_print_int(i + 1, s, content, 3);
}

void my_print_hash(int i, const char *s, int content, int x)
{
    i = skip_space(i, s);
    if (s[i + 1] == 'o') {
        my_putchar('0');
        my_print_int(i + 1, s, content, 6);
    } else if (s[i + 1] == 'x') {
        my_putstr("0x");
        my_print_int(i + 1, s, content, 8);
    } else {
        my_putstr("0X");
        my_print_int(i + 1, s, content, 9);
    }
}

int skip_space(int i, const char *s)
{
    while (s[i + 1] == ' ')
        i++;
    return (i);
}
