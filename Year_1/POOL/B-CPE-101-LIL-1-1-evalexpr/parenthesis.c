/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** parenthesis
*/

#include "my.h"
#include <stdlib.h>

char *pick_calc(char *str);

int check_parent(char *str);

char *replace_parent(char *dest);

char *replace_cpy(char *cpy, char *dest, char *str);

int check_parent_final_str(char *str);

void free_var(char *cpy_str, char *dest);

int calcul(char *str)
{
    char *cpy_str = malloc(sizeof(char) * my_strlen(str) + 1);
    char *dest = pick_calc(str);
    int res = 0;

    cpy_str = my_strcpy(cpy_str, str);
    while (check_parent_final_str(cpy_str) != 0) {
        for (int i = 0; check_parent(dest) != 0; i++) {
            dest = replace_parent(dest);
            dest = pick_calc(dest);
        }
        cpy_str = replace_cpy(cpy_str, dest, str);
        dest = pick_calc(cpy_str);
    }
    res = my_getnbr(cpy_str);
    free_var(cpy_str, dest);
    return (res);
}

char *transform(char *str)
{
    int len = my_strlen(str);
    char *tmp_str = malloc(sizeof(char) * len + 4);
    int i = 0;

    tmp_str[0] = '(';
    for (; str[i]; i++)
        tmp_str[i + 1] = str[i];
    tmp_str[i + 1] = ')';
    tmp_str[i + 2] = '\0';
    return (tmp_str);
}

int launch(char *str)
{
    str = transform(str);
    return (calcul(str));
}

int operators(int a, int c, char b)
{
    if (b == '+')
        return (a + c);
    if (b == '-')
        return (a - c);
    if (b == '/')
        return (a / c);
    if (b == '*')
        return (a * c);
    if (b == '%')
        return (a % c);
    return (0);
}