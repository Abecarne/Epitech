/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** my printf
*/

#include "../my.h"

int shoose_function(char c, va_list func)
{
    if (c == 'd' || c == 'i')
        return (my_put_nbr(va_arg(func, int)));
    if (c == 's')
        return (my_putstr(va_arg(func, char *)));
    if (c == 'c')
        return (my_putchar(va_arg(func, int)));
    return (my_putchar('%') + my_putchar(c));
}

int printf_main(char *str, int char_print, va_list func)
{
    int add = 0;

    for (int i = 0; str[i] != '\0'; i += add + 1) {
        add = 0;
        if (str[i] == '%' && is_flag(str[i + 1]) != 0) {
            char_print += shoose_function(str[i + 1], func);
            add = 1;
        }
        if (str[i] != '%')
            char_print += my_putchar(str[i]);
    }
    return (char_print);
}

int my_printf(char *str, ...)
{
    va_list func;
    int char_print = 0;

    va_start (func, str);
    char_print += printf_main(str, char_print, func);
    va_end(func);
    return (char_print);
}
