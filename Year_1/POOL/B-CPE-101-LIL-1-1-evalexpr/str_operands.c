/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** bootstrap
*/

#include "my.h"
#include <stdlib.h>

int is_factor(char c)
{
    if (c == '*' || c == '/' || c == '%') {
        return (1);
    }
    return (0);
}

int is_add(char c)
{
    if (c == '+' || c == '-') {
        return (1);
    }
    return (0);
}

char *sum(char *str)
{
    char *ind_add = malloc(sizeof(char) * my_strlen(str) + 1);
    int index_add = 0;
    char *copie = malloc(sizeof(char) * my_strlen(str) + 1);
    copie = str;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_add(copie[i]) == 1) {
            ind_add[index_add] = i + '0';
            index_add++;
        }
    }
    ind_add[index_add + 1] = '\0';
    return (ind_add);
}

char *factor(char *str)
{
    char *ind_factor = malloc(sizeof(char) * my_strlen(str) + 1);
    int index_factor = 0;
    char *copie = malloc(sizeof(char) * my_strlen(str) + 1);
    copie = str;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_factor(copie[i]) == 1) {
            ind_factor[index_factor] = i + '0';
            index_factor++;
        }
    }
    ind_factor[index_factor + 1] = '\0';

    return (ind_factor);
}
