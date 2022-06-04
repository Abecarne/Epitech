/*
** EPITECH PROJECT, 2020
** B-PSU-100-LIL-1-1-myprintf-simon.auduberteau
** File description:
** non_printable
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int change_base(int nb, int base);
void my_putchar(char c);
int my_putstr(char const *str);

void no_printable(va_list list)
{
    char *str = va_arg(list, char *);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putstr("\\0");
            change_base(str[i], 8);
        } else
            my_putchar(str[i]);
    }
}