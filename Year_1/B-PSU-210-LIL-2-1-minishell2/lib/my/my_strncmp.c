/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_strncmp
*/

#include "../../include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int max = (my_strlen(s1) <= my_strlen(s2)) ? my_strlen(s1) : my_strlen(s2);
    int min = (my_strlen(s1) <= my_strlen(s2)) ? my_strlen(s2) : my_strlen(s1);
    int i = 0;

    if (n > min)
        return (1);
    while (i < n) {
        if (s1[i] != s2[i])
            return (1);
        i++;
    }
    return (0);
}