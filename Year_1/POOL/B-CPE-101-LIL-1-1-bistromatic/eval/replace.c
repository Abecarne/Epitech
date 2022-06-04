/*
** EPITECH PROJECT, 2020
** tempo
** File description:
** replace_parent
*/

#include "my.h"
#include <stdlib.h>

int check_sign_op(char *dest);

char *finish_str(char *str_finish, int begin_end);

char *result_calc(char *dest);

int my_spe_strlen(char *str);

int begin_same(char *cpy, char *dest)
{
    int len = my_spe_strlen(dest);
    int cmp_equal = 0;
    int j = 0;
    int i = 0;
    for (; cpy[i] != '\0'; i++) {
        if (cpy[i] == dest[j]) {
            cmp_equal++;
            j++;
            if (cmp_equal == len)
                return (i - len + 1);
        } else {
            if (cmp_equal == 1)
                i--;
            cmp_equal = 0;
            j = 0;
        }
    }
    return (0);
}

char *clean_dest(char *dest)
{
    int i = 0;

    for (; dest[i] != '\0'; i++) {
        dest[i] = dest[i + 1];
        if (dest[i + 1] == ')') {
            dest[i] = '\0';
            break;
        }
    }
    return (dest);
}

char *replace_cpy(char *cpy, char *dest, char *str)
{
    char *cpy_cpy = malloc(sizeof(char) * my_strlen(str) + 11);
    int beg = begin_same(cpy, dest);
    int begin_end = beg + my_strlen(dest);
    cpy_cpy = my_strncpy(cpy_cpy, cpy, beg);
    dest = clean_dest(dest);
    cpy_cpy = my_strcat(cpy_cpy, result_calc(dest));
    cpy_cpy = my_strcat(cpy_cpy, finish_str(cpy, begin_end));
    return (cpy_cpy);
}

char *replace_parent(char *dest)
{
    for (int i = 0; dest[i] != '\0'; i++)
        dest[i] = dest[i + 1];
    return (dest);
}