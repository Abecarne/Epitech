/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** put nbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int char_print = 0;

    if (nb <= -10) {
        char_print += my_putchar('-');
        char_print += my_put_nbr((nb / 10) * -1);
        char_print += my_putchar(((nb % 10) * -1) + '0');
    }
    else if (nb < 0) {
        char_print += my_putchar('-');
        char_print += my_putchar(((nb % 10) * -1) + '0');
    } else {
        if (nb >= 10)
            char_print += my_put_nbr(nb / 10);
        char_print += my_putchar ((nb % 10) + '0');
    }
    return (char_print);
}
