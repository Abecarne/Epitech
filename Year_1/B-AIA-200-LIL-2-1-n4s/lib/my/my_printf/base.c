/*
** EPITECH PROJECT, 2019
** base
** File description:
** base
*/
#include <stdarg.h>

int binary(int av)
{
    long i = 0;
    int number = av;
    int res = 0;
    long j = 1;

    while (number > 0) {
        res = number % 2;
        number = number / 2;
        i += res*j;
        res = 0;
        j = j * 10;
    }
    my_put_long(i);
    return (0);
}