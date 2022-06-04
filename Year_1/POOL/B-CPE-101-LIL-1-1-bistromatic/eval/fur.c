/*
** EPITECH PROJECT, 2020
** B-CPE-101-LIL-1-1-evalexpr-simon.auduberteau
** File description:
** fur
*/

#include "my.h"
#include <stdlib.h>

char *int_to_char(int nb)
{
    int integer = nb;
    float comma = nb;
    float tmp = 0;
    char *res = malloc(sizeof(char) * 12);

    if (nb == 0) {
        res[0] = '0';
        res[1] = '\0';
        return (res);
    }
    for (int i = 0; integer != 0; i++) {
        tmp =  (((comma/10) - (integer/10)) * 10);
        integer /= 10;
        comma = integer;
        res[i] = ((int)(tmp+0.100) + '0');
    }
    res = my_revstr(res);
    return (res);
}

int check_sign_op(char *dest)
{
    int i = 0;

    for (; dest[i] != '\0'; i++)
        if (dest[i] == '-' || dest[i] == '+' || dest[i] == '*' ||
        dest[i] == '/' || dest[i] == '%')
            return (i);
    return (i);
}

char *finish_str(char *str_finish, int begin_end)
{
    int i = begin_end;
    char *tmp = malloc(sizeof(char) * my_strlen(str_finish) + 1);
    for (int j = 0; str_finish[i] != '\0'; i++, j++) {
        tmp[j] = str_finish[i];
    }
    tmp[i] = '\0';
    return (tmp);
}