/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_put_nbr
*/

#include "../../include/my.h"

int  my_put_unbr(unsigned int nb)
{
    if (nb >= 9)
        my_put_unbr(nb / 10);
    my_putchar(nb % 10 + 48);
    return (0);
}