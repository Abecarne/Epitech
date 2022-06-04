/*
** EPITECH PROJECT, 2020
** delivery [WSL: fedora]
** File description:
** my_put_hexa
*/

#include "../../include/my.h"

#include <stdlib.h>

int my_put_hexa(int nb)
{
    char *str = malloc(sizeof(char) * 10);
    int i = 0;
    int tmp;

    for (i; nb != 0; i++) {
        tmp = nb % 16;
        if (tmp < 10) {
            str[i] = tmp + 48;
        } else {
            str[i] = tmp + 87;
        }
        nb /= 16;
    }
    my_putstr(my_revstr(str));
}

unsigned long long my_put_hexa_pointer(unsigned long long int nb)
{
    char *str = malloc(sizeof(char) * 10);
    int i = 0;
    int tmp;

    for (i; nb != 0; i++) {
        tmp = nb % 16;
        if (tmp < 10) {
            str[i] = tmp + 48;
        } else {
            str[i] = tmp + 87;
        }
        nb /= 16;
    }
    my_putstr("0x");
    my_putstr(my_revstr(str));
}

int my_put_maj_hexa(int nb)
{
    char *str = malloc(sizeof(char) * 10);
    int i = 0;
    int tmp;

    for (i; nb != 0; i++) {
        tmp = nb % 16;
        if (tmp < 10) {
            str[i] = tmp + 48;
        } else {
            str[i] = tmp + 55;
        }
        nb /= 16;
    }
    my_putstr(my_revstr(str));
}

int my_put_maj__hexa(int nb)
{
    char *str = malloc(sizeof(char) * 10);
    int i = 0;
    int tmp;

    if (nb == 0) {
        my_putchar('0');
    }
    for (i; nb != 0; i++) {
        tmp = nb % 16;
        if (tmp < 10) {
            str[i] = tmp + 48;
        } else {
            str[i] = tmp + 55;
        }
        nb /= 16;
    }
    my_putstr("0X");
    my_putstr(my_revstr(str));
}

int my_put__hexa(int nb)
{
    char *str = malloc(sizeof(char) * 10);
    int i = 0;
    int tmp;

    if (nb == 0) {
        my_putchar('0');
    }
    for (i; nb != 0; i++) {
        tmp = nb % 16;
        if (tmp < 10) {
            str[i] = tmp + 48;
        } else {
            str[i] = tmp + 87;
        }
        nb /= 16;
    }
    my_putstr("0x");
    my_putstr(my_revstr(str));
}