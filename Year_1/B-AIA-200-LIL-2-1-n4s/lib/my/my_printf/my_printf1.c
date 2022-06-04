/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf1
*/
#include <stdlib.h>
#include <stdarg.h>

int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int	my_put_nbr_base(int nb, char *base);

char forma(char arg, va_list ap)
{
    if (arg == 'd' || arg == 'i')
        my_put_nbr(va_arg(ap, int));
    if (arg == 'c')
        my_putchar(va_arg(ap, char));
    if (arg == 's')
        my_putstr(va_arg(ap, char *));
    if (arg == 'p') {
        char *a;
        a = va_arg(ap, char *);
        my_putstr(&a);
    }
    if (arg == 'b')
        binary(va_arg(ap, int));
    return (0);
}

char forma2(char arg, va_list ap)
{
    if (arg == 'x')
        my_put_nbr_base(va_arg(ap, int), "0123456789abcdef");
    if (arg == 'S') {
        if (va_arg(ap, int) < '32' || va_arg(ap, int) > '127') {
            my_putchar('\\');
            my_put_nbr_base(va_arg(ap, char *), "01234567");
        }
        else
            my_putstr(va_arg(ap, char *));
    }
}

int my_printf(char *s, ...)
{
    int	a = 0;
    char arg;
    va_list	ap;

    va_start(ap, s);
    while (s[a] != '\0') {
        if (s[a] == '%') {
            a++;
            arg = s[a];
            forma(arg, ap);
            forma2(arg, ap);
        }
        if (s[a - 1] != '%') {
            my_putchar(s[a]);
        }
        a++;
    }
    va_end(ap);
}