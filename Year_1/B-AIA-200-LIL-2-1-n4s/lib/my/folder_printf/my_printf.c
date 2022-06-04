/*
** EPITECH PROJECT, 2020
** B-PSU-100-LIL-1-1-myprintf-simon.auduberteau
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void my_putchar(char c);
void which_forma(char forma, va_list list, char *s, int i);
int check_forma(char forma);

int my_printf(char *s, ...)
{
    char forma;
    va_list list;

    va_start(list, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%') {
            i++;
            forma = s[i];
            if (forma == 'i')
                forma = 'd';
            if (check_forma(forma) != 0) {
                my_putchar('%');
                my_putchar(s[i]);
            }
            which_forma(forma, list, s, i);
        }
        if (s[i - 1] != '%' && s[i - 1] != '#')
            my_putchar(s[i]);
    }
    va_end(list);
}