/*
** EPITECH PROJECT, 2020
** B-PSU-100-LIL-1-1-myprintf-simon.auduberteau
** File description:
** base
*/

#include <stdlib.h>

void my_putchar(char c);
long my_put_long(long nb);
char *my_revstr(char *str);
int my_putstr(char const *str);

int change_base(long nb, int base, int spe_octal)
{
    long i = 0;
    long number = nb;
    int res = 0;
    long j = 1;

    while (number > 0) {
        res = number % base;
        number = number / base;
        i += res*j;
        res = 0;
        j = j * 10;
    }
    if (spe_octal == 1 && res != 0)
        my_putchar('0');
    my_put_long(i);
    return (0);
}

void hexadecimal(long nb, int cap)
{
    long number = nb;
    char *res = malloc(sizeof(char) * 100);
    double tmp = 0;
    int maj = (cap == 1) ? 39 : 7;

    for (int i = 0; number > 0; i++) {
        tmp = (long double)number / 16 - number / 16;
        tmp *= 16;
        if (tmp > 9) {
            res[i] = (int)tmp + '0' + maj;
        } else
            res[i] = tmp + '0';
        number = number / 16;
    }
    res = my_revstr(res);
    my_putstr(res);
    free(res);
}

void hexadecimal_address(unsigned long nb)
{
    unsigned long number = nb;
    char *res = malloc(sizeof(char) * 100);
    double tmp = 0;

    for (int i = 0; number > 0; i++) {
        tmp = (double)number / 16 - number / 16;
        tmp *= 16;
        if (tmp > 9) {
            res[i] = (int)tmp + '0' + 39;
        } else
            res[i] = tmp + '0';
        number = number / 16;
    }
    res = my_revstr(res);
    my_putstr("0x");
    my_putstr(res);
    free(res);
}