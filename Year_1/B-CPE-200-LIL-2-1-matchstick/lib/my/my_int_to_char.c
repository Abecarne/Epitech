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
}

unsigned long long power_ten(int nb)
{
    unsigned long long res = 1;

    for (int i = 0; i < nb - 1; i++) {
        res *= 10;
    }
    return (res);
}

char *int_to_char(int nb)
{
    char *str = malloc(sizeof(char) * my_nb_len(nb) + 1);
    unsigned long long pow = power_ten(my_nb_len(nb));
    int cpy = nb;

    for (int i = 0; i < my_nb_len(nb); i++) {
        str[i] = (cpy / pow) % 10 + '0';
        pow /= 10;
    }
    return (str);
}