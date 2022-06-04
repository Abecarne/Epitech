/*
** EPITECH PROJECT, 2020
** B-CPE-101-LIL-1-1-evalexpr-simon.auduberteau
** File description:
** replace_dest
*/

#include "my.h"
#include <stdlib.h>

char *int_to_char(int nb);

char *finish_str(char *str_finish, int begin_end);

int begin_same(char *cpy, char *dest);

char *replace_dest_by_res(char *dest, char *calc, int res)
{
    char *tmp_dest = malloc(sizeof(char) * my_strlen(dest) + 10);
    int beg = 0;
    int begin_end = 0;

    beg = begin_same(dest, calc);
    begin_end = beg + my_strlen(calc);
    tmp_dest = my_strncpy(tmp_dest, dest, beg);
    tmp_dest = my_strcat(tmp_dest, int_to_char(res));
    tmp_dest = my_strcat(tmp_dest, finish_str(dest, begin_end));
    return (tmp_dest);
}

int check_dest(char *dest)
{
    for (int i = 0; dest[i] != '\0'; i++)
        if (dest[i] == '+' || dest[i] == '*' || dest[i] == '/' ||
            dest[i] == '%' || dest[i] == '-')
            return (1);
    return (0);
}