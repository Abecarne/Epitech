/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

int my_print_mod(int i, const char *s)
{
    while (s[i] == ' ' && s[i + 1] == ' ')
        i++;
    if (s[i] == ' ') {
        if (s[i + 1] == '\n' || s[i + 1] == '\0') {
        my_putchar('%');
        return (i);
        }
    }
    return (i);
}

int my_print_str(int i, const char *s, char *content)
{
    int len = 0;

    i = my_print_mod(i, s);
    switch (s[i]) {
        case 's' :
            my_putstr(content);
            break;
        case 'S' :
            my_print_nonascii(content);
            break;
        case 'n' :
            len = my_strlen(content);
            my_put_nbr(len);
            break;
    }
    i++;
    return (i);
}

int my_print_int(int i, const char *s, int content, int x)
{
    i = my_print_mod(i, s);
    if (x > 6)
        i = my_print_int2(i, s, content, x);
    else
        switch (s[i]) {
            case 'd' :
                my_put_nbr(content);
                break;
            case 'i' :
                my_put_nbr(content);
                break;
            case 'b' :
                my_print_binary(content);
                break;
            case 'o' :
                my_print_oct2(content);
                break;
        }
    i++;
    return (i);
}

int my_print_int2(int i, const char *s, int content, int x)
{
    i = my_print_mod(i, s);
    if (x > 10)
        i = my_print_other(i, s, content, x);
    else
        switch (s[i]) {
            case 'x' :
                my_print_hex(content);
                break;
            case 'X' :
                my_print_hex(content);
                break;
            case 'u' :
                my_print_positive(content);
                break;
            case 'c' :
                my_putchar(content);
                break;
    }
    return (i);
}

int my_printf(const char *format, ...)
{
    va_list list;
    char str[13] = "sSndbiocxXu#0";

    va_start(list, format);
    for (int i = 0; format[i] != '\0';) {
        i = my_print_char(i, format);
        if (format[i] == '%') {
            i = check_mod(i, format);
            i = skip_space(i, format);
            for (int x = 0; x < 13; x++) {
                if (str[x] == format[i + 1] && x < 3)
                    i = my_print_str(i + 1, format, va_arg(list, char *));
                if (str[x] == format[i + 1] && x >= 3)
                    i = my_print_int(i + 1, format, va_arg(list, int), x);
            }
        }
    }
    va_end(list);
    return (my_strlen(format));
}