/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** div_mul
*/

#include <stdio.h>

void mul_div_long(int a, int b, int *mul, int *div)
{
    if (b == 0) {
        *div = 42;
        *mul = 0;
    } else {
        *div = a / b;
        *mul = a * b;
    }
}

void mul_div_short(int *a, int *b)
{
    int resa = 0;
    int resb = 0;

    if (*b == 0) {
        *a = 0;
        *b = 42;
    } else {
        resa = (*a) * (*b);
        resb = (*a) / (*b);
        *a = resa;
        *b = resb;
    }
}
