/*
** EPITECH PROJECT, 2020
** B-PSU-100-LIL-1-1-myprintf-simon.auduberteau
** File description:
** forma
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int change_base(long nb, int base, int spe_octal);
long my_put_long(long nb);
void hexadecimal(long nb, int cap);
void hexadecimal_address(unsigned long nb);
void no_printable(va_list list);
int check_number(char *s, int i);
void print_output(va_list list, char *s, int i);

void which_forma_4(char forma, va_list list, char *s, int i)
{
    switch (forma) {
    case '.':
        if (check_number(s, i) == 0) {
            print_output(list, s, i);
        }
        break;
    case 'S':
        no_printable(list);
        break;
    }
}

void which_forma_3(char forma, va_list list, char *s, int i)
{
    switch (forma) {
    case '#':
        switch (s[i + 1])
        {
        case 'o':
            change_base(va_arg(list, long), 8, 1);
            break;
        case 'x':
            my_putstr("0x");
            hexadecimal(va_arg(list, long), 1);
            break;
        case 'X':
            my_putstr("0X");
            hexadecimal(va_arg(list, long), 0);
            break;
        }
    }
}

void which_forma_2(char forma, va_list list, char *s, int i)
{
    switch (forma)
    {
    case 'p':
        hexadecimal_address((unsigned long)va_arg(list, void *));
        break;
    case 'l':
        my_put_long(va_arg(list, long));
        break;
    case 'o':
        change_base(va_arg(list, int), 8, 0);
        break;
    case 'X':
        hexadecimal(va_arg(list, long), 0);
        break;
    case 'x':
        hexadecimal(va_arg(list, long), 1);
        break;
    }
    which_forma_3(forma, list, s, i);
}

void which_forma(char forma, va_list list, char *s, int i)
{
    switch (forma)
    {
    case 'c':
        my_putchar(va_arg(list, int));
        break;
    case 's':
        my_putstr(va_arg(list, char *));
        break;
    case 'd':
        my_put_nbr(va_arg(list, int));
        break;
    case 'u':
        my_put_nbr(va_arg(list, int));
        break;
    case 'b':
        change_base(va_arg(list, int), 2, 0);
        break;
    }
    which_forma_2(forma, list, s, i);
}