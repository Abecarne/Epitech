/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** octal
*/
#include <stdio.h>
#include "../../include/my.h"

int my_change_base(int nb, int base)
{
    int res = 0;

    for (int i = 1; (!(nb <= 0)); i *= 10) {
        res += nb % base * i;
        nb /= base;
    }
    my_put_nbr(res);
}