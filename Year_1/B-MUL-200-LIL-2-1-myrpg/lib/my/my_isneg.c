/*
** EPITECH PROJECT, 2020
** my_isneg.c
** File description:
** is neg
*/

#include <unistd.h>
#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    if (n >= 0)
        my_putchar('P');
    return (0);
}
