/*
** EPITECH PROJECT, 2020
** my_int_to_str
** File description:
** Convert an integer into a string
*/

#include <stdlib.h>

char *my_int_to_str(int nb)
{
    char *str;
    int tmp = nb;
    int len = 0;

    for (; tmp > 0; len++)
        tmp /= 10;
    str = malloc(sizeof(char) * len + 1);
    str[len] = '\0';
    for (int i = len - 1; i >= 0; i--) {
        if (nb == 0)
            str[i] = '0';
        else {
            str[i] = nb % 10 + 48;
            nb /= 10;
        }
    }
    return (str);
}