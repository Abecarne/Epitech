/*
** EPITECH PROJECT, 2021
** projets
** File description:
** my_int_to_char
*/

#include "../../include/my.h"
#include <stdlib.h>

unsigned long long my_nb_len(unsigned long long nb)
{
    unsigned long long cpt = 0;

    for (long long i = 1; i < 1000000000000000; i *= 10) {
        if (nb / i < 1) {
            return (cpt);
        }
        cpt++;
    }
    return (cpt);
}

unsigned long long power_ten(int nb)
{
    unsigned long long res = 1;

    for (int i = 0; i < nb - 1; i++) {
        res *= 10;
    }
    return (res);
}

int my_nbrlen(int nb)
{
    int result = 0;

    if (nb < 10)
        return (1);
    for (int i = 10; nb != 0; i * 10) {
        nb = nb / i;
        result++;
    }
    return (result);
}

int power(int nb, int pow)
{
    for (int i = 0; i < pow - 1; i++) {
        nb *= 10;
    }
    return (nb);
}

char *int_to_char(int nb)
{
    char *value = malloc(sizeof(char) * my_nbrlen(nb) + 1);
    int pow_ten = power(1, my_nbrlen(nb));
    int i = 0;
    int nb_cpy = nb;

    if (!value)
        return (84);
    for (i; i < my_nbrlen(nb_cpy); i++) {
        value[i] = (nb_cpy / pow_ten % 10) + '0';
        pow_ten /= 10;
    }
    value[i] = '\0';
    return (value);
}