/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** concat_params
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen2(char  const *str)
{
    int cpt = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        cpt++;
    }
    return (cpt);
}

char *concat_params(int argc , char **argv)
{
    char *dest;
    int size = 0;
    int next = 0;
    int k = 0;

    for (int i = 0; i < argc; i++) {
        size += my_strlen2(argv[i]);
    }
    dest = malloc(sizeof(char) * (size + 1 + argc));

    for (int j = 0; j < argc; j++) {
        for (k = 0; argv[j][k] != '\0'; k++) {
            dest[next] = argv[j][k];
            next++;
        }
        dest[next] = '\n';
        next += 1;
    }
    return (dest);
}