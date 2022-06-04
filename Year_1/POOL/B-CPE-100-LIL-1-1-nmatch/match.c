/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** match
*/
#include "my.h"

int  print_result(char  const *s1 , char  const *s2)
{
    if (matching(s1, s2) == 1) {
        return (1);
    } else {
        return (0);
    }
}

int matching(char const *s1, char const *s2)
{
    int count = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[i]) {
            count++;
        }
    }
    if (count == my_strlen(s1)) {
        return (1);
    } else {
        return (0);
    }
}